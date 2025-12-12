#include "qtnetwork-rb.hpp"
#include "qtnetworkversion-rb.hpp"

#include "qnetworkproxy-rb.hpp"

#include "t-qtnetwork-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtnetwork()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtNetwork = define_module_under(rb_mQt6, "QtNetwork");

        Init_qtnetworkversion(rb_mQt6QtNetwork);

        Init_qnetworkproxy(rb_mQt6QtNetwork);

        Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtnetwork(rb_mQt6T);
    });
}
