#pragma once

#include <QObject>

#define dPvtFree() {dPvt(); delete&p; this->p=nullptr;}

#define Q_API_DOC_INFO()\
    Q_INVOKABLE const QVariant documentation()\
    {\
        QApiDocument doc;\
        doc.load(this);\
        return doc.toVariant();\
    }\
    Q_INVOKABLE void __doc_api_info(QApiDocument*document)

#define Q_API_DOC_PATH(method) Q_INVOKABLE void __doc_api_info_path_operation_##method(QApiPath*path)



