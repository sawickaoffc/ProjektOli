#include "ekranBankomatu.h"
#include <SFML/Graphics/Font.hpp>
extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1;
extern PobranieZPliku pobranie;

void ekranBankomatu::Stworz(sf::RenderWindow* okienko)
{
	this->okienko = okienko; //referencja
	ekranPoczatkowy();
	WpisywaniePinu();
	WyplataGotowki();
	Menu();
	DostepneSrodki();
	ZmianaPinu();
	Limity();
}


void ekranBankomatu::ekranPoczatkowy()
{
	font.loadFromFile("Roboto-Bold.ttf");
	//rysujemy ekran na którym wszystko ma przebiegaæ
	tloEkranu.setPosition(150, 0); //pozycja w jakiej sie zaczyna wiec od górnego lewego rogu
	tloEkranu.setSize(sf::Vector2f(700, 500));
	tloEkranu.setFillColor(sf::Color(30, 0, 86));
	//a nastepnie napis poczatkowy
	Powitanie.setFont(font);
	Powitanie.setCharacterSize(32);
	Powitanie.setPosition(250, 270);
	Powitanie.setFillColor(sf::Color::White);
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
	Powitanie.setFillColor(sf::Color::White);
	WprowadzeniePinu.setString("Wprowadz kod PIN");
	return bankomat1.CzytaniePinu();
}

