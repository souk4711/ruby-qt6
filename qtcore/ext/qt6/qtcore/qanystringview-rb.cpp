#include "qanystringview-rb.hpp"
#include <qanystringview.h>

#include <QString>

using namespace Rice;

Rice::Class rb_cQAnyStringView;

void Init_qanystringview(Rice::Module rb_mQt6QtCore)
{
    rb_cQAnyStringView =
        // RubyQt6::QtCore::QAnyStringView
        define_class_under<QAnyStringView>(rb_mQt6QtCore, "QAnyStringView")
            // Constructor
            .define_constructor(Constructor<QAnyStringView, const QString &>(), Arg("str"))
            .define_method("to_string", &QAnyStringView::toString);
}
