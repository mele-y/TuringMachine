#include "tm.h"

TM::TM()
{

}
void TM::initialTM(QTextDocument* text){
    int n=text->blockCount();
    QString old_state,new_state;
    QChar input_ch,replace_ch,direction;
    for(int i=0;i<n;i++)
    {
        QString line=text->findBlockByNumber(i).text();
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
}
int compute(int x,int y)
{
    QList<QChar> tape;
    for(int i=0;i<y;i++)
    {
        tape.push_back('1');
    }
     tape.push_back('0');

}
