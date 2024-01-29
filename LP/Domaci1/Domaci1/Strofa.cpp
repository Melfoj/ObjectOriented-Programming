#include "Strofa.h"

string Strofa::str_vrsta[] = { "K", "T", "M", "S", "O", "N", "D" };


Strofa& Strofa::operator+=(const Stih& dr)
{
	if (brt < max) {
		if (this->prvi) {
			//if (~this->prvi->stih == ~dr) {
			posl = (!prvi ? prvi : posl->sled) = new Elem(dr);
			brt++;
			return *this;
			//}
			//else throw GBrSl();
		}
		else {
			posl = (!prvi ? prvi : posl->sled) = new Elem(dr);
			brt++;
			return *this;
		}
	}
	else throw GMaxSt();
}

void Strofa::operator-()
{
	tek = prvi;
	while (tek->sled->sled)tek = tek->sled;
	Elem* stari = posl;
	posl = tek;
	delete stari;
}

Stih& Strofa::operator[](int ind)
{
	Elem* tek = prvi;
	for (int i = 0; i < ind; i++) { if (tek)tek = tek->sled;  else throw GNT(); }
	return tek->stih;
}

bool Strofa::operator*()
{
	bool flag = true;
	tek = prvi;
	while (tek) {
		flag = flag && (prvi->stih ^ tek->stih);
		tek = tek->sled;
	}
	return flag;
}

void Strofa::operator()(int i, int j)
{
	Elem* z1 = prvi;
	Elem* z1p = nullptr;
	Elem* z2 = prvi;
	Elem* z2p = nullptr;
	if (i<0 || i>brt || j < 0 || j > brt) throw GBrSt();
	for (int i1 = 1; i1 < i; i1++) {
		z1p = z1;
		z1 = z1->sled;
	}
	for (int i1 = 1; i1 < j; i1++) {
		z2p = z2;
		z2 = z2->sled;
	}

	Elem* tmp = nullptr;
	if (z1 != nullptr && z2 != nullptr) {
		if (z1p != nullptr)
			z1p->sled = z2;
		else
			prvi = z2;

		if (z2p != nullptr)
			z2p->sled = z1;
		else
			prvi = z1;

		tmp = z1->sled;
		z1->sled = z2->sled;
		z2->sled = tmp;
	}
	else throw GBrSl();
}



string Strofa::getV()
{
	return str_vrsta[V];
}


std::ostream& operator<<(std::ostream& os, Strofa& stf)
{

	for (stf.tek = stf.prvi; stf.tek; stf.tek = stf.tek->sled) {
		os << stf.tek->stih;
		if(stf.tek->sled != nullptr)os << endl;
	}

	return os;
}
