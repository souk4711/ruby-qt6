#include "qtnetwork-rb.hpp"
#include "qtnetworkversion-rb.hpp"

#include "qnetworkproxy-rb.hpp"

#include "t-qtnetwork-rb.hpp"

extern "C" void Init_qtnetwork()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtNetwork = define_module_under(rb_mQt6, "QtNetwork");

        Init_qtnetworkversion(rb_mQt6QtNetwork);

        Init_qnetworkproxy(rb_mQt6QtNetwork);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtnetwork(rb_mQt6T);
    });
}
