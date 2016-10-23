//##Eliminar elementos repetidos##//

//Mala forma
for(i=0; i<util_v; i++)
	for(j=i+1; j<util_v; j++)
		if(v[i]==v[j])
			for(k=j+1; k<util_v; k++)
				v[k-1]=v[k];

//Forma correcta
i=0;
while(i<util_v)
	j=i+1;
	while(j<util_v)
		if(v[i]==v[j])
			for(k=j+1; k<util_v; k++)
				v[k-1]=v[k];
				util_v--;
		else
			j++;

//Forma perfecta
esc=0;
for(lec=0; lec<util_v; lec++){
	encontrado=false;
	for(i=0;i<esc && !encontrado; i++)
		encontrado=v[i]==v[lec];
	if(!encontrado)
		v[esc++]=v[lec];
}
util_v=esc;




//Ejercicio para Dar vuelta al vector
for(i=0, j=util_v-1; i<j; i++,j--){
	aux=v[i];
	v[i]=v[j];
	v[j]=aux;
}