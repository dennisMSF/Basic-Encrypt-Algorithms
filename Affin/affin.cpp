#include "Affin.h"
#include "math_fun.h.h"
Affin::Affin(){
	srand(time(0));
	flag = true;
	a = rand() % alphabet.size();
	b = rand() % alphabet.size();
	while (flag) {
		if (euclides(a, alphabet.size()) == 1) {
			flag = false;
		}
		else {
			a = rand() % alphabet.size();
		}
	}
}
Affin::Affin(int m, int n) {
	a = m;
	b = n;
	inversa=euclidesext(m, alphabet.size());
}
int Affin::geta()const {
	return a;
}
int Affin::getb()const {
	return b;
}
int Affin::getinversa()const {
	return inversa;
}
string Affin::cifrado(string mensaje) {
	string aux;
	for (int i = 0; i < mensaje.size(); i++) {
		for (int j = 0; j < alphabet.size(); j++) {
			if (mensaje[i] == alphabet[j]) {
				int c = geta() * j + getb();
				int tmp = modulo(c, alphabet.size());
				aux += alphabet[tmp];
			}
		}

	}
	cout << aux << endl;
	return aux;
}
string Affin::descifrado(string mensaje) {
	string aux;
	for (int i = 0; i < mensaje.size(); i++) {
		for (int j = 0; j <alphabet.size(); j++) {
			if (mensaje[i] == alphabet[j]) {
				int c = inversa * (j - b);
				int tmp = modulo(c, alphabet.size());
				aux += alphabet[tmp];
			}
		}

	}
	cout << aux << endl;
	return aux;
}
