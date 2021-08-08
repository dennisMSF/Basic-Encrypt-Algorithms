#include "protocol.h"
#include "cesar.h"
#include "enigma.h"
#include "affin.h"
protocol::protocol(){
}
void protocol::descifrar(string txt){

}
void protocol::cifrar(){
    cesar cifrado_1;
    cifrado_1.pedir();
    mensaje_aux=cifrado_1.cifrar(cifrado_1.getmensaje());
    enigma cifrado_2(cifrado_1.getmensaje(),cifrado_1.geta(),cifrado_1.getb(),cifrado_1.getc());
    mensaje_aux=cifrado_2.cifrar(mensaje_aux);
    affin cifrado_3;
    mensaje_aux=cifrado_3.cifrado(mensaje_aux);
    mensaje=mensaje+int_to_string(cifrado_1.geta())+int_to_string(cifrado_1.getb())+int_to_string(cifrado_1.getc())+arreglar(int_to_string(cifrado_1.getclave()))+mensaje_aux;
    cout<<mensaje;
    ofstream archivo("mi_archivo.txt");
    archivo<<arreglar(int_to_string(cifrado_3.geta()))<<arreglar(int_to_string(cifrado_3.getb()))<<'\n';
    archivo<<arreglar(int_to_string(cifrado_1.geta()))<<arreglar(int_to_string(cifrado_1.getb()))<<arreglar(int_to_string(cifrado_1.getc()));
    archivo<<mensaje_aux[0]<<mensaje_aux[1]<<mensaje_aux[2]<<mensaje_aux[3]<<mensaje_aux[4];
    archivo<<mensaje_aux[5]<<mensaje_aux[6]<<mensaje_aux[7]<<'\n';
    archivo<<arreglar(int_to_string(cifrado_1.getclave()))<<'\n';
    for(int i=8;i<mensaje_aux.size();i++){
        archivo<<mensaje_aux[i];
    }
}
string protocol::arreglar(string a){
    if(a.size()<2){
        a="0"+a;
    }
    return a;
}
