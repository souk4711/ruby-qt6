#include "qtranslator-rb.hpp"
#include <qtranslator.h>

#include <QLocale>

using namespace Rice;

Rice::Class rb_cQTranslator;

void Init_qtranslator(Rice::Module rb_mQt6QtCore)
{
    rb_cQTranslator =
        // RubyQt6::QtCore::QTranslator
        define_class_under<QTranslator, QObject>(rb_mQt6QtCore, "QTranslator")
            // RubyQt6-Defined Functions
            .define_method("load", [](QTranslator *self, const QLocale &locale, const char *filename, const char *prefix, const char *directory, const char *suffix) -> bool { return self->load(locale, QString(filename), QString(prefix), QString(directory), QString(suffix)); }, Arg("locale"), Arg("filename"), Arg("prefix") = static_cast<const char *>(nullptr), Arg("directory") = static_cast<const char *>(nullptr), Arg("suffix") = static_cast<const char *>(nullptr))
            .define_method("load", [](QTranslator *self, const char *filename, const char *directory, const char *search_delimiters, const char *suffix) -> bool { return self->load(QString(filename), QString(directory), QString(search_delimiters), QString(suffix)); }, Arg("filename"), Arg("directory") = static_cast<const char *>(nullptr), Arg("search_delimiters") = static_cast<const char *>(nullptr), Arg("suffix") = static_cast<const char *>(nullptr))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTranslator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTranslator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("file_path", &QTranslator::filePath)
            .define_method("empty?", &QTranslator::isEmpty)
            .define_method("language", &QTranslator::language)
            .define_method<bool (QTranslator::*)(const QLocale &, const QString &, const QString &, const QString &, const QString &)>("load", &QTranslator::load, Arg("locale"), Arg("filename"), Arg("prefix") = static_cast<const QString &>(QString()), Arg("directory") = static_cast<const QString &>(QString()), Arg("suffix") = static_cast<const QString &>(QString()))
            .define_method<bool (QTranslator::*)(const QString &, const QString &, const QString &, const QString &)>("load", &QTranslator::load, Arg("filename"), Arg("directory") = static_cast<const QString &>(QString()), Arg("search_delimiters") = static_cast<const QString &>(QString()), Arg("suffix") = static_cast<const QString &>(QString()))
            .define_method<bool (QTranslator::*)(const uchar *, int, const QString &)>("load", &QTranslator::load, Arg("data"), Arg("len"), Arg("directory") = static_cast<const QString &>(QString()))
            .define_method("translate", &QTranslator::translate, Arg("context"), Arg("source_text"), Arg("disambiguation") = static_cast<const char *>(nullptr), Arg("n") = static_cast<int>(-1));
}
