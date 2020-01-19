#include <iostream>
#include "myxml.h"
#include "mydatabase.h"

#include <QString>
#include <QTextStream>
//QTextStream cout(stdout);
QTextStream cin(stdin);


int main()
{

    QString fname, dbname, tablename;
        std::cout << "Enter path to XML-file: ";
        fname = cin.readLine(); //  =  "C:\F015.xml"
        MyXml xml(fname);

        std::cout<<"Enter name database: ";
        dbname = cin.readLine(); //

        std::cout<<"Enter name table: ";
        tablename = cin.readLine(); //

        MyDataBase db(dbname,tablename);

        xml.insertDB(db);
        xml.createExcelOrder();

    return 0;
}
