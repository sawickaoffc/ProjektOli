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
    getline(plik, numerKarty);
    getline(plik, bankomat1.obecnyPIN);
    getline(plik, pomocnicza); 
    bankomat1.saldo = stof(pomocnicza);
    getline(plik, bankomat1.limitDzienny);
    getline(plik, bankomat1.limitMiesieczny);
    getline(plik, bankomat1.limitZwykly);
    getline(plik, pomocnicza);
    if (pomocnicza == "0") {
        return false;       //czy Karta jest zablokowana (nie jest)
    }
    else {
        return true;
    }
    getline(plik, pomocnicza); 
    bankomat1.czymozna= stoi(pomocnicza);
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

void PobranieZPliku::ZapisDoKarty(const string& nazwaPliku) {
    bankomat1.saldo -= stof(bankomat1.kwota);
    string zapis = to_string(bankomat1.saldo);
    std::ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        plik << numerKarty << endl;
        plik << bankomat1.obecnyPIN << endl;
        plik << zapis << endl;
        plik << bankomat1.limitDzienny << endl;
        plik << bankomat1.limitMiesieczny << endl;
        plik << bankomat1.limitZwykly << endl;
        plik << to_string(PobranieZKarty(daneKarty)) << endl;
    }
}

