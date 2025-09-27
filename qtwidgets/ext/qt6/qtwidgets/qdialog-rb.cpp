#include "qdialog-rb.hpp"
#include <qdialog.h>

using namespace Rice;

Rice::Class rb_cQDialog;

void Init_qdialog(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQDialog =
        // RubyQt6::QtWidgets::QDialog
        define_class_under<QDialog, QWidget>(rb_mQt6QtWidgets, "QDialog")
            // Constructor
            .define_constructor(Constructor<QDialog, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("size_grip_enabled?", &QDialog::isSizeGripEnabled)
            .define_method("minimum_size_hint", &QDialog::minimumSizeHint)
            .define_method("result", &QDialog::result)
            .define_method("set_modal", &QDialog::setModal, Arg("modal"))
            .define_method("set_result", &QDialog::setResult, Arg("r"))
            .define_method("set_size_grip_enabled", &QDialog::setSizeGripEnabled, Arg("enabled"))
            .define_method("set_visible", &QDialog::setVisible, Arg("visible"))
            .define_method("size_hint", &QDialog::sizeHint)
            // Public Slots
            .define_method("accept", &QDialog::accept)
            .define_method("done", &QDialog::done, Arg("r"))
            .define_method("exec", &QDialog::exec)
            .define_method("open", &QDialog::open)
            .define_method("reject", &QDialog::reject)
            // Signals
            .define_method("accepted", &QDialog::accepted)
            .define_method("finished", &QDialog::finished, Arg("result"))
            .define_method("rejected", &QDialog::rejected);

    Enum<QDialog::DialogCode> rb_cQDialogDialogCode =
        // RubyQt6::QtWidgets::QDialog::DialogCode
        define_enum_under<QDialog::DialogCode>("DialogCode", rb_cQDialog)
            .define_value("Rejected", QDialog::DialogCode::Rejected)
            .define_value("Accepted", QDialog::DialogCode::Accepted);
}
