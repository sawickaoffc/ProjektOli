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
	sf::Text MenuNaglowek;
	sf::Text MenuAnuluj;
	sf::Text MenuAktywacjaKarty;
	sf::Text MenuWyplataGotowki;
	sf::Text MenuWplataGotowki;
	sf::Text MenuDostepneSrodki;
	sf::Text MenuZmianaPin;
//	sf::RectangleShape KsztaltMenuNaglowek;
	sf::RectangleShape KsztaltMenuAnuluj;
	sf::RectangleShape KsztaltMenuAktywacjaKarty;
	sf::RectangleShape KsztaltMenuWyplataGotowki;
	sf::RectangleShape KsztaltMenuWplataGotowki;
	sf::RectangleShape KsztaltMenuDostepneSrodki;
	sf::RectangleShape KsztaltMenuZmianaPin;

public:
	string obecnyPIN; 
	ekranBankomatu() = default;
	void ekranPoczatkowy();
	void RysujEkranPoczatkowy();
	string WpisywaniePinu();
	void RysujWpisywaniePinu();
	void Menu();
	void RysujMenu();
	void Anuluj();
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
	Guzik tablicaMenu[10]; 
	void LimitMiesieczny();
	void RysujLimitMiesieczny();
	void Stworz(sf::RenderWindow* okienko);

	
};

