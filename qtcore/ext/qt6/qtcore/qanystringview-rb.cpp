#include "qanystringview-rb.hpp"
#include <qanystringview.h>

#include <QString>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAnyStringView;

void Init_qanystringview(Module rb_mQt6QtCore)
{
    rb_cQAnyStringView =
        // RubyQt6::QtCore::QAnyStringView
        define_qlass_under<QAnyStringView>(rb_mQt6QtCore, "QAnyStringView")
            // Constructor
            .define_constructor(Constructor<QAnyStringView, const QString &>(), Arg("str"))
            // Public Functions
            .define_method("to_string", &QAnyStringView::toString);
}
