
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"
bool posYaJugada(jugadas& j, pos p);
bool tableroValido(tablero& t);
tablero matrizAmpliada(tablero& t);
vector<pair<int,int>> casillerosParaGanar(tablero& t);
bool posEnBanderitas(pos p, banderitas& b);
void agregarPosAJugadas(tablero& t, banderitas& b, pos p, jugadas& j);
