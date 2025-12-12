#include "qfontdatabase-rb.hpp"
#include <qfontdatabase.h>
#include <rice/qt6/qenum.hpp>

#include <QFontInfo>
#include <QList>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFontDatabase;

void Init_qfontdatabase(Module rb_mQt6QtGui)
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

    Data_Type<QFontDatabase::WritingSystem> rb_cQFontDatabaseWritingSystem =
        // RubyQt6::QtGui::QFontDatabase::WritingSystem
        define_qenum_under<QFontDatabase::WritingSystem>(rb_cQFontDatabase, "WritingSystem");
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Any", QFontDatabase::WritingSystem::Any);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Latin", QFontDatabase::WritingSystem::Latin);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Greek", QFontDatabase::WritingSystem::Greek);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Cyrillic", QFontDatabase::WritingSystem::Cyrillic);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Armenian", QFontDatabase::WritingSystem::Armenian);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Hebrew", QFontDatabase::WritingSystem::Hebrew);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Arabic", QFontDatabase::WritingSystem::Arabic);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Syriac", QFontDatabase::WritingSystem::Syriac);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Thaana", QFontDatabase::WritingSystem::Thaana);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Devanagari", QFontDatabase::WritingSystem::Devanagari);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Bengali", QFontDatabase::WritingSystem::Bengali);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Gurmukhi", QFontDatabase::WritingSystem::Gurmukhi);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Gujarati", QFontDatabase::WritingSystem::Gujarati);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Oriya", QFontDatabase::WritingSystem::Oriya);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Tamil", QFontDatabase::WritingSystem::Tamil);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Telugu", QFontDatabase::WritingSystem::Telugu);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Kannada", QFontDatabase::WritingSystem::Kannada);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Malayalam", QFontDatabase::WritingSystem::Malayalam);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Sinhala", QFontDatabase::WritingSystem::Sinhala);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Thai", QFontDatabase::WritingSystem::Thai);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Lao", QFontDatabase::WritingSystem::Lao);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Tibetan", QFontDatabase::WritingSystem::Tibetan);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Myanmar", QFontDatabase::WritingSystem::Myanmar);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Georgian", QFontDatabase::WritingSystem::Georgian);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Khmer", QFontDatabase::WritingSystem::Khmer);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "SimplifiedChinese", QFontDatabase::WritingSystem::SimplifiedChinese);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "TraditionalChinese", QFontDatabase::WritingSystem::TraditionalChinese);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Japanese", QFontDatabase::WritingSystem::Japanese);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Korean", QFontDatabase::WritingSystem::Korean);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Vietnamese", QFontDatabase::WritingSystem::Vietnamese);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Symbol", QFontDatabase::WritingSystem::Symbol);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Other", QFontDatabase::WritingSystem::Other);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Ogham", QFontDatabase::WritingSystem::Ogham);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Runic", QFontDatabase::WritingSystem::Runic);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "Nko", QFontDatabase::WritingSystem::Nko);
        define_qenum_value_under(rb_cQFontDatabaseWritingSystem, "WritingSystemsCount", QFontDatabase::WritingSystem::WritingSystemsCount);

    Data_Type<QFontDatabase::SystemFont> rb_cQFontDatabaseSystemFont =
        // RubyQt6::QtGui::QFontDatabase::SystemFont
        define_qenum_under<QFontDatabase::SystemFont>(rb_cQFontDatabase, "SystemFont");
        define_qenum_value_under(rb_cQFontDatabaseSystemFont, "GeneralFont", QFontDatabase::SystemFont::GeneralFont);
        define_qenum_value_under(rb_cQFontDatabaseSystemFont, "FixedFont", QFontDatabase::SystemFont::FixedFont);
        define_qenum_value_under(rb_cQFontDatabaseSystemFont, "TitleFont", QFontDatabase::SystemFont::TitleFont);
        define_qenum_value_under(rb_cQFontDatabaseSystemFont, "SmallestReadableFont", QFontDatabase::SystemFont::SmallestReadableFont);
}
