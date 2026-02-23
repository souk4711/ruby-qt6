#include "qtqml-rb.hpp"
#include "qtqmlpreludes-rb.hpp"
#include "qtqmlversion-rb.hpp"

#include "qjsengine-rb.hpp"
#include "qqmlengine-rb.hpp"
#include "qqmlapplicationengine-rb.hpp"
#include "qqmlcontext-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtqml()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtQml = define_module_under(rb_mQt6, "QtQml");

        Init_qtqmlpreludes(rb_mQt6);
        Init_qtqmlversion(rb_mQt6QtQml);

        Init_qjsengine(rb_mQt6QtQml);
        Init_qqmlengine(rb_mQt6QtQml);
        Init_qqmlapplicationengine(rb_mQt6QtQml);
        Init_qqmlcontext(rb_mQt6QtQml);
    });
}
