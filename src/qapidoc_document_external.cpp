#include "./qapidoc_document_external.h"

#define dPvt() auto&p =*reinterpret_cast<ExternalDocumentPvt*>(this->p)

namespace QApiDoc{


class ExternalDocumentPvt{
public:
    DocumentExternal*parent=nullptr;
    QString _description;
    QString _url;

    explicit ExternalDocumentPvt(DocumentExternal*parent)
    {
        this->parent=parent;
    }

    virtual ~ExternalDocumentPvt()
    {
    }
};


DocumentExternal::DocumentExternal(QObject *parent):ObjectMapper{parent}
{
    this->p=new ExternalDocumentPvt(this);
}

DocumentExternal::~DocumentExternal()
{
    dPvtFree();
}

const QString &DocumentExternal::url() const
{
    dPvt();
    return p._url;
}

DocumentExternal &DocumentExternal::url(const QString &newUrl)
{
    return this->setUrl(newUrl);
}

DocumentExternal &DocumentExternal::setUrl(const QString &newUrl)
{
    dPvt();
    if (p._url == newUrl)
        return*this;
    p._url = newUrl;
    emit urlChanged();
    return*this;
}

DocumentExternal &DocumentExternal::resetUrl()
{
    return setUrl({});
}

const QString &DocumentExternal::description() const
{
    dPvt();
    return p._description;
}

DocumentExternal &DocumentExternal::description(const QString &newDescription)
{
    return this->setDescription(newDescription);
}

DocumentExternal &DocumentExternal::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._description == newDescription)
        return*this;
    p._description = newDescription;
    emit descriptionChanged();
    return*this;
}

DocumentExternal &DocumentExternal::resetDescription()
{
    return setDescription({});
}

}
