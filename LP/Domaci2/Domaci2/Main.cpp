#include "Tim.h"
#include "Igrac.h"
#include "Error.h"
#include "Mec.h"
#include "Par.h"
#include "PrivTim.h"
#include <iostream>
using namespace std;

int main() {
	try {
		Igrac i1("Haaland", 1500);
		Igrac i2("Ronaldo", 1700);
		Igrac i3("Ronaldinho", 1600);
		Igrac i4("Messi", 1650);
		Igrac i5("Lewandovski", 1400);
		Igrac i6("Sebastian Squillaci", 200);
		Igrac i7("Lukas Jutkiewicz", 180);
		Tim t1("MCU", 12);
		Tim t2("CZV", 15);
		Tim t3("FCPrt", 20);
		Tim t4("Turk", 2);
		PrivTim pt1(1600, "Saudi Arabia", 100);
		t1.dodajI(1, i1);
		t1.dodajI(2, i2);
		t1.dodajI(4, i3);
		t2.dodajI(6, i4);
		t2.dodajI(5, i5);
		t3.dodajI(7, i6);
		t4.dodajI(2, i7);
		pt1.dodajI(2, i2);
		Igrac iC = t1[1];
		cout << iC<<endl;
		Mec m1(t1, t2);
		Mec m2(t3, t1);
		Mec m3(t2, pt1);
		cout << i1 << endl << i2 << endl << i3 << endl << i4 << endl << i5 << endl << i6 << endl;
		cout << t1 << endl << pt1 << endl;
		if (t1 == t1)cout << "same" << endl;
		else cout << "diff" << endl;
		if (t3 == t2)cout << "same" << endl;
		else cout << "diff" << endl;
		cout << m1 << endl;
		m1.igraj();
		m2.igraj();
		m3.igraj();
		cout << m1<<endl<<m2<<endl<<m3<<endl;
		const int ik0 = 0;
		const int ik1 = 1;
		const int ik3 = 3;
		Par<int, int> p(0, 1);
		cout << p;
		return 0;
	}
	catch (exception e) {
		std::cout << e.what() << std::endl;
	}
}