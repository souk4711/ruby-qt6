#include "qqmlcontext-rb.hpp"
#include <qqmlcontext.h>

#include <QQmlEngine>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQQmlContext;
Class rb_cQQmlContextPropertyPair;

void Init_qqmlcontext(Module rb_mQt6QtQml)
{
    rb_cQQmlContext =
        // RubyQt6::QtQml::QQmlContext
        define_qlass_under<QQmlContext, QObject>(rb_mQt6QtQml, "QQmlContext")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QQmlContext * { return qobject_cast<QQmlContext *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QQmlContext::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QQmlContext, QQmlEngine *, QObject *>(), Arg("engine"), Arg("parent"))
            // Public Functions
            .define_method("base_url", &QQmlContext::baseUrl)
            .define_method("context_object", &QQmlContext::contextObject)
            .define_method("context_property", &QQmlContext::contextProperty, Arg("name"))
            .define_method("engine", &QQmlContext::engine)
            .define_method("imported_script", &QQmlContext::importedScript, Arg("name"))
            .define_method("valid?", &QQmlContext::isValid)
            .define_method("name_for_object", &QQmlContext::nameForObject, Arg("object"))
            .define_method("object_for_name", &QQmlContext::objectForName, Arg("name"))
            .define_method("parent_context", &QQmlContext::parentContext)
            .define_method("resolved_url", &QQmlContext::resolvedUrl, Arg("src"))
            .define_method("set_base_url", &QQmlContext::setBaseUrl, Arg("base_url"))
            .define_method("set_context_object", &QQmlContext::setContextObject, Arg("object"))
            .define_method("set_context_properties", &QQmlContext::setContextProperties, Arg("properties"))
            .define_method<void (QQmlContext::*)(const QString &, QObject *)>("_set_context_property", &QQmlContext::setContextProperty, Arg("name"), Arg("value"))
            .define_method<void (QQmlContext::*)(const QString &, const QVariant &)>("_set_context_property", &QQmlContext::setContextProperty, Arg("name"), Arg("value"));

    rb_cQQmlContextPropertyPair =
        // RubyQt6::QtQml::QQmlContext::PropertyPair
        define_qlass_under<QQmlContext::PropertyPair>(rb_cQQmlContext, "PropertyPair")
            .define_constructor(Constructor<QQmlContext::PropertyPair>())
            .define_attr("name", &QQmlContext::PropertyPair::name)
            .define_attr("value", &QQmlContext::PropertyPair::value);
}
