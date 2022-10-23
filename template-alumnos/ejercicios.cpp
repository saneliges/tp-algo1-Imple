//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {
    int contador = 0;
    for(int fila = -1; fila<=1; fila = fila+1){
        for(int col = -1; col <=1; col = col + 1){
            if(fila!=0 | col != 0 & tablero[pos[0]+fila][pos[1]+columna]){
                contador = contador + 1;
            }
        }
    }
    return contador
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    for(int i = 0; i<=b.size(); i=i+1){
/********* en el ciclo recorremos el vector banderitas y nos fijamos si la posición ya tenia una
 banderita, si esto pasa SALIMOS DEL CICLO y sacalos la banderita en la posición marcada.*************/
        if(b[i] == p){
            erase(b,b[i]);
            i=b.size()+1;
        }
    }
/********* cuando salimos del ciclo nos fijamos si la posición no se jugo y si la posicion no esta jugada
 * ya que sabemos que si salio del ciclo espor que no esta en banderitas.*************/

    if(not(posYaJugada(j, p))){
        b.insert(b.end(), pos);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
