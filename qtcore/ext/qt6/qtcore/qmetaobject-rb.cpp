#include "qmetaobject-rb.hpp"
#include <qmetaobject.h>
#include <qobjectdefs.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMetaObject;
Class rb_cQMetaObjectConnection;

void Init_qmetaobject(Module rb_mQt6QtCore)
{
    rb_cQMetaObject =
        // RubyQt6::QtCore::QMetaObject
        define_class_under<QMetaObject>(rb_mQt6QtCore, "QMetaObject")
            // Public Functions
            .define_method<QObject *(QMetaObject::*)(QObject *) const>("cast", &QMetaObject::cast, Arg("obj"))
            .define_method<const QObject *(QMetaObject::*)(const QObject *) const>("cast", &QMetaObject::cast, Arg("obj"))
            .define_method("class_info", &QMetaObject::classInfo, Arg("index"))
            .define_method("class_info_count", &QMetaObject::classInfoCount)
            .define_method("class_info_offset", &QMetaObject::classInfoOffset)
            .define_method("class_name", &QMetaObject::className)
            .define_method("constructor", &QMetaObject::constructor, Arg("index"))
            .define_method("constructor_count", &QMetaObject::constructorCount)
            .define_method("enumerator", &QMetaObject::enumerator, Arg("index"))
            .define_method("enumerator_count", &QMetaObject::enumeratorCount)
            .define_method("enumerator_offset", &QMetaObject::enumeratorOffset)
            .define_method("index_of_class_info", &QMetaObject::indexOfClassInfo, Arg("name"))
            .define_method("index_of_constructor", &QMetaObject::indexOfConstructor, Arg("constructor"))
            .define_method("index_of_enumerator", &QMetaObject::indexOfEnumerator, Arg("name"))
            .define_method("index_of_method", &QMetaObject::indexOfMethod, Arg("method"))
            .define_method("index_of_property", &QMetaObject::indexOfProperty, Arg("name"))
            .define_method("index_of_signal", &QMetaObject::indexOfSignal, Arg("signal"))
            .define_method("index_of_slot", &QMetaObject::indexOfSlot, Arg("slot"))
            .define_method("inherits", &QMetaObject::inherits, Arg("meta_object"))
            .define_method("meta_type", &QMetaObject::metaType)
            .define_method("method", &QMetaObject::method, Arg("index"))
            .define_method("method_count", &QMetaObject::methodCount)
            .define_method("method_offset", &QMetaObject::methodOffset)
            .define_method("property", &QMetaObject::property, Arg("index"))
            .define_method("property_count", &QMetaObject::propertyCount)
            .define_method("property_offset", &QMetaObject::propertyOffset)
            .define_method("super_class", &QMetaObject::superClass)
            .define_method("tr", &QMetaObject::tr, Arg("s"), Arg("c"), Arg("n") = static_cast<int>(-1))
            .define_method("user_property", &QMetaObject::userProperty);

    rb_cQMetaObjectConnection =
        // RubyQt6::QtCore::QMetaObject::Connection
        define_class_under<QMetaObject::Connection>(rb_cQMetaObject, "Connection");
}
