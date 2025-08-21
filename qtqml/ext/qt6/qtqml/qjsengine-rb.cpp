#include "qjsengine-rb.hpp"
#include <qjsengine.h>

using namespace Rice;

Rice::Class rb_cQJSEngine;

void Init_qjsengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQJSEngine =
        // Qt6::QtQml::QJSEngine
        define_class_under<QJSEngine, QObject>(rb_mQt6QtQml, "QJSEngine");
}
