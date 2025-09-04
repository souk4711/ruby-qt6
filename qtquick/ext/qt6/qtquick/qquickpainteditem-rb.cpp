#include "qquickpainteditem-rb.hpp"
#include <qquickpainteditem.h>

#include <QPainter>

using namespace Rice;

Rice::Class rb_cQQuickPaintedItem;

void Init_qquickpainteditem(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickPaintedItem =
        // RubyQt6::QtQuick::QQuickPaintedItem
        define_class_under<QQuickPaintedItem, QQuickItem>(rb_mQt6QtQuick, "QQuickPaintedItem")
            // Public Functions
            .define_method("antialiasing", &QQuickPaintedItem::antialiasing)
            .define_method("contents_bounding_rect", &QQuickPaintedItem::contentsBoundingRect)
            .define_method("fill_color", &QQuickPaintedItem::fillColor)
            .define_method("mipmap", &QQuickPaintedItem::mipmap)
            .define_method("opaque_painting", &QQuickPaintedItem::opaquePainting)
            .define_method("paint", &QQuickPaintedItem::paint, Arg("painter"))
            .define_method("performance_hints", &QQuickPaintedItem::performanceHints)
            .define_method("render_target", &QQuickPaintedItem::renderTarget)
            .define_method("set_antialiasing", &QQuickPaintedItem::setAntialiasing, Arg("enable"))
            .define_method("set_fill_color", &QQuickPaintedItem::setFillColor, Arg(""))
            .define_method("set_mipmap", &QQuickPaintedItem::setMipmap, Arg("enable"))
            .define_method("set_opaque_painting", &QQuickPaintedItem::setOpaquePainting, Arg("opaque"))
            .define_method("set_performance_hint", &QQuickPaintedItem::setPerformanceHint, Arg("hint"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_performance_hints", &QQuickPaintedItem::setPerformanceHints, Arg("hints"))
            .define_method("set_render_target", &QQuickPaintedItem::setRenderTarget, Arg("target"))
            .define_method("set_texture_size", &QQuickPaintedItem::setTextureSize, Arg("size"))
            .define_method("texture_size", &QQuickPaintedItem::textureSize)
            .define_method("update", &QQuickPaintedItem::update, Arg("rect") = static_cast<const QRect &>(QRect()))
            // Signals
            .define_method("fill_color_changed", &QQuickPaintedItem::fillColorChanged)
            .define_method("render_target_changed", &QQuickPaintedItem::renderTargetChanged)
            .define_method("texture_size_changed", &QQuickPaintedItem::textureSizeChanged);
}
