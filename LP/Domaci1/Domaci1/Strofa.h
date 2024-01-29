#pragma once
#include <iostream>
#include <string>
#include "Stih.h"
#include "Error.h"

using namespace std;

enum vrsta {K, T, M, S, O, N, D};

class Strofa {
private:
    struct Elem {
        Stih stih;
        Elem* sled;
        Elem(const Stih& s, Elem* sl = nullptr) {
            stih = s; sled = sl;
        }
    };

    static string str_vrsta[];

protected:
    Elem* prvi, * posl, * tek;
    int brt, max;
    vrsta V;
    Strofa() { prvi = posl = tek = nullptr; brt = max = 0; }
public:

    Strofa(int m):max(m) { prvi = posl = tek = nullptr; brt = 0; }
    int getMax() { return max; }
    Strofa& operator+=(const Stih& dr);
    int operator+() const { return brt; }
    void operator-();
    Stih& operator[](int ind);
    virtual bool operator*();
    void operator()(int i, int j);
    friend std::ostream& operator<<(std::ostream& os, Strofa& stf);
    string getV();

};