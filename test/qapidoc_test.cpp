#include "./qapidoc_test.h"
#include "./../src/qapidoc_meta_types.h"

namespace QApiDoc {

SDKGoogleTest::SDKGoogleTest()
{
    QLocale::setDefault(QLocale(QLocale::Portuguese, QLocale::Brazil));
}

bool SDKGoogleTest::clear()
{
    return true;
}

QStringList SDKGoogleTest::arguments()const
{
    return qApp->arguments();
}

const QByteArray SDKGoogleTest::toMd5(const QVariant &v)
{
    QByteArray bytes;
    if(!QMetaTypeUtilObjectMetaData.contains(qTypeId(v)))
        bytes=v.toByteArray();
    else
        bytes=QJsonDocument::fromVariant(v).toJson(QJsonDocument::Compact);
    return QCryptographicHash::hash(bytes, QCryptographicHash::Md5).toHex();

}

const QVariant SDKGoogleTest::toVar(const QVariant &v)
{
    return QJsonDocument::fromJson(v.toByteArray()).toVariant();
}

}
