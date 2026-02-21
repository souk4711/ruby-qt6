#include "quuid-rb.hpp"
#include <quuid.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQUuid;

int QUuid_operator_compare(QUuid *lhs, QUuid *rhs)
{
    if (*lhs < *rhs) return -1;
    if (*lhs > *rhs) return  1;
    return 0;
}

void Init_quuid(Module rb_mQt6QtCore)
{
    rb_cQUuid =
        // RubyQt6::QtCore::QUuid
        define_qlass_under<QUuid>(rb_mQt6QtCore, "QUuid")
            // RubyQt6-Defined Functions
            .define_method("variant", [](QUuid *self) -> QUuid::Variant { return self->variant(); })
            .define_method("version", [](QUuid *self) -> QUuid::Version { return self->version(); })
            .define_singleton_function("_operator_compare", QUuid_operator_compare, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QUuid>())
            .define_constructor(Constructor<QUuid, QAnyStringView>(), Arg("string"))
            // Public Functions
            .define_method("null?", &QUuid::isNull)
            .define_method("to_byte_array", &QUuid::toByteArray, Arg("mode") = static_cast<QUuid::StringFormat>(QUuid::StringFormat::WithBraces))
            .define_method("to_string", &QUuid::toString, Arg("mode") = static_cast<QUuid::StringFormat>(QUuid::StringFormat::WithBraces));

    Data_Type<QUuid::StringFormat> rb_cQUuidStringFormat =
        // RubyQt6::QtCore::QUuid::StringFormat
        define_qenum_under<QUuid::StringFormat>(rb_cQUuid, "StringFormat");
        define_qenum_value_under(rb_cQUuidStringFormat, "WithBraces", QUuid::StringFormat::WithBraces);
        define_qenum_value_under(rb_cQUuidStringFormat, "WithoutBraces", QUuid::StringFormat::WithoutBraces);
        define_qenum_value_under(rb_cQUuidStringFormat, "Id128", QUuid::StringFormat::Id128);

    Data_Type<QUuid::Variant> rb_cQUuidVariant =
        // RubyQt6::QtCore::QUuid::Variant
        define_qenum_under<QUuid::Variant>(rb_cQUuid, "Variant");
        define_qenum_value_under(rb_cQUuidVariant, "VarUnknown", QUuid::Variant::VarUnknown);
        define_qenum_value_under(rb_cQUuidVariant, "NCS", QUuid::Variant::NCS);
        define_qenum_value_under(rb_cQUuidVariant, "DCE", QUuid::Variant::DCE);
        define_qenum_value_under(rb_cQUuidVariant, "Microsoft", QUuid::Variant::Microsoft);
        define_qenum_value_under(rb_cQUuidVariant, "Reserved", QUuid::Variant::Reserved);

    Data_Type<QUuid::Version> rb_cQUuidVersion =
        // RubyQt6::QtCore::QUuid::Version
        define_qenum_under<QUuid::Version>(rb_cQUuid, "Version");
        define_qenum_value_under(rb_cQUuidVersion, "VerUnknown", QUuid::Version::VerUnknown);
        define_qenum_value_under(rb_cQUuidVersion, "Time", QUuid::Version::Time);
        define_qenum_value_under(rb_cQUuidVersion, "EmbeddedPOSIX", QUuid::Version::EmbeddedPOSIX);
        define_qenum_value_under(rb_cQUuidVersion, "Md5", QUuid::Version::Md5);
        define_qenum_value_under(rb_cQUuidVersion, "Name", QUuid::Version::Name);
        define_qenum_value_under(rb_cQUuidVersion, "Random", QUuid::Version::Random);
        define_qenum_value_under(rb_cQUuidVersion, "Sha1", QUuid::Version::Sha1);
        define_qenum_value_under(rb_cQUuidVersion, "UnixEpoch", QUuid::Version::UnixEpoch);
}
