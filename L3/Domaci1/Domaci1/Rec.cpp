#include "Rec.h"
#include <unordered_set>
#include <string>

Rec& Rec::operator+=(const Rec& dr)
{
    for (char c : dr.rec) {
        if (rec.find(c) == std::string::npos) {
            rec += c;
        }
    }
    return *this;
}

int Rec::operator~() const
{
    Skup samoglasnici("aeiou");
    Skup sonanti("lrn");
    Skup ln("ln");
    bool pretsam = false;
    bool pretson = false;
    bool pretln = false;
    bool flag = false;
    int slogovi = 0;
    for (int i = 0; i < this->rec.length(); i++)
    {
        char c = this->rec[i];
        c = tolower(c);
        if (samoglasnici(c) == 1) {
            ++slogovi;
            if (pretson == true && flag)--slogovi;
            pretsam = true;
            pretson = false;
            pretln = false;
            flag = false;
        }
        else if (sonanti(c) == 1) {
            if (pretsam == false) { ++slogovi; flag = true; }
            else flag = false;
            pretsam = false;
            pretson = true;
            pretln = false;
            if (c != 'r')pretln = true;
        }
        else if (c == 'j' && pretln)
        {
            --slogovi;
            pretsam = false;
            pretson = false;
            pretln = false;
            flag = false;
        }
        else 
        {
            pretsam = false;
            pretson = false;
            pretln = false;
            flag = false;
        }
    }

    return slogovi;
}

int Rec::operator()(int n) const
{
    int slogovi = ~*this;
    Skup samoglasnici("aeiou");
    Skup sonanti("lrn");
    Skup ln("ln");
    bool pretsam = false;
    bool pretson = false;
    bool pretln = false;
    bool flag = false;
    
    
    if (n < 0)n += (1 + slogovi);
    if (n<=0 || n>slogovi) return -1;
    pretsam = false;
    pretson = false;
    pretln = false;
    slogovi = 0;
    int i = 0;
    for (i = 0; i < this->rec.length(); i++)
    {
        char c = this->rec[i];
        c = tolower(c);
        if (samoglasnici(c) == 1) {
            ++slogovi;
            if (pretson == true && flag)--slogovi;
            pretsam = true;
            pretson = false;
            pretln = false;
            //flag = false;
        }
        else if (sonanti(c) == 1) {
            if (pretsam == false) { ++slogovi; flag = true; }
            else flag = false;
            pretsam = false;
            pretson = true;
            pretln = false;
            if (c != 'r')pretln = true;
        }
        else if (c == 'j' && pretln)
        {
            --slogovi;
            pretsam = false;
            pretson = false;
            pretln = false;
            //flag = false;
        }
        else
        {
            pretsam = false;
            pretson = false;
            pretln = false;
            //flag = false;
        }

        if (slogovi < n) flag = false;
        if (flag == true) return i - 1;
        if (slogovi == n)flag = true;

    }
    return i - 1;
}

bool Rec::operator^(const Rec& dr) const
{
    Rec ov(this->rec);
    if (~ov == 1 || ~dr == 1) { if (dr.getRec()[dr(-1)] == ov.getRec()[ov(-1)])return true; }
    else {
        if (dr.getRec()[dr(-1)] == ov.getRec()[ov(-1)] && dr.getRec()[dr(-2)] == ov.getRec()[ov(-2)])return true;
        else return false;
    }
}

void Rec::read(std::istream& is)
{
    std::string s;
    getline(is, s);
    *this = Rec(s);
}


std::istream& operator>>(std::istream& is, Rec& str)
{
    str.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rec& str)
{
    os << str.rec;
    return os;
}
