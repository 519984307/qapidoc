#include "./qapidoc_document_path_operation.h"
#include "./qapidoc_document_path.h"
#include "./qapidoc_meta_types.h"

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<PathOperationPvt*>(this->p)

class PathOperationPvt{
public:
    PathOperation*parent=nullptr;
    bool _deprecated=false;
    DocumentExternal _externalDocs;
    PathOperation::QApiPathTypeOperation _operation=PathOperation::sptoNotDefined;
    QString _description;
    QString _operationId;
    QString _summary;
    QStringList _consumes;
    QStringList _produces;
    QStringList _security;
    QList<Tag *> _tags;
    QHash<QString, Response*> _responses;
    QList<Parameter *> _parameters;

    explicit PathOperationPvt(PathOperation*parent)
    {
        this->parent=parent;
    }

    virtual ~PathOperationPvt()
    {
    }

};


PathOperation::PathOperation(QObject *parent):ObjectMapper{parent}
{
    this->p=new PathOperationPvt(this);
}

PathOperation::~PathOperation()
{
    dPvtFree();
}

//QVariant PathOperation::toVariant() const
//{
//    const QString qapi_path_operation_consumes = QStringLiteral("consumes");
//    const QString qapi_path_operation_produces = QStringLiteral("produces");
//    dPvt();
//    auto vObject=ObjectMapper::toVariant().toHash();

//    if (!p._consumes.isEmpty())
//        vObject.insert(qapi_path_operation_consumes, toMimeTypesList(p._consumes));

//    if (!p._produces.isEmpty())
//        vObject.insert(qapi_path_operation_produces, toMimeTypesList(p._produces));

//    return vObject;
//}

PathOperation::QApiPathTypeOperation PathOperation::operation() const
{
    dPvt();
    return p._operation;
}

PathOperation &PathOperation::operation(const QVariant &newOperation)
{
    return this->setOperation(newOperation);
}

PathOperation &PathOperation::setOperation(const QVariant &newOperation)
{
    dPvt();
    auto index=qapi_pathTypeOperationList().indexOf(newOperation.toString().toLower());
    if(index>=0)
        p._operation = QApiPathTypeOperation(index);
    else
        p._operation = QApiPathTypeOperation(newOperation.toInt());
    emit operationChanged();
    return*this;
}

PathOperation &PathOperation::resetOperation()
{
    return setOperation({});
}

const QString &PathOperation::description() const
{
    dPvt();
    return p._description;
}

PathOperation &PathOperation::description(const QString &newDescription)
{
    return this->setDescription(newDescription);
}

PathOperation &PathOperation::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._description == newDescription)
        return*this;
    p._description = newDescription;
    emit descriptionChanged();
    return*this;
}

PathOperation &PathOperation::resetDescription()
{
    return setDescription({});
}

const QString &PathOperation::summary() const
{
    dPvt();
    return p._summary;
}

PathOperation &PathOperation::setSummary(const QString &newSummary)
{
    dPvt();
    if (p._summary == newSummary)
        return*this;
    p._summary = newSummary;
    emit summaryChanged();
    return*this;
}

PathOperation &PathOperation::resetSummary()
{
    return setSummary({});
}

bool PathOperation::deprecated() const
{
    dPvt();
    return p._deprecated;
}

PathOperation &PathOperation::setDeprecated(bool newDeprecated)
{
    dPvt();
    if (p._deprecated == newDeprecated)
        return*this;
    p._deprecated = newDeprecated;
    emit deprecatedChanged();
    return*this;
}

PathOperation &PathOperation::resetDeprecated()
{
    return setDeprecated({});
}

QStringList &PathOperation::consumes()
{
    dPvt();
    return p._consumes;
}

PathOperation &PathOperation::consumes(const QString &newConsume)
{
    dPvt();
    if(p._consumes.contains(newConsume))
        return*this;
    return this->setConsumes(QStringList(p._consumes)<<newConsume);
}

PathOperation &PathOperation::consumes(const QStringList &newConsumes)
{
    return this->setConsumes(newConsumes);
}

PathOperation &PathOperation::setConsumes(const QStringList &newConsumes)
{
    dPvt();
    if (p._consumes == newConsumes)
        return*this;
    p._consumes = newConsumes;
    emit consumesChanged();
    return*this;
}

PathOperation &PathOperation::resetConsumes()
{
    return setConsumes({});
}

QStringList &PathOperation::produces()
{
    dPvt();
    return p._produces;
}

