#include "qvalidator-rb.hpp"
#include <qvalidator.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQValidator;
Rice::Class rb_cQDoubleValidator;
Rice::Class rb_cQIntValidator;
Rice::Class rb_cQRegularExpressionValidator;

void Init_qvalidator(Rice::Module rb_mQt6QtGui)
{
    rb_cQValidator =
        // RubyQt6::QtGui::QValidator
        define_class_under<QValidator, QObject>(rb_mQt6QtGui, "QValidator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QValidator::staticMetaObject; })
            // Public Functions
            .define_method("fixup", &QValidator::fixup, Arg("input"))
            .define_method("locale", &QValidator::locale)
            .define_method("set_locale", &QValidator::setLocale, Arg("locale"))
            .define_method("validate", &QValidator::validate, Arg("input"), Arg("pos"))
            // Signals
            .define_method("changed", &QValidator::changed);

    Data_Type<QValidator::State> rb_cQValidatorState =
        // RubyQt6::QtGui::QValidator::State
        define_qenum_under<QValidator::State>(rb_cQValidator, "State");
        define_qenum_value_under(rb_cQValidatorState, "Invalid", QValidator::State::Invalid);
        define_qenum_value_under(rb_cQValidatorState, "Intermediate", QValidator::State::Intermediate);
        define_qenum_value_under(rb_cQValidatorState, "Acceptable", QValidator::State::Acceptable);

    rb_cQDoubleValidator =
        // RubyQt6::QtGui::QDoubleValidator
        define_class_under<QDoubleValidator, QValidator>(rb_mQt6QtGui, "QDoubleValidator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDoubleValidator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDoubleValidator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("bottom", &QDoubleValidator::bottom)
            .define_method("decimals", &QDoubleValidator::decimals)
            .define_method("fixup", &QDoubleValidator::fixup, Arg("input"))
            .define_method("notation", &QDoubleValidator::notation)
            .define_method("set_bottom", &QDoubleValidator::setBottom, Arg("top"))
            .define_method("set_decimals", &QDoubleValidator::setDecimals, Arg("decimals"))
            .define_method("set_notation", &QDoubleValidator::setNotation, Arg("notation"))
            .define_method<void (QDoubleValidator::*)(double, double)>("set_range", &QDoubleValidator::setRange, Arg("bottom"), Arg("top"))
            .define_method<void (QDoubleValidator::*)(double, double, int)>("set_range", &QDoubleValidator::setRange, Arg("bottom"), Arg("top"), Arg("decimals"))
            .define_method("set_top", &QDoubleValidator::setTop, Arg("top"))
            .define_method("top", &QDoubleValidator::top)
            .define_method("validate", &QDoubleValidator::validate, Arg("input"), Arg("pos"))
            // Signals
            .define_method("bottom_changed", &QDoubleValidator::bottomChanged, Arg("bottom"))
            .define_method("decimals_changed", &QDoubleValidator::decimalsChanged, Arg("decimals"))
            .define_method("notation_changed", &QDoubleValidator::notationChanged, Arg("notation"))
            .define_method("top_changed", &QDoubleValidator::topChanged, Arg("top"));

    Data_Type<QDoubleValidator::Notation> rb_cQDoubleValidatorNotation =
        // RubyQt6::QtGui::QDoubleValidator::Notation
        define_qenum_under<QDoubleValidator::Notation>(rb_cQDoubleValidator, "Notation");
        define_qenum_value_under(rb_cQDoubleValidatorNotation, "StandardNotation", QDoubleValidator::Notation::StandardNotation);
        define_qenum_value_under(rb_cQDoubleValidatorNotation, "ScientificNotation", QDoubleValidator::Notation::ScientificNotation);

    rb_cQIntValidator =
        // RubyQt6::QtGui::QIntValidator
        define_class_under<QIntValidator, QValidator>(rb_mQt6QtGui, "QIntValidator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QIntValidator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QIntValidator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("bottom", &QIntValidator::bottom)
            .define_method("fixup", &QIntValidator::fixup, Arg("input"))
            .define_method("set_bottom", &QIntValidator::setBottom, Arg("bottom"))
            .define_method("set_range", &QIntValidator::setRange, Arg("bottom"), Arg("top"))
            .define_method("set_top", &QIntValidator::setTop, Arg("top"))
            .define_method("top", &QIntValidator::top)
            .define_method("validate", &QIntValidator::validate, Arg("input"), Arg("pos"))
            // Signals
            .define_method("bottom_changed", &QIntValidator::bottomChanged, Arg("bottom"))
            .define_method("top_changed", &QIntValidator::topChanged, Arg("top"));

    rb_cQRegularExpressionValidator =
        // RubyQt6::QtGui::QRegularExpressionValidator
        define_class_under<QRegularExpressionValidator, QValidator>(rb_mQt6QtGui, "QRegularExpressionValidator")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QRegularExpressionValidator::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QRegularExpressionValidator, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("regular_expression", &QRegularExpressionValidator::regularExpression)
            // Public Slots
            .define_method("set_regular_expression", &QRegularExpressionValidator::setRegularExpression, Arg("re"))
            // Signals
            .define_method("regular_expression_changed", &QRegularExpressionValidator::regularExpressionChanged, Arg("re"));
}
