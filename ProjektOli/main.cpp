#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bankomat.h"
#include "ekranBankomatu.h"
#include "Guzik.h"
#include <cstring>

bankomat bankomat1;
ekranBankomatu ekranbankomatu1;
enum stan {
	poczatkowy, wpisywaniepinu, menu, wyplacanie, wplacanie, srodki, aktywacja,
	zmianaPinu, wyjeciekarty, limity, limitmiesieczny, potwierdzenie, zmianalimitu,
	limitdzienny, wydaneBanknoty
};
using namespace std;
int main() {
	sf::VideoMode rozmiar(1000, 800);
	sf::RenderWindow okienko(rozmiar, "My window");
	okienko.setFramerateLimit(60); //ilosc klatek na sec
	okienko.setVerticalSyncEnabled(true); //oczekiwanie az kolejna klatka sie skonczy
	sf::Event event;

	bankomat1.Stworz(&okienko); //przekazywanie rzeczy z konstruktora do okienka
	ekranbankomatu1.Stworz(&okienko);

	int poprzedniStan = stan::poczatkowy;
	int stanEkranu = stan::poczatkowy;
	int typLimitu = 0;
	while (okienko.isOpen()) {
		while (okienko.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				okienko.close();
				break;
			case sf::Event::MouseButtonPressed:

				switch (stanEkranu) {
				case stan::poczatkowy:
					if (bankomat1.WlozenieKarty(okienko) == true) {
						stanEkranu = stan::wpisywaniepinu;
					}
					break;
				case stan::wpisywaniepinu:
					if (bankomat1.CzytaniePinu()) {
						stanEkranu = stan::menu;
						std::memset(bankomat1.pin, 0, sizeof(bankomat1.pin));
						bankomat1.petla = 0;
						bankomat1.is_valid_pin = false;
					};
					break;

				case stan::menu:
					std::cout << "Stan konta: " << bankomat1.stanKonta << endl;
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::poczatkowy;
						bankomat1.is_valid_pin = false;
						break;
					case 2:
						stanEkranu = stan::wplacanie;
						bankomat1.kwota = "";
						break;
					case 3:
						stanEkranu = stan::wyplacanie;
						break;
					case 4:
						stanEkranu = stan::srodki;
						break;
					case 5:
						stanEkranu = stan::aktywacja;
						break;
					case 6:
						stanEkranu = stan::zmianaPinu;
						break;
					case 7:
						stanEkranu = stan::limity;
						break;
					case 8:
						break;
					}
					break;

				case stan::wplacanie:
					if (bankomat1.PobierzKwote() && stof(bankomat1.kwota) >0) {
						poprzedniStan = stanEkranu;
						stanEkranu = potwierdzenie;
					}

					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;

				case stan::wyplacanie:
					if (bankomat1.PobierzKwote() && stof(bankomat1.kwota) <= bankomat1.stanKonta
						&& stof(bankomat1.kwota) <= stof(bankomat1.limitZwykly)) {
						poprzedniStan = stanEkranu;
						stanEkranu = potwierdzenie;
					}

					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;

					// Potwierdzenia pinem
				case stan::potwierdzenie:
					if (bankomat1.CzytaniePinu() && bankomat1.iloscProbPin > 0) {

						stanEkranu = stan::menu; // dodac do stanu konta
						std::memset(bankomat1.pin, 0, sizeof(bankomat1.pin));
						bankomat1.petla = 0;
						bankomat1.is_valid_pin = false;

						if (poprzedniStan == wplacanie) {
							bankomat1.stanKonta += stof(bankomat1.kwota);
						}
						else if (poprzedniStan == wyplacanie) {
							bankomat1.stanKonta -= stof(bankomat1.kwota);
							string wyplata = bankomat1.WydajBanknoty(stof(bankomat1.kwota));
							stanEkranu = stan::wydaneBanknoty;

						}
						else if (poprzedniStan == zmianaPinu) {
							bankomat1.czyPierwszePodaniePinu = true;
							stanEkranu = stan::wpisywaniepinu;
						}
						else if (poprzedniStan == zmianalimitu && typLimitu == 0) {
							bankomat1.limitMiesieczny = bankomat1.kwota;
							bankomat1.kwota = "0";
						}
						else if (poprzedniStan == zmianalimitu && typLimitu == 1) {
							bankomat1.limitDzienny = bankomat1.kwota;
							bankomat1.kwota = "0";

						}
						else if (poprzedniStan == zmianalimitu && typLimitu == 2) {
							bankomat1.limitZwykly = bankomat1.kwota;
							bankomat1.kwota = "0";

						}
						cout << poprzedniStan << typLimitu << endl;
					}
					else if (bankomat1.iloscProbPin == 0)
					{
						stanEkranu = poczatkowy;
					}
					ekranbankomatu1.Potwierdzenie();
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;

				case stan::srodki:
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;

				case stan::aktywacja:
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					case 5:
						bankomat1.karta = "Aktywna";
						break;
					}

					break;

				case stan::zmianaPinu:
					poprzedniStan = stanEkranu;
					stanEkranu = potwierdzenie;

					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;

					}
					break;

				case stan::limity:
					poprzedniStan = limity;
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					case 6:
						typLimitu = 0;
						stanEkranu = stan::zmianalimitu;
						break;
					case 7:
						typLimitu = 1;
						stanEkranu = stan::zmianalimitu;
						break;
					case 8:
						typLimitu = 2;
						stanEkranu = stan::zmianalimitu;
						break;
					}
					break;

				case stan::zmianalimitu:
					if (bankomat1.PobierzKwote() && stof(bankomat1.kwota) >= 0) {
						poprzedniStan = stanEkranu;
						stanEkranu = potwierdzenie;
					}

					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;
				case stan::wydaneBanknoty:
					poprzedniStan = stanEkranu;
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::menu;
						break;
					}
					break;

				}
				break;
				std::cout << okienko.isOpen() << okienko.pollEvent(event) << endl;
			}

			okienko.clear(sf::Color::Black);
			bankomat1.rysujBankomat(okienko);
			switch (stanEkranu) {
			case stan::poczatkowy:
				ekranbankomatu1.RysujEkranPoczatkowy();
				break;
			case stan::wpisywaniepinu:
				ekranbankomatu1.RysujWpisywaniePinu();
				break;
			case stan::menu:
				ekranbankomatu1.RysujMenu();
				break;
			case stan::potwierdzenie:
				ekranbankomatu1.RysujPotwierdzenie();
				break;

			case stan::wyplacanie:
				ekranbankomatu1.RysujWyplataGotowki();
				break;
			case stan::wplacanie:
				ekranbankomatu1.RysujWplataGotowki();
				break;
			case stan::srodki:
				ekranbankomatu1.RysujDostepneSrodki();
				break;
			case stan::aktywacja:
				ekranbankomatu1.RysujAktywacjaKarty();
				break;
			case stan::zmianaPinu:
				ekranbankomatu1.RysujZmianaPinu();
				break;
			case stan::wyjeciekarty:
				ekranbankomatu1.RysujWyjecieKarty();
				break;
			case stan::limity:
				ekranbankomatu1.RysujLimity();
				break;
			case stan::zmianalimitu:
				ekranbankomatu1.RysujZmianeLimitu();
				break;
			case stan::limitdzienny:
				ekranbankomatu1.RysujLimitDzienny();
				break;
			case stan::wydaneBanknoty:
				ekranbankomatu1.RysujWydaneBanknoty();
				break;
			}
		}
		okienko.display();
	}
	return 0;
}