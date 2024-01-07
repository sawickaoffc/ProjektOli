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

    void Potwierdzenie();
    void RysujPotwierdzenie();

    void WyjecieKarty();
    void RysujWyjecieKarty();

    void AktywacjaKarty();
    void RysujAktywacjaKarty();

    void ZmianaLimitu();
    void RysujZmianeLimitu();

    Guzik tablicaMenu[9];
    Guzik tablicaPinu[1];
    Guzik tablicaWplacanie[2];
    Guzik tablicaWyplacanie[2];
    Guzik tablicaPotwierdzenie[2];
    Guzik tablicaSrodki[2];
    Guzik tablicaAktywacja[3];
    Guzik tablicaZmianyPinu[2];
    Guzik tablicaLimitu[3];
    Guzik tablicaZmianyLimitu[2];

    void LimitMiesieczny();
    void RysujLimitMiesieczny();
    void Stworz(sf::RenderWindow* okienko);
};
