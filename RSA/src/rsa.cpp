#include "rsa.h"
rsa::rsa(int a){
    /*p=GenPrime_ZZ(a);
    q=GenPrime_ZZ(a);
    n=p*q;
    phi=conv<ZZ>(((p-ZZ(1))*(q-ZZ(1))));
    e=generare(phi,a);
    d=inversa(modulo(phi,n),e);*/
    d=conv<ZZ>("26791");
    n=conv<ZZ>("41693");
    p=conv<ZZ>("241");
    q=conv<ZZ>("173");
    n_ext=conv<ZZ>("41693");
    e_ext=conv<ZZ>("151");
}
rsa::rsa(ZZ e_receptor,ZZ n_receptor){
    e_ext=e_receptor;
    n_ext=n_receptor;
}
string rsa::cifrado(string mensaje){
    string resultado_bloques;
    string cadena_letras=mensaje;
    string binario_e_receptor=binario(e_ext);
    int bloques_n_receptor=ZZ_to_string(n_ext).size();
    ZZ resultado_exponenciacion;
    cadena_letras.append(conv<int>(ZZ(bloques_n_receptor-1)-modulo(ZZ(cadena_letras.size()),ZZ(bloques_n_receptor-1))),'2');
    for(int i=0;i<cadena_letras.size();i+=bloques_n_receptor-1){
        resultado_exponenciacion=bynexpo(string_to_ZZ(cadena_letras.substr(i,bloques_n_receptor-1)),binario_e_receptor,n_ext);
        resultado_bloques+=ZZ_to_string(resultado_exponenciacion).insert(0,ZZ_to_string(n_ext).size()-ZZ_to_string(resultado_exponenciacion).size(),'0');
    }
    return resultado_bloques;
}
string rsa::descifrado(string a){
    string mensaje;
    string resultado_firma;
    int bloques_n_emisor=ZZ_to_string(n).size();
    vector <ZZ> operaciones=precalculo(d,q,p);
    ZZ resultado_exponenciacion_firma;
    for(int i=0;i<a.size();i+=bloques_n_emisor){
        resultado_exponenciacion_firma=restochino(operaciones,string_to_ZZ(a.substr(i,bloques_n_emisor)));
        resultado_firma+=ZZ_to_string(resultado_exponenciacion_firma).insert(0,(ZZ_to_string(n).size()-1)-ZZ_to_string(resultado_exponenciacion_firma).size(),'0');
    }
    cout<<resultado_firma.size();
/// //////////////////RECONSTRUYENDO LA IMAGEN/////////////////////////////// ///
    Image c;
    c.loadFromFile("lienzo.jpg");
    Vector2<unsigned int>x=c.getSize();
    vector<char> tmp;
    int cont_x=0,cont_y=0;
    for(int i=0;i<resultado_firma.size();i+=3){
        tmp.push_back(string_to_int(resultado_firma.substr(i,3)));
        if(tmp.size()==3){
                 Color sd;
                 sd.r=tmp[0];
                 sd.g=tmp[1];
                 sd.b=tmp[2];
                 //cout<<cont_x<<" "<<cont_y<<endl;
                 c.setPixel(cont_x,cont_y,sd);
                 cont_y++;
                 if(cont_y==x.y+1 && cont_x<x.x){
                    cont_x++;
                    cont_y=0;
                 }
                 if(cont_x==90 && cont_y==90){
                    break;
                 }
            tmp.clear();
        }
    }
    c.saveToFile("decif.jpg");
    return "descifrado";
}
vector<ZZ> rsa::precalculo(ZZ d,ZZ q,ZZ p){
    vector<ZZ> auxiliar;
    ZZ dp;
    ZZ dq;
    dp=modulo(d,p-1);
    dq=modulo(d,q-1);
    ZZ p_inversa;
    p_inversa=bynexpo(p,binario(q-2),q);
    auxiliar.push_back(dp);
    auxiliar.push_back(dq);
    auxiliar.push_back(p_inversa);
    return auxiliar;
}
ZZ rsa::restochino(vector<ZZ> g,ZZ j){
    ZZ cp;
    ZZ cq;
    cp=modulo(j,p);
    cq=modulo(j,q);
    ZZ x1;
    ZZ x2;
    x1=bynexpo(cp,binario(g[0]),p);
    x2=bynexpo(cq,binario(g[1]),q);
    ZZ h;
    h=modulo(((x2-x1)*g[2]),q);
    ZZ x;
    x=x1+h*p;
    return x;
}
ZZ rsa::getd(){return d;}
ZZ rsa::gete(){return e;}
ZZ rsa::getn(){return n;}
ZZ rsa::getp(){return p;}
ZZ rsa::getq(){return q;}
