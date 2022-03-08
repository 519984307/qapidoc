#include "./qapidoc_document.h"
#include "./qapidoc_meta_types.h"
#include "./qapidoc_types.h"
#include "./qapidoc.h"
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaMethod>
#include <QMetaProperty>

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<DocumentPvt*>(this->p)

class DocumentPvt{
public:
    Document*parent=nullptr;
    DocumentExternal _externalDocs;
    Info _info;
    QString _basePath;
    QString _host;
    QVariantList _consumes;
    QVariantList _produces;
    QList<Definition*> _definitions;
    QList<RequestParameter*> _parameters;
    QList<Path*> _paths;
    QList<SecurityDefinition *> _securityDefinitions;
    QList<Tag *> _tags;
    QApiTransferProtocolSchemes _schemes;
    explicit DocumentPvt(Document*parent)
    {
        this->parent=parent;
    }

    virtual ~DocumentPvt()
    {
    }

};

Document::Document(QObject *parent):ObjectMapper{parent}
{
    this->p=new DocumentPvt(this);
}

Document::~Document()
{
    dPvtFree();
}

QString Document::version() const
{
    return this->qapi_ger_version;
}

bool Document::load(QObject*object)
{
    if(!ObjectMapper::load(object))
        return false;

    auto document=this;

    QHash<QByteArray, QMetaMethod> vMethodHash;
    const auto &object_ignore_methods=QApiDoc::object_ignore_methods();
    auto&metaObject = *object->metaObject();
    for(int index = 0; index < metaObject.methodCount(); ++index) {
        auto method = metaObject.method(index);

        if(method.methodType()!=method.Method && method.methodType()!=method.Slot)
            continue;

        if(object_ignore_methods.contains(method.name()))
            continue;

        if(!method.name().startsWith(Q_API_DOC_METHOD_START_NAME))
            continue;

        vMethodHash.insert(method.name(), method);
    }

    if(!vMethodHash.contains(Q_API_DOC_METHOD_NAME_INFORMATION))
        return {};

    {//document definition
        auto&method=vMethodHash[Q_API_DOC_METHOD_NAME_INFORMATION];
        if(!method.isValid())
            return {};

        vMethodHash.remove(method.name());

        if(!method.invoke(object, Qt::DirectConnection, Q_ARG(QApiDocument*, document))){
            qWarning()<<QStringLiteral("Invalid calling method: ")<<method.name();
            return {};
        }
    }

    {//document information path
        QList<Path*> paths;
        QHashIterator <QByteArray, QMetaMethod> i(vMethodHash);
        while(i.hasNext()){
            i.next();

            auto&method=i.value();

            if(!method.isValid())
                continue;

            if(!method.name().startsWith(Q_API_DOC_METHOD_NAME_PATH_STARTS_WITH))
                continue;

            auto path=new Path(document);
            path->
                setUri(method.name());
            if(!method.invoke(object, Qt::DirectConnection, Q_ARG(Path*, path))){
                qWarning()<<QStringLiteral("Invalid calling method: ")<<method.name();
                delete path;
                continue;
            }
            paths<<path;
            continue;
        }
        document->setPaths(paths);
    }
    return true;
}

const QString &Document::basePath() const
{
    dPvt();
    return p._basePath;
}

Document &Document::basePath(const QString &newBasePath)
{
    this->setBasePath(newBasePath);
    return*this;
}

Document &Document::setBasePath(const QString &newBasePath)
{
    dPvt();
    if (p._basePath == newBasePath)
        return*this;
    p._basePath = newBasePath;
    emit basePathChanged();
    return*this;
}

Document &Document::resetBasePath()
{
    return setBasePath({});
}

const QString &Document::host() const
{
    dPvt();
    return p._host;
}

Document &Document::host(const QString &newHost)
{
    return this->setHost(newHost);
}

Document &Document::setHost(const QString &newHost)
{
    dPvt();
    if (p._host == newHost)
        return*this;
    p._host = newHost;
    emit hostChanged();
    return*this;
}

Document &Document::resetHost()
{
    return setHost({});
}

