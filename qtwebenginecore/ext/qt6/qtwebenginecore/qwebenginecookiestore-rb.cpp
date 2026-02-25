#include "qwebenginecookiestore-rb.hpp"
#include <qwebenginecookiestore.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineCookieStore;
Class rb_cQWebEngineCookieStoreFilterRequest;

void Init_qwebenginecookiestore(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineCookieStore =
        // RubyQt6::QtWebEngineCore::QWebEngineCookieStore
        define_qlass_under<QWebEngineCookieStore, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineCookieStore")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEngineCookieStore * { return qobject_cast<QWebEngineCookieStore *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineCookieStore::staticMetaObject; })
            // Public Functions
            .define_method("delete_all_cookies", &QWebEngineCookieStore::deleteAllCookies)
            .define_method("delete_cookie", &QWebEngineCookieStore::deleteCookie, Arg("cookie"), Arg("origin") = static_cast<const QUrl &>(QUrl()))
            .define_method("delete_session_cookies", &QWebEngineCookieStore::deleteSessionCookies)
            .define_method("load_all_cookies", &QWebEngineCookieStore::loadAllCookies)
            .define_method("set_cookie", &QWebEngineCookieStore::setCookie, Arg("cookie"), Arg("origin") = static_cast<const QUrl &>(QUrl()));
            // Signals
            // .define_method("cookie_added", &QWebEngineCookieStore::cookieAdded, Arg("cookie"))
            // .define_method("cookie_removed", &QWebEngineCookieStore::cookieRemoved, Arg("cookie"));

    rb_cQWebEngineCookieStoreFilterRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineCookieStore::FilterRequest
        define_qlass_under<QWebEngineCookieStore::FilterRequest>(rb_cQWebEngineCookieStore, "FilterRequest")
            .define_attr("first_party_url", &QWebEngineCookieStore::FilterRequest::firstPartyUrl)
            .define_attr("origin", &QWebEngineCookieStore::FilterRequest::origin)
            .define_attr("third_party", &QWebEngineCookieStore::FilterRequest::thirdParty);
}
