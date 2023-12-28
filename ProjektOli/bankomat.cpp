#include "bankomat.h"
#include <SFML/Graphics/Font.hpp>

bankomat::bankomat(sf::RenderWindow* okienko)
{
	this->okienko = okienko;
	utworzTloEkranu();
}

void bankomat::utworzTloEkranu()
{
	//ustalamy t³o ca³ego ekranu
	tloEkranu.setPosition(0, 0); //pozycja w jakiej sie zaczyna wiec od górnego lewego rogu
	tloEkranu.setSize(sf::Vector2f(1000,500));
	tloEkranu.setFillColor(sf::Color(90, 159, 176));
	//nastêpnie t³o klawiatury poni¿ej ekranu
	klawiatura.setPosition(0, 500); 
	klawiatura.setSize(sf::Vector2f(1000, 300));
	klawiatura.setFillColor(sf::Color(184, 187, 230));
	//opisujemy guziki z boku wyœwietlacza
	lewo1.setPosition(40, 70); 
	lewo1.setSize(sf::Vector2f(70,50));
	lewo1.setFillColor(sf::Color(65, 75, 217));

	lewo2.setPosition(40, 170);
	lewo2.setSize(sf::Vector2f(70, 50));
	lewo2.setFillColor(sf::Color(65, 75, 217));
	
	lewo3.setPosition(40, 270);
	lewo3.setSize(sf::Vector2f(70, 50));
	lewo3.setFillColor(sf::Color(65, 75, 217));
	
	lewo4.setPosition(40, 370);
	lewo4.setSize(sf::Vector2f(70, 50));
	lewo4.setFillColor(sf::Color(65, 75, 217));
	
	prawo1.setPosition(890, 70);
	prawo1.setSize(sf::Vector2f(70, 50));
	prawo1.setFillColor(sf::Color(65, 75, 217));
	
	prawo2.setPosition(890, 170);
	prawo2.setSize(sf::Vector2f(70, 50));
	prawo2.setFillColor(sf::Color(65, 75, 217));
	
	prawo3.setPosition(890, 270);
	prawo3.setSize(sf::Vector2f(70, 50));
	prawo3.setFillColor(sf::Color(65, 75, 217));
	
	prawo4.setPosition(890, 370);
	prawo4.setSize(sf::Vector2f(70, 50));
	prawo4.setFillColor(sf::Color(65, 75, 217));
	
	//teraz rysujemy strza³ki po bokach na klawiszach 

	strzalkaLewo1.setFont(font);
	strzalkaLewo1.setCharacterSize(42);
	strzalkaLewo1.setPosition(50, 70);
	strzalkaLewo1.setFillColor(sf::Color(0, 0, 0));
	strzalkaLewo1.setString("->");
	
	strzalkaLewo2.setFont(font);
	strzalkaLewo2.setCharacterSize(42);
	strzalkaLewo2.setPosition(50, 170);
	strzalkaLewo2.setFillColor(sf::Color(0, 0, 0));
	strzalkaLewo2.setString("->");

	strzalkaLewo3.setFont(font);
	strzalkaLewo3.setCharacterSize(42);
	strzalkaLewo3.setPosition(50, 270);
	strzalkaLewo3.setFillColor(sf::Color(0, 0, 0));
	strzalkaLewo3.setString("->");

	strzalkaLewo4.setFont(font);
	strzalkaLewo4.setCharacterSize(42);
	strzalkaLewo4.setPosition(50, 370);
	strzalkaLewo4.setFillColor(sf::Color(0, 0, 0));
	strzalkaLewo4.setString("->");

	strzalkaPrawo1.setFont(font);
	strzalkaPrawo1.setCharacterSize(42);
	strzalkaPrawo1.setPosition(900, 70);
	strzalkaPrawo1.setFillColor(sf::Color(0, 0, 0));
	strzalkaPrawo1.setString("<-");

	strzalkaPrawo2.setFont(font);
	strzalkaPrawo2.setCharacterSize(42);
	strzalkaPrawo2.setPosition(900, 170);
	strzalkaPrawo2.setFillColor(sf::Color(0, 0, 0));
	strzalkaPrawo2.setString("<-");

	strzalkaPrawo3.setFont(font);
	strzalkaPrawo3.setCharacterSize(42);
	strzalkaPrawo3.setPosition(900, 270);
	strzalkaPrawo3.setFillColor(sf::Color(0, 0, 0));
	strzalkaPrawo3.setString("<-");

	strzalkaPrawo4.setFont(font);
	strzalkaPrawo4.setCharacterSize(42);
	strzalkaPrawo4.setPosition(900, 370);
	strzalkaPrawo4.setFillColor(sf::Color(0, 0, 0));
	strzalkaPrawo4.setString("<-");

	//dodajemy przyciski do klawiatury poni¿ej wyœwietlacza
	jeden.setPosition(150, 560);
	jeden.setSize(sf::Vector2f(70, 60));
	jeden.setFillColor(sf::Color(59, 17, 82));

	dwa.setPosition(290, 560);
	dwa.setSize(sf::Vector2f(70, 60));
	dwa.setFillColor(sf::Color(59, 17, 82));
	
	trzy.setPosition(430, 560);
	trzy.setSize(sf::Vector2f(70, 60));
	trzy.setFillColor(sf::Color(59, 17, 82));
	
	cztery.setPosition(570, 560);
	cztery.setSize(sf::Vector2f(70, 60));
	cztery.setFillColor(sf::Color(59, 17, 82));
	
	piec.setPosition(710, 560);
	piec.setSize(sf::Vector2f(70, 60));
	piec.setFillColor(sf::Color(59, 17, 82));
	
	usun.setPosition(850, 560);
	usun.setSize(sf::Vector2f(70, 60));
	usun.setFillColor(sf::Color(59, 17, 82));
	
	szesc.setSize(sf::Vector2f(70, 60));
	szesc.setFillColor(sf::Color(59, 17, 82));
	szesc.setPosition(150, 680);
	
	siedem.setSize(sf::Vector2f(70, 60));
	siedem.setFillColor(sf::Color(59, 17, 82));
	siedem.setPosition(290, 680);
	
	osiem.setSize(sf::Vector2f(70, 60));
	osiem.setFillColor(sf::Color(59, 17, 82));
	osiem.setPosition(430, 680);
	
	dziewiec.setPosition(570, 680);
	dziewiec.setSize(sf::Vector2f(70, 60));
	dziewiec.setFillColor(sf::Color(59, 17, 82));
	
	zero.setPosition(710, 680);
	zero.setSize(sf::Vector2f(90, 60));
	zero.setFillColor(sf::Color(59, 17, 82));

	enter.setPosition(850, 680);
	enter.setSize(sf::Vector2f(90, 60));
	enter.setFillColor(sf::Color(59, 17, 82));
	
	//a nastêpnie numerki do guzików

	font.loadFromFile("Roboto-Bold.ttf"); //pobieramy czcionke do napisów
	one.setFont(font);
	one.setCharacterSize(62);  //ustawiamy rozmiar czcionki
	one.setPosition(160, 550); //ustawiamy pozycje na okienku gdzie ma zostaæ napisany napis
	one.setFillColor(sf::Color(255, 255, 255)); //kolor
	one.setString("1"); //co piszemy

	two.setFont(font);
	two.setCharacterSize(62);
	two.setPosition(300, 550);
	two.setFillColor(sf::Color(255, 255, 255));
	two.setString("2");

	three.setFont(font);
	three.setCharacterSize(62);
	three.setPosition(440, 550);
	three.setFillColor(sf::Color(255, 255, 255));
	three.setString("3");

	four.setFont(font);
	four.setCharacterSize(62);
	four.setPosition(580, 550);
	four.setFillColor(sf::Color(255, 255, 255));
	four.setString("4");

	five.setFont(font);
	five.setCharacterSize(62);
	five.setPosition(720, 550);
	five.setFillColor(sf::Color(255, 255, 255));
	five.setString("5");

	six.setFont(font);
	six.setCharacterSize(62);
	six.setPosition(160, 670);
	six.setFillColor(sf::Color(255, 255, 255));
	six.setString("6");

	seven.setFont(font);
	seven.setCharacterSize(62);
	seven.setPosition(300, 670);
	seven.setFillColor(sf::Color(255, 255, 255));
	seven.setString("7");

	eight.setFont(font);
	eight.setCharacterSize(62);
	eight.setPosition(440, 670);
	eight.setFillColor(sf::Color(255, 255, 255));
	eight.setString("8");

	nine.setFont(font);
	nine.setCharacterSize(62);
	nine.setPosition(580, 670);
	nine.setFillColor(sf::Color(255, 255, 255));
	nine.setString("9");

	zero2.setFont(font);
	zero2.setCharacterSize(62);
	zero2.setPosition(720, 670);
	zero2.setFillColor(sf::Color(255, 255, 255));
	zero2.setString("0");

	usun2.setFont(font);
	usun2.setCharacterSize(52);
	usun2.setPosition(860, 550);
	usun2.setFillColor(sf::Color(255, 255, 255));
	usun2.setString("<");

	enter2.setFont(font);
	enter2.setCharacterSize(30);
	enter2.setPosition(860, 690);
	enter2.setFillColor(sf::Color(255, 255, 255));
	enter2.setString("Enter");

}

