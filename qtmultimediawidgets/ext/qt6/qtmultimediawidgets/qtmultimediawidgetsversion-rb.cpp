#include "qtmultimediawidgetsversion-rb.hpp"
#include <qtmultimediawidgetsversion.h>

using namespace Rice;

void Init_qtmultimediawidgetsversion(Rice::Module rb_mQt6QtMultimediaWidgets)
{
    rb_mQt6QtMultimediaWidgets.define_constant("QTMULTIMEDIAWIDGETS_VERSION", QTMULTIMEDIAWIDGETS_VERSION_STR);
}
