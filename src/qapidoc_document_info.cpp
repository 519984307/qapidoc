#include "./qapidoc_document_info.h"

namespace QApiDoc {

#define dPvt() auto &p = *reinterpret_cast<InfoPvt *>(this->p)

class InfoPvt
{
public:
    Info *parent = nullptr;
    InfoContact _contact;
    InfoLicense _license;
    QString _description;
    QString _termsOfService;
    QString _title;
    QString _version;

    explicit InfoPvt(Info *parent) { this->parent = parent; }

    virtual ~InfoPvt() {}
};

Info::Info(QObject *parent) : ObjectMapper{parent}
{
    this->p = new InfoPvt{this};
}

Info::~Info()
{
    dPvtFree();
}

const QString &Info::version() const
{
    dPvt();
    return p._version;
}

Info &Info::version(const QString &newVersion)
{
    this->setVersion(newVersion);
    return *this;
}

Info &Info::setVersion(const QString &newVersion)
{
    dPvt();
    if (p._version == newVersion)
        return *this;
    p._version = newVersion;
    emit versionChanged();
    return *this;
}

Info &Info::resetVersion()
{
    return setVersion({});
}

const QString &Info::title() const
{
    dPvt();
    return p._title;
}

Info &Info::title(const QString &newTitle)
{
    this->setTitle(newTitle);
    return *this;
}

Info &Info::setTitle(const QString &newTitle)
{
    dPvt();
    if (p._title == newTitle)
        return *this;
    p._title = newTitle;
    emit titleChanged();
    return *this;
}

Info &Info::resetTitle()
{
    return setTitle({});
}

const QString &Info::description() const
{
    dPvt();
    return p._description;
}

Info &Info::description(const QString &newDescription)
{
    this->setDescription(newDescription);
    return *this;
}

Info &Info::setDescription(const QString &newDescription)
{
    dPvt();
    if (p._description == newDescription)
        return *this;
    p._description = newDescription;
    emit descriptionChanged();
    return *this;
}

Info &Info::resetDescription()
{
    return setDescription({});
}

const QString &Info::termsOfService()
{
    dPvt();
    return p._termsOfService;
}

Info &Info::termsOfService(const QString &newTermsOfService)
{
    this->setTermsOfService(newTermsOfService);
    return *this;
}

Info &Info::setTermsOfService(const QString &newTermsOfService)
{
    dPvt();
    if (p._termsOfService == newTermsOfService)
        return *this;
    p._termsOfService = newTermsOfService;
    emit termsOfServiceChanged();
    return *this;
}

Info &Info::resetTermsOfService()
{
    return setTermsOfService({});
}

InfoContact &Info::contact()
{
    dPvt();
    return p._contact;
}

QVariantHash Info::contactObject() const
{
    dPvt();
    return p._contact.toVariant().toHash();
}

Info &Info::contact(const QVariant &newContact)
{
    return this->setContact(newContact);
}

Info &Info::setContact(const QVariant &newContact)
{
    dPvt();
    p._contact.load(newContact);
    return *this;
}

Info &Info::setContact(const InfoContact &newContact)
{
    dPvt();
    p._contact.load(newContact.toVariant());
    emit contactChanged();
    return *this;
}

Info &Info::resetContact()
{
    dPvt();
    p._contact.clear();
    return *this;
}

InfoLicense &Info::license()
{
    dPvt();
    return p._license;
}

QVariantHash Info::licenseObject() const
{
    dPvt();
    return p._license.toVariant().toHash();
}

Info &Info::license(const QVariant &newLicense)
{
    return this->setLicense(newLicense);
}

Info &Info::setLicense(const QVariant &newLicense)
{
    dPvt();
    p._license.load(newLicense);
    return *this;
}

Info &Info::setLicense(const InfoLicense &newLicense)
{
    dPvt();
    p._license.load(newLicense.toVariant());
    emit licenseChanged();
    return *this;
}

Info &Info::resetLicense()
{
    dPvt();
    p._license.clear();
    return *this;
}

} // namespace QApiDoc
