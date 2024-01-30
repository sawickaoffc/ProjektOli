#pragma once
#include <iostream>
#include "bankomat.h"
#include "Guzik.h"
#include "PobranieZPliku.h"
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

    void WyplataGotowki();
    void RysujWyplataGotowki();
    int a = 0; //do rysuj wyplaty

    void WplataGotowki();
    void RysujWplataGotowki();

    void InnaKwota();
    void RysujInnaKwote();

    void ZmianaPinu();
    void RysujZmianaPinu();

    void DostepneSrodki();
    void RysujDostepneSrodki();

    void Dane();
    void RysujDane();

    void ZmianaLimitu();
    void RysujZmianeLimitu();

    void WydaneBanknoty();
    void RysujWydaneBanknoty();

    void WyborKart();
    void RysujWyborKart();

    Guzik tablicaMenu[6];
    Guzik tablicaPinu[1];
    Guzik tablicaWydaneBanknoty[1];
    Guzik tablicaWyplacanie[8];
    Guzik tablicaSrodki[2];
    Guzik tablicaAktywacja[2];
    Guzik tablicaZmianyPinu[1];
    Guzik tablicaLimitu[6];
    Guzik tablicaZmianyLimitu[1];
    Guzik tablicaKart[4];
    Guzik tablicaWplacanie[6];
    Guzik tablicaDane[3];

    void Limity();
    void RysujLimity();
    void Stworz(sf::RenderWindow* okienko);
};
