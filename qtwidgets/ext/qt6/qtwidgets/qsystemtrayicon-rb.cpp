#include "qsystemtrayicon-rb.hpp"
#include <qsystemtrayicon.h>
#include <rice/qenum.hpp>

#include <QMenu>

using namespace Rice;

Rice::Class rb_cQSystemTrayIcon;

void Init_qsystemtrayicon(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSystemTrayIcon =
        // RubyQt6::QtWidgets::QSystemTrayIcon
        define_class_under<QSystemTrayIcon, QObject>(rb_mQt6QtWidgets, "QSystemTrayIcon")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSystemTrayIcon::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSystemTrayIcon, const QIcon &, QObject *>(), Arg("icon"), Arg("parent"))
            // Public Functions
            .define_method("context_menu", &QSystemTrayIcon::contextMenu)
            .define_method("geometry", &QSystemTrayIcon::geometry)
            .define_method("icon", &QSystemTrayIcon::icon)
            .define_method("visible?", &QSystemTrayIcon::isVisible)
            .define_method("set_context_menu", &QSystemTrayIcon::setContextMenu, Arg("menu"))
            .define_method("set_icon", &QSystemTrayIcon::setIcon, Arg("icon"))
            .define_method("set_tool_tip", &QSystemTrayIcon::setToolTip, Arg("tip"))
            .define_method("tool_tip", &QSystemTrayIcon::toolTip)
            // Public Slots
            .define_method("hide", &QSystemTrayIcon::hide)
            .define_method("set_visible", &QSystemTrayIcon::setVisible, Arg("visible"))
            .define_method("show", &QSystemTrayIcon::show)
            .define_method<void (QSystemTrayIcon::*)(const QString &, const QString &, QSystemTrayIcon::MessageIcon, int)>("show_message", &QSystemTrayIcon::showMessage, Arg("title"), Arg("msg"), Arg("icon") = static_cast<QSystemTrayIcon::MessageIcon>(QSystemTrayIcon::Information), Arg("msecs") = static_cast<int>(10000))
            .define_method<void (QSystemTrayIcon::*)(const QString &, const QString &, const QIcon &, int)>("show_message", &QSystemTrayIcon::showMessage, Arg("title"), Arg("msg"), Arg("icon"), Arg("msecs") = static_cast<int>(10000))
            // Signals
            .define_method("activated", &QSystemTrayIcon::activated, Arg("reason"))
            .define_method("message_clicked", &QSystemTrayIcon::messageClicked)
            // Static Public Members
            .define_singleton_function("system_tray_available?", &QSystemTrayIcon::isSystemTrayAvailable)
            .define_singleton_function("supports_messages", &QSystemTrayIcon::supportsMessages);

    Data_Type<QSystemTrayIcon::ActivationReason> rb_cQSystemTrayIconActivationReason =
        // RubyQt6::QtWidgets::QSystemTrayIcon::ActivationReason
        define_qenum_under<QSystemTrayIcon::ActivationReason>(rb_cQSystemTrayIcon, "ActivationReason");
        define_qenum_value_under(rb_cQSystemTrayIconActivationReason, "Unknown", QSystemTrayIcon::ActivationReason::Unknown);
        define_qenum_value_under(rb_cQSystemTrayIconActivationReason, "Context", QSystemTrayIcon::ActivationReason::Context);
        define_qenum_value_under(rb_cQSystemTrayIconActivationReason, "DoubleClick", QSystemTrayIcon::ActivationReason::DoubleClick);
        define_qenum_value_under(rb_cQSystemTrayIconActivationReason, "Trigger", QSystemTrayIcon::ActivationReason::Trigger);
        define_qenum_value_under(rb_cQSystemTrayIconActivationReason, "MiddleClick", QSystemTrayIcon::ActivationReason::MiddleClick);

    Data_Type<QSystemTrayIcon::MessageIcon> rb_cQSystemTrayIconMessageIcon =
        // RubyQt6::QtWidgets::QSystemTrayIcon::MessageIcon
        define_qenum_under<QSystemTrayIcon::MessageIcon>(rb_cQSystemTrayIcon, "MessageIcon");
        define_qenum_value_under(rb_cQSystemTrayIconMessageIcon, "NoIcon", QSystemTrayIcon::MessageIcon::NoIcon);
        define_qenum_value_under(rb_cQSystemTrayIconMessageIcon, "Information", QSystemTrayIcon::MessageIcon::Information);
        define_qenum_value_under(rb_cQSystemTrayIconMessageIcon, "Warning", QSystemTrayIcon::MessageIcon::Warning);
        define_qenum_value_under(rb_cQSystemTrayIconMessageIcon, "Critical", QSystemTrayIcon::MessageIcon::Critical);
}
