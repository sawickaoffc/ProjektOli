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

	tablicaPrzyciskow[2] = Guzik("->", { 70,50 }, 40, sf::Color{ 65, 75, 217 }, sf::Color::White, font);
	tablicaPrzyciskow[2].Czcionka(font);
	tablicaPrzyciskow[2].Polozenie({ 40,70 });

	tablicaPrzyciskow[3] = Guzik("->", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[3].Czcionka(font);
	tablicaPrzyciskow[3].Polozenie({ 40,170 });

	tablicaPrzyciskow[4] = Guzik("->", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[4].Czcionka(font);
	tablicaPrzyciskow[4].Polozenie({ 40,270 });

	tablicaPrzyciskow[5] = Guzik("->", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[5].Czcionka(font);
	tablicaPrzyciskow[5].Polozenie({ 40,370 });

	tablicaPrzyciskow[6] = Guzik("<-", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[6].Czcionka(font);
	tablicaPrzyciskow[6].Polozenie({ 890,70 });

	tablicaPrzyciskow[7] = Guzik("<-", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[7].Czcionka(font);
	tablicaPrzyciskow[7].Polozenie({ 890,170 });

	tablicaPrzyciskow[8] = Guzik("<-", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[8].Czcionka(font);
	tablicaPrzyciskow[8].Polozenie({ 890,270 });

	tablicaPrzyciskow[9] = Guzik("<-", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[9].Czcionka(font);
	tablicaPrzyciskow[9].Polozenie({ 890,370 });

	//dodajemy przyciski do klawiatury poni¿ej wyœwietlacza


	tablicaPrzyciskow[10] = Guzik("1", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[10].Czcionka(font);
	tablicaPrzyciskow[10].Polozenie({ 150,560 });
	tablicaPrzyciskow[10].set_value(1);

	tablicaPrzyciskow[11] = Guzik("2", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[11].Czcionka(font);
	tablicaPrzyciskow[11].Polozenie({ 290,560 });
	tablicaPrzyciskow[11].set_value(2);

	tablicaPrzyciskow[12] = Guzik("3", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[12].Czcionka(font);
	tablicaPrzyciskow[12].Polozenie({ 430,560 });
	tablicaPrzyciskow[12].set_value(3);

	tablicaPrzyciskow[13] = Guzik("4", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[13].Czcionka(font);
	tablicaPrzyciskow[13].Polozenie({ 570,560 });
	tablicaPrzyciskow[13].set_value(4);

	tablicaPrzyciskow[14] = Guzik("5", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[14].Czcionka(font);
	tablicaPrzyciskow[14].Polozenie({ 710,560 });
	tablicaPrzyciskow[14].set_value(5);

	tablicaPrzyciskow[15] = Guzik("0", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[15].Czcionka(font);
	tablicaPrzyciskow[15].Polozenie({ 710,680 });
	tablicaPrzyciskow[15].set_value(0);

	tablicaPrzyciskow[16] = Guzik("6", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[16].Czcionka(font);
	tablicaPrzyciskow[16].Polozenie({ 150,680 });
	tablicaPrzyciskow[16].set_value(6);

	tablicaPrzyciskow[17] = Guzik("7", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[17].Czcionka(font);
	tablicaPrzyciskow[17].Polozenie({ 290,680 });
	tablicaPrzyciskow[17].set_value(7);

	tablicaPrzyciskow[18] = Guzik("8", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[18].Czcionka(font);
	tablicaPrzyciskow[18].Polozenie({ 430,680 });
	tablicaPrzyciskow[18].set_value(8);

	tablicaPrzyciskow[19] = Guzik("9", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[19].Czcionka(font);
	tablicaPrzyciskow[19].Polozenie({ 570,680 });
	tablicaPrzyciskow[19].set_value(9);

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
	cout << "obecnyPIN:  " << obecnyPIN << endl;

	return is_valid_pin;
}




int bankomat::WybranieStrzalki(sf::RenderWindow& okienko)
{
	if (sf::Event::MouseButtonPressed) {
		for (int i = 2; i < 10; i++)
		{
			if (tablicaPrzyciskow[i].PolozenieMyszki(okienko) == true) {
				switch (i) {
				case 2:
					return 1;
					break;
				case 3:
					return 2;
					break;
				case 4:
					return 3;
					break;
				case 5:
					return 4;
					break;
				case 6:
					return 5;
					break;
				case 7:
					return 6;
					break;
				case 8:
					return 7;
					break;
				case 9:
					return 8;
					break;
				}
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
//pomysl: stworzenie szablonu do prostok¹ta i podpinamy przycisk jako ogolny obraz 
// pod nasze poszczegolne prostokaty i wtedy sprawdzamy z czym sie porywa nam myszka