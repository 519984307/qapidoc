#pragma once

#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDebug>
#include <QHash>
#include <QStringList>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLocale>
#include <QJsonDocument>
#include <gtest/gtest.h>
#include "../src/qapidoc.h"
#include "./qapidoc_object_test.h"


namespace QApiDoc {

class SDKGoogleTest : public testing::Test{
public:

    explicit SDKGoogleTest()
    {
        QLocale::setDefault(QLocale(QLocale::Portuguese, QLocale::Brazil));
    }

    virtual bool clear()
    {
        return true;
    }

    virtual QStringList arguments()
    {
        return qApp->arguments();
    }

    static const QByteArray toMd5(const QVariant&v)
    {
        QByteArray bytes;
        switch (qTypeId(v)) {
        case QMetaType_QStringList:
        case QMetaType_QVariantList:
        case QMetaType_QVariantHash:
        case QMetaType_QVariantMap:
            bytes=QJsonDocument::fromVariant(v).toJson(QJsonDocument::Compact);
            break;
        default:
            bytes=v.toByteArray();
        }
        return QCryptographicHash::hash(bytes, QCryptographicHash::Md5).toHex();

    }

    static QVariant toVar(const QVariant&v)
    {
        return QJsonDocument::fromJson(v.toByteArray()).toVariant();
    }

    static void SetUpTestCase()
    {
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    static void TearDownTestCase()
    {
    }

public:

};

}
