#include "./qapidoc_types.h"
#include <QCoreApplication>

namespace QApiDoc{

Q_GLOBAL_STATIC_WITH_ARGS(QByteArrayList, static_object_ignore_methods,({"destroyed", "objectName", "objectNameChanged", "deleteLater", "_q_reregisterTimers"}));


Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesListBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QStmVTypesList, staticQStmTypesObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

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
const QStmVTypesList &QStmTypesListString(){ return *staticQStmTypesListString; }
const QStmVTypesList &QStmTypesListMetaString(){ return *staticQStmTypesListMetaString; }
const QStmVTypesList &QStmTypesListNumeric(){ return *staticQStmTypesListNumeric; }
const QStmVTypesList &QStmTypesListDoubles(){ return *staticQStmTypesListDoubles; }
const QStmVTypesList &QStmTypesListIntegers(){ return *staticQStmTypesListIntegers; }
const QStmVTypesList &QStmTypesListClass(){ return *staticQStmTypesListClass; }
const QStmVTypesList &QStmTypesListObjects(){ return *staticQStmTypesListObjects; }
const QStmVTypesList &QStmTypesListObjectsString(){ return *staticQStmTypesListObjectsString; }
const QStmVTypesList &QStmTypesListDates(){ return *staticQStmTypesListDates; }
const QStmVTypesList &QStmTypesListBool(){ return *staticQStmTypesListBool; }
const QStmVTypesList &QStmTypesVariantDictionary(){ return *staticQStmTypesVariantDictionary; }
const QStmVTypesList &QStmTypesVariantList(){ return *staticQStmTypesVariantList; }
const QStmVTypesList &QStmTypesObjectMetaData(){ return *staticQStmTypesObjectMetaData; }
}


}


