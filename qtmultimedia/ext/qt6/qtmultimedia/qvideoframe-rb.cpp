#include "qvideoframe-rb.hpp"
#include <qvideoframe.h>
#include <rice/qt6/qenum.hpp>

#include <QPainter>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVideoFrame;

void Init_qvideoframe(Module rb_mQt6QtMultimedia)
{
    rb_cQVideoFrame =
        // RubyQt6::QtMultimedia::QVideoFrame
        define_qlass_under<QVideoFrame>(rb_mQt6QtMultimedia, "QVideoFrame")
            // Constructor
            .define_constructor(Constructor<QVideoFrame>())
            .define_constructor(Constructor<QVideoFrame, const QImage &>(), Arg("image"))
            .define_constructor(Constructor<QVideoFrame, const QVideoFrameFormat &>(), Arg("format"))
            // Public Functions
            .define_method<uchar *(QVideoFrame::*)(int)>("bits", &QVideoFrame::bits, Arg("plane"))
            .define_method("bytes_per_line", &QVideoFrame::bytesPerLine, Arg("plane"))
            .define_method("end_time", &QVideoFrame::endTime)
            .define_method("handle_type", &QVideoFrame::handleType)
            .define_method("height", &QVideoFrame::height)
            .define_method("mapped?", &QVideoFrame::isMapped)
            .define_method("readable?", &QVideoFrame::isReadable)
            .define_method("valid?", &QVideoFrame::isValid)
            .define_method("writable?", &QVideoFrame::isWritable)
            .define_method("map", &QVideoFrame::map, Arg("mode"))
            .define_method("map_mode", &QVideoFrame::mapMode)
            .define_method("mapped_bytes", &QVideoFrame::mappedBytes, Arg("plane"))
            .define_method("mirrored", &QVideoFrame::mirrored)
            .define_method("paint", &QVideoFrame::paint, Arg("painter"), Arg("rect"), Arg("options"))
            .define_method("pixel_format", &QVideoFrame::pixelFormat)
            .define_method("plane_count", &QVideoFrame::planeCount)
            .define_method("rotation", &QVideoFrame::rotation)
            .define_method("set_end_time", &QVideoFrame::setEndTime, Arg("time"))
            .define_method("set_mirrored", &QVideoFrame::setMirrored, Arg("mirrored"))
            .define_method("set_rotation", &QVideoFrame::setRotation, Arg("angle"))
            .define_method("set_start_time", &QVideoFrame::setStartTime, Arg("time"))
            .define_method("set_stream_frame_rate", &QVideoFrame::setStreamFrameRate, Arg("rate"))
            .define_method("set_subtitle_text", &QVideoFrame::setSubtitleText, Arg("text"))
            .define_method("size", &QVideoFrame::size)
            .define_method("start_time", &QVideoFrame::startTime)
            .define_method("stream_frame_rate", &QVideoFrame::streamFrameRate)
            .define_method("subtitle_text", &QVideoFrame::subtitleText)
            .define_method("surface_format", &QVideoFrame::surfaceFormat)
            .define_method("to_image", &QVideoFrame::toImage)
            .define_method("unmap", &QVideoFrame::unmap)
            .define_method("width", &QVideoFrame::width);

    Data_Type<QVideoFrame::HandleType> rb_cQVideoFrameHandleType =
        // RubyQt6::QtMultimedia::QVideoFrame::HandleType
        define_qenum_under<QVideoFrame::HandleType>(rb_cQVideoFrame, "HandleType");
        define_qenum_value_under(rb_cQVideoFrameHandleType, "NoHandle", QVideoFrame::HandleType::NoHandle);
        define_qenum_value_under(rb_cQVideoFrameHandleType, "RhiTextureHandle", QVideoFrame::HandleType::RhiTextureHandle);

    Data_Type<QVideoFrame::MapMode> rb_cQVideoFrameMapMode =
        // RubyQt6::QtMultimedia::QVideoFrame::MapMode
        define_qenum_under<QVideoFrame::MapMode>(rb_cQVideoFrame, "MapMode");
        define_qenum_value_under(rb_cQVideoFrameMapMode, "NotMapped", QVideoFrame::MapMode::NotMapped);
        define_qenum_value_under(rb_cQVideoFrameMapMode, "ReadOnly", QVideoFrame::MapMode::ReadOnly);
        define_qenum_value_under(rb_cQVideoFrameMapMode, "WriteOnly", QVideoFrame::MapMode::WriteOnly);
        define_qenum_value_under(rb_cQVideoFrameMapMode, "ReadWrite", QVideoFrame::MapMode::ReadWrite);
}
