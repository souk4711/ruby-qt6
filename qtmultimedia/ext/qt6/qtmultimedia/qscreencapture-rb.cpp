#include "qscreencapture-rb.hpp"
#include <qscreencapture.h>
#include <rice/qt6/qenum.hpp>

#include <QMediaCaptureSession>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQScreenCapture;

void Init_qscreencapture(Module rb_mQt6QtMultimedia)
{
    rb_cQScreenCapture =
        // RubyQt6::QtMultimedia::QScreenCapture
        define_qlass_under<QScreenCapture, QObject>(rb_mQt6QtMultimedia, "QScreenCapture")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QScreenCapture::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QScreenCapture, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("capture_session", &QScreenCapture::captureSession)
            .define_method("error", &QScreenCapture::error)
            .define_method("error_string", &QScreenCapture::errorString)
            .define_method("active?", &QScreenCapture::isActive)
            .define_method("screen", &QScreenCapture::screen)
            .define_method("set_screen", &QScreenCapture::setScreen, Arg("screen"))
            // Public Slots
            .define_method("set_active", &QScreenCapture::setActive, Arg("active"))
            .define_method("start", &QScreenCapture::start)
            .define_method("stop", &QScreenCapture::stop);
            // Signals
            // .define_method("active_changed", &QScreenCapture::activeChanged, Arg("active"))
            // .define_method("error_changed", &QScreenCapture::errorChanged)
            // .define_method("error_occurred", &QScreenCapture::errorOccurred, Arg("error"), Arg("error_string"))
            // .define_method("screen_changed", &QScreenCapture::screenChanged, Arg("screen"));

    Data_Type<QScreenCapture::Error> rb_cQScreenCaptureError =
        // RubyQt6::QtMultimedia::QScreenCapture::Error
        define_qenum_under<QScreenCapture::Error>(rb_cQScreenCapture, "Error");
        define_qenum_value_under(rb_cQScreenCaptureError, "NoError", QScreenCapture::Error::NoError);
        define_qenum_value_under(rb_cQScreenCaptureError, "InternalError", QScreenCapture::Error::InternalError);
        define_qenum_value_under(rb_cQScreenCaptureError, "CapturingNotSupported", QScreenCapture::Error::CapturingNotSupported);
        define_qenum_value_under(rb_cQScreenCaptureError, "CaptureFailed", QScreenCapture::Error::CaptureFailed);
        define_qenum_value_under(rb_cQScreenCaptureError, "NotFound", QScreenCapture::Error::NotFound);
}
