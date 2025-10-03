#include "qvariant-rb.hpp"
#include <qvariant.h>

#include <QString>

using namespace Rice;

Rice::Class rb_cQVariant;

void Init_qvariant(Rice::Module rb_mQt6QtCore)
{
    rb_cQVariant =
        // RubyQt6::QtCore::QVariant
        define_class_under<QVariant>(rb_mQt6QtCore, "QVariant")
            // RubyQt6-Defined Functions
            .define_singleton_function("from_bool", [](bool value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_int", [](int value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_double", [](double value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qstring", [](const QString &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("to_bool", [](const QVariant &qvariant) -> bool { return qvariant.toBool(); })
            .define_singleton_function("to_int", [](const QVariant &qvariant) -> int { return qvariant.toInt(); })
            .define_singleton_function("to_double", [](const QVariant &qvariant) -> double { return qvariant.toDouble(); })
            .define_singleton_function("to_qstring", [](const QVariant &qvariant) -> QString { return qvariant.toString(); })
            // Public Functions
            .define_method("type_id", &QVariant::typeId)
            .define_method("type_name", &QVariant::typeName);
}
