#ifndef _cvet_h_
#define _cvet_h_

#include <iostream>

using namespace std;


class Cvet {

private:

	string naziv;
	int nabavna_cena;
	int prodajna_cena;

public:

	//Konstruktor
	Cvet(string naziv = "", int nabavna_cena = 0, int prodajna_cena = 0) {
		this->naziv = naziv;
		this->nabavna_cena = nabavna_cena;
		this->prodajna_cena = prodajna_cena;
	}

	string dohvatiNaziv() const{
		return naziv;
	}

	int dohvatiNabavnu() const {
		return nabavna_cena;
	}

	int dohvatiProdajnu() const {
		return prodajna_cena;
	}

	int zarada() {
		int z = prodajna_cena - nabavna_cena;
		return z;
	}

	friend bool operator==(const Cvet& c1, const Cvet& c2);

	friend bool operator!=(const Cvet& c1, const Cvet& c2);

	friend ostream& operator<<(ostream& os, const Cvet& c);

};


#endif // !_cvet_h_
