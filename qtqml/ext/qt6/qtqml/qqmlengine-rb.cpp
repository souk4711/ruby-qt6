#include "qqmlengine-rb.hpp"
#include <qqmlengine.h>

using namespace Rice;

Rice::Class rb_cQQmlEngine;

void Init_qqmlengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQQmlEngine =
        // Qt6::QtQml::QQmlEngine
        define_class_under<QQmlEngine, QJSEngine>(rb_mQt6QtQml, "QQmlEngine");
}
