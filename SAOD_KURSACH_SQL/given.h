#ifndef GIVEN_H
#define GIVEN_H

#include <QDialog>

namespace Ui {
class Given;
}

class Given : public QDialog
{
    Q_OBJECT

public:
    explicit Given(QWidget *parent = nullptr);
    ~Given();
    QString enc;
    QString enc1;
    bool ok,ok1;
private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::Given *ui;
};

#endif // GIVEN_H
