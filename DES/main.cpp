#include "des.h"
using namespace std;
int main(){
    string mensaje_cifrar;
    getline(cin,mensaje_cifrar);
    des cypher(mensaje_cifrar,24);
    cypher.cifrado(mensaje_cifrar);
}
