#ifndef BOOKS_H
#define BOOKS_H

#include <QDialog>
#include "variables.h"
#include "delegate.h"
namespace Ui {
class Books;
}

class Books : public QDialog
{

    Q_OBJECT

public:
    explicit Books(QWidget *parent = nullptr);
    ~Books();
     Variables var;
     int get_column(){
        qDebug()<<var.column_book;
        int c=var.column_book;
        return c;
     }
     int search_by;
     QSqlDatabase get_db_book(){

         return db_book1;
     }
private slots:
     void on_pushButton_clicked();

        void on_tableView_clicked(const QModelIndex &index);

        void on_pushButton_2_clicked();





        void on_lineEdit_textChanged(const QString &arg1);

        void on_radioButton_clicked();

        void on_radioButton_2_clicked();

        void on_radioButton_3_clicked();

        void on_radioButton_4_clicked();

        void on_radioButton_5_clicked();

private:
        QSqlDatabase     db_book1;
    Ui::Books *ui;
     Delegate *mydelegate;

       QSqlQuery   *query;
       QSqlTableModel *model;


       QSortFilterProxyModel *proxyModel;
};

#endif // BOOKS_H
