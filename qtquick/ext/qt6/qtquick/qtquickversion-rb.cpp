#include "qtquickversion-rb.hpp"
#include <qtquickversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtquickversion(Module rb_mQt6QtQuick)
{
    rb_mQt6QtQuick.define_constant("QTQUICK_VERSION", QTQUICK_VERSION_STR);
}
