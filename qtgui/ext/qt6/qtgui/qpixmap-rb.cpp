#include "qpixmap-rb.hpp"
#include <qpixmap.h>

#include <QBitmap>
#include <QImageReader>
#include <QIODevice>
#include <QPaintEngine>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPixmap;

void Init_qpixmap(Module rb_mQt6QtGui)
{
    rb_cQPixmap =
        // RubyQt6::QtGui::QPixmap
        define_qlass_under<QPixmap, QPaintDevice>(rb_mQt6QtGui, "QPixmap")
            // Constructor
            .define_constructor(Constructor<QPixmap>())
            .define_constructor(Constructor<QPixmap, int, int>(), Arg("w"), Arg("h"))
            .define_constructor(Constructor<QPixmap, const QSize &>(), Arg("size"))
            .define_constructor(Constructor<QPixmap, const QString &>(), Arg("file_name"))
            .define_constructor(Constructor<QPixmap, const QPixmap &>(), Arg("other"))
            // Public Functions
            .define_method("cache_key", &QPixmap::cacheKey)
            .define_method("convert_from_image", &QPixmap::convertFromImage, Arg("img"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method<QPixmap (QPixmap::*)(const QRect &) const>("copy", &QPixmap::copy, Arg("rect") = static_cast<const QRect &>(QRect()))
            .define_method<QPixmap (QPixmap::*)(int, int, int, int) const>("copy", &QPixmap::copy, Arg("x"), Arg("y"), Arg("width"), Arg("height"))
            .define_method("create_heuristic_mask", &QPixmap::createHeuristicMask, Arg("clip_tight") = static_cast<bool>(true))
            .define_method("create_mask_from_color", &QPixmap::createMaskFromColor, Arg("mask_color"), Arg("mode") = static_cast<Qt::MaskMode>(Qt::MaskInColor))
            .define_method("depth", &QPixmap::depth)
            .define_method("detach", &QPixmap::detach)
            .define_method("dev_type", &QPixmap::devType)
            .define_method("device_independent_size", &QPixmap::deviceIndependentSize)
            .define_method("device_pixel_ratio", &QPixmap::devicePixelRatio)
            .define_method("fill", &QPixmap::fill, Arg("fill_color") = static_cast<const QColor &>(Qt::white))
            .define_method("has_alpha", &QPixmap::hasAlpha)
            .define_method("has_alpha_channel", &QPixmap::hasAlphaChannel)
            .define_method("height", &QPixmap::height)
            .define_method("detached?", &QPixmap::isDetached)
            .define_method("null?", &QPixmap::isNull)
            .define_method("qbitmap?", &QPixmap::isQBitmap)
            .define_method("_load", &QPixmap::load, Arg("file_name"), Arg("format") = static_cast<const char *>(nullptr), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<bool (QPixmap::*)(const QByteArray &, const char *, Qt::ImageConversionFlags)>("load_from_data", &QPixmap::loadFromData, Arg("data"), Arg("format") = static_cast<const char *>(nullptr), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<bool (QPixmap::*)(const uchar *, ::uint, const char *, Qt::ImageConversionFlags)>("load_from_data", &QPixmap::loadFromData, Arg("buf"), Arg("len"), Arg("format") = static_cast<const char *>(nullptr), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method("mask", &QPixmap::mask)
            .define_method("rect", &QPixmap::rect)
            .define_method<bool (QPixmap::*)(QIODevice *, const char *, int) const>("save", &QPixmap::save, Arg("device"), Arg("format") = static_cast<const char *>(nullptr), Arg("quality") = static_cast<int>(-1))
            .define_method<bool (QPixmap::*)(const QString &, const char *, int) const>("save", &QPixmap::save, Arg("file_name"), Arg("format") = static_cast<const char *>(nullptr), Arg("quality") = static_cast<int>(-1))
            .define_method<QPixmap (QPixmap::*)(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const>("scaled", &QPixmap::scaled, Arg("s"), Arg("aspect_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method<QPixmap (QPixmap::*)(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const>("scaled", &QPixmap::scaled, Arg("w"), Arg("h"), Arg("aspect_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method("scaled_to_height", &QPixmap::scaledToHeight, Arg("h"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method("scaled_to_width", &QPixmap::scaledToWidth, Arg("w"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method<void (QPixmap::*)(int, int, const QRect &, QRegion *)>("scroll", &QPixmap::scroll, Arg("dx"), Arg("dy"), Arg("rect"), Arg("exposed") = static_cast<QRegion *>(nullptr))
            .define_method<void (QPixmap::*)(int, int, int, int, int, int, QRegion *)>("scroll", &QPixmap::scroll, Arg("dx"), Arg("dy"), Arg("x"), Arg("y"), Arg("width"), Arg("height"), Arg("exposed") = static_cast<QRegion *>(nullptr))
            .define_method("set_device_pixel_ratio", &QPixmap::setDevicePixelRatio, Arg("scale_factor"))
            .define_method("set_mask", &QPixmap::setMask, Arg("mask"))
            .define_method("size", &QPixmap::size)
            .define_method("to_image", &QPixmap::toImage)
            .define_method("transformed", &QPixmap::transformed, Arg("transform"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method("width", &QPixmap::width)
            // Static Public Members
            .define_singleton_function("default_depth", &QPixmap::defaultDepth)
            .define_singleton_function<QPixmap (*)(QImage &&, Qt::ImageConversionFlags)>("from_image", &QPixmap::fromImage, Arg("image"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_singleton_function("from_image_reader", &QPixmap::fromImageReader, Arg("image_reader"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_singleton_function("true_matrix", &QPixmap::trueMatrix, Arg("m"), Arg("w"), Arg("h"));
}
