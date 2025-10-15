#include "qtgui-rb.hpp"
#include "qtguiversion-rb.hpp"

#include "qbrush-rb.hpp"
#include "qcolor-rb.hpp"
#include "qcursor-rb.hpp"
#include "qevent-rb.hpp"
#include "qfont-rb.hpp"
#include "qfontdatabase-rb.hpp"
#include "qfontinfo-rb.hpp"
#include "qfontmetrics-rb.hpp"
#include "qicon-rb.hpp"
#include "qkeysequence-rb.hpp"
#include "qpaintdevice-rb.hpp"
#include "qpagedpaintdevice-rb.hpp"
#include "qimage-rb.hpp"
#include "qimagewriter-rb.hpp"
#include "qpicture-rb.hpp"
#include "qpixmap-rb.hpp"
#include "qpainter-rb.hpp"
#include "qpainterpath-rb.hpp"
#include "qpainterpathstroker-rb.hpp"
#include "qpalette-rb.hpp"
#include "qpen-rb.hpp"
#include "qregion-rb.hpp"
#include "qtextcursor-rb.hpp"
#include "qtextoption-rb.hpp"
#include "qtransform-rb.hpp"

#include "qaction-rb.hpp"
#include "qactiongroup-rb.hpp"
#include "qclipboard-rb.hpp"
#include "qguiapplication-rb.hpp"
#include "qmovie-rb.hpp"
#include "qshortcut-rb.hpp"
#include "qtextdocument-rb.hpp"
#include "qvalidator-rb.hpp"
#include "qwindow-rb.hpp"

#include "t-qtgui-rb.hpp"
#include "qpolygon-rb.hpp"

#include "bando-qaction-rb.hpp"
#include "bando-qactiongroup-rb.hpp"
#include "bando-qguiapplication-rb.hpp"
#include "bando-qmovie-rb.hpp"
#include "bando-qshortcut-rb.hpp"
#include "bando-qtextdocument-rb.hpp"
#include "bando-qvalidator-rb.hpp"
#include "bando-qwindow-rb.hpp"

extern "C" void Init_qtgui()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");

        Init_qtguiversion(rb_mQt6QtGui);

        Init_qbrush(rb_mQt6QtGui);
        Init_qcolor(rb_mQt6QtGui);
        Init_qcursor(rb_mQt6QtGui);
        Init_qevent(rb_mQt6QtGui);
        Init_qfont(rb_mQt6QtGui);
        Init_qfontdatabase(rb_mQt6QtGui);
        Init_qfontinfo(rb_mQt6QtGui);
        Init_qfontmetrics(rb_mQt6QtGui);
        Init_qicon(rb_mQt6QtGui);
        Init_qkeysequence(rb_mQt6QtGui);
        Init_qpaintdevice(rb_mQt6QtGui);
        Init_qpagedpaintdevice(rb_mQt6QtGui);
        Init_qimage(rb_mQt6QtGui);
        Init_qimagewriter(rb_mQt6QtGui);
        Init_qpicture(rb_mQt6QtGui);
        Init_qpixmap(rb_mQt6QtGui);
        Init_qpainter(rb_mQt6QtGui);
        Init_qpainterpath(rb_mQt6QtGui);
        Init_qpainterpathstroker(rb_mQt6QtGui);
        Init_qpalette(rb_mQt6QtGui);
        Init_qpen(rb_mQt6QtGui);
        Init_qregion(rb_mQt6QtGui);
        Init_qtextcursor(rb_mQt6QtGui);
        Init_qtextoption(rb_mQt6QtGui);
        Init_qtransform(rb_mQt6QtGui);

        Init_qaction(rb_mQt6QtGui);
        Init_qactiongroup(rb_mQt6QtGui);
        Init_qclipboard(rb_mQt6QtGui);
        Init_qguiapplication(rb_mQt6QtGui);
        Init_qmovie(rb_mQt6QtGui);
        Init_qshortcut(rb_mQt6QtGui);
        Init_qtextdocument(rb_mQt6QtGui);
        Init_qvalidator(rb_mQt6QtGui);
        Init_qwindow(rb_mQt6QtGui);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtgui(rb_mQt6T);
        Init_qpolygon(rb_mQt6QtGui);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qaction(rb_mQt6Bando);
        Init_bando_qactiongroup(rb_mQt6Bando);
        Init_bando_qguiapplication(rb_mQt6Bando);
        Init_bando_qmovie(rb_mQt6Bando);
        Init_bando_qshortcut(rb_mQt6Bando);
        Init_bando_qtextdocument(rb_mQt6Bando);
        Init_bando_qvalidator(rb_mQt6Bando);
        Init_bando_qwindow(rb_mQt6Bando);
    });
}
