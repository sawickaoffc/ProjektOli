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
    string obecnyPIN = "";
    bool is_valid_pin = false;
    bool czyPierwszePodaniePinu = true;
    int pin[4];
    int petla = 0;
    string kwota = "";
    float stanKonta = 0;
    bankomat() = default;
    bankomat(sf::RenderWindow* okienko);
    void utworzTloEkranu();
    void rysujBankomat(sf::RenderWindow& okienko);
    bool CzytaniePinu();
    bool PobierzKwote();
    void Stworz(sf::RenderWindow* okienko);
    Guzik tablicaPrzyciskow[23];
    int WybranieStrzalki(sf::RenderWindow& okienko);
    bool WlozenieKarty(sf::RenderWindow& okienko);

};