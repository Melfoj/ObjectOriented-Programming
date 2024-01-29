#pragma once
#include "Error.h"
using namespace std;

template<typename T>
class Lista {
protected:
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr) {
			pod = p; sled = s;
		}
	};

	Elem* prvi, * posl;
	int br;
	mutable Elem* tek;


public:

	void brisi();
	void pisi();
	Lista() {
		prvi = posl = tek = nullptr;
		br = 0;
	}

	Lista(const Lista& l) = delete;

	Lista& operator=(const Lista&) = delete;


	~Lista() {
		brisi();
	}

	Lista& operator<<=(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}

	Lista& operator>>=(const T& t) {
		Elem* priv= new Elem(t);
		priv->sled = prvi;
		prvi = priv;
		br++;
		return *this;
	}

	int broj() const { return br; }

	void naPrvi() const { tek = prvi; }
	void naSled() const {
		if (tek)
			tek = tek->sled;
	}

	bool imaTek() const {
		return tek != nullptr;
	}

	T& dohvPod() const {
		if (!this->imaTek())throw GTek();
		return tek->pod;
	}
};

template<typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi=posl = tek = nullptr;
}

template<typename T>
void Lista<T>::pisi() {
	this->naPrvi();
	while (tek) {
		cout << tek->pod << " ";
		tek = tek->sled;
	}
	cout << endl;
}
