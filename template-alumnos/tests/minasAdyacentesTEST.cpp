// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

TEST(minasAdyacentesTEST, ochoBombas) {
    tablero t = {{true, true, true},
                 {true, false, true},
                 {true, true , true}};
    pos p = make_pair(1,1);
    int result = minasAdyacentes(t,p);
    cout<< result;
    ASSERT_EQ(8, result);
}

TEST(minasAdyacentesTEST, bordeSuperiorIzquierdo) {
    tablero t = {{false, true, true},
                 {true, false, true},
                 {true, true , true}};
    pos p = make_pair(0,0);
    int result = minasAdyacentes(t,p);
    cout<< result;
    ASSERT_EQ(2, result);
}

TEST(minasAdyacentesTEST, bordeInferiorDerecho) {
    tablero t = {{true, true, true},
                 {true, false, true},
                 {true, true , false}};
    pos p = make_pair(2,2);
    int result = minasAdyacentes(t,p);
    cout<< result;
    ASSERT_EQ(2, result);
}

TEST(minasAdyacentesTEST, sobreMina) {
    tablero t = {{true, true, true},
                 {true, true, true},
                 {true, true , true}};
    pos p = make_pair(1,1);
    int result = minasAdyacentes(t,p);
    cout<< result;
    ASSERT_EQ(8, result);
}

TEST(minasAdyacentesTEST, tableroInvalido) {
    tablero t = {{true, true, true, true},
                 {true, false, true},
                 {true, true }};
    pos p = make_pair(1,1);
    int result = minasAdyacentes(t,p);
    cout<< result;
    ASSERT_EQ(-1, result);
}
