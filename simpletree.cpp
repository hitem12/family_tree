#include "simpletree.h"

SimpleTree::SimpleTree(qint16 id,QGraphicsScene* scene,sql_connect* database)
{
    scene1 = scene;
    // scene->clear();
    // scene->update();
    close_family_size = 0;
    p33 = new Person;
    p33->id = id;
    database->create_person(p33);
    gi_p33 = new person_GraphicItem;
    gi_p33->person = p33;
    gi_p33->x = -0.5*gi_p33->size_x;
    gi_p33->y = -0.5*gi_p33->size_y;
    scene->addItem(gi_p33);
    qDebug() <<(0 && p33->parents[1]);
 // create parends class
    if((p33->parents[0] && p33->parents[1]))
    {
        gi_parents = new person_GraphicItem[2];
        parents = new Person[2];

        parents->id = p33->parents[0];
        (parents+1)->id = p33->parents[1];
        database->create_person(parents);
        database->create_person(parents+1);
        gi_parents->person = parents;
        (gi_parents+1)->person = parents+1;
        (gi_parents+1)->x = -gi_p33->size_x;

        gi_parents->y = -dy;
        (gi_parents+1)->y = -dy;
        scene->addItem(gi_parents);
        scene->addItem(gi_parents+1);
    }

    if(p33->nr_children)
    {
        qint16 child;


        child =p33->nr_children;
        close_family_size = child;        


        person_table = new Person[child];




        //craete all child person class
        for(int i = 0; i<child; i++)
        {
            (person_table+i)->id = p33->children[i];
            qDebug() << (person_table+i)->id ;
            database->create_person(person_table+i);
        }
        close_family = new person_GraphicItem[child];

        // create all child graphicItem class
        for(int i = 0; i<=child; i++)
        {

            (close_family+i)->person = &person_table[i];


        }



        for (int i=0; i < child; i++)
        {
            (close_family+i)->x = -(0.5 * (dx+close_family->size_x) * child - 0.5*dx) + i * (dx+close_family->size_x);
            (close_family+i)->y = dy;
            scene->addItem(close_family+i);
        }


    }


    // delete p33;


}

SimpleTree::~SimpleTree()
{

    scene1->removeItem(gi_p33);


    if(close_family_size)
    {

        for (int i=0; i < close_family_size; i++)
        {

            scene1->removeItem(close_family+i);
            qDebug() << "usunalem" << i;

        }

       // delete[] close_family;
        delete[] person_table;


       // delete gi_p33;

    }
    delete p33;
}
