#pragma once
#include <iostream>
#include <string>
#include "Rec.h"
#include "Error.h"

using namespace std;

class Stih {
private:
    struct Elem {
        Rec rec;
        Elem* sled;
        Elem(const Rec& r, Elem* s = nullptr) {
            rec = r; sled = s;
        }
    };

    Elem *prvi, *posl, *tek;
    int br;

protected:
    virtual void read(std::istream& is);

public:
    
    Stih() { prvi = posl = tek= nullptr; br = 0; }
    Stih& operator+=(const Rec& dr);
    int operator+() const { return br; }
    int operator~() const;
    Rec& operator[](int ind);
    void operator()(int ind);
    void operator()(Rec Rex, int ind);
    bool operator^(const Stih& dr) const;
    friend std::istream& operator>>(std::istream& is, Stih& sth);
    friend std::ostream& operator<<(std::ostream& os, Stih& sth);

};