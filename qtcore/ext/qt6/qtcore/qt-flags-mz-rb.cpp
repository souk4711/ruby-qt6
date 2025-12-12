#include "qt-flags-mz-rb.hpp"
#include <qnamespace.h>

#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qt_flags_mz(Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Data_Type<QFlags<Qt::MatchFlag>> rb_cQtMatchFlags =
        // RubyQt6::QtCore::Qt::MatchFlags
        define_qflags_under<Qt::MatchFlag>(rb_mQt, "MatchFlags");

    Data_Type<QFlags<Qt::Modifier>> rb_cQtModifiers =
        // RubyQt6::QtCore::Qt::Modifiers
        define_qflags_under<Qt::Modifier>(rb_mQt, "Modifiers");

    Data_Type<QFlags<Qt::MouseButton>> rb_cQtMouseButtons =
        // RubyQt6::QtCore::Qt::MouseButtons
        define_qflags_under<Qt::MouseButton>(rb_mQt, "MouseButtons");

    Data_Type<QFlags<Qt::MouseEventFlag>> rb_cQtMouseEventFlags =
        // RubyQt6::QtCore::Qt::MouseEventFlags
        define_qflags_under<Qt::MouseEventFlag>(rb_mQt, "MouseEventFlags");

    Data_Type<QFlags<Qt::Orientation>> rb_cQtOrientations =
        // RubyQt6::QtCore::Qt::Orientations
        define_qflags_under<Qt::Orientation>(rb_mQt, "Orientations");

    Data_Type<QFlags<Qt::ScreenOrientation>> rb_cQtScreenOrientations =
        // RubyQt6::QtCore::Qt::ScreenOrientations
        define_qflags_under<Qt::ScreenOrientation>(rb_mQt, "ScreenOrientations");

    Data_Type<QFlags<Qt::SplitBehaviorFlags>> rb_cQtSplitBehavior =
        // RubyQt6::QtCore::Qt::SplitBehavior
        define_qflags_under<Qt::SplitBehaviorFlags>(rb_mQt, "SplitBehavior");

    Data_Type<QFlags<Qt::TextInteractionFlag>> rb_cQtTextInteractionFlags =
        // RubyQt6::QtCore::Qt::TextInteractionFlags
        define_qflags_under<Qt::TextInteractionFlag>(rb_mQt, "TextInteractionFlags");

    Data_Type<QFlags<Qt::ToolBarArea>> rb_cQtToolBarAreas =
        // RubyQt6::QtCore::Qt::ToolBarAreas
        define_qflags_under<Qt::ToolBarArea>(rb_mQt, "ToolBarAreas");

    Data_Type<QFlags<Qt::TouchPointState>> rb_cQtTouchPointStates =
        // RubyQt6::QtCore::Qt::TouchPointStates
        define_qflags_under<Qt::TouchPointState>(rb_mQt, "TouchPointStates");

    Data_Type<QFlags<Qt::WindowState>> rb_cQtWindowStates =
        // RubyQt6::QtCore::Qt::WindowStates
        define_qflags_under<Qt::WindowState>(rb_mQt, "WindowStates");

    Data_Type<QFlags<Qt::WindowType>> rb_cQtWindowFlags =
        // RubyQt6::QtCore::Qt::WindowFlags
        define_qflags_under<Qt::WindowType>(rb_mQt, "WindowFlags");
}
