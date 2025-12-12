#include "qerrormessage-rb.hpp"
#include <qerrormessage.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQErrorMessage;

void Init_qerrormessage(Module rb_mQt6QtWidgets)
{
    rb_cQErrorMessage =
        // RubyQt6::QtWidgets::QErrorMessage
        define_class_under<QErrorMessage, QDialog>(rb_mQt6QtWidgets, "QErrorMessage")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QErrorMessage::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QErrorMessage, QWidget *>(), Arg("parent"))
            // Public Slots
            .define_method<void (QErrorMessage::*)(const QString &)>("show_message", &QErrorMessage::showMessage, Arg("message"))
            .define_method<void (QErrorMessage::*)(const QString &, const QString &)>("show_message", &QErrorMessage::showMessage, Arg("message"), Arg("type"))
            // Static Public Members
            .define_singleton_function("qt_handler", &QErrorMessage::qtHandler);
}
