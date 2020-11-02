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
            QString str;
            for(auto i:list){
                QList<QString> l=i.split(" ");
                QString temp="$("+l[0]+","+l[1]+")=("+l[2]+","+l[3]+","+l[4]+")\n";
                str+=temp;
            }
            ui->plainTextEdit->setPlainText(str);
     }
}
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_compute_button_clicked()
{
        int x=ui->input_x->text().toInt();
        int y=ui->input_y->text().toInt();
        int ans;
        try {
            ans=tm.compute(x,y);
            ui->output_ans->setText(QString::number(ans));
        } catch (...) {
         QString title="消息";
         QString info="运行超时";
         QMessageBox::critical(this,title,info);
        }

}
