#include "elgamal.h"
elgamal::elgamal(int t)
    :p(gen_prime2p_1(t))
            {
                root=conv<ZZ>(gen_root(p));
                d=gen_d(t,p);
                string bin_d=binario(d);
                /*public_key=bynexpo(root,bin_d,p);
                public_key=byen*/
                x=RandomLen_ZZ(a);
                while(x<1 || x>p-1){
                    x=RandomLen_ZZ(a);
                }
                //public_key=bynexpo(root,bin_d,p);
                public_key=diffie(p,d,x);
            };
elgamal::elgamal(ZZ root_ext,ZZ key_ext,ZZ p_ext){
    d=conv<ZZ>("");
    p=conv<ZZ>("");
    k=hellman(k_ext,p,d);
    r=gen_d(NumBits(p),p);
    string r_bin=binario(r);
    c1=bynexpo(root_ext,r_bin,p_ext);
    k=bynexpo(key_ext,r_bin,p_ext);
    p=p_ext;
}
string elgamal::cifrar(string mensaje){
    string resultado_bloques;
    string cadena_letras;
    int bloques_p_receptor=ZZ_to_string(p).size();
    ZZ resultado_multiplicacion;
    for(int i=0;i<mensaje.size();i++){
        cadena_letras+=arreglar_1(alfabeto.find(mensaje[i]));
    }
    cadena_letras.append(conv<int>(ZZ(bloques_p_receptor-1)-modulo(ZZ(cadena_letras.size()),ZZ(bloques_p_receptor-1))),'2');
    for(int i=0;i<cadena_letras.size();i+=bloques_p_receptor-1){
        resultado_multiplicacion=modulo(string_to_ZZ(cadena_letras.substr(i,bloques_p_receptor-1))*k,p);
        resultado_bloques+=arreglar_2(resultado_multiplicacion,p);
    }
    string arreglo=arreglar_2(c1,p);
    resultado_bloques=arreglo+resultado_bloques;
}
string elgamal::decifrar(string mensaje){
    string resultado;
    string resultado_bloques;
    ZZ resultado_multiplicacion;
    int bloques_p_emisor=ZZ_to_string(p).size();
    ZZ k;
    ZZ k_inversa;
    string bin_d=binario(d);
    k=bynexpo(string_to_ZZ(mensaje.substr(0,ZZ_to_string(p).size())),bin_d,p);
    k_inversa=inversa(k,p);
    for(int i=ZZ_to_string(p).size();i<mensaje.size();i+=bloques_p_emisor){
       resultado_multiplicacion=modulo(string_to_ZZ(mensaje.substr(i,bloques_p_emisor))*k_inversa,p);
       resultado_bloques=arreglar_3(resultado_multiplicacion,p);
    }
     for(int i=0;i<resultado_bloques.size();i+=(int_to_string(alfabeto.size()).size())){
      mensaje+=alfabeto[string_to_int(resultado_bloques.substr(i,int_to_string(alfabeto.size()).size()))];
    }
    return mensaje;
}
ZZ elgamal::getroot(){
    return root;
}
ZZ elgamal::getpublickey(){
    return public_key;
}
ZZ elgamal::getp(){
    return p;
}
ZZ elgamal::getc1(){
    return c1;
}
ZZ elgamal::getc2(){
    return c2;
}
