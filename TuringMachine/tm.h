#ifndef TM_H
#define TM_H

#include<QSet>
#include<QString>
#include<QMap>
#include<QTextDocument>
#include<QTextBlock>
#include<QList>
struct Current
{
    QString state;
    QChar header_symbol;
    Current(QString state,QChar header_symbol)
    {
        this->state=state;
        this->header_symbol=header_symbol;
    }
};
struct Trans
{
    QString trans_state;
    QChar  replace_symbol;
    QChar direction;//0 means left,1 means right
    Trans(QString trans_state,QChar replace_symbol,QChar direction)
    {
        this->trans_state=trans_state;
        this->replace_symbol=replace_symbol;
        this->direction=direction;
    }
};

class TM
{
private:QSet<QString> state_set;
        QChar blank_symnol='B';
        QMap<Current,Trans> rules;
        QString final_state="pf";
        QString start_state="p0";
        QString current_state;
        QList<QChar> tape;
public:
    TM();
    void initialTM(QTextDocument* text);
    int  compute(int x,int y);
};

#endif // TM_H
