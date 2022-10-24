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
 /*** Para que funciónen la estructura for(for(...)) tiene que darse que la matriz sea como minimo de 3x3
  * o seguro que salta error. deberiamos agregar un if(tablero de 3x3) antes?***/
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
 metemos una banderita* ya que sabemos que si salio del ciclo espor que no esta en banderitas.*************/

    if(not(posYaJugada(j, p))){
        b.push_back(pos);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool resultado = false
    for(int i = 0; i <= j.size(); i=i+1){
        resultado = t[j[i][0]] /***recorremos todas las posiciones jugadas y evaluamos el tablero en las mismas
                                    * si almenos una es True, significa que se jugo una posicion con bomba y por lo tanto perdiste***/
    }
    return resultado
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    vector<pair<int,int>> c_ganar = casillerosParaGanar(t);
    bool resultado;
    if(not(perdio(t,j))){
        bool resultado = true;
        for (int i = 0; i <= c_ganar.size(); i = i + 1) {
            if (not(count(j.begin(), j.end(), c_ganar[i]))) {
                resultado = false;
            }
        }
    }
    else{
        resultado = false;
    }
    return resultado
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    agregarPosAJugadas(t, b, p, j);
    if(j[j.size()-1]==0){
        vector<pos> p_ady = {make_pair(p[0], p[1]+1),
                             make_pair(p[0], p[1]-1),
                             make_pair(p[0]+1, p[1]+1),
                             make_pair(p[0]+1, p[1]-1),
                             make_pair(p[0]+1, p[1]),
                             make_pair(p[0]-1, p[1]+1),
                             make_pair(p[0]-1, p[1]),
                             make_pair(p[0]-1, p[1]-1)}
        for(int i = 0, i<=p_ady.size(), i++){
            jugarPlus(t, b, p_ady[i], j) }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
