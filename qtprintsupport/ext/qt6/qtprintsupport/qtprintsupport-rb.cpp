#include "qtprintsupport-rb.hpp"
#include "qtprintsupportversion-rb.hpp"

#include "qprinter-rb.hpp"
#include "qprinterinfo-rb.hpp"

#include "qabstractprintdialog-rb.hpp"
#include "qprintdialog-rb.hpp"

#include "bando-qabstractprintdialog-rb.hpp"
#include "bando-qprintdialog-rb.hpp"

extern "C" void Init_qtprintsupport()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtPrintSupport = define_module_under(rb_mQt6, "QtPrintSupport");

        Init_qtprintsupportversion(rb_mQt6QtPrintSupport);

        Init_qprinter(rb_mQt6QtPrintSupport);
        Init_qprinterinfo(rb_mQt6QtPrintSupport);

        Init_qabstractprintdialog(rb_mQt6QtPrintSupport);
        Init_qprintdialog(rb_mQt6QtPrintSupport);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qabstractprintdialog(rb_mQt6Bando);
        Init_bando_qprintdialog(rb_mQt6Bando);
    });
}
