#include "user_first_window.h"
#include "ui_user_first_window.h"
QString str;
User_first_window::User_first_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_first_window)
{

    ui->setupUi(this);
        show_hello();
    }



User_first_window::~User_first_window()
{
    delete ui;
}

void User_first_window::show_hello()
{
    QStringList lst_check=str.split("|");
    ku2=str.split("|");
    ui->label->setText("Приветствуем - " + lst_check.at(3));


}

void User_first_window::on_pushButton_clicked()
{
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

    bool ok;
    QString phone_number = QInputDialog::getText(this,
                                 QString::fromUtf8("Кому перевести?"),
                                 QString::fromUtf8("Введите номер:"),
                                 QLineEdit::Normal,
                                 QDir::home().dirName(), &ok);
    qDebug("ku");
     QStringList lst;

     QStringList lst_check;

        lst = main_str.split("\n");

        QString str1;
        int j=0;
    bool ku=false;
    QString str123;
    for(int i=0;i<lst.size();i++){
        str123=lst.at(i);
        lst_check=str123.split("|");
        if (lst_check.at(4)==phone_number){
            j=i;
            ku=true;
            break;
        }

    }
    QString name;
    if(ku==false){
        return;
    }
    name=lst.at(j);
    QStringList lste;
    lste=name.split("|");
    QString name1;
    name1="перевод - "+lste.at(3);
    QString money = QInputDialog::getText(this,
                                 name1,
                                 QString::fromUtf8("Введите сумму:"),
                                 QLineEdit::Normal,
                                 QDir::home().dirName(), &ok);
    QString money_have;

    QString newStr1;
    QString money2;
    QString money3;
    QString money4;
    QStringList money_have1;
    newStr=str+"\n"+str123;// вся строка


    money4=ku2.at(5);

    money_have1=str123.split("|");
        money_have=money_have1.at(5);

    money2=QString::number(money_have.toInt()+money.toInt());//кому

    money3=QString::number(ku2.at(5).toInt()-money.toInt());// от кого
    if (money3.toInt()<0){
        qDebug()<<"net deneg";
        return;

    }


    newStr.replace(money_have, money2);// кому

    newStr.replace(money4, money3);// от кого
    qDebug()<<newStr;

   file.seek(0); // go to the beginning of the file
  file.write(newStr.toUtf8());
  qDebug()<<money2;
  main_str="";
}


void User_first_window::on_pushButton_2_clicked()
{
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
    bool ok;
    QString money = QInputDialog::getText(this,
                                  QString::fromUtf8("Пополнение:"),
                                 QString::fromUtf8("Введите сумму:"),
                                 QLineEdit::Normal,
                                 QDir::home().dirName(),&ok);

  QStringList lst_check=str.split("|");
  ku2=str.split("|");
 QString money2=QString::number(ku2.at(5).toInt()+money.toInt());
 main_str.replace(ku2.at(5), money2);

file.seek(0); // go to the beginning of the file
file.write(main_str.toUtf8());
file.close();
main_str="";

}



void User_first_window::on_comboBox_activated(int index)
{
    if(index==1){
        change_log();
    }
    if(index==2){
        change_pass();
    }
}

void User_first_window::change_pass()
{
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

        ku2=str.split("|");
        bool ok;
        QString pass = QInputDialog::getText(this,
                                      QString::fromUtf8("Изменение пароля"),
                                     QString::fromUtf8("Введите новый пароль:"),
                                     QLineEdit::Password,
                                     QDir::home().dirName(),&ok);
       main_str.replace(ku2.at(1), pass);
       file.seek(0); // go to the beginning of the file
       file.write(main_str.toUtf8());
       file.close();

       main_str="";

}

void User_first_window::change_log()
{
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

        ku2=str.split("|");
        bool ok;
        QString log = QInputDialog::getText(this,
                                      QString::fromUtf8("Изменение пароля"),
                                     QString::fromUtf8("Введите новый пароль:"),
                                     QLineEdit::Normal,
                                     QDir::home().dirName(),&ok);
       main_str.replace(ku2.at(0), log);
       file.seek(0); // go to the beginning of the file
       file.write(main_str.toUtf8());
       file.close();
       main_str="";
}


void User_first_window::on_pushButton_3_clicked()
{
    close();
}

