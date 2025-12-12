#include "qtmultimediawidgets-rb.hpp"
#include "qtmultimediawidgetsversion-rb.hpp"

#include "qvideowidget-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtmultimediawidgets()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtMultimediaWidgets = define_module_under(rb_mQt6, "QtMultimediaWidgets");

        Init_qtmultimediawidgetsversion(rb_mQt6QtMultimediaWidgets);

        Init_qvideowidget(rb_mQt6QtMultimediaWidgets);
    });
}
