#pragma once

#include <QVariant>
#include <QVariantMap>
#include <QVariantHash>
#include <QVariantList>
#include <QStringList>
#include <QUuid>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "../src/qapidoc.h"

namespace QApiDoc {

class ObjectTest:public QApiDoc::ObjectMapper
{
    Q_OBJECT
public:
    Q_PROPERTY(bool v01 MEMBER v01)
    Q_PROPERTY(QVariant v02 MEMBER  v02)
    Q_PROPERTY(QDate v03 MEMBER  v03)
    Q_PROPERTY(QTime v04 MEMBER  v04)
    Q_PROPERTY(QDateTime v05 MEMBER  v05)
    Q_PROPERTY(int v06 MEMBER  v06)
    Q_PROPERTY(double v07 MEMBER v07)
    Q_PROPERTY(QString v08 MEMBER v08)
    Q_PROPERTY(QByteArray v09 MEMBER v09)
    Q_PROPERTY(QUuid v10 MEMBER v10)
    Q_PROPERTY(QUrl v11 MEMBER v11)
    Q_PROPERTY(QStringList v12 MEMBER v12)
    Q_PROPERTY(QVariantList v13 MEMBER v13)
    Q_PROPERTY(QVariantHash v14 MEMBER v14)
    Q_PROPERTY(QVariantMap v15 MEMBER v15)

    Q_INVOKABLE explicit ObjectTest(QObject*parent=nullptr):QApiDoc::ObjectMapper(parent)
    {
        Q_UNUSED(v01);
        Q_UNUSED(v02);
        Q_UNUSED(v03);
        Q_UNUSED(v04);
        Q_UNUSED(v05);
        Q_UNUSED(v06);
        Q_UNUSED(v07);
        Q_UNUSED(v08);
        Q_UNUSED(v09);
        Q_UNUSED(v10);
        Q_UNUSED(v11);
        Q_UNUSED(v12);
        Q_UNUSED(v13);
        Q_UNUSED(v14);
        Q_UNUSED(v15);
    }

    bool v01={};
    QVariant v02={};
    QDate v03={};
    QTime v04={};
    QDateTime v05={};
    int v06=0;
    double v07=0;
    QString v08={};
    QByteArray v09={};
    QUuid v10={};
    QUrl v11={};
    QStringList v12={};
    QVariantList v13={};
    QVariantHash v14={};
    QVariantMap v15={};
};

}

