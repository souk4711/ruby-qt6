#include "qcameraformat-rb.hpp"
#include <qcameradevice.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCameraFormat;

void Init_qcameraformat(Module rb_mQt6QtMultimedia)
{
    rb_cQCameraFormat =
        // RubyQt6::QtMultimedia::QCameraFormat
        define_qlass_under<QCameraFormat>(rb_mQt6QtMultimedia, "QCameraFormat")
            // Constructor
            .define_constructor(Constructor<QCameraFormat>())
            // Public Functions
            .define_method("null?", &QCameraFormat::isNull)
            .define_method("max_frame_rate", &QCameraFormat::maxFrameRate)
            .define_method("min_frame_rate", &QCameraFormat::minFrameRate)
            .define_method("pixel_format", &QCameraFormat::pixelFormat)
            .define_method("resolution", &QCameraFormat::resolution);
}
