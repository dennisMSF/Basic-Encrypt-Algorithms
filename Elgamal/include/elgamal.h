#include "math_fun.h"
class elgamal{
public:
    elgamal(int);
    elgamal(ZZ,ZZ,ZZ);
    ZZ getroot();
    ZZ getpublickey();
    ZZ getp();
    ZZ getc1();
    ZZ getc2();
    string cifrar(string);
    string decifrar(string);
    void c1c2(ZZ,ZZ);
private:
    ZZ p;
    ZZ root;
    ZZ d;
    ZZ public_key;
    ZZ r;
    ZZ c1;
    ZZ c2;
    ZZ k;
    ZZ x;
};
