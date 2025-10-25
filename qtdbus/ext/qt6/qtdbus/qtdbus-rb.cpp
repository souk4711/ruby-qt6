#include "qtdbus-rb.hpp"
#include "qtdbusversion-rb.hpp"

extern "C" void Init_qtdbus()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtDBus = define_module_under(rb_mQt6, "QtDBus");

        Init_qtdbusversion(rb_mQt6QtDBus);
    });
}
