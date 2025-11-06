#include "qmetaobjectbuilder-rb.hpp"
#include "private/qmetaobjectbuilder_p.h"

using namespace Rice;

Rice::Class rb_cQMetaObjectBuilder;
Rice::Class rb_cQMetaMethodBuilder;
Rice::Class rb_cQMetaPropertyBuilder;
Rice::Class rb_cQMetaEnumBuilder;

void Init_qmetaobjectbuilder(Rice::Module rb_mQt6QtCore)
{
    rb_cQMetaObjectBuilder =
        // RubyQt6::QtCore::QMetaObjectBuilder
        define_class_under<QMetaObjectBuilder>(rb_mQt6QtCore, "QMetaObjectBuilder")
            // Constructor
            .define_constructor(Constructor<QMetaObjectBuilder>())
            // Public Functions
            .define_method("_add_class_info", &QMetaObjectBuilder::addClassInfo, Arg("name"), Arg("value"))
            .define_method<QMetaMethodBuilder (QMetaObjectBuilder::*)(const QByteArray &)>("add_constructor", &QMetaObjectBuilder::addConstructor, Arg("signature"))
            .define_method<QMetaMethodBuilder (QMetaObjectBuilder::*)(const QMetaMethod &)>("add_constructor", &QMetaObjectBuilder::addConstructor, Arg("prototype"))
            .define_method<QMetaEnumBuilder (QMetaObjectBuilder::*)(const QByteArray &)>("add_enumerator", &QMetaObjectBuilder::addEnumerator, Arg("name"))
            .define_method<QMetaEnumBuilder (QMetaObjectBuilder::*)(const QMetaEnum &)>("add_enumerator", &QMetaObjectBuilder::addEnumerator, Arg("prototype"))
            .define_method("add_meta_object", &QMetaObjectBuilder::addMetaObject, Arg("prototype"), Arg("members") = static_cast<QMetaObjectBuilder::AddMembers>(QMetaObjectBuilder::AddMember::AllMembers))
            .define_method<QMetaMethodBuilder (QMetaObjectBuilder::*)(const QByteArray &)>("add_method", &QMetaObjectBuilder::addMethod, Arg("signature"))
            .define_method<QMetaMethodBuilder (QMetaObjectBuilder::*)(const QByteArray &, const QByteArray &)>("add_method", &QMetaObjectBuilder::addMethod, Arg("signature"), Arg("return_type"))
            .define_method<QMetaMethodBuilder (QMetaObjectBuilder::*)(const QMetaMethod &)>("add_method", &QMetaObjectBuilder::addMethod, Arg("prototype"))
            .define_method<QMetaPropertyBuilder (QMetaObjectBuilder::*)(const QByteArray &, const QByteArray &, QMetaType, int)>("add_property", &QMetaObjectBuilder::addProperty, Arg("name"), Arg("type"), Arg("meta_type"), Arg("notifier_id") = static_cast<int>(-1))
            .define_method<QMetaPropertyBuilder (QMetaObjectBuilder::*)(const QByteArray &, const QByteArray &, int)>("add_property", &QMetaObjectBuilder::addProperty, Arg("name"), Arg("type"), Arg("notifier_id") = static_cast<int>(-1))
            .define_method<QMetaPropertyBuilder (QMetaObjectBuilder::*)(const QMetaProperty &)>("add_property", &QMetaObjectBuilder::addProperty, Arg("prototype"))
            .define_method("add_related_meta_object", &QMetaObjectBuilder::addRelatedMetaObject, Arg("meta"))
            .define_method("_add_signal", &QMetaObjectBuilder::addSignal, Arg("signature"))
            .define_method("_add_slot", &QMetaObjectBuilder::addSlot, Arg("signature"))
            .define_method("class_info_count", &QMetaObjectBuilder::classInfoCount)
            .define_method("class_info_name", &QMetaObjectBuilder::classInfoName, Arg("index"))
            .define_method("class_info_value", &QMetaObjectBuilder::classInfoValue, Arg("index"))
            .define_method("class_name", &QMetaObjectBuilder::className)
            .define_method("constructor", &QMetaObjectBuilder::constructor, Arg("index"))
            .define_method("constructor_count", &QMetaObjectBuilder::constructorCount)
            .define_method("enumerator", &QMetaObjectBuilder::enumerator, Arg("index"))
            .define_method("enumerator_count", &QMetaObjectBuilder::enumeratorCount)
            .define_method("flags", &QMetaObjectBuilder::flags)
            .define_method("index_of_class_info", &QMetaObjectBuilder::indexOfClassInfo, Arg("name"))
            .define_method("index_of_constructor", &QMetaObjectBuilder::indexOfConstructor, Arg("signature"))
            .define_method("index_of_enumerator", &QMetaObjectBuilder::indexOfEnumerator, Arg("name"))
            .define_method("index_of_method", &QMetaObjectBuilder::indexOfMethod, Arg("signature"))
            .define_method("index_of_property", &QMetaObjectBuilder::indexOfProperty, Arg("name"))
            .define_method("index_of_signal", &QMetaObjectBuilder::indexOfSignal, Arg("signature"))
            .define_method("index_of_slot", &QMetaObjectBuilder::indexOfSlot, Arg("signature"))
            .define_method("method", &QMetaObjectBuilder::method, Arg("index"))
            .define_method("method_count", &QMetaObjectBuilder::methodCount)
            .define_method("property", &QMetaObjectBuilder::property, Arg("index"))
            .define_method("property_count", &QMetaObjectBuilder::propertyCount)
            .define_method("related_meta_object", &QMetaObjectBuilder::relatedMetaObject, Arg("index"))
            .define_method("related_meta_object_count", &QMetaObjectBuilder::relatedMetaObjectCount)
            .define_method("remove_class_info", &QMetaObjectBuilder::removeClassInfo, Arg("index"))
            .define_method("remove_constructor", &QMetaObjectBuilder::removeConstructor, Arg("index"))
            .define_method("remove_enumerator", &QMetaObjectBuilder::removeEnumerator, Arg("index"))
            .define_method("remove_method", &QMetaObjectBuilder::removeMethod, Arg("index"))
            .define_method("remove_property", &QMetaObjectBuilder::removeProperty, Arg("index"))
            .define_method("remove_related_meta_object", &QMetaObjectBuilder::removeRelatedMetaObject, Arg("index"))
            .define_method("_set_class_name", &QMetaObjectBuilder::setClassName, Arg("name"))
            .define_method("set_flags", &QMetaObjectBuilder::setFlags, Arg("flags"))
            // .define_method("set_static_metacall_function", &QMetaObjectBuilder::setStaticMetacallFunction, Arg("value"))
            .define_method("set_super_class", &QMetaObjectBuilder::setSuperClass, Arg("meta"))
            // .define_method("static_metacall_function", &QMetaObjectBuilder::staticMetacallFunction)
            .define_method("super_class", &QMetaObjectBuilder::superClass)
            .define_method("to_meta_object", &QMetaObjectBuilder::toMetaObject);

    rb_cQMetaMethodBuilder =
        // RubyQt6::QtCore::QMetaMethodBuilder
        define_class_under<QMetaMethodBuilder>(rb_mQt6QtCore, "QMetaMethodBuilder")
            // Public Functions
            .define_method("access", &QMetaMethodBuilder::access)
            .define_method("attributes", &QMetaMethodBuilder::attributes)
            .define_method("index", &QMetaMethodBuilder::index)
            .define_method("const?", &QMetaMethodBuilder::isConst)
            .define_method("method_type", &QMetaMethodBuilder::methodType)
            .define_method("parameter_names", &QMetaMethodBuilder::parameterNames)
            .define_method("parameter_types", &QMetaMethodBuilder::parameterTypes)
            .define_method("return_type", &QMetaMethodBuilder::returnType)
            .define_method("revision", &QMetaMethodBuilder::revision)
            .define_method("set_access", &QMetaMethodBuilder::setAccess, Arg("value"))
            .define_method("set_attributes", &QMetaMethodBuilder::setAttributes, Arg("value"))
            .define_method("set_const", &QMetaMethodBuilder::setConst, Arg("method_is_const") = static_cast<bool>(true))
            .define_method("set_parameter_names", &QMetaMethodBuilder::setParameterNames, Arg("value"))
            .define_method("_set_return_type", &QMetaMethodBuilder::setReturnType, Arg("value"))
            .define_method("set_revision", &QMetaMethodBuilder::setRevision, Arg("revision"))
            .define_method("set_tag", &QMetaMethodBuilder::setTag, Arg("value"))
            .define_method("signature", &QMetaMethodBuilder::signature)
            .define_method("tag", &QMetaMethodBuilder::tag);

    rb_cQMetaPropertyBuilder =
        // RubyQt6::QtCore::QMetaPropertyBuilder
        define_class_under<QMetaPropertyBuilder>(rb_mQt6QtCore, "QMetaPropertyBuilder")
            // Public Functions
            .define_method("has_notify_signal", &QMetaPropertyBuilder::hasNotifySignal)
            .define_method("has_std_cpp_set", &QMetaPropertyBuilder::hasStdCppSet)
            .define_method("index", &QMetaPropertyBuilder::index)
            .define_method("alias?", &QMetaPropertyBuilder::isAlias)
            .define_method("bindable?", &QMetaPropertyBuilder::isBindable)
            .define_method("constant?", &QMetaPropertyBuilder::isConstant)
            .define_method("designable?", &QMetaPropertyBuilder::isDesignable)
            // .define_method("editable?", &QMetaPropertyBuilder::isEditable)
            .define_method("enum_or_flag?", &QMetaPropertyBuilder::isEnumOrFlag)
            .define_method("final?", &QMetaPropertyBuilder::isFinal)
            .define_method("readable?", &QMetaPropertyBuilder::isReadable)
            .define_method("resettable?", &QMetaPropertyBuilder::isResettable)
            .define_method("scriptable?", &QMetaPropertyBuilder::isScriptable)
            .define_method("stored?", &QMetaPropertyBuilder::isStored)
            .define_method("user?", &QMetaPropertyBuilder::isUser)
            .define_method("writable?", &QMetaPropertyBuilder::isWritable)
            .define_method("name", &QMetaPropertyBuilder::name)
            .define_method("notify_signal", &QMetaPropertyBuilder::notifySignal)
            .define_method("remove_notify_signal", &QMetaPropertyBuilder::removeNotifySignal)
            .define_method("revision", &QMetaPropertyBuilder::revision)
            .define_method("set_alias", &QMetaPropertyBuilder::setAlias, Arg("value"))
            .define_method("set_bindable", &QMetaPropertyBuilder::setBindable, Arg("value"))
            .define_method("set_constant", &QMetaPropertyBuilder::setConstant, Arg("value"))
            .define_method("set_designable", &QMetaPropertyBuilder::setDesignable, Arg("value"))
            .define_method("set_enum_or_flag", &QMetaPropertyBuilder::setEnumOrFlag, Arg("value"))
            .define_method("set_final", &QMetaPropertyBuilder::setFinal, Arg("value"))
            .define_method("set_notify_signal", &QMetaPropertyBuilder::setNotifySignal, Arg("value"))
            .define_method("set_readable", &QMetaPropertyBuilder::setReadable, Arg("value"))
            .define_method("set_resettable", &QMetaPropertyBuilder::setResettable, Arg("value"))
            .define_method("set_revision", &QMetaPropertyBuilder::setRevision, Arg("revision"))
            .define_method("set_scriptable", &QMetaPropertyBuilder::setScriptable, Arg("value"))
            .define_method("set_std_cpp_set", &QMetaPropertyBuilder::setStdCppSet, Arg("value"))
            .define_method("set_stored", &QMetaPropertyBuilder::setStored, Arg("value"))
            .define_method("set_user", &QMetaPropertyBuilder::setUser, Arg("value"))
            .define_method("set_writable", &QMetaPropertyBuilder::setWritable, Arg("value"))
            .define_method("type", &QMetaPropertyBuilder::type);

    rb_cQMetaEnumBuilder =
        // RubyQt6::QtCore::QMetaEnumBuilder
        define_class_under<QMetaEnumBuilder>(rb_mQt6QtCore, "QMetaEnumBuilder")
            // Public Functions
            .define_method<int (QMetaEnumBuilder::*)(const QByteArray &, int)>("add_key", &QMetaEnumBuilder::addKey, Arg("name"), Arg("value"))
            .define_method<int (QMetaEnumBuilder::*)(const QByteArray &, quint64)>("add_key", &QMetaEnumBuilder::addKey, Arg("name"), Arg("value"))
            .define_method("enum_name", &QMetaEnumBuilder::enumName)
            .define_method("index", &QMetaEnumBuilder::index)
            .define_method("is64_bit", &QMetaEnumBuilder::is64Bit)
            .define_method("flag?", &QMetaEnumBuilder::isFlag)
            .define_method("scoped?", &QMetaEnumBuilder::isScoped)
            .define_method("key", &QMetaEnumBuilder::key, Arg("index"))
            .define_method("key_count", &QMetaEnumBuilder::keyCount)
            .define_method("meta_type", &QMetaEnumBuilder::metaType)
            .define_method("name", &QMetaEnumBuilder::name)
            .define_method("remove_key", &QMetaEnumBuilder::removeKey, Arg("index"))
            .define_method("set_enum_name", &QMetaEnumBuilder::setEnumName, Arg("alias"))
            .define_method("set_is64_bit", &QMetaEnumBuilder::setIs64Bit, Arg("value"))
            .define_method("set_is_flag", &QMetaEnumBuilder::setIsFlag, Arg("value"))
            .define_method("set_is_scoped", &QMetaEnumBuilder::setIsScoped, Arg("value"))
            .define_method("set_meta_type", &QMetaEnumBuilder::setMetaType, Arg("meta_type"))
            .define_method("value", &QMetaEnumBuilder::value, Arg("index"))
            .define_method("value64", &QMetaEnumBuilder::value64, Arg("index"));
}
