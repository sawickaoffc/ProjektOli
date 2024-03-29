﻿#include "bankomat.h"
#include "ekranBankomatu.h"
#include <algorithm>
#include <SFML/Graphics/Font.hpp>
extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;
extern PobranieZPliku pobranie;


bankomat::bankomat(sf::RenderWindow* okienko)
{
	this->okienko = okienko;
	utworzTloEkranu();
	CzytaniePinu();
}

void bankomat::Stworz(sf::RenderWindow* okienko)
{
	this->okienko = okienko;
	utworzTloEkranu();
	CzytaniePinu();
	WybranieStrzalki(*okienko);
	WlozenieKarty(*okienko);
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(1300.0, 7000.0);
	saldo = dis(gen);
}

void bankomat::utworzTloEkranu()
{
	font.loadFromFile("Roboto-Bold.ttf");
	//ustalamy tlo calego ekranu

	tablicaPrzyciskow[0] = Guzik("", { 1000,500 }, 0, sf::Color{ 251, 138, 255 }, sf::Color::White, font);
	tablicaPrzyciskow[0].Czcionka(font);
	tablicaPrzyciskow[0].Polozenie({ 0,0 });

	//nastepnie tlo klawiatury poni¿ej ekranu

	tablicaPrzyciskow[1] = Guzik("", { 1000, 300 }, 0, sf::Color{ 251, 194, 255 }, sf::Color::White, font);
	tablicaPrzyciskow[1].Czcionka(font);
	tablicaPrzyciskow[1].Polozenie({ 0,500 });

	//opisujemy guziki z boku wyœwietlacza
	for (int i = 1; i < 5; i++) {
		tablicaPrzyciskow[i + 1] = Guzik("->", { 70, 60 }, 40, sf::Color(30, 0, 86), sf::Color::White, font);
		tablicaPrzyciskow[i + 1].Czcionka(font);
		float liczbaFloat = static_cast<float>(100 * i - 30);
		tablicaPrzyciskow[i + 1].Polozenie({ 40, liczbaFloat });
		tablicaPrzyciskow[i + 1].set_value(i);
	}

	for (int i = 1; i < 5; i++) {
		tablicaPrzyciskow[i + 5] = Guzik("<-", { 70, 60 }, 40, sf::Color(30, 0, 86), sf::Color::White, font);
		tablicaPrzyciskow[i + 5].Czcionka(font);
		float liczbaFloat = static_cast<float>(100 * i - 30);
		tablicaPrzyciskow[i + 5].Polozenie({ 890, liczbaFloat });
		tablicaPrzyciskow[i + 5].set_value(i + 4);
	}

	// klawiatura pin
	for (int i = 1; i < 6; i++) {
		tablicaPrzyciskow[i + 9] = Guzik(std::to_string(i), { 90, 80 }, 40, sf::Color(251, 138, 255), sf::Color::Black, font);
		tablicaPrzyciskow[i + 9].Czcionka(font);
		float liczbaFloat = static_cast<float>(140 * i - 40);
		tablicaPrzyciskow[i + 9].Polozenie({ liczbaFloat , 560 });
		tablicaPrzyciskow[i + 9].set_value(i);
	}

	for (int i = 6; i < 10; i++) {
		tablicaPrzyciskow[i + 10] = Guzik(std::to_string(i), { 90, 80 }, 40, sf::Color(251, 138, 255), sf::Color::Black, font);
		tablicaPrzyciskow[i + 10].Czcionka(font);
		float liczbaFloat = static_cast<float>(140 * (i - 5)  - 40);
		tablicaPrzyciskow[i + 10].Polozenie({ liczbaFloat , 680 });
		tablicaPrzyciskow[i + 10].set_value(i);
	}



	tablicaPrzyciskow[15] = Guzik("0", { 90,80 }, 40, sf::Color(251, 138, 255), sf::Color::Black, font);
	tablicaPrzyciskow[15].Czcionka(font);
	tablicaPrzyciskow[15].Polozenie({ 660,680 });
	tablicaPrzyciskow[15].set_value(0);

	tablicaPrzyciskow[20] = Guzik("Wstecz", { 120,80 }, 30, sf::Color(251, 138, 255), sf::Color::Black, font);
	tablicaPrzyciskow[20].Czcionka(font);
	tablicaPrzyciskow[20].Polozenie({ 770,560 });
	tablicaPrzyciskow[20].set_value(-2);

	tablicaPrzyciskow[21] = Guzik("Enter", { 120,80 }, 30, sf::Color(251, 138, 255), sf::Color::Black, font);
	tablicaPrzyciskow[21].Czcionka(font);
	tablicaPrzyciskow[21].Polozenie({ 770,680 });
	tablicaPrzyciskow[21].set_value(-3);
	//	font.loadFromFile("Roboto-Bold.ttf"); //pobieramy czcionke do napisów


		//robie przycisk do ekranu
	tablicaPrzyciskow[22] = Guzik("Wloz karte", { 260,100 }, 30, sf::Color{ 251, 194, 255 }, sf::Color::Black, font);
	tablicaPrzyciskow[22].Czcionka(font);
	tablicaPrzyciskow[22].Polozenie({ 570,40 });
}


