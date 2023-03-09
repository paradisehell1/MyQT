#include "delegate.h"
#include <iostream>
#include <QItemDelegate>
#include "books.h"
int columnBook;

Delegate::Delegate(QObject *parent):QItemDelegate(parent)
{

}
QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{

    qDebug()<<columnBook;
    if (columnBook==0){

    QLineEdit *edit = new QLineEdit(parent);
    edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]{3})[\\.]([\\d]{3}))")));


          return edit;
    }
    if (columnBook==1){

        QLineEdit *edit = new QLineEdit(parent);
        edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-яЁё]+")));


          return edit;
    }
    if (columnBook==2)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-яЁё]+")));

              return edit;
    }
    if (columnBook==3)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-яЁё]+")));

              return edit;
    }

    if (columnBook==4)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]{4}))")));

              return edit;
    }

    if (columnBook==5)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]+))")));

              return edit;
    }
    if (columnBook==6)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]+))")));

              return edit;
    }



}
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QString value =index.model()->data(index, Qt::EditRole).toString();
         QLineEdit *line = static_cast<QLineEdit*>(editor);
         line->setText(value);
}
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
       QString value = line->text();
       model->setData(index, value);

}
void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
editor->setGeometry(option.rect);
}
