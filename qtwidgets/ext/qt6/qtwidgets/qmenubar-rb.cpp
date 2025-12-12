#include "qmenubar-rb.hpp"
#include <qmenubar.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMenuBar;

void Init_qmenubar(Module rb_mQt6QtWidgets)
{
    rb_cQMenuBar =
        // RubyQt6::QtWidgets::QMenuBar
        define_class_under<QMenuBar, QWidget>(rb_mQt6QtWidgets, "QMenuBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMenuBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMenuBar, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("action_at", &QMenuBar::actionAt, Arg("pt"))
            .define_method("action_geometry", &QMenuBar::actionGeometry, Arg("act"))
            .define_method("active_action", &QMenuBar::activeAction)
            .define_method<QAction *(QMenuBar::*)(QMenu *)>("_add_menu", &QMenuBar::addMenu, Arg("menu"))
            .define_method<QMenu *(QMenuBar::*)(const QIcon &, const QString &)>("_add_menu", &QMenuBar::addMenu, Arg("icon"), Arg("title"))
            .define_method<QMenu *(QMenuBar::*)(const QString &)>("_add_menu", &QMenuBar::addMenu, Arg("title"))
            .define_method("add_separator", &QMenuBar::addSeparator)
            .define_method("clear", &QMenuBar::clear)
            .define_method("corner_widget", &QMenuBar::cornerWidget, Arg("corner") = static_cast<Qt::Corner>(Qt::TopRightCorner))
            .define_method("insert_menu", &QMenuBar::insertMenu, Arg("before"), Arg("menu"))
            .define_method("insert_separator", &QMenuBar::insertSeparator, Arg("before"))
            .define_method("default_up?", &QMenuBar::isDefaultUp)
            .define_method("native_menu_bar?", &QMenuBar::isNativeMenuBar)
            .define_method("set_active_action", &QMenuBar::setActiveAction, Arg("action"))
            .define_method("set_corner_widget", &QMenuBar::setCornerWidget, Arg("widget"), Arg("corner") = static_cast<Qt::Corner>(Qt::TopRightCorner))
            .define_method("set_default_up", &QMenuBar::setDefaultUp, Arg("enable"))
            .define_method("set_native_menu_bar", &QMenuBar::setNativeMenuBar, Arg("native_menu_bar"))
            // Public Slots
            .define_method("set_visible", &QMenuBar::setVisible, Arg("visible"));
            // Signals
            // .define_method("hovered", &QMenuBar::hovered, Arg("action"))
            // .define_method("triggered", &QMenuBar::triggered, Arg("action"));
}
