#include "./qapidoc_object_mapper.h"
#include <QMetaProperty>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

namespace QApiDoc{

ObjectMapper::ObjectMapper(QObject *parent)
    : QObject{parent}
{

}

ObjectMapper::~ObjectMapper()
{

}

ObjectMapper &ObjectMapper::operator =(const QVariant &value)
{
    this->load(value);
    return*this;
}

ObjectMapper &ObjectMapper::operator<<(const QVariant &value)
{
    this->read(value);
    return*this;
}

ObjectMapper &ObjectMapper::operator+=(const QVariant &value)
{
    this->read(value);
    return*this;
}

QVariant ObjectMapper::toVariant() const
{
    QVariantHash __return;
    const auto &object_ignore_methods=QApiDoc::object_ignore_methods();
    auto&metaObject = *this->metaObject();
    for(int col = 0; col < metaObject.propertyCount(); ++col) {
        auto property = metaObject.property(col);

        if(object_ignore_methods.contains(property.name()))
            continue;

        const auto value=property.read(this);

        if(value.isNull() || !value.isValid())
            continue;

        switch (qTypeId(property)) {
        case QMetaType_Double:
        case QMetaType_Int:
        case QMetaType_UInt:
        case QMetaType_LongLong:
        case QMetaType_ULongLong:
        case QMetaType_User:
            if(value.toDouble()==0)
                continue;
            break;
        case QMetaType_QUuid:
            if(value.toUuid().isNull())
                continue;
            break;
        case QMetaType_QUrl:
            if(!value.toUrl().isEmpty())
                continue;
            break;
        case QMetaType_QDate:
            if(!value.toDate().isValid())
                continue;
            break;
        case QMetaType_QTime:
            if(!value.toTime().isValid())
                continue;
            break;
        case QMetaType_QDateTime:
            if(!value.toDateTime().isValid())
                continue;
            break;
        case QMetaType_QString:
        case QMetaType_QByteArray:
        case QMetaType_QChar:
        case QMetaType_QBitArray:
            if(value.toByteArray().trimmed().isEmpty())
                continue;
            break;
        case QMetaType_QVariantMap:
        case QMetaType_QVariantHash:
            if(value.toHash().isEmpty())
                continue;
            break;
        case QMetaType_QVariantList:
        case QMetaType_QStringList:
            if(value.toList().isEmpty())
                continue;
            break;
        default:
            break;
        }
        __return.insert(property.name(), value);
    }
    return __return.isEmpty()?QVariant():__return;
}

QVariant ObjectMapper::toHash() const
{
    return this->toVariant().toHash();
}

QVariant ObjectMapper::toMap() const
{
    return this->toVariant().toMap();
}

QByteArray ObjectMapper::toJson() const
{
    return QJsonDocument::fromVariant(this->toVariant()).toJson(QJsonDocument::Indented);
}

ObjectMapper &ObjectMapper::clear()
{
    const auto &object_ignore_methods=QApiDoc::object_ignore_methods();
    auto metaObject=this->metaObject();
    for(int col = 0; col < metaObject->propertyCount(); ++col) {
        auto property = metaObject->property(col);

        if(object_ignore_methods.contains(property.name()))
            continue;

        switch (qTypeId(property)) {
        case QMetaType_User:
            property.write(this, 0);
            continue;
        case QMetaType_QUuid:
            property.write(this, QUuid());
            continue;
        case QMetaType_QUrl:
            property.write(this, QUrl());
            continue;
        case QMetaType_QDate:
            property.write(this, QDate());
            continue;
        case QMetaType_QTime:
            property.write(this, QTime());
            continue;
        case QMetaType_QDateTime:
            property.write(this, QDateTime());
            continue;
        case QMetaType_Double:
        case QMetaType_Int:
        case QMetaType_UInt:
        case QMetaType_LongLong:
        case QMetaType_ULongLong:
            property.write(this, 0);
            continue;
        case QMetaType_QString:
            property.write(this, QString{});
            continue;
        case QMetaType_QByteArray:
            property.write(this, QByteArray{});
            continue;
        case QMetaType_QChar:
            property.write(this, QChar());
            continue;
        case QMetaType_QBitArray:
            property.write(this, QBitArray());
            continue;
        case QMetaType_QVariantMap:
            property.write(this, QVariantMap());
            continue;
        case QMetaType_QVariantHash:
            property.write(this, QVariantHash());
            continue;
        case QMetaType_QVariantList:
            property.write(this, QVariantList());
            continue;
        case QMetaType_QStringList:
            property.write(this, QStringList());
            continue;
        default:
            property.write(this, QVariant());
        }
    }
    return*this;
}

bool ObjectMapper::isEmpty()
{
    return !this->toVariant().isValid();
}

bool ObjectMapper::load(const QVariant &value)
{
    return this->clear().read(value);
}

bool ObjectMapper::read(const QVariant &value)
{
    const auto &object_ignore_methods=QApiDoc::object_ignore_methods();
    QVariantHash vHash;
    switch (qTypeId(value)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
    {
        auto vList=value.toList();
        return this->read(vList.isEmpty()?QVariantHash{}:vList.first());
    }
    case QMetaType_QVariantHash:
    case QMetaType_QVariantMap:
    {
        vHash=value.toHash();
        break;
    }
    case QMetaType_QString:
    case QMetaType_QByteArray:
    {
        QFile file(value.toString());
        if (file.exists()){
            if(!file.open(file.ReadOnly)){
                qWarning()<<file.errorString();
                return {};
            }
            auto bytes=file.readAll();
            file.close();
            return this->read(QJsonDocument::fromJson(bytes).toVariant());
        }
        return this->read(QJsonDocument::fromJson(file.readAll()).toVariant());
    }
    default:
        return {};
    }

    if(vHash.isEmpty())
        return {};

    QHash<QString, QMetaProperty> propertList;
    auto&metaObject = *this->metaObject();
    for(int col = 0; col < metaObject.propertyCount(); ++col) {
        auto property = metaObject.property(col);
        if(object_ignore_methods.contains(property.name()))
            continue;

        propertList.insert(QByteArray(property.name()).toLower(), property);
    }

    bool __return=false;
    QHashIterator<QString, QVariant> i(vHash);
    while(i.hasNext())
    {
        i.next();
        const auto&v=i.value();
        if(v.isNull() || !v.isValid())
            continue;

        auto p=propertList.value(i.key().toLower());
        if(p.write(this, v))
            __return=true;
    }
    return __return;
}

bool ObjectMapper::load(QObject *object)
{
    this->clear();
    QVariantHash vHash;
    const auto &object_ignore_methods=QApiDoc::object_ignore_methods();
    auto&metaObject = *object->metaObject();
    for(int col = 0; col < metaObject.propertyCount(); ++col) {
        auto property = metaObject.property(col);

        if(object_ignore_methods.contains(property.name()))
            continue;

        vHash[QByteArray(property.name()).toLower()]=property.read(object);
    }
    return this->read(vHash);
}

bool ObjectMapper::save(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(file.Unbuffered | file.Truncate | file.WriteOnly)){
        qWarning()<<file.errorString();
        return false;
    }
    file.write(this->toJson());
    file.flush();
    file.close();
    return true;
}

}

