#ifndef READERS_H
#define READERS_H

#include <QDialog>
#include "variables.h"
#include "delegat_readers.h"
namespace Ui {
class readers;
}

class readers : public QDialog
{

    Q_OBJECT

public:
    explicit readers(QWidget *parent = nullptr);
    ~readers();
     Variables var;
     int get_column(){
        qDebug()<<var.column_book;
        int c=var.column_book;
        return c;
     }
     int search_by;
     QSqlDatabase get_db_readers(){

         return db_readers;
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
    Ui::readers *ui;
     Delegat_readers *mydelegate;

       QSqlQuery   *query;
       QSqlTableModel *model;

         QSqlDatabase     db_readers;
       QSortFilterProxyModel *proxyModel;
};

#endif // readers_H