void ekranBankomatu::RysujWpisywaniePinu()
{
	string pin_str = "";
	for (int j = 0; j < bankomat1.petla; j++) {
		pin_str += "*";
	}

	tablicaPinu[0] = Guzik(pin_str, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaPinu[0].Czcionka(font);
	tablicaPinu[0].Polozenie({ 370, 400 });

	okienko->draw(tloEkranu);
	okienko->draw(WprowadzeniePinu);
	tablicaPinu[0].RysujPrzycisk(*okienko);
}

void ekranBankomatu::Menu()
{
	font.loadFromFile("Roboto-Bold.ttf");

	tablicaMenu[0] = Guzik("Wyplacanie Gotowki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[0].Czcionka(font);
	tablicaMenu[0].Polozenie({ 180,160 });

	tablicaMenu[1] = Guzik("Dostepne Srodki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[1].Czcionka(font);
	tablicaMenu[1].Polozenie({ 180,60 });

	tablicaMenu[2] = Guzik("Zmiana PIN", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[2].Czcionka(font);
	tablicaMenu[2].Polozenie({ 560, 160 });

	tablicaMenu[3] = Guzik("Limity", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[3].Czcionka(font);
	tablicaMenu[3].Polozenie({ 560,60 });

	tablicaMenu[4] = Guzik("Wplacanie Gotowki", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[4].Czcionka(font);
	tablicaMenu[4].Polozenie({ 180,260 });

	tablicaMenu[5] = Guzik("Dane Konta", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaMenu[5].Czcionka(font);
	tablicaMenu[5].Polozenie({ 560,260 });
}

void ekranBankomatu::RysujMenu()
{
	okienko->draw(tloEkranu);
	for (int i = 0; i < 6; ++i) {
		tablicaMenu[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::WyplataGotowki() {
	
	tablicaWyplacanie[0] = Guzik("10", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[0].Czcionka(font);
	tablicaWyplacanie[0].Polozenie({ 180,60 });

	tablicaWyplacanie[1] = Guzik("20", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[1].Czcionka(font);
	tablicaWyplacanie[1].Polozenie({ 180,160 });
	
	tablicaWyplacanie[2] = Guzik("50", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[2].Czcionka(font);
	tablicaWyplacanie[2].Polozenie({ 180,260 });

	tablicaWyplacanie[3] = Guzik("100", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[3].Czcionka(font);
	tablicaWyplacanie[3].Polozenie({ 180,360 });

	tablicaWyplacanie[4] = Guzik("200", {260,70}, 20, sf::Color{255, 191, 143}, sf::Color::White, font);
	tablicaWyplacanie[4].Czcionka(font);
	tablicaWyplacanie[4].Polozenie({ 560, 60 });

	tablicaWyplacanie[5] = Guzik("500", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[5].Czcionka(font);
	tablicaWyplacanie[5].Polozenie({ 560,160 });

	tablicaWyplacanie[6] = Guzik("Inna Kwota", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWyplacanie[6].Czcionka(font);
	tablicaWyplacanie[6].Polozenie({ 560,260 });	
}

void ekranBankomatu::RysujWyplataGotowki()
{
	WyplataGotowki();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 7; ++i) {
		tablicaWyplacanie[i].RysujPrzycisk(*okienko);
	}
	
}

void ekranBankomatu::InnaKwota()
{
	tablicaWyplacanie[7] = Guzik(bankomat1.kwota, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaWyplacanie[7].Czcionka(font);
	tablicaWyplacanie[7].Polozenie({ 370, 300 });

}

void ekranBankomatu::RysujInnaKwote() {
	InnaKwota();
	okienko->draw(tloEkranu);
	for (int i = 7; i < 8; ++i) {
		tablicaWyplacanie[i].RysujPrzycisk(*okienko);
	}
}


void ekranBankomatu::DostepneSrodki() {

	pobranie.PobranieZKarty(pobranie.daneKarty);
	string str = to_string(bankomat1.saldo);
	tablicaSrodki[0] = Guzik(str, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaSrodki[0].Czcionka(font);
	tablicaSrodki[0].Polozenie({ 370, 300 });

	tablicaSrodki[1] = Guzik("Dostepne srodki na koncie: ", { 350,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaSrodki[1].Czcionka(font);
	tablicaSrodki[1].Polozenie({ 300, 180 });
}

void ekranBankomatu::RysujDostepneSrodki() {
	DostepneSrodki();

	okienko->draw(tloEkranu);
	for (int i = 0; i < 2; ++i) {
		tablicaSrodki[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::Dane()
{
	pobranie.PobranieZKarty(pobranie.daneKarty);
	tablicaDane[0] = Guzik("Numer Konta:  " + bankomat1.numerKonta, {400,70}, 20, sf::Color{255, 191, 143}, sf::Color::White, font);
	tablicaDane[0].Czcionka(font);
	tablicaDane[0].Polozenie({ 180,60 });

	tablicaDane[1] = Guzik("Karta:  " + bankomat1.blokada, { 400,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaDane[1].Czcionka(font);
	tablicaDane[1].Polozenie({ 180,160 });

	tablicaDane[2] = Guzik("wyplacona dzis kwota:  " + to_string(bankomat1.wyplataDzienna), { 400,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaDane[2].Czcionka(font);
	tablicaDane[2].Polozenie({ 180,260 });

	tablicaDane[3] = Guzik("wyplacona w tym miesiacu kwota:  " + to_string(bankomat1.wyplataMiesieczna), { 400,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaDane[3].Czcionka(font);
	tablicaDane[3].Polozenie({ 180,360 });

}

void ekranBankomatu::RysujDane()
{
	Dane();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 4; ++i) {
		tablicaDane[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::WplataGotowki()
{
	tablicaWplacanie[0] = Guzik("10", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[0].Czcionka(font);
	tablicaWplacanie[0].Polozenie({ 180,60 });

	tablicaWplacanie[1] = Guzik("20", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[1].Czcionka(font);
	tablicaWplacanie[1].Polozenie({ 180,160 });

	tablicaWplacanie[2] = Guzik("50", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[2].Czcionka(font);
	tablicaWplacanie[2].Polozenie({ 180,260 });

	tablicaWplacanie[3] = Guzik("100", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[3].Czcionka(font);
	tablicaWplacanie[3].Polozenie({ 560,60 });
	
	tablicaWplacanie[4] = Guzik("200", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[4].Czcionka(font);
	tablicaWplacanie[4].Polozenie({ 560, 160 });

	tablicaWplacanie[5] = Guzik("500", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaWplacanie[5].Czcionka(font);
	tablicaWplacanie[5].Polozenie({ 560,260 });
}
void ekranBankomatu::RysujWplataGotowki() {
	WplataGotowki();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 6; ++i) {
		tablicaWplacanie[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::ZmianaPinu() {

	tablicaZmianyPinu[0] = Guzik("Potwierdzam ze chce zmienic pin", { 340,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::White, font);
	tablicaZmianyPinu[0].Czcionka(font);
	tablicaZmianyPinu[0].Polozenie({ 470, 360 });
}

void ekranBankomatu::RysujZmianaPinu()
{
	okienko->draw(tloEkranu);
	for (int i = 0; i < 1; ++i) {
		tablicaZmianyPinu[i].RysujPrzycisk(*okienko);
	}
}


void ekranBankomatu::Limity() {

	tablicaLimitu[1] = Guzik("Ustaw limit miesieczny", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::Black, font);
	tablicaLimitu[1].Czcionka(font);
	tablicaLimitu[1].Polozenie({ 560,160 });

	tablicaLimitu[2] = Guzik("Aktualny limit miesieczny: " + bankomat1.limitMiesieczny, { 300,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaLimitu[2].Czcionka(font);
	tablicaLimitu[2].Polozenie({ 180, 160 });

	tablicaLimitu[3] = Guzik("Ustaw limit dzienny", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::Black, font);
	tablicaLimitu[3].Czcionka(font);
	tablicaLimitu[3].Polozenie({ 560, 260 });

	tablicaLimitu[4] = Guzik("Aktualny limit dzienny: " + bankomat1.limitDzienny, { 300,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaLimitu[4].Czcionka(font);
	tablicaLimitu[4].Polozenie({ 180, 260 });

	tablicaLimitu[5] = Guzik("Ustaw limit zwykly", { 260,70 }, 20, sf::Color{ 255, 191, 143 }, sf::Color::Black, font);
	tablicaLimitu[5].Czcionka(font);
	tablicaLimitu[5].Polozenie({ 560, 360 });

	tablicaLimitu[0] = Guzik("Aktualny limit zwykly: " + bankomat1.limitZwykly, { 300,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaLimitu[0].Czcionka(font);
	tablicaLimitu[0].Polozenie({ 180, 360 });
}

void ekranBankomatu::RysujLimity() {
	Limity();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 6; ++i) {
		tablicaLimitu[i].RysujPrzycisk(*okienko);
	}
}

void ekranBankomatu::ZmianaLimitu() {

	tablicaZmianyLimitu[0] = Guzik(bankomat1.kwota, { 260,70 }, 20, sf::Color{ 255, 255, 255 }, sf::Color::Black, font);
	tablicaZmianyLimitu[0].Czcionka(font);
	tablicaZmianyLimitu[0].Polozenie({ 370, 300 });
}

void ekranBankomatu::RysujZmianeLimitu() {
	ZmianaLimitu();
	okienko->draw(tloEkranu);
	for (int i = 0; i < 1; ++i) {
		tablicaZmianyLimitu[i].RysujPrzycisk(*okienko);
	}

}

void ekranBankomatu::WydaneBanknoty()
{	
	tablicaWydaneBanknoty[0] = Guzik("Wydane banknoty:\nbanknot*ilosc:\n" + bankomat1.WydajBanknoty(stof(bankomat1.kwota)), {460, 150}, 20, sf::Color{255, 255, 255}, sf::Color::Black, font);
	tablicaWydaneBanknoty[0].Czcionka(font);
	tablicaWydaneBanknoty[0].Polozenie({ 270, 300 });
	}

void ekranBankomatu::RysujWydaneBanknoty() {
	if (a == 0) {
		WydaneBanknoty();
	}
	okienko->draw(tloEkranu);
	for (int i = 0; i < 1; ++i) {
		tablicaWydaneBanknoty[i].RysujPrzycisk(*okienko);
	}
	a = 1;
	bankomat1.ilosc = "";
	bankomat1.kwota = "";
}