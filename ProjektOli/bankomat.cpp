#include "bankomat.h"
#include "ekranBankomatu.h"
#include <SFML/Graphics/Font.hpp>
extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;


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

}

void bankomat::utworzTloEkranu()
{
	font.loadFromFile("Roboto-Bold.ttf");
	//ustalamy t³o ca³ego ekranu

	tablicaPrzyciskow[0] = Guzik("", { 1000,500 }, 0, sf::Color{ 189, 76, 86 }, sf::Color::White, font);
	tablicaPrzyciskow[0].Czcionka(font);
	tablicaPrzyciskow[0].Polozenie({ 0,0 });

	//nastêpnie t³o klawiatury poni¿ej ekranu

	tablicaPrzyciskow[1] = Guzik("", { 1000, 300 }, 0, sf::Color{ 184, 187, 230 }, sf::Color::White, font);
	tablicaPrzyciskow[1].Czcionka(font);
	tablicaPrzyciskow[1].Polozenie({ 0,0 });

	//opisujemy guziki z boku wyœwietlacza
	for (int i = 1; i < 5; i++) {
		tablicaPrzyciskow[i + 1] = Guzik("->", { 70, 60 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
		tablicaPrzyciskow[i + 1].Czcionka(font);
		float liczbaFloat = static_cast<float>(100 * i - 30);
		tablicaPrzyciskow[i + 1].Polozenie({ 40, liczbaFloat });
		tablicaPrzyciskow[i + 1].set_value(i);
	}

	for (int i = 1; i < 5; i++) {
		tablicaPrzyciskow[i + 5] = Guzik("<-", { 70, 60 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
		tablicaPrzyciskow[i + 5].Czcionka(font);
		float liczbaFloat = static_cast<float>(100 * i - 30);
		tablicaPrzyciskow[i + 5].Polozenie({ 890, liczbaFloat });
		tablicaPrzyciskow[i + 5].set_value(i + 4);
	}

	// klawiatura pin
	for (int i = 1; i < 6; i++) {
		tablicaPrzyciskow[i + 9] = Guzik(std::to_string(i), { 70, 60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
		tablicaPrzyciskow[i + 9].Czcionka(font);
		float liczbaFloat = static_cast<float>(140 * i);
		tablicaPrzyciskow[i + 9].Polozenie({ liczbaFloat + 10, 560 });
		tablicaPrzyciskow[i + 9].set_value(i);
	}

	for (int i = 6; i < 10; i++) {
		tablicaPrzyciskow[i + 10] = Guzik(std::to_string(i), { 70, 60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
		tablicaPrzyciskow[i + 10].Czcionka(font);
		float liczbaFloat = static_cast<float>(140 * (i - 5));
		tablicaPrzyciskow[i + 10].Polozenie({ liczbaFloat + 10, 680 });
		tablicaPrzyciskow[i + 10].set_value(i);
	}



	tablicaPrzyciskow[15] = Guzik("0", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[15].Czcionka(font);
	tablicaPrzyciskow[15].Polozenie({ 710,680 });
	tablicaPrzyciskow[15].set_value(0);

	tablicaPrzyciskow[20] = Guzik("Usun", { 100,60 }, 20, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[20].Czcionka(font);
	tablicaPrzyciskow[20].Polozenie({ 840,560 });
	tablicaPrzyciskow[20].set_value(-2);

	tablicaPrzyciskow[21] = Guzik("Enter", { 100,60 }, 20, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[21].Czcionka(font);
	tablicaPrzyciskow[21].Polozenie({ 840,680 });
	tablicaPrzyciskow[21].set_value(-3);
	//	font.loadFromFile("Roboto-Bold.ttf"); //pobieramy czcionke do napisów


		//robie przycisk do ekranu
	tablicaPrzyciskow[22] = Guzik("Wlozono karte", { 200,80 }, 30, sf::Color{ 59, 17, 82 }, sf::Color::White, font);
	tablicaPrzyciskow[22].Czcionka(font);
	tablicaPrzyciskow[22].Polozenie({ 630,20 });
}


void bankomat::rysujBankomat(sf::RenderWindow& okienko) {
	for (int i = 0; i < 22; ++i) {
		tablicaPrzyciskow[i].RysujPrzycisk(okienko);
	}
}


bool bankomat::CzytaniePinu() {
	for (int i = 10; i < 22; i++) {
		if (tablicaPrzyciskow[i].PolozenieMyszki(*okienko) == true) {

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
				}
				else if (petla >= 3 && !czyPierwszePodaniePinu) {
					string pin_str = ""; // tablica -> string
					for (int j = 0; j < 4; j++) {
						pin_str += std::to_string(pin[j]);
					}
					cout << pin_str << "  " << obecnyPIN << endl;
					if (pin_str == obecnyPIN) {
						is_valid_pin = true;
					}
					else {
						is_valid_pin = false;
					}
				}

				else if (petla < 3) {
					cout << "Dokoncz pin" << endl;
				}

				else {
					cout << "Podano niepoprawy pin" << endl;
					petla = 0;
					break;
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
	cout << "PIN:  " << PIN << endl;
	cout << "obecnyPIN:  " << obecnyPIN << "\n\n";

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


bool bankomat::PobierzKwote() {
	for (int i = 10; i < 22; i++) {
		if (tablicaPrzyciskow[i].PolozenieMyszki(*okienko) == true) {

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


//pomysl: stworzenie szablonu do prostok¹ta i podpinamy przycisk jako ogolny obraz 
// pod nasze poszczegolne prostokaty i wtedy sprawdzamy z czym sie porywa nam myszka