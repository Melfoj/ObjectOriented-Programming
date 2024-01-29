#pragma once
#include <iomanip>
#include <iostream>
using namespace std;

class Vreme {
public:
	Vreme(int s=0, int m=0) :sat(s), min(m) {};
	Vreme operator+(Vreme& dv);

	friend ostream& operator<<(ostream& os, const Vreme& c);

protected:
	virtual void pisi(ostream& os) const;
	int sat, min;
};
