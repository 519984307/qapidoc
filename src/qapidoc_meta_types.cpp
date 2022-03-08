#include "./qapidoc_meta_types.h"

Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListString, ({QMetaType_QString,QMetaType_QByteArray,QMetaType_QChar,QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListMetaString, ({QMetaType_QUrl, QMetaType_QUuid, QMetaType_QString, QMetaType_QByteArray, QMetaType_QChar, QMetaType_QBitArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListNumeric, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListDoubles, ({QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListIntegers, ({QMetaType_LongLong,QMetaType_Int,QMetaType_UInt,QMetaType_ULongLong,QMetaType_Double}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListClass, ({QMetaType_QUrl,QMetaType_QUuid,QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListObjects, ({QMetaType_QVariantMap,QMetaType_QVariantHash,QMetaType_QVariantList,QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListObjectsString, ({QMetaType_QString,QMetaType_QByteArray}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListDates, ({QMetaType_QDate,QMetaType_QDateTime,QMetaType_QTime}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesListBool, ({QMetaType_Bool}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesVariantDictionary, ({QMetaType_QVariantHash, QMetaType_QVariantMap}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesVariantList, ({QMetaType_QVariantList, QMetaType_QStringList}));
Q_GLOBAL_STATIC_WITH_ARGS(QMetaTypeUtil, staticQStmTypesObjectMetaData, ({QMetaType_QVariantHash, QMetaType_QVariantMap, QMetaType_QVariantList, QMetaType_QStringList}));

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

const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListString(){ return *staticQStmTypesListString; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListMetaString(){ return *staticQStmTypesListMetaString; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListNumeric(){ return *staticQStmTypesListNumeric; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListDoubles(){ return *staticQStmTypesListDoubles; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListIntegers(){ return *staticQStmTypesListIntegers; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListClass(){ return *staticQStmTypesListClass; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListObjects(){ return *staticQStmTypesListObjects; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListObjectsString(){ return *staticQStmTypesListObjectsString; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListDates(){ return *staticQStmTypesListDates; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesListBool(){ return *staticQStmTypesListBool; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesVariantDictionary(){ return *staticQStmTypesVariantDictionary; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesVariantList(){ return *staticQStmTypesVariantList; }
const QMetaTypeUtil &QMetaTypeUtil::QStmTypesObjectMetaData(){ return *staticQStmTypesObjectMetaData; }
