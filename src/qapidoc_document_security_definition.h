#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"

namespace QApiDoc{

#define Q_SWAGGER_SECURITY_DEFINITION_REGISTER(SecurityDefinitionType, MetaObject)\
static const auto __securityDefinition##MetaObject##__registerRegister=SecurityDefinition::registerSecurityDefinition(SecurityDefinitionType, MetaObject::staticMetaObject)

/// <summary>
/// A declaration of the security schemes available to be used in the specification.
/// This does not enforce the security schemes on the operations and only serves to provide the relevant details for each scheme.
/// </summary>
class Q_SWAGGER_EXPORT SecurityDefinition : public ObjectMapper
{
    Q_OBJECT

    //! A single security scheme definition, mapping a "name" to the scheme it defines.
    Q_PROPERTY(QString schemaName READ schemaName WRITE setSchemaName RESET resetSchemaName NOTIFY schemaNameChanged)

    //! A short description for security scheme.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription NOTIFY descriptionChanged)

    //! Required. The type of the security scheme. Valid values are "basic", "apiKey" or "oauth2".
    Q_PROPERTY(SecurityDefinitionType typeSecurity READ typeSecurity NOTIFY typeSecurityChanged)

public:
    Q_API_DECLARE_SECURITY_DEFINITION_TYPE()

    Q_INVOKABLE explicit SecurityDefinition(QObject*parent=nullptr);
    ~SecurityDefinition();

    //!
    //! \brief registerSecurityDefinition
    //! \param securityDefinitionType
    //! \param metaObject
    //! \return
    //!
    static bool registerSecurityDefinition(int securityDefinitionType, const QMetaObject&metaObject);

    //!
    //! \brief newInstance
    //! \param parent
    //! \param securityType
    //! \return
    //!
    static SecurityDefinition*newInstance(QObject *parent, const SecurityDefinitionType securityType);

    //!
    //! \brief schemaName
    //! \return
    //!
    const QString &schemaName() const;
    SecurityDefinition &schemaName(const QString &newSchemaName);
    SecurityDefinition &setSchemaName(const QString &newSchemaName);
    SecurityDefinition &resetSchemaName();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    SecurityDefinition &description(const QString &newDescription);
    SecurityDefinition &setDescription(const QString &newDescription);
    SecurityDefinition &resetDescription();

    //!
    //! \brief typeSecurity
    //! \return
    //!
    virtual SecurityDefinitionType typeSecurity()const{ return {};};

    //!
    //! \brief typeSecurityToString
    //! \return
    //!
    virtual QString typeSecurityToString()const;
private:
    void*p=nullptr;
    const QStringList qapi_SecurityDefinitionType{QString(), QStringLiteral("basic"), QStringLiteral("apiKey"), QStringLiteral("oauth2")};
signals:
    void schemaNameChanged();
    void descriptionChanged();
    void typeSecurityChanged();
};



}

