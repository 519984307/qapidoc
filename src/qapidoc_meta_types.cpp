#include "./qapidoc_meta_types.h"

Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesListBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeList, staticQStmTypesObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

QMetaTypeList::QMetaTypeList(const QVector<int> &list):QVector<int>{list}
{

}

QMetaTypeList::~QMetaTypeList()
{

}


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

namespace Private {
const QMetaTypeList &QStmTypesListString(){ return *staticQStmTypesListString; }
const QMetaTypeList &QStmTypesListMetaString(){ return *staticQStmTypesListMetaString; }
const QMetaTypeList &QStmTypesListNumeric(){ return *staticQStmTypesListNumeric; }
const QMetaTypeList &QStmTypesListDoubles(){ return *staticQStmTypesListDoubles; }
const QMetaTypeList &QStmTypesListIntegers(){ return *staticQStmTypesListIntegers; }
const QMetaTypeList &QStmTypesListClass(){ return *staticQStmTypesListClass; }
const QMetaTypeList &QStmTypesListObjects(){ return *staticQStmTypesListObjects; }
const QMetaTypeList &QStmTypesListObjectsString(){ return *staticQStmTypesListObjectsString; }
const QMetaTypeList &QStmTypesListDates(){ return *staticQStmTypesListDates; }
const QMetaTypeList &QStmTypesListBool(){ return *staticQStmTypesListBool; }
const QMetaTypeList &QStmTypesVariantDictionary(){ return *staticQStmTypesVariantDictionary; }
const QMetaTypeList &QStmTypesVariantList(){ return *staticQStmTypesVariantList; }
const QMetaTypeList &QStmTypesObjectMetaData(){ return *staticQStmTypesObjectMetaData; }
}
