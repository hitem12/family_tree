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
            scene->addItem(close_family+i);


        }


    }


    delete p33;


}

SimpleTree::~SimpleTree()
{
    if(close_family_size)
    {
       /* for (int i=0; i < close_family_size; i++)
        {
            qDebug()<< "usuwam" ;
            scene1->removeItem(close_family+i);

        }
*/
        //delete[] close_family;
       // delete[] person_table;

    }

}
