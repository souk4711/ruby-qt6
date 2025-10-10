#include "qt-flags-al-rb.hpp"
#include <qnamespace.h>

#include <rice/qflags.hpp>

using namespace Rice;

void Init_qt_flags_al(Rice::Module rb_mQt6QtCore)
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
}
