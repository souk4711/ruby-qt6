#include "qvariantmap-rb.hpp"
#include <qvariantmap.h>

#include <QMap>
#include <QVariant>

using namespace Rice;

Rice::Class rb_cQVariantMap;

void Init_qvariantmap(Rice::Module rb_mQt6QtCore)
{
    rb_cQVariantMap =
        // RubyQt6::QtCore::QVariantMap
        define_class_under<QVariantMap, QMap<QString, QVariant>>(rb_mQt6QtCore, "QVariantMap");
}
