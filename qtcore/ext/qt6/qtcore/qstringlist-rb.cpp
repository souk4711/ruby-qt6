#include "qstringlist-rb.hpp"
#include <qstringlist.h>

#include <rice/qlist.hpp>

using namespace Rice;

Rice::Class rb_cQStringList;

void Init_qstringlist(Rice::Module rb_mQt6QtCore)
{
    define_qlist_under<QString>(rb_mQt6QtCore, "QList_QString");

    rb_cQStringList =
        // RubyQt6::QtCore::QStringList
        define_class_under<QStringList, QList<QString>>(rb_mQt6QtCore, "QStringList");
}
