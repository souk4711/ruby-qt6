#include "qlabel-rb.hpp"
#include <qlabel.h>

#include <QMovie>

using namespace Rice;

Rice::Class rb_cQLabel;

void Init_qlabel(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLabel =
        // RubyQt6::QtWidgets::QLabel
        define_class_under<QLabel, QFrame>(rb_mQt6QtWidgets, "QLabel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QLabel::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QLabel, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("alignment", &QLabel::alignment)
            .define_method("buddy", &QLabel::buddy)
            .define_method("has_scaled_contents", &QLabel::hasScaledContents)
            .define_method("has_selected_text", &QLabel::hasSelectedText)
            .define_method("height_for_width", &QLabel::heightForWidth, Arg("w"))
            .define_method("indent", &QLabel::indent)
            .define_method("margin", &QLabel::margin)
            .define_method("minimum_size_hint", &QLabel::minimumSizeHint)
            .define_method("movie", &QLabel::movie)
            .define_method("open_external_links", &QLabel::openExternalLinks)
            .define_method<QPicture (QLabel::*)() const>("picture", &QLabel::picture)
            .define_method<QPixmap (QLabel::*)() const>("pixmap", &QLabel::pixmap)
            .define_method("resource_provider", &QLabel::resourceProvider)
            .define_method("selected_text", &QLabel::selectedText)
            .define_method("selection_start", &QLabel::selectionStart)
            .define_method("set_alignment", &QLabel::setAlignment, Arg("alignment"))
            .define_method("set_buddy", &QLabel::setBuddy, Arg("buddy"))
            .define_method("set_indent", &QLabel::setIndent, Arg("indent"))
            .define_method("set_margin", &QLabel::setMargin, Arg("margin"))
            .define_method("set_open_external_links", &QLabel::setOpenExternalLinks, Arg("open"))
            .define_method("set_resource_provider", &QLabel::setResourceProvider, Arg("provider"))
            .define_method("set_scaled_contents", &QLabel::setScaledContents, Arg("enabled"))
            .define_method("set_selection", &QLabel::setSelection, Arg("start"), Arg("length"))
            .define_method("set_text_format", &QLabel::setTextFormat, Arg("format"))
            .define_method("set_text_interaction_flags", &QLabel::setTextInteractionFlags, Arg("flags"))
            .define_method("set_word_wrap", &QLabel::setWordWrap, Arg("on"))
            .define_method("size_hint", &QLabel::sizeHint)
            .define_method("text", &QLabel::text)
            .define_method("text_format", &QLabel::textFormat)
            .define_method("text_interaction_flags", &QLabel::textInteractionFlags)
            .define_method("word_wrap", &QLabel::wordWrap)
            // Public Slots
            .define_method("clear", &QLabel::clear)
            .define_method("set_movie", &QLabel::setMovie, Arg("movie"))
            .define_method<void (QLabel::*)(int)>("set_num", &QLabel::setNum, Arg("num"))
            .define_method<void (QLabel::*)(double)>("set_num", &QLabel::setNum, Arg("num"))
            .define_method("set_picture", &QLabel::setPicture, Arg("picture"))
            .define_method("set_pixmap", &QLabel::setPixmap, Arg("pixmap"))
            .define_method("_set_text", &QLabel::setText, Arg("text"))
            // Signals
            .define_method("link_activated", &QLabel::linkActivated, Arg("link"))
            .define_method("link_hovered", &QLabel::linkHovered, Arg("link"));
}
