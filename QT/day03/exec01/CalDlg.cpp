#include "CalDlg.h"
#include <QHBoxLayout>
#include <QDoubleValidator>
CalDlg::CalDlg(){
    setupUi(this);
    m_editX->setValidator(new QDoubleValidator(this));
  
    m_editY->setValidator(new QDoubleValidator(this));

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
}
void CalDlg::calResult(){
    double res = m_editX->text().toDouble() + m_editY->text().toDouble();
    m_editZ->setText(QString::number(res, 'g', 5));
}

