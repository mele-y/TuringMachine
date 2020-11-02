#ifndef XPOWYFORM_H
#define XPOWYFORM_H

#include <QWidget>

namespace Ui {
class XPowYForm;
}

class XPowYForm : public QWidget
{
    Q_OBJECT

public:
    explicit XPowYForm(QWidget *parent = nullptr);
    ~XPowYForm();

private slots:
    void on_compute_button_clicked();

private:
    Ui::XPowYForm *ui;
};

#endif // XPOWYFORM_H
