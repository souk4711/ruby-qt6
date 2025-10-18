#include "qtextobject-rb.hpp"
#include <qtextobject.h>

using namespace Rice;

Rice::Class rb_cQTextObject;
Rice::Class rb_cQTextBlockGroup;
Rice::Class rb_cQTextFrame;

void Init_qtextobject(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextObject =
        // RubyQt6::QtGui::QTextObject
        define_class_under<QTextObject, QObject>(rb_mQt6QtGui, "QTextObject")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextObject::staticMetaObject; })
            // Public Functions
            .define_method("document", &QTextObject::document)
            .define_method("format", &QTextObject::format)
            .define_method("format_index", &QTextObject::formatIndex)
            .define_method("object_index", &QTextObject::objectIndex);

    rb_cQTextBlockGroup =
        // RubyQt6::QtGui::QTextBlockGroup
        define_class_under<QTextBlockGroup, QTextObject>(rb_mQt6QtGui, "QTextBlockGroup")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextBlockGroup::staticMetaObject; });

    rb_cQTextFrame =
        // RubyQt6::QtGui::QTextFrame
        define_class_under<QTextFrame, QTextObject>(rb_mQt6QtGui, "QTextFrame")
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
