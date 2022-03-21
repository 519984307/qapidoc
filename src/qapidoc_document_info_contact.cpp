#include "./qapidoc_document_info_contact.h"

namespace QApiDoc {

#define dPvt() auto &p = *reinterpret_cast<InfoContactPvt *>(this->p)

class InfoContactPvt
{
public:
    InfoContact *parent = nullptr;
    QString _email;
    QString _name;
    QString _url;
    explicit InfoContactPvt(InfoContact *parent) { this->parent = parent; }

    virtual ~InfoContactPvt() {}
};

InfoContact::InfoContact(QObject *parent) : ObjectMapper{parent}
{
    this->p = new InfoContactPvt{this};
}

InfoContact::~InfoContact()
{
    dPvtFree();
}

const QString &InfoContact::name() const
{
    dPvt();
    return p._name;
}

InfoContact &InfoContact::name(const QString &newName)
{
    this->setName(newName);
    return *this;
}

InfoContact &InfoContact::setName(const QString &newName)
{
    dPvt();
    if (p._name == newName)
        return *this;
    p._name = newName;
    emit nameChanged();
    return *this;
}

InfoContact &InfoContact::resetName()
{
    return setName({});
}

const QString &InfoContact::email() const
{
    dPvt();
    return p._email;
}

InfoContact &InfoContact::email(const QString &newEmail)
{
    this->setEmail(newEmail);
    return *this;
}

InfoContact &InfoContact::setEmail(const QString &newEmail)
{
    dPvt();
    if (p._email == newEmail)
        return *this;
    p._email = newEmail;
    emit emailChanged();
    return *this;
}

InfoContact &InfoContact::resetEmail()
{
    return setEmail({});
}

const QString &InfoContact::url() const
{
    dPvt();
    return p._url;
}

InfoContact &InfoContact::url(const QString &newUrl)
{
    this->setUrl(newUrl);
    return *this;
}

InfoContact &InfoContact::setUrl(const QString &newUrl)
{
    dPvt();
    if (p._url == newUrl)
        return *this;
    p._url = newUrl;
    emit urlChanged();
    return *this;
}

InfoContact &InfoContact::resetUrl()
{
    return setUrl({});
}

} // namespace QApiDoc
