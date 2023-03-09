#ifndef DELEGATE_H
#define DELEGATE_H

#include "variables.h"
#include<QItemDelegate>
#include <QModelIndex>
#include <QObject>


class Delegate:public QItemDelegate
{


public:



    Variables var;

    explicit Delegate(QObject *parent = nullptr);
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
        void setEditorData(QWidget *editor, const QModelIndex &index) const ;
        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const ;
        void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const ;
};

#endif // DELEGATE_H
