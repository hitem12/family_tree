#include "person_graphicitem.h"

person_GraphicItem::person_GraphicItem()
{
    // person = xx;
    avatar.load("empty_avatar.png");
    size_y= 70;
    size_x= 1.618 * size_y;
    size_y=35;
    //x=-0.5 * size_x;
    //y=0.5 * size_y;
    x=0; y = 0;
    // Pressed = false;
    setFlag(ItemIsMovable);

}


QRectF person_GraphicItem::boundingRect() const
{
    // outer most edges

    return QRectF(x,y,size_x,size_y);

}

void person_GraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    rect = boundingRect();
    painter->setBrush(QColor::QColor(124,230,63));
    painter->drawRect(rect);


    if(true)
    {
        painter->setFont(QFont ("Courier", 8));
        painter->drawText(QRectF(x+0.1*size_x,y+0.1*size_y,size_x-0.1*size_x,size_y-0.1*size_y),person->name);
    }
    else
    {
        //image in the border
        painter->drawImage(QRectF(x,y,size_y/1.618,size_y),avatar);
        painter->drawRect(QRectF(x,y,size_y/1.618,size_y));
        //name and surname
        painter->drawRect(QRectF(x+size_y/1.618,y,size_x-size_y/1.618,size_y/2.618));
        painter->setFont(QFont ("Courier", 8));

        painter->drawText(QRectF(x+size_y/1.618+0.05*size_x,y,size_x-size_y/1.618-0.05*size_x,size_y/2.618),person->name);
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
