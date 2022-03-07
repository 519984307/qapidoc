#include "./qapidoc_object_mapper.h"
#include <QMetaProperty>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

namespace QApiDoc{

static bool writeProperty(QObject*object, const QMetaProperty&property, const QVariant&value)
{
    auto type = qTypeId(property);
    QVariant vValue=value;

    if(property.write(object, vValue))
        return true;

    if(QStmTypesListString.contains(type)){
        QVariant v;
        if(QStmTypesListObjects.contains(qTypeId(value)))
            v=QJsonDocument::fromVariant(vValue).toJson(QJsonDocument::Compact);
        else
            v=vValue.toByteArray();

        switch (type) {
        case QMetaType_QUuid:
            if(property.write(object, vValue.toUuid()))
                return true;
            break;
        case QMetaType_QString:
            if(property.write(object, v.toString()))
                return true;
            break;
        case QMetaType_QByteArray:
            if(property.write(object, v.toByteArray()))
                return true;
            break;
        case QMetaType_QChar:
            if(property.write(object, v.toChar()))
                return true;
            break;
        case QMetaType_QBitArray:
            if(property.write(object, v.toBitArray()))
                return true;
            break;
        default:
            return false;
        }
    }

    if(QStmTypesListIntegers.contains(type)){//ints

        switch (type) {
        case QMetaType_LongLong:
        case QMetaType_ULongLong:
            if(property.write(object, static_cast<qlonglong>(QLocale::c().toDouble(vValue.toString()))))
                return true;
            if(property.write(object, QLocale::c().toLongLong(vValue.toString())))
                return true;
            break;
        case QMetaType_Int:
        case QMetaType_UInt:
            if(property.write(object, QLocale::c().toInt(vValue.toString())))
                return true;
            if(property.write(object, QLocale::c().toInt(vValue.toString())))
                return true;
            if(property.write(object, QLocale::c().toUInt(vValue.toString())))
                return true;
            break;
        case QMetaType_Double:
            if(property.write(object, QLocale::c().toDouble(vValue.toString())))
                return true;
            break;
        default:
            return false;
        }
    }

    if(QStmTypesListClass.contains(type)){
        switch (type) {
        case QMetaType_QUrl:
            if(property.write(object, vValue.toUrl()))
                return true;
            break;
        case QMetaType_QVariantMap:
            if(property.write(object, vValue.toHash()))
                return true;
            break;
        case QMetaType_QVariantHash:
            if(property.write(object, vValue.toHash()))
                return true;
            break;
        case QMetaType_QVariantList:
            if(property.write(object, vValue.toList()))
                return true;
            break;
        case QMetaType_QStringList:
            if(property.write(object, vValue.toStringList()))
                return true;
            break;
        default:
            return false;
        }
    }
    else if(QStmTypesListDates.contains(type)){
        switch (type) {
        case QMetaType_QDate:
            if(property.write(object, vValue.toDate()))
                return true;
            break;
        case QMetaType_QDateTime:
            if(property.write(object, vValue.toDateTime()))
                return true;
            break;
        case QMetaType_QTime:
            if(property.write(object, vValue.toTime()))
                return true;
            break;
        default:
            return false;
        }
    }

    if(QStmTypesListBool.contains(type) || QStmTypesListBool.contains(qTypeId(value))){

        switch (type) {
        case QMetaType_Bool:
            if(property.write(object, vValue.toBool()))
                return true;
            break;
        default:
            break;
        }

        switch (qTypeId(vValue)){
        case QMetaType_Bool:
            if(property.write(object, vValue.toBool()))
                return true;
            break;
        case QMetaType_Int:
        case QMetaType_UInt:
        case QMetaType_ULongLong:
        case QMetaType_LongLong:
        case QMetaType_Double:
            if(property.write(object, (vValue.toInt()==1)))
                return true;
            break;
        case QMetaType_QString:
        case QMetaType_QByteArray:
        case QMetaType_QChar:
        {
            auto vv=vValue.toString().toLower();
            bool vBool=(vv==QStringLiteral("true"));
            if(property.write(object, vBool))
                return true;
            break;
        }
        default:
            return false;
        }
    }
    return false;
}

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

QVariantHash ObjectMapper::toHash() const
{
    return this->toVariant().toHash();
}

QVariantMap ObjectMapper::toMap() const
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

        auto&p=propertList.value(i.key().toLower());
        if(writeProperty(this, p, v))
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

