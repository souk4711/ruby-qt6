#include "qjsengine-rb.hpp"
#include <qjsengine.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQJSEngine;

void Init_qjsengine(Module rb_mQt6QtQml)
{
    rb_cQJSEngine =
        // RubyQt6::QtQml::QJSEngine
        define_class_under<QJSEngine, QObject>(rb_mQt6QtQml, "QJSEngine")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QJSEngine::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QJSEngine, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("catch_error", &QJSEngine::catchError)
            .define_method("collect_garbage", &QJSEngine::collectGarbage)
            .define_method("evaluate", &QJSEngine::evaluate, Arg("program"), Arg("file_name") = static_cast<const QString &>(QString()), Arg("line_number") = static_cast<int>(1), Arg("exception_stack_trace") = static_cast<QStringList *>(nullptr))
            .define_method("global_object", &QJSEngine::globalObject)
            .define_method("has_error", &QJSEngine::hasError)
            .define_method("import_module", &QJSEngine::importModule, Arg("file_name"))
            .define_method("install_extensions", &QJSEngine::installExtensions, Arg("extensions"), Arg("object") = static_cast<const QJSValue &>(QJSValue()))
            .define_method("interrupted?", &QJSEngine::isInterrupted)
            .define_method("new_array", &QJSEngine::newArray, Arg("length") = static_cast<uint>(0))
            .define_method("new_error_object", &QJSEngine::newErrorObject, Arg("error_type"), Arg("message") = static_cast<const QString &>(QString()))
            .define_method("new_object", &QJSEngine::newObject)
            .define_method<QJSValue (QJSEngine::*)(const QMetaObject *)>("new_qmetaobject", &QJSEngine::newQMetaObject, Arg("metaobject"))
            .define_method("new_qobject", &QJSEngine::newQObject, Arg("object"))
            .define_method("new_symbol", &QJSEngine::newSymbol, Arg("name"))
            .define_method("register_module", &QJSEngine::registerModule, Arg("module_name"), Arg("value"))
            .define_method("set_interrupted", &QJSEngine::setInterrupted, Arg("interrupted"))
            .define_method("set_ui_language", &QJSEngine::setUiLanguage, Arg("language"))
            .define_method<void (QJSEngine::*)(QJSValue::ErrorType, const QString &)>("throw_error", &QJSEngine::throwError, Arg("error_type"), Arg("message") = static_cast<const QString &>(QString()))
            .define_method<void (QJSEngine::*)(const QJSValue &)>("throw_error", &QJSEngine::throwError, Arg("error"))
            .define_method<void (QJSEngine::*)(const QString &)>("throw_error", &QJSEngine::throwError, Arg("message"))
            .define_method("ui_language", &QJSEngine::uiLanguage)
            // Signals
            // .define_method("ui_language_changed", &QJSEngine::uiLanguageChanged)
            // Static Public Members
            .define_singleton_function("object_ownership", &QJSEngine::objectOwnership, Arg("obj"))
            .define_singleton_function("set_object_ownership", &QJSEngine::setObjectOwnership, Arg("obj"), Arg("ownership"));
}
