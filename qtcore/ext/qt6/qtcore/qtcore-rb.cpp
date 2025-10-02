#include "qtcore-rb.hpp"
#include "qtcoreversion-rb.hpp"
#include "qt-enum-rb.hpp"
#include "qt-flags-rb.hpp"

#include "qmetamethod-rb.hpp"
#include "qmetaobject-rb.hpp"
#include "qmetaobjectbuilder-rb.hpp"
#include "qmetatype-rb.hpp"

#include "qanystringview-rb.hpp"
#include "qbytearray-rb.hpp"
#include "qchar-rb.hpp"
#include "qstring-rb.hpp"
#include "qiodevicebase-rb.hpp"

#include "qcoreevent-rb.hpp"
#include "qdatetime-rb.hpp"
#include "qdir-rb.hpp"
#include "qlibraryinfo-rb.hpp"
#include "qline-rb.hpp"
#include "qmargins-rb.hpp"
#include "qpoint-rb.hpp"
#include "qrect-rb.hpp"
#include "qresource-rb.hpp"
#include "qsize-rb.hpp"
#include "qurl-rb.hpp"
#include "quuid-rb.hpp"
#include "qvariant-rb.hpp"

#include "t-qtcore-rb.hpp"
#include "qstringlist-rb.hpp"

#include "qobject-rb.hpp"
#include "qcoreapplication-rb.hpp"
#include "qiodevice-rb.hpp"
#include "qfiledevice-rb.hpp"
#include "qfile-rb.hpp"
#include "qtimer-rb.hpp"
#include "qtranslator-rb.hpp"

#include "bando-qtcore-rb.hpp"

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::init();

        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_qtcoreversion(rb_mQt6QtCore);
        Init_qt_enum(rb_mQt6QtCore);
        Init_qt_flags(rb_mQt6QtCore);

        Init_qmetaobjectbuilder(rb_mQt6QtCore);
        Init_qmetaobject(rb_mQt6QtCore);
        Init_qmetamethod(rb_mQt6QtCore);
        Init_qmetatype(rb_mQt6QtCore);

        Init_qanystringview(rb_mQt6QtCore);
        Init_qbytearray(rb_mQt6QtCore);
        Init_qchar(rb_mQt6QtCore);
        Init_qstring(rb_mQt6QtCore);
        Init_qiodevicebase(rb_mQt6QtCore);

        Init_qcoreevent(rb_mQt6QtCore);
        Init_qdatetime(rb_mQt6QtCore);
        Init_qdir(rb_mQt6QtCore);
        Init_qlibraryinfo(rb_mQt6QtCore);
        Init_qline(rb_mQt6QtCore);
        Init_qmargins(rb_mQt6QtCore);
        Init_qpoint(rb_mQt6QtCore);
        Init_qrect(rb_mQt6QtCore);
        Init_qresource(rb_mQt6QtCore);
        Init_qsize(rb_mQt6QtCore);
        Init_qurl(rb_mQt6QtCore);
        Init_quuid(rb_mQt6QtCore);
        Init_qvariant(rb_mQt6QtCore);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtcore(rb_mQt6T);
        Init_qstringlist(rb_mQt6QtCore);

        Init_qobject(rb_mQt6QtCore);
        Init_qcoreapplication(rb_mQt6QtCore);
        Init_qiodevice(rb_mQt6QtCore);
        Init_qfiledevice(rb_mQt6QtCore);
        Init_qfile(rb_mQt6QtCore);
        Init_qtimer(rb_mQt6QtCore);
        Init_qtranslator(rb_mQt6QtCore);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qtcore(rb_mQt6Bando);
    });
}
