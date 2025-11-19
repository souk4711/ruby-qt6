#include "qwebengineprofile-rb.hpp"
#include <qwebengineprofile.h>
#include <rice/qt6/qenum.hpp>

#include <QWebEngineClientCertificateStore>
#include <QWebEngineClientHints>
#include <QWebEngineCookieStore>
#include <QWebEngineDownloadRequest>
#include <QWebEngineExtensionManager>
#include <QWebEngineNotification>
#include <QWebEngineSettings>
#include <QWebEngineScriptCollection>
#include <QWebEngineUrlRequestInterceptor>
#include <QWebEngineUrlSchemeHandler>

using namespace Rice;

Rice::Class rb_cQWebEngineProfile;

struct QWebEngineNotificationFunctor {
    QWebEngineNotificationFunctor(Object value) : value_(value) {}
    void operator()(std::unique_ptr<QWebEngineNotification> notification) { this->value_.call("call", Object(detail::to_ruby(notification))); };
    Object value_;
};

void Init_qwebengineprofile(Rice::Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineProfile =
        // RubyQt6::QtWebEngineCore::QWebEngineProfile
        define_class_under<QWebEngineProfile, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineProfile")
            // RubyQt6-Defined Functions
            .define_method("set_notification_presenter", [](QWebEngineProfile *self, Object presenter) -> void { return self->setNotificationPresenter(QWebEngineNotificationFunctor(presenter)); }, Arg("presenter"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineProfile::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWebEngineProfile, const QString &, QObject *>(), Arg("name"), Arg("parent"))
            // Public Functions
            .define_method("additional_trusted_certificates", &QWebEngineProfile::additionalTrustedCertificates)
            .define_method("cache_path", &QWebEngineProfile::cachePath)
            .define_method("clear_all_visited_links", &QWebEngineProfile::clearAllVisitedLinks)
            .define_method("clear_http_cache", &QWebEngineProfile::clearHttpCache)
            .define_method("clear_visited_links", &QWebEngineProfile::clearVisitedLinks, Arg("urls"))
            .define_method("client_certificate_store", &QWebEngineProfile::clientCertificateStore)
            .define_method("client_hints", &QWebEngineProfile::clientHints)
            .define_method("cookie_store", &QWebEngineProfile::cookieStore)
            .define_method("download_path", &QWebEngineProfile::downloadPath)
            .define_method("extension_manager", &QWebEngineProfile::extensionManager)
            .define_method("http_accept_language", &QWebEngineProfile::httpAcceptLanguage)
            .define_method("http_cache_maximum_size", &QWebEngineProfile::httpCacheMaximumSize)
            .define_method("http_cache_type", &QWebEngineProfile::httpCacheType)
            .define_method("http_user_agent", &QWebEngineProfile::httpUserAgent)
            .define_method("install_url_scheme_handler", &QWebEngineProfile::installUrlSchemeHandler, Arg("scheme"), Arg("handler"))
            .define_method("off_the_record?", &QWebEngineProfile::isOffTheRecord)
            .define_method("push_service_enabled?", &QWebEngineProfile::isPushServiceEnabled)
            .define_method("spell_check_enabled?", &QWebEngineProfile::isSpellCheckEnabled)
            .define_method("list_all_permissions", &QWebEngineProfile::listAllPermissions)
            .define_method("list_permissions_for_origin", &QWebEngineProfile::listPermissionsForOrigin, Arg("security_origin"))
            .define_method("list_permissions_for_permission_type", &QWebEngineProfile::listPermissionsForPermissionType, Arg("permission_type"))
            .define_method("persistent_cookies_policy", &QWebEngineProfile::persistentCookiesPolicy)
            .define_method("persistent_permissions_policy", &QWebEngineProfile::persistentPermissionsPolicy)
            .define_method("persistent_storage_path", &QWebEngineProfile::persistentStoragePath)
            .define_method("query_permission", &QWebEngineProfile::queryPermission, Arg("security_origin"), Arg("permission_type"))
            .define_method("remove_all_url_scheme_handlers", &QWebEngineProfile::removeAllUrlSchemeHandlers)
            .define_method("remove_url_scheme", &QWebEngineProfile::removeUrlScheme, Arg("scheme"))
            .define_method("remove_url_scheme_handler", &QWebEngineProfile::removeUrlSchemeHandler, Arg("handler"))
            .define_method("request_icon_for_icon_url", &QWebEngineProfile::requestIconForIconURL, Arg("url"), Arg("desired_size_in_pixel"), Arg("icon_available_callback"))
            .define_method("request_icon_for_page_url", &QWebEngineProfile::requestIconForPageURL, Arg("url"), Arg("desired_size_in_pixel"), Arg("icon_available_callback"))
            .define_method("scripts", &QWebEngineProfile::scripts)
            .define_method("set_cache_path", &QWebEngineProfile::setCachePath, Arg("path"))
            .define_method("set_download_path", &QWebEngineProfile::setDownloadPath, Arg("path"))
            .define_method("set_http_accept_language", &QWebEngineProfile::setHttpAcceptLanguage, Arg("http_accept_language"))
            .define_method("set_http_cache_maximum_size", &QWebEngineProfile::setHttpCacheMaximumSize, Arg("max_size"))
            .define_method("set_http_cache_type", &QWebEngineProfile::setHttpCacheType, Arg("cache_type"))
            .define_method("set_http_user_agent", &QWebEngineProfile::setHttpUserAgent, Arg("user_agent"))
            .define_method("set_persistent_cookies_policy", &QWebEngineProfile::setPersistentCookiesPolicy, Arg("policy"))
            .define_method("set_persistent_permissions_policy", &QWebEngineProfile::setPersistentPermissionsPolicy, Arg("policy"))
            .define_method("set_persistent_storage_path", &QWebEngineProfile::setPersistentStoragePath, Arg("path"))
            .define_method("set_push_service_enabled", &QWebEngineProfile::setPushServiceEnabled, Arg("enabled"))
            .define_method("set_spell_check_enabled", &QWebEngineProfile::setSpellCheckEnabled, Arg("enabled"))
            .define_method("set_spell_check_languages", &QWebEngineProfile::setSpellCheckLanguages, Arg("languages"))
            .define_method("set_url_request_interceptor", &QWebEngineProfile::setUrlRequestInterceptor, Arg("interceptor"))
            .define_method("settings", &QWebEngineProfile::settings)
            .define_method("spell_check_languages", &QWebEngineProfile::spellCheckLanguages)
            .define_method("storage_name", &QWebEngineProfile::storageName)
            .define_method("url_scheme_handler", &QWebEngineProfile::urlSchemeHandler, Arg("scheme"))
            .define_method("visited_links_contains_url", &QWebEngineProfile::visitedLinksContainsUrl, Arg("url"))
            // Signals
            .define_method("clear_http_cache_completed", &QWebEngineProfile::clearHttpCacheCompleted)
            .define_method("download_requested", &QWebEngineProfile::downloadRequested, Arg("download"))
            // Static Public Members
            .define_singleton_function("default_profile", &QWebEngineProfile::defaultProfile);

    Data_Type<QWebEngineProfile::HttpCacheType> rb_cQWebEngineProfileHttpCacheType =
        // RubyQt6::QtWebEngineCore::QWebEngineProfile::HttpCacheType
        define_qenum_under<QWebEngineProfile::HttpCacheType>(rb_cQWebEngineProfile, "HttpCacheType");
        define_qenum_value_under(rb_cQWebEngineProfileHttpCacheType, "MemoryHttpCache", QWebEngineProfile::HttpCacheType::MemoryHttpCache);
        define_qenum_value_under(rb_cQWebEngineProfileHttpCacheType, "DiskHttpCache", QWebEngineProfile::HttpCacheType::DiskHttpCache);
        define_qenum_value_under(rb_cQWebEngineProfileHttpCacheType, "NoCache", QWebEngineProfile::HttpCacheType::NoCache);

    Data_Type<QWebEngineProfile::PersistentCookiesPolicy> rb_cQWebEngineProfilePersistentCookiesPolicy =
        // RubyQt6::QtWebEngineCore::QWebEngineProfile::PersistentCookiesPolicy
        define_qenum_under<QWebEngineProfile::PersistentCookiesPolicy>(rb_cQWebEngineProfile, "PersistentCookiesPolicy");
        define_qenum_value_under(rb_cQWebEngineProfilePersistentCookiesPolicy, "NoPersistentCookies", QWebEngineProfile::PersistentCookiesPolicy::NoPersistentCookies);
        define_qenum_value_under(rb_cQWebEngineProfilePersistentCookiesPolicy, "AllowPersistentCookies", QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
        define_qenum_value_under(rb_cQWebEngineProfilePersistentCookiesPolicy, "ForcePersistentCookies", QWebEngineProfile::PersistentCookiesPolicy::ForcePersistentCookies);

    Data_Type<QWebEngineProfile::PersistentPermissionsPolicy> rb_cQWebEngineProfilePersistentPermissionsPolicy =
        // RubyQt6::QtWebEngineCore::QWebEngineProfile::PersistentPermissionsPolicy
        define_qenum_under<QWebEngineProfile::PersistentPermissionsPolicy>(rb_cQWebEngineProfile, "PersistentPermissionsPolicy");
        define_qenum_value_under(rb_cQWebEngineProfilePersistentPermissionsPolicy, "AskEveryTime", QWebEngineProfile::PersistentPermissionsPolicy::AskEveryTime);
        define_qenum_value_under(rb_cQWebEngineProfilePersistentPermissionsPolicy, "StoreInMemory", QWebEngineProfile::PersistentPermissionsPolicy::StoreInMemory);
        define_qenum_value_under(rb_cQWebEngineProfilePersistentPermissionsPolicy, "StoreOnDisk", QWebEngineProfile::PersistentPermissionsPolicy::StoreOnDisk);
}
