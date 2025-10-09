#include "qfontdatabase-rb.hpp"
#include <qfontdatabase.h>

#include <QFontInfo>
#include <QList>

using namespace Rice;

Rice::Class rb_cQFontDatabase;

void Init_qfontdatabase(Rice::Module rb_mQt6QtGui)
{
    rb_cQFontDatabase =
        // RubyQt6::QtGui::QFontDatabase
        define_class_under<QFontDatabase>(rb_mQt6QtGui, "QFontDatabase")
            // Static Public Members
            .define_singleton_function("add_application_emoji_font_family", &QFontDatabase::addApplicationEmojiFontFamily, Arg("family_name"))
            .define_singleton_function("add_application_fallback_font_family", &QFontDatabase::addApplicationFallbackFontFamily, Arg("script"), Arg("family_name"))
            .define_singleton_function("add_application_font", &QFontDatabase::addApplicationFont, Arg("file_name"))
            .define_singleton_function("add_application_font_from_data", &QFontDatabase::addApplicationFontFromData, Arg("font_data"))
            .define_singleton_function("application_emoji_font_families", &QFontDatabase::applicationEmojiFontFamilies)
            .define_singleton_function("application_fallback_font_families", &QFontDatabase::applicationFallbackFontFamilies, Arg("script"))
            .define_singleton_function("application_font_families", &QFontDatabase::applicationFontFamilies, Arg("id"))
            .define_singleton_function("bold", &QFontDatabase::bold, Arg("family"), Arg("style"))
            .define_singleton_function("families", &QFontDatabase::families, Arg("writing_system") = static_cast<QFontDatabase::WritingSystem>(QFontDatabase::WritingSystem::Any))
            .define_singleton_function("font", &QFontDatabase::font, Arg("family"), Arg("style"), Arg("point_size"))
            .define_singleton_function("has_family", &QFontDatabase::hasFamily, Arg("family"))
            .define_singleton_function("bitmap_scalable?", &QFontDatabase::isBitmapScalable, Arg("family"), Arg("style") = static_cast<const QString &>(QString()))
            .define_singleton_function("fixed_pitch?", &QFontDatabase::isFixedPitch, Arg("family"), Arg("style") = static_cast<const QString &>(QString()))
            .define_singleton_function("private_family?", &QFontDatabase::isPrivateFamily, Arg("family"))
            .define_singleton_function("scalable?", &QFontDatabase::isScalable, Arg("family"), Arg("style") = static_cast<const QString &>(QString()))
            .define_singleton_function("smoothly_scalable?", &QFontDatabase::isSmoothlyScalable, Arg("family"), Arg("style") = static_cast<const QString &>(QString()))
            .define_singleton_function("italic", &QFontDatabase::italic, Arg("family"), Arg("style"))
            .define_singleton_function("point_sizes", &QFontDatabase::pointSizes, Arg("family"), Arg("style") = static_cast<const QString &>(QString()))
            .define_singleton_function("remove_all_application_fonts", &QFontDatabase::removeAllApplicationFonts)
            .define_singleton_function("remove_application_emoji_font_family", &QFontDatabase::removeApplicationEmojiFontFamily, Arg("family_name"))
            .define_singleton_function("remove_application_fallback_font_family", &QFontDatabase::removeApplicationFallbackFontFamily, Arg("script"), Arg("family_name"))
            .define_singleton_function("remove_application_font", &QFontDatabase::removeApplicationFont, Arg("id"))
            .define_singleton_function("set_application_emoji_font_families", &QFontDatabase::setApplicationEmojiFontFamilies, Arg("family_names"))
            .define_singleton_function("set_application_fallback_font_families", &QFontDatabase::setApplicationFallbackFontFamilies, Arg("script"), Arg("family_names"))
            .define_singleton_function("smooth_sizes", &QFontDatabase::smoothSizes, Arg("family"), Arg("style"))
            .define_singleton_function("standard_sizes", &QFontDatabase::standardSizes)
            .define_singleton_function<QString (*)(const QFont &)>("style_string", &QFontDatabase::styleString, Arg("font"))
            .define_singleton_function<QString (*)(const QFontInfo &)>("style_string", &QFontDatabase::styleString, Arg("font_info"))
            .define_singleton_function("styles", &QFontDatabase::styles, Arg("family"))
            .define_singleton_function("system_font", &QFontDatabase::systemFont, Arg("type"))
            .define_singleton_function("weight", &QFontDatabase::weight, Arg("family"), Arg("style"))
            .define_singleton_function("writing_system_name", &QFontDatabase::writingSystemName, Arg("writing_system"))
            .define_singleton_function("writing_system_sample", &QFontDatabase::writingSystemSample, Arg("writing_system"))
            .define_singleton_function<QList<QFontDatabase::WritingSystem> (*)()>("writing_systems", &QFontDatabase::writingSystems)
            .define_singleton_function<QList<QFontDatabase::WritingSystem> (*)(const QString &)>("writing_systems", &QFontDatabase::writingSystems, Arg("family"));

    Enum<QFontDatabase::WritingSystem> rb_cQFontDatabaseWritingSystem =
        // RubyQt6::QtGui::QFontDatabase::WritingSystem
        define_enum_under<QFontDatabase::WritingSystem>("WritingSystem", rb_cQFontDatabase)
            .define_value("Any", QFontDatabase::WritingSystem::Any)
            .define_value("Latin", QFontDatabase::WritingSystem::Latin)
            .define_value("Greek", QFontDatabase::WritingSystem::Greek)
            .define_value("Cyrillic", QFontDatabase::WritingSystem::Cyrillic)
            .define_value("Armenian", QFontDatabase::WritingSystem::Armenian)
            .define_value("Hebrew", QFontDatabase::WritingSystem::Hebrew)
            .define_value("Arabic", QFontDatabase::WritingSystem::Arabic)
            .define_value("Syriac", QFontDatabase::WritingSystem::Syriac)
            .define_value("Thaana", QFontDatabase::WritingSystem::Thaana)
            .define_value("Devanagari", QFontDatabase::WritingSystem::Devanagari)
            .define_value("Bengali", QFontDatabase::WritingSystem::Bengali)
            .define_value("Gurmukhi", QFontDatabase::WritingSystem::Gurmukhi)
            .define_value("Gujarati", QFontDatabase::WritingSystem::Gujarati)
            .define_value("Oriya", QFontDatabase::WritingSystem::Oriya)
            .define_value("Tamil", QFontDatabase::WritingSystem::Tamil)
            .define_value("Telugu", QFontDatabase::WritingSystem::Telugu)
            .define_value("Kannada", QFontDatabase::WritingSystem::Kannada)
            .define_value("Malayalam", QFontDatabase::WritingSystem::Malayalam)
            .define_value("Sinhala", QFontDatabase::WritingSystem::Sinhala)
            .define_value("Thai", QFontDatabase::WritingSystem::Thai)
            .define_value("Lao", QFontDatabase::WritingSystem::Lao)
            .define_value("Tibetan", QFontDatabase::WritingSystem::Tibetan)
            .define_value("Myanmar", QFontDatabase::WritingSystem::Myanmar)
            .define_value("Georgian", QFontDatabase::WritingSystem::Georgian)
            .define_value("Khmer", QFontDatabase::WritingSystem::Khmer)
            .define_value("SimplifiedChinese", QFontDatabase::WritingSystem::SimplifiedChinese)
            .define_value("TraditionalChinese", QFontDatabase::WritingSystem::TraditionalChinese)
            .define_value("Japanese", QFontDatabase::WritingSystem::Japanese)
            .define_value("Korean", QFontDatabase::WritingSystem::Korean)
            .define_value("Vietnamese", QFontDatabase::WritingSystem::Vietnamese)
            .define_value("Symbol", QFontDatabase::WritingSystem::Symbol)
            .define_value("Other", QFontDatabase::WritingSystem::Other)
            .define_value("Ogham", QFontDatabase::WritingSystem::Ogham)
            .define_value("Runic", QFontDatabase::WritingSystem::Runic)
            .define_value("Nko", QFontDatabase::WritingSystem::Nko)
            .define_value("WritingSystemsCount", QFontDatabase::WritingSystem::WritingSystemsCount);

    Enum<QFontDatabase::SystemFont> rb_cQFontDatabaseSystemFont =
        // RubyQt6::QtGui::QFontDatabase::SystemFont
        define_enum_under<QFontDatabase::SystemFont>("SystemFont", rb_cQFontDatabase)
            .define_value("GeneralFont", QFontDatabase::SystemFont::GeneralFont)
            .define_value("FixedFont", QFontDatabase::SystemFont::FixedFont)
            .define_value("TitleFont", QFontDatabase::SystemFont::TitleFont)
            .define_value("SmallestReadableFont", QFontDatabase::SystemFont::SmallestReadableFont);
}
