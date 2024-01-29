#include "Skup.h"

Skup& Skup::operator+=(char c)
{
        if (rec.find(c) == std::string::npos && isalpha(c)) {
            rec += c;
        }
 
    return *this;
}

bool Skup::operator()(char c) const
{

    return rec.find(c) != std::string::npos;
}

std::ostream& operator<<(std::ostream& out, const Skup& str)
{
    out << str.rec;
    return out;
}
