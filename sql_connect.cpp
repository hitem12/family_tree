#include "sql_connect.h"

sql_connect::sql_connect()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("rodzinka");
    db.setUserName("root");
    db.setPassword("");

    //bool ok = db.open();
    if (db.open())
    {
        //ui->info_label->setText("połączono");
        qDebug() << "rodzinka connect";
    }
    else
    {
       // ui->info_label->setText("ERROR");
        qDebug() <<"SQL server connect ERROR";

    }

}

int sql_connect::take_list(QTableWidget* table)
{   int number;
    //query.exec("SELECT Imiona, Nazwisko, id FROM osoby ");
    QSqlQuery query;
    if (query.exec("SELECT Imiona, Nazwisko, id FROM osoby "))
    {
            qint16 i = 0;
            number = query.size();
            //qDebug() << number;
            table->setRowCount(number);
            while (query.next())
            {

                QString name =  query.value(0).toString() + ' ' + query.value(1).toString();
                QString id = query.value(2).toString();

                table->setItem(i,1,new QTableWidgetItem(name));
                table->setItem(i,0,new QTableWidgetItem(id));
                i++;
            }
    }
    else
    {
        qDebug() << "query Error";
    }
    return number;

}

void sql_connect::create_person(Person* person)
{
    //take parents

   // qDebug() << id_c;
    QSqlQuery query_m;
    if (query_m.exec(QString("SELECT id_matki, id_ojca FROM dzieci WHERE id_dziecka=%1").arg(person->id)))
    {

        while (query_m.next())
        {
         person->parents[0] = query_m.value(0).toInt();
         person->parents[1] = query_m.value(1).toInt();
        }
    }
     else
     { qDebug() << "Error create_person parents"; }

    //take children
    if (query_m.exec(QString("SELECT id_dziecka FROM dzieci WHERE id_ojca= %1 OR id_matki= %1").arg(person->id,person->id)))
    {   int i =0;
        person->children = new qint16[query_m.size()];
        while (query_m.next())
        {
            person->children[i] = query_m.value(0).toInt();
           i++;
         }

        person->nr_children = i;
        //take gender
        if (query_m.exec(QString("SELECT plec FROM osoby WHERE id=%1").arg(person->id)))
        {
            while(query_m.next())
            {
            person->gender =  query_m.value(0).toInt();
            }

        }
        else
        { qDebug() << "Error"; }
    }
    else
    { qDebug() << "Error"; }

    // take name
    person->name = take_name(person->id);


    //take spouse
        if(person->gender == 0)
        {
            if (query_m.exec(QString("SELECT id_meza FROM malzenstwa WHERE id_zony= %1").arg(person->id)))
             {
                int i =0;
                person->spouse = new qint16[query_m.size()];
                while (query_m.next())
                {
                    person->spouse[i] = query_m.value(0).toInt();
                    i++;
                }
                person->nr_spous = i;

            }
            else
                { qDebug() << "Error"; }
        }
        else
        {
            if (query_m.exec(QString("SELECT id_zony FROM malzenstwa WHERE id_meza= %1").arg(person->id)))
             {
                int i =0;
                person->spouse = new qint16[query_m.size()];
                while (query_m.next())
                {
                    person->spouse[i] = query_m.value(0).toInt();
                    i++;
                }
                person->nr_spous = i;
            }
            else
                { qDebug() << "Error"; }
        }


}

QString sql_connect::take_name(qint16 id)
{
    QString name;
    QSqlQuery query_m;
    if (query_m.exec(QString("SELECT Imiona, Nazwisko FROM osoby WHERE id=%1").arg(id)))
    {
        while(query_m.next())
        {
        name =  query_m.value(0).toString() + ' ' + query_m.value(1).toString();
        }
        return name;
    }
    else
    { qDebug() << "Error"; return "Error";}
}


