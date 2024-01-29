#pragma once
#include <exception>
using namespace std;
class GOps :public exception {
public:
	GOps() : exception("BadOps") {}
};
class GTek :public exception {
public:
	GTek() : exception("NoTek") {}
};