#include <iostream>
#include <cassert>

using namespace std;

class VectorDinamico
{
public:
    VectorDinamico(int vectorSize=0,int initialValue=0);
    VectorDinamico(const VectorDinamico& vector);
    ~VectorDinamico();
    int getSize() const{return size;};
    int getElement(int i) const;
    void setElement(int i,int value);
    void resize(int newSize);
    VectorDinamico& operator=(const VectorDinamico& vector);
    int& operator[](int i);
    const int& operator[](int i) const;
    bool operator==(const VectorDinamico &vector) const;
    bool operator!=(const VectorDinamico &vector) const;
    bool operator<(const VectorDinamico &vector) const;
    bool operator>(const VectorDinamico &vector) const;
    bool operator<=(const VectorDinamico &vector) const;
    bool operator>=(const VectorDinamico &vector) const;
    VectorDinamico operator+(int n) const;
    VectorDinamico operator-(int n) const;
    VectorDinamico& operator+=(int n);
    VectorDinamico& operator-=(int n);
    friend ostream& operator<<(ostream &flujo,const VectorDinamico &vector);
    friend istream& operator>>(istream &flujo,const VectorDinamico &vector);
private:
    int size; // tamanio del vector
    int *ptr; // puntero a los elementos
    void copia(const VectorDinamico& vector);
    void libera();
};


VectorDinamico::VectorDinamico(int vectorSize,int initialValue)
{
    assert(vectorSize>=0);
    size=vectorSize;
    if(size>0){
        ptr = new int[ size ]; // crea espacio para el array de elementos
        for ( int i = 0; i < size; ++i )
            ptr[ i ] = initialValue; // inicializa a 0 los elementos
    }
    else
        ptr=0;
}

VectorDinamico::VectorDinamico(const VectorDinamico& vector){
    copia(vector);
}

void VectorDinamico::copia(const VectorDinamico& vector){
    size=vector.size;
    if(size>0){
        ptr = new int[ size ]; // crea espacio para el array de elementos
        for ( int i = 0; i < size; ++i )
            ptr[ i ] = vector.ptr[i]; // copia valor de elementos
    }
    else
        ptr=0;
}

void VectorDinamico::libera(){
    if(ptr){
        delete[] ptr;
    }
}

VectorDinamico::~VectorDinamico(){
    libera();
}

int VectorDinamico::getElement(int i) const{
    assert(i>=0 && i<size);
    return ptr[i];
}

void VectorDinamico::setElement(int i,int value){
    assert(i>=0 && i<size);
    ptr[i]=value;
}

void VectorDinamico::resize(int newSize){
    assert(newSize>=0);
    if(newSize!=size){
        if(newSize!=0){
            int *newptr;
            newptr=new int[newSize];
            int minimo;
            minimo=size<newSize?size:newSize;
            for(int i=0;i<minimo;++i){ // copiar datos antiguos
                newptr[i]=ptr[i];
            }
            for(int i=minimo;i<newSize;++i){ // poner a 0 resto elementos
                newptr[i]=0;
            }
            libera();
            size=newSize;
            ptr=newptr;
        }
        else{
            libera();
            ptr=0;
            size=0;
        }
    }
}

VectorDinamico& VectorDinamico::operator=(const VectorDinamico& vector){
    if(this!=&vector){
        libera();
        copia(vector);
    }
    return *this;
}

int& VectorDinamico::operator[](int i){
    assert(i>=0 && i<size);
    return ptr[i];
}

const int& VectorDinamico::operator[](int i) const{
    assert(i>=0 && i<size);
    return ptr[i];
}

bool VectorDinamico::operator==(const VectorDinamico &vector) const{
    bool iguales=true;
    if(size==vector.size){
        for(int i=0;i<size && iguales;++i){
            if(ptr[i]!=vector.ptr[i]){
                iguales=false;
            }
        }
    }
    else{
        iguales=false;
    }
    return iguales;
}

bool VectorDinamico::operator!=(const VectorDinamico &vector) const{
    return !(*this==vector);
}

bool VectorDinamico::operator<(const VectorDinamico &vector) const{
    bool menor=false;
    bool iguales=true;

    for(int i=0;i<size && i<vector.size && iguales;++i){
        if(ptr[i]<vector.ptr[i]){
            menor=true;
            iguales=false;
        }
        else if(ptr[i]>vector.ptr[i]){
            iguales=false;
        }
    }

    if(iguales && size<vector.size){
        menor=true;
    }
    return menor;
}

bool VectorDinamico::operator>(const VectorDinamico &vector) const{
    bool mayor=false;
    bool iguales=true;

    for(int i=0;i<size && i<vector.size && iguales;++i){
        if(ptr[i]>vector.ptr[i]){
            mayor=true;
            iguales=false;
        }
        else if(ptr[i]<vector.ptr[i]){
            iguales=false;
        }
    }

    if(iguales && size>vector.size){
        mayor=true;
    }
    return mayor;
}

bool VectorDinamico::operator<=(const VectorDinamico &vector) const{
    return !(*this>vector);
}

bool VectorDinamico::operator>=(const VectorDinamico &vector) const{
    return !(*this<vector);
}

VectorDinamico VectorDinamico::operator+(int n) const{
    assert(n>0);
    VectorDinamico vector(size+n,0);

    for(int i=0;i<size;++i){ // copiar datos antiguos
        vector.ptr[i]=ptr[i];
    }
    return vector;
}

VectorDinamico VectorDinamico::operator-(int n) const{
    assert(n>0);
    int newsize=(size-n>=0?size-n:0);
    VectorDinamico vector(newsize);

    for(int i=0;i<newsize;++i){ // copiar datos antiguos
        vector.ptr[i]=ptr[i];
    }
    return vector;
}

VectorDinamico& VectorDinamico::operator+=(int n){
    assert(n>0);

    int *newptr=new int[size+n];
    for(int i=0;i<size;++i){ // copiar datos antiguos
        newptr[i]=ptr[i];
    }
    for(int i=size;i<size+n;++i){ // poner a 0 nuevos elementos
        newptr[i]=0;
    }
    size=size+n;
    libera();
    ptr=newptr;

    return *this;
}

VectorDinamico& VectorDinamico::operator-=(int n){
    assert(n>0);
    int newsize=(size-n>=0?size-n:0);

    int *newptr;
    if(newsize>0){
        newptr=new int[newsize];
    }
    else{
        newptr=0;
    }
    for(int i=0;i<newsize;++i){ // copiar datos antiguos
        newptr[i]=ptr[i];
    }
    size=newsize;
    libera();
    ptr=newptr;

    return *this;
}

ostream& operator<<(ostream &flujo,const VectorDinamico &vector){
    for(int i=0;i<vector.size;++i){
        flujo<<vector.ptr[i]<<" ";
    }
    return flujo;
}

istream& operator>>(istream &flujo,const VectorDinamico &vector){
    //Leer en la forma:  elemento0 elemento1 .... elementosize-1
    for(int i=0;i<vector.size;++i){
        flujo>>vector.ptr[i];
    }

    return flujo;
}

int main()
{
   VectorDinamico integers1( 4 );
   cout<<"integers1: "<<integers1<<endl;
   cout<<"Introduce nuevos elementos de integers1: ";
   cin>>integers1;
   cout<<"integers1: "<<integers1<<endl;
}

 
