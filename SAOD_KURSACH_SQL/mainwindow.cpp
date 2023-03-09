#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Books books;
    books.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    readers read;
    read.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    Info_give inf;
    inf.exec();
}

