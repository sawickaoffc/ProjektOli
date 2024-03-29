#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Guzik.h"
#include "PobranieZPliku.h"

#include <string>
#include <random>
#include <iostream>

class bankomat
{
private:
    sf::Font font;
    sf::RenderWindow* okienko;


public:
    int iloscProbPin = 3;
    string obecnyPIN = ""; // do logowania
    string numerKonta;
    string blokada;
    bool is_valid_pin = false;
    bool czyPierwszePodaniePinu = false;
    int pin[4]; // do wpisywania
    int petla = 0;

    string kwota = "";
    string limitMiesieczny;
    string limitDzienny;
    string limitZwykly;

    int wyplataDzienna;
    int wyplataMiesieczna;
    int wydanie[6] = { 0,0,0,0,0,0};
    int banknoty[6] = { 500, 200, 100, 50, 20, 10 };
    int zasobnik[6];
    int pom[6] = { 0,0,0,0,0,0 };

    bool czymozna;  //zalezy od pliku czy ciagle mozemy wyplacic czy juz przekroczono limit
    string ilosc = ""; //do wyswietlania
    float saldo = 0;
    bankomat() = default;
    bankomat(sf::RenderWindow* okienko);

    void utworzTloEkranu();
    void rysujBankomat(sf::RenderWindow& okienko);

    bool CzytaniePinu();
    bool WarunekWyplat();
    void Wplata();
    bool PobierzKwote();

    string WydajBanknoty(int kwota);
    void Stworz(sf::RenderWindow* okienko);
    Guzik tablicaPrzyciskow[23];

    int WybranieStrzalki(sf::RenderWindow& okienko);
    bool WlozenieKarty(sf::RenderWindow& okienko);
};