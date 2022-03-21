#pragma once

#include "./qapidoc_global.h"
#include <QBitArray>
#include <QByteArray>
#include <QChar>
#include <QMetaProperty>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QUrl>
#include <QUuid>
#include <QVariant>
#include <QVariantHash>
#include <QVariantList>
#include <QVariantMap>
#include <QVector>

namespace QApiDoc {

//!
//! \brief Consts to QMetaType
static const int QMetaType_UnknownType = QMetaType::UnknownType;
static const int QMetaType_Void = QMetaType::Void;
static const int QMetaType_Bool = QMetaType::Bool;
static const int QMetaType_User = QMetaType::User;
static const int QMetaType_Double = QMetaType::Double;
static const int QMetaType_Int = QMetaType::Int;
static const int QMetaType_UInt = QMetaType::UInt;
static const int QMetaType_LongLong = QMetaType::LongLong;
static const int QMetaType_ULongLong = QMetaType::ULongLong;
static const int QMetaType_QBitArray = QMetaType::QBitArray;
static const int QMetaType_QByteArray = QMetaType::QByteArray;
static const int QMetaType_QChar = QMetaType::QChar;
static const int QMetaType_QDate = QMetaType::QDate;
static const int QMetaType_QDateTime = QMetaType::QDateTime;
static const int QMetaType_QString = QMetaType::QString;
static const int QMetaType_QStringList = QMetaType::QStringList;
static const int QMetaType_QTime = QMetaType::QTime;
static const int QMetaType_QUrl = QMetaType::QUrl;
static const int QMetaType_QUuid = QMetaType::QUuid;
static const int QMetaType_QVariantHash = QMetaType::QVariantHash;
static const int QMetaType_QVariantList = QMetaType::QVariantList;
static const int QMetaType_QVariantMap = QMetaType::QVariantMap;
static const int QMetaType_CustomType = 65538;

//!
//! \brief The QMetaTypeUtil class
//!
//! List for QMetaType
class Q_API_DOC_EXPORT QMetaTypeUtil : public QVector<int>
{
public:
    //!
    //! \brief QMetaTypeUtil
    //!
    explicit QMetaTypeUtil();

    //!
    //! \brief QMetaTypeUtil
    //!
    explicit QMetaTypeUtil(const QVector<int> &list);

    //!
    //! \brief ~QMetaTypeUtil
    //!
    virtual ~QMetaTypeUtil();

    //!
    //! \brief qTypeId
    //! \param v
    //! \return
    //!
    static int qTypeId(const QVariant &v);

    //!
    //! \brief qTypeId
    //! \param p
    //! \return
    //!
    static int qTypeId(const QMetaProperty &p);

    //!
    //! \brief qIsNumeric
    //! \param v
    //! \return
    //!
    static bool qIsNumeric(const QVariant &v);

    //!
    //! \brief QMetaTypeUtilString
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilString();

    //!
    //! \brief QMetaTypeUtilMetaString
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilMetaString();

    //!
    //! \brief QMetaTypeUtilNumeric
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilNumeric();

    //!
    //! \brief QMetaTypeUtilDoubles
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilDoubles();

    //!
    //! \brief QMetaTypeUtilIntegers
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilIntegers();

    //!
    //! \brief QMetaTypeUtilClass
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilClass();

    //!
    //! \brief QMetaTypeUtilObjects
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilObjects();

    //!
    //! \brief QMetaTypeUtilObjectsString
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilObjectsString();

    //!
    //! \brief QMetaTypeUtilDates
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilDates();

    //!
    //! \brief QMetaTypeUtilBool
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilBool();

    //!
    //! \brief QMetaTypeUtilVariantDictionary
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilVariantDictionary();

    //!
    //! \brief QMetaTypeUtilVariantList
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilVariantList();

    //!
    //! \brief QMetaTypeUtilObjectMetaData
    //! \return
    //!
    static const QMetaTypeUtil &qMetaTypeUtilObjectMetaData();
};

//!
//! \brief qTypeId
//! \param v
//! \return
//!
int qTypeId(const QVariant &v);

//!
//! \brief qTypeId
//! \param p
//! \return
//!
int qTypeId(const QMetaProperty &p);

//!
//! \brief qIsNumeric
//! \param v
//! \return
//!
bool qIsNumeric(const QVariant &v);

static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilString
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilString();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilMetaString
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilMetaString();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilNumeric
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilNumeric();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilDoubles
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilDoubles();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilIntegers
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilIntegers();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilClass
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilClass();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjects
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilObjects();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjectsString
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilObjectsString();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilDates
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilDates();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilBool = QApiDoc::QMetaTypeUtil::qMetaTypeUtilBool();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilVariantDictionary
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilVariantDictionary();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilVariantList
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilVariantList();
static const QApiDoc::QMetaTypeUtil &QMetaTypeUtilObjectMetaData
    = QApiDoc::QMetaTypeUtil::qMetaTypeUtilObjectMetaData();

} // namespace QApiDoc
