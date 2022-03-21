#include "./qapidoc_document_tags.h"

namespace QApiDoc {

#define dPvt() auto &p = *reinterpret_cast<TagPvt *>(this->p)

class TagPvt
{
public:
    Tag *parent = nullptr;
    DocumentExternal _externalDocs;
    QString _description;
    QString _name;

    explicit TagPvt(Tag *parent) { this->parent = parent; }

    virtual ~TagPvt() {}
};

Tag::Tag(QObject *parent) : ObjectMapper{parent}
{
    this->p = new TagPvt{this};
}

Tag::~Tag()
{
    dPvt();
    delete &p;
}

const QString &Tag::description() const
{
    dPvt();
    return p._description;
}

Tag &Tag::description(const QString &newDescription)
{
    return this->setDescription(newDescription);
}

Tag &Tag::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._description == newDescription)
        return *this;
    p._description = newDescription;
    emit descriptionChanged();
    return *this;
}

Tag &Tag::resetDescription()
{
    return setDescription({});
}

const DocumentExternal &Tag::externalDocs() const
{
    dPvt();
    return p._externalDocs;
}

QVariantHash Tag::externalDocsObject() const
{
    dPvt();
    return p._externalDocs.toVariant().toHash();
}

Tag &Tag::externalDocs(const QVariant &newExternalDocs)
{
    return this->setExternalDocs(newExternalDocs);
}

Tag &Tag::setExternalDocs(const QVariant &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs);
    emit externalDocsChanged();
    return *this;
}

Tag &Tag::setExternalDocs(const DocumentExternal &newExternalDocs)
{
    dPvt();
    p._externalDocs.load(newExternalDocs.toVariant());
    emit externalDocsChanged();
    return *this;
}

Tag &Tag::resetExternalDocs()
{
    return setExternalDocs(QVariantList{});
}

const QString &Tag::name() const
{
    dPvt();
    return p._name;
}

Tag &Tag::name(const QString &newName)
{
    return this->setName(newName);
}

Tag &Tag::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return *this;
    p._name = newName;
    emit nameChanged();
    return *this;
}

Tag &Tag::resetName()
{
    return setName({});
}

} // namespace QApiDoc
