#include "xpowydialog.h"


XPowYDialog::XPowYDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XPowYDialog)
{
    ui->setupUi(this);
}

XPowYDialog::~XPowYDialog()
{
    delete ui;
}
