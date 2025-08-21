#include "qjsengine-rb.hpp"
#include <qjsengine.h>

using namespace Rice;

Rice::Class rb_cQJSEngine;

void Init_qjsengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQJSEngine =
        // Qt6::QtQml::QJSEngine
        define_class_under<QJSEngine, QObject>(rb_mQt6QtQml, "QJSEngine")
            .define_constructor(Constructor<QJSEngine>())
            .define_constructor(Constructor<QJSEngine, QObject *>(), Arg("parent"))
            .define_method("global_object", &QJSEngine::globalObject)
            .define_method("evaluate", &QJSEngine::evaluate, Arg("program"), Arg("file_name") = static_cast<const QString &>(QString()), Arg("line_number") = static_cast<int>(1), Arg("exception_stack_trace") = static_cast<QStringList *>(nullptr))
            .define_method("import_module", &QJSEngine::importModule, Arg("file_name"))
            .define_method("register_module", &QJSEngine::registerModule, Arg("module_name"), Arg("value"))
            .define_method("new_object", &QJSEngine::newObject)
            .define_method("new_symbol", &QJSEngine::newSymbol, Arg("name"))
            .define_method("new_array", &QJSEngine::newArray, Arg("length") = static_cast<uint>(0))
            .define_method("new_q_object", &QJSEngine::newQObject, Arg("object"))
            // TODO: .define_method("new_q_meta_object", &QJSEngine::newQMetaObject, Arg("meta_object"))
            .define_method("new_error_object", &QJSEngine::newErrorObject, Arg("error_type"), Arg("message") = static_cast<const QString &>(QString()))
            .define_method("collect_garbage", &QJSEngine::collectGarbage)
            .define_singleton_function("set_object_ownership", &QJSEngine::setObjectOwnership, Arg(""), Arg(""))
            .define_singleton_function("object_ownership", &QJSEngine::objectOwnership, Arg(""))
            .define_method("install_extensions", &QJSEngine::installExtensions, Arg("extensions"), Arg("object") = static_cast<const QJSValue &>(QJSValue()))
            .define_method("set_interrupted", &QJSEngine::setInterrupted, Arg("interrupted"))
            .define_method("is_interrupted", &QJSEngine::isInterrupted)
            // TODO: .define_method("handle", &QJSEngine::handle)
            .define_method<void (QJSEngine::*)(const QString &)>("throw_error", &QJSEngine::throwError, Arg("message"))
            .define_method<void (QJSEngine::*)(QJSValue::ErrorType, const QString &)>("throw_error", &QJSEngine::throwError, Arg("error_type"), Arg("message") = static_cast<const QString &>(QString()))
            .define_method<void (QJSEngine::*)(const QJSValue &)>("throw_error", &QJSEngine::throwError, Arg("error"))
            .define_method("has_error", &QJSEngine::hasError)
            .define_method("catch_error", &QJSEngine::catchError)
            .define_method("ui_language", &QJSEngine::uiLanguage)
            .define_method("set_ui_language", &QJSEngine::setUiLanguage, Arg("language"))
            .define_method("ui_language_changed", &QJSEngine::uiLanguageChanged);

    // clang-format off
    Enum<QJSEngine::ObjectOwnership> rb_cQJSEngineObjectOwnership =
        // Qt6::QtQml::QJSEngine::ObjectOwnership
        define_enum_under<QJSEngine::ObjectOwnership>("ObjectOwnership", rb_cQJSEngine)
            .define_value("CppOwnership", QJSEngine::ObjectOwnership::CppOwnership)
            .define_value("JavaScriptOwnership", QJSEngine::ObjectOwnership::JavaScriptOwnership);

    Enum<QJSEngine::Extension> rb_cQJSEngineExtension =
        // Qt6::QtQml::QJSEngine::Extension
        define_enum_under<QJSEngine::Extension>("Extension", rb_cQJSEngine)
            .define_value("TranslationExtension", QJSEngine::Extension::TranslationExtension)
            .define_value("ConsoleExtension", QJSEngine::Extension::ConsoleExtension)
            .define_value("GarbageCollectionExtension", QJSEngine::Extension::GarbageCollectionExtension)
            .define_value("AllExtensions", QJSEngine::Extension::AllExtensions);
}
