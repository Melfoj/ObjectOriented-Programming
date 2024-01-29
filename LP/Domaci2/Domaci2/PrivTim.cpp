#include "PrivTim.h"
#include "Error.h"

ostream& PrivTim::pisiPTim(ostream& os)
{
	os << this->naziv << "(" << this->minVr << ") [";
	for (tek = prvi; tek; tek = tek->next) {
		if (tek->igrac) os << *tek->igrac;
	}
	os << "]";
	return os;
}

void PrivTim::dodajI(int ind, Igrac ig)
{
	//Igrac* I = &ig;
	if(ig.getVr()<this->minVr)throw GJadno();
	this->tek = prvi;
	for (int i = 0; i < ind; i++) { if (this->tek)this->tek = this->tek->next; }
	if (this->tek!=nullptr) { if (this->tek->igrac == nullptr)br++; }
	else throw GNemaI();
	this->tek->igrac = new Igrac(ig.getIme(),ig.getVr());
}

ostream& operator<<(ostream& os, PrivTim& pt)
{
	pt.pisiPTim(os);
	return os;
}
