#include "qanystringview-rb.hpp"
#include <qanystringview.h>

using namespace Rice;

Rice::Class rb_cQAnyStringView;

void Init_qanystringview(Rice::Module rb_mQt6QtCore)
{
    rb_cQAnyStringView =
        // Qt6::QtCore::QAnyStringView
        define_class_under<QAnyStringView>(rb_mQt6QtCore, "QAnyStringView");
}
