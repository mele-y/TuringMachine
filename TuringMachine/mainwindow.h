#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QAction>
#include<QByteArray>
#include<QTextDocument>
#include<QDebug>
#include "tm.h"
#include "xpowyform.h"
#include <QTextStream>
#include<QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_compute_button_clicked();

private:
    Ui::MainWindow *ui;
    QString str;
    TM tm;
    QByteArray array;
   // XPowYForm form;
};
#endif // MAINWINDOW_H
