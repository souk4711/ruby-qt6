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

#ifndef BANDO_QITEMDELEGATE_HPP
#define BANDO_QITEMDELEGATE_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QTimerEvent>

template <typename Class_T, typename... Arg_Ts> class BandoQItemDelegate : public Class_T
{
  public:
    BandoQItemDelegate(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQItemDelegate(const BandoQItemDelegate &) = delete;
    BandoQItemDelegate &operator=(const BandoQItemDelegate &) = delete;
    BandoQItemDelegate(BandoQItemDelegate &&) = delete;
    BandoQItemDelegate &operator=(BandoQItemDelegate &&) = delete;
    ~BandoQItemDelegate() override { bando_finalizer<BandoQItemDelegate>(this); };

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQItemDelegate>(this, value, mo); };
    Rice::Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQItemDelegate, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQItemDelegate>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQItemDelegate>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQItemDelegate>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQItemDelegate, QChildEvent>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQItemDelegate, QTimerEvent>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("create_editor");
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(parent)), Rice::Object(Rice::detail::to_ruby(option)), Rice::Object(Rice::detail::to_ruby(index)));
        return Rice::detail::From_Ruby<QWidget *>().convert(rb_return);
    };

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("paint");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(painter)), Rice::Object(Rice::detail::to_ruby(option)), Rice::Object(Rice::detail::to_ruby(index)));
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("set_editor_data");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(editor)), Rice::Object(Rice::detail::to_ruby(index)));
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("set_model_data");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(editor)), Rice::Object(Rice::detail::to_ruby(model)), Rice::Object(Rice::detail::to_ruby(index)));
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("size_hint");
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(option)), Rice::Object(Rice::detail::to_ruby(index)));
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("update_editor_geometry");
        this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(editor)), Rice::Object(Rice::detail::to_ruby(option)), Rice::Object(Rice::detail::to_ruby(index)));
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
    VALUE *value_address_;

    QMetaObject *mo_;
};

template <typename BC_T, typename C_T>
Rice::Data_Type<BC_T> define_bando_qitemdelegate_under(Rice::Module module, char const *name)
{
    Rice::Data_Type<BC_T> bando_qlass =
        Rice::define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_ruby_value", &BC_T::initializeValue, Rice::Arg("value"), Rice::Arg("mo"))
            .define_method("_ruby_value", &BC_T::value)
            .define_method("_event", [](BC_T *self, QEvent *event) -> bool { return self->Class_T_handleQObjectEvent(event); })
            .define_method("_event_filter", [](BC_T *self, QObject *watched, QEvent *event) -> bool { return self->Class_T_handleQObjectEventFilter(watched, event); })
            .define_method("_child_event", [](BC_T *self, QChildEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::childEvent, event); })
            .define_method("_timer_event", [](BC_T *self, QTimerEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::timerEvent, event); })
            .define_method("sender", &BC_T::sender);

    bando_qlass
        .define_method("_create_editor", [](BC_T *self, QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) -> QWidget * { return self->C_T::createEditor(parent, option, index); })
        .define_method("_paint", [](BC_T *self, QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) -> void { return self->C_T::paint(painter, option, index); })
        .define_method("_set_editor_data", [](BC_T *self, QWidget *editor, const QModelIndex &index) -> void { return self->C_T::setEditorData(editor, index); })
        .define_method("_set_model_data", [](BC_T *self, QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) -> void { return self->C_T::setModelData(editor, model, index); })
        .define_method("_size_hint", [](BC_T *self, const QStyleOptionViewItem &option, const QModelIndex &index) -> QSize { return self->C_T::sizeHint(option, index); })
        .define_method("_update_editor_geometry", [](BC_T *self, QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) -> void { return self->C_T::updateEditorGeometry(editor, option, index); })
        .define_method("create_editor", [](BC_T *self, QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) -> QWidget * { return self->C_T::createEditor(parent, option, index); })
        .define_method("paint", [](BC_T *self, QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) -> void { return self->C_T::paint(painter, option, index); })
        .define_method("set_editor_data", [](BC_T *self, QWidget *editor, const QModelIndex &index) -> void { return self->C_T::setEditorData(editor, index); })
        .define_method("set_model_data", [](BC_T *self, QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) -> void { return self->C_T::setModelData(editor, model, index); })
        .define_method("size_hint", [](BC_T *self, const QStyleOptionViewItem &option, const QModelIndex &index) -> QSize { return self->C_T::sizeHint(option, index); })
        .define_method("update_editor_geometry", [](BC_T *self, QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) -> void { return self->C_T::updateEditorGeometry(editor, option, index); });

    return bando_qlass;
}

#endif
