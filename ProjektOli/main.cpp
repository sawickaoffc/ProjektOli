#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bankomat.h"
#include "ekranBankomatu.h"
#include "Guzik.h"
#include <cstring>
#include "PobranieZPliku.h"
 
bankomat bankomat1;
ekranBankomatu ekranbankomatu1;
PobranieZPliku pobranie;
enum stan {
	poczatkowy, wpisywaniepinu, menu, wyplacanie, srodki, wplacanie, innakwota,
	wyjeciekarty, limity, zmianalimitu, wydaneBanknoty, dane
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
	pobranie.Stworz(&okienko);

	int poprzedniStan = stan::poczatkowy;
	int stanEkranu = stan::poczatkowy;
	int typLimitu = 0;
	int zmianaPinu = 0;
	string money = ""; //pomocicza do kwoty
	while (okienko.isOpen()) {
		while (okienko.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				okienko.close();
				break;
			case sf::Event::MouseButtonPressed:
				switch (stanEkranu) {
				case stan::poczatkowy:
					bankomat1.kwota = "";
					bankomat1.is_valid_pin = false;
					bankomat1.iloscProbPin = 3;
					if (bankomat1.WlozenieKarty(okienko) == true && pobranie.zablokowanieKarty == false) {
						stanEkranu = stan::wpisywaniepinu;
					}
					break;
				case stan::wpisywaniepinu:
					pobranie.PobranieZKarty(pobranie.daneKarty);
					if (zmianaPinu == 1 && sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						bankomat1.czyPierwszePodaniePinu = false;
						bankomat1.is_valid_pin = true;
						stanEkranu = stan::menu;
					}
					pobranie.PobranieZKarty(pobranie.daneKarty);
					if (bankomat1.CzytaniePinu()) {
						stanEkranu = stan::menu;
						std::memset(bankomat1.pin, 0, sizeof(bankomat1.pin)); //wyzerowanie pinu
						bankomat1.petla = 0;
					}
					if (zmianaPinu != 1 && sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						stanEkranu = poczatkowy;
					}
					break;
				case stan::menu:
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::srodki;
						break;
					case 2:
						stanEkranu = stan::wyplacanie;
						break;
					case 3:
						stanEkranu = stan::wplacanie;
						break;
					case 5:
						stanEkranu = stan::limity;
						break;
					case 6:
						zmianaPinu = 1;
						bankomat1.czyPierwszePodaniePinu = true;
						bankomat1.is_valid_pin = false;
						stanEkranu = stan::wpisywaniepinu;
						break;
					case 7:
						stanEkranu = stan::dane;
						break;
					}
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						stanEkranu = poczatkowy;
					}
					break;
				case stan::wyplacanie:
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						bankomat1.kwota = "10";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 2:
						bankomat1.kwota = "20";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 3:
						bankomat1.kwota = "50";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 4:
						bankomat1.kwota = "100";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 5:
						bankomat1.kwota = "200";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 6:
						bankomat1.kwota = "500";
						if (bankomat1.WarunekWyplat()) {
							stanEkranu = stan::wydaneBanknoty;
						}
						break;
					case 7:
						stanEkranu = stan::innakwota;
						break;
					}
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true ) {
						stanEkranu = stan::menu;
					}
					break;
				case stan::innakwota:
					if (bankomat1.PobierzKwote() ==true && bankomat1.WarunekWyplat()) {
						stanEkranu = stan::wydaneBanknoty;
					}		

					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.kwota == "") {
						stanEkranu = stan::wyplacanie;
					}
					break;
				case stan::wplacanie:
					
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						bankomat1.kwota = "10";
						bankomat1.wydanie[0] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					case 2:
						bankomat1.kwota = "20";
						bankomat1.wydanie[1] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					case 3:
						bankomat1.kwota = "50";
						bankomat1.wydanie[2] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					case 4:
						bankomat1.kwota = "100";
						bankomat1.wydanie[3] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					case 5:
						bankomat1.kwota = "200";
						bankomat1.wydanie[4] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					case 6:
						bankomat1.kwota = "500";
						bankomat1.wydanie[5] = 1;
						bankomat1.Wplata();
						stanEkranu = stan::srodki;
						break;
					}
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true) {
						stanEkranu = stan::menu;
					}
					break;
				case stan::srodki: 
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						stanEkranu = stan::menu;
					}
					break;
				case stan::dane:
					bankomat1.kwota = "";
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true) {
						stanEkranu = stan::menu;
					}
					break;
				case stan::limity:
					poprzedniStan = limity;
					switch (bankomat1.WybranieStrzalki(okienko)) {
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
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						stanEkranu = stan::menu;
					}
					break;

				case stan::zmianalimitu:
					if (bankomat1.PobierzKwote() && stof(bankomat1.kwota) >= 0) {
						if (typLimitu == 0) {
							bankomat1.limitMiesieczny = bankomat1.kwota;
							pobranie.ZapisDoKarty(pobranie.daneKarty);
							bankomat1.kwota = "";
							stanEkranu = stan::limity;

						}
						else if (typLimitu == 1) {
							bankomat1.limitDzienny = bankomat1.kwota;
							pobranie.ZapisDoKarty(pobranie.daneKarty);
							bankomat1.kwota = "";
							stanEkranu = stan::limity;

						}
						else if (typLimitu == 2) {
							bankomat1.limitZwykly = bankomat1.kwota;			
							pobranie.ZapisDoKarty(pobranie.daneKarty);
							bankomat1.kwota = "";
							stanEkranu = stan::limity;

						}
					}
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0&& bankomat1.kwota == "") {
						stanEkranu = stan::limity;
					}
					break;
				case stan::wydaneBanknoty:
					poprzedniStan = stanEkranu;
					if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[20].PolozenieMyszki(okienko) == true && bankomat1.petla == 0) {
						stanEkranu = menu;
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
			case stan::wyplacanie:
				ekranbankomatu1.RysujWyplataGotowki();
				break;
			case stan::innakwota:
				ekranbankomatu1.RysujInnaKwote();
				break;
			case stan::srodki:
				ekranbankomatu1.RysujDostepneSrodki();
				break;
			case stan::limity:
				ekranbankomatu1.RysujLimity();
				break;
			case stan::zmianalimitu:
				ekranbankomatu1.RysujZmianeLimitu();
				break;
			case stan::wydaneBanknoty:
				ekranbankomatu1.RysujWydaneBanknoty();
				break;
			case stan::wplacanie:
				ekranbankomatu1.RysujWplataGotowki();
				break;
			case stan::dane:
				ekranbankomatu1.RysujDane();
				break;
			}
			okienko.display();
		}
	}
	return 0;
}