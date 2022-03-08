#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_security_definition.h"

namespace QApiDoc{

//!
//! \brief The SecurityDefinitionBasic class
//!
//! The security scheme object Basic
//!
class Q_API_DOC_EXPORT SecurityDefinitionBasic: public SecurityDefinition
{
    Q_OBJECT

    //!
    //!
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)
public:
    Q_INVOKABLE explicit SecurityDefinitionBasic(QObject*parent=nullptr);
    ~SecurityDefinitionBasic();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    SecurityDefinitionBasic &name(const QString &newName);
    SecurityDefinitionBasic &setName(const QString &newName);
    SecurityDefinitionBasic &resetName();

    //!
    //! \brief typeSecurity
    //! \return
    //!
    SecurityDefinitionType typeSecurity()const;
private:
    void*p=nullptr;
signals:

    //!
    //! \brief nameChanged
    //!
    void nameChanged();
};

Q_SWAGGER_SECURITY_DEFINITION_REGISTER(sstBasic, SecurityDefinitionBasic);

}
