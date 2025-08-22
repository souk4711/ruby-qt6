#include "qqmlapplicationengine-rb.hpp"
#include <qqmlapplicationengine.h>

using namespace Rice;

Rice::Class rb_cQQmlApplicationEngine;

void Init_qqmlapplicationengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQQmlApplicationEngine =
        // RubyQt6::QtQml::QQmlApplicationEngine
        define_class_under<QQmlApplicationEngine, QQmlEngine>(rb_mQt6QtQml, "QQmlApplicationEngine")
            .define_constructor(Constructor<QQmlApplicationEngine, QObject*>(), Arg("parent") = static_cast<QObject *>(nullptr))
            .define_method<void(QQmlApplicationEngine::*)(const QString&)>("load", &QQmlApplicationEngine::load, Arg("file_path"));
}
