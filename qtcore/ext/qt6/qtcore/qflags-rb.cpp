#include "qflags-rb.hpp"
#include <qflags.h>
#include <qnamespace.h>

using namespace Rice;

template<typename Enum_T>
Data_Type<QFlags<Enum_T>> QFlags_define_flags_under(Module module, char const* name)
{
    using QFlags_T = QFlags<Enum_T>;
    Data_Type<QFlags_T> flags = define_class_under<QFlags_T>(module, name)
        // Constructor
        .define_constructor(Constructor<QFlags_T>())
        .define_constructor(Constructor<QFlags_T, Enum_T>(), Arg("flags"))
        // Public Functions
        .template define_method("set_flag", &QFlags_T::setFlag, Arg("flag"), Arg("on") = static_cast<bool>(true))
        .template define_method("test_any_flag", &QFlags_T::testAnyFlag, Arg("flag"))
        .template define_method("test_any_flags", &QFlags_T::testAnyFlags, Arg("flags"))
        .template define_method("test_flag", &QFlags_T::testFlag, Arg("flag"))
        .template define_method("test_flags", &QFlags_T::testFlags, Arg("flags"))
        .template define_method("to_int", &QFlags_T::toInt)
        .template define_method("to_i", &QFlags_T::toInt)
        .template define_method("!", &QFlags_T::operator!)
        .template define_method<QFlags_T (QFlags_T::*)(int) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(int) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("^", &QFlags_T::operator^, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("^", &QFlags_T::operator^, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("^=", &QFlags_T::operator^=, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("^=", &QFlags_T::operator^=, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("|", &QFlags_T::operator|, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("|", &QFlags_T::operator|, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("|=", &QFlags_T::operator|=, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("|=", &QFlags_T::operator|=, Arg("other"))
        .template define_method("~", &QFlags_T::operator~)
        // Static Public Members
        .template define_singleton_function("from_int", [](int i) -> QFlags_T { return QFlags_T::fromInt(i); }, Arg("i"));
    return flags;
}

void Init_qflags(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

     auto rb_cQtAlignment =
        // RubyQt6::QtCore::Qt::Alignment
        QFlags_define_flags_under<Qt::AlignmentFlag>(rb_mQt, "Alignment");

     auto rb_cQtApplicationStates =
        // RubyQt6::QtCore::Qt::ApplicationStates
        QFlags_define_flags_under<Qt::ApplicationState>(rb_mQt, "ApplicationStates");

     auto rb_cQtDockWidgetAreas =
        // RubyQt6::QtCore::Qt::DockWidgetAreas
        QFlags_define_flags_under<Qt::DockWidgetArea>(rb_mQt, "DockWidgetAreas");

     auto rb_cQtDropActions =
        // RubyQt6::QtCore::Qt::DropActions
        QFlags_define_flags_under<Qt::DropAction>(rb_mQt, "DropActions");

     auto rb_cQtEdges =
        // RubyQt6::QtCore::Qt::Edges
        QFlags_define_flags_under<Qt::Edge>(rb_mQt, "Edges");

     auto rb_cQtFindChildOptions =
        // RubyQt6::QtCore::Qt::FindChildOptions
        QFlags_define_flags_under<Qt::FindChildOption>(rb_mQt, "FindChildOptions");

     auto rb_cQtGestureFlags =
        // RubyQt6::QtCore::Qt::GestureFlags
        QFlags_define_flags_under<Qt::GestureFlag>(rb_mQt, "GestureFlags");

     auto rb_cQtImageConversionFlags =
        // RubyQt6::QtCore::Qt::ImageConversionFlags
        QFlags_define_flags_under<Qt::ImageConversionFlag>(rb_mQt, "ImageConversionFlags");

     auto rb_cQtInputMethodHints =
        // RubyQt6::QtCore::Qt::InputMethodHints
        QFlags_define_flags_under<Qt::InputMethodHint>(rb_mQt, "InputMethodHints");

     auto rb_cQtInputMethodQueries =
        // RubyQt6::QtCore::Qt::InputMethodQueries
        QFlags_define_flags_under<Qt::InputMethodQuery>(rb_mQt, "InputMethodQueries");

     auto rb_cQtItemFlags =
        // RubyQt6::QtCore::Qt::ItemFlags
        QFlags_define_flags_under<Qt::ItemFlag>(rb_mQt, "ItemFlags");

     auto rb_cQtKeyboardModifiers =
        // RubyQt6::QtCore::Qt::KeyboardModifiers
        QFlags_define_flags_under<Qt::KeyboardModifier>(rb_mQt, "KeyboardModifiers");

     auto rb_cQtMatchFlags =
        // RubyQt6::QtCore::Qt::MatchFlags
        QFlags_define_flags_under<Qt::MatchFlag>(rb_mQt, "MatchFlags");

     auto rb_cQtModifiers =
        // RubyQt6::QtCore::Qt::Modifiers
        QFlags_define_flags_under<Qt::Modifier>(rb_mQt, "Modifiers");

     auto rb_cQtMouseButtons =
        // RubyQt6::QtCore::Qt::MouseButtons
        QFlags_define_flags_under<Qt::MouseButton>(rb_mQt, "MouseButtons");

     auto rb_cQtMouseEventFlags =
        // RubyQt6::QtCore::Qt::MouseEventFlags
        QFlags_define_flags_under<Qt::MouseEventFlag>(rb_mQt, "MouseEventFlags");

     auto rb_cQtOrientations =
        // RubyQt6::QtCore::Qt::Orientations
        QFlags_define_flags_under<Qt::Orientation>(rb_mQt, "Orientations");

     auto rb_cQtScreenOrientations =
        // RubyQt6::QtCore::Qt::ScreenOrientations
        QFlags_define_flags_under<Qt::ScreenOrientation>(rb_mQt, "ScreenOrientations");

     auto rb_cQtSplitBehavior =
        // RubyQt6::QtCore::Qt::SplitBehavior
        QFlags_define_flags_under<Qt::SplitBehaviorFlags>(rb_mQt, "SplitBehavior");

     auto rb_cQtTextInteractionFlags =
        // RubyQt6::QtCore::Qt::TextInteractionFlags
        QFlags_define_flags_under<Qt::TextInteractionFlag>(rb_mQt, "TextInteractionFlags");

     auto rb_cQtToolBarAreas =
        // RubyQt6::QtCore::Qt::ToolBarAreas
        QFlags_define_flags_under<Qt::ToolBarArea>(rb_mQt, "ToolBarAreas");

     auto rb_cQtTouchPointStates =
        // RubyQt6::QtCore::Qt::TouchPointStates
        QFlags_define_flags_under<Qt::TouchPointState>(rb_mQt, "TouchPointStates");

     auto rb_cQtWindowStates =
        // RubyQt6::QtCore::Qt::WindowStates
        QFlags_define_flags_under<Qt::WindowState>(rb_mQt, "WindowStates");

     auto rb_cQtWindowFlags =
        // RubyQt6::QtCore::Qt::WindowFlags
        QFlags_define_flags_under<Qt::WindowType>(rb_mQt, "WindowFlags");
}
