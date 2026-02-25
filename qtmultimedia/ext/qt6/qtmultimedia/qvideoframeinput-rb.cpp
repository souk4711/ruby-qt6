#include "qvideoframeinput-rb.hpp"
#include <qvideoframeinput.h>

#include <QMediaCaptureSession>
#include <QVideoFrame>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVideoFrameInput;

void Init_qvideoframeinput(Module rb_mQt6QtMultimedia)
{
    rb_cQVideoFrameInput =
        // RubyQt6::QtMultimedia::QVideoFrameInput
        define_qlass_under<QVideoFrameInput, QObject>(rb_mQt6QtMultimedia, "QVideoFrameInput")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QVideoFrameInput * { return qobject_cast<QVideoFrameInput *>(object); })
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
