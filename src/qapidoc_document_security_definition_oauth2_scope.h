#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_security_definition.h"

namespace QApiDoc{
//!
//! \brief The SecurityDefinitionOAuth2Scope class
//!
class Q_SWAGGER_EXPORT SecurityDefinitionOAuth2Scope : public ObjectMapper
{
    Q_OBJECT

    //!
    Q_PROPERTY(QString scopeName READ scopeName WRITE setScopeName RESET resetScopeName NOTIFY scopeNameChanged)

    //!
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription NOTIFY descriptionChanged)

public:
    Q_INVOKABLE explicit SecurityDefinitionOAuth2Scope(QObject*parent=nullptr);
    ~SecurityDefinitionOAuth2Scope();

    //!
    //! \brief scopeName
    //! \return
    //!
    const QString &scopeName() const;
    SecurityDefinitionOAuth2Scope &scopeName(const QString &newScopeName);
    SecurityDefinitionOAuth2Scope &setScopeName(const QString &newScopeName);
    SecurityDefinitionOAuth2Scope &resetScopeName();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    SecurityDefinitionOAuth2Scope &description(const QString &newDescription);
    SecurityDefinitionOAuth2Scope &setDescription(const QString &newDescription);
    SecurityDefinitionOAuth2Scope &resetDescription();
private:
    void*p=nullptr;

signals:
    //!
    //! \brief scopeNameChanged
    //!
    void scopeNameChanged();

    //!
    //! \brief descriptionChanged
    //!
    void descriptionChanged();
};

}
