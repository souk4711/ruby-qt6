#include "qregularexpression-rb.hpp"
#include <qregularexpression.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQRegularExpression;
Rice::Class rb_cQRegularExpressionMatch;
Rice::Class rb_cQRegularExpressionMatchIterator;

void Init_qregularexpression(Rice::Module rb_mQt6QtCore)
{
    rb_cQRegularExpression =
        // RubyQt6::QtCore::QRegularExpression
        define_class_under<QRegularExpression>(rb_mQt6QtCore, "QRegularExpression")
            // Constructor
            .define_constructor(Constructor<QRegularExpression, const QString &, QRegularExpression::PatternOptions>(), Arg("pattern"), Arg("options"))
            // Public Functions
            .define_method("capture_count", &QRegularExpression::captureCount)
            .define_method("error_string", &QRegularExpression::errorString)
            .define_method<QRegularExpressionMatchIterator (QRegularExpression::*)(const QString &, qsizetype, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const>("global_match", &QRegularExpression::globalMatch, Arg("subject"), Arg("offset") = static_cast<qsizetype>(0), Arg("match_type") = static_cast<QRegularExpression::MatchType>(QRegularExpression::MatchType::NormalMatch), Arg("match_options") = static_cast<QRegularExpression::MatchOptions>(QRegularExpression::MatchOption::NoMatchOption))
            .define_method("global_match_view", &QRegularExpression::globalMatchView, Arg("subject_view"), Arg("offset") = static_cast<qsizetype>(0), Arg("match_type") = static_cast<QRegularExpression::MatchType>(QRegularExpression::MatchType::NormalMatch), Arg("match_options") = static_cast<QRegularExpression::MatchOptions>(QRegularExpression::MatchOption::NoMatchOption))
            .define_method("valid?", &QRegularExpression::isValid)
            .define_method<QRegularExpressionMatch (QRegularExpression::*)(const QString &, qsizetype, QRegularExpression::MatchType, QRegularExpression::MatchOptions) const>("match", &QRegularExpression::match, Arg("subject"), Arg("offset") = static_cast<qsizetype>(0), Arg("match_type") = static_cast<QRegularExpression::MatchType>(QRegularExpression::MatchType::NormalMatch), Arg("match_options") = static_cast<QRegularExpression::MatchOptions>(QRegularExpression::MatchOption::NoMatchOption))
            .define_method("match_view", &QRegularExpression::matchView, Arg("subject_view"), Arg("offset") = static_cast<qsizetype>(0), Arg("match_type") = static_cast<QRegularExpression::MatchType>(QRegularExpression::MatchType::NormalMatch), Arg("match_options") = static_cast<QRegularExpression::MatchOptions>(QRegularExpression::MatchOption::NoMatchOption))
            .define_method("named_capture_groups", &QRegularExpression::namedCaptureGroups)
            .define_method("optimize", &QRegularExpression::optimize)
            .define_method("pattern", &QRegularExpression::pattern)
            .define_method("pattern_error_offset", &QRegularExpression::patternErrorOffset)
            .define_method("pattern_options", &QRegularExpression::patternOptions)
            .define_method("set_pattern", &QRegularExpression::setPattern, Arg("pattern"))
            .define_method("set_pattern_options", &QRegularExpression::setPatternOptions, Arg("options"))
            // Static Public Members
            .define_singleton_function<QString (*)(QStringView)>("anchored_pattern", &QRegularExpression::anchoredPattern, Arg("expression"))
            .define_singleton_function<QString (*)(const QString &)>("anchored_pattern", &QRegularExpression::anchoredPattern, Arg("expression"))
            .define_singleton_function<QString (*)(QStringView)>("escape", &QRegularExpression::escape, Arg("str"))
            .define_singleton_function<QString (*)(const QString &)>("escape", &QRegularExpression::escape, Arg("str"))
            .define_singleton_function("from_wildcard", &QRegularExpression::fromWildcard, Arg("pattern"), Arg("cs") = static_cast<Qt::CaseSensitivity>(Qt::CaseInsensitive), Arg("options") = static_cast<QRegularExpression::WildcardConversionOptions>(QRegularExpression::WildcardConversionOption::DefaultWildcardConversion))
            .define_singleton_function<QString (*)(QStringView, QRegularExpression::WildcardConversionOptions)>("wildcard_to_regular_expression", &QRegularExpression::wildcardToRegularExpression, Arg("str"), Arg("options") = static_cast<QRegularExpression::WildcardConversionOptions>(QRegularExpression::WildcardConversionOption::DefaultWildcardConversion))
            .define_singleton_function<QString (*)(const QString &, QRegularExpression::WildcardConversionOptions)>("wildcard_to_regular_expression", &QRegularExpression::wildcardToRegularExpression, Arg("str"), Arg("options") = static_cast<QRegularExpression::WildcardConversionOptions>(QRegularExpression::WildcardConversionOption::DefaultWildcardConversion));

    Data_Type<QRegularExpression::PatternOption> rb_cQRegularExpressionPatternOption =
        // RubyQt6::QtCore::QRegularExpression::PatternOption
        define_qenum_under<QRegularExpression::PatternOption>(rb_cQRegularExpression, "PatternOption");
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "NoPatternOption", QRegularExpression::PatternOption::NoPatternOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "CaseInsensitiveOption", QRegularExpression::PatternOption::CaseInsensitiveOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "DotMatchesEverythingOption", QRegularExpression::PatternOption::DotMatchesEverythingOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "MultilineOption", QRegularExpression::PatternOption::MultilineOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "ExtendedPatternSyntaxOption", QRegularExpression::PatternOption::ExtendedPatternSyntaxOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "InvertedGreedinessOption", QRegularExpression::PatternOption::InvertedGreedinessOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "DontCaptureOption", QRegularExpression::PatternOption::DontCaptureOption);
        define_qenum_value_under(rb_cQRegularExpressionPatternOption, "UseUnicodePropertiesOption", QRegularExpression::PatternOption::UseUnicodePropertiesOption);

    Data_Type<QRegularExpression::MatchType> rb_cQRegularExpressionMatchType =
        // RubyQt6::QtCore::QRegularExpression::MatchType
        define_qenum_under<QRegularExpression::MatchType>(rb_cQRegularExpression, "MatchType");
        define_qenum_value_under(rb_cQRegularExpressionMatchType, "NormalMatch", QRegularExpression::MatchType::NormalMatch);
        define_qenum_value_under(rb_cQRegularExpressionMatchType, "PartialPreferCompleteMatch", QRegularExpression::MatchType::PartialPreferCompleteMatch);
        define_qenum_value_under(rb_cQRegularExpressionMatchType, "PartialPreferFirstMatch", QRegularExpression::MatchType::PartialPreferFirstMatch);
        define_qenum_value_under(rb_cQRegularExpressionMatchType, "NoMatch", QRegularExpression::MatchType::NoMatch);

    Data_Type<QRegularExpression::MatchOption> rb_cQRegularExpressionMatchOption =
        // RubyQt6::QtCore::QRegularExpression::MatchOption
        define_qenum_under<QRegularExpression::MatchOption>(rb_cQRegularExpression, "MatchOption");
        define_qenum_value_under(rb_cQRegularExpressionMatchOption, "NoMatchOption", QRegularExpression::MatchOption::NoMatchOption);
        define_qenum_value_under(rb_cQRegularExpressionMatchOption, "AnchorAtOffsetMatchOption", QRegularExpression::MatchOption::AnchorAtOffsetMatchOption);
        define_qenum_value_under(rb_cQRegularExpressionMatchOption, "DontCheckSubjectStringMatchOption", QRegularExpression::MatchOption::DontCheckSubjectStringMatchOption);

    Data_Type<QRegularExpression::WildcardConversionOption> rb_cQRegularExpressionWildcardConversionOption =
        // RubyQt6::QtCore::QRegularExpression::WildcardConversionOption
        define_qenum_under<QRegularExpression::WildcardConversionOption>(rb_cQRegularExpression, "WildcardConversionOption");
        define_qenum_value_under(rb_cQRegularExpressionWildcardConversionOption, "DefaultWildcardConversion", QRegularExpression::WildcardConversionOption::DefaultWildcardConversion);
        define_qenum_value_under(rb_cQRegularExpressionWildcardConversionOption, "UnanchoredWildcardConversion", QRegularExpression::WildcardConversionOption::UnanchoredWildcardConversion);
        define_qenum_value_under(rb_cQRegularExpressionWildcardConversionOption, "NonPathWildcardConversion", QRegularExpression::WildcardConversionOption::NonPathWildcardConversion);

    Data_Type<QFlags<QRegularExpression::MatchOption>> rb_cQRegularExpressionMatchOptions =
        // RubyQt6::QtCore::QRegularExpression::MatchOptions
        define_qflags_under<QRegularExpression::MatchOption>(rb_cQRegularExpression, "MatchOptions");

    Data_Type<QFlags<QRegularExpression::PatternOption>> rb_cQRegularExpressionPatternOptions =
        // RubyQt6::QtCore::QRegularExpression::PatternOptions
        define_qflags_under<QRegularExpression::PatternOption>(rb_cQRegularExpression, "PatternOptions");

    Data_Type<QFlags<QRegularExpression::WildcardConversionOption>> rb_cQRegularExpressionWildcardConversionOptions =
        // RubyQt6::QtCore::QRegularExpression::WildcardConversionOptions
        define_qflags_under<QRegularExpression::WildcardConversionOption>(rb_cQRegularExpression, "WildcardConversionOptions");

    rb_cQRegularExpressionMatch =
        // RubyQt6::QtCore::QRegularExpressionMatch
        define_class_under<QRegularExpressionMatch>(rb_mQt6QtCore, "QRegularExpressionMatch")
            // Constructor
            .define_constructor(Constructor<QRegularExpressionMatch>())
            // Public Functions
            .define_method<QString (QRegularExpressionMatch::*)(QAnyStringView) const>("captured", &QRegularExpressionMatch::captured, Arg("name"))
            .define_method<QString (QRegularExpressionMatch::*)(int) const>("captured", &QRegularExpressionMatch::captured, Arg("nth") = static_cast<int>(0))
            .define_method<qsizetype (QRegularExpressionMatch::*)(QAnyStringView) const>("captured_end", &QRegularExpressionMatch::capturedEnd, Arg("name"))
            .define_method<qsizetype (QRegularExpressionMatch::*)(int) const>("captured_end", &QRegularExpressionMatch::capturedEnd, Arg("nth") = static_cast<int>(0))
            .define_method<qsizetype (QRegularExpressionMatch::*)(QAnyStringView) const>("captured_length", &QRegularExpressionMatch::capturedLength, Arg("name"))
            .define_method<qsizetype (QRegularExpressionMatch::*)(int) const>("captured_length", &QRegularExpressionMatch::capturedLength, Arg("nth") = static_cast<int>(0))
            .define_method<qsizetype (QRegularExpressionMatch::*)(QAnyStringView) const>("captured_start", &QRegularExpressionMatch::capturedStart, Arg("name"))
            .define_method<qsizetype (QRegularExpressionMatch::*)(int) const>("captured_start", &QRegularExpressionMatch::capturedStart, Arg("nth") = static_cast<int>(0))
            .define_method("captured_texts", &QRegularExpressionMatch::capturedTexts)
            .define_method<QStringView (QRegularExpressionMatch::*)(QAnyStringView) const>("captured_view", &QRegularExpressionMatch::capturedView, Arg("name"))
            .define_method<QStringView (QRegularExpressionMatch::*)(int) const>("captured_view", &QRegularExpressionMatch::capturedView, Arg("nth") = static_cast<int>(0))
            .define_method<bool (QRegularExpressionMatch::*)(QAnyStringView) const>("has_captured", &QRegularExpressionMatch::hasCaptured, Arg("name"))
            .define_method<bool (QRegularExpressionMatch::*)(int) const>("has_captured", &QRegularExpressionMatch::hasCaptured, Arg("nth"))
            .define_method("has_match", &QRegularExpressionMatch::hasMatch)
            .define_method("has_partial_match", &QRegularExpressionMatch::hasPartialMatch)
            .define_method("valid?", &QRegularExpressionMatch::isValid)
            .define_method("last_captured_index", &QRegularExpressionMatch::lastCapturedIndex)
            .define_method("match_options", &QRegularExpressionMatch::matchOptions)
            .define_method("match_type", &QRegularExpressionMatch::matchType)
            .define_method("regular_expression", &QRegularExpressionMatch::regularExpression);

    rb_cQRegularExpressionMatchIterator =
        // RubyQt6::QtCore::QRegularExpressionMatchIterator
        define_class_under<QRegularExpressionMatchIterator>(rb_mQt6QtCore, "QRegularExpressionMatchIterator")
            // Public Functions
            .define_method("has_next", &QRegularExpressionMatchIterator::hasNext)
            .define_method("match_options", &QRegularExpressionMatchIterator::matchOptions)
            .define_method("match_type", &QRegularExpressionMatchIterator::matchType)
            .define_method("next", &QRegularExpressionMatchIterator::next)
            .define_method("peek_next", &QRegularExpressionMatchIterator::peekNext)
            .define_method("regular_expression", &QRegularExpressionMatchIterator::regularExpression);
}
