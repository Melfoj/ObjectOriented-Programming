#ifndef _cvecara_h_
#define _cvecara_h_

#include "buket.h"

class Cvecara {

private:

	int zarada = 1000;

	struct Node {
		Buket* buket = nullptr;
		Node* sledeci = nullptr;
	};

	Node* prvi = nullptr;
	Node* tekuci = nullptr;

public:

	//Konstruktor
	Cvecara() {
		prvi = tekuci = nullptr;
	}

	//Kopirajuci
	Cvecara(const Cvecara& cv);

	//Premestajuci
	Cvecara(Cvecara&& cv);

	//Destruktor
	~Cvecara();

	void dodajBuket(Buket* buket);

	void prodajBuket(Buket* buket);

	//Pomocna funkcija za izpis
	ostream& pisiCvecara(ostream& os);

	void sortirajCvecaru();

	friend ostream& operator<<(ostream& os, Cvecara& cv);

};

#endif // !_cvecara_h_
