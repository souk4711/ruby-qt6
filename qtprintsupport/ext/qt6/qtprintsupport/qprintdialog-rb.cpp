#include "qprintdialog-rb.hpp"
#include <qprintdialog.h>

#include <QPrinter>

using namespace Rice;

Rice::Class rb_cQPrintDialog;

void Init_qprintdialog(Rice::Module rb_mQt6QtPrintSupport)
{
    rb_cQPrintDialog =
        // RubyQt6::QtPrintSupport::QPrintDialog
        define_class_under<QPrintDialog, QAbstractPrintDialog>(rb_mQt6QtPrintSupport, "QPrintDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QPrintDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QPrintDialog, QPrinter *, QWidget *>(), Arg("printer"), Arg("parent"))
            // Public Functions
            .define_method("accept", &QPrintDialog::accept)
            .define_method("done", &QPrintDialog::done, Arg("result"))
            .define_method("exec", &QPrintDialog::exec)
            .define_method<void (QPrintDialog::*)(QObject *, const char *)>("open", &QPrintDialog::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QPrintDialog::options)
            .define_method("set_option", &QPrintDialog::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QPrintDialog::setOptions, Arg("options"))
            .define_method("set_visible", &QPrintDialog::setVisible, Arg("visible"))
            .define_method("test_option", &QPrintDialog::testOption, Arg("option"));
            // Signals
            // .define_method<void (QPrintDialog::*)(QPrinter *)>("accepted", &QPrintDialog::accepted, Arg("printer"));
}
