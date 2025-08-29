#include "qlcdnumber-rb.hpp"
#include <qlcdnumber.h>

using namespace Rice;

Rice::Class rb_cQLCDNumber;

void Init_qlcdnumber(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLCDNumber =
        // RubyQt6::QtWidgets::QLCDNumber
        define_class_under<QLCDNumber, QFrame>(rb_mQt6QtWidgets, "QLCDNumber")
            .define_constructor(Constructor<QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_method("_digit_count", &QLCDNumber::digitCount)
            .define_method("_int_value", &QLCDNumber::intValue)
            .define_method("_mode", &QLCDNumber::mode)
            .define_method("_segment_style", &QLCDNumber::segmentStyle)
            .define_method("_small_decimal_point?", &QLCDNumber::smallDecimalPoint)
            .define_method("_value", &QLCDNumber::value)
            .define_method("_set_digit_count", &QLCDNumber::setDigitCount, Arg("num"))
            .define_method<void (QLCDNumber::*)(double)>("_display", &QLCDNumber::display, Arg("num"))
            .define_method<void (QLCDNumber::*)(int)>("_display", &QLCDNumber::display, Arg("num"))
            .define_method<void (QLCDNumber::*)(const QString &)>("_display_str", &QLCDNumber::display, Arg("str"))
            .define_method("_set_mode", &QLCDNumber::setMode, Arg("mode"))
            .define_method("_set_hex_mode", &QLCDNumber::setHexMode)
            .define_method("_set_dec_mode", &QLCDNumber::setDecMode)
            .define_method("_set_oct_mode", &QLCDNumber::setOctMode)
            .define_method("_set_bin_mode", &QLCDNumber::setBinMode)
            .define_method("_set_segment_style", &QLCDNumber::setSegmentStyle, Arg("style"))
            .define_method("_set_small_decimal_point", &QLCDNumber::setSmallDecimalPoint, Arg("enabled"))
            .define_method<bool (QLCDNumber::*)(double) const>("_check_overflow", &QLCDNumber::checkOverflow, Arg("num"))
            .define_method<bool (QLCDNumber::*)(int) const>("_check_overflow", &QLCDNumber::checkOverflow, Arg("num"));

    Enum<QLCDNumber::Mode> rb_cQLCDNumberMode =
        // RubyQt6::QtWidgets::QLCDNumber::Mode
        define_enum_under<QLCDNumber::Mode>("Mode", rb_cQLCDNumber)
            .define_value("Hex", QLCDNumber::Mode::Hex)
            .define_value("Dec", QLCDNumber::Mode::Dec)
            .define_value("Oct", QLCDNumber::Mode::Oct)
            .define_value("Bin", QLCDNumber::Mode::Bin);

    Enum<QLCDNumber::SegmentStyle> rb_cQLCDNumberSegmentStyle =
        // RubyQt6::QtWidgets::QLCDNumber::SegmentStyle
        define_enum_under<QLCDNumber::SegmentStyle>("SegmentStyle", rb_cQLCDNumber)
            .define_value("Outline", QLCDNumber::SegmentStyle::Outline)
            .define_value("Filled", QLCDNumber::SegmentStyle::Filled)
            .define_value("Flat", QLCDNumber::SegmentStyle::Flat);
}
