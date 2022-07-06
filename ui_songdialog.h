/********************************************************************************
** Form generated from reading UI file 'songdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGDIALOG_H
#define UI_SONGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SongDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPreview;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPreview;
    QLabel *l_name;
    QLineEdit *lE_name;
    QLabel *l_autor;
    QLineEdit *lE_autor;
    QLabel *l_duration;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sB_min;
    QLabel *l_min;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *sB_sec;
    QLabel *l_sec;
    QLabel *l_grade;
    QSlider *horizontalSlider;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SongDialog)
    {
        if (SongDialog->objectName().isEmpty())
            SongDialog->setObjectName(QString::fromUtf8("SongDialog"));
        SongDialog->setEnabled(true);
        SongDialog->resize(266, 313);
        gridLayout = new QGridLayout(SongDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelPreview = new QLabel(SongDialog);
        labelPreview->setObjectName(QString::fromUtf8("labelPreview"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPreview->sizePolicy().hasHeightForWidth());
        labelPreview->setSizePolicy(sizePolicy);
        labelPreview->setMinimumSize(QSize(125, 125));
        labelPreview->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(labelPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPreview = new QPushButton(SongDialog);
        btnPreview->setObjectName(QString::fromUtf8("btnPreview"));
        sizePolicy.setHeightForWidth(btnPreview->sizePolicy().hasHeightForWidth());
        btnPreview->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnPreview);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        l_name = new QLabel(SongDialog);
        l_name->setObjectName(QString::fromUtf8("l_name"));

        gridLayout->addWidget(l_name, 1, 0, 1, 1);

        lE_name = new QLineEdit(SongDialog);
        lE_name->setObjectName(QString::fromUtf8("lE_name"));

        gridLayout->addWidget(lE_name, 1, 1, 1, 1);

        l_autor = new QLabel(SongDialog);
        l_autor->setObjectName(QString::fromUtf8("l_autor"));

        gridLayout->addWidget(l_autor, 2, 0, 1, 1);

        lE_autor = new QLineEdit(SongDialog);
        lE_autor->setObjectName(QString::fromUtf8("lE_autor"));

        gridLayout->addWidget(lE_autor, 2, 1, 1, 1);

        l_duration = new QLabel(SongDialog);
        l_duration->setObjectName(QString::fromUtf8("l_duration"));

        gridLayout->addWidget(l_duration, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sB_min = new QSpinBox(SongDialog);
        sB_min->setObjectName(QString::fromUtf8("sB_min"));

        horizontalLayout_3->addWidget(sB_min);

        l_min = new QLabel(SongDialog);
        l_min->setObjectName(QString::fromUtf8("l_min"));

        horizontalLayout_3->addWidget(l_min);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sB_sec = new QSpinBox(SongDialog);
        sB_sec->setObjectName(QString::fromUtf8("sB_sec"));

        horizontalLayout_2->addWidget(sB_sec);

        l_sec = new QLabel(SongDialog);
        l_sec->setObjectName(QString::fromUtf8("l_sec"));

        horizontalLayout_2->addWidget(l_sec);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        l_grade = new QLabel(SongDialog);
        l_grade->setObjectName(QString::fromUtf8("l_grade"));

        gridLayout->addWidget(l_grade, 4, 0, 1, 1);

        horizontalSlider = new QSlider(SongDialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(5);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setValue(5);
        horizontalSlider->setSliderPosition(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(SongDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 2);


        retranslateUi(SongDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SongDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SongDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SongDialog);
    } // setupUi

    void retranslateUi(QDialog *SongDialog)
    {
        SongDialog->setWindowTitle(QCoreApplication::translate("SongDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        labelPreview->setToolTip(QCoreApplication::translate("SongDialog", "\320\237\321\200\320\265\320\262\321\214\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        labelPreview->setText(QString());
#if QT_CONFIG(tooltip)
        btnPreview->setToolTip(QCoreApplication::translate("SongDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPreview->setText(QCoreApplication::translate("SongDialog", "+", nullptr));
        l_name->setText(QCoreApplication::translate("SongDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        l_autor->setText(QCoreApplication::translate("SongDialog", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        l_duration->setText(QCoreApplication::translate("SongDialog", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        l_min->setText(QCoreApplication::translate("SongDialog", "\320\274\320\270\320\275", nullptr));
        l_sec->setText(QCoreApplication::translate("SongDialog", "\321\201\320\265\320\272", nullptr));
        l_grade->setText(QCoreApplication::translate("SongDialog", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongDialog: public Ui_SongDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGDIALOG_H
