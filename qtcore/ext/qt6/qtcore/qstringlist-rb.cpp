#include "qstringlist-rb.hpp"
#include <qstringlist.h>

#include <QList>

using namespace Rice;

Rice::Class rb_cQStringList;

void Init_qstringlist(Rice::Module rb_mQt6QtCore)
{
    rb_cQStringList =
        // RubyQt6::QtCore::QStringList
        define_class_under<QStringList, QList<QString>>(rb_mQt6QtCore, "QStringList");
}
