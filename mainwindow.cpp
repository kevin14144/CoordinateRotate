#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

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


void MainWindow::on_pushButton_clicked()
{
    double_t th =90*3.14/180;//Coordinate rotate 90 degree

    Matrix a;
    float rotateMatrix[4][4]= {{1,0,0,0},{0,(float)cos(th),(float)-sin(th),0},{0,(float)sin(th),(float)cos(th),0},{0,0,0,1}};
    //float rotateMatrix[3][1]={{1},{1},{1}};
    a.SetMatrix(*rotateMatrix,4,4);

    Matrix b(1,2);//initial dim
    float Position[4][4]= {{1,0,0,0},{0,0,0,5},{0,0,0,3},{0,0,0,1}};
    //float Position[1][3]={{1,2,1}};
    b.SetMatrix(*Position,4,4);


    Matrix* result;
    result = a * std::move(b);
    int row = result->GetRowNum();
    int col = result->GetColNum();
    int j,tempX;
    QDebug debug = qDebug();//no newline when print it.

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

//    float* copyResult = result.GetMatrix();
//    for(int i =0;i<row;i++)
//    {
//        tempX = i * col;
//        debug.nospace()<<"[";
//        for(j =0;j<col;j++)
//        {
//            debug.space()<<copyResult[tempX+j];
//        }
//        debug.nospace()<<"]\n";
//    }
//    delete copyResult;

}
