#include "qvariantmap-rb.hpp"
#include <qvariantmap.h>

#include <QMap>
#include <QVariant>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVariantMap;

void Init_qvariantmap(Module rb_mQt6QtCore)
{
    rb_cQVariantMap =
        // RubyQt6::QtCore::QVariantMap
        define_qlass_under<QVariantMap, QMap<QString, QVariant>>(rb_mQt6QtCore, "QVariantMap");
}
