#pragma once
#include <iostream>
#include <string>
#include "Strofa.h"
using namespace std;

class Katren : public Strofa {
public:
	Katren(){ prvi = posl = tek = nullptr; brt = 0; max = 4; V = K; }
	bool operator*() override;
private:

};