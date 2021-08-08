#include "math_fun.h"
class cesar{
    public:
        cesar();
        cesar(int);
        string cifrar(string);
        string descifrar(string);
        string getmensaje();
        int geta();
        int getb();
        int getc();
        int getclave();
        void pedir();
    private:
        string mensaje;
        int clave;
        int a;
        int b;
        int c;
};
