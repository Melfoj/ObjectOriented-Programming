#include <iostream>
#include "cvet.h"
#include "buket.h"
#include "cvecara.h"

using namespace std;

int main() {

	//Provere za cvetove

	Cvet c1("Ruza", 100, 200);
	Cvet c2("Ljiljan", 100, 150);
	Cvet c3("Lala", 100, 150);
	Cvet c4("Ruza", 100, 250);
	Cvet c5("Ohideja", 100, 300);
	Cvet c6("Lizijantus", 150, 2000);
	Cvet c7("Bela Rada", 100, 110);

	cout << c5.dohvatiNaziv() << endl;
	cout << c5.dohvatiNabavnu() << endl;
	cout << c5.dohvatiProdajnu() << endl;
	cout << c5.zarada() << endl;

	cout << "Da li su isti: " << c1.dohvatiNaziv() << " i " << c3.dohvatiNaziv() << endl;
	if (c1 == c2) {
		cout << "Jesu! " << endl;
	}
	else cout << "Nisu! " << endl;

	cout << c5 << endl;

	//Provere za bukete

	Buket b1;
	b1.dodajCvet(&c1);
	b1.dodajCvet(&c2);
	b1.dodajCvet(&c3);
	b1.nabavnaBuketa();
	b1.prodajnaBuketa();
	b1.zaradaBuketa();

	Buket b2;
	b2.dodajCvet(&c1);
	b2.dodajCvet(&c5);
	b2.dodajCvet(&c5);
	b2.dodajCvet(&c4);

	Buket b3;
	b3.dodajCvet(&c6);

	Buket b4;
	b4.dodajCvet(&c7);

	if (b3 > b2) {
		cout << "Prvi je skuplji! " << endl;
	}
	else cout << "Drugi je skuplji! " << endl;

	cout << b2 << endl;

	//Provere za cvecaru

	Cvecara cv1;
	cv1.dodajBuket(&b1);
	cv1.dodajBuket(&b2);
	cv1.dodajBuket(&b3);
	cv1.dodajBuket(&b4);

	cout << cv1;
	cv1.prodajBuket(&b3);
	cout << cv1;

}