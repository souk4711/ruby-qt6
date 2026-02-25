#include "qdialog-rb.hpp"
#include <qdialog.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDialog;

void Init_qdialog(Module rb_mQt6QtWidgets)
{
    rb_cQDialog =
        // RubyQt6::QtWidgets::QDialog
        define_qlass_under<QDialog, QWidget>(rb_mQt6QtWidgets, "QDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QDialog * { return qobject_cast<QDialog *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDialog, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("size_grip_enabled?", &QDialog::isSizeGripEnabled)
            .define_method("result", &QDialog::result)
            .define_method("set_modal", &QDialog::setModal, Arg("modal"))
            .define_method("set_result", &QDialog::setResult, Arg("r"))
            .define_method("set_size_grip_enabled", &QDialog::setSizeGripEnabled, Arg("enabled"))
            .define_method("set_visible", &QDialog::setVisible, Arg("visible"))
            // Public Slots
            .define_method("accept", &QDialog::accept)
            .define_method("done", &QDialog::done, Arg("r"))
            .define_method("exec", &QDialog::exec)
            .define_method("open", &QDialog::open)
            .define_method("reject", &QDialog::reject);
            // Signals
            // .define_method("accepted", &QDialog::accepted)
            // .define_method("finished", &QDialog::finished, Arg("result"))
            // .define_method("rejected", &QDialog::rejected);

    Data_Type<QDialog::DialogCode> rb_cQDialogDialogCode =
        // RubyQt6::QtWidgets::QDialog::DialogCode
        define_qenum_under<QDialog::DialogCode>(rb_cQDialog, "DialogCode");
        define_qenum_value_under(rb_cQDialogDialogCode, "Rejected", QDialog::DialogCode::Rejected);
        define_qenum_value_under(rb_cQDialogDialogCode, "Accepted", QDialog::DialogCode::Accepted);
}
