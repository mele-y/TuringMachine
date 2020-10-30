#include "tm.h"

TM::TM()
{

}

void TM::initialTM(QByteArray array){

     QList<QByteArray> list=array.split('\n');
    //int n=text->blockCount();
    QString old_state,new_state;
    QChar input_ch,replace_ch,direction;
    for(int i=0;i<n;i++)
    {
        QString line=QString(list[i]);
        if(!line.length())
            continue;
        else
        {
           QStringList list=line.split('\t');
           old_state=list[0];
           input_ch=list[1][0];
           new_state=list[2];
           replace_ch=list[3][0];
           direction=list[4][0];
           if(!state_set.contains(old_state))
               state_set.insert(old_state);
           Current c(old_state,input_ch);
           Trans t(new_state,replace_ch,direction);
           rules[c]=t;
        }
    }
    for(auto i:rules.keys())
    {
        //qDebug()<<i.state<<i.header_symbol<<rules[i].trans_state<<rules[i].replace_symbol<<rules[i].direction;
    }
}
int TM::compute(int x,int y)
{
     tape.clear();
     for(int i=0;i<y;i++)
        tape.push_back('1');
     tape.push_back('0');
     for(int i=0;i<x;i++)
        tape.push_back('1');
     current_state=start_state;
     int index=0;
     while(current_state!=final_state)
     {
         Current c(current_state,tape[index]);
         if(!rules.contains(c))
         {
             msg="转换函数&("+current_state+","+tape[index]+")未定义";
             break;
         }
         else
         {
             Trans t=rules[c];
             current_state=t.trans_state;
             tape[index]=t.replace_symbol;
             if(t.direction=='L')
             {
                 index--;
                 if(index<0)
                 tape.push_front('B');
             }
             else
              {
                index++;
                if(index>=tape.size())
                    tape.push_back('B');
              }
         }
     }
     int count=0;
     for(auto i:tape)
     {
         if(i=='1')
             count++;
     }
     return count;
}
