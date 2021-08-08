#include "cesar.h"
cesar::cesar(){
    clave=modulo(genera(),alf.size());
}
cesar::cesar(int b){
    clave=b;
}
string cesar::cifrar(string a){
   string rslt;
    for(int i=0;i<a.size();i++){
        int aux=modulo(alf.find(a[i])+clave,alf.size());
        rslt+=alf[aux];
    }
    return rslt;
}
string cesar::descifrar(string a){
    string rslt;
    for(int i=0;i<a.size();i++){
        int aux=modulo(alf.find(a[i])-clave,alf.size());
        rslt+=alf[aux];
    }
    return rslt;
}
string cesar::getmensaje(){
    return mensaje;
}
int cesar::geta(){
    return a;
}
int cesar::getb(){
    return b;
}
int cesar::getc(){
    return c;
}
int cesar::getclave(){
    return clave;
}
void cesar::pedir(){
    cout<<"ingrese el mensaje: ";
    cin>>mensaje;
    cin>>a;
    cin>>b;
    cin>>c;
}
