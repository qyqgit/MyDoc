#include "CalDlg.h"
#include <QHBoxLayout>
#include <QDoubleValidator>
CalDlg::CalDlg(){
    m_editX = new QLineEdit(this);
    m_editX->setValidator(new QDoubleValidator(this));
    m_editX->setAlignment(Qt::AlignRight);
    m_labSig = new QLabel("+", this);
    m_editY = new QLineEdit(this);
    m_editY->setValidator(new QDoubleValidator(this));
    m_editY->setAlignment(Qt::AlignRight);
    m_btnCal = new QPushButton("=", this);
    m_btnCal->setEnabled(false);
    m_editZ = new QLineEdit(this);
    m_editZ->setReadOnly(true);
    m_editZ->setAlignment(Qt::AlignRight);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_editX);
    layout->addWidget(m_labSig);
    layout->addWidget(m_editY);
    layout->addWidget(m_btnCal);
    layout->addWidget(m_editZ);

    connect(m_editX, SIGNAL(textChanged(const QString&)), this, SLOT(enableCal()));
    connect(m_editY, SIGNAL(textChanged(const QString&)), this, SLOT(enableCal()));
    connect(m_btnCal, SIGNAL(clicked()), this, SLOT(calResult()));
}
void CalDlg::enableCal(){
    bool bXok;
    bool bYok;
    m_editX->text().toDouble(&bXok);
    m_editY->text().toDouble(&bYok);
    m_btnCal->setEnabled(bXok && bYok);
    /*if(bXok && bYok){
        m_btnCal->setEnabled(true);
    }else{
        m_btnCal->setEnabled(false);
    }*/
}
void CalDlg::calResult(){
    double res = m_editX->text().toDouble() + m_editY->text().toDouble();
    m_editZ->setText(QString::number(res, 'g', 5));
}

