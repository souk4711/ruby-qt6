#include "qpen-rb.hpp"
#include <qpen.h>

using namespace Rice;

Rice::Class rb_cQPen;

void Init_qpen(Rice::Module rb_mQt6QtGui)
{
    rb_cQPen =
        // Qt6::QtGui::QPen
        define_class_under<QPen>(rb_mQt6QtGui, "QPen")
            .define_constructor(Constructor<QPen>());
}
