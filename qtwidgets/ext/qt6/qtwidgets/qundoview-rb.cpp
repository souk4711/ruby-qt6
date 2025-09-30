#include "qundoview-rb.hpp"
#include <qundoview.h>

#include <QUndoGroup>
#include <QUndoStack>

using namespace Rice;

Rice::Class rb_cQUndoView;

void Init_qundoview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQUndoView =
        // RubyQt6::QtWidgets::QUndoView
        define_class_under<QUndoView, QListView>(rb_mQt6QtWidgets, "QUndoView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QUndoView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QUndoView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("clean_icon", &QUndoView::cleanIcon)
            .define_method("empty_label", &QUndoView::emptyLabel)
            .define_method("group", &QUndoView::group)
            .define_method("set_clean_icon", &QUndoView::setCleanIcon, Arg("icon"))
            .define_method("set_empty_label", &QUndoView::setEmptyLabel, Arg("label"))
            .define_method("stack", &QUndoView::stack)
            // Public Slots
            .define_method("set_group", &QUndoView::setGroup, Arg("group"))
            .define_method("set_stack", &QUndoView::setStack, Arg("stack"));
}
