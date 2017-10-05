#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QListWidget>

#include <QGraphicsScene>
#include "simpletree.h"
#include "sql_connect.h"
#include "person.h"
#include "person_graphicitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  //  Person* person;

private slots:
    void on_family_list_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


   // QSqlDatabase db;

    sql_connect *database;
    QGraphicsScene *scene;
    SimpleTree* st_view;

    qint16 last_record_id;

};


#endif // MAINWINDOW_H
