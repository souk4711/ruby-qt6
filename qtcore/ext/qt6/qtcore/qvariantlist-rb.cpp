#include "qvariantlist-rb.hpp"
#include <qvariantlist.h>

#include <QList>
#include <QVariant>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVariantList;

void Init_qvariantlist(Module rb_mQt6QtCore)
{
    rb_cQVariantList =
        // RubyQt6::QtCore::QVariantList
        define_class_under<QVariantList, QList<QVariant>>(rb_mQt6QtCore, "QVariantList");
}
