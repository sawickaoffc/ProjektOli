#pragma once
#include <map>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Guzik.h"
#include <string>
#include <random>
#include <iostream>
#include "bankomat.h"
#include "ekranBankomatu.h"


class ZasobnikBanknotow
{
private:
    sf::Font font;
    sf::RenderWindow* okienko;
    std::map<int, Banknoty> banknotes;

public:
    void addBanknotes(int denomination, int quantity);
    int getQuantity(int denomination);
    bool withdrawBanknotes(int denomination, int quantity);

    void Stworz(sf::RenderWindow* okienko);

    void WydawaniePieniedzy();

};