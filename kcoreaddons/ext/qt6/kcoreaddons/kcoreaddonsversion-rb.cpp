#include "kcoreaddonsversion-rb.hpp"
#include <kcoreaddons_version.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_kcoreaddonsversion(Module rb_mQt6KCoreAddons)
{
    rb_mQt6KCoreAddons.define_constant("KCOREADDONS_VERSION", KCOREADDONS_VERSION_STRING);
}
