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
rsa::rsa(ZZ e_receptor,ZZ n_receptor,ZZ d_emisor,ZZ n_emisor){
    e_ext=e_receptor;
    n_ext=n_receptor;
    d=d_emisor;
    n=n_emisor;
}
string rsa::cifrado(string mensaje){
    string resultado_bloques;
    string resultado_rubrica;
    string resultado_firma;
    string cadena_letras;
    string binario_e_receptor=binario(e_ext);
    string binario_d_emisor=binario(d);
    int bloques_n_receptor=ZZ_to_string(n_ext).size();
    int bloques_n_emisor=ZZ_to_string(n).size();
    ZZ resultado_exponenciacion;
    ZZ resultado_exponenciacion_rubrica;
    ZZ resultado_exponenciacion_firma;
    for(int i=0;i<mensaje.size();i++){
        cadena_letras+=arreglar_1(alfabeto.find(mensaje[i]));
    }
    cadena_letras.append(conv<int>(ZZ(bloques_n_receptor-1)-modulo(ZZ(cadena_letras.size()),ZZ(bloques_n_receptor-1))),'2');
    for(int i=0;i<cadena_letras.size();i+=bloques_n_receptor-1){
        resultado_exponenciacion=bynexpo(string_to_ZZ(cadena_letras.substr(i,bloques_n_receptor-1)),binario_e_receptor,n_ext);
        resultado_bloques+=arreglar_2(resultado_exponenciacion,n_ext);
    }
    if(ZZ(resultado_bloques.size()&1)!=ZZ(0)){
        resultado_bloques+='2';
    }
    resultado_bloques.append(conv<int>(ZZ(bloques_n_emisor-1)-modulo(ZZ(resultado_bloques.size()),ZZ(bloques_n_emisor-1))),'2');
    for(int i=0;i<resultado_bloques.size();i+=bloques_n_emisor-1){
        resultado_exponenciacion_rubrica=bynexpo(string_to_ZZ(resultado_bloques.substr(i,bloques_n_emisor-1)),binario_d_emisor,n);
        resultado_rubrica+=arreglar_2(resultado_exponenciacion_rubrica,n);
    }
    if(ZZ(resultado_rubrica.size()&1)!=ZZ(0)){
        resultado_rubrica+='2';
    }
    resultado_rubrica.append(conv<int>(ZZ(bloques_n_receptor-1)-modulo(ZZ(resultado_rubrica.size()),ZZ(bloques_n_receptor-1))),'2');
    for(int i=0;i<resultado_rubrica.size();i+=bloques_n_receptor-1){
        resultado_exponenciacion_firma=bynexpo(string_to_ZZ(resultado_rubrica.substr(i,bloques_n_receptor-1)),binario_e_receptor,n_ext);
        resultado_firma+=arreglar_2(resultado_exponenciacion_firma,n_ext);
    }
    return resultado_firma;
}
string rsa::descifrado(string a){
    string mensaje;
    string resultado_bloques;
    string resultado_rubrica;
    string resultado_firma;
    string binario_e_receptor=binario(e_ext);
    int bloques_n_receptor=ZZ_to_string(n_ext).size();
    int bloques_n_emisor=ZZ_to_string(n).size();
    vector <ZZ> operaciones=precalculo(d,q,p);
    ZZ resultado_exponenciacion;
    ZZ resultado_exponenciacion_rubrica;
    ZZ resultado_exponenciacion_firma;
    if(ZZ(a.size()&1)!=ZZ(0)){
        a+='2';
    }
    a.append(conv<int>(ZZ(bloques_n_emisor)-modulo(ZZ(a.size()),ZZ(bloques_n_emisor))),'2');
    for(int i=0;i<a.size();i+=bloques_n_emisor){
        resultado_exponenciacion_firma=restochino(operaciones,string_to_ZZ(a.substr(i,bloques_n_emisor)));
        resultado_firma+=arreglar_3(resultado_exponenciacion_firma,n);
    }
    if(ZZ(resultado_firma.size()&1)!=ZZ(0)){
        resultado_firma+='2';
    }
    resultado_firma.append(conv<int>(ZZ(bloques_n_receptor)-modulo(ZZ(resultado_firma.size()),ZZ(bloques_n_receptor))),'2');
    for(int i=0;i<resultado_firma.size();i+=bloques_n_receptor){
        resultado_exponenciacion_rubrica=bynexpo(string_to_ZZ(resultado_firma.substr(i,bloques_n_receptor)),binario_e_receptor,n_ext);
        resultado_rubrica+=arreglar_3(resultado_exponenciacion_rubrica,n_ext);
    }
    for(int i=0;i<resultado_rubrica.size();i+=bloques_n_emisor){
        resultado_exponenciacion_firma=restochino(operaciones,string_to_ZZ(resultado_rubrica.substr(i,bloques_n_emisor)));
        resultado_bloques+=arreglar_3(resultado_exponenciacion_firma,n);
    }
    for(int i=0;i<resultado_bloques.size();i+=(int_to_string(alfabeto.size()).size())){
      mensaje+=alfabeto[string_to_int(resultado_bloques.substr(i,int_to_string(alfabeto.size()).size()))];
    }
    return mensaje;
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
