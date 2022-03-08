#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_tags.h"
#include "./qapidoc_document_path_operation_response.h"
#include "./qapidoc_document_path_operation_request_parameter.h"

namespace QApiDoc{

//!
//! \brief The PathOperation class
//!
//! Describes a single API operation on a path.
//!
class Q_API_DOC_EXPORT PathOperation : public ObjectMapper
{
    Q_OBJECT

    //!
    Q_PROPERTY(QApiPathTypeOperation operation READ operation WRITE setOperation RESET resetOperation NOTIFY operationChanged)

    //! A verbose explanation of the operation behavior. GFM syntax can be used for rich text representation.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription NOTIFY descriptionChanged)

    //!
    Q_PROPERTY(QString operationId READ operationId WRITE setOperationId RESET resetOperationId NOTIFY operationIdChanged)

    //!
    Q_PROPERTY(QString summary READ summary WRITE setSummary RESET resetSummary NOTIFY summaryChanged)

    //! Declares this operation to be deprecated. Usage of the declared operation should be refrained.
    //! Default value is false.
    Q_PROPERTY(bool deprecated READ deprecated WRITE setDeprecated RESET resetDeprecated NOTIFY deprecatedChanged)

    //! A list of MIME types the operation can consume. This overrides the consumes definition at the Swagger Object.
    //! An empty value MAY be used to clear the global definition. Value MUST be as described under Mime Types.
    Q_PROPERTY(QStringList consumes READ consumes WRITE setConsumes RESET resetConsumes NOTIFY consumesChanged)

    //! A list of MIME types the operation can produce. This overrides the produces definition at the Swagger Object.
    //! An empty value MAY be used to clear the global definition. Value MUST be as described under Mime Types.
    Q_PROPERTY(QStringList produces READ produces WRITE setProduces RESET resetProduces NOTIFY producesChanged)

    //! A list of parameters that are applicable for this operation.
    //! If a parameter is already defined at the Path Item, the new definition will override it, but can never remove it.
    //! The list MUST NOT include duplicated parameters.
    //! A unique parameter is defined by a combination of a name and location.
    //! The list can use the Reference Object to link to parameters that are defined at the Swagger Object's parameters.
    //! There can be one "body" parameter at most.
    Q_PROPERTY(QVariantList parameters READ parametersObject WRITE setParameters RESET resetParameters NOTIFY parametersChanged)

    //! Required. The list of possible responses as they are returned from executing this operation.
    Q_PROPERTY(QVariantHash responses READ responsesObject WRITE setResponses RESET resetResponses NOTIFY responsesChanged)

    //! Lists the required security schemes to execute this operation.
    //! The object can have multiple security schemes declared in it which are all required (that is, there is a logical
    //! AND between the schemes).
    //! The name used for each property MUST correspond to a security scheme declared in the Security Definitions.
    //! A declaration of which security schemes are applied for this operation.
    //! The list of values describes alternative security schemes that can be used (that is, there is a logical
    //! OR between the security requirements). This definition overrides any declared top-level security.
    //! To remove a top-level security declaration, an empty array can be used.
    Q_PROPERTY(QVariantList security READ security WRITE setSecurity RESET resetSecurity NOTIFY securityChanged)

    //! A list of tags for API documentation control.
    //! Tags can be used for logical grouping of operations by resources or any other qualifier.
    Q_PROPERTY(QVariantList tags READ tagsObject WRITE setTags RESET resetTags NOTIFY tagsChanged)

    //!
    Q_PROPERTY(QVariantHash externalDocs READ externalDocsObject WRITE setExternalDocs RESET resetExternalDocs NOTIFY externalDocsChanged)

public:

    Q_API_DECLARE_PATH_TYPE_OPERATION()

    Q_INVOKABLE explicit PathOperation(QObject*parent=nullptr);
    ~PathOperation();

//    //!
//    //! \brief toVariant
//    //! \return
//    //!
//    QVariant toVariant()const;

