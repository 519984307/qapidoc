#pragma once

#include <QObject>
#include <QMap>
#include <QVariant>
#include <QString>
#include <QMetaProperty>
#include <QTemporaryFile>
#include "./qapidoc_global.h"

//!
//! \brief The QMetaTypeList class
//!
//! List for QMetaType
class Q_API_DOC_EXPORT QMetaTypeList:public QVector<int>
{
public:
    //!
    //! \brief QMetaTypeList
    //!
    explicit QMetaTypeList();

    //!
    //! \brief QMetaTypeList
    //!
    explicit QMetaTypeList(const QVector<int>&list);

    //!
    //! \brief ~QMetaTypeList
    //!
    virtual ~QMetaTypeList();
};

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
//! \brief Consts to QMetaType
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
const QMetaTypeList &QStmTypesListString();
const QMetaTypeList &QStmTypesListMetaString();
const QMetaTypeList &QStmTypesListNumeric();
const QMetaTypeList &QStmTypesListDoubles();
const QMetaTypeList &QStmTypesListIntegers();
const QMetaTypeList &QStmTypesListClass();
const QMetaTypeList &QStmTypesListObjects();
const QMetaTypeList &QStmTypesListObjectsString();
const QMetaTypeList &QStmTypesListDates();
const QMetaTypeList &QStmTypesListBool();
const QMetaTypeList &QStmTypesVariantDictionary();
const QMetaTypeList &QStmTypesVariantList();
const QMetaTypeList &QStmTypesObjectMetaData();
}


static const QMetaTypeList &QStmTypesListString=Private::QStmTypesObjectMetaData();
static const QMetaTypeList &QStmTypesListMetaString=Private::QStmTypesVariantList();
static const QMetaTypeList &QStmTypesListNumeric=Private::QStmTypesVariantDictionary();
static const QMetaTypeList &QStmTypesListDoubles=Private::QStmTypesListBool();
static const QMetaTypeList &QStmTypesListIntegers=Private::QStmTypesListDates();
static const QMetaTypeList &QStmTypesListClass=Private::QStmTypesListObjectsString();
static const QMetaTypeList &QStmTypesListObjects=Private::QStmTypesListObjects();
static const QMetaTypeList &QStmTypesListObjectsString=Private::QStmTypesListClass();
static const QMetaTypeList &QStmTypesListDates=Private::QStmTypesListIntegers();
static const QMetaTypeList &QStmTypesListBool=Private::QStmTypesListDoubles();
static const QMetaTypeList &QStmTypesVariantDictionary=Private::QStmTypesListNumeric();
static const QMetaTypeList &QStmTypesVariantList=Private::QStmTypesListMetaString();
static const QMetaTypeList &QStmTypesObjectMetaData=Private::QStmTypesListString();
