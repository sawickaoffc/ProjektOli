#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Guzik.h"
class bankomat
{
private:
	sf::Font font; 
	sf::RenderWindow* okienko;
	int ostatecznyPIN[4];
	
public:
	string obecnyPIN;
	bool czyPierwszePodaniePinu = false;
	int pin[4];
	int petla = 0;
	bankomat() = default;
	bankomat(sf::RenderWindow* okienko);
	void utworzTloEkranu();
	void rysujBankomat(sf::RenderWindow& okienko);
	string CzytaniePinu();
	void Stworz(sf::RenderWindow* okienko);
	Guzik tablicaPrzyciskow[23];
	int WybranieStrzalki(sf::RenderWindow& okienko);
	bool WlozenieKarty(sf::RenderWindow& okienko);
	bool PodaniePinu(sf::RenderWindow& okienko);
	bool PoprawnoscPinu(sf::RenderWindow& okienko);
};