#ifndef _Tim_h_
#define _Tim_h_
#include "Error.h"
#include "Igrac.h"
#include <iostream>

class Tim {

protected:

	int max;
	string naziv;
	int br;

	struct Node {
		Igrac* igrac=nullptr;
		Node* next = nullptr;
	
	};


	Node* prvi = nullptr;
	Node* posl = nullptr;
	Node* tek = nullptr;

public:

	Tim(string naziv = "", int max = 20) {
		this->max = max;
		this->naziv = naziv;
		this->br = 0;
		posl = prvi = tek = nullptr;
		for (int i = 0; i < max; i++) {
			posl = (!prvi ? prvi : posl->next) = new Node;
		}
	}

	Tim(const Tim& t);

	Tim(Tim&& t)noexcept;

	~Tim();

	Tim& operator=(const Tim& l) {
		if (this != &l) {
			while (prvi) {
				Node* std = prvi;
				prvi = prvi->next;
				delete std;
			}
			posl = tek = posl = nullptr;
			
			this->naziv = l.naziv;
			this->br = l.br;
			this->max = l.max;

			Node* iterator = l.prvi;

			while (iterator) {
				posl = (prvi == nullptr ? prvi : posl->next) = new Node;
				posl->igrac = iterator->igrac;
				iterator = iterator->next;
			}
		}
		return *this;
	}

	virtual void dodajI(int ind, Igrac ig);
	int getBr() { return br; }
	double getVrT();
	void korigujT(double p);
	Igrac& operator[](int ind);
	ostream& pisiTim(ostream& os);
	friend ostream& operator<<(ostream& os, Tim& t);
	bool operator==(const Tim& d) const {
		if (max != d.max || naziv != d.naziv || br != d.br) {
			return false;
		}
		Node* tek1 = prvi;
		Node* tek2 = d.prvi;
		while (tek1 != nullptr && tek2 != nullptr) {
			if (!(tek1->igrac == tek2->igrac)) {
				return false;
			}
			tek1 = tek1->next;
			tek2 = tek2->next;
		}
		return true;
	}


};

#endif // !_Tim_h_
