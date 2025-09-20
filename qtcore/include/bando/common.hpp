#ifndef BANDO_COMMON_HPP
#define BANDO_COMMON_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QMetaMethod>
#include <QMetaObject>
#include <QObject>

enum bando_FunctionName
{
    actionEvent,
    changeEvent,
    closeEvent,
    contextMenuEvent,
    dragEnterEvent,
    dragLeaveEvent,
    dragMoveEvent,
    dropEvent,
    enterEvent,
    focusInEvent,
    focusOutEvent,
    hideEvent,
    inputMethodEvent,
    keyPressEvent,
    keyReleaseEvent,
    leaveEvent,
    mouseDoubleClickEvent,
    mouseMoveEvent,
    mousePressEvent,
    mouseReleaseEvent,
    moveEvent,
    paintEvent,
    resizeEvent,
    showEvent,
    tabletEvent,
    wheelEvent,
};

constexpr std::string_view bando_FunctionName_underscore(bando_FunctionName name)
{
    switch (name)
    {
    case bando_FunctionName::actionEvent:
        return "action_event";
    case bando_FunctionName::changeEvent:
        return "change_event";
    case bando_FunctionName::closeEvent:
        return "close_event";
    case bando_FunctionName::contextMenuEvent:
        return "context_menu_event";
    case bando_FunctionName::dragEnterEvent:
        return "drag_enter_event";
    case bando_FunctionName::dragLeaveEvent:
        return "drag_leave_event";
    case bando_FunctionName::dragMoveEvent:
        return "drag_move_event";
    case bando_FunctionName::dropEvent:
        return "drop_event";
    case bando_FunctionName::enterEvent:
        return "enter_event";
    case bando_FunctionName::focusInEvent:
        return "focus_in_event";
    case bando_FunctionName::focusOutEvent:
        return "focus_out_event";
    case bando_FunctionName::hideEvent:
        return "hide_event";
    case bando_FunctionName::inputMethodEvent:
        return "input_method_event";
    case bando_FunctionName::keyPressEvent:
        return "key_press_event";
    case bando_FunctionName::keyReleaseEvent:
        return "key_release_event";
    case bando_FunctionName::leaveEvent:
        return "leave_event";
    case bando_FunctionName::mouseDoubleClickEvent:
        return "mouse_double_click_event";
    case bando_FunctionName::mouseMoveEvent:
        return "mouse_move_event";
    case bando_FunctionName::mousePressEvent:
        return "mouse_press_event";
    case bando_FunctionName::mouseReleaseEvent:
        return "mouse_release_event";
    case bando_FunctionName::moveEvent:
        return "move_event";
    case bando_FunctionName::paintEvent:
        return "paint_event";
    case bando_FunctionName::resizeEvent:
        return "resize_event";
    case bando_FunctionName::showEvent:
        return "show_event";
    case bando_FunctionName::tabletEvent:
        return "tablet_event";
    case bando_FunctionName::wheelEvent:
        return "wheel_event";
    default:
        Q_UNREACHABLE();
        break;
    }
}

template <typename BandoClass_T> void bando_initializeValue(BandoClass_T *self, Rice::Object value, QMetaObject *mo)
{
    self->value_ = value;
    self->mo_ = mo;
}

template <typename BandoClass_T, typename Class_T> const QMetaObject *bando_metaObject(const BandoClass_T *self)
{
    if (self->QObject::d_ptr->metaObject != nullptr)
        return self->QObject::d_ptr->dynamicMetaObject();
    if (self->mo_ != nullptr)
        return self->mo_;
    return &Class_T::staticMetaObject;
};

template <typename BandoClass_T> int bando_qt_metacall(BandoClass_T *self, QMetaObject::Call call, int id, void **args)
{
    if (call == QMetaObject::InvokeMetaMethod)
    {
        auto mo = self->metaObject();
        auto method = mo->method(id);
        if (!method.isValid())
        {
            qDebug() << "RubyQt6::Bando: qt_metacall: invalid method";
            return -1;
        }
        if (method.methodType() == QMetaMethod::Signal)
        {
            QMetaObject::activate(self, method.methodIndex(), args);
            return -1;
        }
        if (method.methodType() == QMetaMethod::Slot)
        {
            auto name = method.name().toStdString();
            Q_ASSERT(name.rfind("_rubyqt6_", 0) == 0);

            auto arguments = Rice::Array();
            for (int i = 0; i < method.parameterCount(); ++i)
            {
                QVariant argument(method.parameterMetaType(i), args[i + 1]);
                arguments.push(std::move(argument));
            }

            Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
            self->value_.vcall(name, arguments);
            return -1;
        }
    }

    return -1;
};

template <typename BandoClass_T, typename Event_T> void bando_handleEvent(BandoClass_T *self, Event_T *event, bando_FunctionName name)
{
    auto rb_name = bando_FunctionName_underscore(name);
    if (!self->value_.respond_to(Rice::Identifier(rb_name)))
    {
        self->Class_T_handleEvent(name, event);
        return;
    }

    auto arguments = Rice::Array();
    arguments.push(Rice::String(rb_name));
    arguments.push(Rice::Object(Rice::detail::to_ruby(event)));

    Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
    self->value_.vcall("_rubyqt6_handle_event", arguments);
}

#endif
