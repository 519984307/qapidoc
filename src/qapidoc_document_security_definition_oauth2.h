#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_security_definition.h"


namespace QApiDoc{

class SecurityDefinitionOAuth2Scope;

//!
//! \brief The SecurityDefinitionOAuth2 class
//!
class Q_API_DOC_EXPORT SecurityDefinitionOAuth2: public SecurityDefinition
{
    Q_OBJECT

    //!
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //!
    Q_PROPERTY(QString authorizationUrl READ authorizationUrl WRITE setAuthorizationUrl RESET resetAuthorizationUrl NOTIFY authorizationUrlChanged)

    //!
    Q_PROPERTY(QString flow READ flow WRITE setFlow RESET resetFlow NOTIFY flowChanged)

    //!
    Q_PROPERTY(QVariantHash scopes READ scopesObject WRITE setScopes RESET resetScopes NOTIFY scopesChanged)
public:
    Q_INVOKABLE explicit SecurityDefinitionOAuth2(QObject*parent=nullptr);
    ~SecurityDefinitionOAuth2();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    SecurityDefinitionOAuth2 &name(const QString &newName);
    SecurityDefinitionOAuth2 &setName(const QString &newName);
    SecurityDefinitionOAuth2 &resetName();

    //!
    //! \brief authorizationUrl
    //! \return
    //!
    const QString &authorizationUrl() const;
    SecurityDefinitionOAuth2 &authorizationUrl(const QString &newAuthorizationUrl);
    SecurityDefinitionOAuth2 &setAuthorizationUrl(const QString &newAuthorizationUrl);
    SecurityDefinitionOAuth2 &resetAuthorizationUrl();

    //!
    //! \brief flow
    //! \return
    //!
    const QString &flow() const;
    SecurityDefinitionOAuth2 &flow(const QString &newFlow);
    SecurityDefinitionOAuth2 &setFlow(const QString &newFlow);
    SecurityDefinitionOAuth2 &resetFlow();

    //!
    //! \brief scopes
    //! \return
    //!
    QList<SecurityDefinitionOAuth2Scope*> &scopes() const;
    const QVariantHash scopesObject() const;
    SecurityDefinitionOAuth2 &scopes(const QVariant &newScopes);
    SecurityDefinitionOAuth2 &setScopes(const QVariant &newScopes);
    SecurityDefinitionOAuth2 &setScopes(const QList<SecurityDefinitionOAuth2Scope *> &newScopes);
    SecurityDefinitionOAuth2 &resetScopes();

    //!
    //! \brief typeSecurity
    //! \return
    //!
    SecurityDefinitionType typeSecurity()const;
signals:
    //!
    //! \brief nameChanged
    //!
    void nameChanged();

    //!
    //! \brief authorizationUrlChanged
    //!
    void authorizationUrlChanged();

    //!
    //! \brief flowChanged
    //!
    void flowChanged();

    //!
    //! \brief scopesChanged
    //!
    void scopesChanged();

private:
    void*p=nullptr;
};

Q_SWAGGER_SECURITY_DEFINITION_REGISTER(sstOAuth2, SecurityDefinitionOAuth2);

}
