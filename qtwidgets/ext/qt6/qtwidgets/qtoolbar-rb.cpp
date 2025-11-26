#include "qtoolbar-rb.hpp"
#include <qtoolbar.h>

using namespace Rice;

Rice::Class rb_cQToolBar;

void Init_qtoolbar(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQToolBar =
        // RubyQt6::QtWidgets::QToolBar
        define_class_under<QToolBar, QWidget>(rb_mQt6QtWidgets, "QToolBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QToolBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QToolBar, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<QAction *(QToolBar::*)(const QPoint &) const>("action_at", &QToolBar::actionAt, Arg("p"))
            .define_method<QAction *(QToolBar::*)(int, int) const>("action_at", &QToolBar::actionAt, Arg("x"), Arg("y"))
            .define_method("action_geometry", &QToolBar::actionGeometry, Arg("action"))
            .define_method("add_separator", &QToolBar::addSeparator)
            .define_method("add_widget", &QToolBar::addWidget, Arg("widget"))
            .define_method("allowed_areas", &QToolBar::allowedAreas)
            .define_method("clear", &QToolBar::clear)
            .define_method("icon_size", &QToolBar::iconSize)
            .define_method("insert_separator", &QToolBar::insertSeparator, Arg("before"))
            .define_method("insert_widget", &QToolBar::insertWidget, Arg("before"), Arg("widget"))
            .define_method("area_allowed?", &QToolBar::isAreaAllowed, Arg("area"))
            .define_method("floatable?", &QToolBar::isFloatable)
            .define_method("floating?", &QToolBar::isFloating)
            .define_method("movable?", &QToolBar::isMovable)
            .define_method("orientation", &QToolBar::orientation)
            .define_method("set_allowed_areas", &QToolBar::setAllowedAreas, Arg("areas"))
            .define_method("set_floatable", &QToolBar::setFloatable, Arg("floatable"))
            .define_method("set_movable", &QToolBar::setMovable, Arg("movable"))
            .define_method("set_orientation", &QToolBar::setOrientation, Arg("orientation"))
            .define_method("toggle_view_action", &QToolBar::toggleViewAction)
            .define_method("tool_button_style", &QToolBar::toolButtonStyle)
            .define_method("widget_for_action", &QToolBar::widgetForAction, Arg("action"))
            // Public Slots
            .define_method("set_icon_size", &QToolBar::setIconSize, Arg("icon_size"))
            .define_method("set_tool_button_style", &QToolBar::setToolButtonStyle, Arg("tool_button_style"));
            // Signals
            // .define_method("action_triggered", &QToolBar::actionTriggered, Arg("action"))
            // .define_method("allowed_areas_changed", &QToolBar::allowedAreasChanged, Arg("allowed_areas"))
            // .define_method("icon_size_changed", &QToolBar::iconSizeChanged, Arg("icon_size"))
            // .define_method("movable_changed", &QToolBar::movableChanged, Arg("movable"))
            // .define_method("orientation_changed", &QToolBar::orientationChanged, Arg("orientation"))
            // .define_method("tool_button_style_changed", &QToolBar::toolButtonStyleChanged, Arg("tool_button_style"))
            // .define_method("top_level_changed", &QToolBar::topLevelChanged, Arg("top_level"))
            // .define_method("visibility_changed", &QToolBar::visibilityChanged, Arg("visible"));
}
