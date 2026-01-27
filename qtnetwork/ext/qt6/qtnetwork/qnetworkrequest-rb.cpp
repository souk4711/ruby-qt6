#include "qnetworkrequest-rb.hpp"
#include <qnetworkrequest.h>
#include <rice/qt6/qenum.hpp>

#include <QHttp1Configuration>
#include <QHttp2Configuration>
#include <QSslConfiguration>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQNetworkRequest;

void Init_qnetworkrequest(Module rb_mQt6QtNetwork)
{
    rb_cQNetworkRequest =
        // RubyQt6::QtNetwork::QNetworkRequest
        define_class_under<QNetworkRequest>(rb_mQt6QtNetwork, "QNetworkRequest")
            // Constructor
            .define_constructor(Constructor<QNetworkRequest>())
            .define_constructor(Constructor<QNetworkRequest, const QUrl &>(), Arg("url"))
            // Public Functions
            .define_method("attribute", &QNetworkRequest::attribute, Arg("code"), Arg("default_value") = static_cast<const QVariant &>(QVariant()))
            .define_method("decompressed_safety_check_threshold", &QNetworkRequest::decompressedSafetyCheckThreshold)
            .define_method("has_raw_header", &QNetworkRequest::hasRawHeader, Arg("header_name"))
            .define_method("header", &QNetworkRequest::header, Arg("header"))
            .define_method("headers", &QNetworkRequest::headers)
            .define_method("http1_configuration", &QNetworkRequest::http1Configuration)
            .define_method("http2_configuration", &QNetworkRequest::http2Configuration)
            .define_method("maximum_redirects_allowed", &QNetworkRequest::maximumRedirectsAllowed)
            .define_method("originating_object", &QNetworkRequest::originatingObject)
            .define_method("peer_verify_name", &QNetworkRequest::peerVerifyName)
            .define_method("priority", &QNetworkRequest::priority)
            .define_method("raw_header", &QNetworkRequest::rawHeader, Arg("header_name"))
            .define_method("raw_header_list", &QNetworkRequest::rawHeaderList)
            .define_method("set_attribute", &QNetworkRequest::setAttribute, Arg("code"), Arg("value"))
            .define_method("set_decompressed_safety_check_threshold", &QNetworkRequest::setDecompressedSafetyCheckThreshold, Arg("threshold"))
            .define_method("set_header", &QNetworkRequest::setHeader, Arg("header"), Arg("value"))
            .define_method<void (QNetworkRequest::*)(QHttpHeaders &&)>("set_headers", &QNetworkRequest::setHeaders, Arg("new_headers"))
            .define_method<void (QNetworkRequest::*)(const QHttpHeaders &)>("set_headers", &QNetworkRequest::setHeaders, Arg("new_headers"))
            .define_method("set_http1_configuration", &QNetworkRequest::setHttp1Configuration, Arg("configuration"))
            .define_method("set_http2_configuration", &QNetworkRequest::setHttp2Configuration, Arg("configuration"))
            .define_method("set_maximum_redirects_allowed", &QNetworkRequest::setMaximumRedirectsAllowed, Arg("maximum_redirects_allowed"))
            .define_method("set_originating_object", &QNetworkRequest::setOriginatingObject, Arg("object"))
            .define_method("set_peer_verify_name", &QNetworkRequest::setPeerVerifyName, Arg("peer_name"))
            .define_method("set_priority", &QNetworkRequest::setPriority, Arg("priority"))
            .define_method("_set_raw_header", &QNetworkRequest::setRawHeader, Arg("header_name"), Arg("value"))
            .define_method("set_ssl_configuration", &QNetworkRequest::setSslConfiguration, Arg("configuration"))
            .define_method<void (QNetworkRequest::*)(int)>("set_transfer_timeout", &QNetworkRequest::setTransferTimeout, Arg("timeout"))
            .define_method<void (QNetworkRequest::*)(std::chrono::milliseconds)>("set_transfer_timeout", &QNetworkRequest::setTransferTimeout, Arg("duration") = static_cast<std::chrono::milliseconds>(QNetworkRequest::DefaultTransferTimeout))
            .define_method("set_url", &QNetworkRequest::setUrl, Arg("url"))
            .define_method("ssl_configuration", &QNetworkRequest::sslConfiguration)
            .define_method("transfer_timeout", &QNetworkRequest::transferTimeout)
            .define_method("transfer_timeout_as_duration", &QNetworkRequest::transferTimeoutAsDuration)
            .define_method("url", &QNetworkRequest::url);

    Data_Type<QNetworkRequest::Attribute> rb_cQNetworkRequestAttribute =
        // RubyQt6::QtNetwork::QNetworkRequest::Attribute
        define_qenum_under<QNetworkRequest::Attribute>(rb_cQNetworkRequest, "Attribute");
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "HttpStatusCodeAttribute", QNetworkRequest::Attribute::HttpStatusCodeAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "HttpReasonPhraseAttribute", QNetworkRequest::Attribute::HttpReasonPhraseAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "RedirectionTargetAttribute", QNetworkRequest::Attribute::RedirectionTargetAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "ConnectionEncryptedAttribute", QNetworkRequest::Attribute::ConnectionEncryptedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "CacheLoadControlAttribute", QNetworkRequest::Attribute::CacheLoadControlAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "CacheSaveControlAttribute", QNetworkRequest::Attribute::CacheSaveControlAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "SourceIsFromCacheAttribute", QNetworkRequest::Attribute::SourceIsFromCacheAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "DoNotBufferUploadDataAttribute", QNetworkRequest::Attribute::DoNotBufferUploadDataAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "HttpPipeliningAllowedAttribute", QNetworkRequest::Attribute::HttpPipeliningAllowedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "HttpPipeliningWasUsedAttribute", QNetworkRequest::Attribute::HttpPipeliningWasUsedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "CustomVerbAttribute", QNetworkRequest::Attribute::CustomVerbAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "CookieLoadControlAttribute", QNetworkRequest::Attribute::CookieLoadControlAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "AuthenticationReuseAttribute", QNetworkRequest::Attribute::AuthenticationReuseAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "CookieSaveControlAttribute", QNetworkRequest::Attribute::CookieSaveControlAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "MaximumDownloadBufferSizeAttribute", QNetworkRequest::Attribute::MaximumDownloadBufferSizeAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "DownloadBufferAttribute", QNetworkRequest::Attribute::DownloadBufferAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "SynchronousRequestAttribute", QNetworkRequest::Attribute::SynchronousRequestAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "BackgroundRequestAttribute", QNetworkRequest::Attribute::BackgroundRequestAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "EmitAllUploadProgressSignalsAttribute", QNetworkRequest::Attribute::EmitAllUploadProgressSignalsAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "Http2AllowedAttribute", QNetworkRequest::Attribute::Http2AllowedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "Http2WasUsedAttribute", QNetworkRequest::Attribute::Http2WasUsedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "OriginalContentLengthAttribute", QNetworkRequest::Attribute::OriginalContentLengthAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "RedirectPolicyAttribute", QNetworkRequest::Attribute::RedirectPolicyAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "Http2DirectAttribute", QNetworkRequest::Attribute::Http2DirectAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "ResourceTypeAttribute", QNetworkRequest::Attribute::ResourceTypeAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "AutoDeleteReplyOnFinishAttribute", QNetworkRequest::Attribute::AutoDeleteReplyOnFinishAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "ConnectionCacheExpiryTimeoutSecondsAttribute", QNetworkRequest::Attribute::ConnectionCacheExpiryTimeoutSecondsAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "Http2CleartextAllowedAttribute", QNetworkRequest::Attribute::Http2CleartextAllowedAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "UseCredentialsAttribute", QNetworkRequest::Attribute::UseCredentialsAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "FullLocalServerNameAttribute", QNetworkRequest::Attribute::FullLocalServerNameAttribute);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "User", QNetworkRequest::Attribute::User);
        define_qenum_value_under(rb_cQNetworkRequestAttribute, "UserMax", QNetworkRequest::Attribute::UserMax);

    Data_Type<QNetworkRequest::CacheLoadControl> rb_cQNetworkRequestCacheLoadControl =
        // RubyQt6::QtNetwork::QNetworkRequest::CacheLoadControl
        define_qenum_under<QNetworkRequest::CacheLoadControl>(rb_cQNetworkRequest, "CacheLoadControl");
        define_qenum_value_under(rb_cQNetworkRequestCacheLoadControl, "AlwaysNetwork", QNetworkRequest::CacheLoadControl::AlwaysNetwork);
        define_qenum_value_under(rb_cQNetworkRequestCacheLoadControl, "PreferNetwork", QNetworkRequest::CacheLoadControl::PreferNetwork);
        define_qenum_value_under(rb_cQNetworkRequestCacheLoadControl, "PreferCache", QNetworkRequest::CacheLoadControl::PreferCache);
        define_qenum_value_under(rb_cQNetworkRequestCacheLoadControl, "AlwaysCache", QNetworkRequest::CacheLoadControl::AlwaysCache);

    Data_Type<QNetworkRequest::KnownHeaders> rb_cQNetworkRequestKnownHeaders =
        // RubyQt6::QtNetwork::QNetworkRequest::KnownHeaders
        define_qenum_under<QNetworkRequest::KnownHeaders>(rb_cQNetworkRequest, "KnownHeaders");
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "ContentTypeHeader", QNetworkRequest::KnownHeaders::ContentTypeHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "ContentLengthHeader", QNetworkRequest::KnownHeaders::ContentLengthHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "LocationHeader", QNetworkRequest::KnownHeaders::LocationHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "LastModifiedHeader", QNetworkRequest::KnownHeaders::LastModifiedHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "CookieHeader", QNetworkRequest::KnownHeaders::CookieHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "SetCookieHeader", QNetworkRequest::KnownHeaders::SetCookieHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "ContentDispositionHeader", QNetworkRequest::KnownHeaders::ContentDispositionHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "UserAgentHeader", QNetworkRequest::KnownHeaders::UserAgentHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "ServerHeader", QNetworkRequest::KnownHeaders::ServerHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "IfModifiedSinceHeader", QNetworkRequest::KnownHeaders::IfModifiedSinceHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "ETagHeader", QNetworkRequest::KnownHeaders::ETagHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "IfMatchHeader", QNetworkRequest::KnownHeaders::IfMatchHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "IfNoneMatchHeader", QNetworkRequest::KnownHeaders::IfNoneMatchHeader);
        define_qenum_value_under(rb_cQNetworkRequestKnownHeaders, "NumKnownHeaders", QNetworkRequest::KnownHeaders::NumKnownHeaders);

    Data_Type<QNetworkRequest::LoadControl> rb_cQNetworkRequestLoadControl =
        // RubyQt6::QtNetwork::QNetworkRequest::LoadControl
        define_qenum_under<QNetworkRequest::LoadControl>(rb_cQNetworkRequest, "LoadControl");
        define_qenum_value_under(rb_cQNetworkRequestLoadControl, "Automatic", QNetworkRequest::LoadControl::Automatic);
        define_qenum_value_under(rb_cQNetworkRequestLoadControl, "Manual", QNetworkRequest::LoadControl::Manual);

    Data_Type<QNetworkRequest::Priority> rb_cQNetworkRequestPriority =
        // RubyQt6::QtNetwork::QNetworkRequest::Priority
        define_qenum_under<QNetworkRequest::Priority>(rb_cQNetworkRequest, "Priority");
        define_qenum_value_under(rb_cQNetworkRequestPriority, "HighPriority", QNetworkRequest::Priority::HighPriority);
        define_qenum_value_under(rb_cQNetworkRequestPriority, "NormalPriority", QNetworkRequest::Priority::NormalPriority);
        define_qenum_value_under(rb_cQNetworkRequestPriority, "LowPriority", QNetworkRequest::Priority::LowPriority);

    Data_Type<QNetworkRequest::RedirectPolicy> rb_cQNetworkRequestRedirectPolicy =
        // RubyQt6::QtNetwork::QNetworkRequest::RedirectPolicy
        define_qenum_under<QNetworkRequest::RedirectPolicy>(rb_cQNetworkRequest, "RedirectPolicy");
        define_qenum_value_under(rb_cQNetworkRequestRedirectPolicy, "ManualRedirectPolicy", QNetworkRequest::RedirectPolicy::ManualRedirectPolicy);
        define_qenum_value_under(rb_cQNetworkRequestRedirectPolicy, "NoLessSafeRedirectPolicy", QNetworkRequest::RedirectPolicy::NoLessSafeRedirectPolicy);
        define_qenum_value_under(rb_cQNetworkRequestRedirectPolicy, "SameOriginRedirectPolicy", QNetworkRequest::RedirectPolicy::SameOriginRedirectPolicy);
        define_qenum_value_under(rb_cQNetworkRequestRedirectPolicy, "UserVerifiedRedirectPolicy", QNetworkRequest::RedirectPolicy::UserVerifiedRedirectPolicy);

    Data_Type<QNetworkRequest::TransferTimeoutConstant> rb_cQNetworkRequestTransferTimeoutConstant =
        // RubyQt6::QtNetwork::QNetworkRequest::TransferTimeoutConstant
        define_qenum_under<QNetworkRequest::TransferTimeoutConstant>(rb_cQNetworkRequest, "TransferTimeoutConstant");
        define_qenum_value_under(rb_cQNetworkRequestTransferTimeoutConstant, "DefaultTransferTimeoutConstant", QNetworkRequest::TransferTimeoutConstant::DefaultTransferTimeoutConstant);
}
