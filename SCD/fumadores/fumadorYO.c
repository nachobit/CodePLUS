sem_t fumador1,fumador2,fumador3,estanquero
 
struct nfumador {ingrediente};
 
init(fumador1,0)
init(fumador2,0)
init(fumador3,0)
init(estanquero,1)
 
-------------------
Liar_cigarro
-------------------
 
    imprimir(el fumador <fumador> esta liando un cigarro)
 
      sleep(5);
 
------------------
Estanco
------------------
 
 
    int objeto1,objeto2;
       
    objeto1=rand()%3;
    objeto2=rand()%3;
 
    while(objeto1==objeto2){
        objeto1=rand()%3;
        objeto2=rand()%3;
    }
 
        if(objeto==1 && objeto2==2){
                imprimir(Papel y Cerillas)
            signal(fumador1);
        }
 
        if(objeto==0 && objeto2==2){
                imprimir(Tabaco y Cerillas)
            signal(fumador2);
        }
 
        if(objeto==0 && objeto2==1){
                imprimir(Tabaco y Papel)
            signal(fumador3);
        }
   
 
        if (objeto+objeto2 == 3) imprimir (Termina de fumar el fumador 1)
        if (objeto+objeto2 == 2) imprimir (Termina de fumar el fumador 2)
        if (objeto+objeto2 == 1) imprimir (Termina de fumar el fumador 3)
 
 
 
------------------
Fumar
------------------
 
    if(nfumador==0)
        imprimir(Recoge papel y cerillas el fumador 1)
        signal(fumador1)
    if(nfumador==1)
        imprimir(Recoge tabaco y cerillas el fumador 2)
        signal(fumador2)
    if(nfumador==2)
        imprimir(Recoge tabaco y papel el fumador 3)
        signal(fumador3)
 
    wait(estanquero);
 
    signal(estanquero);
 
    liar_cigarro(nfumador);
 
 
    if(nfumador==0)
        imprimir(Fumando el fumador 1)
        signal(fumador1)
    if(nfumador==1)
        imprimir(Fumando el fumador 2)
        signal(fumador2)
    if(nfumador==2)
        imprimir(Fumando el fumador 3)
        signal(fumador3)
 
    sleep(10);
 
    imprimir(Termina de fumar el fumador <objeto+1>);
    