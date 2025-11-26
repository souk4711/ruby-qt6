#include "qtimer-rb.hpp"
#include <qtimer.h>

#include <QBindable>

using namespace Rice;

Rice::Class rb_cQTimer;

void Init_qtimer(Rice::Module rb_mQt6QtCore)
{
    rb_cQTimer =
        // RubyQt6::QtCore::QTimer
        define_class_under<QTimer, QObject>(rb_mQt6QtCore, "QTimer")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTimer::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTimer, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("bindable_active", &QTimer::bindableActive)
            .define_method("bindable_interval", &QTimer::bindableInterval)
            .define_method("bindable_single_shot", &QTimer::bindableSingleShot)
            .define_method("bindable_timer_type", &QTimer::bindableTimerType)
            .define_method("id", &QTimer::id)
            .define_method("interval", &QTimer::interval)
            .define_method("interval_as_duration", &QTimer::intervalAsDuration)
            .define_method("active?", &QTimer::isActive)
            .define_method("single_shot?", &QTimer::isSingleShot)
            .define_method("remaining_time", &QTimer::remainingTime)
            .define_method("remaining_time_as_duration", &QTimer::remainingTimeAsDuration)
            .define_method<void (QTimer::*)(int)>("set_interval", &QTimer::setInterval, Arg("msec"))
            .define_method<void (QTimer::*)(std::chrono::milliseconds)>("set_interval", &QTimer::setInterval, Arg("value"))
            .define_method("set_single_shot", &QTimer::setSingleShot, Arg("single_shot"))
            .define_method("set_timer_type", &QTimer::setTimerType, Arg("atype"))
            .define_method<void (QTimer::*)(std::chrono::milliseconds)>("start", &QTimer::start, Arg("value"))
            .define_method("timer_id", &QTimer::timerId)
            .define_method("timer_type", &QTimer::timerType)
            // Public Slots
            .define_method<void (QTimer::*)(int)>("start", &QTimer::start, Arg("msec"))
            .define_method<void (QTimer::*)()>("start", &QTimer::start)
            .define_method("stop", &QTimer::stop)
            // Signals
            // .define_method("timeout", &QTimer::timeout)
            // Static Public Members
            .define_singleton_function<void (*)(int, Qt::TimerType, const QObject *, const char *)>("_single_shot", &QTimer::singleShot, Arg("msec"), Arg("timer_type"), Arg("receiver"), Arg("member"))
            .define_singleton_function<void (*)(int, const QObject *, const char *)>("_single_shot", &QTimer::singleShot, Arg("msec"), Arg("receiver"), Arg("member"));
}
