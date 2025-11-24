#include "qttest-rb.hpp"
#include "qttestversion-rb.hpp"

#include "t-qttest-rb.hpp"
#include "qsignalspy-rb.hpp"

extern "C" void Init_qttest()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtTest = define_module_under(rb_mQt6, "QtTest");

        Init_qttestversion(rb_mQt6QtTest);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qttest(rb_mQt6T);
        Init_qsignalspy(rb_mQt6QtTest);
    });
}
