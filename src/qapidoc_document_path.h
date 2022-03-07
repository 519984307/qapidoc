#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"

namespace QApiDoc{

class PathOperation;
class RequestParameter;
//!
//! \brief The Path class
//!
//! Holds the relative paths to the individual endpoints.
//! The path is appended to the basePath in order to construct the full URL.
//! The Paths may be empty, due to ACL constraints.
class Q_SWAGGER_EXPORT Path : public ObjectMapper
{
    Q_OBJECT

    //! Describes a single API operation on a path.
    Q_PROPERTY(QVariantList operations READ operationsObject WRITE setOperations RESET resetOperations NOTIFY operationsChanged)

    //! A relative path to an individual endpoint. The field name MUST { with a slash.
    //! The path is appended to the basePath in order to construct the full URL. Path templating is allowed.
    Q_PROPERTY(QString uri READ uri WRITE setUri RESET resetUri NOTIFY uriChanged)

    //!
    Q_PROPERTY(QVariantList parameters READ parametersObject WRITE setParameters RESET resetParameters NOTIFY parametersChanged)
public:

    Q_INVOKABLE explicit Path(QObject*parent=nullptr);
    ~Path();

    //!
    //! \brief toVariant
    //! \return
    //!
    QVariant toVariant()const;

    //!
    //! \brief load
    //! \param value
    //! \return
    //!
    bool load(const QVariant &value);

    //!
    //! \brief operations
    //! \return
    //!
    QList<PathOperation*> &operations() const;
    QVariantList operationsObject() const;
    Path &operations(const QVariantList &newOperations);
    Path &operations(PathOperation *newOperation);
    Path &setOperations(const QVariantList &newOperations);
    Path &setOperations(const QList<PathOperation*> &newOperations);
    Path &resetOperations();
    PathOperation &operation(const QString &newOperation);
    PathOperation &operation(const int &newOperation);

    //!
    //! \brief uri
    //! \return
    //!
    const QString &uri() const;
    Path &uri(const QString &newUri);
    Path &setUri(const QString &newUri);
    Path &resetUri();

    //!
    //! \brief parameters
    //! \return
    //!
    const QList<RequestParameter *> parameters() const;
    const QVariantList parametersObject() const;
    Path &parameters(RequestParameter*newParameters);
    Path &parameters(const QVariantList &newParameters);
    Path &setParameters(const QVariantList &newParameters);
    Path &setParameters(const QList<RequestParameter *> &newParameters);
    Path &resetParameters();

private:
    void*p=nullptr;
signals:
    void operationsChanged();
    void uriChanged();
    void parametersChanged();
};


}

