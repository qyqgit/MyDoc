/********************************************************************************
** Form generated from reading UI file 'showpics.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPICS_H
#define UI_SHOWPICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowPics
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ShowPics)
    {
        if (ShowPics->objectName().isEmpty())
            ShowPics->setObjectName(QStringLiteral("ShowPics"));
        ShowPics->resize(400, 300);
        verticalLayout = new QVBoxLayout(ShowPics);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(ShowPics);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(ShowPics);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ShowPics);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ShowPics);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ShowPics);

        QMetaObject::connectSlotsByName(ShowPics);
    } // setupUi

    void retranslateUi(QDialog *ShowPics)
    {
        ShowPics->setWindowTitle(QApplication::translate("ShowPics", "ShowPics", 0));
        pushButton->setText(QApplication::translate("ShowPics", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("ShowPics", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("ShowPics", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowPics: public Ui_ShowPics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPICS_H
