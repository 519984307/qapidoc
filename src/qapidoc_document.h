#pragma once

#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_tags.h"
#include "./qapidoc_document_info.h"
#include "./qapidoc_document_security_definition.h"
#include "./qapidoc_document_path.h"
#include "./qapidoc_document_path_operation_request_parameter.h"
#include "./qapidoc_document_definition.h"
#include "./qapidoc_document.h"


namespace QApiDoc{

//!
//! \brief The QSwaggerDoc class
//!
//! This is the root document object for the API specification.
//! It combines what previously was the Resource Listing and API Declaration (version 1.2 and earlier) together into one document.
//!
class Q_API_DOC_EXPORT Document : public ObjectMapper
{
    Q_OBJECT

public:

    Q_PROPERTY(QString swagger READ version CONSTANT)

    //!
    //!
    Q_PROPERTY(QVariantHash info READ infoObject WRITE setInfo RESET resetInfo NOTIFY infoChanged)

    //!
    //!
    Q_PROPERTY(QVariantList tags READ tagsObject WRITE setTags RESET resetTags NOTIFY tagsChanged)

    //!
    //!
    Q_PROPERTY(QVariantList consumes READ consumes WRITE setConsumes RESET resetConsumes NOTIFY consumesChanged)

    //!
    //!
    Q_PROPERTY(QVariantList produces READ produces WRITE setProduces RESET resetProduces NOTIFY producesChanged)

    //!
    //!
    Q_PROPERTY(QString basePath READ basePath WRITE setBasePath RESET resetBasePath NOTIFY basePathChanged)

    //!
    //!
    Q_PROPERTY(QString host READ host WRITE setHost RESET resetHost NOTIFY hostChanged)

    //!
    //!
    Q_PROPERTY(QApiTransferProtocolSchemes schemes READ schemes WRITE setSchemes RESET resetSchemes NOTIFY schemesChanged)

    //!
    //!
    Q_PROPERTY(QVariantList paths READ pathsObject WRITE setPaths RESET resetPaths NOTIFY pathsChanged)

    //!
    //!
    Q_PROPERTY(QVariantList definitions READ definitionsObject WRITE setDefinitions RESET resetDefinitions NOTIFY definitionsChanged)

    //!
    //!
    Q_PROPERTY(QVariantList securityDefinitions READ securityDefinitionsObject WRITE setSecurityDefinitions RESET resetSecurityDefinitions NOTIFY securityDefinitionsChanged)

    //!
    //!
    Q_PROPERTY(QVariantHash externalDocs READ externalDocsObject WRITE setExternalDocs  NOTIFY externalDocsChanged)

public:


    Q_INVOKABLE explicit Document(QObject*parent=nullptr);
    ~Document();

    //!
    //! \brief version
    //! \return
    //!
    QString version()const;

    //!
    //! \brief loadFromParent
    //! \return
    //!
    bool load(QObject *object);

    //!
    //! \brief basePath
    //! \return
    //!
    const QString &basePath() const;
    Document &basePath(const QString &newBasePath);
    Document &setBasePath(const QString &newBasePath);
    Document &resetBasePath();

    //!
    //! \brief host
    //! \return
    //!
    const QString &host() const;
    Document &host(const QString &newHost);
    Document &setHost(const QString &newHost);
    Document &resetHost();

    //!
    //! \brief schemes
    //! \return
    //!
    QApiTransferProtocolSchemes schemes()const;
    const QVariantList schemesObject()const;
    Document &schemes(const QVariant &newSchemes);
    Document &setSchemes(const QVariant &newSchemes);
    Document &setSchemes(const QApiTransferProtocolSchemes &newSchemes);
    Document &resetSchemes();

    //!
    //! \brief info
    //! \return
    //!
    Info &info();
    const QVariantHash infoObject()const;
    Document &setInfo(const QVariant &newInfo);
    Document &setInfo(const Info &newInfo);
    Document &resetInfo();

