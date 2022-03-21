#pragma once

#include "./qapidoc_common_types.h"
#include "./qapidoc_document_definition.h"
#include "./qapidoc_document_path_operation_response_headers.h"
#include "./qapidoc_includes.h"

namespace QApiDoc {

//! \brief The Response class
//!
//! Describes a single response from an API Operation.
//! A container for the expected responses of an operation.
//! The container maps a HTTP response code to the expected response.
//! It is not expected from the documentation to necessarily cover all possible HTTP response codes, since they may not be
//! known in advance. However, it is expected from the documentation to cover a successful operation response and any known errors.
//! The default can be used as the default response object for all HTTP codes that are not covered individually by the specification.
//! The Responses Object MUST contain at least one response code, and it SHOULD be the response for a successful operation call.
//!
class Q_API_DOC_EXPORT Response : public ObjectMapper
{
    Q_OBJECT

    //! Any HTTP status code can be used as the property name (one property per HTTP status code).
    //! Describes the expected response for that HTTP status code.
    //! Reference Object can be used to link to a response that is defined at the Swagger Object's responses section.
    Q_PROPERTY(QString statusCode READ statusCode WRITE setStatusCode RESET resetStatusCode NOTIFY
                   statusCodeChanged)

    //! Required. A short description of the response. GFM syntax can be used for rich text representation.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription
                   NOTIFY descriptionChanged)

    //! A definition of the response structure.
    //! It can be a primitive, an array or an object.
    //! If this field does not exist, it means no content is returned as part of the response.
    //! As an extension to the Schema Object, its root type value may also be "file".
    //! This SHOULD be accompanied by a relevant produces mime-type.
    Q_PROPERTY(QVariantHash schema READ schemaObject WRITE setSchema RESET resetSchema NOTIFY
                   schemaChanged)

    //! A list of headers that are sent with the response.
    Q_PROPERTY(QVariantList headers READ headersObject WRITE setHeaders RESET resetHeaders NOTIFY
                   headersChanged);

    //! An example list of the hash response message.
    Q_PROPERTY(QVariantHash examples READ examples WRITE setExamples RESET resetExamples NOTIFY
                   examplesChanged);

public:
    Q_INVOKABLE explicit Response(QObject *parent = nullptr);
    ~Response();

    //!
    //! \brief statusCode
    //! \return
    //!
    QString statusCode() const;
    Response &statusCode(const QVariant &newStatusCode);
    Response &setStatusCode(const QVariant &newStatusCode);
    Response &resetStatusCode();

    //!
    //! \brief schema
    //! \return
    //!
    Definition &schema();
    QVariantHash schemaObject();
    Response &setSchema(const QVariant &newSchema);
    Response &setSchema(const Definition &newSchema);
    Response &resetSchema();

    //!
    //! \brief headers
    //! \return
    //!
    QVariantList headersObject() const;
    QList<Headers *> &headers() const;
    Response &headers(const QVariantList &newHeaders);
    Response &setHeaders(const QVariantList &newHeaders);
    Response &setHeaders(const QList<Headers *> &newHeaders);
    Response &resetHeaders();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    Response &description(const QString &newDescription);
    Response &setDescription(const QString &newDescription);
    Response &resetDescription();

    //!
    //! \brief examples
    //! \return
    //!
    QVariantHash &examples();
    Response &examples(const QVariantHash &newExamples);
    Response &setExamples(const QVariantHash &newExamples);
    Response &resetExamples();

signals:
    void statusCodeChanged();

    void schemaChanged();

    void headersChanged();

    void descriptionChanged();

    void examplesChanged();

protected:
    const QVariantHash toExamplestoHash() const;

private:
    void *p = nullptr;
};

} // namespace QApiDoc
