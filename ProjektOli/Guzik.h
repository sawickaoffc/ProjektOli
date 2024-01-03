#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>

class Guzik
{
private:
	sf::RectangleShape guzik;
	sf::Text tekst; 
public:
	Guzik() {}
	Guzik(string napis, sf::Vector2f rozmiarWektora, int wielkoscNapisu, sf::Color kolorTla, sf::Color kolorTekstu, sf::Font& czcionka);
	void Czcionka(sf::Font& font); 
	void KolorTla(sf::Color color);
	void KolorCzcionki(sf::Color color);
	void Polozenie(sf::Vector2f pos);
	void RysujPrzycisk(sf::RenderWindow& window);
	bool PolozenieMyszki(sf::RenderWindow& window);

};