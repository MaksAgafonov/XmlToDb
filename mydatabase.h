#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QSqlError>

class MyDataBase
{
    QSqlDatabase dbase;
    QSqlQuery a_query;
    QString ntable;
    bool b;

    bool dbInit(QString & str);

    bool createTable(QString &table_name);

public:

    MyDataBase(QString & DBname, QString & tableName);
    bool insertTable(QVector<QString> str);

};

#endif // MYDATABASE_H
