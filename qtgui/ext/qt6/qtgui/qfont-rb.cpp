#include "qfont-rb.hpp"
#include <qfont.h>

#include <QStringList>

using namespace Rice;

Rice::Class rb_cQFont;

void Init_qfont(Rice::Module rb_mQt6QtGui)
{
    rb_cQFont =
        // RubyQt6::QtGui::QFont
        define_class_under<QFont>(rb_mQt6QtGui, "QFont")
            // Constructor
            .define_constructor(Constructor<QFont, const QString &, int, int, bool>(), Arg("family"), Arg("point_size") = static_cast<int>(-1), Arg("weight") = static_cast<int>(-1), Arg("italic") = static_cast<bool>(false))
            .define_constructor(Constructor<QFont, const QStringList &, int, int, bool>(), Arg("families"), Arg("point_size") = static_cast<int>(-1), Arg("weight") = static_cast<int>(-1), Arg("italic") = static_cast<bool>(false))
            // Public Functions
            .define_method("bold", &QFont::bold)
            .define_method("capitalization", &QFont::capitalization)
            .define_method("clear_features", &QFont::clearFeatures)
            .define_method("clear_variable_axes", &QFont::clearVariableAxes)
            .define_method("default_family", &QFont::defaultFamily)
            .define_method("exact_match", &QFont::exactMatch)
            .define_method("families", &QFont::families)
            .define_method("family", &QFont::family)
            .define_method("feature_tags", &QFont::featureTags)
            .define_method("feature_value", &QFont::featureValue, Arg("tag"))
            .define_method("fixed_pitch", &QFont::fixedPitch)
            .define_method("from_string", &QFont::fromString, Arg("descrip"))
            .define_method("hinting_preference", &QFont::hintingPreference)
            .define_method("copy_of?", &QFont::isCopyOf, Arg("f"))
            .define_method("feature_set?", &QFont::isFeatureSet, Arg("tag"))
            .define_method("variable_axis_set?", &QFont::isVariableAxisSet, Arg("tag"))
            .define_method("italic", &QFont::italic)
            .define_method("kerning", &QFont::kerning)
            .define_method("key", &QFont::key)
            .define_method("letter_spacing", &QFont::letterSpacing)
            .define_method("letter_spacing_type", &QFont::letterSpacingType)
            .define_method("overline", &QFont::overline)
            .define_method("pixel_size", &QFont::pixelSize)
            .define_method("point_size", &QFont::pointSize)
            .define_method("point_size_f", &QFont::pointSizeF)
            .define_method("resolve", &QFont::resolve, Arg("other"))
            .define_method("resolve_mask", &QFont::resolveMask)
            .define_method("set_bold", &QFont::setBold, Arg("enable"))
            .define_method("set_capitalization", &QFont::setCapitalization, Arg("caps"))
            .define_method("set_families", &QFont::setFamilies, Arg("families"))
            .define_method("set_family", &QFont::setFamily, Arg("family"))
            .define_method("set_feature", &QFont::setFeature, Arg("tag"), Arg("value"))
            .define_method("set_fixed_pitch", &QFont::setFixedPitch, Arg("enable"))
            .define_method("set_hinting_preference", &QFont::setHintingPreference, Arg("hinting_preference"))
            .define_method("set_italic", &QFont::setItalic, Arg("b"))
            .define_method("set_kerning", &QFont::setKerning, Arg("enable"))
            .define_method("set_letter_spacing", &QFont::setLetterSpacing, Arg("type"), Arg("spacing"))
            .define_method("set_overline", &QFont::setOverline, Arg("enable"))
            .define_method("set_pixel_size", &QFont::setPixelSize, Arg("pixel_size"))
            .define_method("set_point_size", &QFont::setPointSize, Arg("point_size"))
            .define_method("set_point_size_f", &QFont::setPointSizeF, Arg("point_size"))
            .define_method("set_resolve_mask", &QFont::setResolveMask, Arg("mask"))
            .define_method("set_stretch", &QFont::setStretch, Arg("factor"))
            .define_method("set_strike_out", &QFont::setStrikeOut, Arg("enable"))
            .define_method("set_style", &QFont::setStyle, Arg("style"))
            .define_method("set_style_hint", &QFont::setStyleHint, Arg("hint"), Arg("strategy") = static_cast<QFont::StyleStrategy>(QFont::StyleStrategy::PreferDefault))
            .define_method("set_style_name", &QFont::setStyleName, Arg("name"))
            .define_method("set_style_strategy", &QFont::setStyleStrategy, Arg("s"))
            .define_method("set_underline", &QFont::setUnderline, Arg("enable"))
            .define_method("set_variable_axis", &QFont::setVariableAxis, Arg("tag"), Arg("value"))
            .define_method("set_weight", &QFont::setWeight, Arg("weight"))
            .define_method("set_word_spacing", &QFont::setWordSpacing, Arg("spacing"))
            .define_method("stretch", &QFont::stretch)
            .define_method("strike_out", &QFont::strikeOut)
            .define_method("style", &QFont::style)
            .define_method("style_hint", &QFont::styleHint)
            .define_method("style_name", &QFont::styleName)
            .define_method("style_strategy", &QFont::styleStrategy)
            .define_method("to_string", &QFont::toString)
            .define_method("underline", &QFont::underline)
            .define_method("unset_feature", &QFont::unsetFeature, Arg("tag"))
            .define_method("unset_variable_axis", &QFont::unsetVariableAxis, Arg("tag"))
            .define_method("variable_axis_tags", &QFont::variableAxisTags)
            .define_method("variable_axis_value", &QFont::variableAxisValue, Arg("tag"))
            .define_method("weight", &QFont::weight)
            .define_method("word_spacing", &QFont::wordSpacing)
            // Static Public Members
            .define_singleton_function("cache_statistics", &QFont::cacheStatistics)
            .define_singleton_function("cleanup", &QFont::cleanup)
            .define_singleton_function("initialize", &QFont::initialize)
            .define_singleton_function("insert_substitution", &QFont::insertSubstitution, Arg("family_name"), Arg("substitute_name"))
            .define_singleton_function("insert_substitutions", &QFont::insertSubstitutions, Arg("family_name"), Arg("substitute_names"))
            .define_singleton_function("remove_substitutions", &QFont::removeSubstitutions, Arg("family_name"))
            .define_singleton_function("substitute", &QFont::substitute, Arg("family_name"))
            .define_singleton_function("substitutes", &QFont::substitutes, Arg("family_name"))
            .define_singleton_function("substitutions", &QFont::substitutions);

    Enum<QFont::Capitalization> rb_cQFontCapitalization =
        // RubyQt6::QtGui::QFont::Capitalization
        define_enum_under<QFont::Capitalization>("Capitalization", rb_cQFont)
            .define_value("MixedCase", QFont::Capitalization::MixedCase)
            .define_value("AllUppercase", QFont::Capitalization::AllUppercase)
            .define_value("AllLowercase", QFont::Capitalization::AllLowercase)
            .define_value("SmallCaps", QFont::Capitalization::SmallCaps)
            .define_value("Capitalize", QFont::Capitalization::Capitalize);

    Enum<QFont::HintingPreference> rb_cQFontHintingPreference =
        // RubyQt6::QtGui::QFont::HintingPreference
        define_enum_under<QFont::HintingPreference>("HintingPreference", rb_cQFont)
            .define_value("PreferDefaultHinting", QFont::HintingPreference::PreferDefaultHinting)
            .define_value("PreferNoHinting", QFont::HintingPreference::PreferNoHinting)
            .define_value("PreferVerticalHinting", QFont::HintingPreference::PreferVerticalHinting)
            .define_value("PreferFullHinting", QFont::HintingPreference::PreferFullHinting);

    Enum<QFont::SpacingType> rb_cQFontSpacingType =
        // RubyQt6::QtGui::QFont::SpacingType
        define_enum_under<QFont::SpacingType>("SpacingType", rb_cQFont)
            .define_value("PercentageSpacing", QFont::SpacingType::PercentageSpacing)
            .define_value("AbsoluteSpacing", QFont::SpacingType::AbsoluteSpacing);

    Enum<QFont::Stretch> rb_cQFontStretch =
        // RubyQt6::QtGui::QFont::Stretch
        define_enum_under<QFont::Stretch>("Stretch", rb_cQFont)
            .define_value("AnyStretch", QFont::Stretch::AnyStretch)
            .define_value("UltraCondensed", QFont::Stretch::UltraCondensed)
            .define_value("ExtraCondensed", QFont::Stretch::ExtraCondensed)
            .define_value("Condensed", QFont::Stretch::Condensed)
            .define_value("SemiCondensed", QFont::Stretch::SemiCondensed)
            .define_value("Unstretched", QFont::Stretch::Unstretched)
            .define_value("SemiExpanded", QFont::Stretch::SemiExpanded)
            .define_value("Expanded", QFont::Stretch::Expanded)
            .define_value("ExtraExpanded", QFont::Stretch::ExtraExpanded)
            .define_value("UltraExpanded", QFont::Stretch::UltraExpanded);

    Enum<QFont::Style> rb_cQFontStyle =
        // RubyQt6::QtGui::QFont::Style
        define_enum_under<QFont::Style>("Style", rb_cQFont)
            .define_value("StyleNormal", QFont::Style::StyleNormal)
            .define_value("StyleItalic", QFont::Style::StyleItalic)
            .define_value("StyleOblique", QFont::Style::StyleOblique);

    Enum<QFont::StyleHint> rb_cQFontStyleHint =
        // RubyQt6::QtGui::QFont::StyleHint
        define_enum_under<QFont::StyleHint>("StyleHint", rb_cQFont)
            .define_value("Helvetica", QFont::StyleHint::Helvetica)
            .define_value("SansSerif", QFont::StyleHint::SansSerif)
            .define_value("Times", QFont::StyleHint::Times)
            .define_value("Serif", QFont::StyleHint::Serif)
            .define_value("Courier", QFont::StyleHint::Courier)
            .define_value("TypeWriter", QFont::StyleHint::TypeWriter)
            .define_value("OldEnglish", QFont::StyleHint::OldEnglish)
            .define_value("Decorative", QFont::StyleHint::Decorative)
            .define_value("System", QFont::StyleHint::System)
            .define_value("AnyStyle", QFont::StyleHint::AnyStyle)
            .define_value("Cursive", QFont::StyleHint::Cursive)
            .define_value("Monospace", QFont::StyleHint::Monospace)
            .define_value("Fantasy", QFont::StyleHint::Fantasy);

    Enum<QFont::StyleStrategy> rb_cQFontStyleStrategy =
        // RubyQt6::QtGui::QFont::StyleStrategy
        define_enum_under<QFont::StyleStrategy>("StyleStrategy", rb_cQFont)
            .define_value("PreferDefault", QFont::StyleStrategy::PreferDefault)
            .define_value("PreferBitmap", QFont::StyleStrategy::PreferBitmap)
            .define_value("PreferDevice", QFont::StyleStrategy::PreferDevice)
            .define_value("PreferOutline", QFont::StyleStrategy::PreferOutline)
            .define_value("ForceOutline", QFont::StyleStrategy::ForceOutline)
            .define_value("PreferMatch", QFont::StyleStrategy::PreferMatch)
            .define_value("PreferQuality", QFont::StyleStrategy::PreferQuality)
            .define_value("PreferAntialias", QFont::StyleStrategy::PreferAntialias)
            .define_value("NoAntialias", QFont::StyleStrategy::NoAntialias)
            .define_value("NoSubpixelAntialias", QFont::StyleStrategy::NoSubpixelAntialias)
            .define_value("PreferNoShaping", QFont::StyleStrategy::PreferNoShaping)
            .define_value("ContextFontMerging", QFont::StyleStrategy::ContextFontMerging)
            .define_value("PreferTypoLineMetrics", QFont::StyleStrategy::PreferTypoLineMetrics)
            .define_value("NoFontMerging", QFont::StyleStrategy::NoFontMerging);

    Enum<QFont::Weight> rb_cQFontWeight =
        // RubyQt6::QtGui::QFont::Weight
        define_enum_under<QFont::Weight>("Weight", rb_cQFont)
            .define_value("Thin", QFont::Weight::Thin)
            .define_value("ExtraLight", QFont::Weight::ExtraLight)
            .define_value("Light", QFont::Weight::Light)
            .define_value("Normal", QFont::Weight::Normal)
            .define_value("Medium", QFont::Weight::Medium)
            .define_value("DemiBold", QFont::Weight::DemiBold)
            .define_value("Bold", QFont::Weight::Bold)
            .define_value("ExtraBold", QFont::Weight::ExtraBold)
            .define_value("Black", QFont::Weight::Black);
}
