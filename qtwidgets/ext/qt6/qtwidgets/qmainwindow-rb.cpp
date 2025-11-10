#include "qmainwindow-rb.hpp"
#include <qmainwindow.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QDockWidget>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

using namespace Rice;

Rice::Class rb_cQMainWindow;

void Init_qmainwindow(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQMainWindow =
        // RubyQt6::QtWidgets::QMainWindow
        define_class_under<QMainWindow, QWidget>(rb_mQt6QtWidgets, "QMainWindow")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMainWindow::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMainWindow, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<void (QMainWindow::*)(Qt::DockWidgetArea, QDockWidget *)>("add_dock_widget", &QMainWindow::addDockWidget, Arg("area"), Arg("dockwidget"))
            .define_method<void (QMainWindow::*)(Qt::DockWidgetArea, QDockWidget *, Qt::Orientation)>("add_dock_widget", &QMainWindow::addDockWidget, Arg("area"), Arg("dockwidget"), Arg("orientation"))
            .define_method<QToolBar *(QMainWindow::*)(const QString &)>("_add_tool_bar", &QMainWindow::addToolBar, Arg("title"))
            .define_method<void (QMainWindow::*)(QToolBar *)>("_add_tool_bar", &QMainWindow::addToolBar, Arg("toolbar"))
            .define_method<void (QMainWindow::*)(Qt::ToolBarArea, QToolBar *)>("_add_tool_bar", &QMainWindow::addToolBar, Arg("area"), Arg("toolbar"))
            .define_method("add_tool_bar_break", &QMainWindow::addToolBarBreak, Arg("area") = static_cast<Qt::ToolBarArea>(Qt::TopToolBarArea))
            .define_method("central_widget", &QMainWindow::centralWidget)
            .define_method("corner", &QMainWindow::corner, Arg("corner"))
            .define_method("create_popup_menu", &QMainWindow::createPopupMenu)
            .define_method("dock_options", &QMainWindow::dockOptions)
            .define_method("dock_widget_area", &QMainWindow::dockWidgetArea, Arg("dockwidget"))
            .define_method("document_mode", &QMainWindow::documentMode)
            .define_method("icon_size", &QMainWindow::iconSize)
            .define_method("insert_tool_bar", &QMainWindow::insertToolBar, Arg("before"), Arg("toolbar"))
            .define_method("insert_tool_bar_break", &QMainWindow::insertToolBarBreak, Arg("before"))
            .define_method("animated?", &QMainWindow::isAnimated)
            .define_method("dock_nesting_enabled?", &QMainWindow::isDockNestingEnabled)
            .define_method("separator?", &QMainWindow::isSeparator, Arg("pos"))
            .define_method("menu_bar", &QMainWindow::menuBar)
            .define_method("menu_widget", &QMainWindow::menuWidget)
            .define_method("remove_dock_widget", &QMainWindow::removeDockWidget, Arg("dockwidget"))
            .define_method("remove_tool_bar", &QMainWindow::removeToolBar, Arg("toolbar"))
            .define_method("remove_tool_bar_break", &QMainWindow::removeToolBarBreak, Arg("before"))
            .define_method("resize_docks", &QMainWindow::resizeDocks, Arg("docks"), Arg("sizes"), Arg("orientation"))
            .define_method("restore_dock_widget", &QMainWindow::restoreDockWidget, Arg("dockwidget"))
            .define_method("restore_state", &QMainWindow::restoreState, Arg("state"), Arg("version") = static_cast<int>(0))
            .define_method("save_state", &QMainWindow::saveState, Arg("version") = static_cast<int>(0))
            .define_method("set_central_widget", &QMainWindow::setCentralWidget, Arg("widget"))
            .define_method("set_corner", &QMainWindow::setCorner, Arg("corner"), Arg("area"))
            .define_method("set_dock_options", &QMainWindow::setDockOptions, Arg("options"))
            .define_method("set_document_mode", &QMainWindow::setDocumentMode, Arg("enabled"))
            .define_method("set_icon_size", &QMainWindow::setIconSize, Arg("icon_size"))
            .define_method("set_menu_bar", &QMainWindow::setMenuBar, Arg("menubar"))
            .define_method("set_menu_widget", &QMainWindow::setMenuWidget, Arg("menubar"))
            .define_method("set_status_bar", &QMainWindow::setStatusBar, Arg("statusbar"))
            .define_method("set_tab_position", &QMainWindow::setTabPosition, Arg("areas"), Arg("tab_position"))
            .define_method("set_tab_shape", &QMainWindow::setTabShape, Arg("tab_shape"))
            .define_method("set_tool_button_style", &QMainWindow::setToolButtonStyle, Arg("tool_button_style"))
            .define_method("split_dock_widget", &QMainWindow::splitDockWidget, Arg("after"), Arg("dockwidget"), Arg("orientation"))
            .define_method("status_bar", &QMainWindow::statusBar)
            .define_method("tab_position", &QMainWindow::tabPosition, Arg("area"))
            .define_method("tab_shape", &QMainWindow::tabShape)
            .define_method("tabified_dock_widgets", &QMainWindow::tabifiedDockWidgets, Arg("dockwidget"))
            .define_method("tabify_dock_widget", &QMainWindow::tabifyDockWidget, Arg("first"), Arg("second"))
            .define_method("take_central_widget", &QMainWindow::takeCentralWidget)
            .define_method("tool_bar_area", &QMainWindow::toolBarArea, Arg("toolbar"))
            .define_method("tool_bar_break", &QMainWindow::toolBarBreak, Arg("toolbar"))
            .define_method("tool_button_style", &QMainWindow::toolButtonStyle)
            .define_method("unified_title_and_tool_bar_on_mac", &QMainWindow::unifiedTitleAndToolBarOnMac)
            // Public Slots
            .define_method("set_animated", &QMainWindow::setAnimated, Arg("enabled"))
            .define_method("set_dock_nesting_enabled", &QMainWindow::setDockNestingEnabled, Arg("enabled"))
            .define_method("set_unified_title_and_tool_bar_on_mac", &QMainWindow::setUnifiedTitleAndToolBarOnMac, Arg("set"))
            // Signals
            .define_method("icon_size_changed", &QMainWindow::iconSizeChanged, Arg("icon_size"))
            .define_method("tabified_dock_widget_activated", &QMainWindow::tabifiedDockWidgetActivated, Arg("dock_widget"))
            .define_method("tool_button_style_changed", &QMainWindow::toolButtonStyleChanged, Arg("tool_button_style"));

    Data_Type<QMainWindow::DockOption> rb_cQMainWindowDockOption =
        // RubyQt6::QtWidgets::QMainWindow::DockOption
        define_qenum_under<QMainWindow::DockOption>(rb_cQMainWindow, "DockOption");
        define_qenum_value_under(rb_cQMainWindowDockOption, "AnimatedDocks", QMainWindow::DockOption::AnimatedDocks);
        define_qenum_value_under(rb_cQMainWindowDockOption, "AllowNestedDocks", QMainWindow::DockOption::AllowNestedDocks);
        define_qenum_value_under(rb_cQMainWindowDockOption, "AllowTabbedDocks", QMainWindow::DockOption::AllowTabbedDocks);
        define_qenum_value_under(rb_cQMainWindowDockOption, "ForceTabbedDocks", QMainWindow::DockOption::ForceTabbedDocks);
        define_qenum_value_under(rb_cQMainWindowDockOption, "VerticalTabs", QMainWindow::DockOption::VerticalTabs);
        define_qenum_value_under(rb_cQMainWindowDockOption, "GroupedDragging", QMainWindow::DockOption::GroupedDragging);

    Data_Type<QFlags<QMainWindow::DockOption>> rb_cQMainWindowDockOptions =
        // RubyQt6::QtWidgets::QMainWindow::DockOptions
        define_qflags_under<QMainWindow::DockOption>(rb_cQMainWindow, "DockOptions");
}
