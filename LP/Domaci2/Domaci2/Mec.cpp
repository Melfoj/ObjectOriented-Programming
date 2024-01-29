#include "Mec.h"
#include "Par.h"
#include "Error.h"
using namespace std;


void Mec::igraj()
{
	double vt1 = this->getP().getP1().getVrT();
	double vt2 = this->getP().getP2().getVrT();
	if (vt1>vt2) {
		this->r = POBEDA_DOMACIN;
		this->getP().getP1().korigujT(0.1);
		this->getP().getP2().korigujT(-0.1);
	}
	else if (vt2>vt1) {
		this->r = POBEDA_GOST;
		this->getP().getP2().korigujT(0.1);
		this->getP().getP1().korigujT(-0.1);
	}
	else {
		this->r = NERESENO;
	}
}

Par<int, int> Mec::getIsh()
{
	if (this->r == POBEDA_DOMACIN) {
		//Par<int, int> pa(3,0);
		return Par<int,int>(3,0);
	}
	else if (this->r == POBEDA_GOST) {
		Par<int, int> pa(0, 3);
		return pa;
	}
	else if (this->r == NERESENO) {
		Par<int, int> pa(1, 1);
		return pa;
	}
	else throw GNoGame();
}

ostream& operator<<(ostream& os, Mec& m)
{
	os<<m.timovi;
	if (m.gotov()) {
		Par<int, int> p = m.getIsh();
		os << p;
	}
	return os;
}
