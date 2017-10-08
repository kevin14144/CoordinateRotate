#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "math.h"
void MainWindow::on_pushButton_clicked()
{
    double_t th = 90*DegToRad;//Coordinate rotate 90 degree

    Matrix rotate90Deg;
    float rotateMatrix[4][4]= {
        {1,0,0,0},
        {0,(float)cos(th),(float)-sin(th),0},
        {0,(float)sin(th),(float)cos(th),0},
        {0,0,0,1}
    };
    //float rotateMatrix[3][1]={{1},{1},{1}};
    rotate90Deg.SetMatrix(*rotateMatrix,4,4);

    Matrix currentPos;
    float Position[4][4]= {
        {1,0,0,0},
        {0,0,0,5},
        {0,0,0,3},
        {0,0,0,1}
    };
    //float Position[1][3]={{1,2,1}};
    currentPos.SetMatrix(*Position,4,4);

    Matrix rotateInv90Deg;
    th= -90*DegToRad;
    float rotateMatrix2[4][4]= {
        {1,0,0,0},
        {0,(float)cos(th),(float)-sin(th),0},
        {0,(float)sin(th),(float)cos(th),0},
        {0,0,0,1}
    };
    rotateInv90Deg.SetMatrix(*rotateMatrix2,4,4);

    Matrix* result;
    result = rotate90Deg * currentPos;

    Matrix* result2;
    result2 = rotateInv90Deg *(*result);

    Matrix* result3;
    result3 = rotate90Deg * rotateInv90Deg;

    int row = result->GetRowNum();
    int col = result->GetColNum();
    int j,tempX;
    QDebug debug = qDebug();//no newline when print it.
    debug << "Rotate 90";
    for(int i =0;i<row;i++)
    {
        tempX = i * col;
        debug.nospace()<<"[";
        for(j =0;j<col;j++)
        {
            debug.space()<<result->operator [](tempX+j);
            //qDebug("%f ",result.result[tempX+j]);
        }
        debug.nospace()<<"]\n";
    }

    debug << "Rotate -90\n";
    row = result2->GetRowNum();
    col = result2->GetColNum();
    for(int i =0;i<row;i++)
    {
        tempX = i * col;
        debug.nospace()<<"[";
        for(j =0;j<col;j++)
        {
            debug.space()<<result2->operator [](tempX+j);
            //qDebug("%f ",result.result[tempX+j]);
        }
        debug.nospace()<<"]\n";
    }

    debug << "Identity matrix\n";
    row = result3->GetRowNum();
    col = result3->GetColNum();
    for(int i =0;i<row;i++)
    {
        tempX = i * col;
        debug.nospace()<<"[";
        for(j =0;j<col;j++)
        {
            debug.space()<<result3->operator [](tempX+j);
            //qDebug("%f ",result.result[tempX+j]);
        }
        debug.nospace()<<"]\n";
    }

    debug << "Copy matrix\n";
    float* copyResult = result->GetMatrix();
    row = result->GetRowNum();
    col = result->GetColNum();
    for(int i =0;i<row;i++)
    {
        tempX = i * col;
        debug.nospace()<<"[";
        for(j =0;j<col;j++)
        {
            debug.space()<<copyResult[tempX+j];
        }
        debug.nospace()<<"]\n";
    }
    delete copyResult;

    debug << "Copy matrix\n";
    Matrix copy ;
    copy = *result;

    row = copy.GetRowNum();
    col = copy.GetColNum();
    for(int i =0;i<row;i++)
    {
        tempX = i * col;
        debug.nospace()<<"[";
        for(j =0;j<col;j++)
        {
            debug.space()<<copy[tempX+j];
        }
        debug.nospace()<<"]\n";
    }
}
