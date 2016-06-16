#include <iostream>

#include "polilinea.h"

using namespace std;

int main(int argc, char *argv[]){
    Polilinea pol;
    Punto punto1(-4,2),punto2(-2,-2),punto3(1,-3),punto4(2,4),punto5(-1,3);
    pol=pol+punto1+punto2+punto3+punto4+punto5;

    cout<<"pol:"<<endl<<pol;

    Polilinea pol2;
    pol2=pol;
    cout<<"pol2:"<<endl<<pol2;
    cout<<"pol==pol2: "<<boolalpha<<(pol==pol2)<<endl;
    cout<<"pol!=pol2: "<<boolalpha<<(pol!=pol2)<<endl;

    Polilinea pol3;
    pol3=punto5+(punto4+(punto3+(punto2+(punto1+pol3))));

    cout<<"pol3:"<<endl<<pol3;
    cout<<"pol==pol3: "<<boolalpha<<(pol==pol3)<<endl;
    cout<<"pol!=pol3: "<<boolalpha<<(pol!=pol3)<<endl;

    pol2[1]=punto5;
    cout<<"pol2[1]="<<pol[2]<<endl;

    cout<<"Escribiendo polilinea pol ..."<<endl;
    pol.EscribirPolilinea("pol.txt");
    Polilinea pol4;
    pol4.LeerPolilinea("pol.txt");
    cout<<"pol4:"<<endl<<pol4;

    cout<<"Escribiendo polilinea pol3 ..."<<endl;
    pol3.EscribirPolilinea("pol3.txt","Esto es un ejemplo de comentario");
    pol3.LeerPolilinea("pol3.txt");
    cout<<"pol3:"<<endl<<pol3;
}
