#include "qtdbus-rb.hpp"
#include "qtdbusversion-rb.hpp"
#include "qdbus-enum-rb.hpp"

#include "qdbusconnection-rb.hpp"
#include "qdbuserror-rb.hpp"
#include "qdbusmessage-rb.hpp"

#include "qdbusabstractadaptor-rb.hpp"
#include "qdbusabstractinterface-rb.hpp"
#include "qdbusconnectioninterface-rb.hpp"
#include "qdbusinterface-rb.hpp"

#include "t-qtdbus-rb.hpp"

#include "bando-qdbusinterface-rb.hpp"

extern "C" void Init_qtdbus()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtDBus = define_module_under(rb_mQt6, "QtDBus");

        Init_qtdbusversion(rb_mQt6QtDBus);
        Init_qdbus_enum(rb_mQt6QtDBus);

        Init_qdbusconnection(rb_mQt6QtDBus);
        Init_qdbuserror(rb_mQt6QtDBus);
        Init_qdbusmessage(rb_mQt6QtDBus);

        Init_qdbusabstractadaptor(rb_mQt6QtDBus);
        Init_qdbusabstractinterface(rb_mQt6QtDBus);
        Init_qdbusconnectioninterface(rb_mQt6QtDBus);
        Init_qdbusinterface(rb_mQt6QtDBus);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtdbus(rb_mQt6T);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qdbusinterface(rb_mQt6Bando);
    });
}
