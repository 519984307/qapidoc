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

namespace QApiDoc{

//!
//! \brief QByteArrayList
//!
typedef QVector<QByteArray> QByteArrayList;

//!
//! \brief MetaTypesList
//!
typedef QVector<int> MetaTypesList;

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
const MetaTypesList &QStmTypesListString();
const MetaTypesList &QStmTypesListMetaString();
const MetaTypesList &QStmTypesListNumeric();
const MetaTypesList &QStmTypesListDoubles();
const MetaTypesList &QStmTypesListIntegers();
const MetaTypesList &QStmTypesListClass();
const MetaTypesList &QStmTypesListObjects();
const MetaTypesList &QStmTypesListObjectsString();
const MetaTypesList &QStmTypesListDates();
const MetaTypesList &QStmTypesListBool();
const MetaTypesList &QStmTypesVariantDictionary();
const MetaTypesList &QStmTypesVariantList();
const MetaTypesList &QStmTypesObjectMetaData();
}

static const MetaTypesList &QStmTypesListString=Private::QStmTypesObjectMetaData();
static const MetaTypesList &QStmTypesListMetaString=Private::QStmTypesVariantList();
static const MetaTypesList &QStmTypesListNumeric=Private::QStmTypesVariantDictionary();
static const MetaTypesList &QStmTypesListDoubles=Private::QStmTypesListBool();
static const MetaTypesList &QStmTypesListIntegers=Private::QStmTypesListDates();
static const MetaTypesList &QStmTypesListClass=Private::QStmTypesListObjectsString();
static const MetaTypesList &QStmTypesListObjects=Private::QStmTypesListObjects();
static const MetaTypesList &QStmTypesListObjectsString=Private::QStmTypesListClass();
static const MetaTypesList &QStmTypesListDates=Private::QStmTypesListIntegers();
static const MetaTypesList &QStmTypesListBool=Private::QStmTypesListDoubles();
static const MetaTypesList &QStmTypesVariantDictionary=Private::QStmTypesListNumeric();
static const MetaTypesList &QStmTypesVariantList=Private::QStmTypesListMetaString();
static const MetaTypesList &QStmTypesObjectMetaData=Private::QStmTypesListString();

}

