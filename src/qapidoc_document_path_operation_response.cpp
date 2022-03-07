#include "./qapidoc_document_path_operation_response.h"

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<ResponsePvt*>(this->p)

class ResponsePvt{
public:
    Response*parent=nullptr;
    Definition _schema;
    QString _description;
    QVariant _statusCode;
    QVariantHash _examples;
    QList<Headers*> _headers;

    explicit ResponsePvt(Response*parent)
    {
        this->parent=parent;
    }

    virtual ~ResponsePvt()
    {
    }

};

Response::Response(QObject *parent):ObjectMapper{parent}
{
    this->p=new ResponsePvt(this);
}

Response::~Response()
{
    dPvtFree();
}

QString Response::statusCode()const
{
    dPvt();
    return p._statusCode.toString();
}

Response &Response::statusCode(const QVariant &newStatusCode)
{
    return this->setStatusCode(newStatusCode);
}

Response &Response::setStatusCode(const QVariant &newStatusCode)
{
    dPvt();
    if (p._statusCode == newStatusCode)
        return*this;
    p._statusCode = newStatusCode.toString();
    emit statusCodeChanged();
    return*this;
}

Response&Response::resetStatusCode()
{
    return setStatusCode({}); 
}

Definition &Response::schema()
{
    dPvt();
    return p._schema;
}

QVariantHash Response::schemaObject()
{
    dPvt();
    return p._schema.toVariant().toHash();
}

Response &Response::setSchema(const QVariant &newSchema)
{
    dPvt();
    p._schema.load(newSchema);
    emit schemaChanged();
    return*this;
}

Response &Response::setSchema(const Definition &newSchema)
{
    dPvt();
    p._schema.load(newSchema.toVariant());
    emit schemaChanged();
    return*this;
}

Response &Response::resetSchema()
{
    dPvt();
    p._schema.clear();
    return*this;
}

QVariantList Response::headersObject() const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._headers){
        __return<<item->toVariant();
    }
    return __return;
}

QList<Headers *> &Response::headers() const
{
    dPvt();
    return p._headers;
}

Response &Response::headers(const QVariantList &newHeaders)
{
    return this->setHeaders(newHeaders);
}

Response &Response::setHeaders(const QVariantList &newHeaders)
{
    dPvt();
    qDeleteAll(p._headers);
    p._headers.clear();
    for(auto&v:newHeaders){
        auto item=new Headers();
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._headers<<item;
    }
    emit headersChanged();
    return*this;
}

Response &Response::setHeaders(const QList<Headers *> &newHeaders)
{
    dPvt();
    auto aux=p._headers;
    p._headers.clear();
    for(auto&item:newHeaders){
        aux.removeOne(item);
        p._headers<<item;
    }
    qDeleteAll(aux);
    emit headersChanged();
    return*this;
}

Response &Response::resetHeaders()
{
    return setHeaders(QVariantList{}); 
}

const QString &Response::description() const
{
    dPvt();
    return p._description;
}

Response &Response::description(const QString &newDescription)
{
    return this->setDescription(newDescription);
}

Response &Response::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._description == newDescription)
        return*this;
    p._description = newDescription;
    emit descriptionChanged();
    return*this;
}

Response &Response::resetDescription()
{
    return setDescription({}); 
}

QVariantHash &Response::examples()
{
    dPvt();
    return p._examples;
}

Response &Response::examples(const QVariantHash &newExamples)
{
    return this->setExamples(newExamples);
}

Response &Response::setExamples(const QVariantHash &newExamples)
{
    dPvt();
    if (p._examples == newExamples)
        return*this;
    p._examples = newExamples;
    emit examplesChanged();
    return*this;
}

Response &Response::resetExamples()
{
    return setExamples({}); 
}

const QVariantHash Response::toExamplestoHash() const
{
    dPvt();
    int vExampleNumber=0;
    QVariantHash __return;
    vExampleNumber = 0;
    QHashIterator<QString, QVariant> i(p._examples);
    while(i.hasNext()){
        i.next();
        __return.insert(QString::number(++vExampleNumber), i.value());
    }
    return __return;
}


}

