#include "qsettings-rb.hpp"
#include <qsettings.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQSettings;

void Init_qsettings(Rice::Module rb_mQt6QtCore)
{
    rb_cQSettings =
        // RubyQt6::QtCore::QSettings
        define_class_under<QSettings, QObject>(rb_mQt6QtCore, "QSettings")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSettings::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>(), Arg("format"), Arg("scope"), Arg("organization"), Arg("application"), Arg("parent"))
            // Public Functions
            .define_method("all_keys", &QSettings::allKeys)
            .define_method("application_name", &QSettings::applicationName)
            .define_method("_begin_group", &QSettings::beginGroup, Arg("prefix"))
            .define_method("_begin_read_array", &QSettings::beginReadArray, Arg("prefix"))
            .define_method("_begin_write_array", &QSettings::beginWriteArray, Arg("prefix"), Arg("size") = static_cast<int>(-1))
            .define_method("child_groups", &QSettings::childGroups)
            .define_method("child_keys", &QSettings::childKeys)
            .define_method("clear", &QSettings::clear)
            .define_method("_contains", &QSettings::contains, Arg("key"))
            .define_method("end_array", &QSettings::endArray)
            .define_method("end_group", &QSettings::endGroup)
            .define_method("fallbacks_enabled", &QSettings::fallbacksEnabled)
            .define_method("file_name", &QSettings::fileName)
            .define_method("format", &QSettings::format)
            .define_method("group", &QSettings::group)
            .define_method("atomic_sync_required?", &QSettings::isAtomicSyncRequired)
            .define_method("writable?", &QSettings::isWritable)
            .define_method("organization_name", &QSettings::organizationName)
            .define_method("_remove", &QSettings::remove, Arg("key"))
            .define_method("scope", &QSettings::scope)
            .define_method("set_array_index", &QSettings::setArrayIndex, Arg("i"))
            .define_method("set_atomic_sync_required", &QSettings::setAtomicSyncRequired, Arg("enable"))
            .define_method("set_fallbacks_enabled", &QSettings::setFallbacksEnabled, Arg("b"))
            .define_method("_set_value", &QSettings::setValue, Arg("key"), Arg("value"))
            .define_method("status", &QSettings::status)
            .define_method("sync", &QSettings::sync)
            .define_method<QVariant (QSettings::*)(QAnyStringView) const>("_value", &QSettings::value, Arg("key"))
            .define_method<QVariant (QSettings::*)(QAnyStringView, const QVariant &) const>("_value", &QSettings::value, Arg("key"), Arg("default_value"))
            // Static Public Members
            .define_singleton_function("default_format", &QSettings::defaultFormat)
            // .define_singleton_function("register_format", &QSettings::registerFormat, Arg("extension"), Arg("read_func"), Arg("write_func"), Arg("case_sensitivity") = static_cast<Qt::CaseSensitivity>(Qt::CaseSensitive))
            .define_singleton_function("set_default_format", &QSettings::setDefaultFormat, Arg("format"))
            .define_singleton_function("set_path", &QSettings::setPath, Arg("format"), Arg("scope"), Arg("path"));

    Data_Type<QSettings::Format> rb_cQSettingsFormat =
        // RubyQt6::QtCore::QSettings::Format
        define_qenum_under<QSettings::Format>(rb_cQSettings, "Format");
        define_qenum_value_under(rb_cQSettingsFormat, "NativeFormat", QSettings::Format::NativeFormat);
        define_qenum_value_under(rb_cQSettingsFormat, "IniFormat", QSettings::Format::IniFormat);
        define_qenum_value_under(rb_cQSettingsFormat, "InvalidFormat", QSettings::Format::InvalidFormat);

    Data_Type<QSettings::Scope> rb_cQSettingsScope =
        // RubyQt6::QtCore::QSettings::Scope
        define_qenum_under<QSettings::Scope>(rb_cQSettings, "Scope");
        define_qenum_value_under(rb_cQSettingsScope, "UserScope", QSettings::Scope::UserScope);
        define_qenum_value_under(rb_cQSettingsScope, "SystemScope", QSettings::Scope::SystemScope);

    Data_Type<QSettings::Status> rb_cQSettingsStatus =
        // RubyQt6::QtCore::QSettings::Status
        define_qenum_under<QSettings::Status>(rb_cQSettings, "Status");
        define_qenum_value_under(rb_cQSettingsStatus, "NoError", QSettings::Status::NoError);
        define_qenum_value_under(rb_cQSettingsStatus, "AccessError", QSettings::Status::AccessError);
        define_qenum_value_under(rb_cQSettingsStatus, "FormatError", QSettings::Status::FormatError);
}
