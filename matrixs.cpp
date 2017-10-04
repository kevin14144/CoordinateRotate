#include "matrixs.h"

Matrixs::Matrixs()
{
    //initial matrix
    float initial[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    memcpy(Matrix, initial, sizeof(initial));
}

