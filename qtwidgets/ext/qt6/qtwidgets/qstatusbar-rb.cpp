#include "qstatusbar-rb.hpp"
#include <qstatusbar.h>

using namespace Rice;

Rice::Class rb_cQStatusBar;

void Init_qstatusbar(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStatusBar =
        // RubyQt6::QtWidgets::QStatusBar
        define_class_under<QStatusBar, QWidget>(rb_mQt6QtWidgets, "QStatusBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStatusBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QStatusBar, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_permanent_widget", &QStatusBar::addPermanentWidget, Arg("widget"), Arg("stretch") = static_cast<int>(0))
            .define_method("add_widget", &QStatusBar::addWidget, Arg("widget"), Arg("stretch") = static_cast<int>(0))
            .define_method("current_message", &QStatusBar::currentMessage)
            .define_method("insert_permanent_widget", &QStatusBar::insertPermanentWidget, Arg("index"), Arg("widget"), Arg("stretch") = static_cast<int>(0))
            .define_method("insert_widget", &QStatusBar::insertWidget, Arg("index"), Arg("widget"), Arg("stretch") = static_cast<int>(0))
            .define_method("size_grip_enabled?", &QStatusBar::isSizeGripEnabled)
            .define_method("remove_widget", &QStatusBar::removeWidget, Arg("widget"))
            .define_method("set_size_grip_enabled", &QStatusBar::setSizeGripEnabled, Arg("enabled"))
            // Public Slots
            .define_method("clear_message", &QStatusBar::clearMessage)
            .define_method("show_message", &QStatusBar::showMessage, Arg("text"), Arg("timeout") = static_cast<int>(0))
            // Signals
            .define_method("message_changed", &QStatusBar::messageChanged, Arg("text"));
}
