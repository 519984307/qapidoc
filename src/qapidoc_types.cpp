#include "./qapidoc_types.h"
#include <QCoreApplication>

namespace QApiDoc{

Q_GLOBAL_STATIC_WITH_ARGS(QByteArrayList, static_object_ignore_methods,({"destroyed", "objectName", "objectNameChanged", "deleteLater", "_q_reregisterTimers"}));


Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQMetaTypeUtilObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

int qTypeId(const QVariant &v)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return v.typeId();
#else
    return v.type();
#endif
}

int qTypeId(const QMetaProperty &v)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return v.typeId();
#else
    return v.type();
#endif
}

bool qIsNumeric(const QVariant &v)
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

const QByteArrayList &object_ignore_methods()
{
    return *static_object_ignore_methods;
}

namespace Private {
const MetaTypesList &QMetaTypeUtilString(){ return *staticQMetaTypeUtilString; }
const MetaTypesList &QMetaTypeUtilMetaString(){ return *staticQMetaTypeUtilMetaString; }
const MetaTypesList &QMetaTypeUtilNumeric(){ return *staticQMetaTypeUtilNumeric; }
const MetaTypesList &QMetaTypeUtilDoubles(){ return *staticQMetaTypeUtilDoubles; }
const MetaTypesList &QMetaTypeUtilIntegers(){ return *staticQMetaTypeUtilIntegers; }
const MetaTypesList &QMetaTypeUtilClass(){ return *staticQMetaTypeUtilClass; }
const MetaTypesList &QMetaTypeUtilObjects(){ return *staticQMetaTypeUtilObjects; }
const MetaTypesList &QMetaTypeUtilObjectsString(){ return *staticQMetaTypeUtilObjectsString; }
const MetaTypesList &QMetaTypeUtilDates(){ return *staticQMetaTypeUtilDates; }
const MetaTypesList &QMetaTypeUtilBool(){ return *staticQMetaTypeUtilBool; }
const MetaTypesList &QMetaTypeUtilVariantDictionary(){ return *staticQMetaTypeUtilVariantDictionary; }
const MetaTypesList &QMetaTypeUtilVariantList(){ return *staticQMetaTypeUtilVariantList; }
const MetaTypesList &QMetaTypeUtilObjectMetaData(){ return *staticQMetaTypeUtilObjectMetaData; }
}


}


