#include "./qapidoc_types.h"
#include <QCoreApplication>

namespace QApiDoc{

Q_GLOBAL_STATIC_WITH_ARGS(QByteArrayList, static_object_ignore_methods,({"destroyed", "objectName", "objectNameChanged", "deleteLater", "_q_reregisterTimers"}));


Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesListBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(MetaTypesList, staticQStmTypesObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

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
const MetaTypesList &QStmTypesListString(){ return *staticQStmTypesListString; }
const MetaTypesList &QStmTypesListMetaString(){ return *staticQStmTypesListMetaString; }
const MetaTypesList &QStmTypesListNumeric(){ return *staticQStmTypesListNumeric; }
const MetaTypesList &QStmTypesListDoubles(){ return *staticQStmTypesListDoubles; }
const MetaTypesList &QStmTypesListIntegers(){ return *staticQStmTypesListIntegers; }
const MetaTypesList &QStmTypesListClass(){ return *staticQStmTypesListClass; }
const MetaTypesList &QStmTypesListObjects(){ return *staticQStmTypesListObjects; }
const MetaTypesList &QStmTypesListObjectsString(){ return *staticQStmTypesListObjectsString; }
const MetaTypesList &QStmTypesListDates(){ return *staticQStmTypesListDates; }
const MetaTypesList &QStmTypesListBool(){ return *staticQStmTypesListBool; }
const MetaTypesList &QStmTypesVariantDictionary(){ return *staticQStmTypesVariantDictionary; }
const MetaTypesList &QStmTypesVariantList(){ return *staticQStmTypesVariantList; }
const MetaTypesList &QStmTypesObjectMetaData(){ return *staticQStmTypesObjectMetaData; }
}


}


