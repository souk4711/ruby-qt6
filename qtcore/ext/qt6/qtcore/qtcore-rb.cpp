#include "qtcore-rb.hpp"
#include "qtcoreversion-rb.hpp"
#include "qt-enum-af-rb.hpp"
#include "qt-enum-gl-rb.hpp"
#include "qt-enum-mr-rb.hpp"
#include "qt-enum-sz-rb.hpp"
#include "qt-flags-al-rb.hpp"
#include "qt-flags-mz-rb.hpp"

#include "qmetaclassinfo-rb.hpp"
#include "qmetamethod-rb.hpp"
#include "qmetaobject-rb.hpp"
#include "qmetaobjectbuilder-rb.hpp"
#include "qmetatype-rb.hpp"

#include "qanystringview-rb.hpp"
#include "qbytearray-rb.hpp"
#include "qchar-rb.hpp"
#include "qstring-rb.hpp"
#include "qiodevicebase-rb.hpp"

#include "qbasictimer-rb.hpp"
#include "qcoreevent-rb.hpp"
#include "qdatetime-rb.hpp"
#include "qdir-rb.hpp"
#include "qfileinfo-rb.hpp"
#include "qlibraryinfo-rb.hpp"
#include "qline-rb.hpp"
#include "qlocale-rb.hpp"
#include "qmargins-rb.hpp"
#include "qmodelindex-rb.hpp"
#include "qpoint-rb.hpp"
#include "qrect-rb.hpp"
#include "qregularexpression-rb.hpp"
#include "qresource-rb.hpp"
#include "qsize-rb.hpp"
#include "qtextstream-rb.hpp"
#include "qurl-rb.hpp"
#include "quuid-rb.hpp"
#include "qvariant-rb.hpp"

#include "qobject-rb.hpp"
#include "qabstractitemmodel-rb.hpp"
#include "qcoreapplication-rb.hpp"
#include "qiodevice-rb.hpp"
#include "qfiledevice-rb.hpp"
#include "qfile-rb.hpp"
#include "qitemselectionmodel-rb.hpp"
#include "qsettings-rb.hpp"
#include "qsignalmapper-rb.hpp"
#include "qtimer-rb.hpp"
#include "qtranslator-rb.hpp"

#include "t-qtcore-rb.hpp"
#include "qitemselection-rb.hpp"
#include "qstringlist-rb.hpp"

#include "bando-rb.hpp"
#include "bando-qobject-rb.hpp"

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::define_buffer<char *>();

        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_qtcoreversion(rb_mQt6QtCore);
        Init_qt_enum_af(rb_mQt6QtCore);
        Init_qt_enum_gl(rb_mQt6QtCore);
        Init_qt_enum_mr(rb_mQt6QtCore);
        Init_qt_enum_sz(rb_mQt6QtCore);
        Init_qt_flags_al(rb_mQt6QtCore);
        Init_qt_flags_mz(rb_mQt6QtCore);

        Init_qmetaclassinfo(rb_mQt6QtCore);
        Init_qmetamethod(rb_mQt6QtCore);
        Init_qmetaobject(rb_mQt6QtCore);
        Init_qmetaobjectbuilder(rb_mQt6QtCore);
        Init_qmetatype(rb_mQt6QtCore);

        Init_qanystringview(rb_mQt6QtCore);
        Init_qbytearray(rb_mQt6QtCore);
        Init_qchar(rb_mQt6QtCore);
        Init_qstring(rb_mQt6QtCore);
        Init_qiodevicebase(rb_mQt6QtCore);

        Init_qbasictimer(rb_mQt6QtCore);
        Init_qcoreevent(rb_mQt6QtCore);
        Init_qdatetime(rb_mQt6QtCore);
        Init_qdir(rb_mQt6QtCore);
        Init_qfileinfo(rb_mQt6QtCore);
        Init_qlibraryinfo(rb_mQt6QtCore);
        Init_qline(rb_mQt6QtCore);
        Init_qlocale(rb_mQt6QtCore);
        Init_qmargins(rb_mQt6QtCore);
        Init_qmodelindex(rb_mQt6QtCore);
        Init_qpoint(rb_mQt6QtCore);
        Init_qrect(rb_mQt6QtCore);
        Init_qregularexpression(rb_mQt6QtCore);
        Init_qresource(rb_mQt6QtCore);
        Init_qsize(rb_mQt6QtCore);
        Init_qtextstream(rb_mQt6QtCore);
        Init_qurl(rb_mQt6QtCore);
        Init_quuid(rb_mQt6QtCore);
        Init_qvariant(rb_mQt6QtCore);

        Init_qobject(rb_mQt6QtCore);
        Init_qabstractitemmodel(rb_mQt6QtCore);
        Init_qcoreapplication(rb_mQt6QtCore);
        Init_qiodevice(rb_mQt6QtCore);
        Init_qfiledevice(rb_mQt6QtCore);
        Init_qfile(rb_mQt6QtCore);
        Init_qitemselectionmodel(rb_mQt6QtCore);
        Init_qsettings(rb_mQt6QtCore);
        Init_qsignalmapper(rb_mQt6QtCore);
        Init_qtimer(rb_mQt6QtCore);
        Init_qtranslator(rb_mQt6QtCore);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtcore(rb_mQt6T);
        Init_qitemselection(rb_mQt6QtCore);
        Init_qstringlist(rb_mQt6QtCore);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando(rb_mQt6Bando);
        Init_bando_qobject(rb_mQt6Bando);
    });
}
