//#include <iostream>
#define MAX 10

class VD{
	private:
		int reservados;
		int n;
		int *datos;
		void Ampliar();
		void Copiar(const VD &Vd);
		void Borrar();

	public:
		VD(int tam=MAX);
		VD(const VD &Vd){Copiar(Vd);}
		~VD(){Borrar();}
		VD &operator=(const VD &Vd);
		int size()const{
			return n;
		}
		int Get(int pos)const{
			return datos[pos];
		}
		void Set(int pos, int nuevo){
			datos[pos]=nuevo;
		}
		void Insertar(int pos, int nuevo);
		void Eliminar(int pos);
		int & operator[](int pos){
			return datos(pos);	//sobrecarga
		}
		const int & operator[](int pos)const{
			return datos(pos);
		}

		VD operator+(const VD &v)const;
		VD operator+(int a)const;

		friend VD operator+(int a, const VD &v);
		friend ostream & operator<<(ostream &os, const VD &v);
		friend istream & operator>>(istream &is, VD &v);

		bool operator==(const VD &v)const;
		bool operator!=(const VD &v)const{
			return !(*this==v);
		}
};

//IMPLEMENTACION METODOS

void VD::Copiar(const VD &Vd){
	reservados=Vd.reservados;	//this->reservados=Vd.reservados;
	n=Vd.n;
	datos=new int[reservados];
	for (int i = 0; i < n; ++i)
	{
		datos[i]=Vd.datos[i];
	}
}

void VD::Borrar(){
	if(datos!=0)
		delete[] datos;
}

/*NO necesaria ********************
VD::VD(){
	reservados=MAX;
	n=0;
	datos=new int [reservados];
}*//*******************************/

VD::VD(int tam){
	reservados=tam;
	n=0;
	datos=new int[reservados];
}

VD &VD::operator=(const VD &Vd){
	if(this!=&Vd){
		Borrar();
		Copiar(Vd);
	}
	return *this;
}

void VD::Ampliar(){
	reservados=reservados*2;
	int *aux=new int[reservados];
	for (int i = 0; i < n; ++i)
		aux[i]=datos[i];
	delete[]datos;
	datos=aux;
}

void VD::Insertar(int pos, int nuevo){
	if(n==reservados)	//No reservamos memoria
		Ampliar();
	for (int i = n; i > pos; i--)
		datos[i]=datos[i-1];
	datos[pos]=nuevo;
	n++;
}

void VD::Eliminar(int pos){
	for (int i = pos; i < n-1; i++){				
		datos[i]=datos[i+1];
	}
	n--;
}

VD VD::operator+(const VD &v)const{
	int mayor=(n>v.n)?n:v.n;
	VD vout(mayor);
	for (int i = 0; i < mayor; ++i){
		if(i<v.n & i<n)
			vout.datos[i]=datos[i]+v.datos[i];
		else
			if(i<v.n)
				vout.datos[i]=v.datos[i];
			else
				vout.datos[i]=datos[i];
	}
	return vout;
}

VD VD::operator+(int a)const{
	VD vout(*this);
	for (int i = 0; i < n; ++i)
		vout.datos[i]+=a;
	return vout;
}

VD operator+(int a, const VD &v){
	VD vout(v);	//
	for (int i = 0; i < v.n; ++i)
		vout.datos[i]+=a;
	return vout;
}//PUEDE RESUMIRSE EN: return v+a;

ostream & operator<<(ostream &os, const VD &v){
	os<<v.n<<endl;
	for (int i = 0; i < v.n; ++i)
		os << v.datos[i]<< ' ';
	return os;
}

istream & operator>>(istream &is, VD &v){
	int nele;
	is >> nele;
	VD vl(nele);
	for (int i = 0; i < nele; i++){
		int a;
		is>>a;
		vl.Insertar(i,a);
	}
	return is;
}

bool VD::operator==(const VD &v)const{
	if(this->n != v.n)
		return false;
	for (int i = 0; i < this->n; ++i)
		if(datos[i]!=datos[i])
			return false;
	return true;
}
