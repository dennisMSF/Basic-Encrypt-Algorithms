#include "affin.h"
affin::affin(){
	a = modulo(genera(),alf.size());
	b = modulo(genera(),alf.size());
	while (gcd(a, alf.size()) ^ 1) {
        a = modulo(genera(),alf.size());
    }
}
affin::affin(ZZ m, ZZ n) {
	conv(a,m);
	conv(b,n);
	inv=inversa(a, alf.size());
}
string affin::cifrado(string mensaje) {
	string aux;
	for (int i = 0; i < mensaje.size(); i++) {
        int c=modulo((a* alf.find(mensaje[i])+b),alf.size());
        aux+=alf[c];
	}
	return aux;
}
string affin::descifrado(string mensaje) {
	string aux;
	for (int i = 0; i < mensaje.size(); i++) {
		int c=modulo((inv * (alf.find(mensaje[i])-b)),alf.size());
        aux+=alf[c];
	}
	return aux;
}
int affin::geta(){
    return a;
}
int affin::getb(){
    return b;
}
string affin::getms(){
    return mensaje_aux;
}
