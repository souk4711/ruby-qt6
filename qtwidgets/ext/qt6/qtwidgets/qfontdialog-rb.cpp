#include "qfontdialog-rb.hpp"
#include <qfontdialog.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFontDialog;

QFont QFontDialog_get_font_2(Object boolean, QWidget *parent)
{
    bool ok {};
    QFont v = QFontDialog::getFont(&ok, parent);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

QFont QFontDialog_get_font_5(Object boolean, const QFont &initial, QWidget *parent, const QString &title, QFontDialog::FontDialogOptions options)
{
    bool ok {};
    QFont v = QFontDialog::getFont(&ok, initial, parent, title, options);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

void Init_qfontdialog(Module rb_mQt6QtWidgets)
{
    rb_cQFontDialog =
        // RubyQt6::QtWidgets::QFontDialog
        define_qlass_under<QFontDialog, QDialog>(rb_mQt6QtWidgets, "QFontDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("get_font", QFontDialog_get_font_2, Arg("ok"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_singleton_function("get_font", QFontDialog_get_font_5, Arg("ok"), Arg("initial"), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("title") = static_cast<const QString &>(QString()), Arg("options") = static_cast<QFontDialog::FontDialogOptions>(QFontDialog::FontDialogOptions()))
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
            .define_method("test_option", &QFontDialog::testOption, Arg("option"));
            // Signals
            // .define_method("current_font_changed", &QFontDialog::currentFontChanged, Arg("font"))
            // .define_method("font_selected", &QFontDialog::fontSelected, Arg("font"));

    Data_Type<QFontDialog::FontDialogOption> rb_cQFontDialogFontDialogOption =
        // RubyQt6::QtWidgets::QFontDialog::FontDialogOption
        define_qenum_under<QFontDialog::FontDialogOption>(rb_cQFontDialog, "FontDialogOption");
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "NoButtons", QFontDialog::FontDialogOption::NoButtons);
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "DontUseNativeDialog", QFontDialog::FontDialogOption::DontUseNativeDialog);
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "ScalableFonts", QFontDialog::FontDialogOption::ScalableFonts);
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "NonScalableFonts", QFontDialog::FontDialogOption::NonScalableFonts);
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "MonospacedFonts", QFontDialog::FontDialogOption::MonospacedFonts);
        define_qenum_value_under(rb_cQFontDialogFontDialogOption, "ProportionalFonts", QFontDialog::FontDialogOption::ProportionalFonts);

    Data_Type<QFlags<QFontDialog::FontDialogOption>> rb_cQFontDialogFontDialogOptions =
        // RubyQt6::QtWidgets::QFontDialog::FontDialogOptions
        define_qflags_under<QFontDialog::FontDialogOption>(rb_cQFontDialog, "FontDialogOptions");
}
