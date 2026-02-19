#include "kformat-rb.hpp"
#include <kformat.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cKFormat;

void Init_kformat(Module rb_mQt6KCoreAddons)
{
    rb_cKFormat =
        // RubyQt6::KCoreAddons::KFormat
        define_class_under<KFormat>(rb_mQt6KCoreAddons, "KFormat")
            // Constructor
            .define_constructor(Constructor<KFormat>())
            // Public Functions
            .define_method("format_byte_size", &KFormat::formatByteSize, Arg("size"), Arg("precision") = static_cast<int>(1), Arg("dialect") = static_cast<KFormat::BinaryUnitDialect>(KFormat::DefaultBinaryDialect), Arg("units") = static_cast<KFormat::BinarySizeUnits>(KFormat::DefaultBinaryUnits))
            .define_method("format_decimal_duration", &KFormat::formatDecimalDuration, Arg("msecs"), Arg("decimal_places") = static_cast<int>(2))
            .define_method("_format_distance", &KFormat::formatDistance, Arg("distance"), Arg("options"))
            .define_method("_format_duration", &KFormat::formatDuration, Arg("msecs"), Arg("options"))
            .define_method("format_relative_date", &KFormat::formatRelativeDate, Arg("date"), Arg("format"))
            .define_method("format_relative_date_time", &KFormat::formatRelativeDateTime, Arg("date_time"), Arg("format"))
            .define_method("format_spellout_duration", &KFormat::formatSpelloutDuration, Arg("msecs"))
            .define_method("_format_time", &KFormat::formatTime, Arg("datetime"), Arg("format"), Arg("options"))
            .define_method<QString (KFormat::*)(double, KFormat::Unit, int, KFormat::UnitPrefix, KFormat::BinaryUnitDialect) const>("format_value", &KFormat::formatValue, Arg("value"), Arg("unit"), Arg("precision") = static_cast<int>(1), Arg("prefix") = static_cast<KFormat::UnitPrefix>(KFormat::UnitPrefix::AutoAdjust), Arg("dialect") = static_cast<KFormat::BinaryUnitDialect>(KFormat::DefaultBinaryDialect))
            .define_method<QString (KFormat::*)(double, const QString &, int, KFormat::UnitPrefix) const>("format_value", &KFormat::formatValue, Arg("value"), Arg("unit"), Arg("precision") = static_cast<int>(1), Arg("prefix") = static_cast<KFormat::UnitPrefix>(KFormat::UnitPrefix::AutoAdjust))
            .define_method<QString (KFormat::*)(double, const QString &, int, KFormat::UnitPrefix, KFormat::BinaryUnitDialect) const>("format_value", &KFormat::formatValue, Arg("value"), Arg("unit"), Arg("precision"), Arg("prefix"), Arg("dialect"));

    Data_Type<KFormat::BinarySizeUnits> rb_cKFormatBinarySizeUnits =
        // RubyQt6::KCoreAddons::KFormat::BinarySizeUnits
        define_qenum_under<KFormat::BinarySizeUnits>(rb_cKFormat, "BinarySizeUnits");
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "DefaultBinaryUnits", KFormat::BinarySizeUnits::DefaultBinaryUnits);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitByte", KFormat::BinarySizeUnits::UnitByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitKiloByte", KFormat::BinarySizeUnits::UnitKiloByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitMegaByte", KFormat::BinarySizeUnits::UnitMegaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitGigaByte", KFormat::BinarySizeUnits::UnitGigaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitTeraByte", KFormat::BinarySizeUnits::UnitTeraByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitPetaByte", KFormat::BinarySizeUnits::UnitPetaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitExaByte", KFormat::BinarySizeUnits::UnitExaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitZettaByte", KFormat::BinarySizeUnits::UnitZettaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitYottaByte", KFormat::BinarySizeUnits::UnitYottaByte);
        define_qenum_value_under(rb_cKFormatBinarySizeUnits, "UnitLastUnit", KFormat::BinarySizeUnits::UnitLastUnit);

    Data_Type<KFormat::BinaryUnitDialect> rb_cKFormatBinaryUnitDialect =
        // RubyQt6::KCoreAddons::KFormat::BinaryUnitDialect
        define_qenum_under<KFormat::BinaryUnitDialect>(rb_cKFormat, "BinaryUnitDialect");
        define_qenum_value_under(rb_cKFormatBinaryUnitDialect, "DefaultBinaryDialect", KFormat::BinaryUnitDialect::DefaultBinaryDialect);
        define_qenum_value_under(rb_cKFormatBinaryUnitDialect, "IECBinaryDialect", KFormat::BinaryUnitDialect::IECBinaryDialect);
        define_qenum_value_under(rb_cKFormatBinaryUnitDialect, "JEDECBinaryDialect", KFormat::BinaryUnitDialect::JEDECBinaryDialect);
        define_qenum_value_under(rb_cKFormatBinaryUnitDialect, "MetricBinaryDialect", KFormat::BinaryUnitDialect::MetricBinaryDialect);
        define_qenum_value_under(rb_cKFormatBinaryUnitDialect, "LastBinaryDialect", KFormat::BinaryUnitDialect::LastBinaryDialect);

    Data_Type<KFormat::DistanceFormatOption> rb_cKFormatDistanceFormatOption =
        // RubyQt6::KCoreAddons::KFormat::DistanceFormatOption
        define_qenum_under<KFormat::DistanceFormatOption>(rb_cKFormat, "DistanceFormatOption");
        define_qenum_value_under(rb_cKFormatDistanceFormatOption, "LocaleDistanceUnits", KFormat::DistanceFormatOption::LocaleDistanceUnits);
        define_qenum_value_under(rb_cKFormatDistanceFormatOption, "MetricDistanceUnits", KFormat::DistanceFormatOption::MetricDistanceUnits);

    Data_Type<KFormat::DurationFormatOption> rb_cKFormatDurationFormatOption =
        // RubyQt6::KCoreAddons::KFormat::DurationFormatOption
        define_qenum_under<KFormat::DurationFormatOption>(rb_cKFormat, "DurationFormatOption");
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "DefaultDuration", KFormat::DurationFormatOption::DefaultDuration);
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "InitialDuration", KFormat::DurationFormatOption::InitialDuration);
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "ShowMilliseconds", KFormat::DurationFormatOption::ShowMilliseconds);
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "HideSeconds", KFormat::DurationFormatOption::HideSeconds);
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "FoldHours", KFormat::DurationFormatOption::FoldHours);
        define_qenum_value_under(rb_cKFormatDurationFormatOption, "AbbreviatedDuration", KFormat::DurationFormatOption::AbbreviatedDuration);

    Data_Type<KFormat::Unit> rb_cKFormatUnit =
        // RubyQt6::KCoreAddons::KFormat::Unit
        define_qenum_under<KFormat::Unit>(rb_cKFormat, "Unit");
        define_qenum_value_under(rb_cKFormatUnit, "Other", KFormat::Unit::Other);
        define_qenum_value_under(rb_cKFormatUnit, "Bit", KFormat::Unit::Bit);
        define_qenum_value_under(rb_cKFormatUnit, "Byte", KFormat::Unit::Byte);
        define_qenum_value_under(rb_cKFormatUnit, "Meter", KFormat::Unit::Meter);
        define_qenum_value_under(rb_cKFormatUnit, "Hertz", KFormat::Unit::Hertz);

    Data_Type<KFormat::UnitPrefix> rb_cKFormatUnitPrefix =
        // RubyQt6::KCoreAddons::KFormat::UnitPrefix
        define_qenum_under<KFormat::UnitPrefix>(rb_cKFormat, "UnitPrefix");
        define_qenum_value_under(rb_cKFormatUnitPrefix, "AutoAdjust", KFormat::UnitPrefix::AutoAdjust);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Yocto", KFormat::UnitPrefix::Yocto);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Zepto", KFormat::UnitPrefix::Zepto);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Atto", KFormat::UnitPrefix::Atto);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Femto", KFormat::UnitPrefix::Femto);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Pico", KFormat::UnitPrefix::Pico);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Nano", KFormat::UnitPrefix::Nano);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Micro", KFormat::UnitPrefix::Micro);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Milli", KFormat::UnitPrefix::Milli);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Centi", KFormat::UnitPrefix::Centi);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Deci", KFormat::UnitPrefix::Deci);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Unity", KFormat::UnitPrefix::Unity);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Deca", KFormat::UnitPrefix::Deca);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Hecto", KFormat::UnitPrefix::Hecto);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Kilo", KFormat::UnitPrefix::Kilo);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Mega", KFormat::UnitPrefix::Mega);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Giga", KFormat::UnitPrefix::Giga);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Tera", KFormat::UnitPrefix::Tera);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Peta", KFormat::UnitPrefix::Peta);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Exa", KFormat::UnitPrefix::Exa);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Zetta", KFormat::UnitPrefix::Zetta);
        define_qenum_value_under(rb_cKFormatUnitPrefix, "Yotta", KFormat::UnitPrefix::Yotta);

    Data_Type<KFormat::TimeFormatOption> rb_cKFormatTimeFormatOption =
        // RubyQt6::KCoreAddons::KFormat::TimeFormatOption
        define_qenum_under<KFormat::TimeFormatOption>(rb_cKFormat, "TimeFormatOption");
        define_qenum_value_under(rb_cKFormatTimeFormatOption, "DoNotAddTimeZone", KFormat::TimeFormatOption::DoNotAddTimeZone);
        define_qenum_value_under(rb_cKFormatTimeFormatOption, "AddTimezoneAbbreviation", KFormat::TimeFormatOption::AddTimezoneAbbreviation);
        define_qenum_value_under(rb_cKFormatTimeFormatOption, "AddTimezoneAbbreviationIfNeeded", KFormat::TimeFormatOption::AddTimezoneAbbreviationIfNeeded);

    Data_Type<QFlags<KFormat::DistanceFormatOption>> rb_cKFormatDistanceFormatOptions =
        // RubyQt6::KCoreAddons::KFormat::DistanceFormatOptions
        define_qflags_under<KFormat::DistanceFormatOption>(rb_cKFormat, "DistanceFormatOptions");

    Data_Type<QFlags<KFormat::DurationFormatOption>> rb_cKFormatDurationFormatOptions =
        // RubyQt6::KCoreAddons::KFormat::DurationFormatOptions
        define_qflags_under<KFormat::DurationFormatOption>(rb_cKFormat, "DurationFormatOptions");

    Data_Type<QFlags<KFormat::TimeFormatOption>> rb_cKFormatTimeFormatOptions =
        // RubyQt6::KCoreAddons::KFormat::TimeFormatOptions
        define_qflags_under<KFormat::TimeFormatOption>(rb_cKFormat, "TimeFormatOptions");
}
