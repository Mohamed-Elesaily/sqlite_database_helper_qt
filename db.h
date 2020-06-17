#include<QString>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSql>
#include<QString>
#include<QVariant>
#include <QFile>
#ifndef DB_H
#define DB_H


class DB
{
    private:
        static DB* instance;
        DB();
        QSqlDatabase sql= QSqlDatabase::addDatabase("QSQLITE");

    public:
        // get instance of object
        static DB* getInstance();
        //create table when db.sqlite doesn't created it use in choosedir.cpp
        //you shouldn'y use it
        void createTable();
        //it is created automatic
        void setpath(QString path);


        // insert new file
        void insert(QString t);

        // delete file
        void deletefile(int id);

        //get file using id
        QString getFile(int id);
//        int count();
};

#endif // DB_H
