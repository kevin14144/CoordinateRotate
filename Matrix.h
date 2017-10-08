#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <utility>

using namespace std;

class Matrix
{
public:

    Matrix();
    ~Matrix();
    Matrix(int rowNum, int colNum);
    void SetMatrix(const float *src, int rowNum, int colNum);
    float* GetMatrix();
    int GetRowNum();
    int GetColNum();
    void operator =(Matrix &src);
    Matrix *operator *(Matrix &src);

    Matrix *operator +(Matrix&& src);
    float &operator [](int index);


//    Matrix& operator +=(Matrix& rhs)
//    {
//        return *this;
//    }

private:

    float* value = nullptr;
    int rowNum;
    int colNum;
};

#endif // MATRIX_H
