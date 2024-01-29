#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "Skup.h"
#include "Error.h"


class Rec {
public:
    Rec(const std::string& str="a") : rec(str) {
        for (char c : str)
        {
            if (!isalpha(c))throw GZn();
        }
    }
   

    Rec& operator+=(const Rec& dr);

    size_t operator+() const { return rec.length(); }

    int operator~() const;
    
    int operator()(int n) const;

    bool operator^(const Rec& dr) const;

    friend std::istream& operator>>(std::istream& is, Rec& ul);

    friend std::ostream& operator<<(std::ostream& out, const Rec& str);

    std::string getRec() const { return this->rec; }

protected:
    virtual void read(std::istream& is);
private:
    std::string rec;
};

