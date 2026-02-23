#include "qabstractfileiconprovider-rb.hpp"
#include <qabstractfileiconprovider.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractFileIconProvider;

void Init_qabstractfileiconprovider(Module rb_mQt6QtGui)
{
    rb_cQAbstractFileIconProvider =
        // RubyQt6::QtGui::QAbstractFileIconProvider
        define_qlass_under<QAbstractFileIconProvider>(rb_mQt6QtGui, "QAbstractFileIconProvider");
}
