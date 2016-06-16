#include <iostream>

#include "BigInt.h"

using namespace std;

int main(int argc, char *argv[]){
    BigInt enterolargo;
    BigInt enterolargo2("9530273759835"); 
    BigInt enterolargo3(59837);
    cout<<"enterlargo="<<enterolargo<<endl;
    cout<<"enterlargo2="<<enterolargo2<<endl;
    cout<<"enterlargo3="<<enterolargo3<<endl;
    
    BigInt enterolargo4(enterolargo2);
    cout<<"enterlargo4="<<enterolargo4<<endl;
    
    BigInt enterolargo5;
    enterolargo5=enterolargo3;
    cout<<"enterlargo5="<<enterolargo5<<endl;
    
    enterolargo=enterolargo2+enterolargo3;
    cout<<"enterlargo="<<enterolargo<<endl;
    
    BigInt enterolargo6(9);
    BigInt enterolargo7(15);
    cout<<"enterlargo6+enterlargo7="<<enterolargo6+enterolargo7<<endl;
    
    cout<<"Introduce dos enteros largos:";
    cin>>enterolargo>>enterolargo2;
    cout<<"enterlargo="<<enterolargo<<endl;
    cout<<"enterlargo2="<<enterolargo2<<endl;
    
}
