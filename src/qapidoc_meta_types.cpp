#include "./qapidoc_meta_types.h"

namespace QApiDoc{

Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQMetaTypeUtilObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

QMetaTypeUtil::QMetaTypeUtil(const QVector<int> &list):QVector<int>{list}
{

}

QMetaTypeUtil::~QMetaTypeUtil()
{

}


int QMetaTypeUtil::qTypeId(const QVariant &v)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return v.typeId();
#else
    return v.type();
#endif
}

int QMetaTypeUtil::qTypeId(const QMetaProperty &v)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return v.typeId();
#else
    return v.type();
#endif
}

bool QMetaTypeUtil::qIsNumeric(const QVariant &v)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    auto __qtype=v.typeId();
#else
    auto __qtype=v.type();
#endif
    switch (__qtype) {
    case QMetaType_LongLong:
    case QMetaType_Int:
    case QMetaType_UInt:
    case QMetaType_ULongLong:
    case QMetaType_Double:
        return true;
    default:
        if(v.toDouble()>0)
            return true;
        return false;
    }
}

const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilString(){ return *staticQMetaTypeUtilString; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilMetaString(){ return *staticQMetaTypeUtilMetaString; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilNumeric(){ return *staticQMetaTypeUtilNumeric; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilDoubles(){ return *staticQMetaTypeUtilDoubles; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilIntegers(){ return *staticQMetaTypeUtilIntegers; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilClass(){ return *staticQMetaTypeUtilClass; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilObjects(){ return *staticQMetaTypeUtilObjects; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilObjectsString(){ return *staticQMetaTypeUtilObjectsString; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilDates(){ return *staticQMetaTypeUtilDates; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilBool(){ return *staticQMetaTypeUtilBool; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilVariantDictionary(){ return *staticQMetaTypeUtilVariantDictionary; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilVariantList(){ return *staticQMetaTypeUtilVariantList; }
const QMetaTypeUtil &QMetaTypeUtil::QMetaTypeUtilObjectMetaData(){ return *staticQMetaTypeUtilObjectMetaData; }

}


