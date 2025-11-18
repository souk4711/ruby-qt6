#include "qwebenginepermission-rb.hpp"
#include <qwebenginepermission.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQWebEnginePermission;

void Init_qwebenginepermission(Rice::Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEnginePermission =
        // RubyQt6::QtWebEngineCore::QWebEnginePermission
        define_class_under<QWebEnginePermission>(rb_mQt6QtWebEngineCore, "QWebEnginePermission")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QWebEnginePermission>(); })
            .define_singleton_function("_qvariant_from_value", [](const QWebEnginePermission &value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QWebEnginePermission { return qvariant.value<QWebEnginePermission>(); })
            // Public Functions
            .define_method("deny", &QWebEnginePermission::deny)
            .define_method("grant", &QWebEnginePermission::grant)
            .define_method("valid?", &QWebEnginePermission::isValid)
            .define_method("origin", &QWebEnginePermission::origin)
            .define_method("permission_type", &QWebEnginePermission::permissionType)
            .define_method("reset", &QWebEnginePermission::reset)
            .define_method("state", &QWebEnginePermission::state)
            // Static Public Members
            .define_singleton_function("persistent?", &QWebEnginePermission::isPersistent, Arg("permission_type"));

    Data_Type<QWebEnginePermission::PermissionType> rb_cQWebEnginePermissionPermissionType =
        // RubyQt6::QtWebEngineCore::QWebEnginePermission::PermissionType
        define_qenum_under<QWebEnginePermission::PermissionType>(rb_cQWebEnginePermission, "PermissionType");
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "Unsupported", QWebEnginePermission::PermissionType::Unsupported);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "MediaAudioCapture", QWebEnginePermission::PermissionType::MediaAudioCapture);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "MediaVideoCapture", QWebEnginePermission::PermissionType::MediaVideoCapture);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "MediaAudioVideoCapture", QWebEnginePermission::PermissionType::MediaAudioVideoCapture);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "DesktopVideoCapture", QWebEnginePermission::PermissionType::DesktopVideoCapture);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "DesktopAudioVideoCapture", QWebEnginePermission::PermissionType::DesktopAudioVideoCapture);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "MouseLock", QWebEnginePermission::PermissionType::MouseLock);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "Notifications", QWebEnginePermission::PermissionType::Notifications);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "Geolocation", QWebEnginePermission::PermissionType::Geolocation);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "ClipboardReadWrite", QWebEnginePermission::PermissionType::ClipboardReadWrite);
        define_qenum_value_under(rb_cQWebEnginePermissionPermissionType, "LocalFontsAccess", QWebEnginePermission::PermissionType::LocalFontsAccess);

    Data_Type<QWebEnginePermission::State> rb_cQWebEnginePermissionState =
        // RubyQt6::QtWebEngineCore::QWebEnginePermission::State
        define_qenum_under<QWebEnginePermission::State>(rb_cQWebEnginePermission, "State");
        define_qenum_value_under(rb_cQWebEnginePermissionState, "Invalid", QWebEnginePermission::State::Invalid);
        define_qenum_value_under(rb_cQWebEnginePermissionState, "Ask", QWebEnginePermission::State::Ask);
        define_qenum_value_under(rb_cQWebEnginePermissionState, "Granted", QWebEnginePermission::State::Granted);
        define_qenum_value_under(rb_cQWebEnginePermissionState, "Denied", QWebEnginePermission::State::Denied);
}
