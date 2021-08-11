#include<iostream>
#include<string>
using namespace std;
string alfabeto="abcdefghijklmnopqrstuvwxyz ";
string rellenarx(string a,int clave){
    string auxh=a;
    for(int i=0;i<100000;i+=(clave-1)){
        if(i>(a.size()-1)){
            //cout<<endl<<i<<endl;
            for(int j=(a.size()-1);j<i;j++){
                auxh+='x';
            }
            break;
        }
    }
    return auxh;
}
string volta(string b){
    string temp=b;
    for(int i=0;i<b.size();i++){
        for(int j=0;j<alfabeto.size();j++){
            if(b[i]==alfabeto[j]){
                temp[i]=alfabeto[alfabeto.size()-1-j];
            }
        }
    }
    return temp;
}
string vuelta2(string a){
    string temp=a;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<alfabeto.size();j++){
            if(a[i]==alfabeto[j]){
                temp[i]=alfabeto[alfabeto.size()-1-j];
            }
        }
    }
    return temp;
}
string cif(string a,int clave){
    string aux;
    for(int i=0;i<clave;i++){
        int j=i;
        bool b=1;
        while(j<a.size()){
            aux+=a[j];
            if(b){
                int salto=(clave*2)-(2*i)-2;
                if(salto!=0){
                    j+=salto;
                }
                else{
                    j+=2*(clave-1);
                }
            }
            else{
                int salto=2*i;
                if(salto!=0){
                    j+=salto;
                }
                else{
                    j+=2*(clave-1);
                }
            }
            b=!b;
        }
    }
    return aux;

}
string decifrar(string a, int clave){
    string aux6=a;
    int i=0;
    int k=0;
    while(i<a.size()){
        int j=k;
        bool x=true;
        while(j<a.size()){
            aux6[j]=a[i++];
            if(x){
                int movida=2*clave-2*k-2;
                if(movida!=0){
                    j+=movida;
                }
                else{
                    j+=2*(clave-1);
                }
            }
            else{
                int movida=2*k;
                if(movida!=0){
                    j+=movida;
                }
                else{
                    j+=2*(clave-1);
                }
            }
            x=!x;
        }
        k++;
    }
    return aux6;
}
int main(){
    char mensaje[1000];
    cin.getline(mensaje,1000);
    string mesagge(mensaje);
    cout<<"ingrese clave: ";
    int clave;
    cin>>clave;
    string aux1=rellenarx(mesagge,clave);
    string b=cif(volta(aux1),clave);
    cout<<b;
    cout<<endl<<endl;
    string g=vuelta2(decifrar(mensaje,clave));
    cout<<endl<<g;

}