const QVariantList Document::schemesObject() const
{
    dPvt();
    QVariantList __return;
    for (auto&item:qapiTransferProtocolScheme()) {
        if(!p._schemes.testFlag(item))
            continue;
        __return<<this->qapi_transfer_protocol_scheme.at(item);
    }
    return __return;
}

QApiTransferProtocolSchemes Document::schemes() const
{
    dPvt();
    return p._schemes;
}

Document &Document::schemes(const QVariant &newSchemes)
{
    return this->setSchemes(newSchemes);
}

Document &Document::setSchemes(const QVariant &newSchemes)
{
    dPvt();

    auto appendSchema=[&p](const QVariant&v)
    {
        switch (qTypeId(v)) {
        case QMetaType_Int:
        case QMetaType_UInt:
        case QMetaType_LongLong:
        case QMetaType_ULongLong:
        case QMetaType_Double:
            p._schemes = p._schemes | QApiTransferProtocolSchemes(v.toInt());
            break;
        default:
            const auto&schemesHash=qapiTransferProtocolSchemeHash();
            if(!schemesHash.contains(v.toString()))
                break;
            auto scheme=schemesHash.value(v.toString());
            p._schemes = p._schemes | scheme;
        }
    };

    switch (qTypeId(newSchemes)){
    case QMetaType_QStringList:
    case QMetaType_QVariantList:
    {
        dPvt();
        p._schemes={};
        for(auto&v:newSchemes.toList())
            appendSchema(v);
        break;
    }
    default:
        appendSchema(newSchemes);
    }
    return*this;
}

Document &Document::setSchemes(const QApiTransferProtocolSchemes &newSchemes)
{
    dPvt();
    if (p._schemes == newSchemes)
        return*this;
    p._schemes = newSchemes;
    emit schemesChanged();
    return*this;
}

Document &Document::resetSchemes()
{
    return setSchemes(QVariantList{});
}

Info &Document::info()
{
    dPvt();
    return p._info;
}

const QVariantHash Document::infoObject() const
{
    dPvt();
    return p._info.toVariant().toHash();
}

Document &Document::setInfo(const QVariant &newInfo)
{
    dPvt();
    p._info.load(newInfo);
    emit infoChanged();
    return*this;
}

Document &Document::setInfo(const Info &newInfo)
{
    dPvt();
    p._info.load(newInfo.toVariant());
    emit infoChanged();
    return*this;
}

Document &Document::resetInfo()
{
    dPvt();
    p._info.clear();
    return*this;
}

QList<Tag *> &Document::tags() const
{
    dPvt();
    return p._tags;
}

Document &Document::tags(const QVariant &newTags)
{
    return this->setTags(newTags);
}

Document &Document::tags(const QVariantList &newTags)
{
    return this->setTags(newTags);
}

Document &Document::tags(Tag *newTags)
{
    return this->setTags(newTags);
}

Document &Document::tags(const QList<Tag *> &newTags)
{
    return this->setTags(newTags);
}

Document &Document::setTags(const QVariant &newTags)
{
    dPvt();
    auto item = new Tag(this);
    if(!item->load(newTags)){
        delete item;
        return*this;
    }
    p._tags<<item;
    return *this;
}

const QVariantList Document::tagsObject() const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._tags)
        __return<<item->toVariant();
    return __return;
}

