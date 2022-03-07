CONFIG += c++17
CONFIG += silent

QT += core

INCLUDEPATH += $$PWD

HEADERS+= \
        $$PWD/qapidoc.h \
        $$PWD/qapidoc_common_types.h \
        $$PWD/qapidoc_document_definition.h \
        $$PWD/qapidoc_document.h \
        $$PWD/qapidoc_document_external.h \
        $$PWD/qapidoc_document_info.h \
        $$PWD/qapidoc_document_info_license.h \
        $$PWD/qapidoc_document_info_contact.h \
        $$PWD/qapidoc_document_path.h \
        $$PWD/qapidoc_document_path_operation.h \
        $$PWD/qapidoc_document_path_operation_request_parameter.h \
        $$PWD/qapidoc_document_path_operation_response.h \
        $$PWD/qapidoc_document_path_operation_response_headers.h \
        $$PWD/qapidoc_document_security_definition.h \
        $$PWD/qapidoc_document_security_definition_api_key.h \
        $$PWD/qapidoc_document_security_definition_basic.h \
        $$PWD/qapidoc_document_security_definition_oauth2.h \
        $$PWD/qapidoc_document_security_definition_oauth2_scope.h \
        $$PWD/qapidoc_document_tags.h \
        $$PWD/qapidoc_global.h \
        $$PWD/qapidoc_includes.h \
        $$PWD/qapidoc_macros.h \
        $$PWD/qapidoc_object_mapper.h \
        $$PWD/qapidoc_types.h


SOURCES += \
        $$PWD/qapidoc_common_types.cpp \
        $$PWD/qapidoc_document.cpp \
        $$PWD/qapidoc_document_definition.cpp \
        $$PWD/qapidoc_document_external.cpp \
        $$PWD/qapidoc_document_info.cpp \
        $$PWD/qapidoc_document_info_license.cpp \
        $$PWD/qapidoc_document_info_contact.cpp \
        $$PWD/qapidoc_document_path.cpp \
        $$PWD/qapidoc_document_path_operation.cpp \
        $$PWD/qapidoc_document_path_operation_request_parameter.cpp \
        $$PWD/qapidoc_document_path_operation_response.cpp \
        $$PWD/qapidoc_document_path_operation_response_headers.cpp \
        $$PWD/qapidoc_document_security_definition.cpp \
        $$PWD/qapidoc_document_security_definition_api_key.cpp \
        $$PWD/qapidoc_document_security_definition_basic.cpp \
        $$PWD/qapidoc_document_security_definition_oauth2.cpp \
        $$PWD/qapidoc_document_security_definition_oauth2_scope.cpp \
        $$PWD/qapidoc_document_tags.cpp \
        $$PWD/qapidoc_object_mapper.cpp \
        $$PWD/qapidoc_types.cpp
