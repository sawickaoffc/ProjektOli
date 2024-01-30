#include "PobranieZPliku.h"

extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;
extern PobranieZPliku pobranie;

void PobranieZPliku::Stworz(sf::RenderWindow* okienko)
{
    this->okienko = okienko;
    PobranieZKarty(daneKarty);
    PobranieZBankomatu(zasobnik);
    ZapisPoWyplacie(zasobnik);
}

bool PobranieZPliku::PobranieZKarty(const string& nazwaPliku)
{
    string pomocnicza;
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie otworzono pliku karta" << std::endl;
    }
    getline(plik, bankomat1.numerKonta);
    getline(plik, bankomat1.obecnyPIN);
    getline(plik, pomocnicza);
    bankomat1.saldo = stof(pomocnicza);
    getline(plik, bankomat1.limitDzienny);
    getline(plik, bankomat1.limitMiesieczny);
    getline(plik, bankomat1.limitZwykly);
    getline(plik, pomocnicza);
    //cout << pomocnicza << endl;
    if (pomocnicza == "0") {
        bankomat1.blokada = "nie jest zablokowana";
        return false;       //czy Karta jest zablokowana (nie jest)
    }
    else if (pomocnicza == "1") {
        bankomat1.blokada = "jest zablokowana";
        return true;
    }
    getline(plik, pomocnicza);  // do wyplacania czy nie przekraczamy limitu
    if (pomocnicza == "0") {
        bankomat1.czymozna = false;       
    }
    else if(pomocnicza == "1"){
        bankomat1.czymozna = true;
    }
    getline(plik, pomocnicza); //ile juz wyplacilismy
    bankomat1.wyplata = stoi(pomocnicza);
}


void PobranieZPliku::PobranieZBankomatu(const string& nazwaPliku)
{
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie otworzono pliku zasobnik" << std::endl;
        return;
    }
    string pomocnicza;
    getline(plik, pomocnicza);
    bankomat1.zasobnik[0] = stof(pomocnicza);
    getline(plik, pomocnicza);
    bankomat1.zasobnik[1] = stof(pomocnicza);
    getline(plik, pomocnicza);
    bankomat1.zasobnik[2] = stof(pomocnicza);
    getline(plik, pomocnicza);
    bankomat1.zasobnik[3] = stof(pomocnicza);
    getline(plik, pomocnicza);
    bankomat1.zasobnik[4] = stof(pomocnicza);
    getline(plik, pomocnicza);
    bankomat1.zasobnik[5] = stof(pomocnicza);

}

void PobranieZPliku::ZapisPoWyplacie(const string& nazwaPliku)
{
    std::ofstream plik(nazwaPliku);

    if (plik.is_open()) {

        string pomocnicza;
        pomocnicza = to_string(bankomat1.zasobnik[0] - bankomat1.wydanie[0]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[1] - bankomat1.wydanie[1]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[2] - bankomat1.wydanie[2]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[3] - bankomat1.wydanie[3]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[4] - bankomat1.wydanie[4]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[5] - bankomat1.wydanie[5]);
        plik << pomocnicza << endl;
        plik.close();

    }
    else {
        std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
    }
}

void PobranieZPliku::ZapisPoWplacie(const string& nazwaPliku)
{
    std::ofstream plik(nazwaPliku);

    if (plik.is_open()) {

        string pomocnicza;
        pomocnicza = to_string(bankomat1.zasobnik[0] + bankomat1.wydanie[0]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[1] + bankomat1.wydanie[1]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[2] + bankomat1.wydanie[2]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[3] + bankomat1.wydanie[3]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[4] + bankomat1.wydanie[4]);
        plik << pomocnicza << endl;
        pomocnicza = to_string(bankomat1.zasobnik[5] + bankomat1.wydanie[5]);
        plik << pomocnicza << endl;
        plik.close();

    }
    else {
        std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
    }
}

void PobranieZPliku::ZapisDoKarty(const string& nazwaPliku) {
    string zapis = to_string(bankomat1.saldo);
    std::ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        plik << bankomat1.numerKonta << endl;
        plik << bankomat1.obecnyPIN << endl;
        plik << zapis << endl; //saldo
        plik << bankomat1.limitDzienny << endl;
        plik << bankomat1.limitMiesieczny << endl;
        plik << bankomat1.limitZwykly << endl;
        string blokada = "0";
        if (pobranie.zablokowanieKarty) {
            blokada = "1";
        }
        plik << blokada << endl; //zablokowanie karty

        string czymozna = "0";
        if (bankomat1.czymozna == true) {
            czymozna = "1";
        }
        plik << czymozna << endl; //czy mozna wyplacac z karty

        string wyplata = to_string(bankomat1.wyplata);
        plik << wyplata << endl;
    }
}