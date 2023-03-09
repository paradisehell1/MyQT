#include "books.h"
#include "ui_books.h"
extern int columnBook;

Books::Books(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Books)
{
    ui->setupUi(this);
    db_book1= QSqlDatabase::addDatabase("QSQLITE");
    db_book1.setDatabaseName("./SAOD_KURSACH_SQL.db_book1");
    if(db_book1.open()){
        qDebug ("open");
    }
    else{
        qDebug ("faggot");
    }
    query=new QSqlQuery(db_book1);
    query->exec("CREATE TABLE BOOKS(ШИФР TEXT, АВТОР TEXT, НАЗВАНИЕ TEXT, ИЗДАТЕЛЬСТВО TEXT, ГОД ИЗДАНИЯ TEXT,  ВСЕГО TEXT, ОСТАЛОСЬ TEXT);");
    model= new QSqlTableModel(this, db_book1);
    model->setTable ("BOOKS");
    model->select();
    ui->tableView->setModel(model);
    mydelegate=new Delegate(this);
    ui->tableView->setItemDelegate(mydelegate);
    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);
 }



Books::~Books()
{
      db_book1.close();
    delete ui;
}



void Books::on_pushButton_clicked()
{
     model->insertRow(model->rowCount());
     qDebug()<<var.row_book;

}


void Books::on_tableView_clicked(const QModelIndex &index)
{
    var.row_book=index.row();
    columnBook=index.column();
    qDebug()<<columnBook;

}


void Books::on_pushButton_2_clicked()
{
    model->removeRow(var.row_book);
}






void Books::on_lineEdit_textChanged(const QString &arg1)
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




void Books::on_radioButton_clicked()
{
    search_by=0;
}


void Books::on_radioButton_2_clicked()
{
    search_by=1;
}


void Books::on_radioButton_3_clicked()
{
    search_by=2;
}


void Books::on_radioButton_4_clicked()
{
    search_by=3;
}


void Books::on_radioButton_5_clicked()
{
    search_by=4;
}

