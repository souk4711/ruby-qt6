#include "qqmlapplicationengine-rb.hpp"
#include <qqmlapplicationengine.h>

using namespace Rice;

Rice::Class rb_cQQmlApplicationEngine;

void Init_qqmlapplicationengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQQmlApplicationEngine =
        // Qt6::QtQml::QQmlApplicationEngine
        define_class_under<QQmlApplicationEngine, QQmlEngine>(rb_mQt6QtQml, "QQmlApplicationEngine")
            .define_constructor(Constructor<QQmlApplicationEngine, QObject *>(), Arg("parent") = static_cast<QObject *>(nullptr))
            .define_constructor(Constructor<QQmlApplicationEngine, const QUrl &, QObject *>(), Arg("url"), Arg("parent") = static_cast<QObject *>(nullptr))
            .define_constructor(Constructor<QQmlApplicationEngine, QAnyStringView, QAnyStringView, QObject *>(), Arg("uri"), Arg("type_name"), Arg("parent") = static_cast<QObject *>(nullptr))
            .define_constructor(Constructor<QQmlApplicationEngine, const QString &, QObject *>(), Arg("file_path"), Arg("parent") = static_cast<QObject *>(nullptr))
            .define_method("root_objects", &QQmlApplicationEngine::rootObjects)
            .define_method<void (QQmlApplicationEngine::*)(const QUrl &)>("load", &QQmlApplicationEngine::load, Arg("url"))
            .define_method<void (QQmlApplicationEngine::*)(const QString &)>("load", &QQmlApplicationEngine::load, Arg("file_path"))
            .define_method("load_from_module", &QQmlApplicationEngine::loadFromModule, Arg("uri"), Arg("type_name"))
            .define_method("set_initial_properties", &QQmlApplicationEngine::setInitialProperties, Arg("initial_properties"))
            .define_method("set_extra_file_selectors", &QQmlApplicationEngine::setExtraFileSelectors, Arg("extra_file_selectors"))
            .define_method("load_data", &QQmlApplicationEngine::loadData, Arg("data"), Arg("url") = static_cast<const QUrl &>(QUrl()))
            .define_method("object_created", &QQmlApplicationEngine::objectCreated, Arg("object"), Arg("url"))
            .define_method("object_creation_failed", &QQmlApplicationEngine::objectCreationFailed, Arg("url"));
}
