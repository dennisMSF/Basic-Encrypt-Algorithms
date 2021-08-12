#include "enigma.h"
int main()
{
    int a,b,c;
    cout<<"ingrese rotores a usarse: "<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    string d,e,f;
    cout<<"ingrese la clave: "<<endl;
    cin>>d;;
    cout<<endl;
    enigma eni(d,a,b,c);
    string x=eni.cifrar("AAA");
    cout<<x;
}
