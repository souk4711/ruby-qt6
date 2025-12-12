#include "qwebenginefullscreenrequest-rb.hpp"
#include <qwebenginefullscreenrequest.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineFullScreenRequest;

void Init_qwebenginefullscreenrequest(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineFullScreenRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineFullScreenRequest
        define_class_under<QWebEngineFullScreenRequest>(rb_mQt6QtWebEngineCore, "QWebEngineFullScreenRequest")
            // Public Functions
            .define_method("accept", &QWebEngineFullScreenRequest::accept)
            .define_method("origin", &QWebEngineFullScreenRequest::origin)
            .define_method("reject", &QWebEngineFullScreenRequest::reject)
            .define_method("toggle_on", &QWebEngineFullScreenRequest::toggleOn);
}
