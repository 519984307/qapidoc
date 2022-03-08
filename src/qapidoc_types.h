#pragma once

#include "./qapidoc_global.h"
#include <QObject>
#include <QVector>
#include <QVariant>
#include <QVariantHash>
#include <QVariantMap>
#include <QVariantList>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QBitArray>
#include <QChar>
#include <QUuid>
#include <QUrl>
#include <QMetaProperty>

namespace QApiDoc{

//!
//! \brief QByteArrayList
//!
typedef QVector<QByteArray> QByteArrayList;

//!
//! \brief object_ignore_methods
//! \return
//!
const QByteArrayList &object_ignore_methods();


}
