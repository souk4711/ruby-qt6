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
            .define_constructor(Constructor<QLabel, const QString &, QWidget *, Qt::WindowFlags>(), Arg("text"), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("f") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_method("_alignment", &QLabel::alignment)
            .define_method("_buddy", &QLabel::buddy)
            .define_method("_indent", &QLabel::indent)
            .define_method("_margin", &QLabel::margin)
            .define_method("_movie", &QLabel::movie)
            .define_method<QPicture (QLabel::*)() const>("_picture", &QLabel::picture)
            .define_method<QPixmap (QLabel::*)() const>("_pixmap", &QLabel::pixmap)
            .define_method("_resource_provider", &QLabel::resourceProvider)
            .define_method("_selected_text", &QLabel::selectedText)
            .define_method("_selection_start", &QLabel::selectionStart)
            .define_method("_text", &QLabel::text)
            .define_method("_text_format", &QLabel::textFormat)
            .define_method("_text_interaction_flags", &QLabel::textInteractionFlags)
            .define_method("_has_selected_text?", &QLabel::hasSelectedText)
            .define_method("_has_scaled_contents?", &QLabel::hasScaledContents)
            .define_method("_open_external_links?", &QLabel::openExternalLinks)
            .define_method("_word_wrap?", &QLabel::wordWrap)
            .define_method("_set_alignment", &QLabel::setAlignment, Arg("alignment"))
            .define_method("_set_buddy", &QLabel::setBuddy, Arg("buddy"))
            .define_method("_set_indent", &QLabel::setIndent, Arg("indent"))
            .define_method("_set_margin", &QLabel::setMargin, Arg("margin"))
            .define_method("_set_open_external_links", &QLabel::setOpenExternalLinks, Arg("open"))
            .define_method("_set_movie", &QLabel::setMovie, Arg("movie"))
            .define_method<void (QLabel::*)(int)>("_set_num", &QLabel::setNum, Arg("num"))
            .define_method<void (QLabel::*)(double)>("_set_num", &QLabel::setNum, Arg("num"))
            .define_method("_set_picture", &QLabel::setPicture, Arg("picture"))
            .define_method("_set_pixmap", &QLabel::setPixmap, Arg("pixmap"))
            .define_method("_set_resource_provider", &QLabel::setResourceProvider, Arg("provider"))
            .define_method("_set_scaled_contents", &QLabel::setScaledContents, Arg("enabled"))
            .define_method("_set_selection", &QLabel::setSelection, Arg("start"), Arg("length"))
            .define_method("_set_text", &QLabel::setText, Arg("text"))
            .define_method("_set_text_format", &QLabel::setTextFormat, Arg("format"))
            .define_method("_set_text_interaction_flags", &QLabel::setTextInteractionFlags, Arg("flags"))
            .define_method("_set_word_wrap", &QLabel::setWordWrap, Arg("enabled"))
            .define_method("_clear", &QLabel::clear);
}
