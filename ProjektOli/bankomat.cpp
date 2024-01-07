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
	tablicaPrzyciskow[0].Polozenie({ 0,0 });

	//nastêpnie t³o klawiatury poni¿ej ekranu

	tablicaPrzyciskow[1] = Guzik("", { 1000, 300 }, 0, sf::Color{ 184, 187, 230 }, sf::Color::White, font);
	tablicaPrzyciskow[1].Polozenie({ 0,0 });
	//opisujemy guziki z boku wyœwietlacza
	 
	tablicaPrzyciskow[2] = Guzik("->", { 70,50 }, 40, sf::Color{ 65, 75, 217 }, sf::Color::White, font);
	tablicaPrzyciskow[2].Polozenie({ 40,70 });

	tablicaPrzyciskow[3] = Guzik("->", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
	tablicaPrzyciskow[3].Polozenie({ 40,170 });

	tablicaPrzyciskow[4] = Guzik("->", { 70, 50 }, 40, sf::Color(65, 75, 217), sf::Color::White, font);
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

	for (int i = 1; i < 6; i++) {
		tablicaPrzyciskow[i+9] = Guzik(std::to_string(i), {70, 60}, 40, sf::Color(59, 17, 82), sf::Color::White, font);
		tablicaPrzyciskow[i+9].Czcionka(font);
		float liczbaFloat = static_cast<float>(140*i);
		tablicaPrzyciskow[i+9].Polozenie({liczbaFloat+10, 560});
		tablicaPrzyciskow[i+9].set_value(i);
	}
	for (int i = 6; i < 10; i++) {
		tablicaPrzyciskow[i + 10] = Guzik(std::to_string(i), { 70, 60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
		tablicaPrzyciskow[i + 10].Czcionka(font);
		float liczbaFloat = static_cast<float>(140 * (i-5));
		tablicaPrzyciskow[i + 10].Polozenie({ liczbaFloat + 10, 680 });
		tablicaPrzyciskow[i + 10].set_value(i);
	}

	tablicaPrzyciskow[15] = Guzik("0", { 70,60 }, 40, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[15].Polozenie({ 710,680 });
	tablicaPrzyciskow[15].set_value(0);

	tablicaPrzyciskow[20] = Guzik("Usun", { 100,60 }, 20, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[20].Polozenie({ 840,560 });
	tablicaPrzyciskow[20].set_value(-2);

	tablicaPrzyciskow[21] = Guzik("Enter", { 100,60 }, 20, sf::Color(59, 17, 82), sf::Color::White, font);
	tablicaPrzyciskow[21].Polozenie({ 840,680 });
	tablicaPrzyciskow[21].set_value(-3);
	//	font.loadFromFile("Roboto-Bold.ttf"); //pobieramy czcionke do napisów
	
	//robie przycisk do ekranu
	tablicaPrzyciskow[22] = Guzik("Wlozono karte", { 200,80 }, 30, sf::Color{ 59, 17, 82 }, sf::Color::White, font);
	tablicaPrzyciskow[22].Polozenie({ 630,20 });
}

void bankomat::rysujBankomat(sf::RenderWindow& okienko) {
	for (int i = 0; i < 22; ++i) {
		tablicaPrzyciskow[i].RysujPrzycisk(okienko);
	}
}

bool bankomat::CzytaniePinu() {
	for (int i = 10; i < 22; i++) {
		if (tablicaPrzyciskow[i].PolozenieMyszki(*okienko) == true) { //sprawdzam czy najechaliśmy na dany przycisk

			if (tablicaPrzyciskow[i].get_value() == -2 && petla > 0) { // sprawdzamy czy to nasz przycisk usun
				petla--; //cofam sie do poprzedniego indeksu żeby nadpisać ten wyraz
			}

			else if (tablicaPrzyciskow[i].get_value() == -3) {  // sprawdzamy czy to nasz przycisk enter

				if (petla >= 3 && czyPierwszePodaniePinu) {  // zapisujemy nasz pin
					czyPierwszePodaniePinu = false;
					is_valid_pin = true;
					obecnyPIN = "";
					for (int j = 0; j < 4; j++) {
						obecnyPIN += std::to_string(pin[j]);
					}
				}
				// jeśli to już niepierwsze wpisywanie pinu to sprawdzamy jego poprawnosc porownujac go do pierwszego wpisania
				else if (petla >= 3 && !czyPierwszePodaniePinu) { 
					string pin_str = ""; // tablica -> string
					for (int j = 0; j < 4; j++) { //zakres naszej tablicy
						pin_str += std::to_string(pin[j]); //spisujemy nasz podany pin
					}
					cout << pin_str << "  " << obecnyPIN << endl;
					if (pin_str == obecnyPIN) { //jesli pin jest taki sam to wiemy ze jest on poprawny
						is_valid_pin = true;
					}
					else {
						is_valid_pin = false;
					}
				}

				else if (petla < 3) { //jesli chcemy klinac enter bez uzupelnienia calej tablicy
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
				pin[petla] = tablicaPrzyciskow[i].get_value();  //wpisywanie w tablice wartosci guzikow
				petla++;
			}
		}
	}
	// wyswietlanie pinu
	string PIN = "";
	for (int j = 0; j < petla; ++j) { //konwersja na string
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