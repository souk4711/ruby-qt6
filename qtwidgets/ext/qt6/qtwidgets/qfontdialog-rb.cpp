#include "qfontdialog-rb.hpp"
#include <qfontdialog.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQFontDialog;

void Init_qfontdialog(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFontDialog =
        // RubyQt6::QtWidgets::QFontDialog
        define_class_under<QFontDialog, QDialog>(rb_mQt6QtWidgets, "QFontDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFontDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFontDialog, const QFont &, QWidget *>(), Arg("initial"), Arg("parent"))
            // Public Functions
            .define_method("current_font", &QFontDialog::currentFont)
            .define_method<void (QFontDialog::*)(QObject *, const char *)>("open", &QFontDialog::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QFontDialog::options)
            .define_method("selected_font", &QFontDialog::selectedFont)
            .define_method("set_current_font", &QFontDialog::setCurrentFont, Arg("font"))
            .define_method("set_option", &QFontDialog::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QFontDialog::setOptions, Arg("options"))
            .define_method("set_visible", &QFontDialog::setVisible, Arg("visible"))
            .define_method("test_option", &QFontDialog::testOption, Arg("option"))
            // Signals
            .define_method("current_font_changed", &QFontDialog::currentFontChanged, Arg("font"))
            .define_method("font_selected", &QFontDialog::fontSelected, Arg("font"))
            // Static Public Members
            .define_singleton_function<QFont (*)(bool *, QWidget *)>("get_font", &QFontDialog::getFont, Arg("ok"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_singleton_function<QFont (*)(bool *, const QFont &, QWidget *, const QString &, QFontDialog::FontDialogOptions)>("get_font", &QFontDialog::getFont, Arg("ok"), Arg("initial"), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("title") = static_cast<const QString &>(QString()), Arg("options") = static_cast<QFontDialog::FontDialogOptions>(QFontDialog::FontDialogOptions()));

    Enum<QFontDialog::FontDialogOption> rb_cQFontDialogFontDialogOption =
        // RubyQt6::QtWidgets::QFontDialog::FontDialogOption
        define_qenum_under<QFontDialog::FontDialogOption>("FontDialogOption", rb_cQFontDialog)
            .define_value("NoButtons", QFontDialog::FontDialogOption::NoButtons)
            .define_value("DontUseNativeDialog", QFontDialog::FontDialogOption::DontUseNativeDialog)
            .define_value("ScalableFonts", QFontDialog::FontDialogOption::ScalableFonts)
            .define_value("NonScalableFonts", QFontDialog::FontDialogOption::NonScalableFonts)
            .define_value("MonospacedFonts", QFontDialog::FontDialogOption::MonospacedFonts)
            .define_value("ProportionalFonts", QFontDialog::FontDialogOption::ProportionalFonts);

    Data_Type<QFlags<QFontDialog::FontDialogOption>> rb_cQFontDialogFontDialogOptions =
        // RubyQt6::QtWidgets::QFontDialog::FontDialogOptions
        define_qflags_under<QFontDialog::FontDialogOption>(rb_cQFontDialog, "FontDialogOptions");
}
