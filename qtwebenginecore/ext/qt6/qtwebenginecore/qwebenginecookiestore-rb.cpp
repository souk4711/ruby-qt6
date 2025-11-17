#include "qwebenginecookiestore-rb.hpp"
#include <qwebenginecookiestore.h>

using namespace Rice;

Rice::Class rb_cQWebEngineCookieStore;
Rice::Class rb_cQWebEngineCookieStoreFilterRequest;

void Init_qwebenginecookiestore(Rice::Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineCookieStore =
        // RubyQt6::QtWebEngineCore::QWebEngineCookieStore
        define_class_under<QWebEngineCookieStore, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineCookieStore")
            // Public Functions
            .define_method("delete_all_cookies", &QWebEngineCookieStore::deleteAllCookies)
            .define_method("delete_cookie", &QWebEngineCookieStore::deleteCookie, Arg("cookie"), Arg("origin") = static_cast<const QUrl &>(QUrl()))
            .define_method("delete_session_cookies", &QWebEngineCookieStore::deleteSessionCookies)
            .define_method("load_all_cookies", &QWebEngineCookieStore::loadAllCookies)
            .define_method("set_cookie", &QWebEngineCookieStore::setCookie, Arg("cookie"), Arg("origin") = static_cast<const QUrl &>(QUrl()))
            .define_method<void (QWebEngineCookieStore::*)(const std::function<bool(const QWebEngineCookieStore::FilterRequest &)> &)>("set_cookie_filter", &QWebEngineCookieStore::setCookieFilter, Arg("filter_callback"))
            .define_method<void (QWebEngineCookieStore::*)(std::function<bool(const QWebEngineCookieStore::FilterRequest &)> &&)>("set_cookie_filter", &QWebEngineCookieStore::setCookieFilter, Arg("filter_callback"))
            // Signals
            .define_method("cookie_added", &QWebEngineCookieStore::cookieAdded, Arg("cookie"))
            .define_method("cookie_removed", &QWebEngineCookieStore::cookieRemoved, Arg("cookie"));

    rb_cQWebEngineCookieStoreFilterRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineCookieStore::FilterRequest
        define_class_under<QWebEngineCookieStore::FilterRequest>(rb_cQWebEngineCookieStore, "FilterRequest")
            .define_attr("first_party_url", &QWebEngineCookieStore::FilterRequest::firstPartyUrl)
            .define_attr("origin", &QWebEngineCookieStore::FilterRequest::origin)
            .define_attr("third_party", &QWebEngineCookieStore::FilterRequest::thirdParty);
}
