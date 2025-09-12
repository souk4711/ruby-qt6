#include "qmetamethod-rb.hpp"
#include <qmetaobject.h>

using namespace Rice;

Rice::Class rb_cQMetaMethod;

void Init_qmetamethod(Rice::Module rb_mQt6QtCore)
{
    rb_cQMetaMethod =
        // RubyQt6::QtCore::QMetaMethod
        define_class_under<QMetaMethod>(rb_mQt6QtCore, "QMetaMethod")
            // Public Functions
            .define_method("access", &QMetaMethod::access)
            .define_method("attributes", &QMetaMethod::attributes)
            .define_method("enclosing_meta_object", &QMetaMethod::enclosingMetaObject)
            .define_method("get_parameter_types", &QMetaMethod::getParameterTypes, Arg("types"))
            .define_method<bool (QMetaMethod::*)(QObject *, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke", &QMetaMethod::invoke, Arg("object"), Arg("val0"), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method<bool (QMetaMethod::*)(QObject *, QGenericReturnArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke", &QMetaMethod::invoke, Arg("object"), Arg("return_value"), Arg("val0") = static_cast<QGenericArgument>(QGenericArgument(nullptr)), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method<bool (QMetaMethod::*)(QObject *, Qt::ConnectionType, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke", &QMetaMethod::invoke, Arg("object"), Arg("connection_type"), Arg("val0"), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method<bool (QMetaMethod::*)(QObject *, Qt::ConnectionType, QGenericReturnArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke", &QMetaMethod::invoke, Arg("object"), Arg("connection_type"), Arg("return_value"), Arg("val0") = static_cast<QGenericArgument>(QGenericArgument(nullptr)), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method<bool (QMetaMethod::*)(void *, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke_on_gadget", &QMetaMethod::invokeOnGadget, Arg("gadget"), Arg("val0"), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method<bool (QMetaMethod::*)(void *, QGenericReturnArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument) const>("invoke_on_gadget", &QMetaMethod::invokeOnGadget, Arg("gadget"), Arg("return_value"), Arg("val0") = static_cast<QGenericArgument>(QGenericArgument(nullptr)), Arg("val1") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val2") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val3") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val4") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val5") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val6") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val7") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val8") = static_cast<QGenericArgument>(QGenericArgument()), Arg("val9") = static_cast<QGenericArgument>(QGenericArgument()))
            .define_method("const?", &QMetaMethod::isConst)
            .define_method("valid?", &QMetaMethod::isValid)
            .define_method("method_index", &QMetaMethod::methodIndex)
            .define_method("method_signature", &QMetaMethod::methodSignature)
            .define_method("method_type", &QMetaMethod::methodType)
            .define_method("name", &QMetaMethod::name)
            .define_method("name_view", &QMetaMethod::nameView)
            .define_method("parameter_count", &QMetaMethod::parameterCount)
            .define_method("parameter_meta_type", &QMetaMethod::parameterMetaType, Arg("index"))
            .define_method("parameter_names", &QMetaMethod::parameterNames)
            .define_method("parameter_type", &QMetaMethod::parameterType, Arg("index"))
            .define_method("parameter_type_name", &QMetaMethod::parameterTypeName, Arg("index"))
            .define_method("parameter_types", &QMetaMethod::parameterTypes)
            .define_method("relative_method_index", &QMetaMethod::relativeMethodIndex)
            .define_method("return_meta_type", &QMetaMethod::returnMetaType)
            .define_method("return_type", &QMetaMethod::returnType)
            .define_method("revision", &QMetaMethod::revision)
            .define_method("tag", &QMetaMethod::tag)
            .define_method("type_name", &QMetaMethod::typeName);

    Enum<QMetaMethod::Access> rb_cQMetaMethodAccess =
        // RubyQt6::QtCore::QMetaMethod::Access
        define_enum_under<QMetaMethod::Access>("Access", rb_cQMetaMethod)
            .define_value("Private", QMetaMethod::Access::Private)
            .define_value("Protected", QMetaMethod::Access::Protected)
            .define_value("Public", QMetaMethod::Access::Public);

    Enum<QMetaMethod::MethodType> rb_cQMetaMethodMethodType =
        // RubyQt6::QtCore::QMetaMethod::MethodType
        define_enum_under<QMetaMethod::MethodType>("MethodType", rb_cQMetaMethod)
            .define_value("Method", QMetaMethod::MethodType::Method)
            .define_value("Signal", QMetaMethod::MethodType::Signal)
            .define_value("Slot", QMetaMethod::MethodType::Slot)
            .define_value("Constructor", QMetaMethod::MethodType::Constructor);

    Enum<QMetaMethod::Attributes> rb_cQMetaMethodAttributes =
        // RubyQt6::QtCore::QMetaMethod::Attributes
        define_enum_under<QMetaMethod::Attributes>("Attributes", rb_cQMetaMethod)
            .define_value("Compatibility", QMetaMethod::Attributes::Compatibility)
            .define_value("Cloned", QMetaMethod::Attributes::Cloned)
            .define_value("Scriptable", QMetaMethod::Attributes::Scriptable);
}
