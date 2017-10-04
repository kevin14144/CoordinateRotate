#include "matrixs.h"

Matrixs::Matrixs()
{
    float aarray[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    memcpy(Matrix, aarray, sizeof(aarray));

}

