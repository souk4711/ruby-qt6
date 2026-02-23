#include "qnetworkreply-rb.hpp"
#include <qnetworkreply.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQNetworkReply;

void Init_qnetworkreply(Module rb_mQt6QtNetwork)
{
    rb_cQNetworkReply =
        // RubyQt6::QtNetwork::QNetworkReply
        define_qlass_under<QNetworkReply, QIODevice>(rb_mQt6QtNetwork, "QNetworkReply")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QNetworkReply *>(); })
            .define_singleton_function("_qvariant_from_value", [](QNetworkReply *value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QNetworkReply * { return qvariant.value<QNetworkReply *>(); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QNetworkReply::staticMetaObject; })
            // Public Functions
            .define_method("attribute", &QNetworkReply::attribute, Arg("code"))
            .define_method("close", &QNetworkReply::close)
            .define_method("error", &QNetworkReply::error)
            .define_method("has_raw_header", &QNetworkReply::hasRawHeader, Arg("header_name"))
            .define_method("header", &QNetworkReply::header, Arg("header"))
            .define_method("headers", &QNetworkReply::headers)
            .define_method<void (QNetworkReply::*)(const QList<QSslError> &)>("ignore_ssl_errors", &QNetworkReply::ignoreSslErrors, Arg("errors"))
            .define_method("finished?", &QNetworkReply::isFinished)
            .define_method("running?", &QNetworkReply::isRunning)
            .define_method("sequential?", &QNetworkReply::isSequential)
            .define_method("manager", &QNetworkReply::manager)
            .define_method("operation", &QNetworkReply::operation)
            .define_method("raw_header", &QNetworkReply::rawHeader, Arg("header_name"))
            .define_method("raw_header_list", &QNetworkReply::rawHeaderList)
            .define_method("raw_header_pairs", &QNetworkReply::rawHeaderPairs)
            .define_method("read_buffer_size", &QNetworkReply::readBufferSize)
            .define_method("request", &QNetworkReply::request)
            .define_method("set_read_buffer_size", &QNetworkReply::setReadBufferSize, Arg("size"))
            .define_method("set_ssl_configuration", &QNetworkReply::setSslConfiguration, Arg("configuration"))
            .define_method("ssl_configuration", &QNetworkReply::sslConfiguration)
            .define_method("url", &QNetworkReply::url)
            // Public Slots
            .define_method("abort", &QNetworkReply::abort)
            .define_method<void (QNetworkReply::*)()>("ignore_ssl_errors", &QNetworkReply::ignoreSslErrors);
            // Signals
            // .define_method("download_progress", &QNetworkReply::downloadProgress, Arg("bytes_received"), Arg("bytes_total"))
            // .define_method("encrypted", &QNetworkReply::encrypted)
            // .define_method("error_occurred", &QNetworkReply::errorOccurred, Arg("code"))
            // .define_method("finished", &QNetworkReply::finished)
            // .define_method("meta_data_changed", &QNetworkReply::metaDataChanged)
            // .define_method("pre_shared_key_authentication_required", &QNetworkReply::preSharedKeyAuthenticationRequired, Arg("authenticator"))
            // .define_method("redirect_allowed", &QNetworkReply::redirectAllowed)
            // .define_method("redirected", &QNetworkReply::redirected, Arg("url"))
            // .define_method("request_sent", &QNetworkReply::requestSent)
            // .define_method("socket_started_connecting", &QNetworkReply::socketStartedConnecting)
            // .define_method("ssl_errors", &QNetworkReply::sslErrors, Arg("errors"))
            // .define_method("upload_progress", &QNetworkReply::uploadProgress, Arg("bytes_sent"), Arg("bytes_total"));

    Data_Type<QNetworkReply::NetworkError> rb_cQNetworkReplyNetworkError =
        // RubyQt6::QtNetwork::QNetworkReply::NetworkError
        define_qenum_under<QNetworkReply::NetworkError>(rb_cQNetworkReply, "NetworkError");
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "NoError", QNetworkReply::NetworkError::NoError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ConnectionRefusedError", QNetworkReply::NetworkError::ConnectionRefusedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "RemoteHostClosedError", QNetworkReply::NetworkError::RemoteHostClosedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "HostNotFoundError", QNetworkReply::NetworkError::HostNotFoundError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "TimeoutError", QNetworkReply::NetworkError::TimeoutError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "OperationCanceledError", QNetworkReply::NetworkError::OperationCanceledError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "SslHandshakeFailedError", QNetworkReply::NetworkError::SslHandshakeFailedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "TemporaryNetworkFailureError", QNetworkReply::NetworkError::TemporaryNetworkFailureError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "NetworkSessionFailedError", QNetworkReply::NetworkError::NetworkSessionFailedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "BackgroundRequestNotAllowedError", QNetworkReply::NetworkError::BackgroundRequestNotAllowedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "TooManyRedirectsError", QNetworkReply::NetworkError::TooManyRedirectsError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "InsecureRedirectError", QNetworkReply::NetworkError::InsecureRedirectError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "UnknownNetworkError", QNetworkReply::NetworkError::UnknownNetworkError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProxyConnectionRefusedError", QNetworkReply::NetworkError::ProxyConnectionRefusedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProxyConnectionClosedError", QNetworkReply::NetworkError::ProxyConnectionClosedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProxyNotFoundError", QNetworkReply::NetworkError::ProxyNotFoundError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProxyTimeoutError", QNetworkReply::NetworkError::ProxyTimeoutError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProxyAuthenticationRequiredError", QNetworkReply::NetworkError::ProxyAuthenticationRequiredError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "UnknownProxyError", QNetworkReply::NetworkError::UnknownProxyError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentAccessDenied", QNetworkReply::NetworkError::ContentAccessDenied);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentOperationNotPermittedError", QNetworkReply::NetworkError::ContentOperationNotPermittedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentNotFoundError", QNetworkReply::NetworkError::ContentNotFoundError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "AuthenticationRequiredError", QNetworkReply::NetworkError::AuthenticationRequiredError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentReSendError", QNetworkReply::NetworkError::ContentReSendError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentConflictError", QNetworkReply::NetworkError::ContentConflictError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ContentGoneError", QNetworkReply::NetworkError::ContentGoneError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "UnknownContentError", QNetworkReply::NetworkError::UnknownContentError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProtocolUnknownError", QNetworkReply::NetworkError::ProtocolUnknownError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProtocolInvalidOperationError", QNetworkReply::NetworkError::ProtocolInvalidOperationError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ProtocolFailure", QNetworkReply::NetworkError::ProtocolFailure);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "InternalServerError", QNetworkReply::NetworkError::InternalServerError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "OperationNotImplementedError", QNetworkReply::NetworkError::OperationNotImplementedError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "ServiceUnavailableError", QNetworkReply::NetworkError::ServiceUnavailableError);
        define_qenum_value_under(rb_cQNetworkReplyNetworkError, "UnknownServerError", QNetworkReply::NetworkError::UnknownServerError);
}
