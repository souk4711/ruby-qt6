#include "qwebenginenavigationrequest-rb.hpp"
#include <qwebenginenavigationrequest.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineNavigationRequest;

void Init_qwebenginenavigationrequest(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineNavigationRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineNavigationRequest
        define_qlass_under<QWebEngineNavigationRequest, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineNavigationRequest")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEngineNavigationRequest * { return qobject_cast<QWebEngineNavigationRequest *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineNavigationRequest::staticMetaObject; })
            // Public Functions
            .define_method("accept", &QWebEngineNavigationRequest::accept)
            .define_method("has_form_data", &QWebEngineNavigationRequest::hasFormData)
            .define_method("main_frame?", &QWebEngineNavigationRequest::isMainFrame)
            .define_method("navigation_type", &QWebEngineNavigationRequest::navigationType)
            .define_method("reject", &QWebEngineNavigationRequest::reject)
            .define_method("url", &QWebEngineNavigationRequest::url);

    Data_Type<QWebEngineNavigationRequest::NavigationRequestAction> rb_cQWebEngineNavigationRequestNavigationRequestAction =
        // RubyQt6::QtWebEngineCore::QWebEngineNavigationRequest::NavigationRequestAction
        define_qenum_under<QWebEngineNavigationRequest::NavigationRequestAction>(rb_cQWebEngineNavigationRequest, "NavigationRequestAction");
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationRequestAction, "AcceptRequest", QWebEngineNavigationRequest::NavigationRequestAction::AcceptRequest);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationRequestAction, "IgnoreRequest", QWebEngineNavigationRequest::NavigationRequestAction::IgnoreRequest);

    Data_Type<QWebEngineNavigationRequest::NavigationType> rb_cQWebEngineNavigationRequestNavigationType =
        // RubyQt6::QtWebEngineCore::QWebEngineNavigationRequest::NavigationType
        define_qenum_under<QWebEngineNavigationRequest::NavigationType>(rb_cQWebEngineNavigationRequest, "NavigationType");
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "LinkClickedNavigation", QWebEngineNavigationRequest::NavigationType::LinkClickedNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "TypedNavigation", QWebEngineNavigationRequest::NavigationType::TypedNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "FormSubmittedNavigation", QWebEngineNavigationRequest::NavigationType::FormSubmittedNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "BackForwardNavigation", QWebEngineNavigationRequest::NavigationType::BackForwardNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "ReloadNavigation", QWebEngineNavigationRequest::NavigationType::ReloadNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "OtherNavigation", QWebEngineNavigationRequest::NavigationType::OtherNavigation);
        define_qenum_value_under(rb_cQWebEngineNavigationRequestNavigationType, "RedirectNavigation", QWebEngineNavigationRequest::NavigationType::RedirectNavigation);
}
