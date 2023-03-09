#include "mainwindow.h"
#include "ui_mainwindow.h"
    extern QString str;

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


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    name=ui->lineEdit->text();
}



void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    password=ui->lineEdit_2->text();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

}


void MainWindow::on_pushButton_clicked()
{
    bool check_name=false;
    bool check_pass=false;

    if(window){
        Worker_window work;
        QString main_str="";
        QStringList lst_check;
       QFile file1("D:/QTProjects/kursach_OOP/Data_base_worker.txt");
           if(file1.open(QIODevice::ReadOnly |QIODevice::Text |QIODevice::WriteOnly))
           {
               while(!file1.atEnd())
               {
                   //читаем строку
                 main_str =main_str+ file1.readLine();

               }
           }
           else
           {
               qDebug()<< "don't open file";
           }
           file1.close();

           lst = main_str.split("\n");

           QString str1;

       for(int i=0;i<lst.size();i++){
           str=lst.at(i);
           lst_check=str.split("|");

                   if(lst_check.at(0)==name)
                   check_name=true;
                   if(lst_check.at(1)==password)
                       check_pass=true;
                   if(check_name&&check_pass){

                       break;
                   }

       }
       if(check_name&&check_pass){


           close();
           work.exec();


    }
    }

       else{
     QString main_str="";
     QStringList lst_check;
    QFile file("D:/QTProjects/kursach_OOP/Data_base.txt");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text |QIODevice::WriteOnly))
        {
            while(!file.atEnd())
            {
                //читаем строку
              main_str =main_str+ file.readLine();

            }
        }
        else
        {
            qDebug()<< "don't open file";
        }
        lst = main_str.split("\n");

        QString str1;

    for(int i=0;i<lst.size();i++){
        str=lst.at(i);
        lst_check=str.split("|");
                if(lst_check.at(0)==name)
                check_name=true;
                if(lst_check.at(1)==password)
                    check_pass=true;
                if(check_name&&check_pass){
                    str1=lst.at(i);
                    str1.replace(QString("f0"), QString("f1"));
                    main_str.replace(str,str1);

                    file.seek(0); // go to the beginning of the file
                    file.write(main_str.toUtf8()); // write the new text back to the file
                    file.close();
                    break;
                }

    }
    if(check_name&&check_pass){
         User_first_window Us;
        close();
        Us.exec();

        //str1.replace(QString("f1"), QString("f0"));
        //main_str.replace(str,str1);
        //qDebug()<<main_str;
        //file.seek(0); // go to the beginning of the file
        //file.write(main_str.toUtf8()); // write the new text back to the file
        //file.close();
    }
    }

}


void MainWindow::on_pushButton_2_clicked()

{
    window=true;

    ui->label_3->setText("Вход как работник");
    ui->pushButton_2->deleteLater();


}
