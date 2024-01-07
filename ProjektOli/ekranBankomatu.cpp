#include "ekranBankomatu.h"
#include <SFML/Graphics/Font.hpp>
extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;


void ekranBankomatu::Stworz(sf::RenderWindow* okienko)
{
	this->okienko = okienko; //referencja
	ekranPoczatkowy();
	WpisywaniePinu();
	WplataGotowki();
	WyplataGotowki();
	Menu();
	DostepneSrodki();
	ZmianaPinu();
	PotwierdzeniePlatnosci();
	WyjecieKarty();
	AktywacjaKarty();
	LimitMiesieczny();
}

void ekranBankomatu::ekranPoczatkowy()
{
	font.loadFromFile("Roboto-Bold.ttf");
	//rysujemy ekran na którym wszystko ma przebiegaæ
	tloEkranu.setPosition(150, 0); //pozycja w jakiej sie zaczyna wiec od górnego lewego rogu
	tloEkranu.setSize(sf::Vector2f(700, 500));
	tloEkranu.setFillColor(sf::Color(76, 0, 255));
	//a nastepnie napis poczatkowy
	Powitanie.setFont(font);
	Powitanie.setCharacterSize(32);
	Powitanie.setPosition(250, 270);
	Powitanie.setFillColor(sf::Color(0, 0, 0));
	Powitanie.setString("Dzien dobry! \nProsze wlozyc karte do czytnika ");

}

void ekranBankomatu::RysujEkranPoczatkowy()
{
	okienko->draw(tloEkranu);
	okienko->draw(Powitanie);
	bankomat1.tablicaPrzyciskow[22].RysujPrzycisk(*okienko);
}
//wskaznik dajemy gdy przekazujemy caly obiekt


bool ekranBankomatu::WpisywaniePinu()
{
	font.loadFromFile("Roboto-Bold.ttf");
	WprowadzeniePinu.setFont(font);
	WprowadzeniePinu.setCharacterSize(62);
	WprowadzeniePinu.setPosition(250, 270);
	WprowadzeniePinu.setFillColor(sf::Color(0, 0, 0));
	WprowadzeniePinu.setString("Wprowadz kod PIN");
	return bankomat1.CzytaniePinu();
}

void ekranBankomatu::RysujWpisywaniePinu()
{
	okienko->draw(tloEkranu);
	okienko->draw(WprowadzeniePinu);
	okienko->display();
}

