#pragma once


#include "./qapidoc_includes.h"
#include "./qapidoc_common_types.h"
#include "./qapidoc_document_definition.h"

namespace QApiDoc{

//!
//! \brief The RequestParameter class
//!
//! Describes a single operation parameter.A unique parameter is defined by a combination of a name and location.
//!
class Q_API_DOC_EXPORT RequestParameter : public ObjectMapper
{
    Q_OBJECT

    //! Required. The name of the parameter. Parameter names are case sensitive.
    //! If in is "path", the name field MUST correspond to the associated path segment from the path field in the Paths Object.
    //! See Path Templating for further information.
    //! For all other cases, the name corresponds to the parameter name used based on the in property.
    Q_PROPERTY(QString name READ name WRITE setName RESET resetName NOTIFY nameChanged)

    //! There are five possible parameter types: Query, Header, Path, Form e Body.
    Q_PROPERTY(QApiRequestParameterInLocation inLocation READ inLocation WRITE setInLocation RESET resetInLocation NOTIFY inLocationChanged)

    //! Determines whether this parameter is mandatory. If the parameter is in "path", this property is required and its value MUST be true.
    //! Otherwise, the property MAY be included and its default value is false.
    Q_PROPERTY(bool required READ required WRITE setRequired RESET resetRequired NOTIFY requiredChanged)

    //! If in is "body"
    //! Required. The schema defining the type used for the body parameter.
    Q_PROPERTY(QVariantHash schema READ schemaObject WRITE setSchema RESET resetSchema NOTIFY schemaChanged)

    //! A brief description of the parameter. This could contain examples of use. GFM syntax can be used for rich text representation.
    Q_PROPERTY(QString description READ description WRITE setDescription RESET resetDescription NOTIFY descriptionChanged)

    //! If in is any value other than "body"
    //! Required. The type of the parameter. Since the parameter is not located at the request body, it is limited to
    //! simple types (that is, not an object).
    //! The value MUST be one of "string", "number", "int", "boolean", "array" or "file".
    //! If type is "file", the consumes MUST be either "multipart/form-data", " application/x-www-form-urlencoded" or both
    //! and the parameter MUST be in "formData".
    Q_PROPERTY(QApiTypeParameter typeParameter READ typeParameter WRITE setTypeParameter RESET resetTypeParameter NOTIFY typeParameterChanged)

    //! See https://tools.ietf.org/html/draft-fge-json-schema-validation-00#section-5.2.3.
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern RESET resetPattern NOTIFY patternChanged)

    //!
    Q_PROPERTY(QVariantHash items READ items WRITE setItems RESET resetItems NOTIFY itemsChanged)

    //! Primitives have an optional modifier property format. Swagger #pragma once several known formats to more finely define
    //! the data type being used. However, the format property is an open string-valued property, and can have any value
    //! to support documentation needs. Formats such as "email", "uuid", etc., can be used even though they are not
    //! defined by this specification.
    //!  </summary>
    Q_PROPERTY(QString format READ format WRITE setFormat RESET resetFormat NOTIFY formatChanged)

    //! Declares the value of the parameter that the server will use if none is provided, for example a "count" to
    //! control the number of results per page might default to 100 if !supplied by the client in the request.
    //! (Note: "default" has no meaning for required parameters.)
    //! See https://tools.ietf.org/html/draft-fge-json-schema-validation-00#section-6.2. Unlike JSON Schema
    //! this value MUST conform to the defined type for this parameter.
    Q_PROPERTY(QString default READ defaultValue WRITE setDefaultValue RESET resetDefaultValue NOTIFY defaultValueChanged)

    //!
    Q_PROPERTY(QStringList enum READ enumValue WRITE setEnumValue RESET resetEnumValue NOTIFY enumValueChanged)

    //!
    Q_PROPERTY(bool allowEmptyValue READ allowEmptyValue WRITE setAllowEmptyValue RESET resetAllowEmptyValue NOTIFY allowEmptyValueChanged)

    //!
    Q_PROPERTY(QString ref READ ref WRITE setRef RESET resetRef NOTIFY refChanged)

public:

    Q_API_DECLARE_PATH_TYPE_PARAMETER()

    Q_API_DECLARE_PATH_TYPE_OPERATION()

    Q_API_DECLARE_PATH_TYPE_PARAMETER_LOCATION()

    Q_INVOKABLE explicit RequestParameter(QObject*parent=nullptr);
    ~RequestParameter();

    //!
    //! \brief name
    //! \return
    //!
    const QString &name() const;
    RequestParameter&name(const QString &newName);
    RequestParameter&setName(const QString &newName);
    RequestParameter&resetName();

