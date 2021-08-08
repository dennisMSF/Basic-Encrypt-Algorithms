#include "rsa.h"
int main()
{
    rsa objetos(4);
    cout<<objetos.descifrado("00000000000000");
    /*rsa objeto(ZZ(151),ZZ(41693));
    Image c;
    c.loadFromFile("el.jpg");
    Vector2<unsigned int>x=c.getSize();
    string bloque;
    string bloque_aux;
    for(int i=0;i<x.x;i++){
        for(int j=0;j<x.y;j++){
         Color sd=c.getPixel(i,j);
         int r=sd.r,g=sd.g,b=sd.b;
         string r_s,g_s,b_s;
         r_s=int_to_string(r);
         g_s=int_to_string(g);
         b_s=int_to_string(b);
         if(r_s.size()<3){
            r_s.insert(0,3-r_s.size(),'0');
         }
         if(g_s.size()<3){
            g_s.insert(0,3-g_s.size(),'0');
         }
         if(b_s.size()<3){
            b_s.insert(0,3-b_s.size(),'0');
         }
         bloque_aux=bloque_aux+r_s+g_s+b_s;
         bloque+=bloque_aux;
         bloque_aux="";
        }
    }
    cout<<objeto.cifrado(bloque);*/
    //cout<<endl<<objetos.gete()<<" "<<objetos.getd()<<" "<<objetos.getn()<<endl;
}
