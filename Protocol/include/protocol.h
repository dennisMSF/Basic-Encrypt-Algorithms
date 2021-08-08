#include "math_fun.h"
class protocol{
    public:
        protocol();
        string arreglar(string);
        void descifrar(string);
        void cifrar();
    private:
        int clave_C;
        string clave_E;
        int claveA_A;
        int claveB_A;
        string mensaje_aux;
        string mensaje;
};
