#ifndef QAPIDOC_ObjectTestUnit_H
#define QAPIDOC_ObjectTestUnit_H

#include "./qapidoc_test_unit.h"
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

namespace QApiDoc {

    class Q_APIDOC_ObjectTestUnit : public SDKGoogleTestUnit {
    public:
    };

    TEST_F(Q_APIDOC_ObjectTestUnit, checkMD5_MapToObjectObjectToMap)
    {
        ObjectTest object;

        auto values=object.clear().toHash();
        auto md5_1=this->toMd5(values);
        values[QStringLiteral("v01")] = true;
        values[QStringLiteral("v02")] = QVariant{"test"};
        values[QStringLiteral("v03")] = QDate::currentDate();
        values[QStringLiteral("v04")] = QTime::currentTime();
        values[QStringLiteral("v05")] = QDateTime::currentDateTime();
        values[QStringLiteral("v06")] = 98760;
        values[QStringLiteral("v07")] = 4587.12;
        values[QStringLiteral("v08")] = QUuid::createUuid().toString();
        values[QStringLiteral("v09")] = QUuid::createUuid().toByteArray();
        values[QStringLiteral("v10")] = QUuid::createUuid();
        values[QStringLiteral("v11")] = QUrl("http://localhost:8888");
        values[QStringLiteral("v12")] = QStringList{QUuid::createUuid().toString(), QUuid::createUuid().toString(), QUuid::createUuid().toString()};
        values[QStringLiteral("v13")] = QVariantList{QUuid::createUuid(), QUuid::createUuid(), QUuid::createUuid()};
        values[QStringLiteral("v14")] = QVariantHash{{QUuid::createUuid().toString(), QUuid::createUuid()}, {QUuid::createUuid().toString(), QUuid::createUuid()}};
        values[QStringLiteral("v15")] = QVariantMap{{QUuid::createUuid().toString(), QUuid::createUuid()}, {QUuid::createUuid().toString(), QUuid::createUuid()}};
        EXPECT_TRUE(object.load(values))<<"md5-check-A: not loaded values";
        auto md5_2=this->toMd5(object.toHash());
        EXPECT_TRUE(md5_1==md5_2)<<"check-B: invalid md5";
    }
}


#endif // ObjectTestUnit_H
