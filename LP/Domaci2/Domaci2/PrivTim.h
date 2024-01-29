#ifndef _PrivTim_h_
#define _PrivTim_h_
#include "Tim.h"
#include "Igrac.h"
#include <iostream>

class PrivTim : public Tim {
private:

	int minVr;

public:

	PrivTim(int min=0,string naziv="", int max = 20) {
		this->max = max;
		this->naziv = naziv;
		this->br = 0;
		minVr = min;
		posl=prvi = tek = nullptr;
		for (int i = 0; i < max; i++) {
			posl = (!prvi ? prvi : posl->next) = new Node;
		}
	}
	ostream& pisiPTim(ostream& os);
	void dodajI(int ind, Igrac ig) override;

	friend ostream& operator<<(ostream& os, PrivTim& pt);

};

#endif // !_PrivTim_h_
