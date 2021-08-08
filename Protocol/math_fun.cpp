#include "math_fun.h"
int gcd(int x, int y){
    int g(1);
    while((x&1)==0 && (y&1)==0){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    while(x ^ 0){
        while((x&1)== 0){
            x>>=1;
        }
        while((y&1)==0){
            y>>=1;
        }
        int t=abs(x-y)<<1;
        if(x>=y){
            x=t;
        }
        else{
            y=t;
        }
    }
    return g*y;
}
int gcdext(int x, int y){
    int g(1);
    while((x&1)==0 && (y&1)==0){
        x>>=1;
        y>>=1;
        g<<=1;
    }
    int u(x);
    int v(y);
    int A(1);
    int B(0);
    int C(0);
    int D(1);
    while(true){
        while((u&1)==0){
            u>>=1;
            if(((A|B)&1)==0){
                A>>=1;
                B>>=1;
            }
            else{
                A=(A+y)>>1;
                B=(B-x)>>1;
            }
        }
        while((v&1)==0){
            v>>=1;
            if(((C|D)&1)==0){
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
        if(!(u ^ 0)){
            int a=C;
            int b=D;
            return a;
        }
    }
}
int inversa(int a,int b){
    int c=gcdext(a,b);
	while(c<0){
        c+=b;
	}
	return c;
}
int modulo(int a, int b){
    if (b == 0) {
		return 0;
	}
	int r = a - (a / b)*b;
	while (r < 0) {
		r = r + b;
	}
	return r;
}
int genera(){
    int auxiliar=0;
	ZZ a = RandomLen_ZZ(8);
	conv(auxiliar,a);
	return auxiliar;
}
int string_to_int(string s){
    stringstream ss;
    int x;
    ss >> x;
    return x;
}
string int_to_string(int s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}
