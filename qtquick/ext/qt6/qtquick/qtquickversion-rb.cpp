#include "qtquickversion-rb.hpp"
#include <qtquickversion.h>

using namespace Rice;

void Init_qtquickversion(Rice::Module rb_mQt6QtQuick)
{
    rb_mQt6QtQuick.define_constant("QTQUICK_VERSION", QTQUICK_VERSION_STR);
}
