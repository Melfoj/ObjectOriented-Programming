#include <iostream>
#include <string>

#include "fudbaler.h"
#include "pogodak.h"

using namespace std;

int main() {

	Fudbaler f1("Aleksandar Mitrovic", "Srbija", FWD);
	Fudbaler f2("Dusan Vlahovic", "Srbija", FWD);
	Fudbaler f3("Dusan Tadic", "Srbija", FWD);

	//Kontrola
	cout << f3.dohvatiIme() << endl;
	cout << f3.dohvatiPoziciju() << endl;
	cout << f3.dohvatiReprezentaciju() << endl;
	f3.promeniPoziciju(MID);
	cout << f3.dohvatiPoziciju() << endl;
	cout << f3;

	cout << endl;

	Pogodak p1(f1, 25);
	Pogodak p2(f2, 35);
	Pogodak p3(f1, 85);
	cout << p1.dohvatiStrelca();
	cout << p1;
	cout << p2;
	cout << p3;



}