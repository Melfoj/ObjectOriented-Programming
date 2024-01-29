#pragma once
#include <iostream>
#include <string>

class Skup {
public:
    Skup(const std::string& str) : rec(str) {}
    Skup(const Skup&) = delete;
    Skup& operator=(const Skup&) = delete;

    Skup& operator+=(const char c);

    bool operator()(char c) const;

    friend std::ostream& operator<<(std::ostream& out, const Skup& str);


private:
    std::string rec;
};

