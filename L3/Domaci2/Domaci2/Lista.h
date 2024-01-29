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

	void del();
	void pisi(); 
	void copy(const Lista& l);
	void move(Lista& l);
	Lista() {
		prvi = posl = tek = nullptr;
		br = 0;
	}
	~Lista() {
		del();
	}
	Lista(const Lista& l) {
		copy(l);
	}
	Lista(Lista&& l) {
		move(l);
	}
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			del();
			copy(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			del();
			move(l);
		}
		return *this;
	}

	Lista& operator+=(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}

	int broj() const { return br; }

	void naPrvi() const { tek = prvi; }
	void naSled() const { if (tek)tek = tek->sled; }

	bool imaTek() const { return tek != nullptr; }

	T& dohvPod() const {
		if (!this->imaTek())throw GTek();
		return tek->pod;
	}
};

template<typename T>
void Lista<T>::del() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi = posl = tek = nullptr;
}

template<typename T>
void Lista<T>::pisi() {
	this->naPrvi();
	for (this->naPrvi(); tek;tek = tek->sled) {
		cout << tek->pod << " ";
	}
	cout << endl;
}

template<typename T>
inline void Lista<T>::move(Lista& l)
{
	prvi = l.prvi;
	posl = l.posl;
	tek = l.tek;
	l.prvi = l.posl = nullptr;

}

template<typename T>
void Lista<T>::copy(const Lista& l) {
	prvi = posl = tek = nullptr;
	Elem* priv = l.prvi;
	while (priv) {
		posl = (prvi == nullptr ? prvi : posl->sled) = new Elem(priv->pod); priv = priv->sled;
	}
}
