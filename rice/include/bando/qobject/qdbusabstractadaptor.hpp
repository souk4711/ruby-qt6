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

#ifndef BANDO_QDBUSABSTRACTADAPTOR_HPP
#define BANDO_QDBUSABSTRACTADAPTOR_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QTimerEvent>

RICE4RUBYQT6_USE_NAMESPACE

template <typename Class_T, typename... Arg_Ts> class BandoQDBusAbstractAdaptor : public Class_T
{
  public:
    BandoQDBusAbstractAdaptor(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQDBusAbstractAdaptor(const BandoQDBusAbstractAdaptor &) = delete;
    BandoQDBusAbstractAdaptor &operator=(const BandoQDBusAbstractAdaptor &) = delete;
    BandoQDBusAbstractAdaptor(BandoQDBusAbstractAdaptor &&) = delete;
    BandoQDBusAbstractAdaptor &operator=(BandoQDBusAbstractAdaptor &&) = delete;
    ~BandoQDBusAbstractAdaptor() override { bando_finalizer<BandoQDBusAbstractAdaptor>(this); };

    void initializeValue(Object value, QMetaObject *mo) { bando_initializeValue<BandoQDBusAbstractAdaptor>(this, value, mo); };
    Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQDBusAbstractAdaptor, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQDBusAbstractAdaptor>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQDBusAbstractAdaptor>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQDBusAbstractAdaptor>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQDBusAbstractAdaptor>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQDBusAbstractAdaptor>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

    bool autoRelaySignals() const {
        return this->Class_T::autoRelaySignals();
    };

    void setAutoRelaySignals(bool enable) {
        this->Class_T::setAutoRelaySignals(enable);
    };

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

template <typename BC_T, typename C_T>
Data_Type<BC_T> define_bando_qdbusabstractadaptor_under(Module module, char const *name)
{
    Data_Type<BC_T> bando_qlass =
        define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_ruby_value", &BC_T::initializeValue, Arg("value"), Arg("mo"))
            .define_method("_ruby_value", &BC_T::value)
            .define_method("_ruby_value_handle_event", &BC_T::Class_T_handleEvent, Arg("name"), Arg("event"))
            .define_method("_event", &BC_T::Class_T_handleQObjectEvent, Arg("event"))
            .define_method("_event_filter", &BC_T::Class_T_handleQObjectEventFilter, Arg("watched"), Arg("event"))
            .define_method("sender", &BC_T::sender);

    bando_qlass
        .define_method("auto_relay_signals", &BC_T::autoRelaySignals)
        .define_method("set_auto_relay_signals", &BC_T::setAutoRelaySignals, Arg("enable"));

    return bando_qlass;
}

#endif
