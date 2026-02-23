#include "rice-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_rice()
{
    return detail::cpp_protect([] {
        RubyQt6_RTypedData_Registries::instance();
    });
}