Document &Document::setTags(const QVariantList &newTags)
{
    dPvt();
    qDeleteAll(p._tags);
    p._tags.clear();
    for(auto&v:newTags){
        auto item=new Tag(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._tags<<item;
    }
    emit tagsChanged();
    return*this;
}

Document &Document::setTags(Tag *newTags)
{
    dPvt();
    this->setParent(this);
    p._tags<<newTags;
    return*this;
}

Document &Document::setTags(const QList<Tag*> &newTags)
{
    dPvt();
    auto aux=p._tags;
    p._tags.clear();
    for(auto&item:newTags){
        aux.removeOne(item);
        item->setParent(this);
        p._tags<<item;
    }
    qDeleteAll(aux);
    emit tagsChanged();
    return*this;
}

Document &Document::resetTags()
{
    return setTags(QVariantList{});
}

const QVariantList &Document::consumes() const
{
    dPvt();
    return p._consumes;
}

Document &Document::consumes(const QString &newConsume)
{
    dPvt();
    if(!p._consumes.contains(newConsume)){
        p._consumes<<newConsume;
        emit producesChanged();
    }
    return*this;
}

Document &Document::consumes(const QVariantList &newConsumes)
{
    return this->setConsumes(newConsumes);
}

Document &Document::setConsumes(const QVariantList &newConsumes)
{
    dPvt();
    p._consumes = newConsumes;
    emit consumesChanged();
    return*this;
}

Document &Document::resetConsumes()
{
    return setConsumes({});
}

const QVariantList &Document::produces() const
{
    dPvt();
    return p._produces;
}

Document &Document::produces(const QString &newProduce)
{
    dPvt();
    p._produces<<newProduce;
    emit producesChanged();
    return*this;
}

Document &Document::produces(const QVariantList &newProduces)
{
    return this->setProduces(newProduces);
}

Document &Document::setProduces(const QVariantList &newProduces)
{
    dPvt();
    if (p._produces == newProduces)
        return*this;
    p._produces = newProduces;
    emit producesChanged();
    return*this;
}

Document &Document::resetProduces()
{
    return setProduces({});
}

const QVariantList Document::pathsObject()const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._paths)
        __return<<item->toVariant();
    return __return;
}

QList<Path *> &Document::paths()const
{
    dPvt();
    return p._paths;
}

Document &Document::paths(const QVariant &newPath)
{
    dPvt();
    auto item=new Path(this);
    if(!item->load(newPath)){
        delete item;
        return*this;
    }
    p._paths<<item;
    emit securityDefinitionsChanged();
    return*this;
}

Document &Document::paths(const QVariantHash &newPaths)
{
    this->setPaths(newPaths);
    return*this;
}

Document &Document::paths(Path *newPaths)
{
    return this->setPaths(newPaths);
}

Document &Document::setPaths(const QVariant &newPaths)
{
    dPvt();
    qDeleteAll(p._paths);
    p._paths.clear();
    switch (qTypeId(newPaths)){
    case QMetaType_QVariantList:
    {
        for(auto&v:newPaths.toList()){
            auto item=new Path(this);
            if(!item->load(v)){
                delete item;
                continue;
            }
            p._paths<<item;
        }
        emit pathsChanged();
        break;
    }
    case QMetaType_QVariantHash:
    case QMetaType_QVariantMap:
    {
        QHashIterator <QString, QVariant> i(newPaths.toHash());
        while (i.hasNext()){
            i.next();
            auto&v=i.value();
            auto item=new Path(this);
            if(!item->load(v)){
                delete item;
                continue;
            }
            item->setUri(i.key());
            p._paths<<item;
        }
        emit pathsChanged();
        break;
    }
    default:
        break;
    }

    return*this;
}

Document &Document::setPaths(Path *&newPaths)
{
    dPvt();
    newPaths->setParent(this);
    if(!p._paths.contains(newPaths)){
        p._paths<<newPaths;
        emit pathsChanged();
    }
    return*this;
}

Document &Document::setPaths(const QList<Path *> &newPaths)
{
    dPvt();
    auto aux=p._paths;
    p._paths.clear();
    for(auto&item:newPaths){
        aux.removeOne(item);
        item->setParent(this);
        p._paths<<item;
    }
    qDeleteAll(aux);
    emit pathsChanged();
    return*this;
}

Document &Document::resetPaths()
{
    return setPaths(QVariantHash{});
}

const QVariantList Document::definitionsObject() const
{
    dPvt();
    QVariantList __return;
    for(auto&v:p._definitions)
        __return<<v->toVariant();
    return __return;
}

QList<Definition *> &Document::definitions() const
{
    dPvt();
    return p._definitions;
}

Document &Document::definitions(const QVariant &newDefinition)
{
    dPvt();
    auto item = new Definition(this);
    if(!item->load(newDefinition)){
        delete item;
        return*this;
    }
    p._definitions<<item;
    emit securityDefinitionsChanged();
    return*this;
}

