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


void MainWindow::on_pushButton_clicked()
{
    double_t th =90*3.14/180;//Coordinate rotate 90 degree

    Matrixs a;
    float rotateMatrix[4][4]= {{1,0,0,0},{0,(float)cos(th),(float)-sin(th),0},{0,(float)sin(th),(float)cos(th),0},{0,0,0,1}};
    memcpy(a.Matrix, rotateMatrix, sizeof(rotateMatrix));

    Matrixs b;
    float Position[4][4]= {{1,0,0,0},{0,0,0,5},{0,0,0,3},{0,0,0,1}};
    memcpy(b.Matrix, Position, sizeof(Position));

    //Get new postion
    Matrixs NewPosition;
    NewPosition= a * std::move(b);
}
