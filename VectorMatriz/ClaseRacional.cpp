#include <iostream>
#include <cassert>

using namespace std;

class Racional
{
public:
    Racional();
    Racional(int numero);
    Racional(int num, int den);
    ~Racional();
    int getNumerador() const{return numerador;};
    int getDenominador() const{return denominador;};
    Racional operator+() const{return *this;};
    Racional operator-() const;
    Racional operator+(const Racional &racional) const;
    Racional operator-(const Racional &racional) const;
    friend Racional operator+(int numero, const Racional &racional);
    friend Racional operator-(int numero, const Racional &racional);
    Racional operator*(const Racional &racional) const;
    Racional operator/(const Racional &racional) const;
    Racional& operator+=(const Racional &racional);
    Racional& operator-=(const Racional &racional);
    Racional& operator*=(const Racional &racional);
    Racional& operator/=(const Racional &racional);
    bool operator==(const Racional &racional) const;
    bool operator!=(const Racional &racional) const;
    bool operator<(const Racional &racional) const;
    bool operator>(const Racional &racional) const;
    bool operator>=(const Racional &racional) const;
    bool operator<=(const Racional &racional) const;
    friend ostream& operator<<(ostream &flujo,const Racional &racional);

private:
    int numerador;
    int denominador;
    static int mcd(int a,int b);
    void reducir();
};


bool operator==(int numero, const Racional &racional);
bool operator!=(int numero, const Racional &racional);
bool operator<(int numero, const Racional &racional);
bool operator>(int numero, const Racional &racional);
bool operator>=(int numero, const Racional &racional);
bool operator<=(int numero, const Racional &racional);
istream& operator>>(istream &flujo,const Racional &racional);


Racional::Racional()
{
    numerador=0;
    denominador=1;
}

Racional::Racional(int numero)
{
    numerador=numero;
    denominador=1;
}

Racional::Racional(int num, int den)
{
    if(den!=0){
        numerador=num;
        denominador=den;
        if(den<0){
            denominador=-denominador;
            numerador=-numerador;
        }
        reducir();
    }
    else{
        numerador=0;
        denominador=1;
    }
}

Racional::~Racional(){
}

int Racional::mcd(int a, int b){
    if(b==0){
        if(a>0)
            return a;
        else
            return -a;
    }
    else{
        return(mcd(b,a%b));
    }
}

void Racional::reducir(){
    int n=mcd(numerador,denominador);
    numerador/=n;
    denominador/=n;
}

Racional Racional::operator-() const{
    Racional resul(-numerador,denominador);
    return resul;
}

Racional Racional::operator+(const Racional &racional) const{
    Racional resul(numerador*racional.denominador+racional.numerador*denominador,
                   denominador*racional.denominador);
    return resul;
}

Racional Racional::operator-(const Racional &racional) const{
    Racional resul(numerador*racional.denominador-racional.numerador*denominador,
                   denominador*racional.denominador);
    return resul;
}

Racional operator+(int numero, const Racional &racional){
    Racional resul(numero*racional.denominador+racional.numerador,
                    racional.denominador);
    return resul;
}

Racional operator-(int numero, const Racional &racional){
    Racional resul(numero*racional.denominador-racional.numerador,
                    racional.denominador);
    return resul;
}

Racional Racional::operator*(const Racional &racional) const{
    Racional resul(numerador*racional.numerador,
                    denominador*racional.denominador);
    return resul;
}

Racional Racional::operator/(const Racional &racional) const{
    assert(racional.denominador!=0);
    Racional resul(numerador*racional.denominador,
                    denominador*racional.numerador);
    return resul;
}

Racional& Racional::operator+=(const Racional &racional){
    numerador=numerador*racional.denominador+racional.numerador*denominador;
    denominador=denominador*racional.denominador;
    reducir();
    return *this;
}

Racional& Racional::operator-=(const Racional &racional){
    numerador=numerador*racional.denominador-racional.numerador*denominador;
    denominador=denominador*racional.denominador;
    reducir();
    return *this;
}

Racional& Racional::operator*=(const Racional &racional){
    numerador=numerador*racional.numerador;
    denominador=denominador*racional.denominador;
    reducir();
    return *this;
}

Racional& Racional::operator/=(const Racional &racional){
    assert(racional.denominador!=0);
    numerador=numerador*racional.denominador;
    denominador=denominador*racional.numerador;
    reducir();
    return *this;
}

bool Racional::operator==(const Racional &racional) const{
    return (numerador==racional.numerador && denominador==racional.denominador);
}

bool Racional::operator!=(const Racional &racional) const{
    return !(numerador==racional.numerador && denominador==racional.denominador);
}

bool Racional::operator<(const Racional &racional) const{
    return (numerador*racional.denominador<denominador*racional.numerador);
}

bool Racional::operator>(const Racional &racional) const{
    return (numerador*racional.denominador>denominador*racional.numerador);
}

bool Racional::operator>=(const Racional &racional) const{
    return (numerador*racional.denominador>=denominador*racional.numerador);
}

bool Racional::operator<=(const Racional &racional) const{
    return (numerador*racional.denominador<=denominador*racional.numerador);
}

bool operator==(int numero, const Racional &racional){
    return (racional==numero);
}

bool operator!=(int numero, const Racional &racional){
    return (racional!=numero);
}

bool operator<(int numero, const Racional &racional){
    return (racional>=numero);
}

bool operator>(int numero, const Racional &racional){
    return (racional<=numero);
}

bool operator>=(int numero, const Racional &racional){
    return (racional<numero);
}

bool operator<=(int numero, const Racional &racional){
    return (racional>numero);
}

ostream& operator<<(ostream &flujo,const Racional &racional){
    flujo<<racional.numerador<<"/"<<racional.denominador;
    return flujo;
}

istream& operator>>(istream &flujo,Racional &racional){
    char caracter;
    int num,den;
    flujo>>num>>caracter>>den;
    Racional rac(num,den);
    racional=rac;

    return flujo;
}
int main()
{
    Racional racional1(3);
    Racional racional2(3,4);
    Racional racional3(15,6);
    cout<<"racional1 = "<<racional1<<endl;
    cout<<"racional2 = "<<racional2<<endl;
    cout<<"racional3 = "<<racional3<<endl;
    cout<<"Introduce racional (numerador/denominador): ";
    cin>>racional1;
    cout<<"racional1 = "<<racional1<<endl;
}
 
