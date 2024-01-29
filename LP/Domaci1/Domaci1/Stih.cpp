#include "Stih.h"
#include <string>


Stih& Stih::operator+=(const Rec& dr)
{
	posl = (!prvi ? prvi : posl->sled) = new Elem(dr);
	br++;
	return *this;
}

int Stih::operator~() const
{
	int masno = 0;
	for (Elem* tek = prvi; tek != nullptr; tek = tek->sled)
	{
		masno += ~tek->rec;
	}
	return masno;
}

Rec& Stih::operator[](int ind)
{
	Elem* tek = prvi;
	for (int i = 0; i < ind; i++) {
		if (tek)tek = tek->sled;
		else throw  GNT();
	}
	return tek->rec;
}

void Stih::operator()(int ind)
{
	tek = prvi;
	for (int i = 0; i < ind; i++) { if (tek)tek = tek->sled; else throw GNT();}
	Elem* del = tek->sled;
	tek->sled = tek->sled->sled;
	delete del;
}

bool Stih::operator^(const Stih& dr) const
{
	Rec ov(posl->rec);
	Rec og(dr.posl->rec);
	return ov ^ og;
}

void Stih::operator()(Rec Rex, int ind)
{
	Elem* nov = new Elem(Rex); 
	Elem* pret = tek->sled;
	tek = prvi;
	for (int i = 0; i < ind; i++) { if (tek) { tek = tek->sled; pret = tek; } else throw GNT(); }
	pret->sled = nov;
	nov->sled = tek;
	pret = nullptr;
	delete pret;
}


std::istream& operator>>(std::istream& is, Stih& sth)
{
	sth.read(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, Stih& sth)
{
	for (sth.tek=sth.prvi; sth.tek; sth.tek = sth.tek->sled) {
		os << sth.tek->rec;
		if (sth.tek->sled != nullptr)os << " ";
	}
	return os;
}

void Stih::read(std::istream& is)
{
	std::string s;
	string re="";
	Rec r;
	getline(is, s);
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i]))re += s[i];
		if (s[i] == ' ') { r = Rec(re); *this += r;  re = ""; }
	}
	r = Rec(re); *this += r;  re = "";
}

