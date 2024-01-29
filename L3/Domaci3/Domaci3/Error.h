#pragma once
#include <exception>
using namespace std;
class GVr :public exception {
public:
	GVr() : exception("BadVr") {}
};
class GTek :public exception {
public:
	GTek() : exception("NoTek") {}
};