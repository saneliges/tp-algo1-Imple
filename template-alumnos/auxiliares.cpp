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
