#ifndef INFO_GIVE_H
#define INFO_GIVE_H

#include <QDialog>
#include "variables.h"
#include "given.h"

namespace Ui {
class Info_give;
}

class Info_give : public QDialog
{
    Q_OBJECT

public:
    explicit Info_give(QWidget *parent = nullptr);
    ~Info_give();
    int row;
    int del_row;
private slots:
    void on_pushButton_clicked();
    void insert_to_table();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::Info_give *ui;
    Given give;
    QSqlDatabase     db_info;
       QSqlQuery   *query;
       QSqlTableModel *model;
       QString enc,enc1;
};

#endif // INFO_GIVE_H
