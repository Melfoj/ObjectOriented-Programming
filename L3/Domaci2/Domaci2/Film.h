#pragma once
#include <iostream>
#include "Vreme.h"
#include "Lista.h"
using namespace std;

class Film {
public:
	Film(string n = "-", Vreme vr = Vreme(0, 0), char oz = 'D') :o(oz), v(vr), naziv(n) {};
	Film(Film&& f) { move(f); }
	Film(const Film& f) { copy(f); }
	~Film() { del(); }
	Film& operator=(Film&& l) {
		if (this != &l) {
			del();
			move(l);
		}
		return *this;
	}
	Film& operator=(const Film& l) {
		if (this != &l) {
			del();
			copy(l);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Vreme& c);

	void oceniFilm(double oc);
	Vreme getVremeF();
	double getPrOc() const;
	void setO(char c);
	char getO();
	friend ostream& operator<<(ostream& os, const Film& f);

protected:
	virtual void pisi(ostream& os) const;
	void del();
	void copy(const Film& f);
	void move(Film& f);

	string naziv;
	Vreme v;
	char o;
	Lista<double> ocene;
};
