#include "qt-flags-rb.hpp"
#include <qnamespace.h>

#include <rice/qflags.hpp>

using namespace Rice;

void Init_qt_flags(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Data_Type<QFlags<Qt::AlignmentFlag>> rb_cQtAlignment =
        // RubyQt6::QtCore::Qt::Alignment
        define_qflags_under<Qt::AlignmentFlag>(rb_mQt, "Alignment");

    Data_Type<QFlags<Qt::ApplicationState>> rb_cQtApplicationStates =
        // RubyQt6::QtCore::Qt::ApplicationStates
        define_qflags_under<Qt::ApplicationState>(rb_mQt, "ApplicationStates");

    Data_Type<QFlags<Qt::DockWidgetArea>> rb_cQtDockWidgetAreas =
        // RubyQt6::QtCore::Qt::DockWidgetAreas
        define_qflags_under<Qt::DockWidgetArea>(rb_mQt, "DockWidgetAreas");

    Data_Type<QFlags<Qt::DropAction>> rb_cQtDropActions =
        // RubyQt6::QtCore::Qt::DropActions
        define_qflags_under<Qt::DropAction>(rb_mQt, "DropActions");

    Data_Type<QFlags<Qt::Edge>> rb_cQtEdges =
        // RubyQt6::QtCore::Qt::Edges
        define_qflags_under<Qt::Edge>(rb_mQt, "Edges");

    Data_Type<QFlags<Qt::FindChildOption>> rb_cQtFindChildOptions =
        // RubyQt6::QtCore::Qt::FindChildOptions
        define_qflags_under<Qt::FindChildOption>(rb_mQt, "FindChildOptions");

    Data_Type<QFlags<Qt::GestureFlag>> rb_cQtGestureFlags =
        // RubyQt6::QtCore::Qt::GestureFlags
        define_qflags_under<Qt::GestureFlag>(rb_mQt, "GestureFlags");

    Data_Type<QFlags<Qt::ImageConversionFlag>> rb_cQtImageConversionFlags =
        // RubyQt6::QtCore::Qt::ImageConversionFlags
        define_qflags_under<Qt::ImageConversionFlag>(rb_mQt, "ImageConversionFlags");

    Data_Type<QFlags<Qt::InputMethodHint>> rb_cQtInputMethodHints =
        // RubyQt6::QtCore::Qt::InputMethodHints
        define_qflags_under<Qt::InputMethodHint>(rb_mQt, "InputMethodHints");

    Data_Type<QFlags<Qt::InputMethodQuery>> rb_cQtInputMethodQueries =
        // RubyQt6::QtCore::Qt::InputMethodQueries
        define_qflags_under<Qt::InputMethodQuery>(rb_mQt, "InputMethodQueries");

    Data_Type<QFlags<Qt::ItemFlag>> rb_cQtItemFlags =
        // RubyQt6::QtCore::Qt::ItemFlags
        define_qflags_under<Qt::ItemFlag>(rb_mQt, "ItemFlags");

    Data_Type<QFlags<Qt::KeyboardModifier>> rb_cQtKeyboardModifiers =
        // RubyQt6::QtCore::Qt::KeyboardModifiers
        define_qflags_under<Qt::KeyboardModifier>(rb_mQt, "KeyboardModifiers");

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
