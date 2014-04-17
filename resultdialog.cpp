#include "resultdialog.h"
#include "ui_resultdialog.h"

ResultDialog::ResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultDialog)
{
    ui->setupUi(this);
}

ResultDialog::~ResultDialog()
{
    delete ui;
}
void ResultDialog::showResult(QString string)
{
    //QString ans = QString(QString::fromLocal8Bit(string.c_str()));
    ui->result->setText(string);
    this->show();
}
