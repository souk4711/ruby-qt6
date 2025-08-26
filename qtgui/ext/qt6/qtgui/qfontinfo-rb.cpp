#include "qfontinfo-rb.hpp"
#include <qfontinfo.h>

using namespace Rice;

Rice::Class rb_cQFontInfo;

void Init_qfontinfo(Rice::Module rb_mQt6QtGui)
{
    rb_cQFontInfo =
        // RubyQt6::QtGui::QFontInfo
        define_class_under<QFontInfo>(rb_mQt6QtGui, "QFontInfo");
}
