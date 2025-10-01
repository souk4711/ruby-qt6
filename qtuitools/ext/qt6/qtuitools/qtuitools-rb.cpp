#include "qtuitools-rb.hpp"
#include "qtuitoolsversion-rb.hpp"

#include "quiloader-rb.hpp"

extern "C" void Init_qtuitools()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtUiTools = define_module_under(rb_mQt6, "QtUiTools");

        Init_quiloader(rb_mQt6QtUiTools);

        Init_qtuitoolsversion(rb_mQt6QtUiTools);
    });
}
