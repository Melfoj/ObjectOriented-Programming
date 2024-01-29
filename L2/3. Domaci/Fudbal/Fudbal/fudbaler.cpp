#include "fudbaler.h"

string Fudbaler::str_pozicija[] = { "GK", "DEF", "MID", "FWD", "_"};

string Fudbaler::dohvatiPoziciju() const {
	return str_pozicija[pozicija];
}

void Fudbaler::promeniPoziciju(Pozicija nova_pozicija) {
	pozicija = nova_pozicija;
}

ostream& operator<<(ostream& os, const Fudbaler& f) {
	return os << f.ime << " (" << f.str_pozicija[f.pozicija] << "): " << f.reprezentacija << endl;
}
