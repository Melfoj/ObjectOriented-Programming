#include "Kugla.h"
#include <string>

string str_vel[] = { ".", "o", "O", "( )" };
ostream& operator<<(ostream& os, Kugla k)
{
    k.Kugla::piss(os);
    return os;
}

void Kugla::piss(ostream& os)
{
    string s = "(" + to_string((this->getBoja()).getR()) + ", " + to_string((this->getBoja()).getG()) + ", " + to_string((this->getBoja()).getB()) + ") ";
    os<<"velicina: " << this->getVel() << " boja: " << s << " - " << " masa: " << to_string(this->getMasa()) << endl << endl;
}
string Kugla::getVel() { return str_vel[v]; };
