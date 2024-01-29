#pragma once
#include <iostream>
#include "Error.h"
#include <string>
using namespace std;

class Boja {
	int r, g, b;
public:
	Boja(int red = 0, int green = 0, int blue = 0) {
		if (red <= 255 && red >= 0 && green <= 255 && green >= 0 && blue <= 255 && blue >= 0) {
			r = red; g = green; b = blue;
		}
		else throw GVr();
	}
	int getR() { return r; }
	int getG() { return g; }
	int getB() { return b; }
	string getS(){return "(" + to_string(getR()) + ", " + to_string(getG()) + ", " + to_string(getB()) + ") ";}
	bool operator==(const Boja& db);
	Boja operator+(Boja& db);
};