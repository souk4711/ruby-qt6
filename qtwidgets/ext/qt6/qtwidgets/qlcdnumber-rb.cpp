#include "qlcdnumber-rb.hpp"
#include <qlcdnumber.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQLCDNumber;

void Init_qlcdnumber(Module rb_mQt6QtWidgets)
{
    rb_cQLCDNumber =
        // RubyQt6::QtWidgets::QLCDNumber
        define_class_under<QLCDNumber, QFrame>(rb_mQt6QtWidgets, "QLCDNumber")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QLCDNumber::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"))
            // Public Functions
            .define_method<bool (QLCDNumber::*)(double) const>("check_overflow", &QLCDNumber::checkOverflow, Arg("num"))
            .define_method<bool (QLCDNumber::*)(int) const>("check_overflow", &QLCDNumber::checkOverflow, Arg("num"))
            .define_method("digit_count", &QLCDNumber::digitCount)
            .define_method("int_value", &QLCDNumber::intValue)
            .define_method("mode", &QLCDNumber::mode)
            .define_method("segment_style", &QLCDNumber::segmentStyle)
            .define_method("set_digit_count", &QLCDNumber::setDigitCount, Arg("n_digits"))
            .define_method("set_mode", &QLCDNumber::setMode, Arg("mode"))
            .define_method("set_segment_style", &QLCDNumber::setSegmentStyle, Arg("style"))
            .define_method("small_decimal_point", &QLCDNumber::smallDecimalPoint)
            .define_method("value", &QLCDNumber::value)
            // Public Slots
            .define_method<void (QLCDNumber::*)(const QString &)>("_display", &QLCDNumber::display, Arg("str"))
            .define_method<void (QLCDNumber::*)(double)>("_display", &QLCDNumber::display, Arg("num"))
            .define_method<void (QLCDNumber::*)(int)>("_display", &QLCDNumber::display, Arg("num"))
            .define_method("set_bin_mode", &QLCDNumber::setBinMode)
            .define_method("set_dec_mode", &QLCDNumber::setDecMode)
            .define_method("set_hex_mode", &QLCDNumber::setHexMode)
            .define_method("set_oct_mode", &QLCDNumber::setOctMode)
            .define_method("set_small_decimal_point", &QLCDNumber::setSmallDecimalPoint, Arg("enabled"));
            // Signals
            // .define_method("overflow", &QLCDNumber::overflow);

    Data_Type<QLCDNumber::Mode> rb_cQLCDNumberMode =
        // RubyQt6::QtWidgets::QLCDNumber::Mode
        define_qenum_under<QLCDNumber::Mode>(rb_cQLCDNumber, "Mode");
        define_qenum_value_under(rb_cQLCDNumberMode, "Hex", QLCDNumber::Mode::Hex);
        define_qenum_value_under(rb_cQLCDNumberMode, "Dec", QLCDNumber::Mode::Dec);
        define_qenum_value_under(rb_cQLCDNumberMode, "Oct", QLCDNumber::Mode::Oct);
        define_qenum_value_under(rb_cQLCDNumberMode, "Bin", QLCDNumber::Mode::Bin);

    Data_Type<QLCDNumber::SegmentStyle> rb_cQLCDNumberSegmentStyle =
        // RubyQt6::QtWidgets::QLCDNumber::SegmentStyle
        define_qenum_under<QLCDNumber::SegmentStyle>(rb_cQLCDNumber, "SegmentStyle");
        define_qenum_value_under(rb_cQLCDNumberSegmentStyle, "Outline", QLCDNumber::SegmentStyle::Outline);
        define_qenum_value_under(rb_cQLCDNumberSegmentStyle, "Filled", QLCDNumber::SegmentStyle::Filled);
        define_qenum_value_under(rb_cQLCDNumberSegmentStyle, "Flat", QLCDNumber::SegmentStyle::Flat);
}
