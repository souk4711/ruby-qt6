#include "quuid-rb.hpp"
#include <quuid.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQUuid;

int QUuid_operator_compare(QUuid *lhs, QUuid *rhs)
{
    if (*lhs < *rhs) return -1;
    if (*lhs > *rhs) return  1;
    return 0;
}

void Init_quuid(Rice::Module rb_mQt6QtCore)
{
    rb_cQUuid =
        // RubyQt6::QtCore::QUuid
        define_class_under<QUuid>(rb_mQt6QtCore, "QUuid")
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

    Enum<QUuid::StringFormat> rb_cQUuidStringFormat =
        // RubyQt6::QtCore::QUuid::StringFormat
        define_qenum_under<QUuid::StringFormat>("StringFormat", rb_cQUuid)
            .define_value("WithBraces", QUuid::StringFormat::WithBraces)
            .define_value("WithoutBraces", QUuid::StringFormat::WithoutBraces)
            .define_value("Id128", QUuid::StringFormat::Id128);

    Enum<QUuid::Variant> rb_cQUuidVariant =
        // RubyQt6::QtCore::QUuid::Variant
        define_qenum_under<QUuid::Variant>("Variant", rb_cQUuid)
            .define_value("VarUnknown", QUuid::Variant::VarUnknown)
            .define_value("NCS", QUuid::Variant::NCS)
            .define_value("DCE", QUuid::Variant::DCE)
            .define_value("Microsoft", QUuid::Variant::Microsoft)
            .define_value("Reserved", QUuid::Variant::Reserved);

    Enum<QUuid::Version> rb_cQUuidVersion =
        // RubyQt6::QtCore::QUuid::Version
        define_qenum_under<QUuid::Version>("Version", rb_cQUuid)
            .define_value("VerUnknown", QUuid::Version::VerUnknown)
            .define_value("Time", QUuid::Version::Time)
            .define_value("EmbeddedPOSIX", QUuid::Version::EmbeddedPOSIX)
            .define_value("Md5", QUuid::Version::Md5)
            .define_value("Name", QUuid::Version::Name)
            .define_value("Random", QUuid::Version::Random)
            .define_value("Sha1", QUuid::Version::Sha1)
            .define_value("UnixEpoch", QUuid::Version::UnixEpoch);
}
