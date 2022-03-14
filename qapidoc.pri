QT += core

CONFIG -= c++11
CONFIG += c++17
CONFIG += silent

QTREFORCE_QAPIDOC=true
DEFINES+=QTREFORCE_QAPIDOC

INCLUDEPATH += $$PWD/includes

HEADERS+= \
        $$PWD/src/qapidoc.h \
        $$PWD/src/qapidoc_common_types.h \
        $$PWD/src/qapidoc_document_definition.h \
        $$PWD/src/qapidoc_document.h \
        $$PWD/src/qapidoc_document_external.h \
        $$PWD/src/qapidoc_document_info.h \
        $$PWD/src/qapidoc_document_info_license.h \
        $$PWD/src/qapidoc_document_info_contact.h \
        $$PWD/src/qapidoc_document_path.h \
        $$PWD/src/qapidoc_document_path_operation.h \
        $$PWD/src/qapidoc_document_path_operation_parameter.h \
        $$PWD/src/qapidoc_document_path_operation_response.h \
        $$PWD/src/qapidoc_document_path_operation_response_headers.h \
        $$PWD/src/qapidoc_document_security_definition.h \
        $$PWD/src/qapidoc_document_security_definition_api_key.h \
        $$PWD/src/qapidoc_document_security_definition_basic.h \
        $$PWD/src/qapidoc_document_security_definition_oauth2.h \
        $$PWD/src/qapidoc_document_security_definition_oauth2_scope.h \
        $$PWD/src/qapidoc_document_tags.h \
        $$PWD/src/qapidoc_global.h \
        $$PWD/src/qapidoc_includes.h \
        $$PWD/src/qapidoc_macros.h \
        $$PWD/src/qapidoc_meta_types.h \
        $$PWD/src/qapidoc_object_mapper.h \
        $$PWD/src/qapidoc_types.h


SOURCES += \
        $$PWD/src/qapidoc_common_types.cpp \
        $$PWD/src/qapidoc_document.cpp \
        $$PWD/src/qapidoc_document_definition.cpp \
        $$PWD/src/qapidoc_document_external.cpp \
        $$PWD/src/qapidoc_document_info.cpp \
        $$PWD/src/qapidoc_document_info_license.cpp \
        $$PWD/src/qapidoc_document_info_contact.cpp \
        $$PWD/src/qapidoc_document_path.cpp \
        $$PWD/src/qapidoc_document_path_operation.cpp \
        $$PWD/src/qapidoc_document_path_operation_parameter.cpp \
        $$PWD/src/qapidoc_document_path_operation_response.cpp \
        $$PWD/src/qapidoc_document_path_operation_response_headers.cpp \
        $$PWD/src/qapidoc_document_security_definition.cpp \
        $$PWD/src/qapidoc_document_security_definition_api_key.cpp \
        $$PWD/src/qapidoc_document_security_definition_basic.cpp \
        $$PWD/src/qapidoc_document_security_definition_oauth2.cpp \
        $$PWD/src/qapidoc_document_security_definition_oauth2_scope.cpp \
        $$PWD/src/qapidoc_document_tags.cpp \
        $$PWD/src/qapidoc_meta_types.cpp \
        $$PWD/src/qapidoc_object_mapper.cpp \
        $$PWD/src/qapidoc_types.cpp
