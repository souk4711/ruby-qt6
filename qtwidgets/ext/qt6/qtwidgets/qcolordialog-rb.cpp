#include "qcolordialog-rb.hpp"
#include <qcolordialog.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQColorDialog;

void Init_qcolordialog(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQColorDialog =
        // RubyQt6::QtWidgets::QColorDialog
        define_class_under<QColorDialog, QDialog>(rb_mQt6QtWidgets, "QColorDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QColorDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QColorDialog, const QColor &, QWidget *>(), Arg("initial"), Arg("parent"))
            // Public Functions
            .define_method("current_color", &QColorDialog::currentColor)
            .define_method<void (QColorDialog::*)(QObject *, const char *)>("open", &QColorDialog::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QColorDialog::options)
            .define_method("selected_color", &QColorDialog::selectedColor)
            .define_method("set_current_color", &QColorDialog::setCurrentColor, Arg("color"))
            .define_method("set_option", &QColorDialog::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QColorDialog::setOptions, Arg("options"))
            .define_method("set_visible", &QColorDialog::setVisible, Arg("visible"))
            .define_method("test_option", &QColorDialog::testOption, Arg("option"))
            // Signals
            .define_method("color_selected", &QColorDialog::colorSelected, Arg("color"))
            .define_method("current_color_changed", &QColorDialog::currentColorChanged, Arg("color"))
            // Static Public Members
            .define_singleton_function("custom_color", &QColorDialog::customColor, Arg("index"))
            .define_singleton_function("custom_count", &QColorDialog::customCount)
            .define_singleton_function("get_color", &QColorDialog::getColor, Arg("initial") = static_cast<const QColor &>(Qt::white), Arg("parent") = static_cast<QWidget *>(nullptr), Arg("title") = static_cast<const QString &>(QString()), Arg("options") = static_cast<QColorDialog::ColorDialogOptions>(QColorDialog::ColorDialogOptions()))
            .define_singleton_function("set_custom_color", &QColorDialog::setCustomColor, Arg("index"), Arg("color"))
            .define_singleton_function("set_standard_color", &QColorDialog::setStandardColor, Arg("index"), Arg("color"))
            .define_singleton_function("standard_color", &QColorDialog::standardColor, Arg("index"));

    Data_Type<QColorDialog::ColorDialogOption> rb_cQColorDialogColorDialogOption =
        // RubyQt6::QtWidgets::QColorDialog::ColorDialogOption
        define_qenum_under<QColorDialog::ColorDialogOption>(rb_cQColorDialog, "ColorDialogOption");
        define_qenum_value_under(rb_cQColorDialogColorDialogOption, "ShowAlphaChannel", QColorDialog::ColorDialogOption::ShowAlphaChannel);
        define_qenum_value_under(rb_cQColorDialogColorDialogOption, "NoButtons", QColorDialog::ColorDialogOption::NoButtons);
        define_qenum_value_under(rb_cQColorDialogColorDialogOption, "DontUseNativeDialog", QColorDialog::ColorDialogOption::DontUseNativeDialog);
        define_qenum_value_under(rb_cQColorDialogColorDialogOption, "NoEyeDropperButton", QColorDialog::ColorDialogOption::NoEyeDropperButton);

    Data_Type<QFlags<QColorDialog::ColorDialogOption>> rb_cQColorDialogColorDialogOptions =
        // RubyQt6::QtWidgets::QColorDialog::ColorDialogOptions
        define_qflags_under<QColorDialog::ColorDialogOption>(rb_cQColorDialog, "ColorDialogOptions");
}
