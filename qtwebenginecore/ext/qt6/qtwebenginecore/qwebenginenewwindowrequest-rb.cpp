#include "qwebenginenewwindowrequest-rb.hpp"
#include <qwebenginenewwindowrequest.h>
#include <rice/qt6/qenum.hpp>

#include <QWebEnginePage>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineNewWindowRequest;

void Init_qwebenginenewwindowrequest(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineNewWindowRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineNewWindowRequest
        define_qlass_under<QWebEngineNewWindowRequest, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineNewWindowRequest")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineNewWindowRequest::staticMetaObject; })
            // Public Functions
            .define_method("destination", &QWebEngineNewWindowRequest::destination)
            .define_method("open_in", &QWebEngineNewWindowRequest::openIn, Arg("page"))
            .define_method("requested_geometry", &QWebEngineNewWindowRequest::requestedGeometry)
            .define_method("requested_url", &QWebEngineNewWindowRequest::requestedUrl)
            .define_method("user_initiated?", &QWebEngineNewWindowRequest::isUserInitiated);

    Data_Type<QWebEngineNewWindowRequest::DestinationType> rb_cQWebEngineNewWindowRequestDestinationType =
        // RubyQt6::QtWebEngineCore::QWebEngineNewWindowRequest::DestinationType
        define_qenum_under<QWebEngineNewWindowRequest::DestinationType>(rb_cQWebEngineNewWindowRequest, "DestinationType");
        define_qenum_value_under(rb_cQWebEngineNewWindowRequestDestinationType, "InNewWindow", QWebEngineNewWindowRequest::DestinationType::InNewWindow);
        define_qenum_value_under(rb_cQWebEngineNewWindowRequestDestinationType, "InNewTab", QWebEngineNewWindowRequest::DestinationType::InNewTab);
        define_qenum_value_under(rb_cQWebEngineNewWindowRequestDestinationType, "InNewDialog", QWebEngineNewWindowRequest::DestinationType::InNewDialog);
        define_qenum_value_under(rb_cQWebEngineNewWindowRequestDestinationType, "InNewBackgroundTab", QWebEngineNewWindowRequest::DestinationType::InNewBackgroundTab);
}
