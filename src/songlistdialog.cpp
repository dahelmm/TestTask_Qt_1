#include "songlistdialog.h"

#include "ui_songlistdialog.h"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QThread>

#define TABLE "Compositions"

Q_DECLARE_METATYPE(SongListDialog::Composition);

bool databaseActivation = false;

SongListDialog::SongListDialog(QWidget *parent): QDialog(parent)
{
	m_ui = new Ui::SongListDialog();
	m_ui->setupUi(this);
    createDatabase();
    openDatabase();

    query = new QSqlQuery(db);

    createTable(TABLE);
    dlg = new SongDialog();


//    modd = new MyModel();
    model= new QSqlTableModel(this,db);
    model->setTable(TABLE);



    model->select();

    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ui->tableView->setModel(model);
    m_ui->tableView->setColumnHidden(1,true);
    m_ui->tableView->setSortingEnabled(true);
    connect(this,SIGNAL(editActivation(int)), dlg, SLOT(editActivity(int)));
}


SongListDialog::~SongListDialog()
{
    delete m_ui;


}

void SongListDialog::createDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("./compositions.db");
}

bool SongListDialog::openDatabase()
{
    databaseActivation =true;
    return db.open();
}

bool SongListDialog::createTable(QString nameTable)
{
    return query->exec("CREATE TABLE "+nameTable+"("
                "Image BLOB,"
                "Path TXT,"
                "Name TXT,"
                "Autor TXT,"
                "DurationMin INT,"
                "DurationSec INT,"
                "Grade INT);");

}



void SongListDialog::on_btnCreate_clicked()
{

    dlg->exec();

    if(dlg->sign == true)
    {

        QSqlQuery query2(db);
        query2.prepare("INSERT INTO Compositions (Image, Path, Name, Autor, DurationMin, DurationSec, Grade)"
                       "VALUES(?,?,?,?,?,?,?);");
        query2.addBindValue(dlg->song.image);
        query2.addBindValue(dlg->song.path);
        query2.addBindValue(dlg->song.name);
        query2.addBindValue(dlg->song.autor);
        query2.addBindValue(dlg->song.duration_min);
        query2.addBindValue(dlg->song.duration_sec);
        query2.addBindValue(dlg->song.grade);
        if(!query2.exec())
        {
            qDebug()<<"Error insert new row";
        }

        model->select();

    }
}


void SongListDialog::on_tableView_clicked(const QModelIndex &index)
{
    activityRow = index.row();
}


void SongListDialog::on_pB_edit_clicked()
{
    dlg->editSign = true;
    emit editActivation(activityRow);
    dlg->exec();
    model->select();



}

void SongListDialog::on_pB_deleteRow_clicked()
{
    model->removeRow(activityRow);
    model->select();

}







//QVariant MyModel::data(const QModelIndex &ind, int role) const
//{
//    if(ind.column() == 0)
//    {
//        if(role == Qt::DecorationRole)
//            return "";
//        if(role == Qt::DecorationRole)
//        {
//            QPixmap pix;
//            pix.loadFromData(QSqlTableModel::data(ind,Qt::DisplayRole).toByteArray(), "jpeg");
//            return pix;
//        }


//    }
//    return QSqlTableModel::data(ind,role);
//}


