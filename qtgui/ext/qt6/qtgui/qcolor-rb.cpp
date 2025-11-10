#include "qcolor-rb.hpp"
#include <qcolor.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQColor;

void Init_qcolor(Rice::Module rb_mQt6QtGui)
{
    rb_cQColor =
        // RubyQt6::QtGui::QColor
        define_class_under<QColor>(rb_mQt6QtGui, "QColor")
            // Constructor
            .define_constructor(Constructor<QColor>())
            .define_constructor(Constructor<QColor, int, int, int>(), Arg("r"), Arg("g"), Arg("b"))
            .define_constructor(Constructor<QColor, int, int, int, int>(), Arg("r"), Arg("g"), Arg("b"), Arg("a"))
            .define_constructor(Constructor<QColor, Qt::GlobalColor>(), Arg("color"))
            .define_constructor(Constructor<QColor, const char *>(), Arg("color"))
            .define_constructor(Constructor<QColor, const QString &>(), Arg("color"))
            // Public Functions
            .define_method("alpha", &QColor::alpha)
            .define_method("alpha_f", &QColor::alphaF)
            .define_method("black", &QColor::black)
            .define_method("black_f", &QColor::blackF)
            .define_method("blue", &QColor::blue)
            .define_method("blue_f", &QColor::blueF)
            .define_method("convert_to", &QColor::convertTo, Arg("color_spec"))
            .define_method("cyan", &QColor::cyan)
            .define_method("cyan_f", &QColor::cyanF)
            .define_method("darker", &QColor::darker, Arg("f") = static_cast<int>(200))
            .define_method("get_cmyk", &QColor::getCmyk, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<int *>(nullptr))
            .define_method("get_cmyk_f", &QColor::getCmykF, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<float *>(nullptr))
            .define_method("get_hsl", &QColor::getHsl, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<int *>(nullptr))
            .define_method("get_hsl_f", &QColor::getHslF, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<float *>(nullptr))
            .define_method("get_hsv", &QColor::getHsv, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<int *>(nullptr))
            .define_method("get_hsv_f", &QColor::getHsvF, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<float *>(nullptr))
            .define_method("get_rgb", &QColor::getRgb, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<int *>(nullptr))
            .define_method("get_rgb_f", &QColor::getRgbF, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<float *>(nullptr))
            .define_method("green", &QColor::green)
            .define_method("green_f", &QColor::greenF)
            .define_method("hsl_hue", &QColor::hslHue)
            .define_method("hsl_hue_f", &QColor::hslHueF)
            .define_method("hsl_saturation", &QColor::hslSaturation)
            .define_method("hsl_saturation_f", &QColor::hslSaturationF)
            .define_method("hsv_hue", &QColor::hsvHue)
            .define_method("hsv_hue_f", &QColor::hsvHueF)
            .define_method("hsv_saturation", &QColor::hsvSaturation)
            .define_method("hsv_saturation_f", &QColor::hsvSaturationF)
            .define_method("hue", &QColor::hue)
            .define_method("hue_f", &QColor::hueF)
            .define_method("valid?", &QColor::isValid)
            .define_method("lighter", &QColor::lighter, Arg("f") = static_cast<int>(150))
            .define_method("lightness", &QColor::lightness)
            .define_method("lightness_f", &QColor::lightnessF)
            .define_method("magenta", &QColor::magenta)
            .define_method("magenta_f", &QColor::magentaF)
            .define_method("name", &QColor::name, Arg("format") = static_cast<QColor::NameFormat>(QColor::NameFormat::HexRgb))
            .define_method("red", &QColor::red)
            .define_method("red_f", &QColor::redF)
            .define_method("rgb", &QColor::rgb)
            .define_method("rgba", &QColor::rgba)
            .define_method("rgba64", &QColor::rgba64)
            .define_method("saturation", &QColor::saturation)
            .define_method("saturation_f", &QColor::saturationF)
            .define_method("set_alpha", &QColor::setAlpha, Arg("alpha"))
            .define_method("set_alpha_f", &QColor::setAlphaF, Arg("alpha"))
            .define_method("set_blue", &QColor::setBlue, Arg("blue"))
            .define_method("set_blue_f", &QColor::setBlueF, Arg("blue"))
            .define_method("set_cmyk", &QColor::setCmyk, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<int>(255))
            .define_method("set_cmyk_f", &QColor::setCmykF, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<float>(1.0))
            .define_method("set_green", &QColor::setGreen, Arg("green"))
            .define_method("set_green_f", &QColor::setGreenF, Arg("green"))
            .define_method("set_hsl", &QColor::setHsl, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<int>(255))
            .define_method("set_hsl_f", &QColor::setHslF, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<float>(1.0))
            .define_method("set_hsv", &QColor::setHsv, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<int>(255))
            .define_method("set_hsv_f", &QColor::setHsvF, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<float>(1.0))
            .define_method("set_red", &QColor::setRed, Arg("red"))
            .define_method("set_red_f", &QColor::setRedF, Arg("red"))
            .define_method<void (QColor::*)(QRgb) noexcept>("set_rgb", &QColor::setRgb, Arg("rgb"))
            .define_method<void (QColor::*)(int, int, int, int)>("set_rgb", &QColor::setRgb, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<int>(255))
            .define_method("set_rgb_f", &QColor::setRgbF, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<float>(1.0))
            .define_method("set_rgba", &QColor::setRgba, Arg("rgba"))
            .define_method("set_rgba64", &QColor::setRgba64, Arg("rgba"))
            .define_method("spec", &QColor::spec)
            .define_method("to_cmyk", &QColor::toCmyk)
            .define_method("to_extended_rgb", &QColor::toExtendedRgb)
            .define_method("to_hsl", &QColor::toHsl)
            .define_method("to_hsv", &QColor::toHsv)
            .define_method("to_rgb", &QColor::toRgb)
            .define_method("value", &QColor::value)
            .define_method("value_f", &QColor::valueF)
            .define_method("yellow", &QColor::yellow)
            .define_method("yellow_f", &QColor::yellowF)
            // Static Public Members
            .define_singleton_function("color_names", &QColor::colorNames)
            .define_singleton_function("from_cmyk", &QColor::fromCmyk, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<int>(255))
            .define_singleton_function("from_cmyk_f", &QColor::fromCmykF, Arg("c"), Arg("m"), Arg("y"), Arg("k"), Arg("a") = static_cast<float>(1.0))
            .define_singleton_function("from_hsl", &QColor::fromHsl, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<int>(255))
            .define_singleton_function("from_hsl_f", &QColor::fromHslF, Arg("h"), Arg("s"), Arg("l"), Arg("a") = static_cast<float>(1.0))
            .define_singleton_function("from_hsv", &QColor::fromHsv, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<int>(255))
            .define_singleton_function("from_hsv_f", &QColor::fromHsvF, Arg("h"), Arg("s"), Arg("v"), Arg("a") = static_cast<float>(1.0))
            .define_singleton_function<QColor (*)(QRgb)>("from_rgb", &QColor::fromRgb, Arg("rgb"))
            .define_singleton_function<QColor (*)(int, int, int, int)>("from_rgb", &QColor::fromRgb, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<int>(255))
            .define_singleton_function("from_rgb_f", &QColor::fromRgbF, Arg("r"), Arg("g"), Arg("b"), Arg("a") = static_cast<float>(1.0));

    Data_Type<QColor::NameFormat> rb_cQColorNameFormat =
        // RubyQt6::QtGui::QColor::NameFormat
        define_qenum_under<QColor::NameFormat>(rb_cQColor, "NameFormat");
        define_qenum_value_under(rb_cQColorNameFormat, "HexRgb", QColor::NameFormat::HexRgb);
        define_qenum_value_under(rb_cQColorNameFormat, "HexArgb", QColor::NameFormat::HexArgb);

    Data_Type<QColor::Spec> rb_cQColorSpec =
        // RubyQt6::QtGui::QColor::Spec
        define_qenum_under<QColor::Spec>(rb_cQColor, "Spec");
        define_qenum_value_under(rb_cQColorSpec, "Invalid", QColor::Spec::Invalid);
        define_qenum_value_under(rb_cQColorSpec, "Rgb", QColor::Spec::Rgb);
        define_qenum_value_under(rb_cQColorSpec, "Hsv", QColor::Spec::Hsv);
        define_qenum_value_under(rb_cQColorSpec, "Cmyk", QColor::Spec::Cmyk);
        define_qenum_value_under(rb_cQColorSpec, "Hsl", QColor::Spec::Hsl);
        define_qenum_value_under(rb_cQColorSpec, "ExtendedRgb", QColor::Spec::ExtendedRgb);
}
