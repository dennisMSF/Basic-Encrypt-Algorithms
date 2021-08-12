#include "enigma.h"
enigma::enigma(string x,int b, int c, int d){
    clave=x;
    rt1=seleccionar(b);
    rt2=seleccionar(c);
    rt3=seleccionar(d);
    l1=limite[b-1];
    l2=limite[c-1];
    l3=limite[d-1];
}
string enigma::cifrar(string a){
    int tmp_3, tmp_2, tmp_1;
    string rslt;
    tmp_1=alfabeto.find(clave[0]);
    tmp_2=alfabeto.find(clave[1]);
    tmp_3=alfabeto.find(clave[2]);
    for(int i=0;i<a.size();i++){
        if(a[i]==stecker[0]){
            a[i]=stecker[1];
        }
        else if(a[i]==stecker[1]){
            a[i]=stecker[0];
        }
        string cambio;
        int aux;
        tmp_3=modulo(tmp_3+1,alfabeto.size());
        if(tmp_3==(alfabeto.find(l3))){
            tmp_2++;
        }
        if(tmp_2==(alfabeto.find(l2)-1)){
            tmp_2++;
            tmp_1++;
        }
        cambio=rt3[modulo(alfabeto.find(a[i])+tmp_3,alfabeto.size())];
        cambio=rt2[modulo(alfabeto.find(cambio)-tmp_3+tmp_2,alfabeto.size())];
        cambio=rt1[modulo (alfabeto.find(cambio)+tmp_1-tmp_2,alfabeto.size())];

        cambio=reflector[modulo(alfabeto.find(cambio)-tmp_1,alfabeto.size())];

        aux=modulo(rt1.find(alfabeto[modulo((alfabeto.find(cambio)+tmp_1),(alfabeto.size()))])-tmp_1,alfabeto.size());
        aux=modulo(rt2.find(alfabeto[modulo(aux+tmp_2,alfabeto.size())])-tmp_2,alfabeto.size());
        cambio=alfabeto[modulo(rt3.find(alfabeto[modulo(aux+tmp_3,alfabeto.size())])-tmp_3,alfabeto.size())];
        rslt+=cambio;
        if(rslt[i]==stecker[0]){
            rslt[i]=stecker[1];
        }
        else if(rslt[i]==stecker[1]){
            rslt[i]=stecker[0];
        }
    }
    cout<<tmp_1<<" "<<tmp_2<<" "<<tmp_3<<" "<<endl;
    return rslt;

}
string enigma::descifrar(string a){
    int tmp_3, tmp_2, tmp_1;
    string rslt;
    tmp_1=alfabeto.find(clave[0]);
    tmp_2=alfabeto.find(clave[1]);
    tmp_3=alfabeto.find(clave[2]);
    for(int i=0;i<a.size();i++){
        if(a[i]==stecker[0]){
            a[i]=stecker[1];
        }
        else if(a[i]==stecker[1]){
            a[i]=stecker[0];
        }
        string cambio;
        int aux;
        tmp_3=modulo(tmp_3+1,alfabeto.size());
        if(tmp_3==(alfabeto.find(l3))){
            tmp_2++;
        }
        if(tmp_2==(alfabeto.find(l2)-1)){
            tmp_2++;
            tmp_1++;
        }
        cambio=rt3[modulo(alfabeto.find(a[i])+tmp_3,alfabeto.size())];
        cambio=rt2[modulo(alfabeto.find(cambio)-tmp_3+tmp_2,alfabeto.size())];
        cambio=rt1[modulo (alfabeto.find(cambio)+tmp_1-tmp_2,alfabeto.size())];

        cambio=reflector[modulo(alfabeto.find(cambio)-tmp_1,alfabeto.size())];

        aux=modulo(rt1.find(alfabeto[modulo((alfabeto.find(cambio)+tmp_1),(alfabeto.size()))])-tmp_1,alfabeto.size());
        aux=modulo(rt2.find(alfabeto[modulo(aux+tmp_2,alfabeto.size())])-tmp_2,alfabeto.size());
        cambio=alfabeto[modulo(rt3.find(alfabeto[modulo(aux+tmp_3,alfabeto.size())])-tmp_3,alfabeto.size())];
        rslt+=cambio;
        if(rslt[i]==stecker[0]){
            rslt[i]=stecker[1];
        }
        else if(rslt[i]==stecker[1]){
            rslt[i]=stecker[0];
        }
    }
    return rslt;
}
string enigma::seleccionar(int a){
    switch (a){
    case 1:
        return r1;
    case 2:
        return r2;
    case 3:
        return r3;
    case 4:
        return r4;
    case 5:
        return r5;
    case 6:
        return r6;
    case 7:
        return r7;
    case 8:
        return r8;
    }
}
int enigma::modulo(int a,int b){
     if(a==0){
        return 0;
    }
    int tmp=a/b;
    int r=a-(tmp*b);
    if(r<0){
        r+=b;
    }
    return r;
}
