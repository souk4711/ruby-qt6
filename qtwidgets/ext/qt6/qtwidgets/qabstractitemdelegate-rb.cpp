#include "qabstractitemdelegate-rb.hpp"
#include <qabstractitemdelegate.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQAbstractItemDelegate;

void Init_qabstractitemdelegate(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractItemDelegate =
        // RubyQt6::QtWidgets::QAbstractItemDelegate
        define_class_under<QAbstractItemDelegate, QObject>(rb_mQt6QtWidgets, "QAbstractItemDelegate")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractItemDelegate::staticMetaObject; })
            // Signals
            .define_method("close_editor", &QAbstractItemDelegate::closeEditor, Arg("editor"), Arg("hint") = static_cast<QAbstractItemDelegate::EndEditHint>(QAbstractItemDelegate::EndEditHint::NoHint))
            .define_method("commit_data", &QAbstractItemDelegate::commitData, Arg("editor"))
            .define_method("size_hint_changed", &QAbstractItemDelegate::sizeHintChanged, Arg("index"));

   Enum<QAbstractItemDelegate::EndEditHint> rb_cQAbstractItemDelegateEndEditHint =
        // RubyQt6::QtWidgets::QAbstractItemDelegate::EndEditHint
        define_qenum_under<QAbstractItemDelegate::EndEditHint>("EndEditHint", rb_cQAbstractItemDelegate)
            .define_value("NoHint", QAbstractItemDelegate::EndEditHint::NoHint)
            .define_value("EditNextItem", QAbstractItemDelegate::EndEditHint::EditNextItem)
            .define_value("EditPreviousItem", QAbstractItemDelegate::EndEditHint::EditPreviousItem)
            .define_value("SubmitModelCache", QAbstractItemDelegate::EndEditHint::SubmitModelCache)
            .define_value("RevertModelCache", QAbstractItemDelegate::EndEditHint::RevertModelCache);
}
