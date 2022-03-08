#pragma once

#include <QObject>
#include <QVariant>
#include <QVariantHash>
#include <QString>
#include <QMetaProperty>
#include <QTemporaryFile>
#include "./qapidoc_global.h"


namespace QApiDoc{

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
    //! \brief QMetaTypeUtilString
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilString();

    //!
    //! \brief QMetaTypeUtilMetaString
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilMetaString();

    //!
    //! \brief QMetaTypeUtilNumeric
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilNumeric();

    //!
    //! \brief QMetaTypeUtilDoubles
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilDoubles();

    //!
    //! \brief QMetaTypeUtilIntegers
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilIntegers();

    //!
    //! \brief QMetaTypeUtilClass
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilClass();

    //!
    //! \brief QMetaTypeUtilObjects
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilObjects();

    //!
    //! \brief QMetaTypeUtilObjectsString
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilObjectsString();

    //!
    //! \brief QMetaTypeUtilDates
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilDates();

    //!
    //! \brief QMetaTypeUtilBool
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilBool();

    //!
    //! \brief QMetaTypeUtilVariantDictionary
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilVariantDictionary();

    //!
    //! \brief QMetaTypeUtilVariantList
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilVariantList();

    //!
    //! \brief QMetaTypeUtilObjectMetaData
    //! \return
    //!
    static const QMetaTypeUtil &QMetaTypeUtilObjectMetaData();
};

}


//!
//! \brief qTypeId
//! \param v
//! \return
//!
int qTypeId(const QVariant&v){ return QApiDoc::QMetaTypeUtil::qTypeId(v);};

//!
//! \brief qTypeId
//! \param p
//! \return
//!
int qTypeId(const QMetaProperty&p){ return QApiDoc::QMetaTypeUtil::qTypeId(p);};

//!
//! \brief qIsNumeric
//! \param v
//! \return
//!
bool qIsNumeric(const QVariant&v){ return QApiDoc::QMetaTypeUtil::qIsNumeric(v);};

static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilString=QApiDoc::QMetaTypeUtil::QMetaTypeUtilObjectMetaData();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilMetaString=QApiDoc::QMetaTypeUtil::QMetaTypeUtilVariantList();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilNumeric=QApiDoc::QMetaTypeUtil::QMetaTypeUtilVariantDictionary();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilDoubles=QApiDoc::QMetaTypeUtil::QMetaTypeUtilBool();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilIntegers=QApiDoc::QMetaTypeUtil::QMetaTypeUtilDates();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilClass=QApiDoc::QMetaTypeUtil::QMetaTypeUtilObjectsString();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjects=QApiDoc::QMetaTypeUtil::QMetaTypeUtilObjects();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjectsString=QApiDoc::QMetaTypeUtil::QMetaTypeUtilClass();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilDates=QApiDoc::QMetaTypeUtil::QMetaTypeUtilIntegers();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilBool=QApiDoc::QMetaTypeUtil::QMetaTypeUtilDoubles();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilVariantDictionary=QApiDoc::QMetaTypeUtil::QMetaTypeUtilNumeric();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilVariantList=QApiDoc::QMetaTypeUtil::QMetaTypeUtilMetaString();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjectMetaData=QApiDoc::QMetaTypeUtil::QMetaTypeUtilString();