void bankomat::rysujBankomat(sf::RenderWindow& okienko) {
	for (int i = 0; i < 22; ++i) {
		tablicaPrzyciskow[i].RysujPrzycisk(okienko);
	}
}


bool bankomat::CzytaniePinu() {
	for (int i = 10; i < 22; i++) {
		if (tablicaPrzyciskow[i].PolozenieMyszki(*okienko) == true && pobranie.zablokowanieKarty == false) {

			if (tablicaPrzyciskow[i].get_value() == -2 && petla > 0) { // delete
				petla--;
			}

			else if (tablicaPrzyciskow[i].get_value() == -3) {

				if (petla >= 3 && czyPierwszePodaniePinu) {
					czyPierwszePodaniePinu = false;
					is_valid_pin = true;

					obecnyPIN = "";
					for (int j = 0; j < 4; j++) {
						obecnyPIN += std::to_string(pin[j]);
					}
					pobranie.ZapisDoKarty(pobranie.daneKarty);
				}
				else if (petla >= 3 && !czyPierwszePodaniePinu) {
					string pin_str = ""; // tablica -> string
					for (int j = 0; j < 4; j++) {
						pin_str += std::to_string(pin[j]);
					}
					petla = 0;
					if (pin_str == obecnyPIN) {
						is_valid_pin = true;
					}
					else {
						cout << "Podano niepoprawy pin" << endl;
						is_valid_pin = false;
						iloscProbPin--;
						if (iloscProbPin == 0) {
							pobranie.zablokowanieKarty = true;
							pobranie.ZapisDoKarty(pobranie.daneKarty);
						}
					}
				}

				else if (petla < 3) {
					cout << "Dokoncz pin" << endl;
				}
			}

			if (petla >= 4) {
				break;
			}

			if (tablicaPrzyciskow[i].get_value() >= 0) {
				pin[petla] = tablicaPrzyciskow[i].get_value();
				petla++;
			}
		}
	}
	// wyswietlanie pinu
	string PIN = "";
	for (int j = 0; j < petla; ++j) {
		PIN += std::to_string(pin[j]);
	}
	//cout << "PIN:  " << PIN << endl;
	//cout << "obecnyPIN:  " << obecnyPIN << "\n\n";

	return is_valid_pin;
}



int bankomat::WybranieStrzalki(sf::RenderWindow& okienko)
{
	if (sf::Event::MouseButtonPressed) {
		for (int i = 2; i < 10; i++) {
			if (tablicaPrzyciskow[i].PolozenieMyszki(okienko) == true) {
				return tablicaPrzyciskow[i].get_value();
			}
		}
	}
	return 0;
}


bool bankomat::WlozenieKarty(sf::RenderWindow& okienko)
{
	if (sf::Event::MouseButtonPressed && bankomat1.tablicaPrzyciskow[22].PolozenieMyszki(okienko) == true) {
		return true;
	}
	else
		return false;
}

bool bankomat::WarunekWyplat()
{
	pobranie.PorownanieDat();
	pobranie.PobranieZKarty(pobranie.daneKarty);

	if (wyplataDzienna == stoi(limitZwykly) || wyplataDzienna == stoi(limitDzienny) || wyplataDzienna == stoi(limitMiesieczny) || wyplataMiesieczna == stoi(limitMiesieczny)) {
		czymozna = false;
	}
	else if (wyplataDzienna != stoi(limitZwykly) && wyplataDzienna != stoi(limitDzienny) && wyplataDzienna != stoi(limitMiesieczny) && wyplataMiesieczna != stoi(limitMiesieczny)) {
		czymozna = true;
	}
	pobranie.ZapisDoKarty(pobranie.daneKarty);

	if (stoi(kwota) % 10 == 0 && stoi(kwota) <= saldo && stoi(kwota) <= stoi(limitZwykly) &&
		(stoi(limitZwykly) - wyplataDzienna) >= stoi(kwota) && (stoi(limitMiesieczny) - wyplataMiesieczna) >= stoi(kwota) && czymozna == true) {
		ekranbankomatu1.a = 0;
		return true;
	}
	else {
		cout << "Nie spelniono warunkow wyplaty"<<endl;
		return false;
	}
	
}

void bankomat::Wplata()
{
	bankomat1.saldo += stof(bankomat1.kwota);
	pobranie.ZapisDoKarty(pobranie.daneKarty);
	pobranie.ZapisPoWplacie("bankomatZasobnik.txt");
	for (int i = 0; i < 6; i++) {
		wydanie[i] = 0;
	}
}



