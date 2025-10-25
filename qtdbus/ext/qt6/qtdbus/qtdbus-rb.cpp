#include "qtdbus-rb.hpp"
#include "qtdbusversion-rb.hpp"

#include "qdbusconnection-rb.hpp"
#include "qdbuserror-rb.hpp"
#include "qdbusmessage-rb.hpp"

#include "qdbusabstractinterface-rb.hpp"
#include "qdbusconnectioninterface-rb.hpp"
#include "qdbusinterface-rb.hpp"

extern "C" void Init_qtdbus()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtDBus = define_module_under(rb_mQt6, "QtDBus");

        Init_qtdbusversion(rb_mQt6QtDBus);

        Init_qdbusconnection(rb_mQt6QtDBus);
        Init_qdbuserror(rb_mQt6QtDBus);
        Init_qdbusmessage(rb_mQt6QtDBus);

        Init_qdbusabstractinterface(rb_mQt6QtDBus);
        Init_qdbusconnectioninterface(rb_mQt6QtDBus);
        Init_qdbusinterface(rb_mQt6QtDBus);
    });
}
