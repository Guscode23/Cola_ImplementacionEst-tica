#ifndef COLA_EST_H_INCLUDED
#define COLA_EST_H_INCLUDED
#define TAMCOLA 120
#include <stdbool.h>
#include <stdio.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

//Defino estructuras y primitivas//

typedef struct{
  char cola [TAMCOLA];
  unsigned pri,
           ult,
           tamDisponible; //El tamaño disponible se va modificando a medida que voy encolando elementos//

}T_Cola;

//Primitivas//
void crearCola(T_Cola *p);
bool encolar(T_Cola *p,const void* elem,size_t tamElem);
bool desencolar(T_Cola *p,void* elem,size_t tamElem);
bool verTopedeCola(T_Cola *p,void* elem,size_t tamElem);
void copiarDatoenCola(T_Cola *p,const void* dato,size_t tamDato);
bool colaVacia(const T_Cola *p);
bool colaLlena(const T_Cola *p);
void copiarDatodeCola(T_Cola *p,void* dato,size_t tamDato);
void vaciarCola(T_Cola *p);










#endif // COLA_EST_H_INCLUDED