PathOperation &PathOperation::produces(const QString &newProduce)
{
    dPvt();
    if(p._produces.contains(newProduce))
        return*this;
    return this->setProduces(QStringList(p._produces)<<newProduce);
}

PathOperation &PathOperation::produces(const QVariant &newProduces)
{
    return this->setProduces(newProduces);
}

PathOperation &PathOperation::setProduces(const QVariant &newProduces)
{
    dPvt();
    switch (qTypeId(newProduces)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        p._produces=newProduces.toStringList();
        break;
    }
    default:
        p._produces << newProduces.toString();
    }
    emit producesChanged();
    return*this;
}

PathOperation &PathOperation::resetProduces()
{
    return setProduces({});
}

QVariantList PathOperation::parametersObject()const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._parameters)
        __return<<item->toVariant();
    return __return;
}

QList<Parameter *> &PathOperation::parameters() const
{
    dPvt();
    return p._parameters;

}

PathOperation &PathOperation::parameters(const QVariant &newParameter)
{
    return this->setParameters(newParameter);
}

PathOperation &PathOperation::parameters(const Parameter &newParameter)
{
    return this->parameters(newParameter.toVariant());
}

PathOperation &PathOperation::setParameters(const QVariant &newParameters)
{
    dPvt();
    if(!newParameters.isValid())
        return*this;
    QVariantList vList;
    switch (qTypeId(newParameters)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        qDeleteAll(p._parameters);
        p._parameters.clear();
        vList=newParameters.toList();
        break;
    }
    default:
        vList<<newParameters;
    }
    for(auto&v:vList){
        auto item=new Parameter(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._parameters<<item;
    }
    emit parametersChanged();
    return*this;
}

PathOperation &PathOperation::setParameters(const QList<Parameter *> &newParameters)
{
    dPvt();
    auto aux=p._parameters;
    p._parameters.clear();
    for(auto&item:newParameters){
        aux.removeOne(item);
        item->setParent(this);
        p._parameters<<item;
    }
    qDeleteAll(aux);
    emit parametersChanged();
    return*this;
}

PathOperation &PathOperation::resetParameters()
{
    return setParameters(QVariantList{});
}

QVariantHash PathOperation::responsesObject()const
{
    dPvt();
    QVariantHash __return;
    for(auto&item:p._responses)
        __return.insert(item->statusCode(), item->toVariant());
    return __return;
}

QHash<QString, Response *> &PathOperation::responses() const
{
    dPvt();
    return p._responses;
}

PathOperation &PathOperation::responses(const QVariant &newResponse)
{
    dPvt();
    switch (qTypeId(newResponse)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    case QMetaType_QVariantMap:
    case QMetaType_QVariantHash:
        return this->setResponses(newResponse.toList());
    default:
        auto item=new Response(this);
        if(!item->load(newResponse)){
            delete item;
            return*this;
        }
        p._responses.insert(item->statusCode(), item);
        emit responsesChanged();
        return*this;
    }
}

PathOperation &PathOperation::responses(const Response &newResponse)
{
    return this->responses(newResponse.toVariant());
}

PathOperation &PathOperation::setResponses(const QVariant &newResponses)
{
    dPvt();
    qDeleteAll(p._responses);
    p._responses.clear();
    switch (qTypeId(newResponses)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        qDeleteAll(p._responses);
        p._responses.clear();
        for(auto&v:newResponses.toList()){
            auto item=new Response(this);
            if(!item->load(v)){
                delete item;
                return*this;
            }
            p._responses.insert(item->statusCode(), item);
            emit responsesChanged();
        }
        break;
    }
    case QMetaType_QVariantMap:
    case QMetaType_QVariantHash:
    {
        qDeleteAll(p._responses);
        p._responses.clear();
        QHashIterator<QString, QVariant> i(newResponses.toHash());
        while(i.hasNext()){
            i.next();
            auto item= new Response(this);
            if(!item->load(i.value())){
                delete item;
                continue;
            }
            p._responses.insert(i.key(), item);
        }
        emit responsesChanged();
        break;
    }
    default:
        auto item=new Response(this);
        if(!item->load(newResponses)){
            delete item;
            return*this;
        }
        p._responses.insert(item->statusCode(), item);
        emit responsesChanged();
    }
    return*this;
}

