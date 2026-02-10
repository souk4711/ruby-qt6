#include "qfont-rb.hpp"
#include <qfont.h>
#include <rice/qt6/qenum.hpp>

#include <QStringList>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFont;

void Init_qfont(Module rb_mQt6QtGui)
{
    rb_cQFont =
        // RubyQt6::QtGui::QFont
        define_class_under<QFont>(rb_mQt6QtGui, "QFont")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QFont *lhs, QFont *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            // Constructor
            .define_constructor(Constructor<QFont>())
            .define_constructor(Constructor<QFont, const QString &>(), Arg("family"))
            .define_constructor(Constructor<QFont, const QString &, int>(), Arg("family"), Arg("point_size"))
            .define_constructor(Constructor<QFont, const QString &, int, int>(), Arg("family"), Arg("point_size"), Arg("weight"))
            .define_constructor(Constructor<QFont, const QStringList &>(), Arg("families"))
            .define_constructor(Constructor<QFont, const QStringList &, int>(), Arg("families"), Arg("point_size"))
            .define_constructor(Constructor<QFont, const QStringList &, int, int>(), Arg("families"), Arg("point_size"), Arg("weight"))
            .define_constructor(Constructor<QFont, const QFont &>(), Arg("other"))
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
            .define_method("_set_family", &QFont::setFamily, Arg("family"))
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

    Data_Type<QFont::Capitalization> rb_cQFontCapitalization =
        // RubyQt6::QtGui::QFont::Capitalization
        define_qenum_under<QFont::Capitalization>(rb_cQFont, "Capitalization");
        define_qenum_value_under(rb_cQFontCapitalization, "MixedCase", QFont::Capitalization::MixedCase);
        define_qenum_value_under(rb_cQFontCapitalization, "AllUppercase", QFont::Capitalization::AllUppercase);
        define_qenum_value_under(rb_cQFontCapitalization, "AllLowercase", QFont::Capitalization::AllLowercase);
        define_qenum_value_under(rb_cQFontCapitalization, "SmallCaps", QFont::Capitalization::SmallCaps);
        define_qenum_value_under(rb_cQFontCapitalization, "Capitalize", QFont::Capitalization::Capitalize);

    Data_Type<QFont::HintingPreference> rb_cQFontHintingPreference =
        // RubyQt6::QtGui::QFont::HintingPreference
        define_qenum_under<QFont::HintingPreference>(rb_cQFont, "HintingPreference");
        define_qenum_value_under(rb_cQFontHintingPreference, "PreferDefaultHinting", QFont::HintingPreference::PreferDefaultHinting);
        define_qenum_value_under(rb_cQFontHintingPreference, "PreferNoHinting", QFont::HintingPreference::PreferNoHinting);
        define_qenum_value_under(rb_cQFontHintingPreference, "PreferVerticalHinting", QFont::HintingPreference::PreferVerticalHinting);
        define_qenum_value_under(rb_cQFontHintingPreference, "PreferFullHinting", QFont::HintingPreference::PreferFullHinting);

    Data_Type<QFont::SpacingType> rb_cQFontSpacingType =
        // RubyQt6::QtGui::QFont::SpacingType
        define_qenum_under<QFont::SpacingType>(rb_cQFont, "SpacingType");
        define_qenum_value_under(rb_cQFontSpacingType, "PercentageSpacing", QFont::SpacingType::PercentageSpacing);
        define_qenum_value_under(rb_cQFontSpacingType, "AbsoluteSpacing", QFont::SpacingType::AbsoluteSpacing);

    Data_Type<QFont::Stretch> rb_cQFontStretch =
        // RubyQt6::QtGui::QFont::Stretch
        define_qenum_under<QFont::Stretch>(rb_cQFont, "Stretch");
        define_qenum_value_under(rb_cQFontStretch, "AnyStretch", QFont::Stretch::AnyStretch);
        define_qenum_value_under(rb_cQFontStretch, "UltraCondensed", QFont::Stretch::UltraCondensed);
        define_qenum_value_under(rb_cQFontStretch, "ExtraCondensed", QFont::Stretch::ExtraCondensed);
        define_qenum_value_under(rb_cQFontStretch, "Condensed", QFont::Stretch::Condensed);
        define_qenum_value_under(rb_cQFontStretch, "SemiCondensed", QFont::Stretch::SemiCondensed);
        define_qenum_value_under(rb_cQFontStretch, "Unstretched", QFont::Stretch::Unstretched);
        define_qenum_value_under(rb_cQFontStretch, "SemiExpanded", QFont::Stretch::SemiExpanded);
        define_qenum_value_under(rb_cQFontStretch, "Expanded", QFont::Stretch::Expanded);
        define_qenum_value_under(rb_cQFontStretch, "ExtraExpanded", QFont::Stretch::ExtraExpanded);
        define_qenum_value_under(rb_cQFontStretch, "UltraExpanded", QFont::Stretch::UltraExpanded);

    Data_Type<QFont::Style> rb_cQFontStyle =
        // RubyQt6::QtGui::QFont::Style
        define_qenum_under<QFont::Style>(rb_cQFont, "Style");
        define_qenum_value_under(rb_cQFontStyle, "StyleNormal", QFont::Style::StyleNormal);
        define_qenum_value_under(rb_cQFontStyle, "StyleItalic", QFont::Style::StyleItalic);
        define_qenum_value_under(rb_cQFontStyle, "StyleOblique", QFont::Style::StyleOblique);

    Data_Type<QFont::StyleHint> rb_cQFontStyleHint =
        // RubyQt6::QtGui::QFont::StyleHint
        define_qenum_under<QFont::StyleHint>(rb_cQFont, "StyleHint");
        define_qenum_value_under(rb_cQFontStyleHint, "Helvetica", QFont::StyleHint::Helvetica);
        define_qenum_value_under(rb_cQFontStyleHint, "SansSerif", QFont::StyleHint::SansSerif);
        define_qenum_value_under(rb_cQFontStyleHint, "Times", QFont::StyleHint::Times);
        define_qenum_value_under(rb_cQFontStyleHint, "Serif", QFont::StyleHint::Serif);
        define_qenum_value_under(rb_cQFontStyleHint, "Courier", QFont::StyleHint::Courier);
        define_qenum_value_under(rb_cQFontStyleHint, "TypeWriter", QFont::StyleHint::TypeWriter);
        define_qenum_value_under(rb_cQFontStyleHint, "OldEnglish", QFont::StyleHint::OldEnglish);
        define_qenum_value_under(rb_cQFontStyleHint, "Decorative", QFont::StyleHint::Decorative);
        define_qenum_value_under(rb_cQFontStyleHint, "System", QFont::StyleHint::System);
        define_qenum_value_under(rb_cQFontStyleHint, "AnyStyle", QFont::StyleHint::AnyStyle);
        define_qenum_value_under(rb_cQFontStyleHint, "Cursive", QFont::StyleHint::Cursive);
        define_qenum_value_under(rb_cQFontStyleHint, "Monospace", QFont::StyleHint::Monospace);
        define_qenum_value_under(rb_cQFontStyleHint, "Fantasy", QFont::StyleHint::Fantasy);

    Data_Type<QFont::StyleStrategy> rb_cQFontStyleStrategy =
        // RubyQt6::QtGui::QFont::StyleStrategy
        define_qenum_under<QFont::StyleStrategy>(rb_cQFont, "StyleStrategy");
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferDefault", QFont::StyleStrategy::PreferDefault);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferBitmap", QFont::StyleStrategy::PreferBitmap);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferDevice", QFont::StyleStrategy::PreferDevice);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferOutline", QFont::StyleStrategy::PreferOutline);
        define_qenum_value_under(rb_cQFontStyleStrategy, "ForceOutline", QFont::StyleStrategy::ForceOutline);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferMatch", QFont::StyleStrategy::PreferMatch);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferQuality", QFont::StyleStrategy::PreferQuality);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferAntialias", QFont::StyleStrategy::PreferAntialias);
        define_qenum_value_under(rb_cQFontStyleStrategy, "NoAntialias", QFont::StyleStrategy::NoAntialias);
        define_qenum_value_under(rb_cQFontStyleStrategy, "NoSubpixelAntialias", QFont::StyleStrategy::NoSubpixelAntialias);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferNoShaping", QFont::StyleStrategy::PreferNoShaping);
        define_qenum_value_under(rb_cQFontStyleStrategy, "ContextFontMerging", QFont::StyleStrategy::ContextFontMerging);
        define_qenum_value_under(rb_cQFontStyleStrategy, "PreferTypoLineMetrics", QFont::StyleStrategy::PreferTypoLineMetrics);
        define_qenum_value_under(rb_cQFontStyleStrategy, "NoFontMerging", QFont::StyleStrategy::NoFontMerging);

    Data_Type<QFont::Weight> rb_cQFontWeight =
        // RubyQt6::QtGui::QFont::Weight
        define_qenum_under<QFont::Weight>(rb_cQFont, "Weight");
        define_qenum_value_under(rb_cQFontWeight, "Thin", QFont::Weight::Thin);
        define_qenum_value_under(rb_cQFontWeight, "ExtraLight", QFont::Weight::ExtraLight);
        define_qenum_value_under(rb_cQFontWeight, "Light", QFont::Weight::Light);
        define_qenum_value_under(rb_cQFontWeight, "Normal", QFont::Weight::Normal);
        define_qenum_value_under(rb_cQFontWeight, "Medium", QFont::Weight::Medium);
        define_qenum_value_under(rb_cQFontWeight, "DemiBold", QFont::Weight::DemiBold);
        define_qenum_value_under(rb_cQFontWeight, "Bold", QFont::Weight::Bold);
        define_qenum_value_under(rb_cQFontWeight, "ExtraBold", QFont::Weight::ExtraBold);
        define_qenum_value_under(rb_cQFontWeight, "Black", QFont::Weight::Black);
}
