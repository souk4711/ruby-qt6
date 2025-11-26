#include "qfontcombobox-rb.hpp"
#include <qfontcombobox.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQFontComboBox;

void Init_qfontcombobox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFontComboBox =
        // RubyQt6::QtWidgets::QFontComboBox
        define_class_under<QFontComboBox, QComboBox>(rb_mQt6QtWidgets, "QFontComboBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFontComboBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFontComboBox, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("current_font", &QFontComboBox::currentFont)
            .define_method("display_font", &QFontComboBox::displayFont, Arg("font_family"))
            .define_method("font_filters", &QFontComboBox::fontFilters)
            .define_method("sample_text_for_font", &QFontComboBox::sampleTextForFont, Arg("font_family"))
            .define_method("sample_text_for_system", &QFontComboBox::sampleTextForSystem, Arg("writing_system"))
            .define_method("set_display_font", &QFontComboBox::setDisplayFont, Arg("font_family"), Arg("font"))
            .define_method("set_font_filters", &QFontComboBox::setFontFilters, Arg("filters"))
            .define_method("set_sample_text_for_font", &QFontComboBox::setSampleTextForFont, Arg("font_family"), Arg("sample_text"))
            .define_method("set_sample_text_for_system", &QFontComboBox::setSampleTextForSystem, Arg("writing_system"), Arg("sample_text"))
            .define_method("set_writing_system", &QFontComboBox::setWritingSystem, Arg("system"))
            .define_method("writing_system", &QFontComboBox::writingSystem)
            // Public Slots
            .define_method("set_current_font", &QFontComboBox::setCurrentFont, Arg("f"));
            // Signals
            // .define_method("current_font_changed", &QFontComboBox::currentFontChanged, Arg("f"));

    Data_Type<QFontComboBox::FontFilter> rb_cQFontComboBoxFontFilter =
        // RubyQt6::QtWidgets::QFontComboBox::FontFilter
        define_qenum_under<QFontComboBox::FontFilter>(rb_cQFontComboBox, "FontFilter");
        define_qenum_value_under(rb_cQFontComboBoxFontFilter, "AllFonts", QFontComboBox::FontFilter::AllFonts);
        define_qenum_value_under(rb_cQFontComboBoxFontFilter, "ScalableFonts", QFontComboBox::FontFilter::ScalableFonts);
        define_qenum_value_under(rb_cQFontComboBoxFontFilter, "NonScalableFonts", QFontComboBox::FontFilter::NonScalableFonts);
        define_qenum_value_under(rb_cQFontComboBoxFontFilter, "MonospacedFonts", QFontComboBox::FontFilter::MonospacedFonts);
        define_qenum_value_under(rb_cQFontComboBoxFontFilter, "ProportionalFonts", QFontComboBox::FontFilter::ProportionalFonts);

    Data_Type<QFlags<QFontComboBox::FontFilter>> rb_cQFontComboBoxFontFilters =
        // RubyQt6::QtWidgets::QFontComboBox::FontFilters
        define_qflags_under<QFontComboBox::FontFilter>(rb_cQFontComboBox, "FontFilters");
}
