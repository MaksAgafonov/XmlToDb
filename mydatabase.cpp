#include "mydatabase.h"


bool MyDataBase::dbInit(QString & str){
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(str+".sqlite");

    if(dbase.open()){
        a_query = QSqlQuery(dbase);
    }else{
        qDebug() << "database not open";
    }
}

bool MyDataBase::createTable(QString &table_name){
    // DDL query
    ntable = table_name;
    if (a_query.exec("CREATE TABLE "+table_name+" (KODOK  integer PRIMARY KEY NOT NULL, "
                     "OKRNAME VARCHAR(255), "
                     "DATEBEG VARCHAR(255), "
                     "DATEEND VARCHAR(255)"
                     ");")) {
        return true;
    }else{
        qDebug () <<a_query.lastError().text();
        qDebug() << "error create table";
        return false;
    }

}

MyDataBase::MyDataBase(QString &DBname, QString &tableName){
    QString nameDB = "okr4";
    dbInit(DBname);
    QString nameTable("okrug");
    createTable(tableName);
}

bool MyDataBase::insertTable(QVector<QString> strInsert){
    // DML

    QString str_insert = "INSERT INTO "+ntable+"(KODOK, OKRNAME, DATEBEG, DATEEND) "
                                               "VALUES ("+strInsert.at(0)+", '"+strInsert.at(1)+"', '"+strInsert.at(2)+"', '"+strInsert.at(3)+"');";
    b = a_query.exec(str_insert);

    if (!b) {
        qDebug () <<a_query.lastError().text();
    }
}
