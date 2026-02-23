#include "qqmlapplicationengine-rb.hpp"
#include <qqmlapplicationengine.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQQmlApplicationEngine;

void Init_qqmlapplicationengine(Module rb_mQt6QtQml)
{
    rb_cQQmlApplicationEngine =
        // RubyQt6::QtQml::QQmlApplicationEngine
        define_qlass_under<QQmlApplicationEngine, QQmlEngine>(rb_mQt6QtQml, "QQmlApplicationEngine")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QQmlApplicationEngine::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QQmlApplicationEngine, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("root_objects", &QQmlApplicationEngine::rootObjects)
            // Public Slots
            .define_method<void (QQmlApplicationEngine::*)(const QString &)>("load", &QQmlApplicationEngine::load, Arg("file_path"))
            .define_method<void (QQmlApplicationEngine::*)(const QUrl &)>("load", &QQmlApplicationEngine::load, Arg("url"))
            .define_method("load_data", &QQmlApplicationEngine::loadData, Arg("data"), Arg("url") = static_cast<const QUrl &>(QUrl()))
            .define_method("load_from_module", &QQmlApplicationEngine::loadFromModule, Arg("uri"), Arg("type_name"))
            .define_method("set_extra_file_selectors", &QQmlApplicationEngine::setExtraFileSelectors, Arg("extra_file_selectors"))
            .define_method("_set_initial_properties", &QQmlApplicationEngine::setInitialProperties, Arg("initial_properties"));
            // Signals
            // .define_method("object_created", &QQmlApplicationEngine::objectCreated, Arg("object"), Arg("url"))
            // .define_method("object_creation_failed", &QQmlApplicationEngine::objectCreationFailed, Arg("url"));
}