void bankomat::rysujBankomat(){

	okienko->draw(tloEkranu);
	okienko->draw(klawiatura);
	okienko->draw(lewo1);
	okienko->draw(lewo2);
	okienko->draw(lewo3);
	okienko->draw(lewo4);
	okienko->draw(prawo1);
	okienko->draw(prawo2);
	okienko->draw(prawo3);
	okienko->draw(prawo4);
	okienko->draw(jeden);
	okienko->draw(dwa);
	okienko->draw(trzy);
	okienko->draw(cztery);
	okienko->draw(piec);
	okienko->draw(szesc);
	okienko->draw(siedem);
	okienko->draw(osiem);
	okienko->draw(dziewiec);
	okienko->draw(zero);
	okienko->draw(enter);
	okienko->draw(usun);

	okienko->draw(one);
	okienko->draw(two);
	okienko->draw(three);
	okienko->draw(four);
	okienko->draw(five);
	okienko->draw(six);
	okienko->draw(seven);
	okienko->draw(eight);
	okienko->draw(nine);
	okienko->draw(zero2);
	okienko->draw(enter2);
	okienko->draw(usun2);

	okienko->draw(strzalkaLewo1);
	okienko->draw(strzalkaLewo2);
	okienko->draw(strzalkaLewo3);
	okienko->draw(strzalkaLewo4);
	okienko->draw(strzalkaPrawo1);
	okienko->draw(strzalkaPrawo2);
	okienko->draw(strzalkaPrawo3);
	okienko->draw(strzalkaPrawo4);

	okienko->display();
}
