#include "qtranslator-rb.hpp"
#include <qtranslator.h>

#include <QLocale>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTranslator;

void Init_qtranslator(Module rb_mQt6QtCore)
{
    rb_cQTranslator =
        // RubyQt6::QtCore::QTranslator
        define_class_under<QTranslator, QObject>(rb_mQt6QtCore, "QTranslator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTranslator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTranslator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("file_path", &QTranslator::filePath)
            .define_method("empty?", &QTranslator::isEmpty)
            .define_method("language", &QTranslator::language)
            .define_method<bool (QTranslator::*)(const QLocale &, const QString &, const QString &, const QString &, const QString &)>("_load", &QTranslator::load, Arg("locale"), Arg("filename"), Arg("prefix") = static_cast<const QString &>(QString()), Arg("directory") = static_cast<const QString &>(QString()), Arg("suffix") = static_cast<const QString &>(QString()))
            .define_method<bool (QTranslator::*)(const QString &, const QString &, const QString &, const QString &)>("_load", &QTranslator::load, Arg("filename"), Arg("directory") = static_cast<const QString &>(QString()), Arg("search_delimiters") = static_cast<const QString &>(QString()), Arg("suffix") = static_cast<const QString &>(QString()))
            .define_method("translate", &QTranslator::translate, Arg("context"), Arg("source_text"), Arg("disambiguation") = static_cast<const char *>(nullptr), Arg("n") = static_cast<int>(-1));
}
