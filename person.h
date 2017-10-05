#ifndef PERSON_H
#define PERSON_H

#include <QMainWindow>
class Person
{
public:
    Person();
    qint16 id;
    QString name;
    bool gender; //1 man, 0 female


    qint16 *spouse; //małżonek
    qint16 nr_spous;
    qint16 *children;
    qint16 nr_children;
    qint16 parents[2]; //1 father, 2 mather
    ~Person();
};

#endif // PERSON_H
