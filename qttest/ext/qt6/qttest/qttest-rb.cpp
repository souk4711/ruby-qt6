#include "qttest-rb.hpp"
#include "qttestversion-rb.hpp"

#include "t-qttest-rb.hpp"
#include "qsignalspy-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qttest()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtTest = define_module_under(rb_mQt6, "QtTest");

        Init_qttestversion(rb_mQt6QtTest);

        Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qttest(rb_mQt6T);
        Init_qsignalspy(rb_mQt6QtTest);
    });
}
