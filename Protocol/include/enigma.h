#include "math_fun.h"
class enigma{
    public:
        string r1="EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string r2="AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string r3="BDFHJLCPRTXVZNYEIWGAKMUSQO";
        string r4="ESOVPZJAYQUIRHXLNFTGKDCMWB";
        string r5="VZBRGITYUPSDNHLXAWMJQOFECK";
        string r6="JPGVOUMFYQBENHZRDKASXLICTW";
        string r7="NZJHGRCXMYSWBOUFAIVLPEKQDT";
        string r8="FKQHTLXOCBJSPDZRAMEWNIUYGV";
        string reflector="YRUHQSLDPXNGOKMIEBFZCWVJAT";
        enigma(string,int,int,int);
        string cifrar(string);
        string descifrar(string);
        string seleccionar(int);
        string getst();
        string getcl();
        string getl1();
        string getl2();
        string getl3();
        string getmensaje();
        void pedir();
        int convertir(string);
    private:
        string mensaje;
        string stecker;
        string clave;
        string rt1;
        string rt2;
        string rt3;
        string l1;
        string l2;
        string l3;
};
