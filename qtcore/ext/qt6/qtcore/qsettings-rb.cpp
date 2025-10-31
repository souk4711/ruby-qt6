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
            .define_method("begin_group", [](QSettings *self, const char *prefix) -> void { return self->beginGroup(prefix); }, Arg("prefix"))
            .define_method("begin_read_array", [](QSettings *self, const char *prefix) -> int { return self->beginReadArray(prefix); }, Arg("prefix"))
            .define_method("begin_write_array", [](QSettings *self, const char *prefix) -> void { return self->beginWriteArray(prefix); }, Arg("prefix"))
            .define_method("contains", [](QSettings *self, const char *key) -> bool { return self->contains(key); }, Arg("key"))
            .define_method("remove", [](QSettings *self, const char *key) -> void { return self->remove(key); }, Arg("key"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSettings::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>(), Arg("format"), Arg("scope"), Arg("organization"), Arg("application"), Arg("parent"))
            // Public Functions
            .define_method("all_keys", &QSettings::allKeys)
            .define_method("application_name", &QSettings::applicationName)
            .define_method("begin_group", &QSettings::beginGroup, Arg("prefix"))
            .define_method("begin_read_array", &QSettings::beginReadArray, Arg("prefix"))
            .define_method("begin_write_array", &QSettings::beginWriteArray, Arg("prefix"), Arg("size") = static_cast<int>(-1))
            .define_method("child_groups", &QSettings::childGroups)
            .define_method("child_keys", &QSettings::childKeys)
            .define_method("clear", &QSettings::clear)
            .define_method("contains", &QSettings::contains, Arg("key"))
            .define_method("end_array", &QSettings::endArray)
            .define_method("end_group", &QSettings::endGroup)
            .define_method("fallbacks_enabled", &QSettings::fallbacksEnabled)
            .define_method("file_name", &QSettings::fileName)
            .define_method("format", &QSettings::format)
            .define_method("group", &QSettings::group)
            .define_method("atomic_sync_required?", &QSettings::isAtomicSyncRequired)
            .define_method("writable?", &QSettings::isWritable)
            .define_method("organization_name", &QSettings::organizationName)
            .define_method("remove", &QSettings::remove, Arg("key"))
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
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat1", QSettings::Format::CustomFormat1);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat2", QSettings::Format::CustomFormat2);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat3", QSettings::Format::CustomFormat3);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat4", QSettings::Format::CustomFormat4);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat5", QSettings::Format::CustomFormat5);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat6", QSettings::Format::CustomFormat6);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat7", QSettings::Format::CustomFormat7);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat8", QSettings::Format::CustomFormat8);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat9", QSettings::Format::CustomFormat9);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat10", QSettings::Format::CustomFormat10);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat11", QSettings::Format::CustomFormat11);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat12", QSettings::Format::CustomFormat12);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat13", QSettings::Format::CustomFormat13);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat14", QSettings::Format::CustomFormat14);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat15", QSettings::Format::CustomFormat15);
        define_qenum_value_under(rb_cQSettingsFormat, "CustomFormat16", QSettings::Format::CustomFormat16);

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
