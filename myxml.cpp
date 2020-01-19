#include "myxml.h"
#include <QDateTime>

MyXml::MyXml(QString &fname){
    QFile inputFile(fname);
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

    if(inputFile.isOpen())
        qDebug() <<fname << " open";

    QTextStream inputStream(&inputFile);

    QDomDocument xml;
    xml.setContent(&inputFile);

    heder = xml.elementsByTagName("zglv").at(0).firstChildElement().text();


    list = xml.elementsByTagName("zap");
    size = list.size();
}

bool MyXml::insertDB(MyDataBase &db){
    QDomNode n;

    for(int i = 0; i < list.size(); ++i){
        n = list.at(i);
        db.insertTable({n.firstChildElement("KOD_OK").text(),
                        n.firstChildElement("OKRNAME").text(),
                        n.firstChildElement("DATEBEG").text(),
                        n.firstChildElement("DATEEND").text()});
    }
    qDebug()<< "upload completed";

}

bool MyXml::createExcelOrder(){
    QXlsx::Document xlsx;
    xlsx.write("A1", "Название: ");
    xlsx.write("C1", heder);
    xlsx.write("A2", "Количество записей");
    xlsx.write("C2", size);
    xlsx.write("A3", "Время создания");
    xlsx.write("C3", QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    xlsx.saveAs("XmlOrder.xlsx");

    qDebug()<< "report created successfully";
}
