#pragma once

#include <QObject>
#include <QList>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QVariant>
#include <QBitArray>
#include <QMetaProperty>
#include <QVariantMap>
#include <QVariantList>
#include <QVariantHash>
#include <QStringList>
#include <QList>
#include <QVector>
#include <QFlags>
#include <QMutex>
#include <QMutexLocker>

namespace QApiDoc{

//!
//! \brief QByteArrayList
//!
typedef QVector<QByteArray> QByteArrayList;

//!
//! \brief QStmVTypesList
//!
typedef QVector<int> QStmVTypesList;

//!
//! \brief qTypeId
//! \param v
//! \return
//!
int qTypeId(const QVariant&v);

//!
//! \brief qTypeId
//! \param p
//! \return
//!
int qTypeId(const QMetaProperty&p);

//!
//! \brief qIsNumeric
//! \param v
//! \return
//!
bool qIsNumeric(const QVariant&v);


//!
//! \brief object_ignore_methods
//! \return
//!
const QByteArrayList &object_ignore_methods();

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
typedef QMutexLocker<QMutex> QMutexLOCKER;
typedef QMetaType::Type QMetaTypeType;
#else
typedef QMutexLocker QMutexLOCKER;
typedef QVariant::Type QMetaTypeType;
#endif
static const int QMetaType_UnknownType  = QMetaType::UnknownType   ;
static const int QMetaType_Void         = QMetaType::Void          ;
static const int QMetaType_Bool         = QMetaType::Bool          ;
static const int QMetaType_User         = QMetaType::User          ;
static const int QMetaType_Double       = QMetaType::Double        ;
static const int QMetaType_Int          = QMetaType::Int           ;
static const int QMetaType_UInt         = QMetaType::UInt          ;
static const int QMetaType_LongLong     = QMetaType::LongLong      ;
static const int QMetaType_ULongLong    = QMetaType::ULongLong     ;
static const int QMetaType_QBitArray    = QMetaType::QBitArray     ;
static const int QMetaType_QByteArray   = QMetaType::QByteArray    ;
static const int QMetaType_QChar        = QMetaType::QChar         ;
static const int QMetaType_QDate        = QMetaType::QDate         ;
static const int QMetaType_QDateTime    = QMetaType::QDateTime     ;
static const int QMetaType_QString      = QMetaType::QString       ;
static const int QMetaType_QStringList  = QMetaType::QStringList   ;
static const int QMetaType_QTime        = QMetaType::QTime         ;
static const int QMetaType_QUrl         = QMetaType::QUrl          ;
static const int QMetaType_QUuid        = QMetaType::QUuid         ;
static const int QMetaType_QVariantHash = QMetaType::QVariantHash  ;
static const int QMetaType_QVariantList = QMetaType::QVariantList  ;
static const int QMetaType_QVariantMap  = QMetaType::QVariantMap   ;
static const int QMetaType_CustomType   = 65538                    ;

namespace Private {
const QStmVTypesList &QStmTypesListString();
const QStmVTypesList &QStmTypesListMetaString();
const QStmVTypesList &QStmTypesListNumeric();
const QStmVTypesList &QStmTypesListDoubles();
const QStmVTypesList &QStmTypesListIntegers();
const QStmVTypesList &QStmTypesListClass();
const QStmVTypesList &QStmTypesListObjects();
const QStmVTypesList &QStmTypesListObjectsString();
const QStmVTypesList &QStmTypesListDates();
const QStmVTypesList &QStmTypesListBool();
const QStmVTypesList &QStmTypesVariantDictionary();
const QStmVTypesList &QStmTypesVariantList();
const QStmVTypesList &QStmTypesObjectMetaData();
}

static const QStmVTypesList &QStmTypesListString=Private::QStmTypesObjectMetaData();
static const QStmVTypesList &QStmTypesListMetaString=Private::QStmTypesVariantList();
static const QStmVTypesList &QStmTypesListNumeric=Private::QStmTypesVariantDictionary();
static const QStmVTypesList &QStmTypesListDoubles=Private::QStmTypesListBool();
static const QStmVTypesList &QStmTypesListIntegers=Private::QStmTypesListDates();
static const QStmVTypesList &QStmTypesListClass=Private::QStmTypesListObjectsString();
static const QStmVTypesList &QStmTypesListObjects=Private::QStmTypesListObjects();
static const QStmVTypesList &QStmTypesListObjectsString=Private::QStmTypesListClass();
static const QStmVTypesList &QStmTypesListDates=Private::QStmTypesListIntegers();
static const QStmVTypesList &QStmTypesListBool=Private::QStmTypesListDoubles();
static const QStmVTypesList &QStmTypesVariantDictionary=Private::QStmTypesListNumeric();
static const QStmVTypesList &QStmTypesVariantList=Private::QStmTypesListMetaString();
static const QStmVTypesList &QStmTypesObjectMetaData=Private::QStmTypesListString();

}

