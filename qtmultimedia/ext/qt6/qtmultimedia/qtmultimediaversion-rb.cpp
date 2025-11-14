#include "qtmultimediaversion-rb.hpp"
#include <qtmultimediaversion.h>

using namespace Rice;

void Init_qtmultimediaversion(Rice::Module rb_mQt6QtMultimedia)
{
    rb_mQt6QtMultimedia.define_constant("QTMULTIMEDIA_VERSION", QTMULTIMEDIA_VERSION_STR);
}
