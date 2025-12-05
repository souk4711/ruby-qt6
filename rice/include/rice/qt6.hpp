// macros
#define RUBYQT6_DECL_DLLEXPORT __declspec(dllexport)
#define RUBYQT6_DECL_DLLIMPORT __declspec(dllimport)

// include rice stuffs
#include <rice/rice.hpp>
#include <rice/stl.hpp>

// ruby/win32.h has a few defines that conflict with libQt6
#ifdef _WIN32
#  undef access
#  undef stat
#  undef truncate
#endif

// include rubyqt6 stuffs
#include <rice/qt6/qtcore.hpp>
