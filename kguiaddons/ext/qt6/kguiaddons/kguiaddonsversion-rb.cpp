#include "kguiaddonsversion-rb.hpp"
#include <kguiaddons_version.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_kguiaddonsversion(Module rb_mQt6KGuiAddons)
{
    rb_mQt6KGuiAddons.define_constant("KGUIADDONS_VERSION", KGUIADDONS_VERSION_STRING);
}
