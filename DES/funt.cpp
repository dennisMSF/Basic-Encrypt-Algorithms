#include "funt.h"
string binario_m(int numero){
   string result;
   while(numero>0){
        if(numero%2==0){
            result+='0';
            numero>>=1;
        }
        else{
            result+='1';
            numero>>=1;
        }
   }
   string aux;
   for(int i=result.size()-1;i>=0;i--){
        aux+=result[i];
   }
   if(aux.size()<8){
        aux.insert(0,8-aux.size(),'0');
   }
   return aux;
}
string binario_clave(int numero){
   string result;
   while(numero>0){
        if(numero%2==0){
            result+='0';
            numero>>=1;
        }
        else{
            result+='1';
            numero>>=1;
        }
   }
   string aux;
   for(int i=result.size()-1;i>=0;i--){
        aux+=result[i];
   }
   if(aux.size()<8){
        aux.insert(0,8-aux.size(),'0');
   }
   while(aux.size()<64){
        aux+=aux;
   }
   return aux;
}
int numero(string x){
    int resultado=0;
    int aux=1;
    for(int i=0;i<x.size();i++){
        if(x[i]=='1'){
            aux<<=(x.size()-1-i);
            resultado+=aux;
            aux=1;
        }
    }
    return resultado;
}
string int_to_string(int x){
    string result;
    while(x>0){
        if(x%2==0){
            result+='0';
            x>>=1;
        }
        else{
            result+='1';
            x>>=1;
        }
   }
   string aux;
   for(int i=result.size()-1;i>=0;i--){
        aux+=result[i];
   }
   if(aux.size()<4){
        aux.insert(0,4-aux.size(),'0');
   }
   return aux;
}
vector<vector<int> >seleccionar(int x){
    switch (x){
        case 1:
            return caja_S1;
        case 2:
            return caja_S2;
        case 3:
            return caja_S3;
        case 4:
            return caja_S4;
        case 5:
            return caja_S5;
        case 6:
            return caja_S6;
        case 7:
            return caja_S7;
        case 8:
            return caja_S8;
    }

};
