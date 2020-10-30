#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen,&QAction::triggered,
            [=](){
        QString path =QFileDialog::getOpenFileName(this,"open","../");
        if(path.isEmpty()==false){
            QFile file(path);
            bool openFlag=file.open(QIODevice::ReadOnly);
            QTextStream stream(&file);
            QList<QString> list;

            while(!stream.atEnd())
                list.push_back(stream.readLine());
            tm.initialTM(list);
    }
}
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

