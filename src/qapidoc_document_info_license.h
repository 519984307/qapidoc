#pragma once

#include "./qapidoc_includes.h"

namespace QApiDoc {

//!
//! \brief The InfoLicense class
//! License information for the exposed API.
class Q_API_DOC_EXPORT InfoLicense : public ObjectMapper
{
    Q_OBJECT

    //! Required. The license name used for the API.
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //! A URL to the license used for the API. MUST be in the format of a URL.
    Q_PROPERTY(QString url READ url WRITE setUrl RESET resetUrl NOTIFY urlChanged)

public:
    Q_INVOKABLE explicit InfoLicense(QObject *parent = nullptr);
    ~InfoLicense();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    InfoLicense &name(const QString &newName);
    InfoLicense &setName(const QString &newName);
    InfoLicense &resetName();

    //!
    //! \brief url
    //! \return
    //!
    const QString &url() const;
    InfoLicense &url(const QString &newUrl);
    InfoLicense &setUrl(const QString &newUrl);
    InfoLicense &resetUrl();

private:
    void *p = nullptr;

signals:
    void nameChanged();
    void urlChanged();
};

} // namespace QApiDoc
