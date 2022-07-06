/********************************************************************************
** Form generated from reading UI file 'songlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGLISTDIALOG_H
#define UI_SONGLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SongListDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCreate;
    QPushButton *pB_edit;
    QPushButton *pB_deleteRow;

    void setupUi(QDialog *SongListDialog)
    {
        if (SongListDialog->objectName().isEmpty())
            SongListDialog->setObjectName(QString::fromUtf8("SongListDialog"));
        SongListDialog->resize(641, 372);
        gridLayout = new QGridLayout(SongListDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(SongListDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnCreate = new QPushButton(SongListDialog);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        verticalLayout->addWidget(btnCreate);

        pB_edit = new QPushButton(SongListDialog);
        pB_edit->setObjectName(QString::fromUtf8("pB_edit"));

        verticalLayout->addWidget(pB_edit);

        pB_deleteRow = new QPushButton(SongListDialog);
        pB_deleteRow->setObjectName(QString::fromUtf8("pB_deleteRow"));

        verticalLayout->addWidget(pB_deleteRow);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(SongListDialog);

        QMetaObject::connectSlotsByName(SongListDialog);
    } // setupUi

    void retranslateUi(QDialog *SongListDialog)
    {
        SongListDialog->setWindowTitle(QString());
        btnCreate->setText(QCoreApplication::translate("SongListDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pB_edit->setText(QCoreApplication::translate("SongListDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pB_deleteRow->setText(QCoreApplication::translate("SongListDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongListDialog: public Ui_SongListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGLISTDIALOG_H
