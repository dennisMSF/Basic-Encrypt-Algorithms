  
#include "math_fun.h"
ZZ gcd(ZZ x, ZZ y){
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    while(x != ZZ(0)){
        while(ZZ(x&1)==ZZ(0)){
            x>>=1;
        }
        while(ZZ(y&1)==ZZ(0)){
            y>>=1;
        }
        ZZ t=ZZ(abs(x-y))<<1;
        if(x>=y){
            x=t;
        }
        else{
            y=t;
        }
    }
    return ZZ(g*y);
}
pair<ZZ,ZZ> gcdext(ZZ x, ZZ y){
    pair<ZZ,ZZ> auxiliar;
    ZZ g(1);
    while(ZZ(x&1)==ZZ(0) && ZZ(y&1)==ZZ(0)){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    ZZ u(x);
    ZZ v(y);
    ZZ A(1);
    ZZ B(0);
    ZZ C(0);
    ZZ D(1);
    while(true){
        while(ZZ(u&1)==ZZ(0)){
            u>>=1;
            if(ZZ((A|B)&1)==ZZ(0)){
                A>>=1;
                B>>=1;
            }
            else{
                A=(A+y)>>1;
                B=(B-x)>>1;
            }
        }
        while(ZZ(v&1)==ZZ(0)){
            v>>=1;
            if(ZZ((C|D)&1)==ZZ(0)){
                C>>=1;
                D>>=1;
            }
            else{
                C=(C+y)>>1;
                D=(D-x)>>1;
            }
        }
        if (u>=v){
            u=u-v;
            A-=C;
            B-=D;
        }
        else{
            v=v-u;
            C-=A;
            D-=B;
        }
        if(u == ZZ(0)){
            ZZ a(C);
            ZZ b(D);
            auxiliar.first=a;
            auxiliar.second=b;
            return auxiliar;
        }
    }
}
ZZ inversa(ZZ x, ZZ y){
    ZZ c=gcdext(x,y).second;
	while(c<ZZ(0)){
        c+=x;
	}
	return c;
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
ZZ generare(ZZ phi,int g){
    ZZ a;
    a=RandomLen_ZZ(g);
    while(true){
        if(a>1 && a<phi && gcd(phi,a)==1){
            return a;
        }
        else{
            a=RandomLen_ZZ(g);
        }
    }
}
string rev(string b){
    string temp;
    for(int i=0;i<b.size();i++){
        temp+=b[b.size()-1-i];
    }
    return temp;
}
string ZZ_to_string(ZZ s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
string int_to_string(int s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}

int string_to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
ZZ string_to_ZZ(string s){
    stringstream geek(s);
    ZZ x;
    geek >> x;
    return x;
}
string binario(ZZ a){
    string tmp;
    while(a!=ZZ(0)){
        tmp+=ZZ_to_string(ZZ(a%2));
        a>>=1;
   }
   tmp=rev(tmp);
   return tmp;
}
ZZ bynexpo(ZZ b, string n, ZZ m){
    ZZ x(1);
    ZZ power=ZZ(modulo(b,m));
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]=='1'){
            x=modulo(ZZ(x*power),m);
        }
        power=modulo(ZZ(power*power),m);
    }
    return x;
}
string arreglar_1(int a){
    string tmp=int_to_string(a);
    string tmp_1=int_to_string(alfabeto.size());
    if(tmp.size()<(tmp_1.size())){
        tmp.insert(0,(tmp_1.size())-tmp.size(),'0');
    }
    return tmp;
}
string arreglar_2(ZZ a,ZZ n){
    string tmp=ZZ_to_string(a);
    string tmp_1=ZZ_to_string(n);
    if(tmp.size()<(tmp_1.size())){
        tmp.insert(0,(tmp_1.size())-tmp.size(),'0');
    }
    return tmp;
}
string arreglar_3(ZZ a,ZZ n){
    string tmp=ZZ_to_string(a);
    string tmp_1=ZZ_to_string(n);
    if(tmp.size()<(tmp_1.size()-1)){
        tmp.insert(0,(tmp_1.size()-1)-tmp.size(),'0');
    }
    return tmp;
}
