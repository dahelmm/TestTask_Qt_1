#include "songdialog.h"
#include "ui_songdialog.h"
#include <QFileDialog>
#include <QDebug>
#include <QDialogButtonBox>
#include <QPushButton>

extern bool databaseActivation;

SongDialog::SongDialog(QWidget* parent): QDialog(parent), m_ui(new Ui::SongDialog())
{
	m_ui->setupUi(this);
	connect(m_ui->btnPreview, &QPushButton::clicked, this, &SongDialog::choosePreview);
	QDir dir;
	if (!dir.exists(m_imageDir))
		dir.mkpath(m_imageDir);

    if(databaseActivation == false)
    {
        db.open();
    }

    query = new QSqlQuery(db);




}

SongDialog::~SongDialog()
{
	delete m_ui;

}

void SongDialog::choosePreview()
{
	const auto filename = QFileDialog::getOpenFileName(this, tr("Выберите изображение"),
		QString(), "(*.jpeg *.jpg *png *gif)");
	if (filename.isEmpty())
		return;
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    song.image = file.readAll();
	const QString copyName = copiedPreview(filename);
	showPreview(copyName);
    song.path = fullImagePath(filename);

}

QString SongDialog::copiedPreview(const QString& filePath) const
{
	const QImage image(filePath);
	const auto smaller = image.scaled(m_ui->labelPreview->width(), m_ui->labelPreview->height(),
		Qt::AspectRatioMode::KeepAspectRatioByExpanding);

	QString name = "1.png";
	if (!smaller.save(fullImagePath(name), "PNG"))
		return QString();

	return  name;
	
}

void SongDialog::showPreview(const QString& relativePath) const
{
	if (relativePath.isEmpty())
		return;
	const auto fn = fullImagePath(relativePath);
	if (!QFile::exists(fn))
		return;

	const QPixmap pixmap(fn);	
	m_ui->labelPreview->setPixmap(pixmap);
}


QString SongDialog::fullImagePath(const QString& relativePath) const
{
	QDir dir;
	dir.cd(m_imageDir);
	return dir.absoluteFilePath(relativePath);
}
void SongDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == m_ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        song.name = m_ui->lE_name->text();
        song.autor = m_ui->lE_autor->text();
        song.duration_min = m_ui->sB_min->value();
        song.duration_sec = m_ui->sB_sec->value();
        song.grade = m_ui->horizontalSlider->value();
        sign =true;
        if(editSign ==true)
        {
            QSqlQuery query2(db);
            query2.prepare("UPDATE Compositions "
                           "SET "
                           "Image = :image, "
                           "Path = :path, "
                           "Name = :name, "
                           "Autor = :autor, "
                           "DurationMin = :durmin, "
                           "DurationSec = :dursec, "
                           "Grade = :grade  "
                           "WHERE rowid=" +QString::number(rowIndex+1) +";");
            query2.bindValue(":image",song.image);
            query2.bindValue(":path",song.path);
            query2.bindValue(":name",song.name);
            query2.bindValue(":autor",song.autor);
            query2.bindValue(":durmin",song.duration_min);
            query2.bindValue(":dursec",song.duration_sec);
            query2.bindValue(":grade",song.grade);
            if(!query2.exec())
            {
                qDebug()<<"Error";
            }
            editSign = false;
        }


    }
    else
    {
        qDebug()<<"ОТМЕНА";

    }
}

void SongDialog::editActivity(int indexRow)
{
    query->exec("SELECT * FROM Compositions;");
    query->seek(indexRow);

    QPixmap pix;
    pix.loadFromData(query->value(0).toByteArray(),"jpeg");
    int pixW = m_ui->labelPreview->minimumWidth();
    int pixH = m_ui->labelPreview->minimumHeight();
    m_ui->labelPreview->setPixmap(pix.scaled(pixW,pixH,Qt::KeepAspectRatioByExpanding));
    song.path = query->value(1).toString();
    song.name = query->value(2).toString();
    song.autor = query->value(3).toString();
    song.duration_min = query->value(4).toInt();
    song.duration_sec = query->value(5).toInt();
    song.grade = query->value(6).toInt();

    m_ui->lE_name->setText(song.name);
    m_ui->lE_autor->setText(song.autor);
    m_ui->sB_min->setValue(song.duration_min);
    m_ui->sB_sec->setValue(song.duration_sec);
    m_ui->horizontalSlider->setValue(song.grade);
    editSign = true;
    rowIndex = indexRow;

}