    //!
    //! \brief inLocation
    //! \return
    //!
    QApiRequestParameterInLocation inLocation() const;
    RequestParameter&inLocation(const QVariant &newInLocation);
    RequestParameter&setInLocation(const QVariant &newInLocation);
    RequestParameter&resetInLocation();
    QString inLocationToString() const;

    //!
    //! \brief required
    //! \return
    //!
    bool required() const;
    RequestParameter&required(bool newRequired);
    RequestParameter&setRequired(bool newRequired);
    RequestParameter&resetRequired();

    //!
    //! \brief schema
    //! \return
    //!
    Definition &schema();
    QVariantHash schemaObject();
    RequestParameter&schema(const QVariant &newSchema);
    RequestParameter&setSchema(const QVariant &newSchema);
    RequestParameter&setSchema(const Definition &newSchema);
    RequestParameter&resetSchema();

    //!
    //! \brief description
    //! \return
    //!
    const QString &description() const;
    RequestParameter&description(const QString &newDescription);
    RequestParameter&setDescription(const QString &newDescription);
    RequestParameter&resetDescription();

    //!
    //! \brief typeParameter
    //! \return
    //!
    QApiTypeParameter typeParameter() const;
    RequestParameter&typeParameter(const int&newTypeParameter);
    RequestParameter&setTypeParameter(const QVariant &newTypeParameter);
    RequestParameter&resetTypeParameter();

    //!
    //! \brief pattern
    //! \return
    //!
    const QString &pattern() const;
    RequestParameter&pattern(const QString &newPattern);
    RequestParameter&setPattern(const QString &newPattern);
    RequestParameter&resetPattern();

    //!
    //! \brief items
    //! \return
    //!
    const QVariantHash &items() const;
    RequestParameter&setItems(const QVariantHash &newItems);
    RequestParameter&resetItems();

    //!
    //! \brief format
    //! \return
    //!
    const QString &format() const;
    RequestParameter&format(const QString &newFormat);
    RequestParameter&setFormat(const QString &newFormat);
    RequestParameter&resetFormat();

    //!
    //! \brief defaultValue
    //! \return
    //!
    const QString &defaultValue() const;
    RequestParameter&defaultValue(const QString &newDefault);
    RequestParameter&setDefaultValue(const QString &newDefault);
    RequestParameter&resetDefaultValue();

    //!
    //! \brief enumValue
    //! \return
    //!
    QStringList &enumValue();
    RequestParameter&enumValue(const QStringList &newEnum);
    RequestParameter&setEnumValue(const QStringList &newEnum);
    RequestParameter&resetEnumValue();

    //!
    //! \brief allowEmptyValue
    //! \return
    //!
    bool allowEmptyValue() const;
    RequestParameter&allowEmptyValue(bool newAllowEmptyValue);
    RequestParameter&setAllowEmptyValue(bool newAllowEmptyValue);
    RequestParameter&resetAllowEmptyValue();

    //!
    //! \brief ref
    //! \return
    //!
    const QString &ref() const;
    RequestParameter&ref(const QString &newRef);
    RequestParameter&setRef(const QString &newRef);
    RequestParameter&resetRef();
private:
    void*p=nullptr;


//    const QString qapi_RequestParameterAllowEmptyValue = QStringLiteral("allowEmptyValue");
//    const QString qapi_RequestParameterDefault = QStringLiteral("default");
//    const QString qapi_RequestParameterDescription = QStringLiteral("description");
//    const QString qapi_RequestParameterEnum = QStringLiteral("enum");
//    const QString qapi_RequestParameterFormat = QStringLiteral("format");
//    const QString qapi_RequestParameterIn = QStringLiteral("in");
//    const QString qapi_RequestParameterItems = QStringLiteral("items");
//    const QString qapi_RequestParameterName = QStringLiteral("name");
//    const QString qapi_RequestParameterPattern = QStringLiteral("pattern");
//    const QString qapi_RequestParameterRef = QStringLiteral("$ref");
//    const QString qapi_RequestParameterRequired = QStringLiteral("required");
//    const QString qapi_RequestParameterSchema = QStringLiteral("schema");
//    const QString qapi_RequestParameterType = QStringLiteral("type");
//    const QStringList qapi_TypeParameter
//        {
//            QString(),
//            QStringLiteral("string"),
//            QStringLiteral("number"),
//            QStringLiteral("int"),
//            QStringLiteral("boolean"),
//            QStringLiteral("array"),
//            QStringLiteral("file")
//        };

signals:
    void nameChanged();
    void inLocationChanged();
    void requiredChanged();
    void schemaChanged();
    void descriptionChanged();
    void typeParameterChanged();
    void patternChanged();
    void itemsChanged();
    void formatChanged();
    void defaultValueChanged();
    void enumValueChanged();
    void allowEmptyValueChanged();
    void refChanged();
};


}

