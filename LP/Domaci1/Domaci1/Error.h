#pragma once
#include <exception>
using namespace std;
class GBrSt :public exception {
public:
	GBrSt() : exception("Broj Stihova!!") {}
};
class GZn :public exception {
public:
	GZn() : exception("WrZnak") {}
};
class GBrSl :public exception {
public:
	GBrSl() : exception("Broj Slogova!!") {}
};
class GMaxSt :public exception {
public:
	GMaxSt() : exception("PrekMaxSt!") {}
};
class GNT :public exception {
public:
	GNT() : exception("Nema Tolko!") {}
};