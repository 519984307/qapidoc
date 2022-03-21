#pragma once

#include "./qapidoc_includes.h"

namespace QApiDoc {

//!
//! \brief The InfoContact class
//!
//! Contact information for the exposed API.
//!
class Q_API_DOC_EXPORT InfoContact : public ObjectMapper
{
    Q_OBJECT

    //! The identifying name of the contact person/organization.
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //! The URL pointing to the contact information. MUST be in the format of a URL.
    Q_PROPERTY(QString email READ email WRITE setEmail RESET resetEmail NOTIFY emailChanged)

    //! The email address of the contact person/organization. MUST be in the format of an email address.
    Q_PROPERTY(QString url READ url WRITE setUrl RESET resetUrl NOTIFY urlChanged)

public:
    Q_INVOKABLE explicit InfoContact(QObject *parent = nullptr);
    ~InfoContact();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    InfoContact &name(const QString &newName);
    InfoContact &setName(const QString &newName);
    InfoContact &resetName();

    //!
    //! \brief email
    //! \return
    //!
    const QString &email() const;
    InfoContact &email(const QString &newEmail);
    InfoContact &setEmail(const QString &newEmail);
    InfoContact &resetEmail();

    //!
    //! \brief url
    //! \return
    //!
    const QString &url() const;
    InfoContact &url(const QString &newUrl);
    InfoContact &setUrl(const QString &newUrl);
    InfoContact &resetUrl();

signals:
    void nameChanged();
    void emailChanged();
    void urlChanged();

private:
    void *p = nullptr;
};

} // namespace QApiDoc
