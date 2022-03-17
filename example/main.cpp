#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QJsonDocument>
#include "./example_object.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //documented class
    NotationExample::PersonCrud personCrud;

    //export to QVariantHash
    auto documentation=personCrud.documentation().toHash();

    //export to Json
    qDebug()<<QJsonDocument::fromVariant(documentation).toJson();

    return QProcess::NormalExit;
}
