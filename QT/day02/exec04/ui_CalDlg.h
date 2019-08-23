/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALDLG_H
#define UI_CALDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editX;
    QLabel *m_labSig;
    QLineEdit *m_editY;
    QPushButton *m_btnCal;
    QLineEdit *m_editZ;

    void setupUi(QDialog *CalDlg)
    {
        if (CalDlg->objectName().isEmpty())
            CalDlg->setObjectName(QStringLiteral("CalDlg"));
        CalDlg->resize(543, 65);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        CalDlg->setFont(font);
        horizontalLayout = new QHBoxLayout(CalDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_editX = new QLineEdit(CalDlg);
        m_editX->setObjectName(QStringLiteral("m_editX"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        m_editX->setFont(font1);
        m_editX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editX);

        m_labSig = new QLabel(CalDlg);
        m_labSig->setObjectName(QStringLiteral("m_labSig"));
        QFont font2;
        font2.setPointSize(18);
        m_labSig->setFont(font2);

        horizontalLayout->addWidget(m_labSig);

        m_editY = new QLineEdit(CalDlg);
        m_editY->setObjectName(QStringLiteral("m_editY"));
        m_editY->setFont(font1);
        m_editY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editY);

        m_btnCal = new QPushButton(CalDlg);
        m_btnCal->setObjectName(QStringLiteral("m_btnCal"));
        m_btnCal->setEnabled(false);
        m_btnCal->setFont(font1);

        horizontalLayout->addWidget(m_btnCal);

        m_editZ = new QLineEdit(CalDlg);
        m_editZ->setObjectName(QStringLiteral("m_editZ"));
        m_editZ->setFont(font1);
        m_editZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_editZ->setReadOnly(true);

        horizontalLayout->addWidget(m_editZ);


        retranslateUi(CalDlg);

        QMetaObject::connectSlotsByName(CalDlg);
    } // setupUi

    void retranslateUi(QDialog *CalDlg)
    {
        CalDlg->setWindowTitle(QApplication::translate("CalDlg", "Dialog", 0));
        m_labSig->setText(QApplication::translate("CalDlg", "+", 0));
        m_btnCal->setText(QApplication::translate("CalDlg", "=", 0));
    } // retranslateUi

};

namespace Ui {
    class CalDlg: public Ui_CalDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALDLG_H
