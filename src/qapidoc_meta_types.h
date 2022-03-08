#pragma once

#include <QObject>
#include <QVariant>
#include <QVariantHash>
#include <QString>
#include <QMetaProperty>
#include <QTemporaryFile>
#include "./qapidoc_global.h"


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

//!
//! \brief The QMetaTypeUtil class
//!
//! List for QMetaType
class Q_API_DOC_EXPORT QMetaTypeUtil:public QVector<int>
{
public:
    //!
    //! \brief QMetaTypeUtil
    //!
    explicit QMetaTypeUtil();

    //!
    //! \brief QMetaTypeUtil
    //!
    explicit QMetaTypeUtil(const QVector<int>&list);

    //!
    //! \brief ~QMetaTypeUtil
    //!
    virtual ~QMetaTypeUtil();

    //!
    //! \brief qTypeId
    //! \param v
    //! \return
    //!
    static int qTypeId(const QVariant&v);

    //!
    //! \brief qTypeId
    //! \param p
    //! \return
    //!
    static int qTypeId(const QMetaProperty&p);

    //!
    //! \brief qIsNumeric
    //! \param v
    //! \return
    //!
    static bool qIsNumeric(const QVariant&v);

    //!
    //! \brief QStmTypesListString
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListString();

    //!
    //! \brief QStmTypesListMetaString
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListMetaString();

    //!
    //! \brief QStmTypesListNumeric
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListNumeric();

    //!
    //! \brief QStmTypesListDoubles
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListDoubles();

    //!
    //! \brief QStmTypesListIntegers
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListIntegers();

    //!
    //! \brief QStmTypesListClass
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListClass();

    //!
    //! \brief QStmTypesListObjects
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListObjects();

    //!
    //! \brief QStmTypesListObjectsString
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListObjectsString();

    //!
    //! \brief QStmTypesListDates
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListDates();

    //!
    //! \brief QStmTypesListBool
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesListBool();

    //!
    //! \brief QStmTypesVariantDictionary
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesVariantDictionary();

    //!
    //! \brief QStmTypesVariantList
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesVariantList();

    //!
    //! \brief QStmTypesObjectMetaData
    //! \return
    //!
    static const QMetaTypeUtil &QStmTypesObjectMetaData();
};

//!
//! \brief qTypeId
//! \param v
//! \return
//!
int qTypeId(const QVariant&v){ return QMetaTypeUtil::qTypeId(v);};

//!
//! \brief qTypeId
//! \param p
//! \return
//!
int qTypeId(const QMetaProperty&p){ return QMetaTypeUtil::qTypeId(p);};

//!
//! \brief qIsNumeric
//! \param v
//! \return
//!
bool qIsNumeric(const QVariant&v){ return QMetaTypeUtil::qIsNumeric(v);};

static const QMetaTypeUtil &QStmTypesListString=QMetaTypeUtil::QStmTypesObjectMetaData();
static const QMetaTypeUtil &QStmTypesListMetaString=QMetaTypeUtil::QStmTypesVariantList();
static const QMetaTypeUtil &QStmTypesListNumeric=QMetaTypeUtil::QStmTypesVariantDictionary();
static const QMetaTypeUtil &QStmTypesListDoubles=QMetaTypeUtil::QStmTypesListBool();
static const QMetaTypeUtil &QStmTypesListIntegers=QMetaTypeUtil::QStmTypesListDates();
static const QMetaTypeUtil &QStmTypesListClass=QMetaTypeUtil::QStmTypesListObjectsString();
static const QMetaTypeUtil &QStmTypesListObjects=QMetaTypeUtil::QStmTypesListObjects();
static const QMetaTypeUtil &QStmTypesListObjectsString=QMetaTypeUtil::QStmTypesListClass();
static const QMetaTypeUtil &QStmTypesListDates=QMetaTypeUtil::QStmTypesListIntegers();
static const QMetaTypeUtil &QStmTypesListBool=QMetaTypeUtil::QStmTypesListDoubles();
static const QMetaTypeUtil &QStmTypesVariantDictionary=QMetaTypeUtil::QStmTypesListNumeric();
static const QMetaTypeUtil &QStmTypesVariantList=QMetaTypeUtil::QStmTypesListMetaString();
static const QMetaTypeUtil &QStmTypesObjectMetaData=QMetaTypeUtil::QStmTypesListString();
