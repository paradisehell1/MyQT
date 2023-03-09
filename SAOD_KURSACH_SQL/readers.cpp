
#include "readers.h"
#include "ui_readers.h"
extern int columnReaders;

readers::readers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readers)
{

    ui->setupUi(this);
    db_readers= QSqlDatabase::addDatabase("QSQLITE");
    db_readers.setDatabaseName("./SAOD_KURSACH_SQL.db_readers");
    if(db_readers.open()){
        qDebug ("open");
    }
    else{
        qDebug ("faggot");
    }
    query=new QSqlQuery(db_readers);
    query->exec("CREATE TABLE readers(БИЛЕТ TEXT, ФИО TEXT, ГОД TEXT, АДРЕС TEXT, МЕСТО РАБОТЫ ИЗДАНИЯ TEXT);");
    model= new QSqlTableModel(this, db_readers);
    model->setTable ("readers");
    model->select();
    ui->tableView->setModel(model);
    mydelegate=new Delegat_readers(this);
    ui->tableView->setItemDelegate(mydelegate);
    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);
 }



readers::~readers()
{
    delete ui;
}



void readers::on_pushButton_clicked()
{
     model->insertRow(model->rowCount());
     qDebug()<<var.row_readers;

}


void readers::on_tableView_clicked(const QModelIndex &index)
{
    var.row_readers=index.row();
    columnReaders=index.column();
    qDebug()<<columnReaders;

}


void readers::on_pushButton_2_clicked()
{
    model->removeRow(var.row_readers);
}






void readers::on_lineEdit_textChanged(const QString &arg1)
{
    int columFind; // По какой колонке будем искать
      ui->tableView->setModel(proxyModel);
      proxyModel->setFilterKeyColumn(search_by);

            QString ku;
      //Устанавливаем регулярное выражения для фильтра
      QRegularExpression syntax;
      syntax.setPattern(ui->lineEdit->text());

      QString list = syntax.pattern();

         proxyModel->setFilterFixedString(list);
}




void readers::on_radioButton_clicked()
{
    search_by=0;
}


void readers::on_radioButton_2_clicked()
{
    search_by=1;
}


void readers::on_radioButton_3_clicked()
{
    search_by=2;
}


void readers::on_radioButton_4_clicked()
{
    search_by=3;
}


void readers::on_radioButton_5_clicked()
{
    search_by=4;
}

