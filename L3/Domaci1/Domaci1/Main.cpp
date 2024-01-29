#include <iostream>
#include <string>
#include <iostream>
#include "Rec.h"
#include "Stih.h"
#include "Skup.h"
#include "Strofa.h"
#include "Katren.h"
#include "Error.h"

using namespace std;

int main() {
    try {
       /* Rec r1("My");
        Rec r2("thoughts");
        Rec r3("are");
        Rec r4("sporatic");
        Rec r5("I");
        Rec r6("act");
        Rec r7("like");
        Rec r8("Im");
        Rec r9("an");
        Rec r10("addict");
        Rec r11("I");
        Rec r12("rap");
        Rec r13("like");
        Rec r14("Im");
        Rec r15("addicted");
        Rec r16("to");
        Rec r17("smack");
        Rec r18("like");
        Rec r19("Im");
        Rec r20("Kim");
        Rec r21("Mathers");
        */

        Rec r1("Celo");
        Rec r2("selo");
        Rec r3("Smrce");
        Rec r4("belo");
        Rec r5("Pop");
        Rec r6("drzi");
        Rec r7("opelo");
        Rec r8("Carevo");
        Rec r9("novo");
        Rec r10("odelo");
        Rec r69;

        Stih s1;
        Stih s2;
        Stih s3;
        Stih s4;
        Stih s5;
        Katren st;
        s1 += r1;
        s1 += r2;
        s2 += r3;
        s2 += r4;
        s3 += r5;
        s3 += r6;
        s3 += r7;
        s4 += r8;
        s4 += r9;
        s4 += r10;
        
        st += s1;
        st += s2;
        st += s3;
        st += s4;

        cout << r7(3)<<endl;

        cout << (r1 ^ r2)<<endl;
        cout << (r1 ^ r3)<<endl;

        cout << st<<endl;
        cout << *st<<endl;

        st(2, 4);
        cout << st << endl;

        cin >> s5;
        cout << s5<<endl;
        cin >> r69;
        cout << r69<<endl;

        return 0;
    }
    catch (exception e) {
        std::cout << e.what() << std::endl;
    }
}