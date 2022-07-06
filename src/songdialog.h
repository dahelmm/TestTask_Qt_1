#pragma once
#include <QDialog>
#include <QAbstractButton>
#include <QFile>
#include <QSharedPointer>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QSqlTableModel>
#include <QFileDialog>
#include <QDebug>
#include <QSqlRecord>

namespace Ui 
{	
class SongDialog;
}

class SongDialog : public QDialog
{
	Q_OBJECT
public:
	SongDialog(QWidget* parent = nullptr);
	~SongDialog();
    struct Composition
        {
            QByteArray image;
            int duration_min;
            int duration_sec;
            QString path;
            QString name;
            QString autor;
            int grade;
        };
    Composition song;
    bool sign = false;
    bool editSign = false;
    int rowIndex;
public slots:
    void editActivity(int indexRow);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
	void choosePreview();
	QString copiedPreview(const QString& filePath) const;
	void showPreview(const QString& relativePath) const;
	QString fullImagePath(const QString& relativePath) const;
    QSqlQuery *query;
	Ui::SongDialog* m_ui = nullptr;
	const QString m_imageDir = "../../images";
    QSqlDatabase db;
};

