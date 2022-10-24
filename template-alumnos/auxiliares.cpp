//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool posYaJugada(jugadas& j, pos p){
    for(int i = 0; i<=j.size(); i=i+1){
        if(j[i][0]==p){
            return(true);
        }
    }
}

vector<pair<int,int>> casillerosParaGanar(tablero& t){
    vector<pair<int,int>> c_ganar = { };
    for(int fila = 0; fila<=t.size(); fila=fila+1){
        for(int col = 0; col <= t[0].size(); col=col+1){
            if(not(t[fila][col])){
                c_ganar.push_back(make_pair(t[fila],t[col]));
            }
        }
    }
    return(c_ganar)
}

bool posEnBanderitas(pos p, banderitas& b){
    bool resultado = false;
    for(int i = 0; i<=b.size(), i=i+1){
        if (p == banderitas[i]){
            resultado=true;
        }
    }
    return resultado;
}

void agregarPosAJugadas(tablero& t, banderitas& b, pos p, jugadas& j){
    if(not(tablero[pos[0]][pos[1]]) & not(posEnBanderitas) & not(posYaJugada())){
        jugadas.push_back(make_pair(p,minasAdyacentes(t,p)));
    }
}