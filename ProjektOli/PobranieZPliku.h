#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <iostream>
#include "bankomat.h"
#include "ekranBankomatu.h"
#include "Guzik.h"
using namespace std;

class PobranieZPliku
{
private:
	sf::Font font;
	sf::RenderWindow* okienko;
	string numerKarty;

public:
	string daneKarty = "karta1.txt";
	string zasobnik = "bankomatZasobnik.txt";
	bool zablokowanieKarty = PobranieZKarty(daneKarty);
	void Stworz(sf::RenderWindow* okienko);
	PobranieZPliku() = default;
	bool PobranieZKarty(const string& plik);
	void PobranieZBankomatu(const string& nazwaPliku);
	void ZapisPoWyplacie(const string& nazwaPliku);
	void ZapisDoKarty(const string& nazwaPliku);
};

