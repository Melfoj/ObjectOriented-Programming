#include "buket.h"


//Kopirajuci
Buket::Buket(const Buket& b) {

	prvi = nullptr;
	tekuci = nullptr;

	Node* iterator = b.prvi;

	while (iterator) {
		tekuci = (prvi == nullptr ? prvi : tekuci->sledeci) = new Node;
		tekuci->cvet = iterator->cvet;
		iterator = iterator->sledeci;

	}

}

//Premestajuci
Buket::Buket(Buket&& b) {

	prvi = b.prvi;
	tekuci = prvi;
	b.prvi = nullptr;

}

//Destruktor
Buket::~Buket() {

	Node* tekuci = prvi;
	Node* stari;

	while (tekuci) {
		stari = tekuci;
		tekuci = tekuci->sledeci;
		delete stari;
	}

}

//Dodavanje cveta
void Buket::dodajCvet(Cvet* cvet) {

	tekuci = (prvi == nullptr ? prvi : tekuci->sledeci) = new Node;
	tekuci->cvet = cvet;
	tekuci->sledeci = nullptr;

}

//Racunanje nabavne cene buketa
int Buket::nabavnaBuketa() const{
	
	Node* tekuci = prvi;

	int nabavna = 0;
	while (tekuci) {
		nabavna += tekuci->cvet->dohvatiNabavnu();
		tekuci = tekuci->sledeci;

	}

	return nabavna;

}

//Racunanje nabavne cene buketa
int Buket::prodajnaBuketa() const {

	Node* tekuci = prvi;

	int prodajna = 0;
	while (tekuci) {
		prodajna += tekuci->cvet->dohvatiProdajnu();
		tekuci = tekuci->sledeci;

	}

	return prodajna;

}

bool operator>(const Buket& b1, const Buket& b2) {
	if (b1.prodajnaBuketa() > b2.prodajnaBuketa()) {
		return true;
	}
	else return false;

}

void Buket::sortirajBuket() {
	for (Node* cvet1 = prvi; cvet1->sledeci; cvet1 = cvet1->sledeci)
		for (Node* cvet2 = cvet1->sledeci; cvet2; cvet2 = cvet2->sledeci) {
			if (cvet1->cvet->dohvatiNaziv() <= cvet2->cvet->dohvatiNaziv()) {

				Cvet* tmp = cvet1->cvet;
				cvet1->cvet = cvet2->cvet;
				cvet2->cvet = tmp;
			
			}
		}
}

ostream& Buket::pisiBuket(ostream& os) {

	os << "(";
	Node* stari = nullptr;
	int cena = 0;

	for (Node* tekuci = prvi; tekuci; tekuci = tekuci->sledeci) {

		if (tekuci != prvi) {
			if (*tekuci->cvet != *stari->cvet) {
				cena += tekuci->cvet->dohvatiProdajnu();
				os << ", " << tekuci->cvet->dohvatiNaziv();
				stari = tekuci;
			}
			else {
				cena += tekuci->cvet->dohvatiProdajnu();
				stari = tekuci;
			}
		}
		else {
			cena += tekuci->cvet->dohvatiProdajnu();
			os << tekuci->cvet->dohvatiNaziv();
			stari = tekuci;
		}
	}

	os << ") " << cena << " RSD" << endl;

	return os;
}

ostream& operator<<(ostream& os, Buket& b) {
	b.sortirajBuket();
	return b.pisiBuket(os);
}
