#include "qtgui-rb.hpp"
#include "qtguiversion-rb.hpp"

#include "qcolor-rb.hpp"
#include "qfont-rb.hpp"
#include "qfontinfo-rb.hpp"
#include "qicon-rb.hpp"
#include "qpen-rb.hpp"

#include "qpaintdevice-rb.hpp"
#include "qimage-rb.hpp"
#include "qpicture-rb.hpp"
#include "qpixmap-rb.hpp"

#include "qwindow-rb.hpp"
#include "qguiapplication-rb.hpp"

extern "C" void Init_qtgui()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");

        Init_qtguiversion(rb_mQt6QtGui);

        Init_qcolor(rb_mQt6QtGui);
        Init_qfont(rb_mQt6QtGui);
        Init_qfontinfo(rb_mQt6QtGui);
        Init_qicon(rb_mQt6QtGui);
        Init_qpen(rb_mQt6QtGui);

        Init_qpaintdevice(rb_mQt6QtGui);
        Init_qimage(rb_mQt6QtGui);
        Init_qpicture(rb_mQt6QtGui);
        Init_qpixmap(rb_mQt6QtGui);

        Init_qwindow(rb_mQt6QtGui);
        Init_qguiapplication(rb_mQt6QtGui);
    });
}
