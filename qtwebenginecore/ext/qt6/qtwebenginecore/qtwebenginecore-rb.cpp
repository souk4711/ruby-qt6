#include "qtwebenginecore-rb.hpp"
#include "qtwebenginecoreversion-rb.hpp"

#include "qwebenginecertificateerror-rb.hpp"
#include "qwebenginefullscreenrequest-rb.hpp"
#include "qwebenginepermission-rb.hpp"
#include "qwebenginesettings-rb.hpp"

#include "qwebengineclienthints-rb.hpp"
#include "qwebenginecookiestore-rb.hpp"
#include "qwebenginedownloadrequest-rb.hpp"
#include "qwebenginenavigationrequest-rb.hpp"
#include "qwebenginenewwindowrequest-rb.hpp"
#include "qwebenginenotification-rb.hpp"
#include "qwebenginepage-rb.hpp"
#include "qwebengineprofile-rb.hpp"

#include "bando-qwebenginepage-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtwebenginecore()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtWebEngineCore = define_module_under(rb_mQt6, "QtWebEngineCore");

        Init_qtwebenginecoreversion(rb_mQt6QtWebEngineCore);

        Init_qwebenginecertificateerror(rb_mQt6QtWebEngineCore);
        Init_qwebenginefullscreenrequest(rb_mQt6QtWebEngineCore);
        Init_qwebenginepermission(rb_mQt6QtWebEngineCore);
        Init_qwebenginesettings(rb_mQt6QtWebEngineCore);

        Init_qwebengineclienthints(rb_mQt6QtWebEngineCore);
        Init_qwebenginecookiestore(rb_mQt6QtWebEngineCore);
        Init_qwebenginedownloadrequest(rb_mQt6QtWebEngineCore);
        Init_qwebenginenavigationrequest(rb_mQt6QtWebEngineCore);
        Init_qwebenginenewwindowrequest(rb_mQt6QtWebEngineCore);
        Init_qwebenginenotification(rb_mQt6QtWebEngineCore);
        Init_qwebenginepage(rb_mQt6QtWebEngineCore);
        Init_qwebengineprofile(rb_mQt6QtWebEngineCore);

        Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qwebenginepage(rb_mQt6Bando);
    });
}