PathOperation &PathOperation::setResponses(const QList<Response *> &newResponses)
{
    dPvt();
    auto aux=p._responses.values();
    p._responses.clear();
    for(auto&item:newResponses){
        aux.removeOne(item);
        item->setParent(this);
        p._responses.insert(item->statusCode(), item);
    }
    qDeleteAll(aux);
    emit responsesChanged();
    return*this;
}

PathOperation &PathOperation::resetResponses()
{
    return setResponses(QVariantHash{});
}

QVariantList PathOperation::security()const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._security)
        __return<<QVariantHash{{item, QVariant()}};
    return __return;
}

PathOperation &PathOperation::security(const QString &newSecurity)
{
    dPvt();
    if(newSecurity.contains(newSecurity))
        return *this;
    return this->setSecurity(p._security<<newSecurity);
}

PathOperation &PathOperation::security(const QStringList &newSecurity)
{
    return this->setSecurity(newSecurity);
}

PathOperation &PathOperation::setSecurity(const QVariant &newSecurity)
{
    dPvt();
    switch (qTypeId(newSecurity)) {
    case QMetaType_QVariantMap:
    case QMetaType_QVariantHash:
    {
        p._security = newSecurity.toHash().keys();
        break;
    }
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        p._security = newSecurity.toStringList();
        break;
    }
    default:
        p._security.clear();
    }
    emit securityChanged();
    return*this;
}

PathOperation&PathOperation::resetSecurity()
{
    return setSecurity({});
}

QVariantList PathOperation::tagsObject() const
{
    dPvt();
    QVariantList __return;
    for(auto&item : p._tags)
        __return<<item->toVariant();
    return __return;
}

QList<Tag *> &PathOperation::tags() const
{
    dPvt();
    return p._tags;
}

PathOperation &PathOperation::tags(const QVariant &newTag)
{
    return this->setTags(newTag);
}

PathOperation &PathOperation::setTags(const QVariant &newTags)
{
    dPvt();
    switch (qTypeId(newTags)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
        return this->setTags(newTags.toList());
    default:
        auto item= new Tag(this);
        if(!item->load(newTags)){
            delete item;
            return*this;
        }
        p._tags<<item;
        emit tagsChanged();
        return*this;
    }
}

PathOperation &PathOperation::setTags(const QVariantList &newTags)
{
    dPvt();
    qDeleteAll(p._tags);
    p._tags.clear();
    for(auto&v:newTags){
        auto item= new Tag(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._tags<<item;
    }
    emit tagsChanged();
    return*this;
}

PathOperation &PathOperation::resetTags()
{
    return setTags(QVariantList{});
}

const QString &PathOperation::operationId() const
{
    dPvt();
    return p._operationId;
}

PathOperation &PathOperation::operationId(const QVariant &newOperationId)
{
    return this->setOperationId(newOperationId);
}

PathOperation &PathOperation::setOperationId(const QVariant &newOperationId)
{
    dPvt();
    switch (qTypeId(newOperationId)) {
    case QMetaType_QUuid:
        p._operationId = newOperationId.toUuid().toString();
        break;
    default:
        p._operationId = newOperationId.toString();
    }
    emit operationIdChanged();
    return*this;
}

PathOperation &PathOperation::resetOperationId()
{
    return setOperationId({});
}

QVariantList PathOperation::toMimeTypesList(const QStringList &vMimeTypesList) const
{
    QVariantList __return;
    for(const auto&item : vMimeTypesList)
        __return.append(item);
    return __return;
}

QString PathOperation::operationObject()const
{
    dPvt();
    const auto&pathTypeOperationList=qapi_pathTypeOperationList();
    if(p._operation>=0 && p._operation<pathTypeOperationList.count())
        return pathTypeOperationList.at(this->operation());
    return {};
}

DocumentExternal &PathOperation::externalDocs()
{
    dPvt();
    return p._externalDocs;
}

QVariantHash PathOperation::externalDocsObject() const
{
    dPvt();
    return p._externalDocs.toVariant().toHash();
}

PathOperation &PathOperation::externalDocs(const QVariant &newExternalDocs)
{
    return this->setExternalDocs(newExternalDocs);
}

PathOperation &PathOperation::setExternalDocs(const QVariant &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs);
    emit externalDocsChanged();
    return*this;
}

PathOperation &PathOperation::setExternalDocs(const DocumentExternal &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs.toVariant());
    emit externalDocsChanged();
    return*this;
}

PathOperation &PathOperation::resetExternalDocs()
{
    return setExternalDocs(QVariantList{});
}


}

