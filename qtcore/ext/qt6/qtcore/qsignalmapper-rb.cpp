#include "qsignalmapper-rb.hpp"
#include <qsignalmapper.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSignalMapper;

void Init_qsignalmapper(Module rb_mQt6QtCore)
{
    rb_cQSignalMapper =
        // RubyQt6::QtCore::QSignalMapper
        define_qlass_under<QSignalMapper, QObject>(rb_mQt6QtCore, "QSignalMapper")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSignalMapper::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSignalMapper, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method<QObject *(QSignalMapper::*)(QObject *) const>("mapping", &QSignalMapper::mapping, Arg("object"))
            .define_method<QObject *(QSignalMapper::*)(const QString &) const>("mapping", &QSignalMapper::mapping, Arg("text"))
            .define_method<QObject *(QSignalMapper::*)(int) const>("mapping", &QSignalMapper::mapping, Arg("id"))
            .define_method("remove_mappings", &QSignalMapper::removeMappings, Arg("sender"))
            .define_method<void (QSignalMapper::*)(QObject *, QObject *)>("_set_mapping", &QSignalMapper::setMapping, Arg("sender"), Arg("object"))
            .define_method<void (QSignalMapper::*)(QObject *, const QString &)>("_set_mapping", &QSignalMapper::setMapping, Arg("sender"), Arg("text"))
            .define_method<void (QSignalMapper::*)(QObject *, int)>("_set_mapping", &QSignalMapper::setMapping, Arg("sender"), Arg("id"))
            // Public Slots
            .define_method<void (QSignalMapper::*)()>("map", &QSignalMapper::map)
            .define_method<void (QSignalMapper::*)(QObject *)>("map", &QSignalMapper::map, Arg("sender"));
            // Signals
            // .define_method("mapped_int", &QSignalMapper::mappedInt, Arg("id"))
            // .define_method("mapped_object", &QSignalMapper::mappedObject, Arg("object"))
            // .define_method("mapped_string", &QSignalMapper::mappedString, Arg("text"));
}
