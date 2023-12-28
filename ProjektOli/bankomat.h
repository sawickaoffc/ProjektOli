#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class bankomat
{private:
	sf::Font font; 
	sf::RenderWindow* okienko;
	sf::RectangleShape tloEkranu;
	sf::RectangleShape klawiatura;
	sf::RectangleShape lewo1;
	sf::RectangleShape lewo2;
	sf::RectangleShape lewo3;
	sf::RectangleShape lewo4;
	sf::RectangleShape prawo1;
	sf::RectangleShape prawo2;
	sf::RectangleShape prawo3;
	sf::RectangleShape prawo4;
	sf::RectangleShape jeden;
	sf::RectangleShape dwa;
	sf::RectangleShape trzy;
	sf::RectangleShape cztery;
	sf::RectangleShape piec;
	sf::RectangleShape szesc;
	sf::RectangleShape siedem;
	sf::RectangleShape osiem;
	sf::RectangleShape dziewiec;
	sf::RectangleShape zero;
	sf::RectangleShape enter;
	sf::RectangleShape usun;

	sf::Text one;
	sf::Text two;
	sf::Text three;
	sf::Text four;
	sf::Text five;
	sf::Text six;
	sf::Text seven;
	sf::Text eight;
	sf::Text nine;
	sf::Text zero2;
	sf::Text usun2;
	sf::Text enter2;

	sf::Text strzalkaLewo1;
	sf::Text strzalkaLewo2;
	sf::Text strzalkaLewo3;
	sf::Text strzalkaLewo4;
	sf::Text strzalkaPrawo1;
	sf::Text strzalkaPrawo2;
	sf::Text strzalkaPrawo3;
	sf::Text strzalkaPrawo4;


public:
	bankomat(sf::RenderWindow* okienko);
	void utworzTloEkranu();
	void rysujBankomat();


};

