#ifndef XPOWYDIALOG_H
#define XPOWYDIALOG_H

#include <QDialog>

namespace Ui {
class XPowYDialog;
}

class XPowYDialog : public QDialog
{
    Q_OBJECT

public:
    explicit XPowYDialog(QWidget *parent = nullptr);
    ~XPowYDialog();

private:
    Ui::XPowYDialog *ui;
};

#endif // XPOWYDIALOG_H
