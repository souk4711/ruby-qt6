#include "qwindowcapture-rb.hpp"
#include <qwindowcapture.h>
#include <rice/qt6/qenum.hpp>

#include <QMediaCaptureSession>

using namespace Rice;

Rice::Class rb_cQWindowCapture;

void Init_qwindowcapture(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQWindowCapture =
        // RubyQt6::QtMultimedia::QWindowCapture
        define_class_under<QWindowCapture, QObject>(rb_mQt6QtMultimedia, "QWindowCapture")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWindowCapture::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWindowCapture, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("capture_session", &QWindowCapture::captureSession)
            .define_method("error", &QWindowCapture::error)
            .define_method("error_string", &QWindowCapture::errorString)
            .define_method("active?", &QWindowCapture::isActive)
            .define_method("set_window", &QWindowCapture::setWindow, Arg("window"))
            .define_method("window", &QWindowCapture::window)
            // Public Slots
            .define_method("set_active", &QWindowCapture::setActive, Arg("active"))
            .define_method("start", &QWindowCapture::start)
            .define_method("stop", &QWindowCapture::stop)
            // Signals
            // .define_method("active_changed", &QWindowCapture::activeChanged, Arg("active"))
            // .define_method("error_changed", &QWindowCapture::errorChanged)
            // .define_method("error_occurred", &QWindowCapture::errorOccurred, Arg("error"), Arg("error_string"))
            // .define_method("window_changed", &QWindowCapture::windowChanged, Arg("window"))
            // Static Public Members
            .define_singleton_function("capturable_windows", &QWindowCapture::capturableWindows);

    Data_Type<QWindowCapture::Error> rb_cQWindowCaptureError =
        // RubyQt6::QtMultimedia::QWindowCapture::Error
        define_qenum_under<QWindowCapture::Error>(rb_cQWindowCapture, "Error");
        define_qenum_value_under(rb_cQWindowCaptureError, "NoError", QWindowCapture::Error::NoError);
        define_qenum_value_under(rb_cQWindowCaptureError, "InternalError", QWindowCapture::Error::InternalError);
        define_qenum_value_under(rb_cQWindowCaptureError, "CapturingNotSupported", QWindowCapture::Error::CapturingNotSupported);
        define_qenum_value_under(rb_cQWindowCaptureError, "CaptureFailed", QWindowCapture::Error::CaptureFailed);
        define_qenum_value_under(rb_cQWindowCaptureError, "NotFound", QWindowCapture::Error::NotFound);
}