Document &Document::definitions(const QVariantHash &newDefinitions)
{
    return this->setDefinitions(newDefinitions);
}

Document &Document::definitions(Definition *newDefinitions)
{
    return this->setDefinitions(newDefinitions);
}

Document &Document::definitions(const QList<Definition *> &newDefinitions)
{
    this->setDefinitions(newDefinitions);
    return*this;
}

Document &Document::setDefinitions(const QVariant &newDefinitions)
{
    dPvt();
    qDeleteAll(p._paths);
    p._paths.clear();
    switch (qTypeId(newDefinitions)){
    case QMetaType_QVariantList:
    {
        for(auto&v:newDefinitions.toList()){
            auto item=new Definition(this);
            if(!item->load(v)){
                delete item;
                continue;
            }
            p._definitions<<item;
        }
        emit definitionsChanged();
        break;
    }
    case QMetaType_QVariantHash:
    case QMetaType_QVariantMap:
    {
        QHashIterator <QString, QVariant> i(newDefinitions.toHash());
        while (i.hasNext()){
            i.next();
            auto item=new Definition(this);
            item->setName(i.key()).
                setSchema(i.value().toHash());
            p._definitions<<item;
        }
        emit definitionsChanged();
        break;
    }
    default:
        break;
    }
    return*this;
}

Document &Document::setDefinitions(Definition *newDefinitions)
{
    dPvt();
    newDefinitions->setParent(this);
    p._definitions<<newDefinitions;
    return*this;
}

Document &Document::setDefinitions(const QList<Definition *> &newDefinitions)
{
    dPvt();
    auto aux=p._definitions;
    p._definitions.clear();
    for(auto&item:newDefinitions){
        aux.removeOne(item);
        item->setParent(this);
        p._definitions<<item;
    }
    qDeleteAll(aux);
    emit definitionsChanged();
    return*this;
}

Document &Document::resetDefinitions()
{
    return setDefinitions(QVariantHash{});
}

const QVariantList Document::securityDefinitionsObject()const
{
    dPvt();
    QVariantList __return;
    for(auto&v:p._securityDefinitions)
        __return<<v->toVariant();
    return __return;
}

QList<SecurityDefinition *> &Document::securityDefinitions()
{
    dPvt();
    return p._securityDefinitions;
}

Document &Document::securityDefinitions(const QVariant &newSecurityDefinition)
{
    dPvt();
    auto item=new SecurityDefinition(this);
    if(!item->load(newSecurityDefinition)){
        delete item;
        return*this;
    }
    p._securityDefinitions<<item;
    emit securityDefinitionsChanged();
    return*this;
}

Document &Document::securityDefinitions(const QVariantHash &newSecurityDefinitions)
{
    this->setSecurityDefinitions(newSecurityDefinitions);
    return*this;
}

Document &Document::securityDefinitions(const QList<SecurityDefinition *> &newSecurityDefinitions)
{
    this->setSecurityDefinitions(newSecurityDefinitions);
    return*this;
}

Document &Document::setSecurityDefinitions(const QVariant &newSecurityDefinitions)
{
    dPvt();
    qDeleteAll(p._securityDefinitions);
    p._securityDefinitions.clear();

    switch (qTypeId(newSecurityDefinitions)){
    case QMetaType_QVariantList:
    {
        for(auto&v:newSecurityDefinitions.toList()){
            auto item = new SecurityDefinition(this);
            if(!item->load(v)){
                delete item;
                continue;
            }
            p._securityDefinitions<<item;
        }
        emit securityDefinitionsChanged();
        break;
    }
    case QMetaType_QVariantHash:
    case QMetaType_QVariantMap:
    {
        QHashIterator <QString, QVariant> i(newSecurityDefinitions.toHash());
        while (i.hasNext()){
            i.next();
            auto item = new SecurityDefinition(this);
            if(!item->load(i.value())){
                delete item;
                continue;
            }
            p._securityDefinitions<<item;
        }
        emit securityDefinitionsChanged();
        break;
    }
    default:
        break;
    }
    return*this;
}

