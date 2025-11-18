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

#ifndef BANDO_QLAYOUT_HPP
#define BANDO_QLAYOUT_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QLayoutItem>
#include <QTimerEvent>
#include <QWidget>

using namespace Rice;

template <typename Class_T, typename... Arg_Ts> class BandoQLayout : public Class_T
{
  public:
    BandoQLayout(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQLayout(const BandoQLayout &) = delete;
    BandoQLayout &operator=(const BandoQLayout &) = delete;
    BandoQLayout(BandoQLayout &&) = delete;
    BandoQLayout &operator=(BandoQLayout &&) = delete;
    ~BandoQLayout() override { bando_finalizer<BandoQLayout>(this); };

    void initializeValue(Object value, QMetaObject *mo) { bando_initializeValue<BandoQLayout>(this, value, mo); };
    Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQLayout, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQLayout>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQLayout>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQLayout>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQLayout>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQLayout>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

    void addItem(QLayoutItem *item) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("add_item");
        this->value_.call(rb_name, Object(detail::to_ruby(item)));
    };

    int count() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("count");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<int>().convert(rb_return);
    };

    QLayoutItem *itemAt(int index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("item_at");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(index)));
        return detail::From_Ruby<QLayoutItem *>().convert(rb_return);
    };

    QLayoutItem *takeAt(int index) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("take_at");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(index)));
        return detail::From_Ruby<QLayoutItem *>().convert(rb_return);
    };

    QSize sizeHint() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("size_hint");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<QSize>().convert(rb_return);
    };

    Qt::Orientations expandingDirections() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("expanding_directions");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<Qt::Orientations>().convert(rb_return);
    };

    bool hasHeightForWidth() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("has_height_for_width");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    int heightForWidth(int width) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("height_for_width");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(width)));
        return detail::From_Ruby<int>().convert(rb_return);
    };

    QSize maximumSize() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("maximum_size");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<QSize>().convert(rb_return);
    };

    QSize minimumSize() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("minimum_size");
        auto rb_return = this->value_.call(rb_name);
        return detail::From_Ruby<QSize>().convert(rb_return);
    };

    void setGeometry(const QRect &r) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("set_geometry");
        this->value_.call(rb_name, Object(detail::to_ruby(r)));
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
Data_Type<BC_T> define_bando_qlayout_under(Module module, char const *name)
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
        .define_method("expanding_directions", [](BC_T *self) -> Qt::Orientations { return self->C_T::expandingDirections(); })
        .define_method("has_height_for_width", [](BC_T *self) -> bool { return self->C_T::hasHeightForWidth(); })
        .define_method("height_for_width", [](BC_T *self, int width) -> int { return self->C_T::heightForWidth(width); }, Arg("width"))
        .define_method("maximum_size", [](BC_T *self) -> QSize { return self->C_T::maximumSize(); })
        .define_method("minimum_size", [](BC_T *self) -> QSize { return self->C_T::minimumSize(); })
        .define_method("set_geometry", [](BC_T *self, const QRect &r) -> void { return self->C_T::setGeometry(r); }, Arg("r"));

    return bando_qlass;
}

#endif
