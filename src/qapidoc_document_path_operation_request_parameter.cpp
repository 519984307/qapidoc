#include "./qapidoc_document_path_operation_request_parameter.h"

static const QStringList &__typeParameter()
{
    return qapi_TypeParameter();
}

namespace QApiDoc{

#define dPvt()\
auto&p =*reinterpret_cast<RequestParameterPvt*>(this->p)

class RequestParameterPvt{
public:
    RequestParameter*parent=nullptr;
    bool _allowEmptyValue=false;
    bool _requiredValue=false;
    Definition _schema;
    QString _defaultValuehema;
    QString _descriptionehema;
    QString _format;
    QString _name;
    QString _pattern;
    QString _ref;
    QStringList _enumValuef;
    QVariantHash _items;
    RequestParameter::QApiRequestParameterInLocation _inLocation=RequestParameter::srplPath;
    RequestParameter::QApiTypeParameter _typeParameter;

    explicit RequestParameterPvt(RequestParameter*parent)
    {
        this->parent=parent;
    }

    virtual ~RequestParameterPvt()
    {
    }

};

RequestParameter::RequestParameter(QObject *parent):ObjectMapper{parent}
{
    this->p=new RequestParameterPvt(this);
}

RequestParameter::~RequestParameter()
{
    dPvtFree();
}

RequestParameter::QApiRequestParameterInLocation RequestParameter::inLocation() const
{
    dPvt();
    return p._inLocation;
}

RequestParameter &RequestParameter::inLocation(const QVariant &newInLocation)
{
    return this->setInLocation(newInLocation);
}

RequestParameter &RequestParameter::setInLocation(const QVariant&newInLocation)
{
    dPvt();
    if (p._inLocation == newInLocation)
        return*this;
    auto index=qapi_requestParameterInLocation().indexOf(newInLocation.toString().toLower());
    if(index>=0)
        p._inLocation=QApiRequestParameterInLocation(index);
    else
        p._inLocation = QApiRequestParameterInLocation(newInLocation.toInt());
    emit inLocationChanged();
    return*this;
}

RequestParameter &RequestParameter::resetInLocation()
{
    return setInLocation({}); 
}

QString RequestParameter::inLocationToString() const
{
    dPvt();
    return qapi_requestParameterInLocation().at(p._inLocation);
}

bool RequestParameter::required() const
{
    dPvt();
    return p._requiredValue;
}

RequestParameter &RequestParameter::required(bool newRequired)
{
    return this->setRequired(newRequired);
}

RequestParameter &RequestParameter::setRequired(bool newRequired)
{
    dPvt();
    if (p._requiredValue == newRequired)
        return*this;
    p._requiredValue = newRequired;
    emit requiredChanged();
    return*this;
}

RequestParameter &RequestParameter::resetRequired()
{
    return setRequired({}); 
}

Definition &RequestParameter::schema()
{
    dPvt();
    return p._schema;
}

QVariantHash RequestParameter::schemaObject()
{
    dPvt();
    return p._schema.toVariant().toHash();
}

RequestParameter &RequestParameter::schema(const QVariant &newSchema)
{
    return this->setSchema(newSchema);
}

RequestParameter &RequestParameter::setSchema(const QVariant &newSchema)
{
    dPvt();
    p._schema.load(newSchema);
    emit schemaChanged();
    return*this;
}

RequestParameter &RequestParameter::setSchema(const Definition &newSchema)
{
    dPvt();
    p._schema.load(newSchema.toVariant());
    emit schemaChanged();
    return*this;
}

RequestParameter &RequestParameter::resetSchema()
{
    //    setSchema({}); 
    return*this;
}

const QString &RequestParameter::description() const
{
    dPvt();
    return p._descriptionehema;
}

RequestParameter &RequestParameter::description(const QString &newDescription)
{
    return this->setDescription(newDescription);
}

RequestParameter &RequestParameter::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._descriptionehema == newDescription)
        return*this;
    p._descriptionehema = newDescription;
    emit descriptionChanged();
    return*this;
}

RequestParameter &RequestParameter::resetDescription()
{
    return setDescription({}); 
}

RequestParameter::QApiTypeParameter RequestParameter::typeParameter() const
{
    dPvt();
    return p._typeParameter;
}

RequestParameter &RequestParameter::typeParameter(const int &newTypeParameter)
{
    return this->setTypeParameter(newTypeParameter);
}

