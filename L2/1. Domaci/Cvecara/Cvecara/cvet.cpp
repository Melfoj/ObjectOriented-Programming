#include "cvet.h"

bool operator==(const Cvet& c1, const Cvet& c2) {
    return c1.naziv == c2.naziv;
}

bool operator!=(const Cvet& c1, const Cvet& c2) {
    return !(c1 == c2);
}

ostream& operator<<(ostream& os, const Cvet& c) {
    return os << c.naziv << endl;
}
