#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <bitset>
#include <NTL/ZZ.h>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace NTL;
using namespace std;
using namespace sf;
int mod(int a, int b){
    int r = a-b*(a/b);
    return (r<0) ? b+r : r ;
}
string corrimiento_izquierda(string a){
    string aux;
    aux=a.substr(1,a.size()-1)+a.substr(0,1);
    return aux;
}
string corrimiento_derecha(string a){
    string aux;
    aux=a.substr(0,a.size()-1)+a.substr(a.size()-1,1);
    return aux;
}
int string_to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
string int_to_string(int s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
ZZ modulo(ZZ x, ZZ y){
    if (y == 0) {
		return ZZ(0);
	}
	ZZ r = x - (x / y)*y;
	while (r < 0) {
		r +=y;
	}
	return r;
}
string ZZ_to_string(ZZ s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
ZZ string_to_ZZ(string s){
    stringstream geek(s);
    ZZ x;
    geek >> x;
    return x;
}
void swap_(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    Image img;
    int bit;
    cin >> bit;
    img.loadFromFile("momo.jpg");
    vector<int> k;
    for(int i=0 ; i<bit ; i++){
        Color c_rgb = img.getPixel(i,0);
        k.push_back( c_rgb.r);
        k.push_back( c_rgb.g);
        k.push_back( c_rgb.b);
    }

    vector<int> s;
    for(int i=0;i<bit;i++){
        s.push_back(i);
    }
    int f=0;

    for(int i=0 ; i<bit ; i++)
    {
        f = mod( f+s[i]+k[i], bit );
        swap_(s[i], s[f]);
    }
    int const g=4;
    bitset<g> foo;
    string str="";
    for(int i=0 ; i<bit ; i++)
    {
        i = ( mod(i+1, bit) );
        f = mod( f+s[i], bit );
        swap_(s[i], s[f]);
        foo = mod(s[i] + s[f], bit);
        str.append(foo.to_string());
    }
    cout<<str<<endl;
    /// /////////////
    srand(time(0));
    int particiones=4;
    vector<int> n_taps={11,2,3,15,6};
    string seed=str;
    ZZ aux(0);
    if(seed.size()<bit){
        for(int i=0;seed.size()!=bit;i++){
            aux=modulo(ZZ(string_to_int(seed.substr(i+1,1))+string_to_int(seed.substr(i,1))),ZZ(2));
            seed.append(ZZ_to_string(aux));
            aux=0;
        }
    }
    int n_1=0;
    int n_0=0;
    for(int i=0;i<seed.size();i++){
        if(seed[i]=='1'){
            n_1++;
        }
    }
    n_0=seed.size()-n_1;
    while(n_1!=n_0){
        int ran=rand()%bit;
        switch (n_1<n_0){
            case 0:
                if(seed[ran]=='0'){
                    ran=rand()%bit;
                }
                else{
                    seed[ran]='0';
                    n_0++;n_1--;
                }
                break;

            case 1:
                if(seed[ran]=='1'){
                    ran=rand()%bit;
                }
                else{
                    seed[ran]='1';
                    n_1++;n_0--;
                }
                break;
        }
    }
    int l=0;
    string l_aux;
    string l_auxi;
    vector<string> ayuda_trampa;
    while(l<16){
        //ZZ le_auxiliar=string_to_ZZ(seed.substr(0,1))+string_to_ZZ(seed.substr(n_taps[0],1))+string_to_ZZ(seed.substr(n_taps[1],1))+string_to_ZZ(seed.substr(n_taps[2],1));
        ZZ le_auxiliar;
        for(int i=0;i<n_taps.size();i++){
            le_auxiliar=le_auxiliar+string_to_ZZ(seed.substr(n_taps[i],1));
        }
        le_auxiliar+=string_to_ZZ(seed.substr(0,1));
        l_aux=l_aux+seed.substr(1,seed.size()-1);
        l_auxi=l_aux+ZZ_to_string(modulo(le_auxiliar,ZZ(2)));
        for(int i=0;i<l_auxi.size();i+=(bit/particiones)){
            ayuda_trampa.push_back(l_auxi.substr(i,bit/particiones));
        }
        for(int i=0;i<ayuda_trampa.size();i++){
            switch (i&1){
                case 0:
                  ayuda_trampa[i]=corrimiento_izquierda(ayuda_trampa[i]);
                  continue;
                case 1:
                  ayuda_trampa[i]=corrimiento_derecha(ayuda_trampa[i]);
                  continue;
          }
        }
        string temporal;
        for(int i=0;i<ayuda_trampa.size();i++){
            temporal+=ayuda_trampa[i];
        }
        l_auxi=temporal;
        l_aux="";
        ayuda_trampa={};
        seed=l_auxi;
        l++;
    }
    ZZ c(1);
    ZZ result;
    for(int i=0;i<l_auxi.size();i++){
        if(l_auxi[i]=='1'){
            c<<=(l_auxi.size()-1-i);
            result+=c;
            c=1;
        }
    }
    cout<<result;
    return 0;

}
