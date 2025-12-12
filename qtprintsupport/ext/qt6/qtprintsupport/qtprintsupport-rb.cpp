#include "qtprintsupport-rb.hpp"
#include "qtprintsupportversion-rb.hpp"

#include "qprinter-rb.hpp"
#include "qprinterinfo-rb.hpp"

#include "qabstractprintdialog-rb.hpp"
#include "qprintdialog-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtprintsupport()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtPrintSupport = define_module_under(rb_mQt6, "QtPrintSupport");

        Init_qtprintsupportversion(rb_mQt6QtPrintSupport);

        Init_qprinter(rb_mQt6QtPrintSupport);
        Init_qprinterinfo(rb_mQt6QtPrintSupport);

        Init_qabstractprintdialog(rb_mQt6QtPrintSupport);
        Init_qprintdialog(rb_mQt6QtPrintSupport);
    });
}
