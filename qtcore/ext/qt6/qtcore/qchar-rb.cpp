#include "qchar-rb.hpp"
#include <qchar.h>
#include <rice/qenum.hpp>

#include <QString>

using namespace Rice;

Rice::Class rb_cQChar;

void Init_qchar(Rice::Module rb_mQt6QtCore)
{
    rb_cQChar =
        // RubyQt6::QtCore::QChar
        define_class_under<QChar>(rb_mQt6QtCore, "QChar")
            // RubyQt6-Defined Functions
            .define_method("to_std_string", [](QChar *self) -> std::string { return QString(*self).toStdString(); })
            // Constructor
            .define_constructor(Constructor<QChar, int>(), Arg("code"))
            // Public Functions
            .define_method<QChar::Category (QChar::*)() const noexcept>("category", &QChar::category)
            .define_method("cell", &QChar::cell)
            .define_method<unsigned char (QChar::*)() const noexcept>("combining_class", &QChar::combiningClass)
            .define_method<QString (QChar::*)() const>("decomposition", &QChar::decomposition)
            .define_method<QChar::Decomposition (QChar::*)() const noexcept>("decomposition_tag", &QChar::decompositionTag)
            .define_method<int (QChar::*)() const noexcept>("digit_value", &QChar::digitValue)
            .define_method<QChar::Direction (QChar::*)() const noexcept>("direction", &QChar::direction)
            .define_method<bool (QChar::*)() const noexcept>("has_mirrored", &QChar::hasMirrored)
            .define_method<bool (QChar::*)() const noexcept>("digit?", &QChar::isDigit)
            .define_method<bool (QChar::*)() const noexcept>("high_surrogate?", &QChar::isHighSurrogate)
            .define_method<bool (QChar::*)() const noexcept>("letter?", &QChar::isLetter)
            .define_method<bool (QChar::*)() const noexcept>("letter_or_number?", &QChar::isLetterOrNumber)
            .define_method<bool (QChar::*)() const noexcept>("low_surrogate?", &QChar::isLowSurrogate)
            .define_method<bool (QChar::*)() const noexcept>("lower?", &QChar::isLower)
            .define_method<bool (QChar::*)() const noexcept>("mark?", &QChar::isMark)
            .define_method<bool (QChar::*)() const noexcept>("non_character?", &QChar::isNonCharacter)
            .define_method("null?", &QChar::isNull)
            .define_method<bool (QChar::*)() const noexcept>("number?", &QChar::isNumber)
            .define_method<bool (QChar::*)() const noexcept>("print?", &QChar::isPrint)
            .define_method<bool (QChar::*)() const noexcept>("punct?", &QChar::isPunct)
            .define_method<bool (QChar::*)() const noexcept>("space?", &QChar::isSpace)
            .define_method<bool (QChar::*)() const noexcept>("surrogate?", &QChar::isSurrogate)
            .define_method<bool (QChar::*)() const noexcept>("symbol?", &QChar::isSymbol)
            .define_method<bool (QChar::*)() const noexcept>("title_case?", &QChar::isTitleCase)
            .define_method<bool (QChar::*)() const noexcept>("upper?", &QChar::isUpper)
            .define_method<QChar::JoiningType (QChar::*)() const noexcept>("joining_type", &QChar::joiningType)
            .define_method<QChar (QChar::*)() const noexcept>("mirrored_char", &QChar::mirroredChar)
            .define_method("row", &QChar::row)
            .define_method<QChar::Script (QChar::*)() const noexcept>("script", &QChar::script)
            .define_method("set_cell", &QChar::setCell, Arg("acell"))
            .define_method("set_row", &QChar::setRow, Arg("arow"))
            .define_method<QChar (QChar::*)() const noexcept>("to_case_folded", &QChar::toCaseFolded)
            .define_method("to_latin1", &QChar::toLatin1)
            .define_method<QChar (QChar::*)() const noexcept>("to_lower", &QChar::toLower)
            .define_method<QChar (QChar::*)() const noexcept>("to_title_case", &QChar::toTitleCase)
            .define_method<QChar (QChar::*)() const noexcept>("to_upper", &QChar::toUpper)
            // .define_method<char16_t (QChar::*)() const noexcept>("unicode", &QChar::unicode)
            .define_method<QChar::UnicodeVersion (QChar::*)() const noexcept>("unicode_version", &QChar::unicodeVersion);

    Data_Type<QChar::Category> rb_cQCharCategory =
        // RubyQt6::QtCore::QChar::Category
        define_qenum_under<QChar::Category>(rb_cQChar, "Category");
        define_qenum_value_under(rb_cQCharCategory, "Mark_NonSpacing", QChar::Category::Mark_NonSpacing);
        define_qenum_value_under(rb_cQCharCategory, "Mark_SpacingCombining", QChar::Category::Mark_SpacingCombining);
        define_qenum_value_under(rb_cQCharCategory, "Mark_Enclosing", QChar::Category::Mark_Enclosing);
        define_qenum_value_under(rb_cQCharCategory, "Number_DecimalDigit", QChar::Category::Number_DecimalDigit);
        define_qenum_value_under(rb_cQCharCategory, "Number_Letter", QChar::Category::Number_Letter);
        define_qenum_value_under(rb_cQCharCategory, "Number_Other", QChar::Category::Number_Other);
        define_qenum_value_under(rb_cQCharCategory, "Separator_Space", QChar::Category::Separator_Space);
        define_qenum_value_under(rb_cQCharCategory, "Separator_Line", QChar::Category::Separator_Line);
        define_qenum_value_under(rb_cQCharCategory, "Separator_Paragraph", QChar::Category::Separator_Paragraph);
        define_qenum_value_under(rb_cQCharCategory, "Other_Control", QChar::Category::Other_Control);
        define_qenum_value_under(rb_cQCharCategory, "Other_Format", QChar::Category::Other_Format);
        define_qenum_value_under(rb_cQCharCategory, "Other_Surrogate", QChar::Category::Other_Surrogate);
        define_qenum_value_under(rb_cQCharCategory, "Other_PrivateUse", QChar::Category::Other_PrivateUse);
        define_qenum_value_under(rb_cQCharCategory, "Other_NotAssigned", QChar::Category::Other_NotAssigned);
        define_qenum_value_under(rb_cQCharCategory, "Letter_Uppercase", QChar::Category::Letter_Uppercase);
        define_qenum_value_under(rb_cQCharCategory, "Letter_Lowercase", QChar::Category::Letter_Lowercase);
        define_qenum_value_under(rb_cQCharCategory, "Letter_Titlecase", QChar::Category::Letter_Titlecase);
        define_qenum_value_under(rb_cQCharCategory, "Letter_Modifier", QChar::Category::Letter_Modifier);
        define_qenum_value_under(rb_cQCharCategory, "Letter_Other", QChar::Category::Letter_Other);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_Connector", QChar::Category::Punctuation_Connector);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_Dash", QChar::Category::Punctuation_Dash);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_Open", QChar::Category::Punctuation_Open);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_Close", QChar::Category::Punctuation_Close);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_InitialQuote", QChar::Category::Punctuation_InitialQuote);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_FinalQuote", QChar::Category::Punctuation_FinalQuote);
        define_qenum_value_under(rb_cQCharCategory, "Punctuation_Other", QChar::Category::Punctuation_Other);
        define_qenum_value_under(rb_cQCharCategory, "Symbol_Math", QChar::Category::Symbol_Math);
        define_qenum_value_under(rb_cQCharCategory, "Symbol_Currency", QChar::Category::Symbol_Currency);
        define_qenum_value_under(rb_cQCharCategory, "Symbol_Modifier", QChar::Category::Symbol_Modifier);
        define_qenum_value_under(rb_cQCharCategory, "Symbol_Other", QChar::Category::Symbol_Other);

    Data_Type<QChar::CombiningClass> rb_cQCharCombiningClass =
        // RubyQt6::QtCore::QChar::CombiningClass
        define_qenum_under<QChar::CombiningClass>(rb_cQChar, "CombiningClass");
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_BelowLeftAttached", QChar::CombiningClass::Combining_BelowLeftAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_BelowAttached", QChar::CombiningClass::Combining_BelowAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_BelowRightAttached", QChar::CombiningClass::Combining_BelowRightAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_LeftAttached", QChar::CombiningClass::Combining_LeftAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_RightAttached", QChar::CombiningClass::Combining_RightAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_AboveLeftAttached", QChar::CombiningClass::Combining_AboveLeftAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_AboveAttached", QChar::CombiningClass::Combining_AboveAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_AboveRightAttached", QChar::CombiningClass::Combining_AboveRightAttached);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_BelowLeft", QChar::CombiningClass::Combining_BelowLeft);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_Below", QChar::CombiningClass::Combining_Below);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_BelowRight", QChar::CombiningClass::Combining_BelowRight);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_Left", QChar::CombiningClass::Combining_Left);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_Right", QChar::CombiningClass::Combining_Right);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_AboveLeft", QChar::CombiningClass::Combining_AboveLeft);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_Above", QChar::CombiningClass::Combining_Above);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_AboveRight", QChar::CombiningClass::Combining_AboveRight);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_DoubleBelow", QChar::CombiningClass::Combining_DoubleBelow);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_DoubleAbove", QChar::CombiningClass::Combining_DoubleAbove);
        define_qenum_value_under(rb_cQCharCombiningClass, "Combining_IotaSubscript", QChar::CombiningClass::Combining_IotaSubscript);

    Data_Type<QChar::Decomposition> rb_cQCharDecomposition =
        // RubyQt6::QtCore::QChar::Decomposition
        define_qenum_under<QChar::Decomposition>(rb_cQChar, "Decomposition");
        define_qenum_value_under(rb_cQCharDecomposition, "NoDecomposition", QChar::Decomposition::NoDecomposition);
        define_qenum_value_under(rb_cQCharDecomposition, "Canonical", QChar::Decomposition::Canonical);
        define_qenum_value_under(rb_cQCharDecomposition, "Font", QChar::Decomposition::Font);
        define_qenum_value_under(rb_cQCharDecomposition, "NoBreak", QChar::Decomposition::NoBreak);
        define_qenum_value_under(rb_cQCharDecomposition, "Initial", QChar::Decomposition::Initial);
        define_qenum_value_under(rb_cQCharDecomposition, "Medial", QChar::Decomposition::Medial);
        define_qenum_value_under(rb_cQCharDecomposition, "Final", QChar::Decomposition::Final);
        define_qenum_value_under(rb_cQCharDecomposition, "Isolated", QChar::Decomposition::Isolated);
        define_qenum_value_under(rb_cQCharDecomposition, "Circle", QChar::Decomposition::Circle);
        define_qenum_value_under(rb_cQCharDecomposition, "Super", QChar::Decomposition::Super);
        define_qenum_value_under(rb_cQCharDecomposition, "Sub", QChar::Decomposition::Sub);
        define_qenum_value_under(rb_cQCharDecomposition, "Vertical", QChar::Decomposition::Vertical);
        define_qenum_value_under(rb_cQCharDecomposition, "Wide", QChar::Decomposition::Wide);
        define_qenum_value_under(rb_cQCharDecomposition, "Narrow", QChar::Decomposition::Narrow);
        define_qenum_value_under(rb_cQCharDecomposition, "Small", QChar::Decomposition::Small);
        define_qenum_value_under(rb_cQCharDecomposition, "Square", QChar::Decomposition::Square);
        define_qenum_value_under(rb_cQCharDecomposition, "Compat", QChar::Decomposition::Compat);
        define_qenum_value_under(rb_cQCharDecomposition, "Fraction", QChar::Decomposition::Fraction);

    Data_Type<QChar::Direction> rb_cQCharDirection =
        // RubyQt6::QtCore::QChar::Direction
        define_qenum_under<QChar::Direction>(rb_cQChar, "Direction");
        define_qenum_value_under(rb_cQCharDirection, "DirL", QChar::Direction::DirL);
        define_qenum_value_under(rb_cQCharDirection, "DirR", QChar::Direction::DirR);
        define_qenum_value_under(rb_cQCharDirection, "DirEN", QChar::Direction::DirEN);
        define_qenum_value_under(rb_cQCharDirection, "DirES", QChar::Direction::DirES);
        define_qenum_value_under(rb_cQCharDirection, "DirET", QChar::Direction::DirET);
        define_qenum_value_under(rb_cQCharDirection, "DirAN", QChar::Direction::DirAN);
        define_qenum_value_under(rb_cQCharDirection, "DirCS", QChar::Direction::DirCS);
        define_qenum_value_under(rb_cQCharDirection, "DirB", QChar::Direction::DirB);
        define_qenum_value_under(rb_cQCharDirection, "DirS", QChar::Direction::DirS);
        define_qenum_value_under(rb_cQCharDirection, "DirWS", QChar::Direction::DirWS);
        define_qenum_value_under(rb_cQCharDirection, "DirON", QChar::Direction::DirON);
        define_qenum_value_under(rb_cQCharDirection, "DirLRE", QChar::Direction::DirLRE);
        define_qenum_value_under(rb_cQCharDirection, "DirLRO", QChar::Direction::DirLRO);
        define_qenum_value_under(rb_cQCharDirection, "DirAL", QChar::Direction::DirAL);
        define_qenum_value_under(rb_cQCharDirection, "DirRLE", QChar::Direction::DirRLE);
        define_qenum_value_under(rb_cQCharDirection, "DirRLO", QChar::Direction::DirRLO);
        define_qenum_value_under(rb_cQCharDirection, "DirPDF", QChar::Direction::DirPDF);
        define_qenum_value_under(rb_cQCharDirection, "DirNSM", QChar::Direction::DirNSM);
        define_qenum_value_under(rb_cQCharDirection, "DirBN", QChar::Direction::DirBN);
        define_qenum_value_under(rb_cQCharDirection, "DirLRI", QChar::Direction::DirLRI);
        define_qenum_value_under(rb_cQCharDirection, "DirRLI", QChar::Direction::DirRLI);
        define_qenum_value_under(rb_cQCharDirection, "DirFSI", QChar::Direction::DirFSI);
        define_qenum_value_under(rb_cQCharDirection, "DirPDI", QChar::Direction::DirPDI);


    Data_Type<QChar::JoiningType> rb_cQCharJoiningType =
        // RubyQt6::QtCore::QChar::JoiningType
        define_qenum_under<QChar::JoiningType>(rb_cQChar, "JoiningType");
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_None", QChar::JoiningType::Joining_None);
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_Causing", QChar::JoiningType::Joining_Causing);
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_Dual", QChar::JoiningType::Joining_Dual);
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_Right", QChar::JoiningType::Joining_Right);
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_Left", QChar::JoiningType::Joining_Left);
        define_qenum_value_under(rb_cQCharJoiningType, "Joining_Transparent", QChar::JoiningType::Joining_Transparent);

    Data_Type<QChar::Script> rb_cQCharScript =
        // RubyQt6::QtCore::QChar::Script
        define_qenum_under<QChar::Script>(rb_cQChar, "Script");
        define_qenum_value_under(rb_cQCharScript, "Script_Unknown", QChar::Script::Script_Unknown);
        define_qenum_value_under(rb_cQCharScript, "Script_Inherited", QChar::Script::Script_Inherited);
        define_qenum_value_under(rb_cQCharScript, "Script_Common", QChar::Script::Script_Common);
        define_qenum_value_under(rb_cQCharScript, "Script_Latin", QChar::Script::Script_Latin);
        define_qenum_value_under(rb_cQCharScript, "Script_Greek", QChar::Script::Script_Greek);
        define_qenum_value_under(rb_cQCharScript, "Script_Cyrillic", QChar::Script::Script_Cyrillic);
        define_qenum_value_under(rb_cQCharScript, "Script_Armenian", QChar::Script::Script_Armenian);
        define_qenum_value_under(rb_cQCharScript, "Script_Hebrew", QChar::Script::Script_Hebrew);
        define_qenum_value_under(rb_cQCharScript, "Script_Arabic", QChar::Script::Script_Arabic);
        define_qenum_value_under(rb_cQCharScript, "Script_Syriac", QChar::Script::Script_Syriac);
        define_qenum_value_under(rb_cQCharScript, "Script_Thaana", QChar::Script::Script_Thaana);
        define_qenum_value_under(rb_cQCharScript, "Script_Devanagari", QChar::Script::Script_Devanagari);
        define_qenum_value_under(rb_cQCharScript, "Script_Bengali", QChar::Script::Script_Bengali);
        define_qenum_value_under(rb_cQCharScript, "Script_Gurmukhi", QChar::Script::Script_Gurmukhi);
        define_qenum_value_under(rb_cQCharScript, "Script_Gujarati", QChar::Script::Script_Gujarati);
        define_qenum_value_under(rb_cQCharScript, "Script_Oriya", QChar::Script::Script_Oriya);
        define_qenum_value_under(rb_cQCharScript, "Script_Tamil", QChar::Script::Script_Tamil);
        define_qenum_value_under(rb_cQCharScript, "Script_Telugu", QChar::Script::Script_Telugu);
        define_qenum_value_under(rb_cQCharScript, "Script_Kannada", QChar::Script::Script_Kannada);
        define_qenum_value_under(rb_cQCharScript, "Script_Malayalam", QChar::Script::Script_Malayalam);
        define_qenum_value_under(rb_cQCharScript, "Script_Sinhala", QChar::Script::Script_Sinhala);
        define_qenum_value_under(rb_cQCharScript, "Script_Thai", QChar::Script::Script_Thai);
        define_qenum_value_under(rb_cQCharScript, "Script_Lao", QChar::Script::Script_Lao);
        define_qenum_value_under(rb_cQCharScript, "Script_Tibetan", QChar::Script::Script_Tibetan);
        define_qenum_value_under(rb_cQCharScript, "Script_Myanmar", QChar::Script::Script_Myanmar);
        define_qenum_value_under(rb_cQCharScript, "Script_Georgian", QChar::Script::Script_Georgian);
        define_qenum_value_under(rb_cQCharScript, "Script_Hangul", QChar::Script::Script_Hangul);
        define_qenum_value_under(rb_cQCharScript, "Script_Ethiopic", QChar::Script::Script_Ethiopic);
        define_qenum_value_under(rb_cQCharScript, "Script_Cherokee", QChar::Script::Script_Cherokee);
        define_qenum_value_under(rb_cQCharScript, "Script_CanadianAboriginal", QChar::Script::Script_CanadianAboriginal);
        define_qenum_value_under(rb_cQCharScript, "Script_Ogham", QChar::Script::Script_Ogham);
        define_qenum_value_under(rb_cQCharScript, "Script_Runic", QChar::Script::Script_Runic);
        define_qenum_value_under(rb_cQCharScript, "Script_Khmer", QChar::Script::Script_Khmer);
        define_qenum_value_under(rb_cQCharScript, "Script_Mongolian", QChar::Script::Script_Mongolian);
        define_qenum_value_under(rb_cQCharScript, "Script_Hiragana", QChar::Script::Script_Hiragana);
        define_qenum_value_under(rb_cQCharScript, "Script_Katakana", QChar::Script::Script_Katakana);
        define_qenum_value_under(rb_cQCharScript, "Script_Bopomofo", QChar::Script::Script_Bopomofo);
        define_qenum_value_under(rb_cQCharScript, "Script_Han", QChar::Script::Script_Han);
        define_qenum_value_under(rb_cQCharScript, "Script_Yi", QChar::Script::Script_Yi);
        define_qenum_value_under(rb_cQCharScript, "Script_OldItalic", QChar::Script::Script_OldItalic);
        define_qenum_value_under(rb_cQCharScript, "Script_Gothic", QChar::Script::Script_Gothic);
        define_qenum_value_under(rb_cQCharScript, "Script_Deseret", QChar::Script::Script_Deseret);
        define_qenum_value_under(rb_cQCharScript, "Script_Tagalog", QChar::Script::Script_Tagalog);
        define_qenum_value_under(rb_cQCharScript, "Script_Hanunoo", QChar::Script::Script_Hanunoo);
        define_qenum_value_under(rb_cQCharScript, "Script_Buhid", QChar::Script::Script_Buhid);
        define_qenum_value_under(rb_cQCharScript, "Script_Tagbanwa", QChar::Script::Script_Tagbanwa);
        define_qenum_value_under(rb_cQCharScript, "Script_Coptic", QChar::Script::Script_Coptic);
        define_qenum_value_under(rb_cQCharScript, "Script_Limbu", QChar::Script::Script_Limbu);
        define_qenum_value_under(rb_cQCharScript, "Script_TaiLe", QChar::Script::Script_TaiLe);
        define_qenum_value_under(rb_cQCharScript, "Script_LinearB", QChar::Script::Script_LinearB);
        define_qenum_value_under(rb_cQCharScript, "Script_Ugaritic", QChar::Script::Script_Ugaritic);
        define_qenum_value_under(rb_cQCharScript, "Script_Shavian", QChar::Script::Script_Shavian);
        define_qenum_value_under(rb_cQCharScript, "Script_Osmanya", QChar::Script::Script_Osmanya);
        define_qenum_value_under(rb_cQCharScript, "Script_Cypriot", QChar::Script::Script_Cypriot);
        define_qenum_value_under(rb_cQCharScript, "Script_Braille", QChar::Script::Script_Braille);
        define_qenum_value_under(rb_cQCharScript, "Script_Buginese", QChar::Script::Script_Buginese);
        define_qenum_value_under(rb_cQCharScript, "Script_NewTaiLue", QChar::Script::Script_NewTaiLue);
        define_qenum_value_under(rb_cQCharScript, "Script_Glagolitic", QChar::Script::Script_Glagolitic);
        define_qenum_value_under(rb_cQCharScript, "Script_Tifinagh", QChar::Script::Script_Tifinagh);
        define_qenum_value_under(rb_cQCharScript, "Script_SylotiNagri", QChar::Script::Script_SylotiNagri);
        define_qenum_value_under(rb_cQCharScript, "Script_OldPersian", QChar::Script::Script_OldPersian);
        define_qenum_value_under(rb_cQCharScript, "Script_Kharoshthi", QChar::Script::Script_Kharoshthi);
        define_qenum_value_under(rb_cQCharScript, "Script_Balinese", QChar::Script::Script_Balinese);
        define_qenum_value_under(rb_cQCharScript, "Script_Cuneiform", QChar::Script::Script_Cuneiform);
        define_qenum_value_under(rb_cQCharScript, "Script_Phoenician", QChar::Script::Script_Phoenician);
        define_qenum_value_under(rb_cQCharScript, "Script_PhagsPa", QChar::Script::Script_PhagsPa);
        define_qenum_value_under(rb_cQCharScript, "Script_Nko", QChar::Script::Script_Nko);
        define_qenum_value_under(rb_cQCharScript, "Script_Sundanese", QChar::Script::Script_Sundanese);
        define_qenum_value_under(rb_cQCharScript, "Script_Lepcha", QChar::Script::Script_Lepcha);
        define_qenum_value_under(rb_cQCharScript, "Script_OlChiki", QChar::Script::Script_OlChiki);
        define_qenum_value_under(rb_cQCharScript, "Script_Vai", QChar::Script::Script_Vai);
        define_qenum_value_under(rb_cQCharScript, "Script_Saurashtra", QChar::Script::Script_Saurashtra);
        define_qenum_value_under(rb_cQCharScript, "Script_KayahLi", QChar::Script::Script_KayahLi);
        define_qenum_value_under(rb_cQCharScript, "Script_Rejang", QChar::Script::Script_Rejang);
        define_qenum_value_under(rb_cQCharScript, "Script_Lycian", QChar::Script::Script_Lycian);
        define_qenum_value_under(rb_cQCharScript, "Script_Carian", QChar::Script::Script_Carian);
        define_qenum_value_under(rb_cQCharScript, "Script_Lydian", QChar::Script::Script_Lydian);
        define_qenum_value_under(rb_cQCharScript, "Script_Cham", QChar::Script::Script_Cham);
        define_qenum_value_under(rb_cQCharScript, "Script_TaiTham", QChar::Script::Script_TaiTham);
        define_qenum_value_under(rb_cQCharScript, "Script_TaiViet", QChar::Script::Script_TaiViet);
        define_qenum_value_under(rb_cQCharScript, "Script_Avestan", QChar::Script::Script_Avestan);
        define_qenum_value_under(rb_cQCharScript, "Script_EgyptianHieroglyphs", QChar::Script::Script_EgyptianHieroglyphs);
        define_qenum_value_under(rb_cQCharScript, "Script_Samaritan", QChar::Script::Script_Samaritan);
        define_qenum_value_under(rb_cQCharScript, "Script_Lisu", QChar::Script::Script_Lisu);
        define_qenum_value_under(rb_cQCharScript, "Script_Bamum", QChar::Script::Script_Bamum);
        define_qenum_value_under(rb_cQCharScript, "Script_Javanese", QChar::Script::Script_Javanese);
        define_qenum_value_under(rb_cQCharScript, "Script_MeeteiMayek", QChar::Script::Script_MeeteiMayek);
        define_qenum_value_under(rb_cQCharScript, "Script_ImperialAramaic", QChar::Script::Script_ImperialAramaic);
        define_qenum_value_under(rb_cQCharScript, "Script_OldSouthArabian", QChar::Script::Script_OldSouthArabian);
        define_qenum_value_under(rb_cQCharScript, "Script_InscriptionalParthian", QChar::Script::Script_InscriptionalParthian);
        define_qenum_value_under(rb_cQCharScript, "Script_InscriptionalPahlavi", QChar::Script::Script_InscriptionalPahlavi);
        define_qenum_value_under(rb_cQCharScript, "Script_OldTurkic", QChar::Script::Script_OldTurkic);
        define_qenum_value_under(rb_cQCharScript, "Script_Kaithi", QChar::Script::Script_Kaithi);
        define_qenum_value_under(rb_cQCharScript, "Script_Batak", QChar::Script::Script_Batak);
        define_qenum_value_under(rb_cQCharScript, "Script_Brahmi", QChar::Script::Script_Brahmi);
        define_qenum_value_under(rb_cQCharScript, "Script_Mandaic", QChar::Script::Script_Mandaic);
        define_qenum_value_under(rb_cQCharScript, "Script_Chakma", QChar::Script::Script_Chakma);
        define_qenum_value_under(rb_cQCharScript, "Script_MeroiticCursive", QChar::Script::Script_MeroiticCursive);
        define_qenum_value_under(rb_cQCharScript, "Script_MeroiticHieroglyphs", QChar::Script::Script_MeroiticHieroglyphs);
        define_qenum_value_under(rb_cQCharScript, "Script_Miao", QChar::Script::Script_Miao);
        define_qenum_value_under(rb_cQCharScript, "Script_Sharada", QChar::Script::Script_Sharada);
        define_qenum_value_under(rb_cQCharScript, "Script_SoraSompeng", QChar::Script::Script_SoraSompeng);
        define_qenum_value_under(rb_cQCharScript, "Script_Takri", QChar::Script::Script_Takri);
        define_qenum_value_under(rb_cQCharScript, "Script_CaucasianAlbanian", QChar::Script::Script_CaucasianAlbanian);
        define_qenum_value_under(rb_cQCharScript, "Script_BassaVah", QChar::Script::Script_BassaVah);
        define_qenum_value_under(rb_cQCharScript, "Script_Duployan", QChar::Script::Script_Duployan);
        define_qenum_value_under(rb_cQCharScript, "Script_Elbasan", QChar::Script::Script_Elbasan);
        define_qenum_value_under(rb_cQCharScript, "Script_Grantha", QChar::Script::Script_Grantha);
        define_qenum_value_under(rb_cQCharScript, "Script_PahawhHmong", QChar::Script::Script_PahawhHmong);
        define_qenum_value_under(rb_cQCharScript, "Script_Khojki", QChar::Script::Script_Khojki);
        define_qenum_value_under(rb_cQCharScript, "Script_LinearA", QChar::Script::Script_LinearA);
        define_qenum_value_under(rb_cQCharScript, "Script_Mahajani", QChar::Script::Script_Mahajani);
        define_qenum_value_under(rb_cQCharScript, "Script_Manichaean", QChar::Script::Script_Manichaean);
        define_qenum_value_under(rb_cQCharScript, "Script_MendeKikakui", QChar::Script::Script_MendeKikakui);
        define_qenum_value_under(rb_cQCharScript, "Script_Modi", QChar::Script::Script_Modi);
        define_qenum_value_under(rb_cQCharScript, "Script_Mro", QChar::Script::Script_Mro);
        define_qenum_value_under(rb_cQCharScript, "Script_OldNorthArabian", QChar::Script::Script_OldNorthArabian);
        define_qenum_value_under(rb_cQCharScript, "Script_Nabataean", QChar::Script::Script_Nabataean);
        define_qenum_value_under(rb_cQCharScript, "Script_Palmyrene", QChar::Script::Script_Palmyrene);
        define_qenum_value_under(rb_cQCharScript, "Script_PauCinHau", QChar::Script::Script_PauCinHau);
        define_qenum_value_under(rb_cQCharScript, "Script_OldPermic", QChar::Script::Script_OldPermic);
        define_qenum_value_under(rb_cQCharScript, "Script_PsalterPahlavi", QChar::Script::Script_PsalterPahlavi);
        define_qenum_value_under(rb_cQCharScript, "Script_Siddham", QChar::Script::Script_Siddham);
        define_qenum_value_under(rb_cQCharScript, "Script_Khudawadi", QChar::Script::Script_Khudawadi);
        define_qenum_value_under(rb_cQCharScript, "Script_Tirhuta", QChar::Script::Script_Tirhuta);
        define_qenum_value_under(rb_cQCharScript, "Script_WarangCiti", QChar::Script::Script_WarangCiti);
        define_qenum_value_under(rb_cQCharScript, "Script_Ahom", QChar::Script::Script_Ahom);
        define_qenum_value_under(rb_cQCharScript, "Script_AnatolianHieroglyphs", QChar::Script::Script_AnatolianHieroglyphs);
        define_qenum_value_under(rb_cQCharScript, "Script_Hatran", QChar::Script::Script_Hatran);
        define_qenum_value_under(rb_cQCharScript, "Script_Multani", QChar::Script::Script_Multani);
        define_qenum_value_under(rb_cQCharScript, "Script_OldHungarian", QChar::Script::Script_OldHungarian);
        define_qenum_value_under(rb_cQCharScript, "Script_SignWriting", QChar::Script::Script_SignWriting);
        define_qenum_value_under(rb_cQCharScript, "Script_Adlam", QChar::Script::Script_Adlam);
        define_qenum_value_under(rb_cQCharScript, "Script_Bhaiksuki", QChar::Script::Script_Bhaiksuki);
        define_qenum_value_under(rb_cQCharScript, "Script_Marchen", QChar::Script::Script_Marchen);
        define_qenum_value_under(rb_cQCharScript, "Script_Newa", QChar::Script::Script_Newa);
        define_qenum_value_under(rb_cQCharScript, "Script_Osage", QChar::Script::Script_Osage);
        define_qenum_value_under(rb_cQCharScript, "Script_Tangut", QChar::Script::Script_Tangut);
        define_qenum_value_under(rb_cQCharScript, "Script_MasaramGondi", QChar::Script::Script_MasaramGondi);
        define_qenum_value_under(rb_cQCharScript, "Script_Nushu", QChar::Script::Script_Nushu);
        define_qenum_value_under(rb_cQCharScript, "Script_Soyombo", QChar::Script::Script_Soyombo);
        define_qenum_value_under(rb_cQCharScript, "Script_ZanabazarSquare", QChar::Script::Script_ZanabazarSquare);
        define_qenum_value_under(rb_cQCharScript, "Script_Dogra", QChar::Script::Script_Dogra);
        define_qenum_value_under(rb_cQCharScript, "Script_GunjalaGondi", QChar::Script::Script_GunjalaGondi);
        define_qenum_value_under(rb_cQCharScript, "Script_HanifiRohingya", QChar::Script::Script_HanifiRohingya);
        define_qenum_value_under(rb_cQCharScript, "Script_Makasar", QChar::Script::Script_Makasar);
        define_qenum_value_under(rb_cQCharScript, "Script_Medefaidrin", QChar::Script::Script_Medefaidrin);
        define_qenum_value_under(rb_cQCharScript, "Script_OldSogdian", QChar::Script::Script_OldSogdian);
        define_qenum_value_under(rb_cQCharScript, "Script_Sogdian", QChar::Script::Script_Sogdian);
        define_qenum_value_under(rb_cQCharScript, "Script_Elymaic", QChar::Script::Script_Elymaic);
        define_qenum_value_under(rb_cQCharScript, "Script_Nandinagari", QChar::Script::Script_Nandinagari);
        define_qenum_value_under(rb_cQCharScript, "Script_NyiakengPuachueHmong", QChar::Script::Script_NyiakengPuachueHmong);
        define_qenum_value_under(rb_cQCharScript, "Script_Wancho", QChar::Script::Script_Wancho);
        define_qenum_value_under(rb_cQCharScript, "Script_Chorasmian", QChar::Script::Script_Chorasmian);
        define_qenum_value_under(rb_cQCharScript, "Script_DivesAkuru", QChar::Script::Script_DivesAkuru);
        define_qenum_value_under(rb_cQCharScript, "Script_KhitanSmallScript", QChar::Script::Script_KhitanSmallScript);
        define_qenum_value_under(rb_cQCharScript, "Script_Yezidi", QChar::Script::Script_Yezidi);
        define_qenum_value_under(rb_cQCharScript, "Script_CyproMinoan", QChar::Script::Script_CyproMinoan);
        define_qenum_value_under(rb_cQCharScript, "Script_OldUyghur", QChar::Script::Script_OldUyghur);
        define_qenum_value_under(rb_cQCharScript, "Script_Tangsa", QChar::Script::Script_Tangsa);
        define_qenum_value_under(rb_cQCharScript, "Script_Toto", QChar::Script::Script_Toto);
        define_qenum_value_under(rb_cQCharScript, "Script_Vithkuqi", QChar::Script::Script_Vithkuqi);
        define_qenum_value_under(rb_cQCharScript, "Script_Kawi", QChar::Script::Script_Kawi);
        define_qenum_value_under(rb_cQCharScript, "Script_NagMundari", QChar::Script::Script_NagMundari);
        define_qenum_value_under(rb_cQCharScript, "Script_Garay", QChar::Script::Script_Garay);
        define_qenum_value_under(rb_cQCharScript, "Script_GurungKhema", QChar::Script::Script_GurungKhema);
        define_qenum_value_under(rb_cQCharScript, "Script_KiratRai", QChar::Script::Script_KiratRai);
        define_qenum_value_under(rb_cQCharScript, "Script_OlOnal", QChar::Script::Script_OlOnal);
        define_qenum_value_under(rb_cQCharScript, "Script_Sunuwar", QChar::Script::Script_Sunuwar);
        define_qenum_value_under(rb_cQCharScript, "Script_Todhri", QChar::Script::Script_Todhri);
        define_qenum_value_under(rb_cQCharScript, "Script_TuluTigalari", QChar::Script::Script_TuluTigalari);
        define_qenum_value_under(rb_cQCharScript, "ScriptCount", QChar::Script::ScriptCount);

    Data_Type<QChar::SpecialCharacter> rb_cQCharSpecialCharacter =
        // RubyQt6::QtCore::QChar::SpecialCharacter
        define_qenum_under<QChar::SpecialCharacter>(rb_cQChar, "SpecialCharacter");
        define_qenum_value_under(rb_cQCharSpecialCharacter, "Null", QChar::SpecialCharacter::Null);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "Tabulation", QChar::SpecialCharacter::Tabulation);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "LineFeed", QChar::SpecialCharacter::LineFeed);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "FormFeed", QChar::SpecialCharacter::FormFeed);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "CarriageReturn", QChar::SpecialCharacter::CarriageReturn);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "Space", QChar::SpecialCharacter::Space);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "Nbsp", QChar::SpecialCharacter::Nbsp);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "SoftHyphen", QChar::SpecialCharacter::SoftHyphen);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "ReplacementCharacter", QChar::SpecialCharacter::ReplacementCharacter);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "ObjectReplacementCharacter", QChar::SpecialCharacter::ObjectReplacementCharacter);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "ByteOrderMark", QChar::SpecialCharacter::ByteOrderMark);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "ByteOrderSwapped", QChar::SpecialCharacter::ByteOrderSwapped);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "ParagraphSeparator", QChar::SpecialCharacter::ParagraphSeparator);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "LineSeparator", QChar::SpecialCharacter::LineSeparator);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "VisualTabCharacter", QChar::SpecialCharacter::VisualTabCharacter);
        define_qenum_value_under(rb_cQCharSpecialCharacter, "LastValidCodePoint", QChar::SpecialCharacter::LastValidCodePoint);

    Data_Type<QChar::UnicodeVersion> rb_cQCharUnicodeVersion =
        // RubyQt6::QtCore::QChar::UnicodeVersion
        define_qenum_under<QChar::UnicodeVersion>(rb_cQChar, "UnicodeVersion");
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_Unassigned", QChar::UnicodeVersion::Unicode_Unassigned);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_1_1", QChar::UnicodeVersion::Unicode_1_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_2_0", QChar::UnicodeVersion::Unicode_2_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_2_1_2", QChar::UnicodeVersion::Unicode_2_1_2);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_3_0", QChar::UnicodeVersion::Unicode_3_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_3_1", QChar::UnicodeVersion::Unicode_3_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_3_2", QChar::UnicodeVersion::Unicode_3_2);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_4_0", QChar::UnicodeVersion::Unicode_4_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_4_1", QChar::UnicodeVersion::Unicode_4_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_5_0", QChar::UnicodeVersion::Unicode_5_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_5_1", QChar::UnicodeVersion::Unicode_5_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_5_2", QChar::UnicodeVersion::Unicode_5_2);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_6_0", QChar::UnicodeVersion::Unicode_6_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_6_1", QChar::UnicodeVersion::Unicode_6_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_6_2", QChar::UnicodeVersion::Unicode_6_2);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_6_3", QChar::UnicodeVersion::Unicode_6_3);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_7_0", QChar::UnicodeVersion::Unicode_7_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_8_0", QChar::UnicodeVersion::Unicode_8_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_9_0", QChar::UnicodeVersion::Unicode_9_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_10_0", QChar::UnicodeVersion::Unicode_10_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_11_0", QChar::UnicodeVersion::Unicode_11_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_12_0", QChar::UnicodeVersion::Unicode_12_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_12_1", QChar::UnicodeVersion::Unicode_12_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_13_0", QChar::UnicodeVersion::Unicode_13_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_14_0", QChar::UnicodeVersion::Unicode_14_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_15_0", QChar::UnicodeVersion::Unicode_15_0);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_15_1", QChar::UnicodeVersion::Unicode_15_1);
        define_qenum_value_under(rb_cQCharUnicodeVersion, "Unicode_16_0", QChar::UnicodeVersion::Unicode_16_0);
}
