#ifndef _mec_h_
#define _mec_h_
#include <iostream>
#include <string>
#include "Par.h"
#include "Tim.h"
#include "PrivTim.h"
#include "Par.h"
using namespace std;

enum Rezultat { POBEDA_DOMACIN, NERESENO, POBEDA_GOST, _};


class Mec {

private:

	Par<Tim,Tim> timovi;
	Rezultat r=_;
	static string str_rezultat[];

public:
	Mec(Tim& t1, Tim& t2, Rezultat rez = _) {
		Tim* pt1 = new Tim(t1);
		Tim* pt2 = new Tim(t2);
		timovi.set(*pt1, *pt2);
		r = rez;
	}
	Mec(Mec& m) {
		Tim* pt1 = new Tim(m.timovi.getP1());
		Tim* pt2 = new Tim(m.timovi.getP2());
		timovi.set(*pt1, *pt2);
		r = m.r;
	}
	Par<Tim, Tim>& getP() { return timovi; }
	void igraj();
	bool gotov() { return r != _; }
	Par<int, int> getIsh();
	friend ostream& operator<<(ostream& os, Mec& m);

};


#endif // !_mec_h_

