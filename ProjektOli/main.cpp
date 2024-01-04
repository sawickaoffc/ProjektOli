#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bankomat.h"
#include "ekranBankomatu.h"
#include "Guzik.h"
bankomat bankomat1; 
ekranBankomatu ekranbankomatu1;
enum stan {
	poczatkowy,wpisywaniepinu,menu, wyplacanie, wplacanie, srodki,aktywacja,zmianaPinu, wyjeciekarty, limit, 
};

using namespace std;
int main(){
	sf::VideoMode rozmiar(1000, 800);
	sf::RenderWindow okienko(rozmiar,  "My window");
	okienko.setFramerateLimit(60); //ilosc klatek na sec
	okienko.setVerticalSyncEnabled(true); //oczekiwanie az kolejna klatka sie skonczy
	sf::Event event;

	bankomat1.Stworz(&okienko); //przekazywanie rzeczy z konstruktora do okienka
	ekranbankomatu1.Stworz(&okienko);

	int stanEkranu = stan::poczatkowy;
	while (okienko.isOpen()) {
		while (okienko.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				okienko.close();
				break;
			case sf::Event::MouseButtonPressed:
				bankomat1.CzytaniePinu(); 
				switch (stanEkranu) {
				case stan::poczatkowy:
					if (bankomat1.WlozenieKarty(okienko) == true) {
						stanEkranu = stan::wpisywaniepinu;
					}
					break;
				case stan::wpisywaniepinu: 
					stanEkranu = stan::menu;
					break;
				case stan::menu:
					switch (bankomat1.WybranieStrzalki(okienko)) {
					case 1:
						stanEkranu = stan::poczatkowy;
						break;
					case 2:
						stanEkranu = stan::wplacanie;
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
						stanEkranu = stan::limit;
						break;
					case 8:
						//stan::;
						break;
					}
					break;

				}
				break;
			}

	okienko.clear(sf::Color::Black);
	bankomat1.rysujBankomat(okienko);
	switch (stanEkranu)
	{
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
		ekranbankomatu1.RysujWyplataGotowki();
		break;
	case stan::wyjeciekarty:
		ekranbankomatu1.RysujWyplataGotowki();
		break;
	case stan::limit:
		ekranbankomatu1.RysujWyplataGotowki();
		break;
	}


	ekranbankomatu1.RysujEkranPoczatkowy();
	
	//ekranBankomatu.RysujWpisywaniePinu();
	//ekranBankomatu.RysujMenu();

	}
	okienko.display();
	}
	return 0;
}