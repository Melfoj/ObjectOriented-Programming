#include "Tim.h"

Igrac& Tim::operator[](int ind)
{
	this->tek = prvi;
	for (int i = 0; i < ind-1; i++)  if (tek)tek = tek->next; 
	if (tek->igrac!=nullptr)return *this->tek->igrac;
	else throw GNemaI();
}

ostream& Tim::pisiTim(ostream& os)
{
	os << this->naziv<<"[";
	for (tek = prvi; tek; tek = tek->next) {
		if (tek->igrac) os << *tek->igrac;
	}
	os << "]";
	return os;
}

Tim::Tim(const Tim& t)
{
	prvi = nullptr;
	tek = nullptr;
	posl = nullptr;
	this->naziv = t.naziv;
	this->br = t.br;
	this->max = t.max;

	Node* iterator = t.prvi;

	while (iterator) {
		posl = (prvi == nullptr ? prvi : posl->next) = new Node;
		posl->igrac = iterator->igrac;
		iterator = iterator->next;
	}
}

Tim::Tim(Tim&& t)noexcept
{
	br = t.br;
	max = t.max;
	prvi = t.prvi;
	naziv = t.naziv;
	tek = prvi;
	t.prvi = nullptr;
}

Tim::~Tim()
{
/*	tek = prvi;

	while (tek != nullptr) {

		Node* stari=tek;
		tek = tek->next;
		if(stari!=nullptr)delete stari;
	}
	prvi = tek = posl = nullptr;
*/
	while (prvi) {
		Node* sta = prvi;
		prvi = prvi->next;
		delete sta;
	}
	posl = tek = posl = nullptr;
}



void Tim::dodajI(int ind, Igrac ig)
{
	//Igrac* I = &ig;
	if (ind > max)throw GNemaP();
	tek = prvi;
	for (int i = 1; i < ind; i++) { if (tek)tek = tek->next; }
	if (tek != nullptr) { if (tek->igrac == nullptr)br++; }
	else throw GNemaI();
	tek->igrac = new Igrac (ig.getIme(), ig.getVr());//I;
}

double Tim::getVrT()
{
	double d = 0;
	tek = prvi;
	while (tek) {
		if (tek != nullptr) {
			if (tek->igrac != nullptr) { d += tek->igrac->getVr(); }
	}
		tek = tek->next;
	}
	if(br!=0)d = d / br;
	return d;
}

void Tim::korigujT(double p)
{
	tek = prvi;
	while (tek) {
		if (tek->igrac)tek->igrac->changeVr(p);
		tek = tek->next;
	}
}

ostream& operator<<(ostream& os, Tim& t)
{
	t.pisiTim(os);
	return os;
}

