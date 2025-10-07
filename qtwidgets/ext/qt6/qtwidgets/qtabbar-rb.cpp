#include "qtabbar-rb.hpp"
#include <qtabbar.h>

using namespace Rice;

Rice::Class rb_cQTabBar;

void Init_qtabbar(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQTabBar =
        // RubyQt6::QtWidgets::QTabBar
        define_class_under<QTabBar, QWidget>(rb_mQt6QtWidgets, "QTabBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTabBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTabBar, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("accessible_tab_name", &QTabBar::accessibleTabName, Arg("index"))
            .define_method<int (QTabBar::*)(const QIcon &, const QString &)>("add_tab", &QTabBar::addTab, Arg("icon"), Arg("text"))
            .define_method<int (QTabBar::*)(const QString &)>("add_tab", &QTabBar::addTab, Arg("text"))
            .define_method("auto_hide", &QTabBar::autoHide)
            .define_method("change_current_on_drag", &QTabBar::changeCurrentOnDrag)
            .define_method("count", &QTabBar::count)
            .define_method("current_index", &QTabBar::currentIndex)
            .define_method("document_mode", &QTabBar::documentMode)
            .define_method("draw_base", &QTabBar::drawBase)
            .define_method("elide_mode", &QTabBar::elideMode)
            .define_method("expanding", &QTabBar::expanding)
            .define_method("icon_size", &QTabBar::iconSize)
            .define_method<int (QTabBar::*)(int, const QIcon &, const QString &)>("insert_tab", &QTabBar::insertTab, Arg("index"), Arg("icon"), Arg("text"))
            .define_method<int (QTabBar::*)(int, const QString &)>("insert_tab", &QTabBar::insertTab, Arg("index"), Arg("text"))
            .define_method("movable?", &QTabBar::isMovable)
            .define_method("tab_enabled?", &QTabBar::isTabEnabled, Arg("index"))
            .define_method("tab_visible?", &QTabBar::isTabVisible, Arg("index"))
            .define_method("move_tab", &QTabBar::moveTab, Arg("from"), Arg("to"))
            .define_method("remove_tab", &QTabBar::removeTab, Arg("index"))
            .define_method("selection_behavior_on_remove", &QTabBar::selectionBehaviorOnRemove)
            .define_method("set_accessible_tab_name", &QTabBar::setAccessibleTabName, Arg("index"), Arg("name"))
            .define_method("set_auto_hide", &QTabBar::setAutoHide, Arg("hide"))
            .define_method("set_change_current_on_drag", &QTabBar::setChangeCurrentOnDrag, Arg("change"))
            .define_method("set_document_mode", &QTabBar::setDocumentMode, Arg("set"))
            .define_method("set_draw_base", &QTabBar::setDrawBase, Arg("draw_the_base"))
            .define_method("set_elide_mode", &QTabBar::setElideMode, Arg("mode"))
            .define_method("set_expanding", &QTabBar::setExpanding, Arg("enabled"))
            .define_method("set_icon_size", &QTabBar::setIconSize, Arg("size"))
            .define_method("set_movable", &QTabBar::setMovable, Arg("movable"))
            .define_method("set_selection_behavior_on_remove", &QTabBar::setSelectionBehaviorOnRemove, Arg("behavior"))
            .define_method("set_shape", &QTabBar::setShape, Arg("shape"))
            .define_method("set_tab_button", &QTabBar::setTabButton, Arg("index"), Arg("position"), Arg("widget"))
            .define_method("set_tab_data", &QTabBar::setTabData, Arg("index"), Arg("data"))
            .define_method("set_tab_enabled", &QTabBar::setTabEnabled, Arg("index"), Arg("enabled"))
            .define_method("set_tab_icon", &QTabBar::setTabIcon, Arg("index"), Arg("icon"))
            .define_method("set_tab_text", &QTabBar::setTabText, Arg("index"), Arg("text"))
            .define_method("set_tab_text_color", &QTabBar::setTabTextColor, Arg("index"), Arg("color"))
            .define_method("set_tab_tool_tip", &QTabBar::setTabToolTip, Arg("index"), Arg("tip"))
            .define_method("set_tab_visible", &QTabBar::setTabVisible, Arg("index"), Arg("visible"))
            .define_method("set_tab_whats_this", &QTabBar::setTabWhatsThis, Arg("index"), Arg("text"))
            .define_method("set_tabs_closable", &QTabBar::setTabsClosable, Arg("closable"))
            .define_method("set_uses_scroll_buttons", &QTabBar::setUsesScrollButtons, Arg("use_buttons"))
            .define_method("shape", &QTabBar::shape)
            .define_method("tab_at", &QTabBar::tabAt, Arg("pos"))
            .define_method("tab_button", &QTabBar::tabButton, Arg("index"), Arg("position"))
            .define_method("tab_data", &QTabBar::tabData, Arg("index"))
            .define_method("tab_icon", &QTabBar::tabIcon, Arg("index"))
            .define_method("tab_rect", &QTabBar::tabRect, Arg("index"))
            .define_method("tab_text", &QTabBar::tabText, Arg("index"))
            .define_method("tab_text_color", &QTabBar::tabTextColor, Arg("index"))
            .define_method("tab_tool_tip", &QTabBar::tabToolTip, Arg("index"))
            .define_method("tab_whats_this", &QTabBar::tabWhatsThis, Arg("index"))
            .define_method("tabs_closable", &QTabBar::tabsClosable)
            .define_method("uses_scroll_buttons", &QTabBar::usesScrollButtons)
            // Public Slots
            .define_method("set_current_index", &QTabBar::setCurrentIndex, Arg("index"))
            // Signals
            .define_method("current_changed", &QTabBar::currentChanged, Arg("index"))
            .define_method("tab_bar_clicked", &QTabBar::tabBarClicked, Arg("index"))
            .define_method("tab_bar_double_clicked", &QTabBar::tabBarDoubleClicked, Arg("index"))
            .define_method("tab_close_requested", &QTabBar::tabCloseRequested, Arg("index"))
            .define_method("tab_moved", &QTabBar::tabMoved, Arg("from"), Arg("to"));

    Enum<QTabBar::ButtonPosition> rb_cQTabBarButtonPosition =
        // RubyQt6::QtWidgets::QTabBar::ButtonPosition
        define_enum_under<QTabBar::ButtonPosition>("ButtonPosition", rb_cQTabBar)
            .define_value("LeftSide", QTabBar::ButtonPosition::LeftSide)
            .define_value("RightSide", QTabBar::ButtonPosition::RightSide);

    Enum<QTabBar::SelectionBehavior> rb_cQTabBarSelectionBehavior =
        // RubyQt6::QtWidgets::QTabBar::SelectionBehavior
        define_enum_under<QTabBar::SelectionBehavior>("SelectionBehavior", rb_cQTabBar)
            .define_value("SelectLeftTab", QTabBar::SelectionBehavior::SelectLeftTab)
            .define_value("SelectRightTab", QTabBar::SelectionBehavior::SelectRightTab)
            .define_value("SelectPreviousTab", QTabBar::SelectionBehavior::SelectPreviousTab);

    Enum<QTabBar::Shape> rb_cQTabBarShape =
        // RubyQt6::QtWidgets::QTabBar::Shape
        define_enum_under<QTabBar::Shape>("Shape", rb_cQTabBar)
            .define_value("RoundedNorth", QTabBar::Shape::RoundedNorth)
            .define_value("RoundedSouth", QTabBar::Shape::RoundedSouth)
            .define_value("RoundedWest", QTabBar::Shape::RoundedWest)
            .define_value("RoundedEast", QTabBar::Shape::RoundedEast)
            .define_value("TriangularNorth", QTabBar::Shape::TriangularNorth)
            .define_value("TriangularSouth", QTabBar::Shape::TriangularSouth)
            .define_value("TriangularWest", QTabBar::Shape::TriangularWest)
            .define_value("TriangularEast", QTabBar::Shape::TriangularEast);
}
