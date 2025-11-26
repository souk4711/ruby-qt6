#include "qmenu-rb.hpp"
#include <qmenu.h>

using namespace Rice;

Rice::Class rb_cQMenu;

void Init_qmenu(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQMenu =
        // RubyQt6::QtWidgets::QMenu
        define_class_under<QMenu, QWidget>(rb_mQt6QtWidgets, "QMenu")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMenu::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMenu, const QString &, QWidget *>(), Arg("title"), Arg("parent"))
            // Public Functions
            .define_method("action_at", &QMenu::actionAt, Arg("pt"))
            .define_method("action_geometry", &QMenu::actionGeometry, Arg("act"))
            .define_method("active_action", &QMenu::activeAction)
            .define_method<QAction *(QMenu::*)(QMenu *)>("add_menu", &QMenu::addMenu, Arg("menu"))
            .define_method<QMenu *(QMenu::*)(const QIcon &, const QString &)>("add_menu", &QMenu::addMenu, Arg("icon"), Arg("title"))
            .define_method<QMenu *(QMenu::*)(const QString &)>("add_menu", &QMenu::addMenu, Arg("title"))
            .define_method<QAction *(QMenu::*)(const QIcon &, const QString &)>("add_section", &QMenu::addSection, Arg("icon"), Arg("text"))
            .define_method<QAction *(QMenu::*)(const QString &)>("add_section", &QMenu::addSection, Arg("text"))
            .define_method("add_separator", &QMenu::addSeparator)
            .define_method("clear", &QMenu::clear)
            .define_method("default_action", &QMenu::defaultAction)
            .define_method<QAction *(QMenu::*)()>("exec", &QMenu::exec)
            .define_method<QAction *(QMenu::*)(const QPoint &, QAction *)>("exec", &QMenu::exec, Arg("pos"), Arg("at") = static_cast<QAction *>(nullptr))
            .define_method("hide_tear_off_menu", &QMenu::hideTearOffMenu)
            .define_method("icon", &QMenu::icon)
            .define_method("insert_menu", &QMenu::insertMenu, Arg("before"), Arg("menu"))
            .define_method<QAction *(QMenu::*)(QAction *, const QIcon &, const QString &)>("insert_section", &QMenu::insertSection, Arg("before"), Arg("icon"), Arg("text"))
            .define_method<QAction *(QMenu::*)(QAction *, const QString &)>("insert_section", &QMenu::insertSection, Arg("before"), Arg("text"))
            .define_method("insert_separator", &QMenu::insertSeparator, Arg("before"))
            .define_method("empty?", &QMenu::isEmpty)
            .define_method("tear_off_enabled?", &QMenu::isTearOffEnabled)
            .define_method("tear_off_menu_visible?", &QMenu::isTearOffMenuVisible)
            .define_method("menu_action", &QMenu::menuAction)
            .define_method("popup", &QMenu::popup, Arg("pos"), Arg("at") = static_cast<QAction *>(nullptr))
            .define_method("separators_collapsible", &QMenu::separatorsCollapsible)
            .define_method("set_active_action", &QMenu::setActiveAction, Arg("act"))
            .define_method("set_default_action", &QMenu::setDefaultAction, Arg("act"))
            .define_method("set_icon", &QMenu::setIcon, Arg("icon"))
            .define_method("set_no_replay_for", &QMenu::setNoReplayFor, Arg("widget"))
            .define_method("set_separators_collapsible", &QMenu::setSeparatorsCollapsible, Arg("collapse"))
            .define_method("set_tear_off_enabled", &QMenu::setTearOffEnabled, Arg("enable"))
            .define_method("set_title", &QMenu::setTitle, Arg("title"))
            .define_method("set_tool_tips_visible", &QMenu::setToolTipsVisible, Arg("visible"))
            .define_method<void (QMenu::*)()>("show_tear_off_menu", &QMenu::showTearOffMenu)
            .define_method<void (QMenu::*)(const QPoint &)>("show_tear_off_menu", &QMenu::showTearOffMenu, Arg("pos"))
            .define_method("title", &QMenu::title)
            .define_method("tool_tips_visible", &QMenu::toolTipsVisible)
            // Signals
            // .define_method("about_to_hide", &QMenu::aboutToHide)
            // .define_method("about_to_show", &QMenu::aboutToShow)
            // .define_method("hovered", &QMenu::hovered, Arg("action"))
            // .define_method("triggered", &QMenu::triggered, Arg("action"))
            // Static Public Members
            .define_singleton_function<QAction *(*)(const QList<QAction *> &, const QPoint &, QAction *, QWidget *)>("exec", &QMenu::exec, Arg("actions"), Arg("pos"), Arg("at") = static_cast<QAction *>(nullptr), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_singleton_function("menu_in_action", &QMenu::menuInAction, Arg("action"));
}
