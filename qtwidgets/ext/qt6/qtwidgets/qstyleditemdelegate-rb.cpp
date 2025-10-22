#include "qstyleditemdelegate-rb.hpp"
#include <qstyleditemdelegate.h>

#include <QItemEditorFactory>

using namespace Rice;

Rice::Class rb_cQStyledItemDelegate;

void Init_qstyleditemdelegate(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStyledItemDelegate =
        // RubyQt6::QtWidgets::QStyledItemDelegate
        define_class_under<QStyledItemDelegate, QAbstractItemDelegate>(rb_mQt6QtWidgets, "QStyledItemDelegate")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStyledItemDelegate::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QStyledItemDelegate, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("item_editor_factory", &QStyledItemDelegate::itemEditorFactory)
            .define_method("set_item_editor_factory", &QStyledItemDelegate::setItemEditorFactory, Arg("factory"));
}
