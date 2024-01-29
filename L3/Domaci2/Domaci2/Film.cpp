#include "Film.h"

void Film::oceniFilm(double oc)
{
	ocene += oc;
}

Vreme Film::getVremeF()
{
	return this->v;
}

double Film::getPrOc() const
{
	double p = 0;
	ocene.naPrvi();
	while (ocene.imaTek()) {
		p += ocene.dohvPod();
		ocene.naSled();
	}
	return p / ocene.broj();
}

void Film::setO(char c)
{
	this->o = c;
}

char Film::getO()
{
	return this->o;
}

void Film::pisi(ostream& os) const
{
	os << this->o << " - " << this->naziv << " " << this->v << " " << this->getPrOc() << endl;
}

void Film::del()
{
	ocene.Lista::del();
}

void Film::copy(const Film& flip)
{
	naziv = flip.naziv;
	ocene = flip.ocene;
	o = flip.o;
	v = flip.v;
}

void Film::move(Film& flip)
{
	naziv = flip.naziv;
	ocene = flip.ocene;
	o = flip.o;
	v = flip.v;
	ocene.Lista::del();
}

ostream& operator<<(ostream& os, const Film& f)
{
	f.pisi(os);
	return os;
}

