#ifndef MYXML_H
#define MYXML_H
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include "mydatabase.h"
#include "xlsxdocument.h"
class MyXml
{
    QDomNodeList list;
    int size = 0;
    QString heder = "";
    QString data = "";

public:
    MyXml(QString & fname);

    bool insertDB(MyDataBase & db);

    bool createExcelOrder();
};

#endif // MYXML_H
