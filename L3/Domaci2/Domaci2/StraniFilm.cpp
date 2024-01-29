#include "StraniFilm.h"

void StraniFilm::pisi(ostream& os) const
{
	Film::pisi(os);
	os << "( " << tis << " )" << ", " << zemlja << endl;
}
