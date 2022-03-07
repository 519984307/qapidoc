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

        auto v1=object.clear().toHash();
        v1[QStringLiteral("v01")] = true;
        v1[QStringLiteral("v02")] = QVariant{"test"};
        v1[QStringLiteral("v03")] = QDate::currentDate();
        v1[QStringLiteral("v04")] = QTime::currentTime();
        v1[QStringLiteral("v05")] = QDateTime::currentDateTime();
        v1[QStringLiteral("v06")] = int(98760);
        v1[QStringLiteral("v07")] = double(4587.12);
        v1[QStringLiteral("v08")] = QUuid::createUuid().toString();
        v1[QStringLiteral("v09")] = QUuid::createUuid().toByteArray();
        v1[QStringLiteral("v10")] = QUuid::createUuid();
        v1[QStringLiteral("v11")] = QUrl("http://localhost:8888");
        v1[QStringLiteral("v12")] = QStringList{QUuid::createUuid().toString(), QUuid::createUuid().toString(), QUuid::createUuid().toString()};
        v1[QStringLiteral("v13")] = QVariantList{QUuid::createUuid(), QUuid::createUuid(), QUuid::createUuid()};
        v1[QStringLiteral("v14")] = QVariantHash{{QUuid::createUuid().toString(), QUuid::createUuid()}, {QUuid::createUuid().toString(), QUuid::createUuid()}};
        v1[QStringLiteral("v15")] = QVariantMap{{QUuid::createUuid().toString(), QUuid::createUuid()}, {QUuid::createUuid().toString(), QUuid::createUuid()}};
        auto md5_1=this->toMd5(v1);
        EXPECT_TRUE(object.load(v1))<<"md5-check-A: not loaded values";
        auto v2=object.toHash();
        auto md5_2=this->toMd5(v2);
        EXPECT_TRUE(md5_1==md5_2)<<"check-B: invalid md5";
    }
}


#endif // ObjectTestUnit_H
