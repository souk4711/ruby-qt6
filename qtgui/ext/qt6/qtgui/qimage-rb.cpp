#include "qimage-rb.hpp"
#include <qimage.h>
#include <rice/qt6/qenum.hpp>

#include <QColorTransform>
#include <QColorSpace>
#include <QIODevice>
#include <QPaintEngine>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQImage;

void Init_qimage(Module rb_mQt6QtGui)
{
    rb_cQImage =
        // RubyQt6::QtGui::QImage
        define_qlass_under<QImage, QPaintDevice>(rb_mQt6QtGui, "QImage")
            // Constructor
            .define_constructor(Constructor<QImage>())
            .define_constructor(Constructor<QImage, const QString &>(), Arg("file_name"))
            .define_constructor(Constructor<QImage, const QSize &, QImage::Format>(), Arg("size"), Arg("format"))
            // Public Functions
            .define_method("all_gray", &QImage::allGray)
            .define_method<void (QImage::*)(const QColorTransform &)>("apply_color_transform", &QImage::applyColorTransform, Arg("transform"))
            .define_method<void (QImage::*)(const QColorTransform &, QImage::Format, Qt::ImageConversionFlags)>("apply_color_transform", &QImage::applyColorTransform, Arg("transform"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method("bit_plane_count", &QImage::bitPlaneCount)
            .define_method<const uchar *(QImage::*)() const>("bits", &QImage::bits)
            .define_method<uchar *(QImage::*)()>("bits", &QImage::bits)
            .define_method("bytes_per_line", &QImage::bytesPerLine)
            .define_method("cache_key", &QImage::cacheKey)
            .define_method("color", &QImage::color, Arg("i"))
            .define_method("color_count", &QImage::colorCount)
            .define_method("color_space", &QImage::colorSpace)
            .define_method("color_table", &QImage::colorTable)
            // .define_method<QImage (QImage::*)(const QColorTransform &) const>("color_transformed", &QImage::colorTransformed, Arg("transform"))
            // .define_method<QImage (QImage::*)(const QColorTransform &)>("color_transformed", &QImage::colorTransformed, Arg("transform"))
            // .define_method<QImage (QImage::*)(const QColorTransform &, QImage::Format, Qt::ImageConversionFlags) const>("color_transformed", &QImage::colorTransformed, Arg("transform"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(const QColorTransform &, QImage::Format, Qt::ImageConversionFlags)>("color_transformed", &QImage::colorTransformed, Arg("transform"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method("const_bits", &QImage::constBits)
            .define_method("const_scan_line", &QImage::constScanLine, Arg("i"))
            .define_method("convert_to", &QImage::convertTo, Arg("f"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method<void (QImage::*)(const QColorSpace &)>("convert_to_color_space", &QImage::convertToColorSpace, Arg("color_space"))
            .define_method<void (QImage::*)(const QColorSpace &, QImage::Format, Qt::ImageConversionFlags)>("convert_to_color_space", &QImage::convertToColorSpace, Arg("color_space"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(QImage::Format, Qt::ImageConversionFlags) const>("convert_to_format", &QImage::convertToFormat, Arg("f"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(QImage::Format, Qt::ImageConversionFlags)>("convert_to_format", &QImage::convertToFormat, Arg("f"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(QImage::Format, const QList &, Qt::ImageConversionFlags) const>("convert_to_format", &QImage::convertToFormat, Arg("f"), Arg("color_table"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(QImage::Format, Qt::ImageConversionFlags) const>("converted_to", &QImage::convertedTo, Arg("f"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(QImage::Format, Qt::ImageConversionFlags)>("converted_to", &QImage::convertedTo, Arg("f"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(const QColorSpace &) const>("converted_to_color_space", &QImage::convertedToColorSpace, Arg("color_space"))
            // .define_method<QImage (QImage::*)(const QColorSpace &, QImage::Format, Qt::ImageConversionFlags) const>("converted_to_color_space", &QImage::convertedToColorSpace, Arg("color_space"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            // .define_method<QImage (QImage::*)(const QColorSpace &, QImage::Format, Qt::ImageConversionFlags)>("converted_to_color_space", &QImage::convertedToColorSpace, Arg("color_space"), Arg("format"), Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method<QImage (QImage::*)(const QRect &) const>("copy", &QImage::copy, Arg("rect") = static_cast<const QRect &>(QRect()))
            .define_method<QImage (QImage::*)(int, int, int, int) const>("copy", &QImage::copy, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("create_alpha_mask", &QImage::createAlphaMask, Arg("flags") = static_cast<Qt::ImageConversionFlags>(Qt::AutoColor))
            .define_method("create_heuristic_mask", &QImage::createHeuristicMask, Arg("clip_tight") = static_cast<bool>(true))
            .define_method("create_mask_from_color", &QImage::createMaskFromColor, Arg("color"), Arg("mode") = static_cast<Qt::MaskMode>(Qt::MaskInColor))
            .define_method("depth", &QImage::depth)
            .define_method("detach", &QImage::detach)
            .define_method("dev_type", &QImage::devType)
            .define_method("device_independent_size", &QImage::deviceIndependentSize)
            .define_method("device_pixel_ratio", &QImage::devicePixelRatio)
            .define_method("dots_per_meter_x", &QImage::dotsPerMeterX)
            .define_method("dots_per_meter_y", &QImage::dotsPerMeterY)
            .define_method<void (QImage::*)(uint)>("fill", &QImage::fill, Arg("pixel"))
            .define_method<void (QImage::*)(Qt::GlobalColor)>("fill", &QImage::fill, Arg("color"))
            .define_method<void (QImage::*)(const QColor &)>("fill", &QImage::fill, Arg("color"))
            .define_method("flip", &QImage::flip, Arg("orient") = static_cast<Qt::Orientations>(Qt::Vertical))
            // .define_method<QImage (QImage::*)(Qt::Orientations) const>("flipped", &QImage::flipped, Arg("orient") = static_cast<Qt::Orientations>(Qt::Vertical))
            // .define_method<QImage (QImage::*)(Qt::Orientations)>("flipped", &QImage::flipped, Arg("orient") = static_cast<Qt::Orientations>(Qt::Vertical))
            .define_method("format", &QImage::format)
            .define_method("has_alpha_channel", &QImage::hasAlphaChannel)
            .define_method("height", &QImage::height)
            .define_method("invert_pixels", &QImage::invertPixels, Arg("mode") = static_cast<QImage::InvertMode>(QImage::InvertMode::InvertRgb))
            .define_method("detached?", &QImage::isDetached)
            .define_method("grayscale?", &QImage::isGrayscale)
            .define_method("null?", &QImage::isNull)
            .define_method<bool (QImage::*)(QIODevice *, const char *)>("load", &QImage::load, Arg("device"), Arg("format"))
            .define_method<bool (QImage::*)(const QString &, const char *)>("load", &QImage::load, Arg("file_name"), Arg("format") = static_cast<const char *>(nullptr))
            .define_method<bool (QImage::*)(QByteArrayView, const char *)>("load_from_data", &QImage::loadFromData, Arg("data"), Arg("format") = static_cast<const char *>(nullptr))
            .define_method<bool (QImage::*)(const QByteArray &, const char *)>("load_from_data", &QImage::loadFromData, Arg("data"), Arg("format") = static_cast<const char *>(nullptr))
            .define_method<bool (QImage::*)(const uchar *, int, const char *)>("load_from_data", &QImage::loadFromData, Arg("buf"), Arg("len"), Arg("format") = static_cast<const char *>(nullptr))
            // .define_method("mirror", &QImage::mirror, Arg("horizontally") = static_cast<bool>(false), Arg("vertically") = static_cast<bool>(true))
            // .define_method<QImage (QImage::*)(bool, bool) const>("mirrored", &QImage::mirrored, Arg("horizontally") = static_cast<bool>(false), Arg("vertically") = static_cast<bool>(true))
            // .define_method<QImage (QImage::*)(bool, bool)>("mirrored", &QImage::mirrored, Arg("horizontally") = static_cast<bool>(false), Arg("vertically") = static_cast<bool>(true))
            .define_method("offset", &QImage::offset)
            .define_method<QRgb (QImage::*)(const QPoint &) const>("pixel", &QImage::pixel, Arg("pt"))
            .define_method<QRgb (QImage::*)(int, int) const>("pixel", &QImage::pixel, Arg("x"), Arg("y"))
            .define_method<QColor (QImage::*)(const QPoint &) const>("pixel_color", &QImage::pixelColor, Arg("pt"))
            .define_method<QColor (QImage::*)(int, int) const>("pixel_color", &QImage::pixelColor, Arg("x"), Arg("y"))
            .define_method("pixel_format", &QImage::pixelFormat)
            .define_method<int (QImage::*)(const QPoint &) const>("pixel_index", &QImage::pixelIndex, Arg("pt"))
            .define_method<int (QImage::*)(int, int) const>("pixel_index", &QImage::pixelIndex, Arg("x"), Arg("y"))
            .define_method("rect", &QImage::rect)
            .define_method("reinterpret_as_format", &QImage::reinterpretAsFormat, Arg("f"))
            .define_method<bool (QImage::*)(QIODevice *, const char *, int) const>("save", &QImage::save, Arg("device"), Arg("format") = static_cast<const char *>(nullptr), Arg("quality") = static_cast<int>(-1))
            .define_method<bool (QImage::*)(const QString &, const char *, int) const>("save", &QImage::save, Arg("file_name"), Arg("format") = static_cast<const char *>(nullptr), Arg("quality") = static_cast<int>(-1))
            .define_method<QImage (QImage::*)(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const>("scaled", &QImage::scaled, Arg("s"), Arg("aspect_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method<QImage (QImage::*)(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const>("scaled", &QImage::scaled, Arg("w"), Arg("h"), Arg("aspect_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method("scaled_to_height", &QImage::scaledToHeight, Arg("h"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method("scaled_to_width", &QImage::scaledToWidth, Arg("w"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method<const uchar *(QImage::*)(int) const>("scan_line", &QImage::scanLine, Arg("i"))
            .define_method<uchar *(QImage::*)(int)>("scan_line", &QImage::scanLine, Arg("i"))
            .define_method("set_alpha_channel", &QImage::setAlphaChannel, Arg("alpha_channel"))
            .define_method("set_color", &QImage::setColor, Arg("i"), Arg("c"))
            .define_method("set_color_count", &QImage::setColorCount, Arg("color_count"))
            .define_method("set_color_space", &QImage::setColorSpace, Arg("color_space"))
            .define_method("set_color_table", &QImage::setColorTable, Arg("colors"))
            .define_method("set_device_pixel_ratio", &QImage::setDevicePixelRatio, Arg("scale_factor"))
            .define_method("set_dots_per_meter_x", &QImage::setDotsPerMeterX, Arg("x"))
            .define_method("set_dots_per_meter_y", &QImage::setDotsPerMeterY, Arg("y"))
            .define_method("set_offset", &QImage::setOffset, Arg("offset"))
            .define_method<void (QImage::*)(const QPoint &, uint)>("set_pixel", &QImage::setPixel, Arg("pt"), Arg("index_or_rgb"))
            .define_method<void (QImage::*)(int, int, uint)>("set_pixel", &QImage::setPixel, Arg("x"), Arg("y"), Arg("index_or_rgb"))
            .define_method<void (QImage::*)(const QPoint &, const QColor &)>("set_pixel_color", &QImage::setPixelColor, Arg("pt"), Arg("c"))
            .define_method<void (QImage::*)(int, int, const QColor &)>("set_pixel_color", &QImage::setPixelColor, Arg("x"), Arg("y"), Arg("c"))
            .define_method("set_text", &QImage::setText, Arg("key"), Arg("value"))
            .define_method("size", &QImage::size)
            .define_method("size_in_bytes", &QImage::sizeInBytes)
            .define_method("text", &QImage::text, Arg("key") = static_cast<const QString &>(QString()))
            .define_method("text_keys", &QImage::textKeys)
            .define_method("transformed", &QImage::transformed, Arg("matrix"), Arg("mode") = static_cast<Qt::TransformationMode>(Qt::FastTransformation))
            .define_method<bool (QImage::*)(const QPoint &) const>("valid", &QImage::valid, Arg("pt"))
            .define_method<bool (QImage::*)(int, int) const>("valid", &QImage::valid, Arg("x"), Arg("y"))
            .define_method("width", &QImage::width)
            // Static Public Members
            .define_singleton_function<QImage (*)(QByteArrayView, const char *)>("from_data", &QImage::fromData, Arg("data"), Arg("format") = static_cast<const char *>(nullptr))
            .define_singleton_function<QImage (*)(const QByteArray &, const char *)>("from_data", &QImage::fromData, Arg("data"), Arg("format") = static_cast<const char *>(nullptr))
            .define_singleton_function<QImage (*)(const uchar *, int, const char *)>("from_data", &QImage::fromData, Arg("data"), Arg("size"), Arg("format") = static_cast<const char *>(nullptr))
            // .define_singleton_function("to_image_format", &QImage::toImageFormat, Arg("format"))
            // .define_singleton_function("to_pixel_format", &QImage::toPixelFormat, Arg("format"))
            .define_singleton_function("true_matrix", &QImage::trueMatrix, Arg("matrix"), Arg("w"), Arg("h"));

    Data_Type<QImage::Format> rb_cQImageFormat =
        // RubyQt6::QtGui::QImage::Format
        define_qenum_under<QImage::Format>(rb_cQImage, "Format");
        define_qenum_value_under(rb_cQImageFormat, "Format_Invalid", QImage::Format::Format_Invalid);
        define_qenum_value_under(rb_cQImageFormat, "Format_Mono", QImage::Format::Format_Mono);
        define_qenum_value_under(rb_cQImageFormat, "Format_MonoLSB", QImage::Format::Format_MonoLSB);
        define_qenum_value_under(rb_cQImageFormat, "Format_Indexed8", QImage::Format::Format_Indexed8);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB32", QImage::Format::Format_RGB32);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB32", QImage::Format::Format_ARGB32);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB32_Premultiplied", QImage::Format::Format_ARGB32_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB16", QImage::Format::Format_RGB16);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB8565_Premultiplied", QImage::Format::Format_ARGB8565_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB666", QImage::Format::Format_RGB666);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB6666_Premultiplied", QImage::Format::Format_ARGB6666_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB555", QImage::Format::Format_RGB555);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB8555_Premultiplied", QImage::Format::Format_ARGB8555_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB888", QImage::Format::Format_RGB888);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB444", QImage::Format::Format_RGB444);
        define_qenum_value_under(rb_cQImageFormat, "Format_ARGB4444_Premultiplied", QImage::Format::Format_ARGB4444_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBX8888", QImage::Format::Format_RGBX8888);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA8888", QImage::Format::Format_RGBA8888);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA8888_Premultiplied", QImage::Format::Format_RGBA8888_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_BGR30", QImage::Format::Format_BGR30);
        define_qenum_value_under(rb_cQImageFormat, "Format_A2BGR30_Premultiplied", QImage::Format::Format_A2BGR30_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGB30", QImage::Format::Format_RGB30);
        define_qenum_value_under(rb_cQImageFormat, "Format_A2RGB30_Premultiplied", QImage::Format::Format_A2RGB30_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_Alpha8", QImage::Format::Format_Alpha8);
        define_qenum_value_under(rb_cQImageFormat, "Format_Grayscale8", QImage::Format::Format_Grayscale8);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBX64", QImage::Format::Format_RGBX64);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA64", QImage::Format::Format_RGBA64);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA64_Premultiplied", QImage::Format::Format_RGBA64_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_Grayscale16", QImage::Format::Format_Grayscale16);
        define_qenum_value_under(rb_cQImageFormat, "Format_BGR888", QImage::Format::Format_BGR888);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBX16FPx4", QImage::Format::Format_RGBX16FPx4);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA16FPx4", QImage::Format::Format_RGBA16FPx4);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA16FPx4_Premultiplied", QImage::Format::Format_RGBA16FPx4_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBX32FPx4", QImage::Format::Format_RGBX32FPx4);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA32FPx4", QImage::Format::Format_RGBA32FPx4);
        define_qenum_value_under(rb_cQImageFormat, "Format_RGBA32FPx4_Premultiplied", QImage::Format::Format_RGBA32FPx4_Premultiplied);
        define_qenum_value_under(rb_cQImageFormat, "Format_CMYK8888", QImage::Format::Format_CMYK8888);
        define_qenum_value_under(rb_cQImageFormat, "NImageFormats", QImage::Format::NImageFormats);

    Data_Type<QImage::InvertMode> rb_cQImageInvertMode =
        // RubyQt6::QtGui::QImage::InvertMode
        define_qenum_under<QImage::InvertMode>(rb_cQImage, "InvertMode");
        define_qenum_value_under(rb_cQImageInvertMode, "InvertRgb", QImage::InvertMode::InvertRgb);
        define_qenum_value_under(rb_cQImageInvertMode, "InvertRgba", QImage::InvertMode::InvertRgba);
}
