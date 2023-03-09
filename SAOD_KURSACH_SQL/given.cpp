#include "given.h"
#include "ui_given.h"
#include "variables.h"
#include "readers.h"
#include "books.h"
#include <QMessageBox>

Given::Given(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Given)
{
    ui->setupUi(this);
    readers read;

     QSqlDatabase     db_readers1=read.get_db_readers();


    QSqlQuery qry(db_readers1);
    bool ok1=false;
    qry.prepare("SELECT * FROM readers"); // готовим запрос
    qry.exec();

    while(qry.next()) {
        if (enc1==(qry.value(0).toString())){
                ok1=true;
    }
       qDebug()<<(qry.value(0).toString());

    }

    db_readers1.close();

//    if(ok1==false)
//        return;
    Books book;
   QSqlDatabase  db_book1=book.get_db_book();
QString s;




QSqlQuery query1(db_book1);

bool ok=false;
query1.prepare("SELECT * FROM BOOKS"); // готовим запрос
query1.exec();
  ui->label->setText(query1.value(0).toString());
while(query1.next()) {
    if (enc==(query1.value(0).toString())){
            ok=true;
}
   qDebug()<<(query1.value(0).toString());

}

db_book1.close();
}

Given::~Given()
{
    delete ui;
}


void Given::on_pushButton_clicked()
{
    if(ok==false || ok1==false){
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка","Такого нет!");
        messageBox.setFixedSize(500,200);
        enc="";
        enc1="";
       }

close();
}


void Given::on_lineEdit_textChanged(const QString &arg1)

{
       ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]{3})[\\.]([\\d]{3}))")));
    enc=arg1;
}


void Given::on_lineEdit_2_textChanged(const QString &arg1)
{

     ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("(([А,Ч,В]{1}+[\\d]{4})[\\-]([\\d]{2}))")));

    enc1=arg1;
}

