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
    bool result = false;
    for(int i = 0; i<=j.size(); i=i+1){
        if(j[i].first==p){
            result = true;
            return(result);
        }
    }
    return(result);
}

bool tableroValido(tablero& t){
    bool result = (t.size()==t[0].size()) && (t.size() >= 3);
    return result;
}

tablero matrizAmpliada(tablero& t){
    tablero t_ampliada;
    for(int i = 0 ; i<t.size()+1; i++){
        for(int j = 0 ; j <=t[0].size()+1 ; j++){
            if(i==0 || j == 0 || i == t.size() || j == t[0].size()){
                t_ampliada[i][j] = false;
            }
            else{
                t_ampliada[i][j] = true;
            }
        }
    }
    return t_ampliada;
}

vector<pair<int,int>> casillerosParaGanar(tablero& t){
    vector<pair<int,int>> c_ganar = { };
    for(int fila = 0; fila<=t.size(); fila=fila+1){
        for(int col = 0; col <= t[0].size(); col=col+1){
            if(not(t[fila][col])){
                c_ganar.push_back(make_pair(fila,col));
            }
        }
    }
    return(c_ganar);
}

bool posEnBanderitas(pos p, banderitas& b){
    bool resultado = false;
    for(int i = 0; i<=b.size(); i=i+1){
        if (p == b[i]){
            resultado=true;
        }
    }
    return resultado;
}

void agregarPosAJugadas(tablero& t, banderitas& b, pos p, jugadas& j){
    bool pos_bande = posEnBanderitas(p, b);
    bool pos_jugada = posYaJugada(j, p);
    if( not pos_bande && not pos_jugada && not(t[p.first][p.second])) {
        j.push_back(make_pair(p,minasAdyacentes(t,p)));
    }
}