#include "qbasictimer-rb.hpp"
#include <qbasictimer.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQBasicTimer;

void Init_qbasictimer(Module rb_mQt6QtCore)
{
    rb_cQBasicTimer =
        // RubyQt6::QtCore::QBasicTimer
        define_class_under<QBasicTimer>(rb_mQt6QtCore, "QBasicTimer")
            // Constructor
            .define_constructor(Constructor<QBasicTimer>())
            // Public Functions
            .define_method("id", &QBasicTimer::id)
            .define_method("active?", &QBasicTimer::isActive)
            .define_method<void (QBasicTimer::*)(QBasicTimer::Duration, QObject *)>("start", &QBasicTimer::start, Arg("duration"), Arg("obj"))
            .define_method<void (QBasicTimer::*)(QBasicTimer::Duration, Qt::TimerType, QObject *)>("start", &QBasicTimer::start, Arg("duration"), Arg("timer_type"), Arg("obj"))
            .define_method<void (QBasicTimer::*)(int, QObject *)>("start", &QBasicTimer::start, Arg("msec"), Arg("obj"))
            .define_method<void (QBasicTimer::*)(int, Qt::TimerType, QObject *)>("start", &QBasicTimer::start, Arg("msec"), Arg("timer_type"), Arg("obj"))
            .define_method("stop", &QBasicTimer::stop)
            .define_method("timer_id", &QBasicTimer::timerId);
}
