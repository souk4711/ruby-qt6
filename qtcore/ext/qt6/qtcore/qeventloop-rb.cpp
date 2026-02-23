#include "qeventloop-rb.hpp"
#include <qeventloop.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQEventLoop;

void Init_qeventloop(Module rb_mQt6QtCore)
{
    rb_cQEventLoop =
        // RubyQt6::QtCore::QEventLoop
        define_qlass_under<QEventLoop, QObject>(rb_mQt6QtCore, "QEventLoop")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QEventLoop::staticMetaObject; });

    Data_Type<QEventLoop::ProcessEventsFlag> rb_cQEventLoopProcessEventsFlag =
        // RubyQt6::QtCore::QEventLoop::ProcessEventsFlag
        define_qenum_under<QEventLoop::ProcessEventsFlag>(rb_cQEventLoop, "ProcessEventsFlag");
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "AllEvents", QEventLoop::ProcessEventsFlag::AllEvents);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "ExcludeUserInputEvents", QEventLoop::ProcessEventsFlag::ExcludeUserInputEvents);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "ExcludeSocketNotifiers", QEventLoop::ProcessEventsFlag::ExcludeSocketNotifiers);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "WaitForMoreEvents", QEventLoop::ProcessEventsFlag::WaitForMoreEvents);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "X11ExcludeTimers", QEventLoop::ProcessEventsFlag::X11ExcludeTimers);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "EventLoopExec", QEventLoop::ProcessEventsFlag::EventLoopExec);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "DialogExec", QEventLoop::ProcessEventsFlag::DialogExec);
        define_qenum_value_under(rb_cQEventLoopProcessEventsFlag, "ApplicationExec", QEventLoop::ProcessEventsFlag::ApplicationExec);

    Data_Type<QFlags<QEventLoop::ProcessEventsFlag>> rb_cQEventLoopProcessEventsFlags =
        // RubyQt6::QtCore::QEventLoop::ProcessEventsFlags
        define_qflags_under<QEventLoop::ProcessEventsFlag>(rb_cQEventLoop, "ProcessEventsFlags");
}
