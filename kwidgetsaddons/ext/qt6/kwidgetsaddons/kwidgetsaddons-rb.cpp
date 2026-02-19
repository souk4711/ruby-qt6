#include "kwidgetsaddons-rb.hpp"
#include "kwidgetsaddonsversion-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_kwidgetsaddons()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6KWidgetsAddons = define_module_under(rb_mQt6, "KWidgetsAddons");

        Init_kwidgetsaddonsversion(rb_mQt6KWidgetsAddons);
    });
}
