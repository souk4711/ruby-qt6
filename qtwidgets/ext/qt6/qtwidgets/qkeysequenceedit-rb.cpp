#include "qkeysequenceedit-rb.hpp"
#include <qkeysequenceedit.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQKeySequenceEdit;

void Init_qkeysequenceedit(Module rb_mQt6QtWidgets)
{
    rb_cQKeySequenceEdit =
        // RubyQt6::QtWidgets::QKeySequenceEdit
        define_qlass_under<QKeySequenceEdit, QWidget>(rb_mQt6QtWidgets, "QKeySequenceEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QKeySequenceEdit * { return qobject_cast<QKeySequenceEdit *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QKeySequenceEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QKeySequenceEdit, const QKeySequence &, QWidget *>(), Arg("key"), Arg("parent"))
            // Public Functions
            .define_method("finishing_key_combinations", &QKeySequenceEdit::finishingKeyCombinations)
            .define_method("clear_button_enabled?", &QKeySequenceEdit::isClearButtonEnabled)
            .define_method("key_sequence", &QKeySequenceEdit::keySequence)
            .define_method("maximum_sequence_length", &QKeySequenceEdit::maximumSequenceLength)
            .define_method("set_clear_button_enabled", &QKeySequenceEdit::setClearButtonEnabled, Arg("enable"))
            .define_method("set_finishing_key_combinations", &QKeySequenceEdit::setFinishingKeyCombinations, Arg("finishing_key_combinations"))
            // Public Slots
            .define_method("clear", &QKeySequenceEdit::clear)
            .define_method("set_key_sequence", &QKeySequenceEdit::setKeySequence, Arg("key_sequence"))
            .define_method("set_maximum_sequence_length", &QKeySequenceEdit::setMaximumSequenceLength, Arg("count"));
            // Signals
            // .define_method("editing_finished", &QKeySequenceEdit::editingFinished)
            // .define_method("key_sequence_changed", &QKeySequenceEdit::keySequenceChanged, Arg("key_sequence"));
}
