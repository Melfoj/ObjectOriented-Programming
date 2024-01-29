#include "cvecara.h"

//Kopirajuci
Cvecara::Cvecara(const Cvecara& cv) {

		prvi = nullptr;
		tekuci = nullptr;

		Node* iterator = cv.prvi;

		while (iterator) {
			tekuci = (prvi == nullptr ? prvi : tekuci->sledeci) = new Node;
			tekuci->buket = iterator->buket;
			iterator = iterator->sledeci;
		}

}

//Premestajuci
Cvecara::Cvecara(Cvecara&& cv) {

	prvi = cv.prvi;
	tekuci = prvi;
	cv.prvi = nullptr;

}

//Destruktor
Cvecara::~Cvecara() {

	Node* tekuci = prvi;
	Node* stari;

	while (tekuci) {
		stari = tekuci;
		tekuci = tekuci->sledeci;
		delete stari;
	}

}

void Cvecara::dodajBuket(Buket* buket) {
	
	if (buket->zaradaBuketa() >= buket->nabavnaBuketa()*0.2) {
		tekuci = (prvi == nullptr ? prvi : tekuci->sledeci) = new Node;
		tekuci->buket = buket;
		tekuci->sledeci = nullptr;
		zarada -= buket->nabavnaBuketa();
	} 

	sortirajCvecaru();

}

void Cvecara::sortirajCvecaru() {

	for (Node* buket1 = prvi; buket1->sledeci; buket1 = buket1->sledeci)
		for (Node* buket2 = buket1->sledeci; buket2; buket2 = buket2->sledeci) {
			if (buket1->buket->prodajnaBuketa() >= buket2->buket->prodajnaBuketa()) {

				Buket* tmp = buket1->buket;
				buket1->buket = buket2->buket;
				buket2->buket = tmp;

			}
		}
}

void Cvecara::prodajBuket(Buket* buket) {

	tekuci = prvi;
	Node* stari = nullptr;

	while (tekuci) {

		if (tekuci->buket == buket) {

			if (tekuci == prvi) {
				prvi = prvi->sledeci;
				delete tekuci;
				tekuci = prvi;
				continue;
			}

			stari->sledeci = tekuci->sledeci;
			Node* tmp = tekuci;
			tekuci = tekuci->sledeci;
			delete tmp;
			continue;
		}

		stari = tekuci;
		tekuci = tekuci->sledeci;
	}

	zarada += buket->prodajnaBuketa();

}

ostream& Cvecara::pisiCvecara(ostream& os) {

	for (Node* tekuci = prvi; tekuci; tekuci = tekuci->sledeci) {
		tekuci->buket->pisiBuket(os);
	}

	return os;
}

ostream& operator<<(ostream& os, Cvecara& cv) {

	os << "Zarada = " << cv.zarada << " RSD" << endl;

	return cv.pisiCvecara(os);

}
