#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include"choosedir.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSql>
#include"db.h"
#include"string_manip.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DB* sql = sql->getInstance();
    DB* b= b->getInstance();
    b->setpath("db.sqlite");
    b->deletefile(1);
    qDebug()<< b->getFile(5);

   return a.exec();
}



