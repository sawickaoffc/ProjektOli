#include "Guzik.h"

Guzik::Guzik(string napis, sf::Vector2f rozmiarWektora, int wielkoscNapisu, sf::Color kolorTla, sf::Color kolorTekstu, sf::Font &czcionka)
{
	tekst.setFillColor(kolorTekstu);
	tekst.setCharacterSize(wielkoscNapisu);
	guzik.setSize(rozmiarWektora);
	guzik.setFillColor(kolorTla);
	tekst.setFont(czcionka); 
	tekst.setString(napis);

}

void Guzik::Czcionka(sf::Font& font)
{
	tekst.setFont(font);
}
void Guzik::KolorTla(sf::Color color)
{
	guzik.setFillColor(color);
}
void Guzik::KolorCzcionki(sf::Color color)
{
	tekst.setFillColor(color);
}
void Guzik::Polozenie(sf::Vector2f pos)
{
	guzik.setPosition(pos);
	tekst.setOrigin(tekst.getLocalBounds().width / 2 + tekst.getLocalBounds().left, tekst.getLocalBounds().top + tekst.getLocalBounds().height / 2);
	//float xPozycja = (pos.x + guzik.getGlobalBounds().width / 2) - (tekst.getGlobalBounds().width / 2) - (tekst.getLocalBounds().width / 2);
	//float yPozycja = (pos.y + guzik.getGlobalBounds().height / 2) - (tekst.getGlobalBounds().height / 2) - (tekst.getLocalBounds().height / 2);
	tekst.setPosition({ pos.x+(guzik.getGlobalBounds().width / 2), pos.y + (guzik.getGlobalBounds().height / 2) });
}
void Guzik::RysujPrzycisk(sf::RenderWindow& okienko)
{
	okienko.draw(guzik);
	okienko.draw(tekst);
}

bool Guzik::PolozenieMyszki(sf::RenderWindow& window)
{
	float xMyszki = sf::Mouse::getPosition(window).x;
	float yMyszki = sf::Mouse::getPosition(window).y;
	float xWspolrzedne = guzik.getPosition().x;
	float yWspolrzedne = guzik.getPosition().y;
	float SzerokoscPrzycisku = guzik.getPosition().x + guzik.getLocalBounds().width;
	float WysokoscPrzycisku = guzik.getPosition().y + guzik.getLocalBounds().height;
	if (xMyszki< SzerokoscPrzycisku && xMyszki > xWspolrzedne && yMyszki < WysokoscPrzycisku && yMyszki >yWspolrzedne)
	{
		return true;
	}
	else
		return false;
}