#include "./qapidoc_document_path.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_path_operation.h"
#include "./qapidoc_document_path_operation_request_parameter.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

namespace QApiDoc{

#define dPvt() auto&p =*reinterpret_cast<PathPvt*>(this->p)

class PathPvt{
public:
    Path*parent=nullptr;
    QList<PathOperation*> _operations;
    QList<RequestParameter*> _parameters;
    QString _uri;

    explicit PathPvt(Path*parent)
    {
        this->parent=parent;
    }

    virtual ~PathPvt()
    {
    }

};

Path::Path(QObject *parent):ObjectMapper{parent}
{
    this->p=new PathPvt(this);
}

Path::~Path()
{
    dPvtFree();
}

QVariant Path::toVariant() const
{
    dPvt();
    QVariantHash __operations;
    for(auto&item:p._operations)
        __operations.insert(item->operationObject(), item->toVariant());
    return QVariantHash{{this->uri(), __operations}};
}

bool Path::load(const QVariant &value)
{
    dPvt();
    auto vHash=value.toHash();
    QHashIterator <QString, QVariant> i(vHash);
    p._operations.clear();
    while(i.hasNext()){
        i.hasNext();

        auto vOperationName = i.value().toString();
        if (vOperationName == QStringLiteral("parameters")){
            this->setParameters(i.value().toList());
            continue;
        }

        QRegularExpression reg(QStringLiteral("(^x-)"));

        if (!reg.match(vOperationName).hasMatch())
            continue;

        auto vOperationObject=vHash.value(i.key()).toHash();
        if(vOperationObject.isEmpty())
            continue;

        auto operation=new PathOperation(this);
        if(!operation->load(vOperationObject)){
            delete operation;
            continue;
        }
        p._operations<<operation;
    }
    return true;
}

QList<PathOperation *> &Path::operations() const
{
    dPvt();
    return p._operations;
}

QVariantList Path::operationsObject()const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._operations)
        __return<<item->toVariant();
    return __return;
}

Path &Path::operations(const QVariantList &newOperations)
{
    return this->setOperations(newOperations);
}

Path &Path::operations(PathOperation *newOperation)
{
    dPvt();
    return this->setOperations(p._operations<<newOperation);
}

Path &Path::setOperations(const QVariantList &newOperations)
{
    dPvt();
    qDeleteAll(p._operations);
    p._operations.clear();
    for(auto&v:newOperations){
        auto item=new PathOperation(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._operations<<item;
    }
    emit operationsChanged();
    return*this;
}

Path &Path::setOperations(const QList<PathOperation *> &newOperations)
{
    dPvt();
    auto aux=p._operations;
    p._operations.clear();
    for(auto&item:newOperations){
        aux.removeOne(item);
        if(!p._operations.contains(item))
            p._operations<<item;
    }
    qDeleteAll(aux);
    emit operationsChanged();
    return*this;
}

Path &Path::resetOperations()
{
    return setOperations(QVariantList{});
}

PathOperation &Path::operation(const QString &newOperation)
{
    const auto&pathTypeOperationHash=qapi_PathTypeOperationHash();
    int typeOperation=QApiPathTypeOperation::sptoNotDefined;
    if(pathTypeOperationHash.contains(newOperation.trimmed().toLower()))
        typeOperation=pathTypeOperationHash.value(newOperation.trimmed().toLower());

    return this->operation(QApiPathTypeOperation(typeOperation));
}

PathOperation &Path::operation(const int &newOperation)
{
    dPvt();
    auto pathOperation=new PathOperation(this);
    pathOperation->setOperation(newOperation);
    p._operations<<pathOperation;
    return *pathOperation;
}

const QString &Path::uri() const
{
    dPvt();
    return p._uri;
}

Path &Path::uri(const QString &newUri)
{
    return this->setUri(newUri);
}

Path &Path::setUri(const QString &newUri)
{
    dPvt();
    if (p._uri == newUri)
        return*this;
    p._uri = newUri;
    emit uriChanged();
    return*this;
}

Path &Path::resetUri()
{
    return setUri({});
}

const QVariantList Path::parametersObject() const
{
    dPvt();
    QVariantList __return;
    for(auto&item:p._parameters)
        __return<<item->toVariant();
    return __return;
}

const QList<RequestParameter *> Path::parameters() const
{
    dPvt();
    return p._parameters;
}

Path &Path::parameters(RequestParameter *newParameters)
{
    dPvt();
    return this->setParameters(p._parameters<<newParameters);
}

Path &Path::parameters(const QVariantList &newParameters)
{
    return this->setParameters(newParameters);
}

Path &Path::setParameters(const QVariantList &newParameters)
{
    dPvt();
    qDeleteAll(p._parameters);
    p._parameters.clear();
    for(auto&v:newParameters){
        auto item= new RequestParameter(this);
        if(!item->load(v)){
            delete item;
            continue;
        }
        p._parameters<<item;
    }
    emit parametersChanged();
    return*this;
}

Path &Path::setParameters(const QList<RequestParameter *> &newParameters)
{
    dPvt();
    auto aux=p._parameters;
    p._parameters.clear();
    for(auto&item:newParameters){
        aux.removeOne(item);

        if(!aux.contains(item))
            p._parameters<<item;
    }
    qDeleteAll(aux);
    emit parametersChanged();
    return*this;
}

Path &Path::resetParameters()
{
    return this->setParameters(QVariantList{});
}

}

