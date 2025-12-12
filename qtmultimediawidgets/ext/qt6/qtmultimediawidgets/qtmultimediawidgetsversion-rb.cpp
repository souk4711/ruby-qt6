#include "qtmultimediawidgetsversion-rb.hpp"
#include <qtmultimediawidgetsversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtmultimediawidgetsversion(Module rb_mQt6QtMultimediaWidgets)
{
    rb_mQt6QtMultimediaWidgets.define_constant("QTMULTIMEDIAWIDGETS_VERSION", QTMULTIMEDIAWIDGETS_VERSION_STR);
}
