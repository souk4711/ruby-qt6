#include <rice/rice.hpp>
#include <rice/stl.hpp>

// ruby/win32.h has a few defines that conflict with libQt6
#ifdef _WIN32
#undef access
#undef stat
#undef truncate
#endif
