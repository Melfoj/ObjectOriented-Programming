#pragma once
#include <iostream>
#include "Boja.h"
#include <string>

using namespace std;

class Ukras {

protected:
	Boja b;
	int masa;

	virtual void piss(ostream& os) {
		string s = "(" + to_string((this->getBoja()).getR()) + ", " + to_string((this->getBoja()).getG()) + ", " + to_string((this->getBoja()).getB()) + ") ";
		os << "boja: " << s << " - " << "masa: " << to_string(this->getMasa()) << endl << endl;
	}

public:
	Ukras(Boja boj=Boja(0,0,0), int m = 0) :b(boj), masa(m) {};
	int getMasa() { return masa; }
	Boja getBoja() { return b; }

	friend ostream& operator<<(ostream& os, Ukras u);
};