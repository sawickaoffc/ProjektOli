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
#include <chrono>
#include <ctime>

using namespace std;

class PobranieZPliku
{
private:
	sf::Font font;
	sf::RenderWindow* okienko;
	string numerKarty;
	int dzien;
	int miesiac;
	int rok;

public:
	string daneKarty = "karta1.txt";

	//auto data = std::chrono::system_clock::now();
	string zasobnik = "bankomatZasobnik.txt";
	bool zablokowanieKarty;
	void Stworz(sf::RenderWindow* okienko);
	PobranieZPliku() = default;
	void PobranieZKarty(const string& plik);
	void PobranieZBankomatu(const string& nazwaPliku);
	void ZapisPoWyplacie(const string& nazwaPliku);
	void ZapisPoWplacie(const string& nazwaPliku);
	void ZapisDoKarty(const string& nazwaPliku);
	void Data();
	bool PorownanieDat();
};

