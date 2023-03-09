#ifndef WORKER_WINDOW_H
#define WORKER_WINDOW_H

#include "qtablewidget.h"
#include <QDialog>
#include <QFile>
#include <QStringList>
#include <QList>

namespace Ui {
class Worker_window;
}

class Worker_window : public QDialog
{
    Q_OBJECT

public:
    explicit Worker_window(QWidget *parent = nullptr);
    ~Worker_window();

    QString main_str1="";
    QStringList lst;
    int row;
    int column;
    int row123;
    int column123;
    QTableWidgetItem *passwordItem;
    QTableWidgetItem *passwordItem1;
private:
    Ui::Worker_window *ui;
private slots:
   void to_table(QString s);
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_tableWidget_cellClicked(int row, int column);
   void mask_data();

   void on_pushButton_3_clicked();
};

#endif // WORKER_WINDOW_H
