#include "./qapidoc_document_security_definition_api_key.h"

namespace QApiDoc {

#define dPvt() auto &p = *reinterpret_cast<SecurityDefinitionApiKeyPvt *>(this->p)

class SecurityDefinitionApiKeyPvt
{
public:
    SecurityDefinitionApiKey *parent = nullptr;
    SecurityDefinitionApiKey::SecurityDefinitionApiKeyInLocation _inLocation;
    QString _name;
    explicit SecurityDefinitionApiKeyPvt(SecurityDefinitionApiKey *parent)
    {
        this->parent = parent;
    }

    virtual ~SecurityDefinitionApiKeyPvt() {}
};

SecurityDefinitionApiKey::SecurityDefinitionApiKey(QObject *parent) : SecurityDefinition{parent}
{
    this->p = new SecurityDefinitionApiKeyPvt{this};
}

SecurityDefinitionApiKey::~SecurityDefinitionApiKey()
{
    dPvtFree();
}

SecurityDefinitionApiKey::SecurityDefinitionApiKeyInLocation SecurityDefinitionApiKey::inLocation()
    const
{
    dPvt();
    return p._inLocation;
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::inLocation(const QVariant &newInLocation)
{
    return this->setInLocation(newInLocation);
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::setInLocation(const QVariant &newInLocation)
{
    dPvt();
    auto vIn = newInLocation.toString().toLower();
    if (vIn == qapi_SecurityDefinitionApiKeyInLocation.at(kilQuery))
        p._inLocation = kilQuery;
    else if (vIn == qapi_SecurityDefinitionApiKeyInLocation.at(kilHeader))
        p._inLocation = kilHeader;
    else
        p._inLocation = SecurityDefinitionApiKeyInLocation(newInLocation.toInt());
    emit inLocationChanged();
    return *this;
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::resetInLocation()
{
    return setInLocation({});
}

SecurityDefinition::SecurityDefinitionType SecurityDefinitionApiKey::typeSecurity() const
{
    return sstApiKey;
}

const QString &SecurityDefinitionApiKey::name() const
{
    dPvt();
    return p._name;
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::name(const QString &newName)
{
    return this->setName(newName);
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return *this;
    p._name = newName;
    emit nameChanged();
    return *this;
}

SecurityDefinitionApiKey &SecurityDefinitionApiKey::resetName()
{
    return setName({});
}

} // namespace QApiDoc
