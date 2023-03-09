#ifndef DELEGAT_READERS_H
#define DELEGAT_READERS_H

#include "variables.h"
#include<QItemDelegate>
#include <QModelIndex>
#include <QObject>


class Delegat_readers:public QItemDelegate
{


public:



    Variables var;

    explicit Delegat_readers(QObject *parent = nullptr);
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
        void setEditorData(QWidget *editor, const QModelIndex &index) const ;
        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const ;
        void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const ;
};

#endif // Delegeate_readers_H
