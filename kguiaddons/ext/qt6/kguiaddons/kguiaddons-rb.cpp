#include "kguiaddons-rb.hpp"
#include "kguiaddonsversion-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_kguiaddons()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6KGuiAddons = define_module_under(rb_mQt6, "KGuiAddons");

        Init_kguiaddonsversion(rb_mQt6KGuiAddons);
    });
}
