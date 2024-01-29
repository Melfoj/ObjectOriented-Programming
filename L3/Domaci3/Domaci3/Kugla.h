#pragma once
#include <iostream>
#include "Ukras.h"

using namespace std;

enum vel { MALA, SREDNJA, VELIKA, NAJVECA };

class Kugla:public Ukras {
protected:
	vel v;
	void piss(ostream& os) override;

public:

	Kugla(Boja boj=Boja(69,69,69), vel ve=MALA, int mas=0) :v(ve), Ukras(boj,mas){};
	friend ostream& operator<<(ostream& os, Kugla k);
	string getVel();
};