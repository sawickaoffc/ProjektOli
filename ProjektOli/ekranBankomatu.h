#pragma once
#include <iostream>
#include "bankomat.h"
#include "Guzik.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class ekranBankomatu
{
private:
	sf::RectangleShape tloEkranu;
	sf::RenderWindow* okienko;
	sf::Font font;
	sf::Text Powitanie;
	sf::Text WprowadzeniePinu;
	
public:
	ekranBankomatu() = default;
	void ekranPoczatkowy();
	void RysujEkranPoczatkowy();
	bool WpisywaniePinu();
	void RysujWpisywaniePinu();
	void Menu();
	void RysujMenu();
	void WplataGotowki();
	void RysujWplataGotowki();
	void WyplataGotowki();
	void RysujWyplataGotowki();
	void ZmianaPinu();
	void RysujZmianaPinu();
	void DostepneSrodki();
	void RysujDostepneSrodki();
	void PotwierdzeniePlatnosci();
	void RysujPotwierdzeniePlatnosci();
	void WyjecieKarty();
	void RysujWyjecieKarty();
	void RysujAktywacjaKarty();
	void AktywacjaKarty();
	Guzik tablicaMenu[9]; 
	void LimitMiesieczny();
	void RysujLimitMiesieczny();
	void Stworz(sf::RenderWindow* okienko);

	
};

