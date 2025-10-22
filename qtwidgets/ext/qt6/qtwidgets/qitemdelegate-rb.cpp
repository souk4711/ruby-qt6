#include "qitemdelegate-rb.hpp"
#include <qitemdelegate.h>

#include <QItemEditorFactory>

using namespace Rice;

Rice::Class rb_cQItemDelegate;

void Init_qitemdelegate(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQItemDelegate =
        // RubyQt6::QtWidgets::QItemDelegate
        define_class_under<QItemDelegate, QAbstractItemDelegate>(rb_mQt6QtWidgets, "QItemDelegate")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QItemDelegate::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QItemDelegate, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("has_clipping", &QItemDelegate::hasClipping)
            .define_method("item_editor_factory", &QItemDelegate::itemEditorFactory)
            .define_method("set_clipping", &QItemDelegate::setClipping, Arg("clip"))
            .define_method("set_item_editor_factory", &QItemDelegate::setItemEditorFactory, Arg("factory"));
}
