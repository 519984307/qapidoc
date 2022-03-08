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

    explicit SDKGoogleTest();

    virtual bool clear();

    virtual QStringList arguments();

    static const QByteArray toMd5(const QVariant&v);

    static const QVariant toVar(const QVariant&v);

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
