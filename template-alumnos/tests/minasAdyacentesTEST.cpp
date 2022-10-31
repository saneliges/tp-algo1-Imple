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

