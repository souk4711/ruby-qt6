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

#ifndef BANDO_QLAYOUT_HPP
#define BANDO_QLAYOUT_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QLayoutItem>
#include <QTimerEvent>
#include <QWidget>

template <typename Class_T, typename... Arg_Ts> class BandoQLayout : public Class_T
{
  public:
    BandoQLayout(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQLayout(const BandoQLayout &) = delete;
    BandoQLayout &operator=(const BandoQLayout &) = delete;
    BandoQLayout(BandoQLayout &&) = delete;
    BandoQLayout &operator=(BandoQLayout &&) = delete;
    ~BandoQLayout() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQLayout>(this, value, mo); };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQLayout, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQLayout>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQLayout>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQLayout>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQLayout, QChildEvent>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQLayout, QTimerEvent>(this, event, bando_FunctionName::timerEvent); };

    void addItem(QLayoutItem *item) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("add_item");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(item)));
    };

    int count() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("count");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<int>().convert(rb_return);
    };

    QLayoutItem *itemAt(int index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("item_at");
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(index)));
        return Rice::detail::From_Ruby<QLayoutItem *>().convert(rb_return);
    };

    QLayoutItem *takeAt(int index) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("take_at");
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(index)));
        return Rice::detail::From_Ruby<QLayoutItem *>().convert(rb_return);
    };

    QSize sizeHint() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("size_hint");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    };

    Qt::Orientations expandingDirections() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("expanding_directions");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<Qt::Orientations>().convert(rb_return);
    };

    bool hasHeightForWidth() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("has_height_for_width");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<bool>().convert(rb_return);
    };

    int heightForWidth(int width) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("height_for_width");
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(width)));
        return Rice::detail::From_Ruby<int>().convert(rb_return);
    };

    QSize maximumSize() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("maximum_size");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    };

    QSize minimumSize() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("minimum_size");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    };

    void setGeometry(const QRect &r) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("set_geometry");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(r)));
    }

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

    Rice::Object value_;
    QMetaObject *mo_;
};

template <typename BC_T, typename C_T>
Rice::Data_Type<BC_T> define_bando_qlayout_under(Rice::Module module, char const *name)
{
    Rice::Data_Type<BC_T> bando_qlass =
        Rice::define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_value", &BC_T::initializeValue, Rice::Arg("value"), Rice::Arg("mo"))
            .define_method("_event", [](BC_T *self, QEvent *event) -> bool { return self->Class_T_handleQObjectEvent(event); })
            .define_method("_event_filter", [](BC_T *self, QObject *watched, QEvent *event) -> bool { return self->Class_T_handleQObjectEventFilter(watched, event); })
            .define_method("_child_event", [](BC_T *self, QChildEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::childEvent, event); })
            .define_method("_timer_event", [](BC_T *self, QTimerEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::timerEvent, event); });

    bando_qlass
        .define_method("_expanding_directions", [](BC_T *self) -> Qt::Orientations { return self->C_T::expandingDirections(); })
        .define_method("_has_height_for_width", [](BC_T *self) -> bool { return self->C_T::hasHeightForWidth(); })
        .define_method("_height_for_width", [](BC_T *self, int width) -> int { return self->C_T::heightForWidth(width); })
        .define_method("_maximum_size", [](BC_T *self) -> QSize { return self->C_T::maximumSize(); })
        .define_method("_minimum_size", [](BC_T *self) -> QSize { return self->C_T::minimumSize(); })
        .define_method("_set_geometry", [](BC_T *self, const QRect &r) -> void { return self->C_T::setGeometry(r); })
        .define_method("expanding_directions", [](BC_T *self) -> Qt::Orientations { return self->C_T::expandingDirections(); })
        .define_method("has_height_for_width", [](BC_T *self) -> bool { return self->C_T::hasHeightForWidth(); })
        .define_method("height_for_width", [](BC_T *self, int width) -> int { return self->C_T::heightForWidth(width); })
        .define_method("maximum_size", [](BC_T *self) -> QSize { return self->C_T::maximumSize(); })
        .define_method("minimum_size", [](BC_T *self) -> QSize { return self->C_T::minimumSize(); })
        .define_method("set_geometry", [](BC_T *self, const QRect &r) -> void { return self->C_T::setGeometry(r); });

    return bando_qlass;
}

#endif
