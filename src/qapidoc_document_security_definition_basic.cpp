#include "./qapidoc_document_security_definition_basic.h"

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<SecurityDefinitionBasicPvt*>(this->p)

class SecurityDefinitionBasicPvt{
public:
    SecurityDefinitionBasic*parent=nullptr;
    QString _name;

    explicit SecurityDefinitionBasicPvt(SecurityDefinitionBasic*parent)
    {
        this->parent=parent;
    }

    virtual ~SecurityDefinitionBasicPvt()
    {
    }
};

SecurityDefinitionBasic::SecurityDefinitionBasic(QObject *parent):SecurityDefinition{parent}
{
    this->p=new SecurityDefinitionBasicPvt(this);
}

SecurityDefinitionBasic::~SecurityDefinitionBasic()
{
    dPvtFree();
}

const QString &SecurityDefinitionBasic::name() const
{
    dPvt();
    return p._name;
}

SecurityDefinitionBasic &SecurityDefinitionBasic::name(const QString &newName)
{
    return this->setName(newName);
}

SecurityDefinitionBasic &SecurityDefinitionBasic::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return*this;
    p._name = newName;
    emit nameChanged();
    return*this;
}

SecurityDefinitionBasic &SecurityDefinitionBasic::resetName()
{
    return setName({});
}

SecurityDefinition::SecurityDefinitionType SecurityDefinitionBasic::typeSecurity() const
{
    return sstBasic;
}


}
