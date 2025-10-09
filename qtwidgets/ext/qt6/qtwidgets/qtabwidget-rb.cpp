#include "qtabwidget-rb.hpp"
#include <qtabwidget.h>

#include <QTabBar>

using namespace Rice;

Rice::Class rb_cQTabWidget;

void Init_qtabwidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTabWidget =
        // RubyQt6::QtWidgets::QTabWidget
        define_class_under<QTabWidget, QWidget>(rb_mQt6QtWidgets, "QTabWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTabWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTabWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<int (QTabWidget::*)(QWidget *, const QIcon &, const QString &)>("add_tab", &QTabWidget::addTab, Arg("widget").takeOwnership(), Arg("icon"), Arg("label"))
            .define_method<int (QTabWidget::*)(QWidget *, const QString &)>("add_tab", &QTabWidget::addTab, Arg("widget").takeOwnership(), Arg("label"))
            .define_method("clear", &QTabWidget::clear)
            .define_method("corner_widget", &QTabWidget::cornerWidget, Arg("corner") = static_cast<Qt::Corner>(Qt::TopRightCorner))
            .define_method("count", &QTabWidget::count)
            .define_method("current_index", &QTabWidget::currentIndex)
            .define_method("current_widget", &QTabWidget::currentWidget)
            .define_method("document_mode", &QTabWidget::documentMode)
            .define_method("elide_mode", &QTabWidget::elideMode)
            .define_method("icon_size", &QTabWidget::iconSize)
            .define_method("index_of", &QTabWidget::indexOf, Arg("widget"))
            .define_method<int (QTabWidget::*)(int, QWidget *, const QIcon &, const QString &)>("insert_tab", &QTabWidget::insertTab, Arg("index"), Arg("widget").takeOwnership(), Arg("icon"), Arg("label"))
            .define_method<int (QTabWidget::*)(int, QWidget *, const QString &)>("insert_tab", &QTabWidget::insertTab, Arg("index"), Arg("widget").takeOwnership(), Arg("label"))
            .define_method("movable?", &QTabWidget::isMovable)
            .define_method("tab_enabled?", &QTabWidget::isTabEnabled, Arg("index"))
            .define_method("tab_visible?", &QTabWidget::isTabVisible, Arg("index"))
            .define_method("remove_tab", &QTabWidget::removeTab, Arg("index"))
            .define_method("set_corner_widget", &QTabWidget::setCornerWidget, Arg("widget").takeOwnership(), Arg("corner") = static_cast<Qt::Corner>(Qt::TopRightCorner))
            .define_method("set_document_mode", &QTabWidget::setDocumentMode, Arg("set"))
            .define_method("set_elide_mode", &QTabWidget::setElideMode, Arg("mode"))
            .define_method("set_icon_size", &QTabWidget::setIconSize, Arg("size"))
            .define_method("set_movable", &QTabWidget::setMovable, Arg("movable"))
            .define_method("set_tab_bar_auto_hide", &QTabWidget::setTabBarAutoHide, Arg("enabled"))
            .define_method("set_tab_enabled", &QTabWidget::setTabEnabled, Arg("index"), Arg("enabled"))
            .define_method("set_tab_icon", &QTabWidget::setTabIcon, Arg("index"), Arg("icon"))
            .define_method("set_tab_position", &QTabWidget::setTabPosition, Arg("position"))
            .define_method("set_tab_shape", &QTabWidget::setTabShape, Arg("s"))
            .define_method("set_tab_text", &QTabWidget::setTabText, Arg("index"), Arg("text"))
            .define_method("set_tab_tool_tip", &QTabWidget::setTabToolTip, Arg("index"), Arg("tip"))
            .define_method("set_tab_visible", &QTabWidget::setTabVisible, Arg("index"), Arg("visible"))
            .define_method("set_tab_whats_this", &QTabWidget::setTabWhatsThis, Arg("index"), Arg("text"))
            .define_method("set_tabs_closable", &QTabWidget::setTabsClosable, Arg("closeable"))
            .define_method("set_uses_scroll_buttons", &QTabWidget::setUsesScrollButtons, Arg("use_buttons"))
            .define_method("tab_bar", &QTabWidget::tabBar)
            .define_method("tab_bar_auto_hide", &QTabWidget::tabBarAutoHide)
            .define_method("tab_icon", &QTabWidget::tabIcon, Arg("index"))
            .define_method("tab_position", &QTabWidget::tabPosition)
            .define_method("tab_shape", &QTabWidget::tabShape)
            .define_method("tab_text", &QTabWidget::tabText, Arg("index"))
            .define_method("tab_tool_tip", &QTabWidget::tabToolTip, Arg("index"))
            .define_method("tab_whats_this", &QTabWidget::tabWhatsThis, Arg("index"))
            .define_method("tabs_closable", &QTabWidget::tabsClosable)
            .define_method("uses_scroll_buttons", &QTabWidget::usesScrollButtons)
            .define_method("widget", &QTabWidget::widget, Arg("index"))
            // Public Slots
            .define_method("set_current_index", &QTabWidget::setCurrentIndex, Arg("index"))
            .define_method("set_current_widget", &QTabWidget::setCurrentWidget, Arg("widget"))
            // Signals
            .define_method("current_changed", &QTabWidget::currentChanged, Arg("index"))
            .define_method("tab_bar_clicked", &QTabWidget::tabBarClicked, Arg("index"))
            .define_method("tab_bar_double_clicked", &QTabWidget::tabBarDoubleClicked, Arg("index"))
            .define_method("tab_close_requested", &QTabWidget::tabCloseRequested, Arg("index"));

    Enum<QTabWidget::TabPosition> rb_cQTabWidgetTabPosition =
        // RubyQt6::QtWidgets::QTabWidget::TabPosition
        define_enum_under<QTabWidget::TabPosition>("TabPosition", rb_cQTabWidget)
            .define_value("North", QTabWidget::TabPosition::North)
            .define_value("South", QTabWidget::TabPosition::South)
            .define_value("West", QTabWidget::TabPosition::West)
            .define_value("East", QTabWidget::TabPosition::East);

    Enum<QTabWidget::TabShape> rb_cQTabWidgetTabShape =
        // RubyQt6::QtWidgets::QTabWidget::TabShape
        define_enum_under<QTabWidget::TabShape>("TabShape", rb_cQTabWidget)
            .define_value("Rounded", QTabWidget::TabShape::Rounded)
            .define_value("Triangular", QTabWidget::TabShape::Triangular);
}
