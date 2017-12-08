#ifndef SIMPLETREE_H
#define SIMPLETREE_H

#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "person.h"
#include "person_graphicitem.h"
#include "sql_connect.h"
class SimpleTree
{

public:
    SimpleTree(qint16 id,QGraphicsScene* scene,sql_connect* database);
    ~SimpleTree();
    Person *p33;
    Person *parents;
    Person *person_table;
    person_GraphicItem *gi_parents;
    person_GraphicItem *gi_p33;
    person_GraphicItem *close_family;
    qint16 close_family_size;
    QGraphicsScene* scene1;
 private:
    qreal dx = 30;
    qreal dy = 100;

};

#endif // SIMPLETREE_H
