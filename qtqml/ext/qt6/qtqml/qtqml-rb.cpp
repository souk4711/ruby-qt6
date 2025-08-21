#include "qtqml-rb.hpp"

// clang-format off
#include "qtqmlversion-rb.hpp"

#include "qjsengine-rb.hpp"
#include "qqmlengine-rb.hpp"
#include "qqmlapplicationengine-rb.hpp"
// clang-format on

extern "C" void Init_qtqml()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQml = define_module_under(rb_mQt6, "QtQml");

        Init_qtqmlversion(rb_mQt6QtQml);

        Init_qjsengine(rb_mQt6QtQml);
        Init_qqmlengine(rb_mQt6QtQml);
        Init_qqmlapplicationengine(rb_mQt6QtQml);
    });
}
