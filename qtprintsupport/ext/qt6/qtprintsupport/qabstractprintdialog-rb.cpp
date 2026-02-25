#include "qabstractprintdialog-rb.hpp"
#include <qabstractprintdialog.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QPrinter>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractPrintDialog;

void Init_qabstractprintdialog(Module rb_mQt6QtPrintSupport)
{
    rb_cQAbstractPrintDialog =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog
        define_qlass_under<QAbstractPrintDialog, QDialog>(rb_mQt6QtPrintSupport, "QAbstractPrintDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAbstractPrintDialog * { return qobject_cast<QAbstractPrintDialog *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractPrintDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAbstractPrintDialog, QPrinter *, QWidget *>(), Arg("printer"), Arg("parent"))
            // Public Functions
            .define_method("from_page", &QAbstractPrintDialog::fromPage)
            .define_method("max_page", &QAbstractPrintDialog::maxPage)
            .define_method("min_page", &QAbstractPrintDialog::minPage)
            .define_method("print_range", &QAbstractPrintDialog::printRange)
            .define_method("printer", &QAbstractPrintDialog::printer)
            .define_method("set_from_to", &QAbstractPrintDialog::setFromTo, Arg("from_page"), Arg("to_page"))
            .define_method("set_min_max", &QAbstractPrintDialog::setMinMax, Arg("min"), Arg("max"))
            .define_method("set_option_tabs", &QAbstractPrintDialog::setOptionTabs, Arg("tabs"))
            .define_method("set_print_range", &QAbstractPrintDialog::setPrintRange, Arg("range"))
            .define_method("to_page", &QAbstractPrintDialog::toPage);

   Data_Type<QAbstractPrintDialog::PrintDialogOption> rb_cQAbstractPrintDialogPrintDialogOption =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintDialogOption
        define_qenum_under<QAbstractPrintDialog::PrintDialogOption>(rb_cQAbstractPrintDialog, "PrintDialogOption");
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintToFile", QAbstractPrintDialog::PrintDialogOption::PrintToFile);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintSelection", QAbstractPrintDialog::PrintDialogOption::PrintSelection);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintPageRange", QAbstractPrintDialog::PrintDialogOption::PrintPageRange);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintShowPageSize", QAbstractPrintDialog::PrintDialogOption::PrintShowPageSize);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintCollateCopies", QAbstractPrintDialog::PrintDialogOption::PrintCollateCopies);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintDialogOption, "PrintCurrentPage", QAbstractPrintDialog::PrintDialogOption::PrintCurrentPage);

    Data_Type<QAbstractPrintDialog::PrintRange> rb_cQAbstractPrintDialogPrintRange =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintRange
        define_qenum_under<QAbstractPrintDialog::PrintRange>(rb_cQAbstractPrintDialog, "PrintRange");
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintRange, "AllPages", QAbstractPrintDialog::PrintRange::AllPages);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintRange, "Selection", QAbstractPrintDialog::PrintRange::Selection);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintRange, "PageRange", QAbstractPrintDialog::PrintRange::PageRange);
        define_qenum_value_under(rb_cQAbstractPrintDialogPrintRange, "CurrentPage", QAbstractPrintDialog::PrintRange::CurrentPage);

    Data_Type<QFlags<QAbstractPrintDialog::PrintDialogOption>> rb_cQAbstractPrintDialogPrintDialogOptions =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintDialogOptions
        define_qflags_under<QAbstractPrintDialog::PrintDialogOption>(rb_cQAbstractPrintDialog, "PrintDialogOptions");
}
