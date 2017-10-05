#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("rodzinka");
    db.setUserName("root");
    db.setPassword("");

    //bool ok = db.open();
    if (db.open())
    {
        ui->info_label->setText("połączono");
        qDebug() << "rodzinka connect";
    }
    else
    {
        ui->info_label->setText("ERROR");
        qDebug() <<"SQL server connect ERROR";

    }
    */
    database = new sql_connect();


    ui->family_list->setColumnCount(2);
    ui->family_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->family_list->setColumnWidth(1,200);
    ui->family_list->setColumnWidth(0,30);


    last_record_id = database->take_list(ui->family_list);
    last_record_id = ui->family_list->item(last_record_id-1,0)->text().toInt() ;     //take data from sql and retrun higher id






   // ui->family_list->hideColumn(0);
    ui->family_list->verticalHeader()->hide();
    ui->family_list->horizontalHeader()->hide();


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



    scene->setBackgroundBrush(Qt::gray);

    //close_family->setPos(100,200);
    st_view = new SimpleTree(33,scene,database);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete database;
    delete st_view;
}

void MainWindow::on_family_list_clicked(const QModelIndex &index)
{

   ui->family_list->currentItem()->setBackgroundColor(Qt::green);
   ui->family_list->currentItem()->setTextColor(Qt::white);

   delete st_view;
   st_view = new SimpleTree((ui->family_list->item(ui->family_list->currentRow(),0)->text().toInt()),scene,database);
  // qDebug() << ui->family_list->item(ui->family_list->currentRow(),0)->text().toInt();// wypisanie numeru id

}

void MainWindow::on_pushButton_clicked()
{
   scene->removeItem(st_view->close_family);

}
