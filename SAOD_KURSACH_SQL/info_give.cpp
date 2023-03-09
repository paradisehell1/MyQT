#include "info_give.h"
#include "ui_info_give.h"
#include "books.h"
#include "readers.h"
#include "given.h"


Info_give::Info_give(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info_give)
{
    ui->setupUi(this);
    db_info= QSqlDatabase::addDatabase("QSQLITE");
    db_info.setDatabaseName("./SAOD_KURSACH_SQL.db_info");
    db_info.open();
    query=new QSqlQuery(db_info);
    query->exec("CREATE TABLE INFO(ШИФР TEXT, БИЛЕТ TEXT);");
    model= new QSqlTableModel(this, db_info);
    model->setTable ("INFO");

  ui->tableView->setModel(model);
}

Info_give::~Info_give()
{
    delete ui;
}

void Info_give::on_pushButton_clicked()
{

give.exec();
enc=give.enc;
enc1=give.enc1;



insert_to_table();


}

void Info_give::insert_to_table()
{


    if ((enc=="") and (enc1=="")){

    }

    row=model->insertRow(model->rowCount());
    qDebug()<<row;

    model->setData(model->index(row, 0), QVariant::fromValue<QString>(enc), Qt::EditRole);
        model->setData(model->index(row, 1), QVariant::fromValue<QString>(enc1), Qt::EditRole);

    ui->tableView->setModel(model);

}


void Info_give::on_tableView_clicked(const QModelIndex &index)
{

   del_row=index.row();

}



void Info_give::on_pushButton_2_clicked()
{
    model->removeRow(del_row);
}

