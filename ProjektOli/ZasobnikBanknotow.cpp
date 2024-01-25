#include "ZasobnikBanknotow.h"
extern bankomat bankomat1;
extern ekranBankomatu ekranbankomatu1; 
extern ZasobnikBanknotow banbanknoteContainer;

struct Banknoty {
    int denomination;  // Nomina³ banknotu
    int quantity;      // Iloœæ banknotów danego nomina³u
};



// Dodawanie banknotów do zasobnika
void ZasobnikBanknotow::addBanknotes(int denomination, int quantity)
{
    banknotes[denomination].denomination = denomination;
    banknotes[denomination].quantity += quantity;
}

// Pobieranie iloœci banknotów danego nomina³u
int ZasobnikBanknotow::getQuantity(int denomination)
{
    return banknotes[denomination].quantity;
}

// Wyjmowanie banknotów z zasobnika
bool ZasobnikBanknotow::withdrawBanknotes(int denomination, int quantity)
{
    if (banknotes[denomination].quantity >= quantity) {
        banknotes[denomination].quantity -= quantity;
        return true;
    }
    return false;
}

void ZasobnikBanknotow::Stworz(sf::RenderWindow* okienko)
{
    this->okienko = okienko;
    
}


void ZasobnikBanknotow::WydawaniePieniedzy()
{
	int pomwydaj = 0;

	int pomkwota;
	int pomdzielenie;
	int pomreszta;
	int banknoty[6];
	int czywystarczy;
	ipdzie = 0;
	idzie = 0;
	iddzie = 0;
	isto = 0;
	ipsto = 0;
	idsto = 0;
	//przypisuje pomocniczo do pomkwota ile chcemy wybrac z bankomatu
	pomkwota = howmuch;
	banknoty[0] = 500;
	banknoty[1] = 200;
	banknoty[2] = 100;
	banknoty[3] = 50;
	banknoty[4] = 20;
	banknoty[5] = 10;
	//vector<int> mojVector = { 500, 200, 100, 50, 20, 10 };
	//vector<int> vectorPom = { 500, 200, 100, 50, 20, 10 };
	DefMoney();
	for (int i = 0; i < 6; i++)
	{
		cout << "Powtorzenie " << i << endl;
		//sprawdzam czy któr¹ chce pobrc jest wieksza od danego bankotu
		if (pomkwota >= banknoty[i]) {

			//dziele na banknot 
			pomdzielenie = pomkwota / banknoty[i];
			pomreszta = pomkwota % banknoty[i];


			//je¿eli jest tyle banotow

			if (banknoty[i] == 500 && pomdzielenie <= psto)
			{
				pomkwota = pomreszta;
				ipsto = pomdzielenie;


			}

			if (banknoty[i] == 200 && pomdzielenie <= dsto)
			{
				pomkwota = pomreszta;
				idsto = pomdzielenie;

			}

			if (banknoty[i] == 100 && pomdzielenie <= sto)
			{
				pomkwota = pomreszta;
				isto = pomdzielenie;

			}

			if (banknoty[i] == 50 && pomdzielenie <= pdzie)
			{
				cout << "wchodzi do 50" << endl;
				pomkwota = pomreszta;
				ipdzie = pomdzielenie;

			}

			if (banknoty[i] == 20 && pomdzielenie <= ddzie)
			{
				pomkwota = pomreszta;
				iddzie = pomdzielenie;

			}

			if (banknoty[i] == 10 && pomdzielenie <= dzie)
			{
				pomkwota = pomreszta;
				idzie = pomdzielenie;

			}

			cout << "Pomkwota" << pomkwota;

			if (pomkwota == 0)
			{
				i = 1000;
			}

			// reszte przypisuj do zmiennej
		}
		//je¿eli nie to kontynuuje  

		if (pomkwota == 0 && pomwydaj == 0)
		{
			cout << "xxxxx: " << idsto;
			cout << "xxxxx: " << dsto;
			dzie = dzie - idzie;
			ddzie = pdzie - iddzie;
			pdzie = pdzie - ipdzie;
			sto = sto - isto;
			dsto = dsto - idsto;
			psto = psto - ipsto;
			zapiszDoPliku("ATM.txt");

			///dopisac limiyy

		}

	}
	//cout << endl << "Pieniadze: " << endl << ipsto << endl << idsto << endl << isto << endl << ipdzie << endl << iddzie << endl << idzie;

	if (pomkwota != 0)
	{
		cout << "Druga Petla" << endl;
		//pomkwota = howmuch;

	///////////////////////////////////////////

		for (int j = 0; j < 6; j++)
		{
			cout << endl << endl << "wchodze do drugiej petli" << endl;
			ipdzie = 0;
			idzie = 0;
			iddzie = 0;
			isto = 0;
			ipsto = 0;
			idsto = 0;
			pomkwota = howmuch;
			for (int i = 0; i < 6; i++)
			{
				//cout << "powtozenie petli " << j << "   " << i << endl;
				if (pomkwota >= banknoty[i]) {

					//dziele na banknot 
					pomdzielenie = pomkwota / banknoty[i];
					pomreszta = pomkwota % banknoty[i];


					if (j != 5 && banknoty[i] == 500 && pomdzielenie < psto)
					{
						pomkwota = pomreszta;
						ipsto = pomdzielenie;


					}

					if (j != 4 && banknoty[i] == 200 && pomdzielenie < dsto)
					{
						pomkwota = pomreszta;
						idsto = pomdzielenie;

					}

					if (j != 3 && banknoty[i] == 100 && pomdzielenie < sto)
					{
						pomkwota = pomreszta;
						isto = pomdzielenie;

					}

					if (j != 2 && banknoty[i] == 50 && pomdzielenie < pdzie)
					{
						pomkwota = pomreszta;
						ipdzie = pomdzielenie;
						cout << "wchodze do 50" << endl;

					}

					if (j != 1 && banknoty[i] == 20 && pomdzielenie < ddzie)
					{
						pomkwota = pomreszta;
						iddzie = pomdzielenie;

					}

					if (j != 0 && banknoty[i] == 10 && pomdzielenie < dzie)
					{
						pomkwota = pomreszta;
						idzie = pomdzielenie;

					}
					if (pomkwota == 0)
					{
						i = 10;
						j = 10;
					}
				}

				cout << "Pomkwota" << pomkwota;


			}

		}
		//////////////////////////////////////////////////////////////////
	}

	this->okienko.clear(Color::White);
	DrawKeyboard();
	DrawNumbers();
	string pomstring;
	pomstring = to_string(ipsto);
	Write(pomstring, 370, 100);
	Write("500", 270, 100);
	pomstring = to_string(idsto);
	Write(pomstring, 370, 130);
	Write("200", 270, 130);
	pomstring = to_string(isto);
	Write(pomstring, 370, 160);
	Write("100", 270, 160);
	pomstring = to_string(ipdzie);
	Write(pomstring, 370, 190);
	Write("50", 270, 190);
	pomstring = to_string(iddzie);
	Write(pomstring, 370, 210);
	Write("20", 270, 210);
	pomstring = to_string(idzie);
	Write(pomstring, 370, 240);
	Write("10", 270, 240);
	///////////
	cout << "500 : " << ipsto << endl;
	cout << "200 : " << idsto << endl;
	cout << "100 : " << isto << endl;
	cout << "50 : " << ipdzie << endl;
	cout << "20 : " << iddzie << endl;
	cout << "10 : " << idzie << endl;
	if (pomkwota == 0 && pomwydaj == 0)
	{
		cout << "xxxxx: " << idsto;
		cout << "xxxxx: " << dsto;
		dzie = dzie - idzie;
		ddzie = pdzie - iddzie;
		pdzie = pdzie - ipdzie;
		sto = sto - isto;
		dsto = dsto - idsto;
		psto = psto - ipsto;
		zapiszDoPliku("ATM.txt");
	}
	if (pomkwota != 0)
	{
		cout << "Nie mo¿na wydac " << endl;
	}

}