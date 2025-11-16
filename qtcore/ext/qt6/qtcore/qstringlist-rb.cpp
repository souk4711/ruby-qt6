#include "qstringlist-rb.hpp"
#include <qstringlist.h>

#include <QList>

using namespace Rice;

Rice::Class rb_cQStringList;

void Init_qstringlist(Rice::Module rb_mQt6QtCore)
{
    rb_cQStringList =
        // RubyQt6::QtCore::QStringList
        define_class_under<QStringList, QList<QString>>(rb_mQt6QtCore, "QStringList")
            .define_method("join", [](QStringList *self, const char *separator) -> QString { return self->join(separator); }, Arg("separator") = static_cast<const char *>(nullptr))
            .define_method("join", [](QStringList *self, QString &separator) -> QString { return self->join(separator); }, Arg("separator") = static_cast<const QString &>(QString()));
}
