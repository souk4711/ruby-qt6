#include "kcoreaddons-rb.hpp"
#include "kcoreaddonsversion-rb.hpp"

#include "kaboutdata-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_kcoreaddons()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6KCoreAddons = define_module_under(rb_mQt6, "KCoreAddons");

        Init_kcoreaddonsversion(rb_mQt6KCoreAddons);

        Init_kaboutdata(rb_mQt6KCoreAddons);
    });
}
