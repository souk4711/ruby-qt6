#include "qtuitools-rb.hpp"
#include "qtuitoolsversion-rb.hpp"

#include "quiloader-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtuitools()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtUiTools = define_module_under(rb_mQt6, "QtUiTools");

        Init_quiloader(rb_mQt6QtUiTools);

        Init_qtuitoolsversion(rb_mQt6QtUiTools);
    });
}