void ekranBankomatu::Menu()
{
	font.loadFromFile("Roboto-Bold.ttf");
	tablicaMenu[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[0].Czcionka(font);
	tablicaMenu[0].Polozenie({ 180,60 });

	tablicaMenu[1] = Guzik("Wplacanie Gotowki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[1].Czcionka(font);
	tablicaMenu[1].Polozenie({ 180,160 });

	tablicaMenu[2] = Guzik("Wyplacanie Gotowki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[2].Czcionka(font);
	tablicaMenu[2].Polozenie({ 180,260 });

	tablicaMenu[3] = Guzik("Dostêpne Srodki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[3].Czcionka(font);
	tablicaMenu[3].Polozenie({ 180,360 });

	tablicaMenu[4] = Guzik("Aktywacja Karty", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[4].Czcionka(font);
	tablicaMenu[4].Polozenie({ 560,60 });

	tablicaMenu[5] = Guzik("Zmiana PIN", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[5].Czcionka(font);
	tablicaMenu[5].Polozenie({ 560, 160 });

	tablicaMenu[6] = Guzik("Limit miesieczny", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[6].Czcionka(font);
	tablicaMenu[6].Polozenie({ 560,260 });

	tablicaMenu[7] = Guzik("", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[7].Czcionka(font);
	tablicaMenu[7].Polozenie({ 560, 360 });

}

void ekranBankomatu::RysujMenu()
{
	okienko->draw(tloEkranu);
	for (int i = 0; i < 8; ++i) {
		tablicaMenu[i].RysujPrzycisk(*okienko);
	}
}


void ekranBankomatu::WplataGotowki()
{
	tablicaWplacanie[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[0].Czcionka(font);
	tablicaWplacanie[0].Polozenie({ 180,60 });

	tablicaWplacanie[1] = Guzik(bankomat1.kwota, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaWplacanie[1].Czcionka(font);
	tablicaWplacanie[1].Polozenie({ 370, 300 });

}

void ekranBankomatu::RysujWplataGotowki() {
	WplataGotowki();

	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaWplacanie[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::PotwierdzeniePlatnosci() {
	tablicaPotwierdzenie[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaPotwierdzenie[0].Czcionka(font);
	tablicaPotwierdzenie[0].Polozenie({ 180,60 });

	string pin_str = "";
	for (int j = 0; j < bankomat1.petla; j++) {
		pin_str += std::to_string(bankomat1.pin[j]);
	}

	tablicaPotwierdzenie[1] = Guzik(pin_str, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaPotwierdzenie[1].Czcionka(font);
	tablicaPotwierdzenie[1].Polozenie({ 370, 300 });

}

void ekranBankomatu::RysujPotwierdzeniePlatnosci() {
	PotwierdzeniePlatnosci();

	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaPotwierdzenie[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::WyplataGotowki() {
	tablicaWyplacanie[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[0].Czcionka(font);
	tablicaWyplacanie[0].Polozenie({ 180,60 });

	tablicaWyplacanie[1] = Guzik(bankomat1.kwota, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaWyplacanie[1].Czcionka(font);
	tablicaWyplacanie[1].Polozenie({ 370, 300 });
}

void ekranBankomatu::RysujWyplataGotowki()
{
	WyplataGotowki();

	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaWyplacanie[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::DostepneSrodki() {
	tablicaSrodki[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaSrodki[0].Czcionka(font);
	tablicaSrodki[0].Polozenie({ 180,60 });

	int stan_len = to_string(static_cast<int>(bankomat1.stanKonta)).length();

	string stan_str = to_string(bankomat1.stanKonta).substr(0, stan_len + 3);
	tablicaSrodki[1] = Guzik(stan_str, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaSrodki[1].Czcionka(font);
	tablicaSrodki[1].Polozenie({ 370, 300 });
}

void ekranBankomatu::RysujDostepneSrodki() {
	DostepneSrodki();

	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaSrodki[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::AktywacjaKarty() {
	tablicaAktywacja[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaAktywacja[0].Czcionka(font);
	tablicaAktywacja[0].Polozenie({ 180,60 });

	tablicaAktywacja[1] = Guzik("Aktywuj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::Black, font);
	tablicaAktywacja[1].Czcionka(font);
	tablicaAktywacja[1].Polozenie({ 560,60 });

	tablicaAktywacja[2] = Guzik("Stan Karty: " + bankomat1.karta, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaAktywacja[2].Czcionka(font);
	tablicaAktywacja[2].Polozenie({ 370, 300 });

}


void ekranBankomatu::RysujAktywacjaKarty() {
	AktywacjaKarty();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 3; ++i) {
		tablicaAktywacja[i].RysujPrzycisk(*okienko);
	}

}


void ekranBankomatu::ZmianaPinu() {
	tablicaZmianyPinu[0] = Guzik("Anuluj", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaZmianyPinu[0].Czcionka(font);
	tablicaZmianyPinu[0].Polozenie({ 180,60 });

	tablicaZmianyPinu[1] = Guzik("Potwierdzam ze chce zmienic pin", { 340,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaZmianyPinu[1].Czcionka(font);
	tablicaZmianyPinu[1].Polozenie({ 470, 360 });

	// string pin_str = "";
	// for (int j = 0; j < bankomat1.petla; j++) {
	// 	pin_str += std::to_string(bankomat1.pin[j]);
	// }

	// tablicaZmianyPinu[2] = Guzik(pin_str, { 390,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	// tablicaZmianyPinu[2].Czcionka(font);
	// tablicaZmianyPinu[2].Polozenie({ 325, 390});

}

void ekranBankomatu::RysujZmianaPinu()
{
	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaZmianyPinu[i].RysujPrzycisk(*okienko);
	}
}





void ekranBankomatu::WyjecieKarty()
{
}

void ekranBankomatu::RysujWyjecieKarty()
{
	okienko->draw(tloEkranu);
}



void ekranBankomatu::LimitMiesieczny()
{
}

void ekranBankomatu::RysujLimitMiesieczny()
{
}
