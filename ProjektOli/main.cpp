#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bankomat.h"
#include "ekranBankomatu.h"
#include "Guzik.h"
bankomat bankomat1; 
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

	bankomat1 = bankomat(&okienko); //przekazywanie rzeczy z konstruktora do okienka
	ekranBankomatu ekranBankomatu(&okienko);

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
				break;
			}

	okienko.clear(sf::Color::Black);
	bankomat1.rysujBankomat(okienko);
	switch (stanEkranu)
	{
	case stan::poczatkowy:
		ekranBankomatu.RysujEkranPoczatkowy();
		break;
	case stan::wpisywaniepinu:
		ekranBankomatu.RysujWpisywaniePinu();
		break;
	case stan::menu:
		ekranBankomatu.RysujMenu();
		break; 
	case stan::wyplacanie:
		ekranBankomatu.RysujWyplataGotowki();
		break;
	case stan::wplacanie: 
		ekranBankomatu.RysujWplataGotowki(); 
		break;
	case stan::srodki:
		ekranBankomatu.RysujDostepneSrodki();
		break;
	case stan::aktywacja:
		ekranBankomatu.RysujAktywacjaKarty();
		break;
	case stan::zmianaPinu:
		ekranBankomatu.RysujWyplataGotowki();
		break;
	case stan::wyjeciekarty:
		ekranBankomatu.RysujWyplataGotowki();
		break;
	case stan::limit:
		ekranBankomatu.RysujWyplataGotowki();
		break;
	}

	ekranBankomatu.RysujEkranPoczatkowy();

	//ekranBankomatu.RysujWpisywaniePinu();
	//ekranBankomatu.RysujMenu();

	}
	okienko.display();
	}
	return 0;
}