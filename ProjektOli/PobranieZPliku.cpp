#include "PobranieZPliku.h"
#pragma warning(suppress : 4996)

extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;
extern PobranieZPliku pobranie;

void PobranieZPliku::Stworz(sf::RenderWindow* okienko)
{
    this->okienko = okienko;
    PobranieZKarty(daneKarty);
    PobranieZBankomatu(zasobnik);
    ZapisPoWyplacie(zasobnik);
    PorownanieDat();
}

void PobranieZPliku::PobranieZKarty(const string& nazwaPliku)
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
        zablokowanieKarty = false;
        bankomat1.blokada = "nie jest zablokowana";
        //czy Karta jest zablokowana (nie jest)
    }
    if (pomocnicza == "1") {
        bankomat1.blokada = "jest zablokowana";
        zablokowanieKarty = true;
    }

    getline(plik, pomocnicza);  // do wyplacania czy nie przekraczamy limitu
    if (pomocnicza == "0" ) {
        bankomat1.czymozna = false;       
    }
    if(pomocnicza == "1"){
        bankomat1.czymozna = true;
    }

    string nowa;
    getline(plik, nowa); //ile juz wyplacilismy dziennie
    bankomat1.wyplataDzienna = stoi(nowa);

    getline(plik, nowa); //ile juz wyplacilismy miesiecznie
    bankomat1.wyplataMiesieczna = stoi(nowa);

    getline(plik, nowa); 
    dzien = stoi(nowa);

    getline(plik, nowa);
    miesiac = stoi(nowa);

    getline(plik, nowa);
    rok = stoi(nowa);

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
        std::cerr << "Nie mo�na otworzy� pliku." << std::endl;
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
        std::cerr << "Nie mo�na otworzy� pliku." << std::endl;
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

        string wyplataDzienna = to_string(bankomat1.wyplataDzienna);
        plik << wyplataDzienna << endl;

        string wyplataMiesieczna = to_string(bankomat1.wyplataMiesieczna);
        plik << wyplataMiesieczna << endl;

        string dzien = to_string(pobranie.dzien);
        plik << dzien << endl;

        string miesiac = to_string(pobranie.miesiac);
        plik << miesiac << endl;

        string rok = to_string(pobranie.rok);
        plik << rok << endl;
    }
}

void PobranieZPliku::PorownanieDat()
{
    int d = dzien;
    int m = miesiac;
    int r = rok;
    std::time_t currentTime = std::time(nullptr);
    std::tm localTime;

    if (r == localTime.tm_year + 1900 && m == localTime.tm_mon + 1 && d == localTime.tm_mday) {
        return;
    }
    else if(r == localTime.tm_year + 1900 && m == localTime.tm_mon + 1) {
        bankomat1.wyplataDzienna = 0;
        dzien = localTime.tm_mday;
    }
    else {
        rok = localTime.tm_year + 1900;
        miesiac = localTime.tm_mon + 1;
        dzien = localTime.tm_mday;
        bankomat1.wyplataMiesieczna = 0;
    }
    return;
}
