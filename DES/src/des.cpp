#include "des.h"
des::des(string a,int x){
    clave_bits=binario_clave(x);
    mensaje=a;
}
string des::cifrado(string x){
    string permutacion_1;
    for(int i=0;i<pc1.size();i++){
        permutacion_1+=clave_bits[pc1[i]];
    }
    string R0=permutacion_1.substr(0,permutacion_1.size()/2);
    string L0=permutacion_1.substr(permutacion_1.size()/2,permutacion_1.size());
    string R0_aux;
    string L0_aux;
    string result_aux;
    string permutacion_2;
    for(int i=0;i<16;i++){
        R0_aux=R0.substr(rotaciones[i],R0.size())+R0.substr(0,rotaciones[i]);
        L0_aux=L0.substr(rotaciones[i],L0.size())+L0.substr(0,rotaciones[i]);
        result_aux=R0_aux+L0_aux;
        for(int i=0;i<pc_2.size();i++){
            permutacion_2+=result_aux[pc_2[i]-1];
        }
        subclaves.push_back(permutacion_2);
        permutacion_2="";
    }
/// /////////////////Mensaje///////////////////////////////
    string mensaje_auxiliar;
    for(int i=0;i<mensaje.size();i++){
        mensaje_auxiliar+=binario_m(mensaje[i]);
    }
    int i=0;
    while(mensaje_auxiliar.size()%64!=0){
        mensaje_auxiliar+=mensaje_auxiliar[i];
        i++;
    }
    string temporal;
    for(int i=0;i<ip_1.size();i++){
        temporal+=mensaje_auxiliar[ip_1[i]-1];
    }
    string MR0=temporal.substr(0,temporal.size()/2);
    string ML0=temporal.substr(temporal.size()/2,temporal.size());
    string expandido;
    for(int i=0;i<expansion.size();i++){
        expandido+=MR0[expansion[i]-1];
    }
    string xor_result;
    vector<string>xor_rr;
    for(int i=0;i<subclaves.size();i++){
        for(int j=0;j<subclaves[i].size();j++){
            if(subclaves[i][j]==expandido[j]){
                xor_result+='0';
            }
            else{
                xor_result+='1';
            }
        }
        xor_rr.push_back(xor_result);
        xor_result="";
    }
    for(int i=0;i<xor_rr.size();i++){
        cout<<xor_rr[i]<<" "<<xor_rr[i].size()<<endl;
    }
    vector<string>b8;
    string temporal_1;
    int caja=1;
    for(int i=0;i<xor_rr.size();i++){
        for(int j=0;j<xor_rr[i].size();j++){
            temporal_1+=xor_rr[i][j];
            if(temporal_1.size()==6){
                b8.push_back(temporal_1);
                string fila;
                fila=fila+temporal_1[0]+temporal_1[5];
                string columna=temporal_1.substr(1,4);
                //cout<<endl<<fila<<" "<<columna<<endl;
                int tmp_fila=numero(fila);
                int tmp_columna=numero(columna);
                int salida=seleccionar(caja)[tmp_fila][tmp_columna];
                string salida_s=int_to_string(salida);
                temporal_1="";
                cout<<caja<<endl;
                caja++;
            }
        }
        caja=1;
    }
    return "A";
}
