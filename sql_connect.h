#ifndef SQL_CONNECT_H
#define SQL_CONNECT_H

#include <QtSql>
#include <QDebug>
#include <QTableWidget>

#include "person.h"


class sql_connect
{
public:
    sql_connect();
    QSqlDatabase db;


    int take_list(QTableWidget* table);

    void take_parents(Person* person);
    void create_person(Person* person);
    QString take_name(qint16 id);
    ~sql_connect();

};

#endif // SQL_CONNECT_H
