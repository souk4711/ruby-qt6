#include "qwebengineclienthints-rb.hpp"
#include <qwebengineclienthints.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineClientHints;

void Init_qwebengineclienthints(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineClientHints =
        // RubyQt6::QtWebEngineCore::QWebEngineClientHints
        define_qlass_under<QWebEngineClientHints, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineClientHints")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEngineClientHints * { return qobject_cast<QWebEngineClientHints *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineClientHints::staticMetaObject; })
            // Public Functions
            .define_method("arch", &QWebEngineClientHints::arch)
            .define_method("bitness", &QWebEngineClientHints::bitness)
            .define_method("form_factors", &QWebEngineClientHints::formFactors)
            .define_method("full_version", &QWebEngineClientHints::fullVersion)
            .define_method("full_version_list", &QWebEngineClientHints::fullVersionList)
            .define_method("all_client_hints_enabled?", &QWebEngineClientHints::isAllClientHintsEnabled)
            .define_method("mobile?", &QWebEngineClientHints::isMobile)
            .define_method("wow64?", &QWebEngineClientHints::isWow64)
            .define_method("model", &QWebEngineClientHints::model)
            .define_method("platform", &QWebEngineClientHints::platform)
            .define_method("platform_version", &QWebEngineClientHints::platformVersion)
            .define_method("reset_all", &QWebEngineClientHints::resetAll)
            .define_method("set_all_client_hints_enabled", &QWebEngineClientHints::setAllClientHintsEnabled, Arg("enabled"))
            .define_method("set_arch", &QWebEngineClientHints::setArch, Arg("arch"))
            .define_method("set_bitness", &QWebEngineClientHints::setBitness, Arg("bitness"))
            .define_method("set_form_factors", &QWebEngineClientHints::setFormFactors, Arg("form_factors"))
            .define_method("set_full_version", &QWebEngineClientHints::setFullVersion, Arg("full_version"))
            .define_method("set_full_version_list", &QWebEngineClientHints::setFullVersionList, Arg("full_version_list"))
            .define_method("set_is_mobile", &QWebEngineClientHints::setIsMobile, Arg("is_mobile"))
            .define_method("set_is_wow64", &QWebEngineClientHints::setIsWow64, Arg("is_wow64"))
            .define_method("set_model", &QWebEngineClientHints::setModel, Arg("model"))
            .define_method("set_platform", &QWebEngineClientHints::setPlatform, Arg("platform"))
            .define_method("set_platform_version", &QWebEngineClientHints::setPlatformVersion, Arg("platform_version"));
}
