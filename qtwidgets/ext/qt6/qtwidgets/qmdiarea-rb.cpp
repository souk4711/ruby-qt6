#include "qmdiarea-rb.hpp"
#include <qmdiarea.h>

#include <QMdiSubWindow>

using namespace Rice;

Rice::Class rb_cQMdiArea;

void Init_qmdiarea(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQMdiArea =
        // RubyQt6::QtWidgets::QMdiArea
        define_class_under<QMdiArea, QAbstractScrollArea>(rb_mQt6QtWidgets, "QMdiArea")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMdiArea::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMdiArea, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("activation_order", &QMdiArea::activationOrder)
            .define_method("active_sub_window", &QMdiArea::activeSubWindow)
            .define_method("add_sub_window", &QMdiArea::addSubWindow, Arg("widget"), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_method("background", &QMdiArea::background)
            .define_method("current_sub_window", &QMdiArea::currentSubWindow)
            .define_method("document_mode", &QMdiArea::documentMode)
            .define_method("remove_sub_window", &QMdiArea::removeSubWindow, Arg("widget"))
            .define_method("set_activation_order", &QMdiArea::setActivationOrder, Arg("order"))
            .define_method("set_background", &QMdiArea::setBackground, Arg("background"))
            .define_method("set_document_mode", &QMdiArea::setDocumentMode, Arg("enabled"))
            .define_method("set_option", &QMdiArea::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_tab_position", &QMdiArea::setTabPosition, Arg("position"))
            .define_method("set_tab_shape", &QMdiArea::setTabShape, Arg("shape"))
            .define_method("set_tabs_closable", &QMdiArea::setTabsClosable, Arg("closable"))
            .define_method("set_tabs_movable", &QMdiArea::setTabsMovable, Arg("movable"))
            .define_method("set_view_mode", &QMdiArea::setViewMode, Arg("mode"))
            .define_method("sub_window_list", &QMdiArea::subWindowList, Arg("order") = static_cast<QMdiArea::WindowOrder>(QMdiArea::WindowOrder::CreationOrder))
            .define_method("tab_position", &QMdiArea::tabPosition)
            .define_method("tab_shape", &QMdiArea::tabShape)
            .define_method("tabs_closable", &QMdiArea::tabsClosable)
            .define_method("tabs_movable", &QMdiArea::tabsMovable)
            .define_method("test_option", &QMdiArea::testOption, Arg("opton"))
            .define_method("view_mode", &QMdiArea::viewMode)
            // Public Slots
            .define_method("activate_next_sub_window", &QMdiArea::activateNextSubWindow)
            .define_method("activate_previous_sub_window", &QMdiArea::activatePreviousSubWindow)
            .define_method("cascade_sub_windows", &QMdiArea::cascadeSubWindows)
            .define_method("close_active_sub_window", &QMdiArea::closeActiveSubWindow)
            .define_method("close_all_sub_windows", &QMdiArea::closeAllSubWindows)
            .define_method("set_active_sub_window", &QMdiArea::setActiveSubWindow, Arg("window"))
            .define_method("tile_sub_windows", &QMdiArea::tileSubWindows)
            // Signals
            .define_method("sub_window_activated", &QMdiArea::subWindowActivated, Arg("window"));

    Enum<QMdiArea::AreaOption> rb_cQMdiAreaAreaOption =
        // RubyQt6::QtWidgets::QMdiArea::AreaOption
        define_enum_under<QMdiArea::AreaOption>("AreaOption", rb_cQMdiArea)
            .define_value("DontMaximizeSubWindowOnActivation", QMdiArea::AreaOption::DontMaximizeSubWindowOnActivation);

    Enum<QMdiArea::ViewMode> rb_cQMdiAreaViewMode =
        // RubyQt6::QtWidgets::QMdiArea::ViewMode
        define_enum_under<QMdiArea::ViewMode>("ViewMode", rb_cQMdiArea)
            .define_value("SubWindowView", QMdiArea::ViewMode::SubWindowView)
            .define_value("TabbedView", QMdiArea::ViewMode::TabbedView);

    Enum<QMdiArea::WindowOrder> rb_cQMdiAreaWindowOrder =
        // RubyQt6::QtWidgets::QMdiArea::WindowOrder
        define_enum_under<QMdiArea::WindowOrder>("WindowOrder", rb_cQMdiArea)
            .define_value("CreationOrder", QMdiArea::WindowOrder::CreationOrder)
            .define_value("StackingOrder", QMdiArea::WindowOrder::StackingOrder)
            .define_value("ActivationHistoryOrder", QMdiArea::WindowOrder::ActivationHistoryOrder);
}
