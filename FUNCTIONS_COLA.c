#include "COLA_EST.h"
#include <string.h>

void crearCola(T_Cola *p)
{
   //El primer elemento como el último son iguales//
    p->pri=0;
    p->ult=0;
    p->tamDisponible=TAMCOLA;

}

bool encolar(T_Cola *p,const void* elem,size_t tamElem)
{
    //Verifico que la cola no esté llena//

    if(tamElem+sizeof(size_t)> p->tamDisponible)
        return false;

    //¿Qué pasa si el dato está partido?//

    copiarDatoenCola(p,&tamElem,sizeof(size_t)); //Es una especie de memcpy->copio el tamaño del dato//
    //Modifico el fondo//
    p->ult=(p->ult+sizeof(size_t))%TAMCOLA;//Indico la posicion del último//
    copiarDatoenCola(p,elem,tamElem); //Ahora copio el elemento directamente//
    p->ult=(p->ult+sizeof(size_t))%TAMCOLA;
    p->tamDisponible-=tamElem+sizeof(size_t); //Se reduce el tamaño disponible//

    return true;
}

void copiarDatoenCola(T_Cola *p,const void* dato,size_t tamDato)
{
   size_t cantaCopiar=tamDato;
   size_t cantContigua=p->ult>=p->pri ? TAMCOLA -p->ult:p->pri-p->ult; //Analizo cómo está frente con respecto a fondo//

   memcpy(p->cola +p->ult,dato,cantContigua);
   cantaCopiar-=cantContigua;

   if(cantaCopiar>0)
   {
       memcpy(p->cola,dato+cantContigua,cantaCopiar);

   }
}

bool desencolar(T_Cola *p,void* elem,size_t tamElem)
{
    //Constituye la operación inversa//

    if(p->tamDisponible==TAMCOLA) //Verifico que la pila no se encuentre vacía//
        return false;

    size_t tamElemColado;

    copiarDatodeCola(p,&tamElemColado,sizeof(size_t)); //Copio el tamaño del dato//
    p->pri=(p->pri + sizeof(size_t))%TAMCOLA; //El dato puede que esté partido.Modifico obviamente el elemento que está primero, que va a ser el último en salir//
    copiarDatoenCola(p,elem,MIN(tamElem,tamElemColado));
    p->pri=(p->pri+tamElemColado)%TAMCOLA; //Copio el dato en sí//
    p->tamDisponible+=tamElemColado+sizeof(size_t); //Al tamaño disponible se le suma el elemento+tamaño del elemento desencolado//

    return true;
}

void copiarDatodeCola(T_Cola *p,void* dato,size_t tamDato)
{
   size_t cantaCopiar=tamDato;
   size_t cantContigua=p->pri>=p->ult ? MIN(TAMCOLA-p->pri,tamDato):tamDato;

   memcpy(dato,p->cola+p->pri,cantContigua);
   cantaCopiar-=cantContigua;

   if(cantaCopiar>0)
    memcpy(p->cola,dato+cantContigua,cantaCopiar);

}

bool verTopedeCola( T_Cola *p,void*elem,size_t tamElem)
{
    if(p->tamDisponible==TAMCOLA) //Verifico que la cola no esté vacía//
         return false;


    size_t tamElemEncolado;
    unsigned primero=p->pri;
    copiarDatodeCola(p,&tamElemEncolado,sizeof(size_t));
    ((T_Cola*)p)->pri=(p->pri + sizeof(size_t))% TAMCOLA;
    copiarDatodeCola(p,elem,MIN(tamElem,tamElemEncolado));
    ((T_Cola*)p)->pri=primero;

    return true;
}

bool colaVacia(const T_Cola *p)
{
     //Si el tamaño disponible es igual al tamaño de la cola, entonces se encuentra vacía//

     return p->tamDisponible==TAMCOLA;

}

bool colaLlena(const T_Cola *p)
{
   //Si el tamaño disponible de la cola es cero, entonces la cola está llena//

   return p->tamDisponible==0;

}

void vaciarCola(T_Cola *p)
{
    p->pri=0;
    p->ult=0;
    p->tamDisponible=TAMCOLA;

}










