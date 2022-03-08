#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_document_external.h"

namespace QApiDoc{

class Q_API_DOC_EXPORT Tag : public ObjectMapper
{
    Q_OBJECT

    //!
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //!
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription NOTIFY descriptionChanged)

    //!
    Q_PROPERTY(QVariantHash externalDocs READ externalDocsObject WRITE setExternalDocs RESET resetExternalDocs NOTIFY externalDocsChanged)

public:
    Q_INVOKABLE explicit Tag(QObject*parent=nullptr);
    ~Tag();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    Tag &name(const QString &newName);
    Tag &setName(const QString &newName);
    Tag &resetName();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    Tag &description(const QString &newDescription);
    Tag &setDescription(const QString &newDescription);
    Tag &resetDescription();

    //!
    //! \brief externalDocs
    //! \return
    //!
    const DocumentExternal &externalDocs() const;
    QVariantHash externalDocsObject() const;
    Tag &externalDocs(const QVariant &newExternalDocs);
    Tag &setExternalDocs(const QVariant &newExternalDocs);
    Tag &setExternalDocs(const DocumentExternal &newExternalDocs);
    Tag &resetExternalDocs();

private:
    void*p=nullptr;

    const QString qapi_TagDescription = QStringLiteral("description");
    const QString qapi_TagExternalDocs = QStringLiteral("externalDocs");
    const QString qapi_TagName = QStringLiteral("name");
    const QString qapi_TagNameUrl = QStringLiteral("url");

signals:
    //!
    //! \brief nameChanged
    //!
    void nameChanged();

    //!
    //! \brief descriptionChanged
    //!
    void descriptionChanged();

    //!
    //! \brief externalDocsChanged
    //!
    void externalDocsChanged();
};


}

