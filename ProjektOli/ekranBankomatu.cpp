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



void ekranBankomatu::WyplataGotowki()
{
}

void ekranBankomatu::RysujWyplataGotowki()
{
	okienko->draw(tloEkranu);
}

void ekranBankomatu::ZmianaPinu()
{
	tablicaMenu[8] = Guzik("Potwierdzam ze chce zmienic Pin", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[8].Czcionka(font);
	tablicaMenu[8].Polozenie({ 370, 360 });
}

void ekranBankomatu::RysujZmianaPinu()
{
	okienko->draw(tloEkranu);
	ekranbankomatu1.tablicaMenu[8].RysujPrzycisk(*okienko);
}

void ekranBankomatu::DostepneSrodki()
{
}

void ekranBankomatu::RysujDostepneSrodki()
{
	okienko->draw(tloEkranu);
}

void ekranBankomatu::PotwierdzeniePlatnosci() {

}

void ekranBankomatu::RysujPotwierdzeniePlatnosci()
{
	okienko->draw(tloEkranu);
}

void ekranBankomatu::WyjecieKarty()
{
}

void ekranBankomatu::RysujWyjecieKarty()
{
	okienko->draw(tloEkranu);
}

void ekranBankomatu::RysujAktywacjaKarty()
{
}

void ekranBankomatu::AktywacjaKarty()
{
}

void ekranBankomatu::LimitMiesieczny()
{
}

void ekranBankomatu::RysujLimitMiesieczny()
{
}
