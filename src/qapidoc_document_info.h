#pragma once

#include "./qapidoc_includes.h"

#include "./qapidoc_document_info_contact.h"
#include "./qapidoc_document_info_license.h"

namespace QApiDoc {

//!
//! \brief The Info class
//!
//! The object provides metadata about the API.
//! The metadata can be used by the clients if needed, and can be presented in the Swagger-UI for convenience.
//!
class Q_API_DOC_EXPORT Info : public ObjectMapper
{
    Q_OBJECT

    //! Required Provides the version of the application API (!to be confused with the specification version).
    Q_PROPERTY(QString version READ version WRITE setVersion RESET resetVersion NOTIFY versionChanged)

    //! Required. The title of the application.
    Q_PROPERTY(QString title READ title WRITE setTitle RESET resetTitle NOTIFY titleChanged)

    //! A short description of the application. GFM syntax can be used for rich text representation.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription
                   NOTIFY descriptionChanged)

    //! The contact information for the exposed API.
    Q_PROPERTY(QVariantHash contact READ contactObject WRITE setContact RESET resetContact NOTIFY
                   contactChanged)

    //! The Terms of Service for the API.
    Q_PROPERTY(QString termsOfService READ termsOfService WRITE setTermsOfService RESET
                   resetTermsOfService NOTIFY termsOfServiceChanged)

    //! The license information for the exposed API.
    Q_PROPERTY(QVariantHash license READ licenseObject WRITE setLicense RESET resetLicense NOTIFY
                   licenseChanged)

public:
    Q_INVOKABLE explicit Info(QObject *parent = nullptr);
    ~Info();

    //!
    //! \brief version
    //! \return
    //!
    const QString &version() const;
    Info &version(const QString &newVersion);
    Info &setVersion(const QString &newVersion);
    Info &resetVersion();

    //!
    //! \brief title
    //! \return
    //!
    const QString &title() const;
    Info &title(const QString &newTitle);
    Info &setTitle(const QString &newTitle);
    Info &resetTitle();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    Info &description(const QString &newDescription);
    Info &setDescription(const QString &newDescription);
    Info &resetDescription();

    //!
    //! \brief termsOfService
    //! \return
    //!
    const QString &termsOfService();
    Info &termsOfService(const QString &newTermsOfService);
    Info &setTermsOfService(const QString &newTermsOfService);
    Info &resetTermsOfService();

    //!
    //! \brief contact
    //! \return
    //!
    InfoContact &contact();
    QVariantHash contactObject() const;
    Info &contact(const QVariant &newContact);
    Info &setContact(const QVariant &newContact);
    Info &setContact(const InfoContact &newContact);
    Info &resetContact();

    //!
    //! \brief license
    //! \return
    //!
    InfoLicense &license();
    QVariantHash licenseObject() const;
    Info &license(const QVariant &newLicense);
    Info &setLicense(const QVariant &newLicense);
    Info &setLicense(const InfoLicense &newLicense);
    Info &resetLicense();

signals:
    void versionChanged();
    void titleChanged();
    void descriptionChanged();
    void contactChanged();
    void termsOfServiceChanged();
    void licenseChanged();

private:
    void *p = nullptr;
};

} // namespace QApiDoc
