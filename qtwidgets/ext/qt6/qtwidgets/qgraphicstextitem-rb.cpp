#include "qgraphicstextitem-rb.hpp"
#include <qgraphicsitem.h>

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QTextCursor>
#include <QTextDocument>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQGraphicsTextItem;

void Init_qgraphicstextitem(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsTextItem =
        // RubyQt6::QtWidgets::QGraphicsTextItem
        define_class_under<QGraphicsTextItem, QGraphicsObject>(rb_mQt6QtWidgets, "QGraphicsTextItem")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGraphicsTextItem::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGraphicsTextItem, const QString &, QGraphicsItem *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("adjust_size", &QGraphicsTextItem::adjustSize)
            .define_method("bounding_rect", &QGraphicsTextItem::boundingRect)
            .define_method("contains", &QGraphicsTextItem::contains, Arg("point"))
            .define_method("default_text_color", &QGraphicsTextItem::defaultTextColor)
            .define_method("document", &QGraphicsTextItem::document)
            .define_method("font", &QGraphicsTextItem::font)
            .define_method("obscured_by?", &QGraphicsTextItem::isObscuredBy, Arg("item"))
            .define_method("opaque_area", &QGraphicsTextItem::opaqueArea)
            .define_method("open_external_links", &QGraphicsTextItem::openExternalLinks)
            .define_method("paint", &QGraphicsTextItem::paint, Arg("painter"), Arg("option"), Arg("widget"))
            .define_method("set_default_text_color", &QGraphicsTextItem::setDefaultTextColor, Arg("c"))
            .define_method("set_document", &QGraphicsTextItem::setDocument, Arg("document"))
            .define_method("set_font", &QGraphicsTextItem::setFont, Arg("font"))
            .define_method("set_html", &QGraphicsTextItem::setHtml, Arg("html"))
            .define_method("set_open_external_links", &QGraphicsTextItem::setOpenExternalLinks, Arg("open"))
            .define_method("set_plain_text", &QGraphicsTextItem::setPlainText, Arg("text"))
            .define_method("set_tab_changes_focus", &QGraphicsTextItem::setTabChangesFocus, Arg("b"))
            .define_method("set_text_cursor", &QGraphicsTextItem::setTextCursor, Arg("cursor"))
            .define_method("set_text_interaction_flags", &QGraphicsTextItem::setTextInteractionFlags, Arg("flags"))
            .define_method("set_text_width", &QGraphicsTextItem::setTextWidth, Arg("width"))
            .define_method("shape", &QGraphicsTextItem::shape)
            .define_method("tab_changes_focus", &QGraphicsTextItem::tabChangesFocus)
            .define_method("text_cursor", &QGraphicsTextItem::textCursor)
            .define_method("text_interaction_flags", &QGraphicsTextItem::textInteractionFlags)
            .define_method("text_width", &QGraphicsTextItem::textWidth)
            .define_method("to_html", &QGraphicsTextItem::toHtml)
            .define_method("to_plain_text", &QGraphicsTextItem::toPlainText)
            .define_method("type", &QGraphicsTextItem::type);
            // Signals
            // .define_method("link_activated", &QGraphicsTextItem::linkActivated, Arg("link"))
            // .define_method("link_hovered", &QGraphicsTextItem::linkHovered, Arg("link"));
}