    //!
    //! \brief operation
    //! \return
    //!
    QApiPathTypeOperation operation() const;
    PathOperation &operation(const QVariant&newOperation);
    PathOperation &setOperation(const QVariant&newOperation);
    PathOperation &resetOperation();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    PathOperation &description(const QString &newDescription);
    PathOperation &setDescription(const QString &newDescription);
    PathOperation &resetDescription();

    //!
    //! \brief operationId
    //! \return
    //!
    const QString &operationId() const;
    PathOperation &operationId(const QVariant &newOperationId);
    PathOperation &setOperationId(const QString &newOperationId);
    PathOperation &resetOperationId();

    //!
    //! \brief summary
    //! \return
    //!
    const QString &summary() const;
    PathOperation &setSummary(const QString &newSummary);
    PathOperation &resetSummary();

    //!
    //! \brief deprecated
    //! \return
    //!
    bool deprecated() const;
    PathOperation &setDeprecated(bool newDeprecated);
    PathOperation &resetDeprecated();

    //!
    //! \brief consumes
    //! \return
    //!
    QStringList &consumes();
    PathOperation &consumes(const QString &newConsume);
    PathOperation &consumes(const QStringList &newConsumes);
    PathOperation &setConsumes(const QStringList &newConsumes);
    PathOperation &resetConsumes();

    //!
    //! \brief produces
    //! \return
    //!
    QStringList &produces();
    PathOperation &produces(const QString&newProduce);
    PathOperation &produces(const QVariant &newProduces);
    PathOperation &setProduces(const QVariant &newProduces);
    PathOperation &resetProduces();

    //!
    //! \brief parameters
    //! \return
    //!
    QVariantList parametersObject() const;
    QList<RequestParameter*> &parameters()const;
    PathOperation &parameters(const QVariant&newParameter);
    PathOperation &parameters(const RequestParameter&newParameter);
    PathOperation &setParameters(const QVariant &newParameters);
    PathOperation &setParameters(const QList<RequestParameter *> &newParameters);
    PathOperation &resetParameters();

    //!
    //! \brief responses
    //! \return
    //!
    QVariantHash responsesObject() const;
    QHash<QString, Response*> &responses()const;
    PathOperation &responses(const QVariant&newResponse);
    PathOperation &responses(const Response&newResponse);
    PathOperation &setResponses(const QVariant &newResponses);
    PathOperation &setResponses(const QList<Response *> &newResponses);
    PathOperation &resetResponses();

    //!
    //! \brief security
    //! \return
    //!
    QVariantList security() const;
    PathOperation &security(const QString &newSecurity);
    PathOperation &security(const QStringList &newSecurity);
    PathOperation &setSecurity(const QVariant &newSecurity);
    PathOperation &resetSecurity();

    //!
    //! \brief tags
    //! \return
    //!
    QVariantList tagsObject()const;
    QList<Tag*> &tags()const;
    PathOperation &tags(const QVariant &newTag);
    PathOperation &setTags(const QVariant &newTags);
    PathOperation &setTags(const QVariantList &newTags);
    PathOperation &resetTags();

    //!
    //! \brief externalDocs
    //! \return
    //!
    DocumentExternal &externalDocs();
    QVariantHash externalDocsObject()const;
    PathOperation &externalDocs(const QVariant &newExternalDocs);
    PathOperation &setExternalDocs(const QVariant &newExternalDocs);
    PathOperation &setExternalDocs(const DocumentExternal &newExternalDocs);
    PathOperation &resetExternalDocs();

    //!
    //! \brief toMimeTypesList
    //! \param vMimeTypesList
    //! \return
    //!
    QVariantList toMimeTypesList(const QStringList &vMimeTypesList)const;

    //!
    //! \brief operationToString
    //! \return
    //!
    QString operationToString() const;
signals:
    void operationChanged();
    void descriptionChanged();
    void consumesChanged();
    void producesChanged();
    void parametersChanged();
    void responsesChanged();
    void securityChanged();
    void tagsChanged();
    void operationIdChanged();
    void deprecatedChanged();
    void summaryChanged();
    void externalDocsChanged();

private:
    void*p=nullptr;
};


}

