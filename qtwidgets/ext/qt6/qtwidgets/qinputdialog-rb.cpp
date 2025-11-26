#include "qinputdialog-rb.hpp"
#include <qinputdialog.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQInputDialog;

double QInputDialog_get_double(QWidget *parent, const QString &title, const QString &label, double value, double min, double max, int decimals, Object boolean, Qt::WindowFlags flags, double step)
{
    bool ok {};
    double v = QInputDialog::getDouble(parent, title, label, value, min, max, decimals, &ok, flags, step);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

int QInputDialog_get_int(QWidget *parent, const QString &title, const QString &label, int value, int min, int max, int step, Object boolean, Qt::WindowFlags flags)
{
    bool ok {};
    int v = QInputDialog::getInt(parent, title, label, value, min, max, step, &ok, flags);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

QString QInputDialog_get_item(QWidget *parent, const QString &title, const QString &label, const QStringList &items, int current, bool editable, Object boolean, Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
    bool ok {};
    QString v = QInputDialog::getItem(parent, title, label, items, current, editable, &ok, flags, inputMethodHints);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

QString QInputDialog_get_multi_line_text(QWidget *parent, const QString &title, const QString &label, const QString &text, Object boolean, Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
    bool ok {};
    QString v = QInputDialog::getMultiLineText(parent, title, label, text, &ok, flags, inputMethodHints);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

QString QInputDialog_get_text(QWidget *parent, const QString &title, const QString &label, QLineEdit::EchoMode mode, const QString &text, Object boolean, Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
    bool ok {};
    QString v = QInputDialog::getText(parent, title, label, mode, text, &ok, flags, inputMethodHints);
    if (!boolean.is_nil()) boolean.call("value=", ok);
    return v;
}

void Init_qinputdialog(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQInputDialog =
        // RubyQt6::QtWidgets::QInputDialog
        define_class_under<QInputDialog, QDialog>(rb_mQt6QtWidgets, "QInputDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("get_double", QInputDialog_get_double, Arg("parent"), Arg("title"), Arg("label"), Arg("value") = static_cast<double>(0), Arg("min_value") = static_cast<double>(-2147483647), Arg("max_value") = static_cast<double>(2147483647), Arg("decimals") = static_cast<int>(1), Arg("ok") = static_cast<Object>(Qnil), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()), Arg("step") = static_cast<double>(1))
            .define_singleton_function("get_int", QInputDialog_get_int, Arg("parent"), Arg("title"), Arg("label"), Arg("value") = static_cast<int>(0), Arg("min_value") = static_cast<int>(-2147483647), Arg("max_value") = static_cast<int>(2147483647), Arg("step") = static_cast<int>(1), Arg("ok") = static_cast<Object>(Qnil), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_singleton_function("get_item", QInputDialog_get_item, Arg("parent"), Arg("title"), Arg("label"), Arg("items"), Arg("current") = static_cast<int>(0), Arg("editable") = static_cast<bool>(true), Arg("ok") = static_cast<Object>(Qnil), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()), Arg("input_method_hints") = static_cast<Qt::InputMethodHints>(Qt::ImhNone))
            .define_singleton_function("get_multi_line_text", QInputDialog_get_multi_line_text, Arg("parent"), Arg("title"), Arg("label"), Arg("text") = static_cast<const QString &>(QString()), Arg("ok") = static_cast<Object>(Qnil), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()), Arg("input_method_hints") = static_cast<Qt::InputMethodHints>(Qt::ImhNone))
            .define_singleton_function("get_text", QInputDialog_get_text, Arg("parent"), Arg("title"), Arg("label"), Arg("echo") = static_cast<QLineEdit::EchoMode>(QLineEdit::Normal), Arg("text") = static_cast<const QString &>(QString()), Arg("ok") = static_cast<Object>(Qnil), Arg("flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()), Arg("input_method_hints") = static_cast<Qt::InputMethodHints>(Qt::ImhNone))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QInputDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QInputDialog, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("cancel_button_text", &QInputDialog::cancelButtonText)
            .define_method("combo_box_items", &QInputDialog::comboBoxItems)
            .define_method("done", &QInputDialog::done, Arg("result"))
            .define_method("double_decimals", &QInputDialog::doubleDecimals)
            .define_method("double_maximum", &QInputDialog::doubleMaximum)
            .define_method("double_minimum", &QInputDialog::doubleMinimum)
            .define_method("double_step", &QInputDialog::doubleStep)
            .define_method("double_value", &QInputDialog::doubleValue)
            .define_method("input_mode", &QInputDialog::inputMode)
            .define_method("int_maximum", &QInputDialog::intMaximum)
            .define_method("int_minimum", &QInputDialog::intMinimum)
            .define_method("int_step", &QInputDialog::intStep)
            .define_method("int_value", &QInputDialog::intValue)
            .define_method("combo_box_editable?", &QInputDialog::isComboBoxEditable)
            .define_method("label_text", &QInputDialog::labelText)
            .define_method("ok_button_text", &QInputDialog::okButtonText)
            .define_method<void (QInputDialog::*)(QObject *, const char *)>("open", &QInputDialog::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QInputDialog::options)
            .define_method("set_cancel_button_text", &QInputDialog::setCancelButtonText, Arg("text"))
            .define_method("set_combo_box_editable", &QInputDialog::setComboBoxEditable, Arg("editable"))
            .define_method("set_combo_box_items", &QInputDialog::setComboBoxItems, Arg("items"))
            .define_method("set_double_decimals", &QInputDialog::setDoubleDecimals, Arg("decimals"))
            .define_method("set_double_maximum", &QInputDialog::setDoubleMaximum, Arg("max"))
            .define_method("set_double_minimum", &QInputDialog::setDoubleMinimum, Arg("min"))
            .define_method("set_double_range", &QInputDialog::setDoubleRange, Arg("min"), Arg("max"))
            .define_method("set_double_step", &QInputDialog::setDoubleStep, Arg("step"))
            .define_method("set_double_value", &QInputDialog::setDoubleValue, Arg("value"))
            .define_method("set_input_mode", &QInputDialog::setInputMode, Arg("mode"))
            .define_method("set_int_maximum", &QInputDialog::setIntMaximum, Arg("max"))
            .define_method("set_int_minimum", &QInputDialog::setIntMinimum, Arg("min"))
            .define_method("set_int_range", &QInputDialog::setIntRange, Arg("min"), Arg("max"))
            .define_method("set_int_step", &QInputDialog::setIntStep, Arg("step"))
            .define_method("set_int_value", &QInputDialog::setIntValue, Arg("value"))
            .define_method("set_label_text", &QInputDialog::setLabelText, Arg("text"))
            .define_method("set_ok_button_text", &QInputDialog::setOkButtonText, Arg("text"))
            .define_method("set_option", &QInputDialog::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QInputDialog::setOptions, Arg("options"))
            .define_method("set_text_echo_mode", &QInputDialog::setTextEchoMode, Arg("mode"))
            .define_method("set_text_value", &QInputDialog::setTextValue, Arg("text"))
            .define_method("set_visible", &QInputDialog::setVisible, Arg("visible"))
            .define_method("test_option", &QInputDialog::testOption, Arg("option"))
            .define_method("text_echo_mode", &QInputDialog::textEchoMode)
            .define_method("text_value", &QInputDialog::textValue);
            // Signals
            // .define_method("double_value_changed", &QInputDialog::doubleValueChanged, Arg("value"))
            // .define_method("double_value_selected", &QInputDialog::doubleValueSelected, Arg("value"))
            // .define_method("int_value_changed", &QInputDialog::intValueChanged, Arg("value"))
            // .define_method("int_value_selected", &QInputDialog::intValueSelected, Arg("value"))
            // .define_method("text_value_changed", &QInputDialog::textValueChanged, Arg("text"))
            // .define_method("text_value_selected", &QInputDialog::textValueSelected, Arg("text"));

    Data_Type<QInputDialog::InputDialogOption> rb_cQInputDialogInputDialogOption =
        // RubyQt6::QtWidgets::QInputDialog::InputDialogOption
        define_qenum_under<QInputDialog::InputDialogOption>(rb_cQInputDialog, "InputDialogOption");
        define_qenum_value_under(rb_cQInputDialogInputDialogOption, "NoButtons", QInputDialog::InputDialogOption::NoButtons);
        define_qenum_value_under(rb_cQInputDialogInputDialogOption, "UseListViewForComboBoxItems", QInputDialog::InputDialogOption::UseListViewForComboBoxItems);
        define_qenum_value_under(rb_cQInputDialogInputDialogOption, "UsePlainTextEditForTextInput", QInputDialog::InputDialogOption::UsePlainTextEditForTextInput);

    Data_Type<QInputDialog::InputMode> rb_cQInputDialogInputMode =
        // RubyQt6::QtWidgets::QInputDialog::InputMode
        define_qenum_under<QInputDialog::InputMode>(rb_cQInputDialog, "InputMode");
        define_qenum_value_under(rb_cQInputDialogInputMode, "TextInput", QInputDialog::InputMode::TextInput);
        define_qenum_value_under(rb_cQInputDialogInputMode, "IntInput", QInputDialog::InputMode::IntInput);
        define_qenum_value_under(rb_cQInputDialogInputMode, "DoubleInput", QInputDialog::InputMode::DoubleInput);

    Data_Type<QFlags<QInputDialog::InputDialogOption>> rb_cQInputDialogInputDialogOptions =
        // RubyQt6::QtWidgets::QInputDialog::InputDialogOptions
        define_qflags_under<QInputDialog::InputDialogOption>(rb_cQInputDialog, "InputDialogOptions");
}
