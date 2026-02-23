#include "qfontinfo-rb.hpp"
#include <qfontinfo.h>

#include <QList>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFontInfo;

void Init_qfontinfo(Module rb_mQt6QtGui)
{
    rb_cQFontInfo =
        // RubyQt6::QtGui::QFontInfo
        define_qlass_under<QFontInfo>(rb_mQt6QtGui, "QFontInfo")
            // Constructor
            .define_constructor(Constructor<QFontInfo, const QFont &>(), Arg("font"))
            // Public Functions
            .define_method("bold", &QFontInfo::bold)
            .define_method("exact_match", &QFontInfo::exactMatch)
            .define_method("family", &QFontInfo::family)
            .define_method("fixed_pitch", &QFontInfo::fixedPitch)
            .define_method("italic", &QFontInfo::italic)
            .define_method("overline", &QFontInfo::overline)
            .define_method("pixel_size", &QFontInfo::pixelSize)
            .define_method("point_size", &QFontInfo::pointSize)
            .define_method("point_size_f", &QFontInfo::pointSizeF)
            .define_method("strike_out", &QFontInfo::strikeOut)
            .define_method("style", &QFontInfo::style)
            .define_method("style_hint", &QFontInfo::styleHint)
            .define_method("style_name", &QFontInfo::styleName)
            .define_method("underline", &QFontInfo::underline)
            .define_method("variable_axes", &QFontInfo::variableAxes)
            .define_method("weight", &QFontInfo::weight);
}