Document &Document::setSecurityDefinitions(const QList<SecurityDefinition *> &newSecurityDefinitions)
{
    dPvt();
    auto aux=p._securityDefinitions;
    p._securityDefinitions.clear();
    for(auto&item:newSecurityDefinitions){
        aux.removeOne(item);
        item->setParent(this);
        p._securityDefinitions<<item;
    }
    qDeleteAll(aux);
    emit securityDefinitionsChanged();
    return*this;
    /*
    const QString qapi_ExternalDocs = QStringLiteral("externalDocs");
    const QString qapi_ExternalDocsDescription = QStringLiteral("description");
    const QString qapi_SecurityDefinitions = QStringLiteral("securityDefinitions");
    const QString qapi_SecurityDefinitionsType = QStringLiteral("type");

    auto vSecurityDefinitionsHash = vSwaggerObject.value(this->qapi_SecurityDefinitions).toHash();
    QHashIterator <QString, QVariant> i(vSecurityDefinitionsHash);
    while (i.hasNext()){
        i.next();
        auto vSecurityDefinitionItemHash = i.value().toHash();
        if (
            vSecurityDefinitionItemHash.isEmpty()
            ||
            !vSecurityDefinitionItemHash.contains(this->qapi_SecurityDefinitionsType)
            ||
            vSecurityDefinitionItemHash.contains(this->qapi_SecurityDefinitionsType)
            ){
            continue;//TODO TRETA NO IF REVER CODIGO
        }

        auto vSecurityDefinitionType=SecurityDefinitionType(vSecurityDefinitionItemHash.value(this->qapi_SecurityDefinitionsType).toInt());
        auto vSecurityDefinition = SecurityDefinition::newInstance(this, vSecurityDefinitionType);
        if (vSecurityDefinition!=nullptr)
            this->securityDefinitions(i.value());
    }
    */
}

Document &Document::resetSecurityDefinitions()
{
    setSecurityDefinitions(QVariantHash{});
    emit securityDefinitionsChanged();
    return*this;
}

const QVariantList Document::parametersObject()const
{
    dPvt();
    QVariantList __return;
    for(auto&v:p._parameters)
        __return<<v->toVariant();
    return __return;
}

QList<RequestParameter *> &Document::parameters() const
{
    dPvt();
    return p._parameters;
}

Document &Document::parameters(const QVariant &newParameter)
{
    dPvt();
    auto item=new RequestParameter(this);
    if(!item->load(newParameter)){
        delete item;
        return*this;
    }
    p._parameters<<item;
    emit parametersChanged();
    return*this;
}

Document &Document::parameters(const QVariantList &newParameters)
{
    return this->setParameters(newParameters);
}

Document &Document::parameters(const QList<RequestParameter *> &newParameters)
{
    this->setParameters(newParameters);
    return*this;
}

Document &Document::setParameters(const QVariantList &newParameters)
{
    dPvt();
    qDeleteAll(p._parameters);
    p._parameters.clear();
    for(auto&v:newParameters)
        this->parameters(v);
    return*this;
}

Document &Document::setParameters(const QList<RequestParameter *> &newParameters)
{
    dPvt();
    auto aux=p._parameters;
    p._parameters.clear();
    for(auto&item:newParameters){
        aux.removeOne(item);
        this->setParent(this);
        p._parameters<<item;
    }
    qDeleteAll(aux);
    emit parametersChanged();
    return*this;
}

Document &Document::resetParameters()
{
    return setParameters(QVariantList{});
}

DocumentExternal &Document::externalDocs()
{
    dPvt();
    return p._externalDocs;
}

const QVariantHash Document::externalDocsObject() const
{
    dPvt();
    return p._externalDocs.toVariant().toHash();
}

Document &Document::externalDocs(const QVariant &newExternalDocs)
{
    return this->setExternalDocs(newExternalDocs);
}

Document &Document::setExternalDocs(const QVariant &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs);
    emit externalDocsChanged();
    return*this;
}

Document &Document::setExternalDocs(const DocumentExternal &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs.toVariant());
    emit externalDocsChanged();
    return*this;
}

Document &Document::resetExternalDocs()
{
    dPvt();
    p._externalDocs.clear();
    return*this;
}

}