bool bankomat::PobierzKwote() {
	for (int i = 10; i < 22; i++) {
		if (tablicaPrzyciskow[i].PolozenieMyszki(*okienko) == true && sf::Event::MouseButtonPressed) {
			if (tablicaPrzyciskow[i].get_value() >= 0) { // delete
				kwota += std::to_string(tablicaPrzyciskow[i].get_value());
			}
			else if (tablicaPrzyciskow[i].get_value() == -2) { // delete
				kwota = kwota.substr(0, kwota.length() - 1);
			}
			else if (tablicaPrzyciskow[i].get_value() == -3) { // enter
				return true; //PotwierdzeniePlatnosci();
			}
		}
	}
	return false;
}

string bankomat::WydajBanknoty(int kwota) {
	int pomocnicza = kwota;
	int dziele;
	int reszta;
	int czywystarczy;
	for (int i = 0; i < 6; i++)
	{
		if (pomocnicza >= banknoty[i]) {
			dziele = pomocnicza / banknoty[i];
			reszta = pomocnicza % banknoty[i];

			if (banknoty[i] == 500 && dziele <= zasobnik[0])
			{
				pomocnicza = reszta;
				wydanie[0] = dziele;
			}

			if (banknoty[i] == 200 && dziele <= zasobnik[1])
			{
				pomocnicza = reszta;
				wydanie[1] = dziele;
			}

			if (banknoty[i] == 100 && dziele <= zasobnik[2])
			{
				pomocnicza = reszta;
				wydanie[2] = dziele;
			}

			if (banknoty[i] == 50 && dziele <= zasobnik[3])
			{
				pomocnicza = reszta;
				wydanie[3] = dziele;
			}

			if (banknoty[i] == 20 && dziele <= zasobnik[4])
			{
				pomocnicza = reszta;
				wydanie[4] = dziele;
			}

			if (banknoty[i] == 10 && dziele <= zasobnik[5])
			{
				pomocnicza = reszta;
				wydanie[5] = dziele;

			}
			if (pomocnicza == 0)
			{
				i = 1000;
			}
		}

		if (pomocnicza == 0)
		{
			pobranie.ZapisPoWyplacie("bankomatZasobnik.txt");

			for (int i = 0; i < 6; i++) {
				if (wydanie[i] != 0) {

					ilosc += std::to_string(banknoty[i]);
					ilosc += "*";
					ilosc += std::to_string(wydanie[i]);
					ilosc += ", ";
				}
			}
			bankomat1.saldo -= stof(bankomat1.kwota);
			bankomat1.wyplataDzienna += stof(bankomat1.kwota);
			bankomat1.wyplataMiesieczna += stof(bankomat1.kwota);
			pobranie.ZapisDoKarty(pobranie.daneKarty);
			ekranbankomatu1.a = 0;
			for (int i = 0; i < 6; i++) {
				wydanie[i] = 0;
			}
			return ilosc;
		}

	}
	if (pomocnicza != 0)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i <= 5; i++) {
				wydanie[i] = pom[i];
			}
			pomocnicza = kwota;
			for (int i = 0; i < 6; i++)
			{
				if (pomocnicza >= banknoty[i]) {
					dziele = pomocnicza / banknoty[i];
					reszta = pomocnicza % banknoty[i];
					if (j != 5 && banknoty[i] == 500 && dziele <= zasobnik[0])
					{
						pomocnicza = reszta;
						wydanie[0] = dziele;
					}
					if (j != 4 && banknoty[i] == 200 && dziele <= zasobnik[1])
					{
						pomocnicza = reszta;
						wydanie[1] = dziele;
					}
					if (j != 3 && banknoty[i] == 100 && dziele <= zasobnik[2])
					{
						pomocnicza = reszta;
						wydanie[2] = dziele;
					}
					if (j != 2 && banknoty[i] == 50 && dziele <= zasobnik[3])
					{
						pomocnicza = reszta;
						wydanie[3] = dziele;
					}
					if (j != 1 && banknoty[i] == 20 && dziele <= zasobnik[4])
					{
						pomocnicza = reszta;
						wydanie[4] = dziele;
					}
					if (j != 0 && banknoty[i] == 10 && dziele <= zasobnik[5])
					{
						pomocnicza = reszta;
						wydanie[5] = dziele;
					}
					if (pomocnicza == 0)
					{
						pobranie.ZapisPoWyplacie("bankomatZasobnik.txt");
						for (int i = 0; i < 6; i++) {
							if (wydanie[i] != 0) {
								ilosc += std::to_string(banknoty[i]);
								ilosc += "*";
								ilosc += std::to_string(wydanie[i]);
								ilosc += ",   ";
							}
						}
						bankomat1.saldo -= stof(bankomat1.kwota);
						bankomat1.wyplataDzienna += stof(bankomat1.kwota);
						bankomat1.wyplataMiesieczna += stof(bankomat1.kwota);
						ekranbankomatu1.a = 0;
						pobranie.ZapisDoKarty(pobranie.daneKarty);
						return ilosc;
					}
				}
			}
		}
	}
	if (pomocnicza != 0)
	{
		return "NIE MOZNA WYPLACIC";
		ekranbankomatu1.a = 0;
	}
}