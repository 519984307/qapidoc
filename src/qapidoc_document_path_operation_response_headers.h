#pragma once

#include "./qapidoc_includes.h"

namespace QApiDoc {

//!
//! \brief The Headers class
//!
//!Lists the headers that can be sent as part of a response.
//!
class Q_API_DOC_EXPORT Headers : public ObjectMapper
{
    Q_OBJECT

    //! A header name alias.
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //! A short description of the header.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription
                   NOTIFY descriptionChanged)

    //!
    Q_PROPERTY(QString type READ type WRITE setType RESET resetType NOTIFY typeChanged)

    //! Required. The type of the object. The value MUST be one of "string", "number", "int", "boolean", or "array".
    Q_PROPERTY(QString format READ format WRITE setFormat RESET resetFormat NOTIFY formatChanged)

public:
    Q_INVOKABLE explicit Headers(QObject *parent = nullptr);
    ~Headers();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    Headers &name(const QString &newName);
    Headers &setName(const QString &newName);
    Headers &resetName();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    Headers &description(const QString &newDescription);
    Headers &setDescription(const QString &newDescription);
    Headers &resetDescription();

    //!
    //! \brief type
    //! \return
    //!
    const QString &type() const;
    Headers &type(const QString &newType);
    Headers &setType(const QString &newType);
    Headers &resetType();

    //!
    //! \brief format
    //! \return
    //!
    const QString &format() const;
    Headers &format(const QString &newFormat);
    Headers &setFormat(const QString &newFormat);
    Headers &resetFormat();

signals:

    //!
    //! \brief nameChanged
    //!
    void nameChanged();

    //!
    //! \brief descriptionChanged
    //!
    void descriptionChanged();

    //!
    //! \brief typeChanged
    //!
    void typeChanged();

    //!
    //! \brief formatChanged
    //!
    void formatChanged();

private:
    void *p = nullptr;
};

} // namespace QApiDoc
