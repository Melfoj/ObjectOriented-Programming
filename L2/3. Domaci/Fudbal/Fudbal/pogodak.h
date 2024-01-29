#ifndef _pogodak_h_
#define _pogodak_h_

#include "fudbaler.h"

class Pogodak {

private:
	
	Fudbaler strelac;
	int minut;

public:

	//Konstruktor
	Pogodak(Fudbaler& strelac, int minut) {
		this->strelac = strelac;
		this->minut = minut;
	}

	Fudbaler& dohvatiStrelca() {
		return strelac;
	}

	friend ostream& operator<<(ostream& os, const Pogodak& p);

};

#endif // !_pogodak_h_
