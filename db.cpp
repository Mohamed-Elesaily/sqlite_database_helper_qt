#include "db.h"
#include<QDebug>
DB* DB::instance=nullptr;
DB::DB()
{

}
DB* DB::getInstance(){
    if(instance == nullptr){
        instance = new DB();


    }
 return instance;
}
void DB::createTable(){
    QSqlQuery query;
   if(DB::sql.open()){
       query.exec("CREATE TABLE FILE(ID INTEGER PRIMARY KEY AUTOINCREMENT,FILENAME TEXT);");
   }
}
void DB::setpath(QString path){
  DB::sql.setDatabaseName(path);

}
void DB::insert(QString t){
        QSqlQuery query;
        if(DB::sql.open()){
              query.prepare("INSERT INTO FILE (FILENAME)VALUES (?);");
              query.addBindValue(t);
              query.exec();

  }

}
void DB::deletefile(int id){
    QSqlQuery query;
     if(DB::sql.open()){
    query.prepare("DELETE FROM FILE WHERE ID=?" );
    query.addBindValue(id);
    query.exec();
}
}
QString DB::getFile(int id){
    QSqlQuery query;
       QString file;
       if(DB::sql.open()){
       query.exec("SELECT FILENAME FROM FILE WHERE ID=?");
       query.addBindValue(id);
       query.exec();
      if( query.next() )
       {
            file = query.value(0).toString();
       }
       }
       return file;
}
//int DB::count(){
//    QSqlQuery qry_ID;
////    QSqlQuery query;
//    int num=0;
//       if(DB::sql.open()){

//           qry_ID.exec("SELECT FILENAME,MAX(ID) FROM FILE");

//           qry_ID.next();
//           qDebug()<< qry_ID.value(0).toInt();


//       }
//return num;
//}
