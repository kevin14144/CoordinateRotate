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


#include <math.h>
void MainWindow::on_pushButton_clicked()
{
    double_t th =90*3.14/180;
    Matrixs a;
    float aarray[4][4]= {{1,0,0,0},{0,(float)cos(th),(float)-sin(th),0},{0,(float)sin(th),(float)cos(th),0},{0,0,0,1}};
    memcpy(a.Matrix, aarray, sizeof(aarray));
    Matrixs b;
    float barray[4][4]= {{1,0,0,0},{0,0,0,5},{0,0,0,3},{0,0,0,1}};
    memcpy(b.Matrix, barray, sizeof(barray));


    Matrixs c;
    c= a*std::move(b);
}
