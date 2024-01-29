#ifndef _Igrac_h_
#define _Igrac_h_
#include <iostream>
#include <string>
using namespace std;

class Igrac {

private:

	string ime;
	int vr;

public:

	Igrac(string ime = "",int vr=1000) {
		this->ime = ime;
		this->vr = vr;

	}

	Igrac(Igrac& I) {
		this->ime = I.ime;
		this->vr = I.vr;
	}
	Igrac(Igrac&& I)noexcept {
		this->ime = I.ime;
		this->vr = I.vr;
	}

	string getIme() const {
		return ime;
	}

	int getVr() const {
		return vr;
	}

	void changeVr(double p) { this->vr = int(this->vr * (1 + p)); }
	friend bool operator==(const Igrac& i1, const Igrac& i2);

	Igrac& operator=(const Igrac& l) {
		this->ime = l.ime;
		this->vr = l.vr;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Igrac& i);

};


#endif // !_Igrac_h_

