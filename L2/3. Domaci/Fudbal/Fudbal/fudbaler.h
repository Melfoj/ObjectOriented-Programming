#ifndef _fudbaler_h_
#define _fudbaler_h_

#include <iostream>
#include <string>
using namespace std;

enum Pozicija { GK, DEF, MID, FWD, _ };


class Fudbaler {

private:

	string ime;
	string reprezentacija;
	Pozicija pozicija;
	static string str_pozicija[];

public:

	//Konstruktor
	Fudbaler(string ime = "", string reprezentacija = "", Pozicija pozicija = _) {
		this->ime = ime;
		this->reprezentacija = reprezentacija;
		this->pozicija = pozicija;

	}

	//Zabrana kopiranja
	Fudbaler(const Fudbaler&) = delete;

	string dohvatiIme() const {
		return ime;
	}

	string dohvatiReprezentaciju() const {
		return reprezentacija;
	}

	string dohvatiPoziciju() const;

	void promeniPoziciju(Pozicija nova_pozicija);

	friend ostream& operator<<(ostream& os, const Fudbaler& f);

};


#endif // !_fudbaler_h_

