#include "worker_window.h"
#include "ui_worker_window.h"

Worker_window::Worker_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Worker_window)
{
    ui->setupUi(this);

    QStringList lst_check;
    QFile file("D:/QTProjects/kursach_OOP/Data_base.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text |QIODevice::WriteOnly))
       {
           while(!file.atEnd())
           {
               //читаем строку
             main_str1 =main_str1+ file.readLine();

           }
       }
       else
       {
           qDebug()<< "don't open file";
       }
       lst = main_str1.split("\n");

       file.close();
       QString strr;

       for(int i=0;i<lst.size();i++){

           strr=lst.at(i);

           to_table(strr);


       }
       mask_data();

}

Worker_window::~Worker_window()
{
    delete ui;
}

void Worker_window::to_table(QString s)
{
    QStringList lstCheck;
    lstCheck=s.split("|");
    if(ui->tableWidget->rowCount() < row + 1)
        ui->tableWidget->setRowCount(row + 1);
        if(ui->tableWidget->columnCount() < lstCheck.size())
        ui->tableWidget->setColumnCount( lstCheck.size() );

        for( int column = 0; column < lstCheck.size(); column++)
        {
        QTableWidgetItem *newItem = new QTableWidgetItem( lstCheck.at(column) );
        ui->tableWidget->setItem(row, column, newItem);
        }

        row++;


}


void Worker_window::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    row++;
}


void Worker_window::on_pushButton_2_clicked()
{
     ui->tableWidget->removeRow(row123);
}


void Worker_window::on_tableWidget_cellClicked(int row, int column)
{
    row123=row;
    column123=column;
}

void Worker_window::mask_data()
{

//        QString check;
//        check= passwordItem->data(Qt::admin)
//        qDebug()<<check;
}





void Worker_window::on_pushButton_3_clicked()
{
    QFile file("D:/QTProjects/kursach_OOP/Data_base.txt");
       if(file.open(QIODevice::ReadOnly |QIODevice::Text |QIODevice::WriteOnly))
       {
           while(!file.atEnd())
           {
               //читаем строку
             main_str1 =main_str1+ file.readLine();

           }
       }
       else
       {
           qDebug()<< "don't open file";
       }

        QString check="";
       for(int i=0;i<row;i++){

           if(i!=0){
               check.resize(check.size()-1);
               check=check+"\n";
           }
           for (int j=0;j<6;j++){
   QTableWidgetItem *item = ui->tableWidget->item(i,j);
//       if(j==0){
//           check=check+ passwordItem->data(Qt::UserRole).toString()+"|";
//           qDebug("1");
//           qDebug()<<check;
//           continue;
//       }
//       if(j==1){
//           check=check+ passwordItem1->data(Qt::UserRole).toString()+"|";
//           qDebug("2");
//           qDebug()<<check;
//           continue;

//       }
    if (NULL != item) {
        check =check+ item->text()+"|";

           }
       }
}
       qDebug("3");
       check.resize(check.size()-1);
       qDebug()<<check;
       file.seek(0); // go to the beginning of the file
       file.write(check.toUtf8());
       file.close();
    close();

}

