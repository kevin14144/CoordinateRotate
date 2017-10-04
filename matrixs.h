#ifndef MATRIXS_H
#define MATRIXS_H


#include <string>
#include <utility>

using namespace std;

class Matrixs
{
public:
    float Matrix[4][4];
    Matrixs();

    Matrixs&& operator *(Matrixs&& other) noexcept // move assignment
    {
        //this*other
        Matrixs a;
        if(this != &other) {
            int i , j, k;
            for(i=0;i<4;i++)//row
            {
                for(k=0;k<4;k++)//colum
                {
                    for(j=0;j<4;j++)//colum
                    {
                        a.Matrix[i][k]+= this->Matrix[i][j] * other.Matrix[j][k];

                    }
                }
            }
        }

        //reuse (r value)
        return std::move(a);
    }

    Matrixs&& operator +(Matrixs&& other)
    {
        Matrixs a;
        if(this != &other) {
            int i , j;
            for(i=0;i<4;i++)//row
            {
                for(j=0;j<4;j++)//colum
                {
                    a.Matrix[i][j] = this->Matrix[i][j] + other.Matrix[i][j];
                }
            }
        }
        return std::move(a);
    }

    Matrixs& operator +=(Matrixs& rhs)
    {
        return *this;
    }

};

#endif // MATRIXS_H
