#include "qstylefactory-rb.hpp"
#include <qstylefactory.h>

#include <QStyle>

using namespace Rice;

Rice::Class rb_cQStyleFactory;

void Init_qstylefactory(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStyleFactory =
        // RubyQt6::QtWidgets::QStyleFactory
        define_class_under<QStyleFactory>(rb_mQt6QtWidgets, "QStyleFactory")
            // Static Public Members
            .define_singleton_function("create", &QStyleFactory::create, Arg("key"))
            .define_singleton_function("keys", &QStyleFactory::keys);
}
