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
            if(openFlag==true){
               QByteArray array,temp;
               QVector<QString> sv;
               while(file.atEnd()==false){
                   temp=file.readLine();
                   array+=temp;
//                   int ibegin;
//                   int iend=0;
//                   if(iend!=-1){
//                      ibegin=iend;
//                      iend= temp.indexOf(' ',(ibegin+1)); //每次找到空格
//                      QString sr="";
//                      for(int j=ibegin;j<iend;j++){
//                          sr+=temp[j]; //每次得到字符串
//                      }
//                       sv.append(sr);
//                   }
//                   QString sr="";
//                   for(int j=iend;j<temp.length();j++){
//                        sr+=temp[j];
//                   }
//                   sv.append(sr);
//                   sr.clear();

////                 /*sr="("+sv[0]+","+sv[1]+")"+"|-"+"("+sv[2]+","+sv[3]+","+sv[4]+")\n";
//                   //this->str.append(sr);*/
//                   qDebug()<<sv;
            }
               QTextDocument text(array);
               qDebug()<<text.toPlainText();
            file.close();
        }
    }
}
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

