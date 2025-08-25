#include "qtcore-rb.hpp"

// clang-format off
#include "qt-rb.hpp"
#include "qtcoreversion-rb.hpp"

#include "qanystringview-rb.hpp"
#include "qstring-rb.hpp"
#include "qurl-rb.hpp"
#include "qvariant-rb.hpp"

#include "qobject-rb.hpp"
#include "qmetaobject-rb.hpp"
#include "qmetamethod-rb.hpp"
#include "qcoreapplication-rb.hpp"
// clang-format on

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_qt(rb_mQt6QtCore);
        Init_qtcoreversion(rb_mQt6QtCore);

        Init_qanystringview(rb_mQt6QtCore);
        Init_qstring(rb_mQt6QtCore);
        Init_qurl(rb_mQt6QtCore);
        Init_qvariant(rb_mQt6QtCore);

        Init_qobject(rb_mQt6QtCore);
        Init_qmetaobject(rb_mQt6QtCore);
        Init_qmetamethod(rb_mQt6QtCore);
        Init_qcoreapplication(rb_mQt6QtCore);
    });
}
