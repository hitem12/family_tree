#ifndef PERSON_GRAPHICITEM_H
#define PERSON_GRAPHICITEM_H

#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>
#include "person.h"
#include "sql_connect.h"



class person_GraphicItem :public QGraphicsItem
{

public:
    Person* person;
    qreal x,y;


    person_GraphicItem();



private:
    QRectF boundingRect() const;

        // overriding paint()
        void paint(QPainter * painter,
                   const QStyleOptionGraphicsItem * option,
                   QWidget * widget);

        QRectF rect;


        QImage avatar;

    protected:

        // overriding mouse events
      //  void mousePressEvent(QGraphicsSceneMouseEvent *event);
       // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

person_GraphicItem* simple_tree(Person*);
#endif // PERSON_GRAPHICITEM_H
