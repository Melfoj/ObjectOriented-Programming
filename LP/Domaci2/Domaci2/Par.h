#ifndef _Par_h_
#define _Par_h_
#include "Error.h"
#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Par {
protected:
	T1* p1=new T1();
	T2* p2=new T2();

public:
	void set(T1& p11, T2& p22) { this->p1 = &p11; this->p2 = &p22; }
	void setP1(T1 p11) { this->p1 = p11; }
	void setP2(T2 p22) { this->p2 = p22; }
	T1 getP1() { return *p1; }
	T2 getP2() { return *p2; }
	void del();
	void pisi(ostream& os);
	void copy(const Par& p);
	void move(Par& p);
	~Par() { del(); }
	Par() { p1 = p2 = nullptr; }
	Par(const T1& f, const T2& s) { *p1 = f; *p2 = s; }
	Par(const Par& p) {
		copy(p);
	}
	Par(Par&& p) {
		move(p);
	}
	Par& operator=(const Par& l) {
		if (this != &l) {
			del();
			copy(l);
		}
		return *this;
	}
	Par& operator=(Par&& l) {
		if (this != &l) {
			del();
			move(l);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os,Par& p) {
		p.pisi(os);
		return os;
	}

	friend bool operator==(const Par<T1, T2>& p11, const Par<T1, T2>& p22) {
		if (typeid(p11.p1) == typeid(p22.p1) && typeid(p11.p2) == typeid(p22.p2)) {
			return p11.p1 == p22.p1 && p11.p2 == p22.p2;
		}
		else return false;
	}
};

template<typename T1, typename T2>
void Par<T1,T2>::del() {
	T1* dex = this->p1;
	p1 = nullptr;
	delete dex;
	T2* st = this->p2;
	p2 = nullptr;
	delete st;
}

template<typename T1, typename T2>
void Par<T1,T2>::pisi(ostream& os) {
	os << "[" << *p1 << "-" << *p2 << "]" << endl;
}

template<typename T1, typename T2>
inline void Par<T1,T2>::move(Par& l)
{
	p1 = l.p1;
	p2 = l.p2;
	l.p1 = l.p2 = nullptr;

}

template<typename T1, typename T2>
void Par<T1,T2>::copy(const Par& l) {
	p1 = l.p1;
	p2 = l.p2;
}
#endif // !_Par_h_