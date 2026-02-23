#include "qtextlist-rb.hpp"
#include <qtextlist.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextList;

void Init_qtextlist(Module rb_mQt6QtGui)
{
    rb_cQTextList =
        // RubyQt6::QtGui::QTextList
        define_qlass_under<QTextList, QTextBlockGroup>(rb_mQt6QtGui, "QTextList")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextList::staticMetaObject; })
            // Public Functions
            .define_method("add", &QTextList::add, Arg("block"))
            .define_method("count", &QTextList::count)
            .define_method("format", &QTextList::format)
            .define_method("item", &QTextList::item, Arg("i"))
            .define_method("item_number", &QTextList::itemNumber, Arg("block"))
            .define_method("item_text", &QTextList::itemText, Arg("block"))
            .define_method("remove", &QTextList::remove, Arg("block"))
            .define_method("remove_item", &QTextList::removeItem, Arg("i"))
            .define_method("set_format", &QTextList::setFormat, Arg("format"));
}
