#include "qsignalspy-rb.hpp"
#include <qsignalspy.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSignalSpy;

void Init_qsignalspy(Module rb_mQt6QtTest)
{
    rb_cQSignalSpy =
        // RubyQt6::QtTest::QSignalSpy
        define_class_under<QSignalSpy, QList<QList<QVariant>>>(rb_mQt6QtTest, "QSignalSpy")
            // Constructor
            .define_constructor(Constructor<QSignalSpy, const QObject *, const char *>(), Arg("receiver"), Arg("signal"))
            // Public Functions
            .define_method("valid?", &QSignalSpy::isValid)
            .define_method("signal", &QSignalSpy::signal)
            .define_method<bool (QSignalSpy::*)(int)>("wait", &QSignalSpy::wait, Arg("timeout"));
}
