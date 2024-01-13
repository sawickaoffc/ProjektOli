#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Guzik.h"
#include <string>
#include <random>
#include <iostream>

class bankomat
{
private:
    sf::Font font;
    sf::RenderWindow* okienko;


public:
    string obecnyPIN = ""; // do logowania
    bool is_valid_pin = false;
    bool czyPierwszePodaniePinu = true;
    int pin[4]; // do wpisywania
    int petla = 0;
    string karta = "nieaktywna";
    string kwota = "";
    string limitMiesieczny = "5000";
    string limitDzienny = "500";
    string limitZwykly = "200";
    //vector<vector<int>> banknoty { {10, 1}, {20, 2}, {50, 1}, {100, 1}, {200, 2}, {500, 1000} };
    vector<int> wydanie{ 0,0,0,0,0,0 };
    vector<int> banknoty{ 10, 20, 50, 100, 200, 500 };
    string ilosc;
    float stanKonta = 0;
    bankomat() = default;
    bankomat(sf::RenderWindow* okienko);
    void utworzTloEkranu();
    void rysujBankomat(sf::RenderWindow& okienko);
    bool CzytaniePinu();
    bool PobierzKwote();
    vector<int> WydajBanknoty(int kwota);
    void Stworz(sf::RenderWindow* okienko);
    Guzik tablicaPrzyciskow[23];
    int WybranieStrzalki(sf::RenderWindow& okienko);
    bool WlozenieKarty(sf::RenderWindow& okienko);
};