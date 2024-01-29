#pragma once
#include <iostream>
#include "Film.h"
using namespace std;

class StraniFilm: public Film {
public:
	StraniFilm(string n, Vreme vr, string t, string z) :Film(n, vr), tis(t), zemlja(z) { o = 'S'; };



protected:
	void pisi(ostream& os) const override;
	string tis;
	string zemlja;
};
