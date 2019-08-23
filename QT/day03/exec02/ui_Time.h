/********************************************************************************
** Form generated from reading UI file 'Time.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_H
#define UI_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Time
{
public:
    QLabel *myLabel;
    QPushButton *myButton;

    void setupUi(QDialog *Time)
    {
        if (Time->objectName().isEmpty())
            Time->setObjectName(QStringLiteral("Time"));
        Time->setEnabled(true);
        Time->resize(204, 109);
        myLabel = new QLabel(Time);
        myLabel->setObjectName(QStringLiteral("myLabel"));
        myLabel->setGeometry(QRect(50, 40, 91, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        myLabel->setFont(font);
        myLabel->setAlignment(Qt::AlignCenter);
        myButton = new QPushButton(Time);
        myButton->setObjectName(QStringLiteral("myButton"));
        myButton->setGeometry(QRect(50, 70, 99, 27));

        retranslateUi(Time);

        QMetaObject::connectSlotsByName(Time);
    } // setupUi

    void retranslateUi(QDialog *Time)
    {
        Time->setWindowTitle(QApplication::translate("Time", "Dialog", 0));
        myLabel->setText(QApplication::translate("Time", "00:00:00  AM", 0));
        myButton->setText(QApplication::translate("Time", "Click", 0));
    } // retranslateUi

};

namespace Ui {
    class Time: public Ui_Time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIME_H
