#pragma once


#include "./qapidoc_includes.h"

#include "./qapidoc_common_types.h"
#include "./qapidoc_document_security_definition.h"


namespace QApiDoc{

//!
//! \brief The SecurityDefinitionApiKey class
//!
//! The security scheme object API key (either as a header or as a query parameter)
//!
class Q_SWAGGER_EXPORT SecurityDefinitionApiKey : public SecurityDefinition
{
    Q_OBJECT

    //! Required. The name of the header or query parameter to be used.
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //! Required The location of the API key. Valid values are "query" or "header".
    Q_PROPERTY(SecurityDefinitionApiKeyInLocation inLocation READ inLocation WRITE setInLocation RESET resetInLocation NOTIFY inLocationChanged)
public:
    //!
    //! \brief The SecurityDefinitionApiKeyInLocation enum
    //!
    enum SecurityDefinitionApiKeyInLocation {kilNotDefined, kilQuery, kilHeader};
    Q_ENUM(SecurityDefinitionApiKeyInLocation)

    Q_INVOKABLE explicit SecurityDefinitionApiKey(QObject*parent=nullptr);
    ~SecurityDefinitionApiKey();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    SecurityDefinitionApiKey &name(const QString &newName);
    SecurityDefinitionApiKey &setName(const QString &newName);
    SecurityDefinitionApiKey &resetName();

    //!
    //! \brief inLocation
    //! \return
    //!
    SecurityDefinitionApiKeyInLocation inLocation() const;
    SecurityDefinitionApiKey &inLocation(const QVariant &newInLocation);
    SecurityDefinitionApiKey &setInLocation(const QVariant &newInLocation);
    SecurityDefinitionApiKey &resetInLocation();

    //!
    //! \brief typeSecurity
    //! \return
    //!
    SecurityDefinitionType typeSecurity()const;
private:
    void*p=nullptr;
    const QStringList qapi_SecurityDefinitionApiKeyInLocation{QString(), QStringLiteral("query"), QStringLiteral("header")};
signals:
    //!
    //! \brief nameChanged
    //!
    void nameChanged();

    //!
    //! \brief inLocationChanged
    //!
    void inLocationChanged();
};

Q_SWAGGER_SECURITY_DEFINITION_REGISTER(sstApiKey, SecurityDefinitionApiKey);


}

