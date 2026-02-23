#include "qvideoframeformat-rb.hpp"
#include <qvideoframeformat.h>
#include <rice/qt6/qenum.hpp>

#include <QVideoFrame>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVideoFrameFormat;

void Init_qvideoframeformat(Module rb_mQt6QtMultimedia)
{
    rb_cQVideoFrameFormat =
        // RubyQt6::QtMultimedia::QVideoFrameFormat
        define_qlass_under<QVideoFrameFormat>(rb_mQt6QtMultimedia, "QVideoFrameFormat")
            // Constructor
            .define_constructor(Constructor<QVideoFrameFormat>())
            .define_constructor(Constructor<QVideoFrameFormat, const QSize &, QVideoFrameFormat::PixelFormat>(), Arg("size"), Arg("pixel_format"))
            // Public Functions
            .define_method("color_range", &QVideoFrameFormat::colorRange)
            .define_method("color_space", &QVideoFrameFormat::colorSpace)
            .define_method("color_transfer", &QVideoFrameFormat::colorTransfer)
            .define_method("detach", &QVideoFrameFormat::detach)
            .define_method("fragment_shader_file_name", &QVideoFrameFormat::fragmentShaderFileName)
            .define_method("frame_height", &QVideoFrameFormat::frameHeight)
            .define_method("frame_size", &QVideoFrameFormat::frameSize)
            .define_method("frame_width", &QVideoFrameFormat::frameWidth)
            .define_method("mirrored?", &QVideoFrameFormat::isMirrored)
            .define_method("valid?", &QVideoFrameFormat::isValid)
            .define_method("max_luminance", &QVideoFrameFormat::maxLuminance)
            .define_method("pixel_format", &QVideoFrameFormat::pixelFormat)
            .define_method("plane_count", &QVideoFrameFormat::planeCount)
            .define_method("rotation", &QVideoFrameFormat::rotation)
            .define_method("scan_line_direction", &QVideoFrameFormat::scanLineDirection)
            .define_method("set_color_range", &QVideoFrameFormat::setColorRange, Arg("range"))
            .define_method("set_color_space", &QVideoFrameFormat::setColorSpace, Arg("color_space"))
            .define_method("set_color_transfer", &QVideoFrameFormat::setColorTransfer, Arg("color_transfer"))
            .define_method<void (QVideoFrameFormat::*)(const QSize &)>("set_frame_size", &QVideoFrameFormat::setFrameSize, Arg("size"))
            .define_method<void (QVideoFrameFormat::*)(int, int)>("set_frame_size", &QVideoFrameFormat::setFrameSize, Arg("width"), Arg("height"))
            .define_method("set_max_luminance", &QVideoFrameFormat::setMaxLuminance, Arg("lum"))
            .define_method("set_mirrored", &QVideoFrameFormat::setMirrored, Arg("mirrored"))
            .define_method("set_rotation", &QVideoFrameFormat::setRotation, Arg("rotation"))
            .define_method("set_scan_line_direction", &QVideoFrameFormat::setScanLineDirection, Arg("direction"))
            .define_method("set_stream_frame_rate", &QVideoFrameFormat::setStreamFrameRate, Arg("rate"))
            .define_method("set_viewport", &QVideoFrameFormat::setViewport, Arg("viewport"))
            .define_method("stream_frame_rate", &QVideoFrameFormat::streamFrameRate)
            .define_method("viewport", &QVideoFrameFormat::viewport)
            // Static Public Members
            .define_singleton_function("image_format_from_pixel_format", &QVideoFrameFormat::imageFormatFromPixelFormat, Arg("format"))
            .define_singleton_function("pixel_format_from_image_format", &QVideoFrameFormat::pixelFormatFromImageFormat, Arg("format"))
            .define_singleton_function("pixel_format_to_string", &QVideoFrameFormat::pixelFormatToString, Arg("pixel_format"));

    Data_Type<QVideoFrameFormat::ColorRange> rb_cQVideoFrameFormatColorRange =
        // RubyQt6::QtMultimedia::QVideoFrameFormat::ColorRange
        define_qenum_under<QVideoFrameFormat::ColorRange>(rb_cQVideoFrameFormat, "ColorRange");
        define_qenum_value_under(rb_cQVideoFrameFormatColorRange, "ColorRange_Unknown", QVideoFrameFormat::ColorRange::ColorRange_Unknown);
        define_qenum_value_under(rb_cQVideoFrameFormatColorRange, "ColorRange_Video", QVideoFrameFormat::ColorRange::ColorRange_Video);
        define_qenum_value_under(rb_cQVideoFrameFormatColorRange, "ColorRange_Full", QVideoFrameFormat::ColorRange::ColorRange_Full);

    Data_Type<QVideoFrameFormat::ColorSpace> rb_cQVideoFrameFormatColorSpace =
        // RubyQt6::QtMultimedia::QVideoFrameFormat::ColorSpace
        define_qenum_under<QVideoFrameFormat::ColorSpace>(rb_cQVideoFrameFormat, "ColorSpace");
        define_qenum_value_under(rb_cQVideoFrameFormatColorSpace, "ColorSpace_Undefined", QVideoFrameFormat::ColorSpace::ColorSpace_Undefined);
        define_qenum_value_under(rb_cQVideoFrameFormatColorSpace, "ColorSpace_BT601", QVideoFrameFormat::ColorSpace::ColorSpace_BT601);
        define_qenum_value_under(rb_cQVideoFrameFormatColorSpace, "ColorSpace_BT709", QVideoFrameFormat::ColorSpace::ColorSpace_BT709);
        define_qenum_value_under(rb_cQVideoFrameFormatColorSpace, "ColorSpace_AdobeRgb", QVideoFrameFormat::ColorSpace::ColorSpace_AdobeRgb);
        define_qenum_value_under(rb_cQVideoFrameFormatColorSpace, "ColorSpace_BT2020", QVideoFrameFormat::ColorSpace::ColorSpace_BT2020);

    Data_Type<QVideoFrameFormat::ColorTransfer> rb_cQVideoFrameFormatColorTransfer =
        // RubyQt6::QtMultimedia::QVideoFrameFormat::ColorTransfer
        define_qenum_under<QVideoFrameFormat::ColorTransfer>(rb_cQVideoFrameFormat, "ColorTransfer");
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_Unknown", QVideoFrameFormat::ColorTransfer::ColorTransfer_Unknown);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_BT709", QVideoFrameFormat::ColorTransfer::ColorTransfer_BT709);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_BT601", QVideoFrameFormat::ColorTransfer::ColorTransfer_BT601);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_Linear", QVideoFrameFormat::ColorTransfer::ColorTransfer_Linear);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_Gamma22", QVideoFrameFormat::ColorTransfer::ColorTransfer_Gamma22);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_Gamma28", QVideoFrameFormat::ColorTransfer::ColorTransfer_Gamma28);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_ST2084", QVideoFrameFormat::ColorTransfer::ColorTransfer_ST2084);
        define_qenum_value_under(rb_cQVideoFrameFormatColorTransfer, "ColorTransfer_STD_B67", QVideoFrameFormat::ColorTransfer::ColorTransfer_STD_B67);

    Data_Type<QVideoFrameFormat::Direction> rb_cQVideoFrameFormatDirection =
        // RubyQt6::QtMultimedia::QVideoFrameFormat::Direction
        define_qenum_under<QVideoFrameFormat::Direction>(rb_cQVideoFrameFormat, "Direction");
        define_qenum_value_under(rb_cQVideoFrameFormatDirection, "TopToBottom", QVideoFrameFormat::Direction::TopToBottom);
        define_qenum_value_under(rb_cQVideoFrameFormatDirection, "BottomToTop", QVideoFrameFormat::Direction::BottomToTop);

    Data_Type<QVideoFrameFormat::PixelFormat> rb_cQVideoFrameFormatPixelFormat =
        // RubyQt6::QtMultimedia::QVideoFrameFormat::PixelFormat
        define_qenum_under<QVideoFrameFormat::PixelFormat>(rb_cQVideoFrameFormat, "PixelFormat");
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_Invalid", QVideoFrameFormat::PixelFormat::Format_Invalid);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_ARGB8888", QVideoFrameFormat::PixelFormat::Format_ARGB8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_ARGB8888_Premultiplied", QVideoFrameFormat::PixelFormat::Format_ARGB8888_Premultiplied);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_XRGB8888", QVideoFrameFormat::PixelFormat::Format_XRGB8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_BGRA8888", QVideoFrameFormat::PixelFormat::Format_BGRA8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_BGRA8888_Premultiplied", QVideoFrameFormat::PixelFormat::Format_BGRA8888_Premultiplied);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_BGRX8888", QVideoFrameFormat::PixelFormat::Format_BGRX8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_ABGR8888", QVideoFrameFormat::PixelFormat::Format_ABGR8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_XBGR8888", QVideoFrameFormat::PixelFormat::Format_XBGR8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_RGBA8888", QVideoFrameFormat::PixelFormat::Format_RGBA8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_RGBX8888", QVideoFrameFormat::PixelFormat::Format_RGBX8888);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_AYUV", QVideoFrameFormat::PixelFormat::Format_AYUV);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_AYUV_Premultiplied", QVideoFrameFormat::PixelFormat::Format_AYUV_Premultiplied);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_YUV420P", QVideoFrameFormat::PixelFormat::Format_YUV420P);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_YUV422P", QVideoFrameFormat::PixelFormat::Format_YUV422P);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_YV12", QVideoFrameFormat::PixelFormat::Format_YV12);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_UYVY", QVideoFrameFormat::PixelFormat::Format_UYVY);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_YUYV", QVideoFrameFormat::PixelFormat::Format_YUYV);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_NV12", QVideoFrameFormat::PixelFormat::Format_NV12);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_NV21", QVideoFrameFormat::PixelFormat::Format_NV21);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_IMC1", QVideoFrameFormat::PixelFormat::Format_IMC1);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_IMC2", QVideoFrameFormat::PixelFormat::Format_IMC2);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_IMC3", QVideoFrameFormat::PixelFormat::Format_IMC3);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_IMC4", QVideoFrameFormat::PixelFormat::Format_IMC4);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_Y8", QVideoFrameFormat::PixelFormat::Format_Y8);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_Y16", QVideoFrameFormat::PixelFormat::Format_Y16);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_P010", QVideoFrameFormat::PixelFormat::Format_P010);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_P016", QVideoFrameFormat::PixelFormat::Format_P016);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_SamplerExternalOES", QVideoFrameFormat::PixelFormat::Format_SamplerExternalOES);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_Jpeg", QVideoFrameFormat::PixelFormat::Format_Jpeg);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_SamplerRect", QVideoFrameFormat::PixelFormat::Format_SamplerRect);
        define_qenum_value_under(rb_cQVideoFrameFormatPixelFormat, "Format_YUV420P10", QVideoFrameFormat::PixelFormat::Format_YUV420P10);
}
