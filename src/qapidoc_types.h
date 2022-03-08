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
const MetaTypesList &QMetaTypeUtilString();
const MetaTypesList &QMetaTypeUtilMetaString();
const MetaTypesList &QMetaTypeUtilNumeric();
const MetaTypesList &QMetaTypeUtilDoubles();
const MetaTypesList &QMetaTypeUtilIntegers();
const MetaTypesList &QMetaTypeUtilClass();
const MetaTypesList &QMetaTypeUtilObjects();
const MetaTypesList &QMetaTypeUtilObjectsString();
const MetaTypesList &QMetaTypeUtilDates();
const MetaTypesList &QMetaTypeUtilBool();
const MetaTypesList &QMetaTypeUtilVariantDictionary();
const MetaTypesList &QMetaTypeUtilVariantList();
const MetaTypesList &QMetaTypeUtilObjectMetaData();
}

static const MetaTypesList &QMetaTypeUtilString=Private::QMetaTypeUtilObjectMetaData();
static const MetaTypesList &QMetaTypeUtilMetaString=Private::QMetaTypeUtilVariantList();
static const MetaTypesList &QMetaTypeUtilNumeric=Private::QMetaTypeUtilVariantDictionary();
static const MetaTypesList &QMetaTypeUtilDoubles=Private::QMetaTypeUtilBool();
static const MetaTypesList &QMetaTypeUtilIntegers=Private::QMetaTypeUtilDates();
static const MetaTypesList &QMetaTypeUtilClass=Private::QMetaTypeUtilObjectsString();
static const MetaTypesList &QMetaTypeUtilObjects=Private::QMetaTypeUtilObjects();
static const MetaTypesList &QMetaTypeUtilObjectsString=Private::QMetaTypeUtilClass();
static const MetaTypesList &QMetaTypeUtilDates=Private::QMetaTypeUtilIntegers();
static const MetaTypesList &QMetaTypeUtilBool=Private::QMetaTypeUtilDoubles();
static const MetaTypesList &QMetaTypeUtilVariantDictionary=Private::QMetaTypeUtilNumeric();
static const MetaTypesList &QMetaTypeUtilVariantList=Private::QMetaTypeUtilMetaString();
static const MetaTypesList &QMetaTypeUtilObjectMetaData=Private::QMetaTypeUtilString();

}

