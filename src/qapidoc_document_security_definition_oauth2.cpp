#include "./qapidoc_document_security_definition_oauth2.h"
#include "./qapidoc_document_security_definition_oauth2_scope.h"
#include "./qapidoc_meta_types.h"

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<SecurityDefinitionOAuth2Pvt*>(this->p)

class SecurityDefinitionOAuth2Pvt{
public:
    SecurityDefinitionOAuth2*parent=nullptr;
    QString _name;
    QString _authorizationUrl;
    QString _flow;
    QList<SecurityDefinitionOAuth2Scope*> _scopes;
    explicit SecurityDefinitionOAuth2Pvt(SecurityDefinitionOAuth2*parent)
    {
        this->parent=parent;
    }

    virtual ~SecurityDefinitionOAuth2Pvt()
    {
    }
};

SecurityDefinitionOAuth2::SecurityDefinitionOAuth2(QObject *parent):SecurityDefinition{parent}
{
    this->p=new SecurityDefinitionOAuth2Pvt(this);
}

SecurityDefinitionOAuth2::~SecurityDefinitionOAuth2()
{
    dPvtFree();
}

SecurityDefinition::SecurityDefinitionType SecurityDefinitionOAuth2::typeSecurity() const
{
    return sstOAuth2;
}

const QVariantHash SecurityDefinitionOAuth2::scopesObject() const
{
    dPvt();
    QVariantHash __return;
    for(auto&item:p._scopes)
        __return.insert(item->scopeName(), item->description());
    return __return;
}

QList<SecurityDefinitionOAuth2Scope *> &SecurityDefinitionOAuth2::scopes() const
{
    dPvt();
    return p._scopes;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::scopes(const QVariant &newScopes)
{
    return this->setScopes(newScopes);
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::setScopes(const QVariant &newScopes)
{
    dPvt();
    QVariantList vList;
    switch (qTypeId(newScopes)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        qDeleteAll(p._scopes);
        p._scopes.clear();
        vList=newScopes.toList();
        break;
    }
    case QMetaType_QVariantHash:
    case QMetaType_QVariantMap:
    {
        qDeleteAll(p._scopes);
        p._scopes.clear();
        vList=newScopes.toHash().values();
        break;
    }
    default:
        vList<<newScopes;
    }

    for(auto&v:vList){
        auto item=new SecurityDefinitionOAuth2Scope(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._scopes<<item;
    }
    emit scopesChanged();
    return*this;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::setScopes(const QList<SecurityDefinitionOAuth2Scope *> &newScopes)
{
    dPvt();
    auto aux=p._scopes;
    p._scopes.clear();
    for(auto&item:newScopes){
        aux.removeOne(item);
        item->setParent(this);
        p._scopes<<item;
    }
    qDeleteAll(aux);
    emit scopesChanged();
    return*this;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::resetScopes()
{
    return setScopes(QVariantList{});
}

const QString &SecurityDefinitionOAuth2::flow() const
{
    dPvt();
    return p._flow;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::flow(const QString &newFlow)
{
    return this->setFlow(newFlow);
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::setFlow(const QString &newFlow)
{
    dPvt();
    if (p._flow == newFlow)
        return*this;
    p._flow = newFlow;
    emit flowChanged();
    return*this;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::resetFlow()
{
    return setFlow({});
}

const QString &SecurityDefinitionOAuth2::authorizationUrl() const
{
    dPvt();
    return p._authorizationUrl;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::authorizationUrl(const QString &newAuthorizationUrl)
{
    return this->setAuthorizationUrl(newAuthorizationUrl);
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::setAuthorizationUrl(const QString &newAuthorizationUrl)
{
    dPvt();
    if (p._authorizationUrl == newAuthorizationUrl)
        return*this;
    p._authorizationUrl = newAuthorizationUrl;
    emit authorizationUrlChanged();
    return*this;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::resetAuthorizationUrl()
{
    return setAuthorizationUrl({});
}

const QString &SecurityDefinitionOAuth2::name() const
{
    dPvt();
    return p._name;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::name(const QString &newName)
{
    return this->setName(newName);
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return*this;
    p._name = newName;
    emit nameChanged();
    return*this;
}

SecurityDefinitionOAuth2 &SecurityDefinitionOAuth2::resetName()
{
    return setName({});
}


}
