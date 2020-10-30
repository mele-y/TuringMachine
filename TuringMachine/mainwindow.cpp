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
               while(file.atEnd()==false){
                   QVector<int> blankIndex;
                   temp=file.readLine();
                   array+=temp;
                   for(int i=0;i<temp.length();i++){
                       if(temp[i]==' ')
                           blankIndex.append(i);
                   }
//                   qDebug()<<blankIndex;
                   QString a,b,c,d,e;
                   for(int i=0;i<blankIndex[0];i++)
                       a+=temp[i];
                       b+=temp[blankIndex[0]+1];
                   for(int i=blankIndex[1]+1;i<blankIndex[2];i++)
                       c+=temp[i];
                       d+=temp[blankIndex[2]+1];
                       e+=temp[blankIndex[3]+1];
                   QString sr;
                   sr="("+a+","+b+")"+"|-"+"("+c+","+d+","+e+")\n";
                   this->str.append(sr);
            }
               QTextDocument text(array);
               QTextDocument *text2=&text;
               tm.initialTM(text2);
               //qDebug()<<str;
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

