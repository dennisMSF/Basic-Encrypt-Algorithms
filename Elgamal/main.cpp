#include "elgamal.h"
using namespace std;

int main()
{
    elgamal objeto(10);
    cout<<objeto.getroot()<<" "<<objeto.getp()<<" "<<objeto.getpublickey();
}
