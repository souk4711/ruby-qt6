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
            .define_method("count", [](QStringList *self, const char *str) -> qsizetype {
                Data_Object<QStringList> self_(self);
                auto r = self_.call("count", QString(str));
                return detail::From_Ruby<qsizetype>().convert(r);
            })
            .define_method("include?", [](QStringList *self, const char *str) -> bool {
                Data_Object<QStringList> self_(self);
                auto r = self_.call("include?", QString(str));
                return detail::From_Ruby<bool>().convert(r);
            })
            .define_method("index", [](QStringList *self, const char *str) -> std::optional<qsizetype> {
                Data_Object<QStringList> self_(self);
                auto r = self_.call("index", QString(str));
                return detail::From_Ruby<std::optional<qsizetype>>().convert(r);
            })
            .define_method("insert", [](QStringList *self, qsizetype index, const char *str) -> QStringList * {
                Data_Object<QStringList> self_(self);
                auto _ = self_.call("insert", index, QString(str));
                return self;
            })
            .define_method("push", [](QStringList *self, const char * str) -> QStringList * {
                Data_Object<QStringList> self_(self);
                auto _ = self_.call("push", QString(str));
                return self;
            })
            .define_method("delete", [](QStringList *self, const char * str) -> std::optional<QString> {
                Data_Object<QStringList> self_(self);
                auto r = self_.call("delete", QString(str));
                return detail::From_Ruby<std::optional<QString>>().convert(r);
            })
            .define_method("[]=", [](QStringList *self, qsizetype index, const char *str) -> QString {
                Data_Object<QStringList> self_(self);
                auto r = self_.call("[]=", index, QString(str));
                return detail::From_Ruby<QString>().convert(r);
            })
            .define_method("_join", [](QStringList *self, QString &separator) -> QString {
                return self->join(separator);
            });
}
