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

#ifndef BANDO_QOBJECT_HPP
#define BANDO_QOBJECT_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QTimerEvent>

RICE4RUBYQT6_USE_NAMESPACE

template <typename Class_T, typename... Arg_Ts> class BandoQObject : public Class_T
{
  public:
    BandoQObject(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQObject(const BandoQObject &) = delete;
    BandoQObject &operator=(const BandoQObject &) = delete;
    BandoQObject(BandoQObject &&) = delete;
    BandoQObject &operator=(BandoQObject &&) = delete;
    ~BandoQObject() override { bando_finalizer<BandoQObject>(this); };

    void initializeValue(Object value, QMetaObject *mo) { bando_initializeValue<BandoQObject>(this, value, mo); };
    Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQObject, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQObject>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQObject>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQObject>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQObject>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQObject>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

  public:
    bool Class_T_handleQObjectEvent(QEvent *event) { return this->Class_T::event(event); };
    bool Class_T_handleQObjectEventFilter(QObject *watched, QEvent *event) { return this->Class_T::eventFilter(watched, event); };

    void Class_T_handleEvent(bando_FunctionName name, QEvent *event) {
        switch (name)
        {
        case bando_FunctionName::childEvent: return this->Class_T::childEvent(static_cast<QChildEvent *>(event));
        case bando_FunctionName::timerEvent: return this->Class_T::timerEvent(static_cast<QTimerEvent *>(event));
        default: Q_UNREACHABLE(); break;
        }
    };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);

    Object value_;
    VALUE *value_address_;

    QMetaObject *mo_;
};

template <typename BC_T>
VALUE bando_qobject_initialize_ruby_value(VALUE self, VALUE value, VALUE mo)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    bando_qobject->initializeValue(Object(value), detail::From_Ruby<QMetaObject *>().convert(mo));
    return Qnil;
}

template <typename BC_T>
VALUE bando_qobject_ruby_value(VALUE self)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    auto rb_return = bando_qobject->value();
    return rb_return;
}

template <typename BC_T>
VALUE bando_qobject_ruby_value_handle_event(VALUE self, VALUE name, VALUE event)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    bando_qobject->Class_T_handleEvent(detail::From_Ruby<bando_FunctionName>().convert(name), detail::From_Ruby<QEvent *>().convert(event));
    return Qnil;
}

template <typename BC_T>
VALUE bando_qobject_event(VALUE self, VALUE event)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    auto rb_return = bando_qobject->Class_T_handleQObjectEvent(detail::From_Ruby<QEvent *>().convert(event));
    return detail::To_Ruby<bool>().convert(rb_return);
}

template <typename BC_T>
VALUE bando_qobject_event_filter(VALUE self, VALUE watched, VALUE event)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    auto rb_return = bando_qobject->Class_T_handleQObjectEventFilter(detail::From_Ruby<QObject *>().convert(watched), detail::From_Ruby<QEvent *>().convert(event));
    return detail::To_Ruby<bool>().convert(rb_return);
}

template <typename BC_T>
VALUE bando_qobject_sender(VALUE self)
{
    auto bando_qobject = detail::From_Ruby<BC_T *>().convert(self);
    auto rb_return = bando_qobject->sender();
    return detail::To_Ruby<QObject *>().convert(rb_return);
}

template <typename BC_T, typename C_T>
Data_Type<BC_T> define_bando_qobject_under(Module module, char const *name)
{
    Data_Type<BC_T> bando_qlass = define_class_under<BC_T, C_T>(module, name);
    detail::protect(rb_define_method, bando_qlass, "_initialize_ruby_value", (RUBY_METHOD_FUNC)bando_qobject_initialize_ruby_value<BC_T>, 2);
    detail::protect(rb_define_method, bando_qlass, "_ruby_value", (RUBY_METHOD_FUNC)bando_qobject_ruby_value<BC_T>, 0);
    detail::protect(rb_define_method, bando_qlass, "_ruby_value_handle_event", (RUBY_METHOD_FUNC)bando_qobject_ruby_value_handle_event<BC_T>, 2);
    detail::protect(rb_define_method, bando_qlass, "_event", (RUBY_METHOD_FUNC)bando_qobject_event<BC_T>, 1);
    detail::protect(rb_define_method, bando_qlass, "_event_filter", (RUBY_METHOD_FUNC)bando_qobject_event_filter<BC_T>, 2);
    detail::protect(rb_define_method, bando_qlass, "_sender", (RUBY_METHOD_FUNC)bando_qobject_sender<BC_T>, 0);
    return bando_qlass;
}

#endif
