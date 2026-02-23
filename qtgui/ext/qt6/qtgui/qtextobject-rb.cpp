#include "qtextobject-rb.hpp"
#include <qtextobject.h>

#include <QTextList>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextBlock;
Class rb_cQTextObject;
Class rb_cQTextBlockGroup;
Class rb_cQTextFrame;

void Init_qtextobject(Module rb_mQt6QtGui)
{
    rb_cQTextBlock =
        // RubyQt6::QtGui::QTextBlock
        define_qlass_under<QTextBlock>(rb_mQt6QtGui, "QTextBlock")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QTextBlock *lhs, QTextBlock *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QTextBlock>())
            // Public Functions
            .define_method("block_format", &QTextBlock::blockFormat)
            .define_method("block_format_index", &QTextBlock::blockFormatIndex)
            .define_method("block_number", &QTextBlock::blockNumber)
            .define_method("char_format", &QTextBlock::charFormat)
            .define_method("char_format_index", &QTextBlock::charFormatIndex)
            .define_method("clear_layout", &QTextBlock::clearLayout)
            .define_method("contains", &QTextBlock::contains, Arg("position"))
            .define_method("document", &QTextBlock::document)
            .define_method("first_line_number", &QTextBlock::firstLineNumber)
            .define_method("fragment_index", &QTextBlock::fragmentIndex)
            .define_method("valid?", &QTextBlock::isValid)
            .define_method("visible?", &QTextBlock::isVisible)
            .define_method("layout", &QTextBlock::layout)
            .define_method("length", &QTextBlock::length)
            .define_method("line_count", &QTextBlock::lineCount)
            .define_method("next", &QTextBlock::next)
            .define_method("position", &QTextBlock::position)
            .define_method("previous", &QTextBlock::previous)
            .define_method("revision", &QTextBlock::revision)
            .define_method("set_line_count", &QTextBlock::setLineCount, Arg("count"))
            .define_method("set_revision", &QTextBlock::setRevision, Arg("rev"))
            .define_method("set_user_data", &QTextBlock::setUserData, Arg("data"))
            .define_method("set_user_state", &QTextBlock::setUserState, Arg("state"))
            .define_method("set_visible", &QTextBlock::setVisible, Arg("visible"))
            .define_method("text", &QTextBlock::text)
            .define_method("text_direction", &QTextBlock::textDirection)
            .define_method("text_formats", &QTextBlock::textFormats)
            .define_method("text_list", &QTextBlock::textList)
            .define_method("user_data", &QTextBlock::userData)
            .define_method("user_state", &QTextBlock::userState);

    rb_cQTextObject =
        // RubyQt6::QtGui::QTextObject
        define_qlass_under<QTextObject, QObject>(rb_mQt6QtGui, "QTextObject")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextObject::staticMetaObject; })
            // Public Functions
            .define_method("document", &QTextObject::document)
            .define_method("format", &QTextObject::format)
            .define_method("format_index", &QTextObject::formatIndex)
            .define_method("object_index", &QTextObject::objectIndex);

    rb_cQTextBlockGroup =
        // RubyQt6::QtGui::QTextBlockGroup
        define_qlass_under<QTextBlockGroup, QTextObject>(rb_mQt6QtGui, "QTextBlockGroup")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextBlockGroup::staticMetaObject; });

    rb_cQTextFrame =
        // RubyQt6::QtGui::QTextFrame
        define_qlass_under<QTextFrame, QTextObject>(rb_mQt6QtGui, "QTextFrame")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextFrame::staticMetaObject; })
            // Public Functions
            .define_method("child_frames", &QTextFrame::childFrames)
            .define_method("first_cursor_position", &QTextFrame::firstCursorPosition)
            .define_method("first_position", &QTextFrame::firstPosition)
            .define_method("frame_format", &QTextFrame::frameFormat)
            .define_method("last_cursor_position", &QTextFrame::lastCursorPosition)
            .define_method("last_position", &QTextFrame::lastPosition)
            .define_method("layout_data", &QTextFrame::layoutData)
            .define_method("parent_frame", &QTextFrame::parentFrame)
            .define_method("set_frame_format", &QTextFrame::setFrameFormat, Arg("format"));
}
