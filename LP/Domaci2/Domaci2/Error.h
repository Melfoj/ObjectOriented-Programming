#ifndef _Error_h_
#define _Error_h_
#include <exception>
#include <iostream>
using namespace std;

class GJadno :public exception {
public:
	GJadno() : exception("Ko ti je ovaj?") {}
};
class GNoGame :public exception {
public:
	GNoGame() : exception("Sutra se igra") {}
};
class GNemaP :public exception {
public:
	GNemaP() : exception("Ne postoji pozz") {}
};
class GNemaI :public exception {
public:
	GNemaI() : exception("Ne postoji igrr") {}
}; 

#endif // !_Error_h_