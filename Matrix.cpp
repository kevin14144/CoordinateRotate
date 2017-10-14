#include "Matrix.h"
#include "qdebug.h"

Matrix::Matrix()
{

}

Matrix::~Matrix()
{
    if(value != nullptr)
    {
        delete value;
    }
}

Matrix::Matrix(int rowNum, int colNum)
{

    if(rowNum !=0 && colNum != 0)
    {
        if(value != nullptr)
        {
            delete value;
        }
        value = new float[rowNum * colNum];
        int col;
        for(int row = 0;row < rowNum; row++)
        {
            for(col = 0;col < colNum; col++)
            {
                value[row * rowNum + col] = 0;
            }
        }
        this->rowNum = rowNum;
        this->colNum = colNum;
    }
    else
    {
        throw;
    }
}

void Matrix::SetMatrix(int rowNum, int colNum)
{
    if(rowNum != 0 && colNum != 0)
    {
        if(value != nullptr)
        {
            delete value;
        }
        value = new float[rowNum * colNum];
        int col;
        for(int row = 0;row < rowNum; row++)
        {
            for(col = 0;col < colNum; col++)
            {
                value[row * colNum + col] = 0;
            }
        }
        this->rowNum = rowNum;
        this->colNum = colNum;
    }
}

void Matrix::SetMatrix(const float* src, int rowNum, int colNum)
{
        SetMatrix(rowNum,colNum);
        int col;
        if(src == nullptr)
        {
            throw "src nullptr";
        }

        for(int row = 0;row < rowNum; row++)
        {
            for(col = 0;col < colNum; col++)
            {
                value[row * colNum + col] = src[row * colNum + col];
            }
        }


}

float* Matrix::GetMatrix()
{
    float* dst = new float[rowNum * colNum];
    int col;
    for(int row = 0;row < rowNum; row++)
    {
        for(col = 0;col < colNum; col++)
        {
            dst[row*rowNum+col] = value[row*rowNum+col];
        }
    }
    return dst;
}

int Matrix::GetRowNum()
{
    return rowNum;
}

int Matrix::GetColNum()
{
    return colNum;
}


Matrix& Matrix::operator =(Matrix &src)
{
    this->SetMatrix(src.GetMatrix(),src.GetRowNum(),src.GetColNum());
    return *this;
}

Matrix& Matrix::operator +(Matrix &src)
{
    if(this->GetColNum() != src.GetColNum() ||
            this->GetRowNum() != src.GetRowNum())
    {
        throw;
    }
    if(this == &src)
    {
        throw;
    }

    return Add(*this, src);
}
Matrix& Matrix::operator +=(Matrix &src)
{
    return *this = *this + src;//Add(*this, src);
    //return this + src;
}

float& Matrix::operator [](int index)
{
    return value[index];
}

Matrix* Matrix::operator *(Matrix &src)
{

    //Return = this * src
    //Judge the matrix dim
    if(this->GetColNum() != src.GetRowNum())
    {
        throw;
    }
    if(this == &src)
    {
        throw;
    }

    int ResultRowNum,ResultColNum,relativeNum;

    ResultRowNum = this->GetRowNum();
    ResultColNum = src.GetColNum();
    relativeNum = this->GetColNum();

    Matrix* resultAns = new Matrix(ResultRowNum,ResultColNum);
    //Matrix resultAns(ResultRowNum,ResultColNum);
    int i , j, k, tempResultXIndex,tempResultElmentIndex,tempAMatrixIndex;

    for(i=0;i<ResultRowNum;i++)//row  3
    {
        tempResultXIndex = i*ResultColNum;

        for(k=0;k<ResultColNum;k++)//colum 3
        {
            tempResultElmentIndex = tempResultXIndex + k;
            tempAMatrixIndex = i * relativeNum;

            for(j=0;j<relativeNum;j++)//colum 2
            {
                resultAns->value[tempResultElmentIndex] +=
                        this->value[tempAMatrixIndex+j] *
                        src.value[j*ResultColNum+k];
            }
        }
    }

    return resultAns;
}


Matrix& Matrix::Add(Matrix& src,Matrix& src2)
{
    int ResultRowNum,ResultColNum;

    ResultRowNum = src.GetRowNum();
    ResultColNum = src.GetColNum();

    Matrix* dst = new Matrix(ResultRowNum,ResultColNum);

    //N-D Matrix is a kind of 1D vector
    int i , j ,tempXelement,tempElement;
    for(i=0;i<ResultRowNum;i++)//row
    {
        tempXelement = i * ResultColNum;//Change next row
        for(j=0;j<ResultColNum;j++)//colum
        {
            tempElement = tempXelement + j;//Change next column
            dst->value[tempElement] = src.value[tempElement]
                    + src2.value[tempElement];
        }
    }
    return *dst;
}
