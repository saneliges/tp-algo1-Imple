// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;
vector<vector<int>> mat = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
};

vector<int> pos = {3,2};

cout << minasAdyacentes(mat, pos) << endl;
