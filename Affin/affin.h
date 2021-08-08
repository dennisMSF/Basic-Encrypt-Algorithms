#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
using namespace std;
static string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
class Affin{
private:
	int a;
	int b;
	bool flag;
	int inversa;
public:
	Affin();
	Affin(int a, int b);
	string cifrado(string);
	string descifrado(string);
	int geta()const;
	int getb()const;
	int getinversa()const;
};
