#include "qwebenginesettings-rb.hpp"
#include <qwebenginesettings.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineSettings;

void Init_qwebenginesettings(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineSettings =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings
        define_class_under<QWebEngineSettings>(rb_mQt6QtWebEngineCore, "QWebEngineSettings")
            // Public Functions
            .define_method("default_text_encoding", &QWebEngineSettings::defaultTextEncoding)
            .define_method("font_family", &QWebEngineSettings::fontFamily, Arg("which"))
            .define_method("font_size", &QWebEngineSettings::fontSize, Arg("type"))
            .define_method("image_animation_policy", &QWebEngineSettings::imageAnimationPolicy)
            .define_method("reset_attribute", &QWebEngineSettings::resetAttribute, Arg("attr"))
            .define_method("reset_font_family", &QWebEngineSettings::resetFontFamily, Arg("which"))
            .define_method("reset_font_size", &QWebEngineSettings::resetFontSize, Arg("type"))
            .define_method("reset_image_animation_policy", &QWebEngineSettings::resetImageAnimationPolicy)
            .define_method("reset_unknown_url_scheme_policy", &QWebEngineSettings::resetUnknownUrlSchemePolicy)
            .define_method("set_attribute", &QWebEngineSettings::setAttribute, Arg("attr"), Arg("on"))
            .define_method("set_default_text_encoding", &QWebEngineSettings::setDefaultTextEncoding, Arg("encoding"))
            .define_method("set_font_family", &QWebEngineSettings::setFontFamily, Arg("which"), Arg("family"))
            .define_method("set_font_size", &QWebEngineSettings::setFontSize, Arg("type"), Arg("size"))
            .define_method("set_image_animation_policy", &QWebEngineSettings::setImageAnimationPolicy, Arg("policy"))
            .define_method("set_unknown_url_scheme_policy", &QWebEngineSettings::setUnknownUrlSchemePolicy, Arg("policy"))
            .define_method("test_attribute", &QWebEngineSettings::testAttribute, Arg("attr"))
            .define_method("unknown_url_scheme_policy", &QWebEngineSettings::unknownUrlSchemePolicy);

    Data_Type<QWebEngineSettings::FontFamily> rb_cQWebEngineSettingsFontFamily =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings::FontFamily
        define_qenum_under<QWebEngineSettings::FontFamily>(rb_cQWebEngineSettings, "FontFamily");
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "StandardFont", QWebEngineSettings::FontFamily::StandardFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "FixedFont", QWebEngineSettings::FontFamily::FixedFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "SerifFont", QWebEngineSettings::FontFamily::SerifFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "SansSerifFont", QWebEngineSettings::FontFamily::SansSerifFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "CursiveFont", QWebEngineSettings::FontFamily::CursiveFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "FantasyFont", QWebEngineSettings::FontFamily::FantasyFont);
        define_qenum_value_under(rb_cQWebEngineSettingsFontFamily, "PictographFont", QWebEngineSettings::FontFamily::PictographFont);

    Data_Type<QWebEngineSettings::FontSize> rb_cQWebEngineSettingsFontSize =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings::FontSize
        define_qenum_under<QWebEngineSettings::FontSize>(rb_cQWebEngineSettings, "FontSize");
        define_qenum_value_under(rb_cQWebEngineSettingsFontSize, "MinimumFontSize", QWebEngineSettings::FontSize::MinimumFontSize);
        define_qenum_value_under(rb_cQWebEngineSettingsFontSize, "MinimumLogicalFontSize", QWebEngineSettings::FontSize::MinimumLogicalFontSize);
        define_qenum_value_under(rb_cQWebEngineSettingsFontSize, "DefaultFontSize", QWebEngineSettings::FontSize::DefaultFontSize);
        define_qenum_value_under(rb_cQWebEngineSettingsFontSize, "DefaultFixedFontSize", QWebEngineSettings::FontSize::DefaultFixedFontSize);

    Data_Type<QWebEngineSettings::ImageAnimationPolicy> rb_cQWebEngineSettingsImageAnimationPolicy =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings::ImageAnimationPolicy
        define_qenum_under<QWebEngineSettings::ImageAnimationPolicy>(rb_cQWebEngineSettings, "ImageAnimationPolicy");
        define_qenum_value_under(rb_cQWebEngineSettingsImageAnimationPolicy, "Inherited", QWebEngineSettings::ImageAnimationPolicy::Inherited);
        define_qenum_value_under(rb_cQWebEngineSettingsImageAnimationPolicy, "Allow", QWebEngineSettings::ImageAnimationPolicy::Allow);
        define_qenum_value_under(rb_cQWebEngineSettingsImageAnimationPolicy, "AnimateOnce", QWebEngineSettings::ImageAnimationPolicy::AnimateOnce);
        define_qenum_value_under(rb_cQWebEngineSettingsImageAnimationPolicy, "Disallow", QWebEngineSettings::ImageAnimationPolicy::Disallow);

    Data_Type<QWebEngineSettings::UnknownUrlSchemePolicy> rb_cQWebEngineSettingsUnknownUrlSchemePolicy =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings::UnknownUrlSchemePolicy
        define_qenum_under<QWebEngineSettings::UnknownUrlSchemePolicy>(rb_cQWebEngineSettings, "UnknownUrlSchemePolicy");
        define_qenum_value_under(rb_cQWebEngineSettingsUnknownUrlSchemePolicy, "InheritedUnknownUrlSchemePolicy", QWebEngineSettings::UnknownUrlSchemePolicy::InheritedUnknownUrlSchemePolicy);
        define_qenum_value_under(rb_cQWebEngineSettingsUnknownUrlSchemePolicy, "DisallowUnknownUrlSchemes", QWebEngineSettings::UnknownUrlSchemePolicy::DisallowUnknownUrlSchemes);
        define_qenum_value_under(rb_cQWebEngineSettingsUnknownUrlSchemePolicy, "AllowUnknownUrlSchemesFromUserInteraction", QWebEngineSettings::UnknownUrlSchemePolicy::AllowUnknownUrlSchemesFromUserInteraction);
        define_qenum_value_under(rb_cQWebEngineSettingsUnknownUrlSchemePolicy, "AllowAllUnknownUrlSchemes", QWebEngineSettings::UnknownUrlSchemePolicy::AllowAllUnknownUrlSchemes);

    Data_Type<QWebEngineSettings::WebAttribute> rb_cQWebEngineSettingsWebAttribute =
        // RubyQt6::QtWebEngineCore::QWebEngineSettings::WebAttribute
        define_qenum_under<QWebEngineSettings::WebAttribute>(rb_cQWebEngineSettings, "WebAttribute");
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "AutoLoadImages", QWebEngineSettings::WebAttribute::AutoLoadImages);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "JavascriptEnabled", QWebEngineSettings::WebAttribute::JavascriptEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "JavascriptCanOpenWindows", QWebEngineSettings::WebAttribute::JavascriptCanOpenWindows);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "JavascriptCanAccessClipboard", QWebEngineSettings::WebAttribute::JavascriptCanAccessClipboard);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "LinksIncludedInFocusChain", QWebEngineSettings::WebAttribute::LinksIncludedInFocusChain);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "LocalStorageEnabled", QWebEngineSettings::WebAttribute::LocalStorageEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "LocalContentCanAccessRemoteUrls", QWebEngineSettings::WebAttribute::LocalContentCanAccessRemoteUrls);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "XSSAuditingEnabled", QWebEngineSettings::WebAttribute::XSSAuditingEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "SpatialNavigationEnabled", QWebEngineSettings::WebAttribute::SpatialNavigationEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "LocalContentCanAccessFileUrls", QWebEngineSettings::WebAttribute::LocalContentCanAccessFileUrls);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "HyperlinkAuditingEnabled", QWebEngineSettings::WebAttribute::HyperlinkAuditingEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ScrollAnimatorEnabled", QWebEngineSettings::WebAttribute::ScrollAnimatorEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ErrorPageEnabled", QWebEngineSettings::WebAttribute::ErrorPageEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PluginsEnabled", QWebEngineSettings::WebAttribute::PluginsEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "FullScreenSupportEnabled", QWebEngineSettings::WebAttribute::FullScreenSupportEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ScreenCaptureEnabled", QWebEngineSettings::WebAttribute::ScreenCaptureEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "WebGLEnabled", QWebEngineSettings::WebAttribute::WebGLEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "Accelerated2dCanvasEnabled", QWebEngineSettings::WebAttribute::Accelerated2dCanvasEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "AutoLoadIconsForPage", QWebEngineSettings::WebAttribute::AutoLoadIconsForPage);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "TouchIconsEnabled", QWebEngineSettings::WebAttribute::TouchIconsEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "FocusOnNavigationEnabled", QWebEngineSettings::WebAttribute::FocusOnNavigationEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PrintElementBackgrounds", QWebEngineSettings::WebAttribute::PrintElementBackgrounds);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "AllowRunningInsecureContent", QWebEngineSettings::WebAttribute::AllowRunningInsecureContent);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "AllowGeolocationOnInsecureOrigins", QWebEngineSettings::WebAttribute::AllowGeolocationOnInsecureOrigins);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "AllowWindowActivationFromJavaScript", QWebEngineSettings::WebAttribute::AllowWindowActivationFromJavaScript);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ShowScrollBars", QWebEngineSettings::WebAttribute::ShowScrollBars);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PlaybackRequiresUserGesture", QWebEngineSettings::WebAttribute::PlaybackRequiresUserGesture);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "WebRTCPublicInterfacesOnly", QWebEngineSettings::WebAttribute::WebRTCPublicInterfacesOnly);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "JavascriptCanPaste", QWebEngineSettings::WebAttribute::JavascriptCanPaste);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "DnsPrefetchEnabled", QWebEngineSettings::WebAttribute::DnsPrefetchEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PdfViewerEnabled", QWebEngineSettings::WebAttribute::PdfViewerEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "NavigateOnDropEnabled", QWebEngineSettings::WebAttribute::NavigateOnDropEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ReadingFromCanvasEnabled", QWebEngineSettings::WebAttribute::ReadingFromCanvasEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "ForceDarkMode", QWebEngineSettings::WebAttribute::ForceDarkMode);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PrintHeaderAndFooter", QWebEngineSettings::WebAttribute::PrintHeaderAndFooter);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "PreferCSSMarginsForPrinting", QWebEngineSettings::WebAttribute::PreferCSSMarginsForPrinting);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "TouchEventsApiEnabled", QWebEngineSettings::WebAttribute::TouchEventsApiEnabled);
        define_qenum_value_under(rb_cQWebEngineSettingsWebAttribute, "BackForwardCacheEnabled", QWebEngineSettings::WebAttribute::BackForwardCacheEnabled);
}
