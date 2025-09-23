#include "qtcore-rb.hpp"
#include "qtcoreversion-rb.hpp"
#include "qt-rb.hpp"

#include "qchar-rb.hpp"
#include "qstring-rb.hpp"
#include "qanystringview-rb.hpp"
#include "qbytearray-rb.hpp"
#include "qdatetime-rb.hpp"
#include "qline-rb.hpp"
#include "qmargins-rb.hpp"
#include "qpoint-rb.hpp"
#include "qrect-rb.hpp"
#include "qsize-rb.hpp"
#include "qurl-rb.hpp"
#include "quuid-rb.hpp"
#include "qvariant-rb.hpp"

#include "qflags-rb.hpp"
#include "qstringlist-rb.hpp"

#include "qcoreevent-rb.hpp"

#include "qmetaobjectbuilder-rb.hpp"
#include "qmetaobject-rb.hpp"
#include "qmetamethod-rb.hpp"
#include "qmetatype-rb.hpp"

#include "qobject-rb.hpp"
#include "qcoreapplication-rb.hpp"
#include "qtimer-rb.hpp"

#include "bando-qtcore-rb.hpp"

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::init();

        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_qtcoreversion(rb_mQt6QtCore);
        Init_qt(rb_mQt6QtCore);

        Init_qchar(rb_mQt6QtCore);
        Init_qstring(rb_mQt6QtCore);
        Init_qanystringview(rb_mQt6QtCore);
        Init_qbytearray(rb_mQt6QtCore);
        Init_qdatetime(rb_mQt6QtCore);
        Init_qline(rb_mQt6QtCore);
        Init_qmargins(rb_mQt6QtCore);
        Init_qpoint(rb_mQt6QtCore);
        Init_qrect(rb_mQt6QtCore);
        Init_qsize(rb_mQt6QtCore);
        Init_qurl(rb_mQt6QtCore);
        Init_quuid(rb_mQt6QtCore);
        Init_qvariant(rb_mQt6QtCore);

        Init_qflags(rb_mQt6QtCore);
        Init_qstringlist(rb_mQt6QtCore);

        Init_qcoreevent(rb_mQt6QtCore);

        Init_qmetaobjectbuilder(rb_mQt6QtCore);
        Init_qmetaobject(rb_mQt6QtCore);
        Init_qmetamethod(rb_mQt6QtCore);
        Init_qmetatype(rb_mQt6QtCore);

        Init_qobject(rb_mQt6QtCore);
        Init_qcoreapplication(rb_mQt6QtCore);
        Init_qtimer(rb_mQt6QtCore);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qtcore(rb_mQt6Bando);
    });
}
