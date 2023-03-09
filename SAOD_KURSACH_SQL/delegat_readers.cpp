#include "Delegat_readers.h"
#include <iostream>
#include <QItemDelegate>
#include "readers.h"
int columnReaders;

Delegat_readers::Delegat_readers(QObject *parent):QItemDelegate(parent)
{

}
QWidget *Delegat_readers::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{

    qDebug()<<columnReaders;
    if (columnReaders==0){

    QLineEdit *edit = new QLineEdit(parent);
    edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([А,Ч,В]{1}+[\\d]{4})[\\-]([\\d]{2}))")));


          return edit;
    }
    if (columnReaders==1)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-яЁё]+")));

              return edit;
    }
    if (columnReaders==2)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("(([\\d]{4}))")));

              return edit;
    }

    if (columnReaders==3)
    {

          QLineEdit *edit = new QLineEdit(parent);


              return edit;
    }

    if (columnReaders==4)
    {

          QLineEdit *edit = new QLineEdit(parent);
          edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zА-Яа-яЁё]+")));

              return edit;
    }



}
void Delegat_readers::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QString value =index.model()->data(index, Qt::EditRole).toString();
         QLineEdit *line = static_cast<QLineEdit*>(editor);
         line->setText(value);
}
void Delegat_readers::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
       QString value = line->text();
       model->setData(index, value);

}
void Delegat_readers::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
editor->setGeometry(option.rect);
}