RequestParameter &RequestParameter::setTypeParameter(const QVariant &newTypeParameter)
{
    dPvt();
    if (p._typeParameter == newTypeParameter)
        return*this;
    auto index=__typeParameter().indexOf(newTypeParameter.toString().toLower());
    if(index>=0)
        p._typeParameter=QApiTypeParameter(index);
    else
        p._typeParameter = QApiTypeParameter(newTypeParameter.toInt());
    emit typeParameterChanged();
    return*this;
}

RequestParameter &RequestParameter::resetTypeParameter()
{
    return setTypeParameter({}); 
}

const QString &RequestParameter::pattern() const
{
    dPvt();
    return p._pattern;
}

RequestParameter &RequestParameter::pattern(const QString &newPattern)
{
    return this->setPattern(newPattern);
}

RequestParameter &RequestParameter::setPattern(const QString &newPattern)
{
    dPvt();
    if (p._pattern == newPattern)
        return*this;
    p._pattern = newPattern;
    emit patternChanged();
    return*this;
}

RequestParameter &RequestParameter::resetPattern()
{
    return setPattern({}); 
}

const QVariantHash &RequestParameter::items() const
{
    dPvt();
    return p._items;
}

RequestParameter &RequestParameter::setItems(const QVariantHash &newItems)
{
    dPvt();
    if (p._items == newItems)
        return*this;
    p._items = newItems;
    emit itemsChanged();
    return*this;
}

RequestParameter &RequestParameter::resetItems()
{
    return setItems({}); 
}

const QString &RequestParameter::format() const
{
    dPvt();
    return p._format;
}

RequestParameter &RequestParameter::format(const QString &newFormat)
{
    return this->setFormat(newFormat);
}

RequestParameter &RequestParameter::setFormat(const QString &newFormat)
{
    dPvt();
    if (p._format == newFormat)
        return*this;
    p._format = newFormat;
    emit formatChanged();
    return*this;
}

RequestParameter &RequestParameter::resetFormat()
{
    return setFormat({}); 
}

const QString &RequestParameter::defaultValue() const
{
    dPvt();
    return p._defaultValuehema;
}

RequestParameter &RequestParameter::defaultValue(const QString &newDefault)
{
    return this->setDefaultValue(newDefault);
}

RequestParameter &RequestParameter::setDefaultValue(const QString &newDefault)
{
    dPvt();
    if (p._defaultValuehema == newDefault)
        return*this;
    p._defaultValuehema = newDefault;
    emit defaultValueChanged();
    return*this;
}

RequestParameter &RequestParameter::resetDefaultValue()
{
    return setDefaultValue({}); 
}

QStringList &RequestParameter::enumValue()
{
    dPvt();
    return p._enumValuef;
}

RequestParameter &RequestParameter::enumValue(const QStringList &newEnum)
{
    return this->setEnumValue(newEnum);
}

RequestParameter &RequestParameter::setEnumValue(const QStringList &newEnum)
{
    dPvt();
    p._enumValuef = newEnum;
    emit enumValueChanged();
    return*this;
}

RequestParameter &RequestParameter::resetEnumValue()
{
    return setEnumValue({}); 
}

bool RequestParameter::allowEmptyValue() const
{
    dPvt();
    return p._allowEmptyValue;
}

RequestParameter &RequestParameter::allowEmptyValue(bool newAllowEmptyValue)
{
    return this->setAllowEmptyValue(newAllowEmptyValue);
}

RequestParameter &RequestParameter::setAllowEmptyValue(bool newAllowEmptyValue)
{
    dPvt();
    if (p._allowEmptyValue == newAllowEmptyValue)
        return*this;
    p._allowEmptyValue = newAllowEmptyValue;
    emit allowEmptyValueChanged();
    return*this;
}

RequestParameter &RequestParameter::resetAllowEmptyValue()
{
    return setAllowEmptyValue({}); 
}

const QString &RequestParameter::ref() const
{
    dPvt();
    return p._ref;
}

RequestParameter &RequestParameter::ref(const QString &newRef)
{
    return this->setRef(newRef);
}

RequestParameter &RequestParameter::setRef(const QString &newRef)
{
    dPvt();
    if (p._ref == newRef)
        return*this;
    p._ref = newRef;
    emit refChanged();
    return*this;
}

RequestParameter &RequestParameter::resetRef()
{
    return setRef({}); 
}

const QString &RequestParameter::name() const
{
    dPvt();
    return p._name;
}

RequestParameter &RequestParameter::name(const QString &newName)
{
    return this->setName(newName);
}

RequestParameter &RequestParameter::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return*this;
    p._name = newName;
    emit nameChanged();
    return*this;
}

RequestParameter &RequestParameter::resetName()
{
    return setName({}); 
}

}


