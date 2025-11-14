#include "qtmultimedia-rb.hpp"
#include "qtmultimediaversion-rb.hpp"

extern "C" void Init_qtmultimedia()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtMultimedia = define_module_under(rb_mQt6, "QtMultimedia");

        Init_qtmultimediaversion(rb_mQt6QtMultimedia);
    });
}
