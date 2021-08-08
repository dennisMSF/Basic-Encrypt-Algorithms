#include "rsa.h"
int main()
{
    rsa objeto(8);
    //cout<<objeto.gete()<<endl<<objeto.getd()<<endl<<objeto.getn()<<endl<<objeto.getp()<<endl<<objeto.getq()<<endl;
    /*rsa objeto(conv<ZZ>("151"),conv<ZZ>("41693"),conv<ZZ>("26791"),conv<ZZ>("41693"));
    string mensaje;
    getline(cin,mensaje);
    cout<<objeto.cifrado(mensaje);*/
    cout<<objeto.descifrado("00000000");
}
