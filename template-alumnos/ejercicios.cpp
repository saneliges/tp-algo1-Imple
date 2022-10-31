//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>
#include <algorithm>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {
    int contador = 0;
    tablero t_aux = matrizAmpliada(t);
    if(tableroValido(t)){
        for (int fila = -1; fila <= 1; fila++) {
            for (int col = -1; col <= 1; col++) {
                if ( ((fila != 0) || (col != 0 )) && t[p.first + fila][(p.second + col)]) {
                    contador = contador + 1;
                }
            }
        }
    }
    else{
        cout<< "El tablero no es valido"<< endl;
    }
    return contador;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    for(int i = 0; i<=b.size(); i=i+1){
/********* en el ciclo recorremos el vector banderitas y nos fijamos si la posición ya tenia una
 banderita, si esto pasa SALIMOS DEL CICLO y sacamos la banderita en la posición marcada.*************/
        if(b[i] == p){
            b.erase(b.begin()+i);
            i=b.size()+1;
        }
    }
/********* cuando salimos del ciclo nos fijamos si la posición no se jugo y si la posicion no esta jugada
 metemos una banderita* ya que sabemos que si salio del ciclo espor que no esta en banderitas.*************/
    bool pos_jugada = posYaJugada(j, p);
    if(not(pos_jugada)){
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool resultado = false;
    for(int i = 0; i <= j.size(); i=i+1){
        resultado = t[(j[i].first).first][(j[i].first).second]; /***recorremos todas las posiciones jugadas y evaluamos el tablero en las mismas
                                    * si almenos una es True, significa que se jugo una posicion con bomba y por lo tanto perdiste***/
    }
    return resultado;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    vector<pair<int,int>> c_ganar = casillerosParaGanar(t);
    int cont_casParaGanarEnJugadas = 0;
    bool resultado = cont_casParaGanarEnJugadas == c_ganar.size();

    for(int i = 0; i < c_ganar.size(); i++ ) {
        for(int k = 0; k < j.size(); k++ ){
            if( j[k].first == c_ganar[i]){
                    cont_casParaGanarEnJugadas = cont_casParaGanarEnJugadas + 1;

            }
        }
    }
    return resultado;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    agregarPosAJugadas(t, b, p, j);
    if(j[j.size()-1].second==0){
        vector<pos> p_ady = {make_pair(p.first, p.second+1),
                             make_pair(p.first, p.second-1),
                             make_pair(p.first+1, p.second+1),
                             make_pair(p.first+1, p.second-1),
                             make_pair(p.first+1, p.second),
                             make_pair(p.first-1, p.second+1),
                             make_pair(p.first-1, p.second),
                             make_pair(p.first-1, p.second-1)}
        ;
        for(int i = 0; i<=p_ady.size(); i++){
            jugarPlus(t, b, p_ady[i], j);
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
/***
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
***/