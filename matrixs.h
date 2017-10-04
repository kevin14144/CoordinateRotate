#ifndef MATRIXS_H
#define MATRIXS_H

#include "qdebug.h"

class Matrixs
{
public:
    Matrixs();



    Matrixs& operator* (Matrixs&& other) noexcept // move assignment
    {
        //this*other
        Matrixs* a = new Matrixs;

        if(this != &other) {

            for(int i=0;i<4;i++)//row
            {
                for(int k=0;k<4;k++)//colum
                {
                    for(int j=0;j<4;j++)//colum
                    {
                        a->Matrix[i][k]+= this->Matrix[i][j] * other.Matrix[j][k];

                    }
                }
            }
        }
        return *a;
    }

    float Matrix[4][4];

};

#endif // MATRIXS_H
