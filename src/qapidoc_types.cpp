#include "qapidoc_types.h"

namespace QApiDoc{

Q_GLOBAL_STATIC_WITH_ARGS(QByteArrayList, static_object_ignore_methods,({"destroyed", "objectName", "objectNameChanged", "deleteLater", "_q_reregisterTimers"}));


const QByteArrayList &object_ignore_methods()
{
    return *static_object_ignore_methods;
}

}

