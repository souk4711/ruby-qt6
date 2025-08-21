#include "qcoreapplication-rb.hpp"
#include <qcoreapplication.h>

using namespace Rice;

Rice::Class rb_cQCoreApplication;

void Init_qcoreapplication(Rice::Module rb_mQt6QtCore)
{
    rb_cQCoreApplication =
        // Qt6::QtCore::QCoreApplication
        define_class_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication");
}
