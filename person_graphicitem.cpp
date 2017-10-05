#include "person_graphicitem.h"

person_GraphicItem::person_GraphicItem()
{
   // person = xx;
    avatar.load("empty_avatar.png");
    y= 70;
    x= 1.618 * y;
    y=35;
   // Pressed = false;
    setFlag(ItemIsMovable);
}


QRectF person_GraphicItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,x,y);

}

void person_GraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rect = boundingRect();
    painter->setBrush(QColor::QColor(124,230,63));
    painter->drawRect(rect);


    if(true)
    {
        painter->setFont(QFont ("Courier", 8));
        painter->drawText(QRectF(0.1*x,0.1*y,x-0.1*x,y-0.1*y),person->name);
    }
    else
    {
    //image in the border
    painter->drawImage(QRectF(0,0,y/1.618,y),avatar);
    painter->drawRect(QRectF(0,0,y/1.618,y));
    //name and surname
    painter->drawRect(QRectF(y/1.618,0,x-y/1.618,y/2.618));
    painter->setFont(QFont ("Courier", 8));

    painter->drawText(QRectF(y/1.618+0.05*x,0,x-y/1.618-0.05*x,y/2.618),person->name);
    //QPen pen(Qt::red, 3);

    //painter->setPen(pen);
   // painter->setFont(QFont ("Courier", 30));
    //painter->drawEllipse(rect);
    }
}


/*
 void SimpleTree::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
     Pressed = true;
     update();
     QGraphicsItem::mousePressEvent(event);
 }

 void SimpleTree::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
     Pressed = false;
     update();
     QGraphicsItem::mouseReleaseEvent(event);
 }
*/

/*
person_GraphicItem simple_tree(Person *xy)
{
    qint16 child;
    person_GraphicItem* close_family;

    //sql_connect.create_person(person->id);
    child =10;


    //close_family = new person_GraphicItem[1];
    close_family = new person_GraphicItem(xy);
    for(int i = 1; i<=child; i++)
    {
        close_family[i] = new person_GraphicItem(xy->children[i-1]);
    }

    return close_family;
}

*/
