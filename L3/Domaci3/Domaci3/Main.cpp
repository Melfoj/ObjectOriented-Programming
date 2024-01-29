#include <iostream>
#include "Lista.h"
#include "Boja.h"
#include "Ukras.h"
#include "Kugla.h"
#include "Error.h"

using namespace std;

int main() {

	try {
		Boja b3(250, 250, 250);
		Boja b9(50, 50, 50);
		Boja b5(69, 42, 250);

		cout << (b3 == b9) << endl;
		cout << (b9 == b5) << endl << endl;


		Ukras u1(b3, 130);
		Ukras u2(b9, 204);

		cout << u1.getBoja().getS() << " ";
		cout << u2.getMasa() << endl << endl;

		Kugla k1(b3, NAJVECA, 567);
		Kugla k2(b9, VELIKA, 678);
		Kugla k3(b5, SREDNJA, 789);
		Kugla k4(b3, MALA, 111);
		cout << k1 << endl;

		Lista<Kugla> l;

		l <<= k2;
		l <<= k4;
		l >>= k1;
		l >>= k3;

		l.pisi();
		cout << endl;

		cout << endl;
	}
	catch (exception e) {
		std::cout << e.what() << std::endl;
	}
}