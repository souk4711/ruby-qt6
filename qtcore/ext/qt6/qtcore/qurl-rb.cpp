#include "qurl-rb.hpp"
#include <qurl.h>

#include <QUrlQuery>

using namespace Rice;

Rice::Class rb_cQUrl;

void Init_qurl(Rice::Module rb_mQt6QtCore)
{
    rb_cQUrl =
        // Qt6::QtCore::QUrl
        define_class_under<QUrl>(rb_mQt6QtCore, "QUrl")
            .define_constructor(Constructor<QUrl>())
            .define_constructor(Constructor<QUrl, const QUrl &>(), Arg("copy"))
            .define_method<QUrl &(QUrl::*)(const QUrl &) noexcept>("assign", &QUrl::operator=, Arg("copy"))
            // TODO: .define_constructor(Constructor<QUrl, const QString &, QUrl::ParsingMode>(), Arg("url"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            .define_method<QUrl &(QUrl::*)(const QString &)>("assign", &QUrl::operator=, Arg("url"))
            .define_method("swap", &QUrl::swap, Arg("other"))
            // TODO: .define_method("set_url", &QUrl::setUrl, Arg("url"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            // TODO: .define_method("url", &QUrl::url, Arg("options") = static_cast<FormattingOptions>(FormattingOptions(PrettyDecoded)))
            // TODO: .define_method("to_string", &QUrl::toString, Arg("options") = static_cast<FormattingOptions>(FormattingOptions(PrettyDecoded)))
            // TODO: .define_method("to_display_string", &QUrl::toDisplayString, Arg("options") = static_cast<FormattingOptions>(FormattingOptions(PrettyDecoded)))
            .define_method("adjusted", &QUrl::adjusted, Arg("options"))
            // TODO: .define_method("to_encoded", &QUrl::toEncoded, Arg("options") = static_cast<FormattingOptions>(FullyEncoded))
            // TODO: .define_singleton_function("from_encoded", &QUrl::fromEncoded, Arg("input"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            // TODO: .define_singleton_function("from_user_input", &QUrl::fromUserInput, Arg("user_input"), Arg("working_directory") = static_cast<const QString &>(QString()), Arg("options") = static_cast<UserInputResolutionOptions>(DefaultResolution))
            .define_method("is_valid", &QUrl::isValid)
            .define_method("error_string", &QUrl::errorString)
            .define_method("is_empty", &QUrl::isEmpty)
            .define_method("clear", &QUrl::clear)
            .define_method("set_scheme", &QUrl::setScheme, Arg("scheme"))
            .define_method("scheme", &QUrl::scheme)
            // TODO: .define_method("set_authority", &QUrl::setAuthority, Arg("authority"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            // TODO: .define_method("authority", &QUrl::authority, Arg("options") = static_cast<ComponentFormattingOptions>(PrettyDecoded))
            // TODO: .define_method("set_user_info", &QUrl::setUserInfo, Arg("user_info"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            // TODO: .define_method("user_info", &QUrl::userInfo, Arg("options") = static_cast<ComponentFormattingOptions>(PrettyDecoded))
            // TODO: .define_method("set_user_name", &QUrl::setUserName, Arg("user_name"), Arg("mode") = static_cast<ParsingMode>(DecodedMode))
            // TODO: .define_method("user_name", &QUrl::userName, Arg("options") = static_cast<ComponentFormattingOptions>(FullyDecoded))
            // TODO: .define_method("set_password", &QUrl::setPassword, Arg("password"), Arg("mode") = static_cast<ParsingMode>(DecodedMode))
            // TODO: .define_method("password", &QUrl::password, Arg("") = static_cast<ComponentFormattingOptions>(FullyDecoded))
            // TODO: .define_method("set_host", &QUrl::setHost, Arg("host"), Arg("mode") = static_cast<ParsingMode>(DecodedMode))
            // TODO: .define_method("host", &QUrl::host, Arg("") = static_cast<ComponentFormattingOptions>(FullyDecoded))
            .define_method("set_port", &QUrl::setPort, Arg("port"))
            .define_method("port", &QUrl::port, Arg("default_port") = static_cast<int>(-1))
            // TODO: .define_method("set_path", &QUrl::setPath, Arg("path"), Arg("mode") = static_cast<ParsingMode>(DecodedMode))
            // TODO: .define_method("path", &QUrl::path, Arg("options") = static_cast<ComponentFormattingOptions>(FullyDecoded))
            // TODO: .define_method("file_name", &QUrl::fileName, Arg("options") = static_cast<ComponentFormattingOptions>(FullyDecoded))
            .define_method("has_query", &QUrl::hasQuery)
            // TODO: .define_method<void (QUrl::*)(const QString &, QUrl::ParsingMode)>("set_query", &QUrl::setQuery, Arg("query"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            .define_method<void (QUrl::*)(const QUrlQuery &)>("set_query", &QUrl::setQuery, Arg("query"))
            // TODO: .define_method("query", &QUrl::query, Arg("") = static_cast<ComponentFormattingOptions>(PrettyDecoded))
            .define_method("has_fragment", &QUrl::hasFragment)
            // TODO: .define_method("fragment", &QUrl::fragment, Arg("options") = static_cast<ComponentFormattingOptions>(PrettyDecoded))
            // TODO: .define_method("set_fragment", &QUrl::setFragment, Arg("fragment"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            .define_method("resolved", &QUrl::resolved, Arg("relative"))
            .define_method("is_relative", &QUrl::isRelative)
            .define_method("is_parent_of", &QUrl::isParentOf, Arg("url"))
            .define_method("is_local_file", &QUrl::isLocalFile)
            .define_singleton_function("from_local_file", &QUrl::fromLocalFile, Arg("localfile"))
            .define_method("to_local_file", &QUrl::toLocalFile)
            .define_method("detach", &QUrl::detach)
            .define_method("is_detached", &QUrl::isDetached)
            .define_method("matches", &QUrl::matches, Arg("url"), Arg("options"))
            .define_singleton_function("from_percent_encoding", &QUrl::fromPercentEncoding, Arg(""))
            .define_singleton_function("to_percent_encoding", &QUrl::toPercentEncoding, Arg(""), Arg("exclude") = static_cast<const QByteArray &>(QByteArray()), Arg("include") = static_cast<const QByteArray &>(QByteArray()))
            // TODO: .define_singleton_function("from_ace", &QUrl::fromAce, Arg("domain"), Arg("options") = static_cast<AceProcessingOptions>({}))
            // TODO: .define_singleton_function("to_ace", &QUrl::toAce, Arg("domain"), Arg("options") = static_cast<AceProcessingOptions>({}))
            .define_singleton_function("idn_whitelist", &QUrl::idnWhitelist)
            // TODO: .define_singleton_function("to_string_list", &QUrl::toStringList, Arg("uris"), Arg("options") = static_cast<FormattingOptions>(FormattingOptions(PrettyDecoded)))
            // TODO: .define_singleton_function("from_string_list", &QUrl::fromStringList, Arg("uris"), Arg("mode") = static_cast<ParsingMode>(TolerantMode))
            .define_singleton_function("set_idn_whitelist", &QUrl::setIdnWhitelist, Arg(""))
        // .define_method("data_ptr", &QUrl::data_ptr)
        ;

    // clang-format off
    Enum<QUrl::ParsingMode> rb_cQUrlParsingMode =
        // Qt6::QtCore::QUrl::ParsingMode
        define_enum_under<QUrl::ParsingMode>("ParsingMode", rb_cQUrl)
            .define_value("TolerantMode", QUrl::ParsingMode::TolerantMode)
            .define_value("StrictMode", QUrl::ParsingMode::StrictMode)
            .define_value("DecodedMode", QUrl::ParsingMode::DecodedMode);

    Enum<QUrl::UrlFormattingOption> rb_cQUrlUrlFormattingOption =
        // Qt6::QtCore::QUrl::UrlFormattingOption
        define_enum_under<QUrl::UrlFormattingOption>("UrlFormattingOption", rb_cQUrl)
            .define_value("None", QUrl::UrlFormattingOption::None)
            .define_value("RemoveScheme", QUrl::UrlFormattingOption::RemoveScheme)
            .define_value("RemovePassword", QUrl::UrlFormattingOption::RemovePassword)
            .define_value("RemoveUserInfo", QUrl::UrlFormattingOption::RemoveUserInfo)
            .define_value("RemovePort", QUrl::UrlFormattingOption::RemovePort)
            .define_value("RemoveAuthority", QUrl::UrlFormattingOption::RemoveAuthority)
            .define_value("RemovePath", QUrl::UrlFormattingOption::RemovePath)
            .define_value("RemoveQuery", QUrl::UrlFormattingOption::RemoveQuery)
            .define_value("RemoveFragment", QUrl::UrlFormattingOption::RemoveFragment)
            .define_value("PreferLocalFile", QUrl::UrlFormattingOption::PreferLocalFile)
            .define_value("StripTrailingSlash", QUrl::UrlFormattingOption::StripTrailingSlash)
            .define_value("RemoveFilename", QUrl::UrlFormattingOption::RemoveFilename)
            .define_value("NormalizePathSegments", QUrl::UrlFormattingOption::NormalizePathSegments);

    Enum<QUrl::ComponentFormattingOption> rb_cQUrlComponentFormattingOption =
        // Qt6::QtCore::QUrl::ComponentFormattingOption
        define_enum_under<QUrl::ComponentFormattingOption>("ComponentFormattingOption", rb_cQUrl)
            .define_value("PrettyDecoded", QUrl::ComponentFormattingOption::PrettyDecoded)
            .define_value("EncodeSpaces", QUrl::ComponentFormattingOption::EncodeSpaces)
            .define_value("EncodeUnicode", QUrl::ComponentFormattingOption::EncodeUnicode)
            .define_value("EncodeDelimiters", QUrl::ComponentFormattingOption::EncodeDelimiters)
            .define_value("EncodeReserved", QUrl::ComponentFormattingOption::EncodeReserved)
            .define_value("DecodeReserved", QUrl::ComponentFormattingOption::DecodeReserved)
            .define_value("FullyEncoded", QUrl::ComponentFormattingOption::FullyEncoded)
            .define_value("FullyDecoded", QUrl::ComponentFormattingOption::FullyDecoded);

    Enum<QUrl::UserInputResolutionOption> rb_cQUrlUserInputResolutionOption =
        // Qt6::QtCore::QUrl::UserInputResolutionOption
        define_enum_under<QUrl::UserInputResolutionOption>("UserInputResolutionOption", rb_cQUrl)
            .define_value("DefaultResolution", QUrl::UserInputResolutionOption::DefaultResolution)
            .define_value("AssumeLocalFile", QUrl::UserInputResolutionOption::AssumeLocalFile);

    Enum<QUrl::AceProcessingOption> rb_cQUrlAceProcessingOption =
        // Qt6::QtCore::QUrl::AceProcessingOption
        define_enum_under<QUrl::AceProcessingOption>("AceProcessingOption", rb_cQUrl)
            .define_value("IgnoreIDNWhitelist", QUrl::AceProcessingOption::IgnoreIDNWhitelist)
            .define_value("AceTransitionalProcessing", QUrl::AceProcessingOption::AceTransitionalProcessing);
}
