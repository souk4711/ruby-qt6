#include "qvideoframeinput-rb.hpp"
#include <qvideoframeinput.h>

#include <QMediaCaptureSession>
#include <QVideoFrame>

using namespace Rice;

Rice::Class rb_cQVideoFrameInput;

void Init_qvideoframeinput(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQVideoFrameInput =
        // RubyQt6::QtMultimedia::QVideoFrameInput
        define_class_under<QVideoFrameInput, QObject>(rb_mQt6QtMultimedia, "QVideoFrameInput")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QVideoFrameInput::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QVideoFrameInput, const QVideoFrameFormat &, QObject *>(), Arg("format"), Arg("parent"))
            // Public Functions
            .define_method("capture_session", &QVideoFrameInput::captureSession)
            .define_method("format", &QVideoFrameInput::format)
            .define_method("send_video_frame", &QVideoFrameInput::sendVideoFrame, Arg("frame"));
            // Signals
            // .define_method("ready_to_send_video_frame", &QVideoFrameInput::readyToSendVideoFrame);
}
