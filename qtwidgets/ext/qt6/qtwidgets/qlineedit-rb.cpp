#include "qlineedit-rb.hpp"
#include <qlineedit.h>

#include <QCompleter>
#include <QEvent>
#include <QMenu>
#include <QValidator>

using namespace Rice;

Rice::Class rb_cQLineEdit;

void Init_qlineedit(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLineEdit =
        // RubyQt6::QtWidgets::QLineEdit
        define_class_under<QLineEdit, QWidget>(rb_mQt6QtWidgets, "QLineEdit")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QLineEdit::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QLineEdit, const QString &, QWidget *>(), Arg("contents"), Arg("parent"))
            // Public Functions
            .define_method<QAction *(QLineEdit::*)(const QIcon &, QLineEdit::ActionPosition)>("add_action", &QLineEdit::addAction, Arg("icon"), Arg("position"))
            .define_method<void (QLineEdit::*)(QAction *, QLineEdit::ActionPosition)>("add_action", &QLineEdit::addAction, Arg("action"), Arg("position"))
            .define_method("alignment", &QLineEdit::alignment)
            .define_method("backspace", &QLineEdit::backspace)
            .define_method("completer", &QLineEdit::completer)
            .define_method("create_standard_context_menu", &QLineEdit::createStandardContextMenu)
            .define_method("cursor_backward", &QLineEdit::cursorBackward, Arg("mark"), Arg("steps") = static_cast<int>(1))
            .define_method("cursor_forward", &QLineEdit::cursorForward, Arg("mark"), Arg("steps") = static_cast<int>(1))
            .define_method("cursor_move_style", &QLineEdit::cursorMoveStyle)
            .define_method("cursor_position", &QLineEdit::cursorPosition)
            .define_method("cursor_position_at", &QLineEdit::cursorPositionAt, Arg("pos"))
            .define_method("cursor_word_backward", &QLineEdit::cursorWordBackward, Arg("mark"))
            .define_method("cursor_word_forward", &QLineEdit::cursorWordForward, Arg("mark"))
            .define_method("del", &QLineEdit::del)
            .define_method("deselect", &QLineEdit::deselect)
            .define_method("display_text", &QLineEdit::displayText)
            .define_method("drag_enabled", &QLineEdit::dragEnabled)
            .define_method("echo_mode", &QLineEdit::echoMode)
            .define_method("event", &QLineEdit::event, Arg("e"))
            .define_method("has_acceptable_input", &QLineEdit::hasAcceptableInput)
            .define_method("has_frame", &QLineEdit::hasFrame)
            .define_method("has_selected_text", &QLineEdit::hasSelectedText)
            .define_method("home", &QLineEdit::home, Arg("mark"))
            .define_method("input_mask", &QLineEdit::inputMask)
            .define_method<QVariant (QLineEdit::*)(Qt::InputMethodQuery) const>("input_method_query", &QLineEdit::inputMethodQuery, Arg("property"))
            .define_method<QVariant (QLineEdit::*)(Qt::InputMethodQuery, QVariant) const>("input_method_query", &QLineEdit::inputMethodQuery, Arg("property"), Arg("argument"))
            .define_method("insert", &QLineEdit::insert, Arg("new_text"))
            .define_method("clear_button_enabled?", &QLineEdit::isClearButtonEnabled)
            .define_method("modified?", &QLineEdit::isModified)
            .define_method("read_only?", &QLineEdit::isReadOnly)
            .define_method("redo_available?", &QLineEdit::isRedoAvailable)
            .define_method("undo_available?", &QLineEdit::isUndoAvailable)
            .define_method("max_length", &QLineEdit::maxLength)
            .define_method("minimum_size_hint", &QLineEdit::minimumSizeHint)
            .define_method("placeholder_text", &QLineEdit::placeholderText)
            .define_method("selection_end", &QLineEdit::selectionEnd)
            .define_method("selection_length", &QLineEdit::selectionLength)
            .define_method("selection_start", &QLineEdit::selectionStart)
            .define_method("set_alignment", &QLineEdit::setAlignment, Arg("flag"))
            .define_method("set_clear_button_enabled", &QLineEdit::setClearButtonEnabled, Arg("enable"))
            .define_method("set_completer", &QLineEdit::setCompleter, Arg("completer"))
            .define_method("set_cursor_move_style", &QLineEdit::setCursorMoveStyle, Arg("style"))
            .define_method("set_cursor_position", &QLineEdit::setCursorPosition, Arg("position"))
            .define_method("set_drag_enabled", &QLineEdit::setDragEnabled, Arg("b"))
            .define_method("set_echo_mode", &QLineEdit::setEchoMode, Arg("mode"))
            .define_method("set_frame", &QLineEdit::setFrame, Arg("enable"))
            .define_method("set_input_mask", &QLineEdit::setInputMask, Arg("input_mask"))
            .define_method("set_max_length", &QLineEdit::setMaxLength, Arg("length"))
            .define_method("set_modified", &QLineEdit::setModified, Arg("modified"))
            .define_method("set_placeholder_text", &QLineEdit::setPlaceholderText, Arg("placeholder"))
            .define_method("set_read_only", &QLineEdit::setReadOnly, Arg("enable"))
            .define_method("set_selection", &QLineEdit::setSelection, Arg("start"), Arg("length"))
            .define_method("set_text", &QLineEdit::setText, Arg("text"))
            .define_method<void (QLineEdit::*)(const QMargins &)>("set_text_margins", &QLineEdit::setTextMargins, Arg("margins"))
            .define_method<void (QLineEdit::*)(int, int, int, int)>("set_text_margins", &QLineEdit::setTextMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("set_validator", &QLineEdit::setValidator, Arg("validator"))
            .define_method("size_hint", &QLineEdit::sizeHint)
            .define_method("text", &QLineEdit::text)
            .define_method("text_margins", &QLineEdit::textMargins)
            .define_method("timer_event", &QLineEdit::timerEvent, Arg("e"))
            .define_method("validator", &QLineEdit::validator)
            // Public Slots
            .define_method("clear", &QLineEdit::clear)
            .define_method("copy", &QLineEdit::copy)
            .define_method("cut", &QLineEdit::cut)
            .define_method("paste", &QLineEdit::paste)
            .define_method("redo", &QLineEdit::redo)
            .define_method("select_all", &QLineEdit::selectAll)
            .define_method("selected_text", &QLineEdit::selectedText)
            .define_method("undo", &QLineEdit::undo)
            // Signals
            .define_method("cursor_position_changed", &QLineEdit::cursorPositionChanged, Arg("old"), Arg("new"))
            .define_method("editing_finished", &QLineEdit::editingFinished)
            .define_method("input_rejected", &QLineEdit::inputRejected)
            .define_method("return_pressed", &QLineEdit::returnPressed)
            .define_method("text_changed", &QLineEdit::textChanged, Arg("text"))
            .define_method("text_edited", &QLineEdit::textEdited, Arg("text"));

    Enum<QLineEdit::ActionPosition> rb_cQLineEditActionPosition =
        // RubyQt6::QtWidgets::QLineEdit::ActionPosition
        define_enum_under<QLineEdit::ActionPosition>("ActionPosition", rb_cQLineEdit)
            .define_value("LeadingPosition", QLineEdit::ActionPosition::LeadingPosition)
            .define_value("TrailingPosition", QLineEdit::ActionPosition::TrailingPosition);

    Enum<QLineEdit::EchoMode> rb_cQLineEditEchoMode =
        // RubyQt6::QtWidgets::QLineEdit::EchoMode
        define_enum_under<QLineEdit::EchoMode>("EchoMode", rb_cQLineEdit)
            .define_value("Normal", QLineEdit::EchoMode::Normal)
            .define_value("NoEcho", QLineEdit::EchoMode::NoEcho)
            .define_value("Password", QLineEdit::EchoMode::Password)
            .define_value("PasswordEchoOnEdit", QLineEdit::EchoMode::PasswordEchoOnEdit);
}
