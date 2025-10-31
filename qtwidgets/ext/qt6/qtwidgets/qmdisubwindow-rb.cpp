#include "qmdisubwindow-rb.hpp"
#include <qmdisubwindow.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QMdiArea>
#include <QMenu>

using namespace Rice;

Rice::Class rb_cQMdiSubWindow;

void Init_qmdisubwindow(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQMdiSubWindow =
        // RubyQt6::QtWidgets::QMdiSubWindow
        define_class_under<QMdiSubWindow, QWidget>(rb_mQt6QtWidgets, "QMdiSubWindow")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMdiSubWindow::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMdiSubWindow, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("shaded?", &QMdiSubWindow::isShaded)
            .define_method("keyboard_page_step", &QMdiSubWindow::keyboardPageStep)
            .define_method("keyboard_single_step", &QMdiSubWindow::keyboardSingleStep)
            .define_method("maximized_buttons_widget", &QMdiSubWindow::maximizedButtonsWidget)
            .define_method("maximized_system_menu_icon_widget", &QMdiSubWindow::maximizedSystemMenuIconWidget)
            .define_method("mdi_area", &QMdiSubWindow::mdiArea)
            .define_method("set_keyboard_page_step", &QMdiSubWindow::setKeyboardPageStep, Arg("step"))
            .define_method("set_keyboard_single_step", &QMdiSubWindow::setKeyboardSingleStep, Arg("step"))
            .define_method("set_option", &QMdiSubWindow::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_system_menu", &QMdiSubWindow::setSystemMenu, Arg("system_menu"))
            .define_method("set_widget", &QMdiSubWindow::setWidget, Arg("widget").takeOwnership())
            .define_method("system_menu", &QMdiSubWindow::systemMenu)
            .define_method("test_option", &QMdiSubWindow::testOption, Arg("option"))
            .define_method("_widget", &QMdiSubWindow::widget)
            // Public Slots
            .define_method("show_shaded", &QMdiSubWindow::showShaded)
            .define_method("show_system_menu", &QMdiSubWindow::showSystemMenu)
            // Signals
            .define_method("about_to_activate", &QMdiSubWindow::aboutToActivate)
            .define_method("window_state_changed", &QMdiSubWindow::windowStateChanged, Arg("old_state"), Arg("new_state"));

    Data_Type<QMdiSubWindow::SubWindowOption> rb_cQMdiSubWindowSubWindowOption =
        // RubyQt6::QtWidgets::QMdiSubWindow::SubWindowOption
        define_qenum_under<QMdiSubWindow::SubWindowOption>(rb_cQMdiSubWindow, "SubWindowOption");
        define_qenum_value_under(rb_cQMdiSubWindowSubWindowOption, "AllowOutsideAreaHorizontally", QMdiSubWindow::SubWindowOption::AllowOutsideAreaHorizontally);
        define_qenum_value_under(rb_cQMdiSubWindowSubWindowOption, "AllowOutsideAreaVertically", QMdiSubWindow::SubWindowOption::AllowOutsideAreaVertically);
        define_qenum_value_under(rb_cQMdiSubWindowSubWindowOption, "RubberBandResize", QMdiSubWindow::SubWindowOption::RubberBandResize);
        define_qenum_value_under(rb_cQMdiSubWindowSubWindowOption, "RubberBandMove", QMdiSubWindow::SubWindowOption::RubberBandMove);

    Data_Type<QFlags<QMdiSubWindow::SubWindowOption>> rb_cQMdiSubWindowSubWindowOptions =
        // RubyQt6::QtWidgets::QMdiSubWindow::SubWindowOptions
        define_qflags_under<QMdiSubWindow::SubWindowOption>(rb_cQMdiSubWindow, "SubWindowOptions");
}
