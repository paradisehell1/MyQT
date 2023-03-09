#ifndef USER_FIRST_WINDOW_H
#define USER_FIRST_WINDOW_H

#include <QDialog>
#include <QFile>
#include <QTimer>
#include <QtGui>
#include <QInputDialog>
#include <QLineEdit>


namespace Ui {
class User_first_window;
}

class User_first_window : public QDialog
{
    Q_OBJECT

public:
    explicit User_first_window(QWidget *parent = nullptr);
    ~User_first_window();
    QStringList ku2;
    QString newStr;
     QString main_str="";
     int choise;

private slots:
    void show_hello();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);
    void change_pass();
    void change_log();

    void on_pushButton_3_clicked();

private:
    Ui::User_first_window *ui;
};

#endif // USER_FIRST_WINDOW_H
