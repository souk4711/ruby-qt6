#include "qabstractprintdialog-rb.hpp"
#include <qabstractprintdialog.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QPrinter>

using namespace Rice;

Rice::Class rb_cQAbstractPrintDialog;

void Init_qabstractprintdialog(Rice::Module rb_mQt6QtPrintSupport)
{
    rb_cQAbstractPrintDialog =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog
        define_class_under<QAbstractPrintDialog, QDialog>(rb_mQt6QtPrintSupport, "QAbstractPrintDialog")
            // RubyQt6-Defined Functions
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

   Enum<QAbstractPrintDialog::PrintDialogOption> rb_cQAbstractPrintDialogPrintDialogOption =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintDialogOption
        define_qenum_under<QAbstractPrintDialog::PrintDialogOption>("PrintDialogOption", rb_cQAbstractPrintDialog)
            .define_value("PrintToFile", QAbstractPrintDialog::PrintDialogOption::PrintToFile)
            .define_value("PrintSelection", QAbstractPrintDialog::PrintDialogOption::PrintSelection)
            .define_value("PrintPageRange", QAbstractPrintDialog::PrintDialogOption::PrintPageRange)
            .define_value("PrintShowPageSize", QAbstractPrintDialog::PrintDialogOption::PrintShowPageSize)
            .define_value("PrintCollateCopies", QAbstractPrintDialog::PrintDialogOption::PrintCollateCopies)
            .define_value("PrintCurrentPage", QAbstractPrintDialog::PrintDialogOption::PrintCurrentPage);

    Enum<QAbstractPrintDialog::PrintRange> rb_cQAbstractPrintDialogPrintRange =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintRange
        define_qenum_under<QAbstractPrintDialog::PrintRange>("PrintRange", rb_cQAbstractPrintDialog)
            .define_value("AllPages", QAbstractPrintDialog::PrintRange::AllPages)
            .define_value("Selection", QAbstractPrintDialog::PrintRange::Selection)
            .define_value("PageRange", QAbstractPrintDialog::PrintRange::PageRange)
            .define_value("CurrentPage", QAbstractPrintDialog::PrintRange::CurrentPage);

    Data_Type<QFlags<QAbstractPrintDialog::PrintDialogOption>> rb_cQAbstractPrintDialogPrintDialogOptions =
        // RubyQt6::QtPrintSupport::QAbstractPrintDialog::PrintDialogOptions
        define_qflags_under<QAbstractPrintDialog::PrintDialogOption>(rb_cQAbstractPrintDialog, "PrintDialogOptions");
}
