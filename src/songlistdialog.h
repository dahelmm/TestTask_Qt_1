#pragma once
#include "songdialog.h"

#include <QDialog>
#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>
#include <QAbstractItemModel>
#include <QSqlTableModel>
#include <QLabel>
#include <QSqlRelationalTableModel>

namespace Ui 
{
class SongListDialog;
}


//class MyModel : public QSqlTableModel
//{
//public:
//    virtual QVariant data(const QModelIndex &ind, int role = Qt::DisplayRole) const;

//};

class SongListDialog : public QDialog
{
Q_OBJECT

public:
	SongListDialog(QWidget *parent = nullptr);
	~SongListDialog();
    void createDatabase();
    bool openDatabase();
    bool createTable(QString nameTable);

    struct Composition
    {
        QByteArray image;
        QString path;
        QString name;
        QString autor;
        int duration_min;
        int duration_sec;
        int grade;
    };
    Composition song2;

//    MyModel *modd ;


public slots:
    void on_btnCreate_clicked();

private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void on_pB_edit_clicked();
    void on_pB_deleteRow_clicked();


private:
	Ui::SongListDialog* m_ui = nullptr;
    QSqlDatabase db;
    QSqlQuery *query;
    SongDialog *dlg;
    QSqlTableModel *model;

    int activityRow;



signals:
    void editActivation(int);


};


