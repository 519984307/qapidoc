#pragma once

#include "./qapidoc_global.h"
#include <QObject>

namespace QApiDoc {

//!
//! \brief The ObjectMapper class
//!
class Q_API_DOC_EXPORT ObjectMapper : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit ObjectMapper(QObject *parent = nullptr);
    ~ObjectMapper();

    //!
    //! \brief operator =
    //! \param value
    //!
    ObjectMapper &operator=(const QVariant &value);

    //!
    //! \brief operator <<
    //! \param value
    //! \return
    //!
    ObjectMapper &operator<<(const QVariant &value);

    //!
    //! \brief operator +=
    //! \param value
    //! \return
    //!
    ObjectMapper &operator+=(const QVariant &value);

    //!
    //! \brief toVariant
    //! \return
    //!
    virtual QVariant toVariant() const;

    //!
    //! \brief toHash
    //! \return
    //!
    virtual QVariantHash toHash() const;

    //!
    //! \brief toMap
    //! \return
    //!
    virtual QVariantMap toMap() const;

    //!
    //! \brief toJson
    //! \return
    //!
    virtual QByteArray toJson() const;

    //!
    //! \brief clear
    //!
    virtual ObjectMapper &clear();

    //!
    //! \brief isEmpty
    //! \return
    //!
    virtual bool isEmpty();

    //!
    //! \brief load
    //! \param value
    //! \return
    //!
    virtual bool load(const QVariant &value);

    //!
    //! \brief load
    //! \param parent
    //! \return
    //!
    virtual bool load(QObject *object);

    //!
    //! \brief read
    //! \param value
    //! \return
    //!
    virtual bool read(const QVariant &value);

    //!
    //! \brief save
    //! \param fileName
    //! \return
    //!
    virtual bool save(const QString &fileName);

signals:
};

} // namespace QApiDoc
