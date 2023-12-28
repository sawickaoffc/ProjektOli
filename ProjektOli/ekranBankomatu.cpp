#include "ekranBankomatu.h"
#include <SFML/Graphics/Font.hpp>

using namespace std;

void ekranBankomatu::ekranPoczatkowy()
{
	font.loadFromFile("Roboto-Bold.ttf");
	//rysujemy ekran na którym wszystko ma przebiegaæ
	tloEkranu.setPosition(150, 0); //pozycja w jakiej sie zaczyna wiec od górnego lewego rogu
	tloEkranu.setSize(sf::Vector2f(700, 500));
	tloEkranu.setFillColor(sf::Color(76, 0, 255));
	//a nastepnie napis poczatkowy
	Powitanie.setFont(font);
	Powitanie.setCharacterSize(62);
	Powitanie.setPosition(250, 270);
	Powitanie.setFillColor(sf::Color(0, 0, 0));
	Powitanie.setString("Dzien dobry! \n Prosze wlozyc karte do czytnika ");


}

void ekranBankomatu::RysujEkranPoczatkowy()
{
	okienko->draw(tloEkranu);
	okienko->draw(Powitanie);
	//okienko->display();
	//okienko->clear();

}

ekranBankomatu::ekranBankomatu(sf::RenderWindow* okienko) //konstruktor
{
	this->okienko = okienko; //referencja
	ekranPoczatkowy(); 
	WpisywaniePinu();
	WplataGotowki();
	WyplataGotowki();

}

void ekranBankomatu::WpisywaniePinu()
{
	font.loadFromFile("Roboto-Bold.ttf");
	WprowadzeniePinu.setFont(font);
	WprowadzeniePinu.setCharacterSize(62);
	WprowadzeniePinu.setPosition(250, 270);
	WprowadzeniePinu.setFillColor(sf::Color(0, 0, 0));
	WprowadzeniePinu.setString("Wprowadz kod PIN");

//	cin>>x; //musze zrobic swich case i tablice z tym
		
}

void ekranBankomatu::RysujWpisywaniePinu()
{
	okienko->draw(tloEkranu);
	okienko->draw(WprowadzeniePinu);

	okienko->display();
}

void ekranBankomatu::Menu()
{


}

void ekranBankomatu::RysujMenu()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::Anuluj()
{
}

void ekranBankomatu::WplataGotowki()
{
}

void ekranBankomatu::RysujWplataGotowki()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::WyplataGotowki()
{
}

void ekranBankomatu::RysujWyplataGotowki()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::ZmianaPinu()
{
}

void ekranBankomatu::RysujZmianaPinu()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::DostepneSrodki()
{
}

void ekranBankomatu::RysujDostepneSrodki()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::PotwierdzeniePlatnosci()
{
}

void ekranBankomatu::RysujPotwierdzeniePlatnosci()
{
	okienko->draw(tloEkranu);
	okienko->display();
}

void ekranBankomatu::WyjecieKarty()
{
}

void ekranBankomatu::RysujWyjecieKarty()
{
	okienko->draw(tloEkranu);
	okienko->display();
}
