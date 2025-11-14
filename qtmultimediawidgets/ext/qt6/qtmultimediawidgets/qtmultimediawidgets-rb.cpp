#include "qtmultimediawidgets-rb.hpp"
#include "qtmultimediawidgetsversion-rb.hpp"

extern "C" void Init_qtmultimediawidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtMultimediaWidgets = define_module_under(rb_mQt6, "QtMultimediaWidgets");

        Init_qtmultimediawidgetsversion(rb_mQt6QtMultimediaWidgets);
    });
}
