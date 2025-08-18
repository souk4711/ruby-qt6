#include "qtcore-rb.hpp"

#include "qcoreapplication-rb.hpp"
#include "qobject-rb.hpp"
#include "qt-rb.hpp"

extern "C" void Init_qtcore()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");

        Init_Qt(rb_mQt6QtCore);
        Init_QObject(rb_mQt6QtCore);
        Init_QCoreApplication(rb_mQt6QtCore);
    });
}
