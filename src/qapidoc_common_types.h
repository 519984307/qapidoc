#pragma once

#include "./qapidoc_includes.h"
#include <QCoreApplication>

#define Q_API_DOC_METHOD_START_NAME QByteArrayLiteral("__doc_api")
#define Q_API_DOC_METHOD_NAME_INFORMATION QByteArrayLiteral("__doc_api_info")
#define Q_API_DOC_METHOD_NAME_PATH_STARTS_WITH QByteArrayLiteral("__doc_api_info_path")

//!
//! \brief The SecurityDefinitionType enum
//!
//! Allows the definition of a security scheme that can be used by the operations.
//! Supported schemes are:
//! * basic autication
//! * API key (either as a header or as a query parameter)
//! * OAuth2's common flows (implicit, password, application and access code).
//!
#define __Q_API_DECLARE_SECURITY_DEFINITION_TYPE()\
enum SecurityDefinitionType{sstNotDefined, sstBasic, sstApiKey, sstOAuth2};

__Q_API_DECLARE_SECURITY_DEFINITION_TYPE()
Q_DECLARE_FLAGS(SecurityDefinitionsType, SecurityDefinitionType)
Q_DECLARE_OPERATORS_FOR_FLAGS(SecurityDefinitionsType)

#define Q_API_DECLARE_SECURITY_DEFINITION_TYPE()\
__Q_API_DECLARE_SECURITY_DEFINITION_TYPE()\
Q_ENUM(SecurityDefinitionsType)

//!
//! \brief The QApiTransferProtocolScheme enum
//!
#define __Q_API_DECLARE_TRANSFER_PROTOCOL_SCHEME()\
enum QApiTransferProtocolScheme{ stpsNotDefined, stpsHttp, stpsHttps, stpsWs, stpsWss };\
typedef QVector<QApiTransferProtocolScheme> QApiTransferProtocolSchemeList;\
typedef QHash<QString, QApiTransferProtocolScheme> QApiTransferProtocolSchemeHash;

__Q_API_DECLARE_TRANSFER_PROTOCOL_SCHEME()

Q_DECLARE_FLAGS(QApiTransferProtocolSchemes, QApiTransferProtocolScheme)\
Q_DECLARE_OPERATORS_FOR_FLAGS(QApiTransferProtocolSchemes)

//!
//! \brief qapiTransferProtocolScheme
//! \return
//!
const QApiTransferProtocolSchemeList &qapiTransferProtocolScheme();

//!
//! \brief qapiTransferProtocolSchemeHash
//! \return
//!
const QApiTransferProtocolSchemeHash &qapiTransferProtocolSchemeHash();

//!
//! \brief The QApiTypeParameter enum
//!
//! The type of the parameter. Since the parameter is not located at the request body, it is limited to
//! simple types (that is, not an object).
//! The value MUST be one of "string", "number", "int", "boolean", "array" or "file".
//!
#define __Q_API_DECLARE_PATH_TYPE_PARAMETER()\
enum QApiTypeParameter{stpNotDefined=QMetaType::UnknownType, stpString=QMetaType::QString, stpNumber=QMetaType::Int, stpInt=QMetaType::Int, stpBoolean=QMetaType::Bool, stpArray=QMetaType::QVariantList, stpFile=QMetaType::QByteArray};

__Q_API_DECLARE_PATH_TYPE_PARAMETER()

#define Q_API_DECLARE_PATH_TYPE_PARAMETER()\
__Q_API_DECLARE_PATH_TYPE_PARAMETER()\
Q_ENUM(QApiTypeParameter)

//!
//! \brief qapi_TypeParameter
//! \return
//!
const QStringList &qapi_TypeParameter();

//!
//! \brief The QApiPathTypeOperation enum
//!
#define __Q_API_DECLARE_PATH_TYPE_OPERATION()\
enum QApiPathTypeOperation{sptoNotDefined, sptoGet, sptoPost, sptoPut, sptoDelete, sptoOptions, sptoHead, sptoPatch, sptoTrace};

__Q_API_DECLARE_PATH_TYPE_OPERATION()

#define Q_API_DECLARE_PATH_TYPE_OPERATION()\
__Q_API_DECLARE_PATH_TYPE_OPERATION()\
Q_ENUM(QApiPathTypeOperation)

typedef QHash<QString, QApiPathTypeOperation> QApiPathTypeOperationHash;

//!
//! \brief qapi_pathTypeOperationList
//! \return
//!
const QStringList &qapi_pathTypeOperationList();

//!
//! \brief qapi_PathTypeOperationHash
//! \return
//!
const QApiPathTypeOperationHash &qapi_PathTypeOperationHash();


//!
//! \brief The QApiRequestParameterInLocation enum
//!
//! * Query - Parameters that are appended to the URL. For example, in /items?id=###, the query parameter is id.
//! * Header - Custom headers that are expected as part of the request.
//! * Path - Used together with Path Templating, where the parameter value is actually part of the operation's URL.
//!        This does not include the host or base path of the API. For example, in /items/{itemId}, the path parameter is itemId.
//! * Form - Used to describe the payload of an HTTP request when either application/x-www-form-urlencoded, multipart/form-data
//!          or both are used as the content type of the request (in Swagger's definition, the consumes property of an operation).
//!          This is the only parameter type that can be used to send files, thus supporting the file type.
//!          Since form parameters are sent in the payload, they cannot be declared together with a body parameter for the same
//!          operation. Form parameters have a different format based on the content-type used (for further details,
//!          consult http://www.w3.org/TR/html401/interact/forms.html#h-17.13.4).
//! * Body - The payload that's appended to the HTTP request. Since there can only be one payload, there can only be one body parameter.
//!          The name of the body parameter has no effect on the parameter itself and is used for documentation purposes only.
//!          Since Form parameters are also in the payload, body and form parameters cannot exist together for the same operation.
//!
#define __Q_API_DECLARE_PATH_TYPE_PARAMETER_LOCATION()\
enum QApiRequestParameterInLocation{srplNotDefined, srplQuery, srplHeader, srplPath, srplFormData, srplBody};

__Q_API_DECLARE_PATH_TYPE_PARAMETER_LOCATION()

#define Q_API_DECLARE_PATH_TYPE_PARAMETER_LOCATION()\
__Q_API_DECLARE_PATH_TYPE_PARAMETER_LOCATION()\
    Q_ENUM(QApiRequestParameterInLocation)

//!
//! \brief qapi_requestParameterInLocation
//! \return
//!
const QStringList &qapi_requestParameterInLocation();
