#ifndef _buket_h_
#define _buket_h_

#include <iostream>
#include "cvet.h"

using namespace std;

class Buket {

private:

	struct Node {
		Cvet* cvet = nullptr;
		Node* sledeci = nullptr;
	};

	Node* prvi = nullptr;
	Node* tekuci = nullptr;

public:

	//Konstruktor
	Buket() {
		prvi = tekuci = nullptr;
	}

	//Kopirajuci
	Buket(const Buket& b);

	//Premestajuci
	Buket(Buket&& b);

	//Destruktor
	~Buket();

	void dodajCvet(Cvet* cvet);

	int nabavnaBuketa() const;

	int prodajnaBuketa() const;

	int zaradaBuketa() const {
		int z = prodajnaBuketa() - nabavnaBuketa();
		return z;
	}

	friend bool operator>(const Buket& b1, const Buket& b2);

	//Pomocne funkcije za ispis - Sort i ispis
	void sortirajBuket();

	ostream& pisiBuket(ostream& os);

	friend ostream& operator<<(ostream& os, Buket& b);

};

#endif // !_buket_h_

