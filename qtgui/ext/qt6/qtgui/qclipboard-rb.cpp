#include "qclipboard-rb.hpp"
#include <qclipboard.h>

#include <QImage>
#include <QPixmap>
#include <QMimeData>

using namespace Rice;

Rice::Class rb_cQClipboard;

void Init_qclipboard(Rice::Module rb_mQt6QtGui)
{
    rb_cQClipboard =
        // RubyQt6::QtGui::QClipboard
        define_class_under<QClipboard, QObject>(rb_mQt6QtGui, "QClipboard")
            // Public Functions
            .define_method("clear", &QClipboard::clear, Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("image", &QClipboard::image, Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("mime_data", &QClipboard::mimeData, Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("owns_clipboard", &QClipboard::ownsClipboard)
            .define_method("owns_find_buffer", &QClipboard::ownsFindBuffer)
            .define_method("owns_selection", &QClipboard::ownsSelection)
            .define_method("pixmap", &QClipboard::pixmap, Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("set_image", &QClipboard::setImage, Arg("image"), Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("set_mime_data", &QClipboard::setMimeData, Arg("data"), Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("set_pixmap", &QClipboard::setPixmap, Arg("pixmap"), Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("set_text", &QClipboard::setText, Arg("text"), Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method("supports_find_buffer", &QClipboard::supportsFindBuffer)
            .define_method("supports_selection", &QClipboard::supportsSelection)
            .define_method<QString (QClipboard::*)(QClipboard::Mode) const>("text", &QClipboard::text, Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            .define_method<QString (QClipboard::*)(QString &, QClipboard::Mode) const>("text", &QClipboard::text, Arg("subtype"), Arg("mode") = static_cast<QClipboard::Mode>(QClipboard::Mode::Clipboard))
            // Signals
            .define_method("changed", &QClipboard::changed, Arg("mode"))
            .define_method("data_changed", &QClipboard::dataChanged)
            .define_method("find_buffer_changed", &QClipboard::findBufferChanged)
            .define_method("selection_changed", &QClipboard::selectionChanged);

    Enum<QClipboard::Mode> rb_cQClipboardMode =
        // RubyQt6::QtGui::QClipboard::Mode
        define_enum_under<QClipboard::Mode>("Mode", rb_cQClipboard)
            .define_value("Clipboard", QClipboard::Mode::Clipboard)
            .define_value("Selection", QClipboard::Mode::Selection)
            .define_value("FindBuffer", QClipboard::Mode::FindBuffer)
            .define_value("LastMode", QClipboard::Mode::LastMode);
}
