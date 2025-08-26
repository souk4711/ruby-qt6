#include "qicon-rb.hpp"
#include <qicon.h>

using namespace Rice;

Rice::Class rb_cQIcon;

void Init_qicon(Rice::Module rb_mQt6QtGui)
{
    rb_cQIcon =
        // RubyQt6::QtGui::QIcon
        define_class_under<QIcon>(rb_mQt6QtGui, "QIcon");
}
