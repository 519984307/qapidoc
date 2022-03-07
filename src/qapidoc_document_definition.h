#pragma once

#include "./qapidoc_includes.h"


namespace QApiDoc{

//!
//! \brief The Definition class
//!
//! The Schema Object allows the definition of input and output data types.
//! These types can be objects, but also primitives and arrays.
//! This object is based on the JSON Schema Specification Draft 4 and #pragma once a predefined subset of it.
//! On top of this subset, there are extensions provided by this specification to allow for more complete documentation.
//! Further information about the properties can be found in JSON Schema Core and JSON Schema Validation.
//! Unless stated otherwise, the property definitions follow the JSON Schema specification as referenced here.
//!
class Q_SWAGGER_EXPORT Definition : public ObjectMapper
{
    Q_OBJECT

    //! The schema name alias.
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    //! See more in:
    //!  * http://json-schema.org
    //!  * https://github.com/OAI/OpenAPI-Specification/blob/master/versions/2.0.md#schemaObject
    Q_PROPERTY(QVariantHash schema READ schema WRITE setSchema NOTIFY schemaChanged)
public:
    Q_INVOKABLE explicit Definition(QObject*parent=nullptr);
    ~Definition();

//    //!
//    //! \brief toRefDefinition
//    //! \return
//    //!
//    QVariantHash toRefDefinition()const;

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    Definition &name(const QString &newName);
    Definition &setName(const QString &newName);

    //!
    //! \brief schema
    //! \return
    //!
    const QVariantHash &schema() const;
    Definition &schema(const QVariantHash &newSchema);
    Definition &setSchema(const QVariantHash &newSchema);

signals:
    void nameChanged();
    void schemaChanged();
private:
    void*p=nullptr;
};


}


