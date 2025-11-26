#include "qtoolbox-rb.hpp"
#include <qtoolbox.h>

using namespace Rice;

Rice::Class rb_cQToolBox;

void Init_qtoolbox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQToolBox =
        // RubyQt6::QtWidgets::QToolBox
        define_class_under<QToolBox, QFrame>(rb_mQt6QtWidgets, "QToolBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QToolBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QToolBox, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<int (QToolBox::*)(QWidget *, const QIcon &, const QString &)>("add_item", &QToolBox::addItem, Arg("item"), Arg("icon"), Arg("text"))
            .define_method<int (QToolBox::*)(QWidget *, const QString &)>("add_item", &QToolBox::addItem, Arg("item"), Arg("text"))
            .define_method("count", &QToolBox::count)
            .define_method("current_index", &QToolBox::currentIndex)
            .define_method("current_widget", &QToolBox::currentWidget)
            .define_method("index_of", &QToolBox::indexOf, Arg("widget"))
            .define_method<int (QToolBox::*)(int, QWidget *, const QIcon &, const QString &)>("insert_item", &QToolBox::insertItem, Arg("index"), Arg("item"), Arg("icon"), Arg("text"))
            .define_method<int (QToolBox::*)(int, QWidget *, const QString &)>("insert_item", &QToolBox::insertItem, Arg("index"), Arg("item"), Arg("text"))
            .define_method("item_enabled?", &QToolBox::isItemEnabled, Arg("index"))
            .define_method("item_icon", &QToolBox::itemIcon, Arg("index"))
            .define_method("item_text", &QToolBox::itemText, Arg("index"))
            .define_method("item_tool_tip", &QToolBox::itemToolTip, Arg("index"))
            .define_method("remove_item", &QToolBox::removeItem, Arg("index"))
            .define_method("set_item_enabled", &QToolBox::setItemEnabled, Arg("index"), Arg("enabled"))
            .define_method("set_item_icon", &QToolBox::setItemIcon, Arg("index"), Arg("icon"))
            .define_method("set_item_text", &QToolBox::setItemText, Arg("index"), Arg("text"))
            .define_method("set_item_tool_tip", &QToolBox::setItemToolTip, Arg("index"), Arg("tool_tip"))
            .define_method("widget", &QToolBox::widget, Arg("index"))
            // Public Slots
            .define_method("set_current_index", &QToolBox::setCurrentIndex, Arg("index"))
            .define_method("set_current_widget", &QToolBox::setCurrentWidget, Arg("widget"));
            // Signals
            // .define_method("current_changed", &QToolBox::currentChanged, Arg("index"));
}
