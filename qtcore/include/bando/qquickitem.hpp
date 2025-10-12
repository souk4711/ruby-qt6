// This file is part of [Ruby-Qt6](https://github.com/souk4711/ruby-qt6).
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

#ifndef BANDO_QQUICKITEM_HPP
#define BANDO_QQUICKITEM_HPP

#include <bando/common.hpp>

template <typename Class_T, typename... Arg_Ts> class BandoQQuickItem : public Class_T
{
  public:
    BandoQQuickItem(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQQuickItem(const BandoQQuickItem &) = delete;
    BandoQQuickItem &operator=(const BandoQQuickItem &) = delete;
    BandoQQuickItem(BandoQQuickItem &&) = delete;
    BandoQQuickItem &operator=(BandoQQuickItem &&) = delete;
    ~BandoQQuickItem() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQQuickItem>(this, value, mo); };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQQuickItem, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQQuickItem>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQQuickItem>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQQuickItem>(this, watched, event); };

  public:
    bool Class_T_handleQObjectEvent(QEvent *event) { return this->Class_T::event(event); };
    bool Class_T_handleQObjectEventFilter(QObject *watched, QEvent *event) { return this->Class_T::eventFilter(watched, event); };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

template <typename BC_T, typename C_T>
Rice::Data_Type<BC_T> define_bando_qquickitem_under(Rice::Module module, char const *name)
{
    Rice::Data_Type<BC_T> bando_qlass =
        Rice::define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_value", &BC_T::initializeValue, Rice::Arg("mo"), Rice::Arg("value"))
            .define_method("_event", [](BC_T *self, QEvent *event) -> bool { return self->Class_T_handleQObjectEvent(event); })
            .define_method("_event_filter", [](BC_T *self, QObject *watched, QEvent *event) -> bool { return self->Class_T_handleQObjectEventFilter(watched, event); });
    return bando_qlass;
}

#endif
