// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;
TEST(posConBanderitaPreviaYNoJugada, cambiarBanderitasTest){
    tablero t = {{true, false, false},
               {true, false, false},
               {false, false, false}};
    jugadas j = {make_pair(make_pair(1,1),1),
                 };
    pos p = make_pair(1,0);
    banderitas b = {make_pair(0,0), make_pair(1,0)};
    cambiarBanderita(t, j, p, b);
    banderitas b_esperada = {make_pair(0,0)};
    ASSERT_EQ(b, b_esperada);
}