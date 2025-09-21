#include "qbrush-rb.hpp"
#include <qbrush.h>

using namespace Rice;

Rice::Class rb_cQBrush;

void Init_qbrush(Rice::Module rb_mQt6QtGui)
{
    rb_cQBrush =
        // RubyQt6::QtGui::QBrush
        define_class_under<QBrush>(rb_mQt6QtGui, "QBrush")
            // Constructor
            .define_constructor(Constructor<QBrush, Qt::BrushStyle>(), Arg("bs"))
            .define_constructor(Constructor<QBrush, Qt::GlobalColor, Qt::BrushStyle>(), Arg("color"), Arg("bs") = static_cast<Qt::BrushStyle>(Qt::SolidPattern))
            .define_constructor(Constructor<QBrush, const QColor &, Qt::BrushStyle>(), Arg("color"), Arg("bs") = static_cast<Qt::BrushStyle>(Qt::SolidPattern))
            .define_constructor(Constructor<QBrush, Qt::GlobalColor, const QPixmap &>(), Arg("color"), Arg("pixmap"))
            .define_constructor(Constructor<QBrush, const QColor &, const QPixmap &>(), Arg("color"), Arg("pixmap"))
            // .define_constructor(Constructor<QBrush, const QGradient &>(), Arg("gradient"))
            .define_constructor(Constructor<QBrush, const QImage &>(), Arg("image"))
            .define_constructor(Constructor<QBrush, const QPixmap &>(), Arg("pixmap"))
            // Public Functions
            .define_method("color", &QBrush::color)
            .define_method("gradient", &QBrush::gradient)
            .define_method("opaque?", &QBrush::isOpaque)
            .define_method<void (QBrush::*)(const QColor &)>("set_color", &QBrush::setColor, Arg("color"))
            .define_method<void (QBrush::*)(Qt::GlobalColor)>("set_color", &QBrush::setColor, Arg("color"))
            .define_method("set_style", &QBrush::setStyle, Arg("style"))
            .define_method("set_texture", &QBrush::setTexture, Arg("pixmap"))
            .define_method("set_texture_image", &QBrush::setTextureImage, Arg("image"))
            .define_method("set_transform", &QBrush::setTransform, Arg("transform"))
            .define_method("style", &QBrush::style)
            .define_method("texture", &QBrush::texture)
            .define_method("texture_image", &QBrush::textureImage)
            .define_method("transform", &QBrush::transform);
}
