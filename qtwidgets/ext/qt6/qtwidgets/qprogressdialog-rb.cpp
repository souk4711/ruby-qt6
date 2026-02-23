#include "qprogressdialog-rb.hpp"
#include <qprogressdialog.h>

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQProgressDialog;

void Init_qprogressdialog(Module rb_mQt6QtWidgets)
{
    rb_cQProgressDialog =
        // RubyQt6::QtWidgets::QProgressDialog
        define_qlass_under<QProgressDialog, QDialog>(rb_mQt6QtWidgets, "QProgressDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QProgressDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QProgressDialog, const QString &, const QString &, int, int, QWidget *>(), Arg("label_text"), Arg("cancel_button_text"), Arg("minimum"), Arg("maximum"), Arg("parent"))
            // Public Functions
            .define_method("auto_close", &QProgressDialog::autoClose)
            .define_method("auto_reset", &QProgressDialog::autoReset)
            .define_method("label_text", &QProgressDialog::labelText)
            .define_method("maximum", &QProgressDialog::maximum)
            .define_method("minimum", &QProgressDialog::minimum)
            .define_method("minimum_duration", &QProgressDialog::minimumDuration)
            .define_method<void (QProgressDialog::*)(QObject *, const char *)>("open", &QProgressDialog::open, Arg("receiver"), Arg("member"))
            .define_method("set_auto_close", &QProgressDialog::setAutoClose, Arg("close"))
            .define_method("set_auto_reset", &QProgressDialog::setAutoReset, Arg("reset"))
            .define_method("set_bar", &QProgressDialog::setBar, Arg("bar"))
            .define_method("set_cancel_button", &QProgressDialog::setCancelButton, Arg("button"))
            .define_method("set_label", &QProgressDialog::setLabel, Arg("label"))
            .define_method("value", &QProgressDialog::value)
            .define_method("was_canceled", &QProgressDialog::wasCanceled)
            // Public Slots
            .define_method("cancel", &QProgressDialog::cancel)
            .define_method("reset", &QProgressDialog::reset)
            .define_method("set_cancel_button_text", &QProgressDialog::setCancelButtonText, Arg("text"))
            .define_method("set_label_text", &QProgressDialog::setLabelText, Arg("text"))
            .define_method("set_maximum", &QProgressDialog::setMaximum, Arg("maximum"))
            .define_method("set_minimum", &QProgressDialog::setMinimum, Arg("minimum"))
            .define_method("set_minimum_duration", &QProgressDialog::setMinimumDuration, Arg("ms"))
            .define_method("set_range", &QProgressDialog::setRange, Arg("minimum"), Arg("maximum"))
            .define_method("set_value", &QProgressDialog::setValue, Arg("progress"));
            // Signals
            // .define_method("canceled", &QProgressDialog::canceled);
}
