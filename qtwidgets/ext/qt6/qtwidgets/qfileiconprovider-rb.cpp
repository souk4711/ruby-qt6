#include "qfileiconprovider-rb.hpp"
#include <qfileiconprovider.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFileIconProvider;

void Init_qfileiconprovider(Module rb_mQt6QtWidgets)
{
    rb_cQFileIconProvider =
        // RubyQt6::QtWidgets::QFileIconProvider
        define_class_under<QFileIconProvider, QAbstractFileIconProvider>(rb_mQt6QtWidgets, "QFileIconProvider")
            // Constructor
            .define_constructor(Constructor<QFileIconProvider>())
            // Public Functions
            .define_method<QIcon (QFileIconProvider::*)(const QFileInfo &) const>("icon", &QFileIconProvider::icon, Arg("info"));
}
