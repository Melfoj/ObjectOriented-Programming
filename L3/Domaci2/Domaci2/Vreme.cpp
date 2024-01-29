#include "Vreme.h"
#include "Film.h"

Vreme Vreme::operator+(Vreme& dv)
{
    int s = sat + dv.sat;
    int m = min + dv.min;
    return Vreme(s,m);
}

void Vreme::pisi(ostream& os) const
{
    os << setw(2) << setfill('0') <<this->sat<< ":" << setw(2) << setfill('0') << this->min<<endl;
}

ostream& operator<<(ostream& os, const Vreme& v)
{
    v.pisi(os);
    return os;
}
