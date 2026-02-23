#include "qnetworkproxy-rb.hpp"
#include <qnetworkproxy.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQNetworkProxy;
Class rb_cQNetworkProxyFactory;
Class rb_cQNetworkProxyQuery;

void Init_qnetworkproxy(Module rb_mQt6QtNetwork)
{
    rb_cQNetworkProxy =
        // RubyQt6::QtNetwork::QNetworkProxy
        define_qlass_under<QNetworkProxy>(rb_mQt6QtNetwork, "QNetworkProxy")
            // Constructor
            .define_constructor(Constructor<QNetworkProxy>())
            // Public Functions
            .define_method("capabilities", &QNetworkProxy::capabilities)
            .define_method("has_raw_header", &QNetworkProxy::hasRawHeader, Arg("header_name"))
            .define_method("header", &QNetworkProxy::header, Arg("header"))
            .define_method("headers", &QNetworkProxy::headers)
            .define_method("host_name", &QNetworkProxy::hostName)
            .define_method("caching_proxy?", &QNetworkProxy::isCachingProxy)
            .define_method("transparent_proxy?", &QNetworkProxy::isTransparentProxy)
            .define_method("password", &QNetworkProxy::password)
            .define_method("port", &QNetworkProxy::port)
            .define_method("raw_header", &QNetworkProxy::rawHeader, Arg("header_name"))
            .define_method("raw_header_list", &QNetworkProxy::rawHeaderList)
            .define_method("set_capabilities", &QNetworkProxy::setCapabilities, Arg("capab"))
            .define_method("set_header", &QNetworkProxy::setHeader, Arg("header"), Arg("value"))
            .define_method<void (QNetworkProxy::*)(QHttpHeaders &&)>("set_headers", &QNetworkProxy::setHeaders, Arg("new_headers"))
            .define_method<void (QNetworkProxy::*)(const QHttpHeaders &)>("set_headers", &QNetworkProxy::setHeaders, Arg("new_headers"))
            .define_method("set_host_name", &QNetworkProxy::setHostName, Arg("host_name"))
            .define_method("set_password", &QNetworkProxy::setPassword, Arg("password"))
            .define_method("set_port", &QNetworkProxy::setPort, Arg("port"))
            .define_method("set_raw_header", &QNetworkProxy::setRawHeader, Arg("header_name"), Arg("value"))
            .define_method("set_type", &QNetworkProxy::setType, Arg("type"))
            .define_method("set_user", &QNetworkProxy::setUser, Arg("user_name"))
            .define_method("type", &QNetworkProxy::type)
            .define_method("user", &QNetworkProxy::user)
            // Static Public Members
            .define_singleton_function("application_proxy", &QNetworkProxy::applicationProxy)
            .define_singleton_function("set_application_proxy", &QNetworkProxy::setApplicationProxy, Arg("proxy"));

    Data_Type<QNetworkProxy::Capability> rb_cQNetworkProxyCapability =
        // RubyQt6::QtNetwork::QNetworkProxy::Capability
        define_qenum_under<QNetworkProxy::Capability>(rb_cQNetworkProxy, "Capability");
        define_qenum_value_under(rb_cQNetworkProxyCapability, "TunnelingCapability", QNetworkProxy::Capability::TunnelingCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "ListeningCapability", QNetworkProxy::Capability::ListeningCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "UdpTunnelingCapability", QNetworkProxy::Capability::UdpTunnelingCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "CachingCapability", QNetworkProxy::Capability::CachingCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "HostNameLookupCapability", QNetworkProxy::Capability::HostNameLookupCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "SctpTunnelingCapability", QNetworkProxy::Capability::SctpTunnelingCapability);
        define_qenum_value_under(rb_cQNetworkProxyCapability, "SctpListeningCapability", QNetworkProxy::Capability::SctpListeningCapability);

    Data_Type<QNetworkProxy::ProxyType> rb_cQNetworkProxyProxyType =
        // RubyQt6::QtNetwork::QNetworkProxy::ProxyType
        define_qenum_under<QNetworkProxy::ProxyType>(rb_cQNetworkProxy, "ProxyType");
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "DefaultProxy", QNetworkProxy::ProxyType::DefaultProxy);
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "Socks5Proxy", QNetworkProxy::ProxyType::Socks5Proxy);
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "NoProxy", QNetworkProxy::ProxyType::NoProxy);
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "HttpProxy", QNetworkProxy::ProxyType::HttpProxy);
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "HttpCachingProxy", QNetworkProxy::ProxyType::HttpCachingProxy);
        define_qenum_value_under(rb_cQNetworkProxyProxyType, "FtpCachingProxy", QNetworkProxy::ProxyType::FtpCachingProxy);

    Data_Type<QFlags<QNetworkProxy::Capability>> rb_cQNetworkProxyCapabilities =
        // RubyQt6::QtNetwork::QNetworkProxy::Capabilities
        define_qflags_under<QNetworkProxy::Capability>(rb_cQNetworkProxy, "Capabilities");

    rb_cQNetworkProxyFactory =
        // RubyQt6::QtNetwork::QNetworkProxyFactory
        define_qlass_under<QNetworkProxyFactory>(rb_mQt6QtNetwork, "QNetworkProxyFactory")
            // Public Functions
            .define_method("query_proxy", &QNetworkProxyFactory::queryProxy, Arg("query") = static_cast<const QNetworkProxyQuery &>(QNetworkProxyQuery()))
            // Static Public Members
            .define_singleton_function("proxy_for_query", &QNetworkProxyFactory::proxyForQuery, Arg("query"))
            .define_singleton_function("set_application_proxy_factory", &QNetworkProxyFactory::setApplicationProxyFactory, Arg("factory"))
            .define_singleton_function("set_use_system_configuration", &QNetworkProxyFactory::setUseSystemConfiguration, Arg("enable"))
            .define_singleton_function("system_proxy_for_query", &QNetworkProxyFactory::systemProxyForQuery, Arg("query") = static_cast<const QNetworkProxyQuery &>(QNetworkProxyQuery()))
            .define_singleton_function("uses_system_configuration", &QNetworkProxyFactory::usesSystemConfiguration);

    rb_cQNetworkProxyQuery =
        // RubyQt6::QtNetwork::QNetworkProxyQuery
        define_qlass_under<QNetworkProxyQuery>(rb_mQt6QtNetwork, "QNetworkProxyQuery")
            // Constructor
            .define_constructor(Constructor<QNetworkProxyQuery>())
            // Public Functions
            .define_method("local_port", &QNetworkProxyQuery::localPort)
            .define_method("peer_host_name", &QNetworkProxyQuery::peerHostName)
            .define_method("peer_port", &QNetworkProxyQuery::peerPort)
            .define_method("protocol_tag", &QNetworkProxyQuery::protocolTag)
            .define_method("query_type", &QNetworkProxyQuery::queryType)
            .define_method("set_local_port", &QNetworkProxyQuery::setLocalPort, Arg("port"))
            .define_method("set_peer_host_name", &QNetworkProxyQuery::setPeerHostName, Arg("hostname"))
            .define_method("set_peer_port", &QNetworkProxyQuery::setPeerPort, Arg("port"))
            .define_method("set_protocol_tag", &QNetworkProxyQuery::setProtocolTag, Arg("protocol_tag"))
            .define_method("set_query_type", &QNetworkProxyQuery::setQueryType, Arg("type"))
            .define_method("set_url", &QNetworkProxyQuery::setUrl, Arg("url"))
            .define_method("url", &QNetworkProxyQuery::url);

    Data_Type<QNetworkProxyQuery::QueryType> rb_cQNetworkProxyQueryQueryType =
        // RubyQt6::QtNetwork::QNetworkProxyQuery::QueryType
        define_qenum_under<QNetworkProxyQuery::QueryType>(rb_cQNetworkProxyQuery, "QueryType");
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "TcpSocket", QNetworkProxyQuery::QueryType::TcpSocket);
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "UdpSocket", QNetworkProxyQuery::QueryType::UdpSocket);
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "SctpSocket", QNetworkProxyQuery::QueryType::SctpSocket);
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "TcpServer", QNetworkProxyQuery::QueryType::TcpServer);
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "UrlRequest", QNetworkProxyQuery::QueryType::UrlRequest);
        define_qenum_value_under(rb_cQNetworkProxyQueryQueryType, "SctpServer", QNetworkProxyQuery::QueryType::SctpServer);
}
