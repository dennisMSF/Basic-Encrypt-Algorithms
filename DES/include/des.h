#include "funt.h"
class des{
public:
    string mensaje;
    string clave_bits;
    vector<string>subclaves;
    vector<string>bloques;
    string cifrado(string);
    string descifrado(string);
    des(string,int);
};
