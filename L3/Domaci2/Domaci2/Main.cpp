#include <iostream>
#include <string>
#include <iostream>
#include "Vreme.h"
#include "Film.h"
#include "StraniFilm.h"

using namespace std;

int main() {
    try {
        
        Vreme v1(2, 20);
        Vreme v2(2, 42);

        Film f1("Montevideo", v1);
        StraniFilm f2("Avatar", v2, "Titlovan", "Murica");

        f1.oceniFilm(8.2);
        f1.oceniFilm(10.0);
        f1.oceniFilm(7.8);
        f1.oceniFilm(6.0);

        f2.oceniFilm(8.2);
        f2.oceniFilm(8.0);
        f2.oceniFilm(9.8);
        f2.oceniFilm(8.0);

        std::cout << f1 << endl;

        std::cout << f2 << endl;
        return 0;
    }
    catch (exception e) {
        std::cout << e.what() << std::endl;
    }
}