    //!
    //! \brief tags
    //! \return
    //!
    QList<Tag*> &tags()const;
    const QVariantList tagsObject()const;
    Document &tags(const QVariant &newTags);
    Document &tags(const QVariantList &newTags);
    Document &tags(Tag *newTags);
    Document &tags(const QList<Tag *> &newTags);
    Document &setTags(const QVariant &newTags);
    Document &setTags(const QVariantList &newTags);
    Document &setTags(Tag *newTags);
    Document &setTags(const QList<Tag *> &newTags);
    Document &resetTags();

    //!
    //! \brief consumes
    //! \return
    //!
    const QVariantList &consumes()const;
    Document &consumes(const QString&newConsume);
    Document &consumes(const QVariantList &newConsumes);
    Document &setConsumes(const QVariantList &newConsumes);
    Document &resetConsumes();

    //!
    //! \brief produces
    //! \return
    //!
    const QVariantList &produces()const;
    Document &produces(const QString&newProduce);
    Document &produces(const QVariantList&newProduces);
    Document &setProduces(const QVariantList &newProduces);
    Document &resetProduces();

    //!
    //! \brief paths
    //! \return
    //!
    QList<Path *> &paths() const;
    const QVariantList pathsObject() const;
    Document &paths(const QVariant&newPath);
    Document &paths(const QVariantHash &newPaths);
    Document &paths(Path *newPaths);
    Document &setPaths(const QVariant &newPaths);
    Document &setPaths(Path * &newPaths);
    Document &setPaths(const QList<Path *> &newPaths);
    Document &resetPaths();

    //!
    //! \brief definitions
    //! \return
    //!
    QList<Definition*> &definitions()const;
    const QVariantList definitionsObject()const;
    Document &definitions(const QVariant &newDefinition);
    Document &definitions(const QVariantHash &newDefinitions);
    Document &definitions(Definition *newDefinitions);
    Document &definitions(const QList<Definition *> &newDefinitions);
    Document &setDefinitions(const QVariant &newDefinitions);
    Document &setDefinitions(Definition *newDefinitions);
    Document &setDefinitions(const QList<Definition *> &newDefinitions);
    Document &resetDefinitions();

    //!
    //! \brief securityDefinitions
    //! \return
    //!
    QList<SecurityDefinition*> &securityDefinitions();
    const QVariantList securityDefinitionsObject() const;
    Document &securityDefinitions(const QVariant&newSecurityDefinition);
    Document &securityDefinitions(const QVariantHash &newSecurityDefinitions);
    Document &securityDefinitions(const QList<SecurityDefinition *> &newSecurityDefinitions);
    Document &setSecurityDefinitions(const QVariant &newSecurityDefinitions);
    Document &setSecurityDefinitions(const QList<SecurityDefinition *> &newSecurityDefinitions);
    Document &resetSecurityDefinitions();

    //!
    //! \brief parameters
    //! \return
    //!
    QList<RequestParameter*> &parameters()const;
    const QVariantList parametersObject() const;
    Document &parameters(const QVariant&newParameter);
    Document &parameters(const QVariantList &newParameters);
    Document &parameters(const QList<RequestParameter *> &newParameters);
    Document &setParameters(const QVariantList &newParameters);
    Document &setParameters(const QList<RequestParameter *> &newParameters);
    Document &resetParameters();

    //!
    //! \brief externalDocs
    //! \return
    //!
    DocumentExternal &externalDocs();
    const QVariantHash externalDocsObject()const;
    Document &externalDocs(const QVariant &newExternalDocs);
    Document &setExternalDocs(const QVariant &newExternalDocs);
    Document &setExternalDocs(const DocumentExternal &newExternalDocs);
    Document &resetExternalDocs();

public:
    const QString qapi_ger_version = QStringLiteral("2.0");
    const QStringList qapi_transfer_protocol_scheme={
        QString(),
        QStringLiteral("http"),
        QStringLiteral("https"),
        QStringLiteral("ws"),
        QStringLiteral("wss")
    };
signals:
    void infoChanged();
    void tagsChanged();
    void consumesChanged();
    void producesChanged();
    void basePathChanged();
    void hostChanged();
    void schemesChanged();
    void pathsChanged();
    void definitionsChanged();
    void securityDefinitionsChanged();
    void externalDocsChanged();
    void swaggerObjectChanged();
    void parametersChanged();
private:
    void*p=nullptr;
};

}

