#include "qtcore-rb.hpp"

#include "qt-rb.hpp"

#include "qstring-rb.hpp"
#include "qurl-rb.hpp"

#include "qobject-rb.hpp"

#include "qcoreapplication-rb.hpp"

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_qt(rb_mQt6QtCore);

        Init_qstring(rb_mQt6QtCore);
        Init_qurl(rb_mQt6QtCore);

        Init_qobject(rb_mQt6QtCore);

        Init_qcoreapplication(rb_mQt6QtCore);
    });
}
