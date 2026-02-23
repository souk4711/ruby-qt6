#include "qstylefactory-rb.hpp"
#include <qstylefactory.h>

#include <QStyle>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQStyleFactory;

void Init_qstylefactory(Module rb_mQt6QtWidgets)
{
    rb_cQStyleFactory =
        // RubyQt6::QtWidgets::QStyleFactory
        define_qlass_under<QStyleFactory>(rb_mQt6QtWidgets, "QStyleFactory")
            // Static Public Members
            .define_singleton_function("create", &QStyleFactory::create, Arg("key"))
            .define_singleton_function("keys", &QStyleFactory::keys);
}
