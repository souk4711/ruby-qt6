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

#ifndef BANDO_QSORTFILTERPROXYMODEL_HPP
#define BANDO_QSORTFILTERPROXYMODEL_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QTimerEvent>
#include <QSortFilterProxyModel>

RICE4RUBYQT6_USE_NAMESPACE

template <typename Class_T, typename... Arg_Ts> class BandoQSortFilterProxyModel : public Class_T
{
  public:
    BandoQSortFilterProxyModel(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQSortFilterProxyModel(const BandoQSortFilterProxyModel &) = delete;
    BandoQSortFilterProxyModel &operator=(const BandoQSortFilterProxyModel &) = delete;
    BandoQSortFilterProxyModel(BandoQSortFilterProxyModel &&) = delete;
    BandoQSortFilterProxyModel &operator=(BandoQSortFilterProxyModel &&) = delete;
    ~BandoQSortFilterProxyModel() override { bando_finalizer<BandoQSortFilterProxyModel>(this); };

    void initializeValue(Object value, QMetaObject *mo) { bando_initializeValue<BandoQSortFilterProxyModel>(this, value, mo); };
    Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQSortFilterProxyModel, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQSortFilterProxyModel>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQSortFilterProxyModel>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQSortFilterProxyModel>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQSortFilterProxyModel>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQSortFilterProxyModel>(this, event, bando_FunctionName::timerEvent); };
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

  public:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("filter_accepts_column");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(source_column)), Object(detail::to_ruby(source_parent)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("filter_accepts_row");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(source_row)), Object(detail::to_ruby(source_parent)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("less_than");
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(source_left)), Object(detail::to_ruby(source_right)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    bool Class_T_filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const {
        return this->Class_T::filterAcceptsColumn(source_column, source_parent);
    };

    bool Class_T_filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
        return this->Class_T::filterAcceptsRow(source_row, source_parent);
    };

    bool Class_T_lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const {
        return this->Class_T::lessThan(source_left, source_right);
    };
};

template <typename BC_T, typename C_T>
Data_Type<BC_T> define_bando_qsortfilterproxymodel_under(Module module, char const *name)
{
    Data_Type<BC_T> bando_qlass =
        define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_ruby_value", &BC_T::initializeValue, Arg("value"), Arg("mo"))
            .define_method("_ruby_value", &BC_T::value)
            .define_method("_ruby_value_handle_event", &BC_T::Class_T_handleEvent, Arg("name"), Arg("event"))
            .define_method("_event", &BC_T::Class_T_handleQObjectEvent, Arg("event"))
            .define_method("_event_filter", &BC_T::Class_T_handleQObjectEventFilter, Arg("watched"), Arg("event"))
            .define_method("_sender", &BC_T::sender);

    bando_qlass
        .define_method("filter_accepts_column", &BC_T::Class_T_filterAcceptsColumn, Arg("source_column"), Arg("source_parent"))
        .define_method("filter_accepts_row", &BC_T::Class_T_filterAcceptsRow, Arg("source_row"), Arg("source_parent"))
        .define_method("less_than", &BC_T::Class_T_lessThan, Arg("source_left"), Arg("source_right"));

    return bando_qlass;
}

#endif
