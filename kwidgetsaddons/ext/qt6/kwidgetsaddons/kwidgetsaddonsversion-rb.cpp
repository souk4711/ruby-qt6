#include "kwidgetsaddonsversion-rb.hpp"
#include <kwidgetsaddons_version.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_kwidgetsaddonsversion(Module rb_mQt6KWidgetsAddons)
{
    rb_mQt6KWidgetsAddons.define_constant("KWIDGETSADDONS_VERSION", KWIDGETSADDONS_VERSION_STRING);
}
