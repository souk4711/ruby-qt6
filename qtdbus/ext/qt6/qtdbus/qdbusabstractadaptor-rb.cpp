#include "qdbusabstractadaptor-rb.hpp"
#include <qdbusabstractadaptor.h>

using namespace Rice;

Rice::Class rb_cQDBusAbstractAdaptor;

void Init_qdbusabstractadaptor(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusAbstractAdaptor =
        // RubyQt6::QtDBus::QDBusAbstractAdaptor
        define_class_under<QDBusAbstractAdaptor, QObject>(rb_mQt6QtDBus, "QDBusAbstractAdaptor")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusAbstractAdaptor::staticMetaObject; });
}
