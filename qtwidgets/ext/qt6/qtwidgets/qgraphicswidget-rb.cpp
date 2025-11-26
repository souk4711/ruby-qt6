#include "qgraphicswidget-rb.hpp"
#include <qgraphicswidget.h>

#include <QGraphicsLayout>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQGraphicsWidget;

void Init_qgraphicswidget(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsWidget =
        // RubyQt6::QtWidgets::QGraphicsWidget
        define_class_under<QGraphicsWidget, QGraphicsObject>(rb_mQt6QtWidgets, "QGraphicsWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGraphicsWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGraphicsWidget, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("actions", &QGraphicsWidget::actions)
            .define_method("add_action", &QGraphicsWidget::addAction, Arg("action"))
            .define_method("add_actions", &QGraphicsWidget::addActions, Arg("actions"))
            .define_method("adjust_size", &QGraphicsWidget::adjustSize)
            .define_method("auto_fill_background", &QGraphicsWidget::autoFillBackground)
            .define_method("bounding_rect", &QGraphicsWidget::boundingRect)
            .define_method("focus_policy", &QGraphicsWidget::focusPolicy)
            .define_method("focus_widget", &QGraphicsWidget::focusWidget)
            .define_method("font", &QGraphicsWidget::font)
            .define_method("get_contents_margins", &QGraphicsWidget::getContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("get_window_frame_margins", &QGraphicsWidget::getWindowFrameMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("grab_shortcut", &QGraphicsWidget::grabShortcut, Arg("sequence"), Arg("context") = static_cast<Qt::ShortcutContext>(Qt::WindowShortcut))
            .define_method("insert_action", &QGraphicsWidget::insertAction, Arg("before"), Arg("action"))
            .define_method("insert_actions", &QGraphicsWidget::insertActions, Arg("before"), Arg("actions"))
            .define_method("active_window?", &QGraphicsWidget::isActiveWindow)
            .define_method("layout", &QGraphicsWidget::layout)
            .define_method("layout_direction", &QGraphicsWidget::layoutDirection)
            .define_method("paint", &QGraphicsWidget::paint, Arg("painter"), Arg("option"), Arg("widget") = static_cast<QWidget *>(nullptr))
            .define_method("paint_window_frame", &QGraphicsWidget::paintWindowFrame, Arg("painter"), Arg("option"), Arg("widget") = static_cast<QWidget *>(nullptr))
            .define_method("palette", &QGraphicsWidget::palette)
            .define_method("rect", &QGraphicsWidget::rect)
            .define_method("release_shortcut", &QGraphicsWidget::releaseShortcut, Arg("id"))
            .define_method("remove_action", &QGraphicsWidget::removeAction, Arg("action"))
            .define_method<void (QGraphicsWidget::*)(const QSizeF &)>("resize", &QGraphicsWidget::resize, Arg("size"))
            .define_method<void (QGraphicsWidget::*)(qreal, qreal)>("resize", &QGraphicsWidget::resize, Arg("w"), Arg("h"))
            .define_method("set_attribute", &QGraphicsWidget::setAttribute, Arg("attribute"), Arg("on") = static_cast<bool>(true))
            .define_method("set_auto_fill_background", &QGraphicsWidget::setAutoFillBackground, Arg("enabled"))
            .define_method<void (QGraphicsWidget::*)(QMarginsF)>("set_contents_margins", &QGraphicsWidget::setContentsMargins, Arg("margins"))
            .define_method<void (QGraphicsWidget::*)(qreal, qreal, qreal, qreal)>("set_contents_margins", &QGraphicsWidget::setContentsMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("set_focus_policy", &QGraphicsWidget::setFocusPolicy, Arg("policy"))
            .define_method("set_font", &QGraphicsWidget::setFont, Arg("font"))
            .define_method<void (QGraphicsWidget::*)(const QRectF &)>("set_geometry", &QGraphicsWidget::setGeometry, Arg("rect"))
            .define_method<void (QGraphicsWidget::*)(qreal, qreal, qreal, qreal)>("set_geometry", &QGraphicsWidget::setGeometry, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("set_layout", &QGraphicsWidget::setLayout, Arg("layout"))
            .define_method("set_layout_direction", &QGraphicsWidget::setLayoutDirection, Arg("direction"))
            .define_method("set_palette", &QGraphicsWidget::setPalette, Arg("palette"))
            .define_method("set_shortcut_auto_repeat", &QGraphicsWidget::setShortcutAutoRepeat, Arg("id"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_shortcut_enabled", &QGraphicsWidget::setShortcutEnabled, Arg("id"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_style", &QGraphicsWidget::setStyle, Arg("style"))
            .define_method("set_window_flags", &QGraphicsWidget::setWindowFlags, Arg("w_flags"))
            .define_method<void (QGraphicsWidget::*)(QMarginsF)>("set_window_frame_margins", &QGraphicsWidget::setWindowFrameMargins, Arg("margins"))
            .define_method<void (QGraphicsWidget::*)(qreal, qreal, qreal, qreal)>("set_window_frame_margins", &QGraphicsWidget::setWindowFrameMargins, Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_method("set_window_title", &QGraphicsWidget::setWindowTitle, Arg("title"))
            .define_method("shape", &QGraphicsWidget::shape)
            .define_method("size", &QGraphicsWidget::size)
            .define_method("style", &QGraphicsWidget::style)
            .define_method("test_attribute", &QGraphicsWidget::testAttribute, Arg("attribute"))
            .define_method("type", &QGraphicsWidget::type)
            .define_method("unset_layout_direction", &QGraphicsWidget::unsetLayoutDirection)
            .define_method("unset_window_frame_margins", &QGraphicsWidget::unsetWindowFrameMargins)
            .define_method("window_flags", &QGraphicsWidget::windowFlags)
            .define_method("window_frame_geometry", &QGraphicsWidget::windowFrameGeometry)
            .define_method("window_frame_rect", &QGraphicsWidget::windowFrameRect)
            .define_method("window_title", &QGraphicsWidget::windowTitle)
            .define_method("window_type", &QGraphicsWidget::windowType)
            // Public Slots
            .define_method("close", &QGraphicsWidget::close)
            // Signals
            // .define_method("geometry_changed", &QGraphicsWidget::geometryChanged)
            // .define_method("layout_changed", &QGraphicsWidget::layoutChanged)
            // Static Public Members
            .define_singleton_function("set_tab_order", &QGraphicsWidget::setTabOrder, Arg("first"), Arg("second"));
}
