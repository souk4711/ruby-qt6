#include "qlayout-rb.hpp"
#include <QLayout>

using namespace Rice;

Rice::Class rb_cQLayout;

void Init_QLayout(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQLayout = // Qt6::QtWidgets::QLayout
        define_class_under<QLayout, QObject>(rb_mQt6QtWidgets, "QLayout");
}
