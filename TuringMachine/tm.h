#ifndef TM_H
#define TM_H

#include<QSet>
#include<QString>
#include<QMap>

struct current
{
    QString state;
    QChar header_symbol;
};
struct trans
{
    QString trans_state;
    QChar  replace_symbol;
    int direction;//0 means left,1 means right
};

class TM
{
private:QSet<QString> state_set;
        QChar blank_symnol='B';
        QMap<current,trans> rules;
public:
    TM();
    void initialTM(QString);

};

#endif // TM_H
