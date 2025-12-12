#include "qtmultimediaversion-rb.hpp"
#include <qtmultimediaversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtmultimediaversion(Module rb_mQt6QtMultimedia)
{
    rb_mQt6QtMultimedia.define_constant("QTMULTIMEDIA_VERSION", QTMULTIMEDIA_VERSION_STR);
}
