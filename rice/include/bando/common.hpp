// This file is part of [RubyQt6](https://github.com/souk4711/ruby-qt6).
//
// It is licensed under the LGPLv3, included below.
//
// As a special exception to the GNU Lesser General Public License version 3
// ("LGPL3"), the copyright holders of this Library give you permission to
// convey to a third party a Combined Work that links statically or dynamically
// to this Library without providing any Minimal Corresponding Source or
// Minimal Application Code as set out in 4d or providing the installation
// information set out in section 4e, provided that you comply with the other
// provisions of LGPL3 and provided that you meet, for the Application the
// terms and conditions of the license(s) which apply to the Application.
//
// Except as stated in this special exception, the provisions of LGPL3 will
// continue to comply in full to this Library. If you modify this Library, you
// may apply this exception to your version of this Library, but you are not
// obliged to do so. If you do not wish to do so, delete this exception
// statement from your version. This exception does not (and cannot) modify any
// license terms which apply to the Application, with which you must still
// comply.

#ifndef BANDO_COMMON_HPP
#define BANDO_COMMON_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QEvent>
#include <QMetaMethod>
#include <QMetaObject>
#include <QObject>

using namespace Rice;

enum bando_FunctionName
{
    actionEvent,
    changeEvent,
    childEvent,
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
    timerEvent,
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
    case bando_FunctionName::childEvent:
        return "child_event";
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
    case bando_FunctionName::timerEvent:
        return "timer_event";
    case bando_FunctionName::wheelEvent:
        return "wheel_event";
    default:
        Q_UNREACHABLE();
        break;
    }
}

template <typename BandoClass_T> void bando_initializeValue(BandoClass_T *self, Object value, QMetaObject *mo)
{
    self->value_ = value;
    self->mo_ = mo;

    self->value_address_ = const_cast<VALUE*>(&self->value_.value());
    detail::protect(rb_gc_register_address, self->value_address_);
}

template <typename BandoClass_T> void bando_finalizer(BandoClass_T *self)
{
    if (self->value_address_ != nullptr)
        detail::protect(rb_gc_unregister_address, self->value_address_);
}

template <typename BandoClass_T, typename Class_T> const QMetaObject *bando_metaObject(const BandoClass_T *self)
{
    if (self->QObject::d_ptr->metaObject != nullptr)
        return self->QObject::d_ptr->dynamicMetaObject();
    if (self->mo_ != nullptr)
        return self->mo_;
    return &Class_T::staticMetaObject;
}

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
            auto name = "_rubyqt6_slot_" + method.name().toStdString();
            auto arguments = Array();
            for (int i = 0; i < method.parameterCount(); ++i)
            {
                QVariant argument(method.parameterMetaType(i), args[i + 1]);
                arguments.push(std::move(argument), false);
            }

            Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
            auto rb_return = self->value_.vcall(name, arguments);

            if (method.returnType() != QMetaType::Void) {
                if (!rb_return.is_nil()) {
                    const QVariant result = detail::From_Ruby<QVariant>().convert(rb_return);
                    method.returnMetaType().construct(args[0], result.constData());
                }
            }

            return -1;
        }
    }

    return -1;
}

template <typename BandoClass_T> bool bando_handleQObjectEvent(BandoClass_T *self, QEvent *event)
{
    auto rb_name = Identifier("event");
    if (!self->value_.respond_to(rb_name))
        return self->Class_T_handleQObjectEvent(event);

    Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
    auto rb_return = self->value_.call(rb_name, Object(detail::to_ruby(event)));
    return detail::From_Ruby<bool>().convert(rb_return);
}

template <typename BandoClass_T> bool bando_handleQObjectEventFilter(BandoClass_T *self, QObject *watched, QEvent *event)
{
    auto rb_name = Identifier("event_filter");
    if (!self->value_.respond_to(rb_name))
        return self->Class_T_handleQObjectEventFilter(watched, event);

    Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
    auto rb_return = self->value_.call(rb_name, Object(detail::to_ruby(watched)), Object(detail::to_ruby(event)));
    return detail::From_Ruby<bool>().convert(rb_return);
}

template <typename BandoClass_T> void bando_handleEvent(BandoClass_T *self, QEvent *event, bando_FunctionName name)
{
    auto rb_name = Identifier(bando_FunctionName_underscore(name));
    if (!self->value_.respond_to(rb_name))
        return self->Class_T_handleEvent(name, event);

    Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
    self->value_.call(rb_name, Object(detail::to_ruby(event)));
}

#endif
