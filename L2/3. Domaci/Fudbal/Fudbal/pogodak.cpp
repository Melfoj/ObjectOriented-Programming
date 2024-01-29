#include "Pogodak.h"

ostream& operator<<(ostream& os, const Pogodak& p) {
	return os << "[" << p.minut << "'] - " << p.strelac.dohvatiIme() << endl;

}
