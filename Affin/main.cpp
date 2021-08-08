#include<iostream>
#include"Header.h"
#include "Affin.h"
using namespace std;
int main() {
	char mensaje[100000];
	cin.getline(mensaje, 100000);
	string mesagge(mensaje);
	Affin ese;
	Affin ese2(7, 56);
	cout << ese.geta() << endl << ese.getb() << endl;
	cout << ese2.getinversa() << endl;
	ese.cifrado(mensaje);
	ese2.descifrado("Lu9-KduguKrV_-V");
	system("pause");
}
