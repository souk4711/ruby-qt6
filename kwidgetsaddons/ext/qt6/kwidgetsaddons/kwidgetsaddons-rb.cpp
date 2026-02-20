#include "kwidgetsaddons-rb.hpp"
#include "kwidgetsaddonsversion-rb.hpp"

#include "kguiitem-rb.hpp"
#include "kseparator-rb.hpp"

#include "bando-kseparator-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_kwidgetsaddons()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6KWidgetsAddons = define_module_under(rb_mQt6, "KWidgetsAddons");

        Init_kwidgetsaddonsversion(rb_mQt6KWidgetsAddons);

        Init_kguiitem(rb_mQt6KWidgetsAddons);
        Init_kseparator(rb_mQt6KWidgetsAddons);

        Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_kseparator(rb_mQt6Bando);
    });
}
