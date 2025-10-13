#include "qtprintsupport-rb.hpp"
#include "qtprintsupportversion-rb.hpp"

extern "C" void Init_qtprintsupport()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtPrintSupport = define_module_under(rb_mQt6, "QtPrintSupport");

        Init_qtprintsupportversion(rb_mQt6QtPrintSupport);
    });
}
