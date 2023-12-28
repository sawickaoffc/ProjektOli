#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bankomat.h"
#include "ekranBankomatu.h"



using namespace std;



int main(){

	sf::VideoMode rozmiar(1000, 800);
	sf::RenderWindow okienko(rozmiar,  "My window");
	okienko.setFramerateLimit(60); //ilosc klatek na sec
	okienko.setVerticalSyncEnabled(true); //oczekiwanie az kolejna klatka sie skonczy
	bankomat bankomat(&okienko);
	ekranBankomatu ekranBankomatu(&okienko);
	sf::Event event;

	while (okienko.isOpen()) {
		while (okienko.pollEvent(event))
			if (event.type == sf::Event::Closed)
				okienko.close();
	okienko.clear(sf::Color::Black);
	bankomat.rysujBankomat();
	ekranBankomatu.ekranPoczatkowy();
	okienko.display();
	}

	return 0;

}