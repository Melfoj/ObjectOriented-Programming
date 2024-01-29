#include "Igrac.h"

bool operator==(const Igrac& i1, const Igrac& i2)
{
    return (i1.ime == i2.ime) && (i1.vr == i2.vr);
}

ostream& operator<<(ostream& os, const Igrac& i)
{
    return os << i.ime << "#" << i.vr;
}
