#include "qnetworkaccessmanager-rb.hpp"
#include <qnetworkaccessmanager.h>
#include <rice/qt6/qenum.hpp>

#include <QAbstractNetworkCache>
#include <QHstsPolicy>
#include <QHttpMultiPart>
#include <QNetworkCookieJar>
#include <QNetworkProxy>
#include <QNetworkProxyFactory>
#include <QNetworkReply>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQNetworkAccessManager;

void Init_qnetworkaccessmanager(Module rb_mQt6QtNetwork)
{
    rb_cQNetworkAccessManager =
        // RubyQt6::QtNetwork::QNetworkAccessManager
        define_class_under<QNetworkAccessManager, QObject>(rb_mQt6QtNetwork, "QNetworkAccessManager")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QNetworkAccessManager::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QNetworkAccessManager, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("add_strict_transport_security_hosts", &QNetworkAccessManager::addStrictTransportSecurityHosts, Arg("known_hosts"))
            .define_method("auto_delete_replies", &QNetworkAccessManager::autoDeleteReplies)
            .define_method("cache", &QNetworkAccessManager::cache)
            .define_method("clear_access_cache", &QNetworkAccessManager::clearAccessCache)
            .define_method("clear_connection_cache", &QNetworkAccessManager::clearConnectionCache)
            .define_method("connect_to_host", &QNetworkAccessManager::connectToHost, Arg("host_name"), Arg("port") = static_cast<quint16>(80))
            .define_method<void (QNetworkAccessManager::*)(const QString &, quint16, const QSslConfiguration &)>("connect_to_host_encrypted", &QNetworkAccessManager::connectToHostEncrypted, Arg("host_name"), Arg("port") = static_cast<quint16>(443), Arg("ssl_configuration"))
            .define_method<void (QNetworkAccessManager::*)(const QString &, quint16, const QSslConfiguration &, const QString &)>("connect_to_host_encrypted", &QNetworkAccessManager::connectToHostEncrypted, Arg("host_name"), Arg("port"), Arg("ssl_configuration"), Arg("peer_name"))
            .define_method("cookie_jar", &QNetworkAccessManager::cookieJar)
            .define_method("delete_resource", &QNetworkAccessManager::deleteResource, Arg("request"))
            .define_method("enable_strict_transport_security_store", &QNetworkAccessManager::enableStrictTransportSecurityStore, Arg("enabled"), Arg("store_dir") = static_cast<const QString &>(QString()))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &)>("get", &QNetworkAccessManager::get, Arg("request"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, QIODevice *)>("get", &QNetworkAccessManager::get, Arg("request"), Arg("data"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &)>("get", &QNetworkAccessManager::get, Arg("request"), Arg("data"))
            .define_method("head", &QNetworkAccessManager::head, Arg("request"))
            .define_method("strict_transport_security_enabled?", &QNetworkAccessManager::isStrictTransportSecurityEnabled)
            .define_method("strict_transport_security_store_enabled?", &QNetworkAccessManager::isStrictTransportSecurityStoreEnabled)
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, QHttpMultiPart *)>("post", &QNetworkAccessManager::post, Arg("request"), Arg("multi_part"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, QIODevice *)>("post", &QNetworkAccessManager::post, Arg("request"), Arg("data"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &)>("post", &QNetworkAccessManager::post, Arg("request"), Arg("data"))
            // .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, std::nullptr_t)>("post", &QNetworkAccessManager::post, Arg("request"), Arg("data"))
            .define_method("proxy", &QNetworkAccessManager::proxy)
            .define_method("proxy_factory", &QNetworkAccessManager::proxyFactory)
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, QHttpMultiPart *)>("put", &QNetworkAccessManager::put, Arg("request"), Arg("multi_part"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, QIODevice *)>("put", &QNetworkAccessManager::put, Arg("request"), Arg("data"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &)>("put", &QNetworkAccessManager::put, Arg("request"), Arg("data"))
            // .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, std::nullptr_t)>("put", &QNetworkAccessManager::put, Arg("request"), Arg("data"))
            .define_method("redirect_policy", &QNetworkAccessManager::redirectPolicy)
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &, QHttpMultiPart *)>("send_custom_request", &QNetworkAccessManager::sendCustomRequest, Arg("request"), Arg("verb"), Arg("multi_part"))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &, QIODevice *)>("send_custom_request", &QNetworkAccessManager::sendCustomRequest, Arg("request"), Arg("verb"), Arg("data") = static_cast<QIODevice *>(nullptr))
            .define_method<QNetworkReply *(QNetworkAccessManager::*)(const QNetworkRequest &, const QByteArray &, const QByteArray &)>("send_custom_request", &QNetworkAccessManager::sendCustomRequest, Arg("request"), Arg("verb"), Arg("data"))
            .define_method("set_auto_delete_replies", &QNetworkAccessManager::setAutoDeleteReplies, Arg("auto_delete"))
            .define_method("set_cache", &QNetworkAccessManager::setCache, Arg("cache"))
            .define_method("set_cookie_jar", &QNetworkAccessManager::setCookieJar, Arg("cookie_jar"))
            .define_method("set_proxy", &QNetworkAccessManager::setProxy, Arg("proxy"))
            .define_method("set_proxy_factory", &QNetworkAccessManager::setProxyFactory, Arg("factory"))
            .define_method("set_redirect_policy", &QNetworkAccessManager::setRedirectPolicy, Arg("policy"))
            .define_method("set_strict_transport_security_enabled", &QNetworkAccessManager::setStrictTransportSecurityEnabled, Arg("enabled"))
            .define_method<void (QNetworkAccessManager::*)(int)>("set_transfer_timeout", &QNetworkAccessManager::setTransferTimeout, Arg("timeout"))
            .define_method("strict_transport_security_hosts", &QNetworkAccessManager::strictTransportSecurityHosts)
            .define_method("supported_schemes", &QNetworkAccessManager::supportedSchemes)
            .define_method("transfer_timeout", &QNetworkAccessManager::transferTimeout)
            .define_method("transfer_timeout_as_duration", &QNetworkAccessManager::transferTimeoutAsDuration);
            // Signals
            // .define_method("authentication_required", &QNetworkAccessManager::authenticationRequired, Arg("reply"), Arg("authenticator"))
            // .define_method("encrypted", &QNetworkAccessManager::encrypted, Arg("reply"))
            // .define_method("finished", &QNetworkAccessManager::finished, Arg("reply"))
            // .define_method("pre_shared_key_authentication_required", &QNetworkAccessManager::preSharedKeyAuthenticationRequired, Arg("reply"), Arg("authenticator"))
            // .define_method("proxy_authentication_required", &QNetworkAccessManager::proxyAuthenticationRequired, Arg("proxy"), Arg("authenticator"))
            // .define_method("ssl_errors", &QNetworkAccessManager::sslErrors, Arg("reply"), Arg("errors"));

    Data_Type<QNetworkAccessManager::Operation> rb_cQNetworkAccessManagerOperation =
        // RubyQt6::QtNetwork::QNetworkAccessManager::Operation
        define_qenum_under<QNetworkAccessManager::Operation>(rb_cQNetworkAccessManager, "Operation");
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "HeadOperation", QNetworkAccessManager::Operation::HeadOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "GetOperation", QNetworkAccessManager::Operation::GetOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "PutOperation", QNetworkAccessManager::Operation::PutOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "PostOperation", QNetworkAccessManager::Operation::PostOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "DeleteOperation", QNetworkAccessManager::Operation::DeleteOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "CustomOperation", QNetworkAccessManager::Operation::CustomOperation);
        define_qenum_value_under(rb_cQNetworkAccessManagerOperation, "UnknownOperation", QNetworkAccessManager::Operation::UnknownOperation);
}
