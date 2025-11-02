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

#ifndef BANDO_QSPINBOX_HPP
#define BANDO_QSPINBOX_HPP

#include <bando/common.hpp>
#include <QActionEvent>
#include <QEvent>
#include <QChildEvent>
#include <QCloseEvent>
#include <QContextMenuEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEnterEvent>
#include <QFocusEvent>
#include <QFocusEvent>
#include <QHideEvent>
#include <QInputMethodEvent>
#include <QKeyEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QShowEvent>
#include <QTabletEvent>
#include <QTimerEvent>
#include <QWheelEvent>

template <typename Class_T, typename... Arg_Ts> class BandoQSpinBox : public Class_T
{
  public:
    BandoQSpinBox(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQSpinBox(const BandoQSpinBox &) = delete;
    BandoQSpinBox &operator=(const BandoQSpinBox &) = delete;
    BandoQSpinBox(BandoQSpinBox &&) = delete;
    BandoQSpinBox &operator=(BandoQSpinBox &&) = delete;
    ~BandoQSpinBox() override { bando_finalizer<BandoQSpinBox>(this); };

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQSpinBox>(this, value, mo); };
    Rice::Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQSpinBox, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQSpinBox>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQSpinBox>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQSpinBox>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQSpinBox, QChildEvent>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQSpinBox, QTimerEvent>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

    void actionEvent(QActionEvent *event) override { bando_handleEvent<BandoQSpinBox, QActionEvent>(this, event, bando_FunctionName::actionEvent); };
    void changeEvent(QEvent *event) override { bando_handleEvent<BandoQSpinBox, QEvent>(this, event, bando_FunctionName::changeEvent); };
    void closeEvent(QCloseEvent *event) override { bando_handleEvent<BandoQSpinBox, QCloseEvent>(this, event, bando_FunctionName::closeEvent); };
    void contextMenuEvent(QContextMenuEvent *event) override { bando_handleEvent<BandoQSpinBox, QContextMenuEvent>(this, event, bando_FunctionName::contextMenuEvent); };
    void dragEnterEvent(QDragEnterEvent *event) override { bando_handleEvent<BandoQSpinBox, QDragEnterEvent>(this, event, bando_FunctionName::dragEnterEvent); };
    void dragLeaveEvent(QDragLeaveEvent *event) override { bando_handleEvent<BandoQSpinBox, QDragLeaveEvent>(this, event, bando_FunctionName::dragLeaveEvent); };
    void dragMoveEvent(QDragMoveEvent *event) override { bando_handleEvent<BandoQSpinBox, QDragMoveEvent>(this, event, bando_FunctionName::dragMoveEvent); };
    void dropEvent(QDropEvent *event) override { bando_handleEvent<BandoQSpinBox, QDropEvent>(this, event, bando_FunctionName::dropEvent); };
    void enterEvent(QEnterEvent *event) override { bando_handleEvent<BandoQSpinBox, QEnterEvent>(this, event, bando_FunctionName::enterEvent); };
    void focusInEvent(QFocusEvent *event) override { bando_handleEvent<BandoQSpinBox, QFocusEvent>(this, event, bando_FunctionName::focusInEvent); };
    void focusOutEvent(QFocusEvent *event) override { bando_handleEvent<BandoQSpinBox, QFocusEvent>(this, event, bando_FunctionName::focusOutEvent); };
    void hideEvent(QHideEvent *event) override { bando_handleEvent<BandoQSpinBox, QHideEvent>(this, event, bando_FunctionName::hideEvent); };
    void inputMethodEvent(QInputMethodEvent *event) override { bando_handleEvent<BandoQSpinBox, QInputMethodEvent>(this, event, bando_FunctionName::inputMethodEvent); };
    void keyPressEvent(QKeyEvent *event) override { bando_handleEvent<BandoQSpinBox, QKeyEvent>(this, event, bando_FunctionName::keyPressEvent); };
    void keyReleaseEvent(QKeyEvent *event) override { bando_handleEvent<BandoQSpinBox, QKeyEvent>(this, event, bando_FunctionName::keyReleaseEvent); };
    void leaveEvent(QEvent *event) override { bando_handleEvent<BandoQSpinBox, QEvent>(this, event, bando_FunctionName::leaveEvent); };
    void mouseDoubleClickEvent(QMouseEvent *event) override { bando_handleEvent<BandoQSpinBox, QMouseEvent>(this, event, bando_FunctionName::mouseDoubleClickEvent); };
    void mouseMoveEvent(QMouseEvent *event) override { bando_handleEvent<BandoQSpinBox, QMouseEvent>(this, event, bando_FunctionName::mouseMoveEvent); };
    void mousePressEvent(QMouseEvent *event) override { bando_handleEvent<BandoQSpinBox, QMouseEvent>(this, event, bando_FunctionName::mousePressEvent); };
    void mouseReleaseEvent(QMouseEvent *event) override { bando_handleEvent<BandoQSpinBox, QMouseEvent>(this, event, bando_FunctionName::mouseReleaseEvent); };
    void moveEvent(QMoveEvent *event) override { bando_handleEvent<BandoQSpinBox, QMoveEvent>(this, event, bando_FunctionName::moveEvent); };
    void paintEvent(QPaintEvent *event) override { bando_handleEvent<BandoQSpinBox, QPaintEvent>(this, event, bando_FunctionName::paintEvent); };
    void resizeEvent(QResizeEvent *event) override { bando_handleEvent<BandoQSpinBox, QResizeEvent>(this, event, bando_FunctionName::resizeEvent); };
    void showEvent(QShowEvent *event) override { bando_handleEvent<BandoQSpinBox, QShowEvent>(this, event, bando_FunctionName::showEvent); };
    void tabletEvent(QTabletEvent *event) override { bando_handleEvent<BandoQSpinBox, QTabletEvent>(this, event, bando_FunctionName::tabletEvent); };
    void wheelEvent(QWheelEvent *event) override { bando_handleEvent<BandoQSpinBox, QWheelEvent>(this, event, bando_FunctionName::wheelEvent); };

    QSize minimumSizeHint() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("minimum_size_hint");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    };

    QSize sizeHint() const override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Rice::Identifier("size_hint");
        auto rb_return = this->value_.call(rb_name);
        return Rice::detail::From_Ruby<QSize>().convert(rb_return);
    };

    QString textFromValue(int value) const override {
        auto rb_name = Rice::Identifier("text_from_value");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::textFromValue(value);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(value)));
        return Rice::detail::From_Ruby<QString>().convert(rb_return);
    }

    int valueFromText(const QString &text) const override {
        auto rb_name = Rice::Identifier("value_from_text");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::valueFromText(text);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Rice::Object(Rice::detail::to_ruby(text)));
        return Rice::detail::From_Ruby<int>().convert(rb_return);
    }

  public:
    bool Class_T_handleQObjectEvent(QEvent *event) { return this->Class_T::event(event); };
    bool Class_T_handleQObjectEventFilter(QObject *watched, QEvent *event) { return this->Class_T::eventFilter(watched, event); };

    void Class_T_handleEvent(bando_FunctionName name, QEvent *event) {
        switch (name)
        {
        case bando_FunctionName::childEvent: return this->Class_T::childEvent(static_cast<QChildEvent *>(event));
        case bando_FunctionName::timerEvent: return this->Class_T::timerEvent(static_cast<QTimerEvent *>(event));

        case bando_FunctionName::actionEvent: return this->Class_T::actionEvent(static_cast<QActionEvent *>(event));
        case bando_FunctionName::changeEvent: return this->Class_T::changeEvent(event);
        case bando_FunctionName::closeEvent: return this->Class_T::closeEvent(static_cast<QCloseEvent *>(event));
        case bando_FunctionName::contextMenuEvent: return this->Class_T::contextMenuEvent(static_cast<QContextMenuEvent *>(event));
        case bando_FunctionName::dragEnterEvent: return this->Class_T::dragEnterEvent(static_cast<QDragEnterEvent *>(event));
        case bando_FunctionName::dragLeaveEvent: return this->Class_T::dragLeaveEvent(static_cast<QDragLeaveEvent *>(event));
        case bando_FunctionName::dragMoveEvent: return this->Class_T::dragMoveEvent(static_cast<QDragMoveEvent *>(event));
        case bando_FunctionName::dropEvent: return this->Class_T::dropEvent(static_cast<QDropEvent *>(event));
        case bando_FunctionName::enterEvent: return this->Class_T::enterEvent(static_cast<QEnterEvent *>(event));
        case bando_FunctionName::focusInEvent: return this->Class_T::focusInEvent(static_cast<QFocusEvent *>(event));
        case bando_FunctionName::focusOutEvent: return this->Class_T::focusOutEvent(static_cast<QFocusEvent *>(event));
        case bando_FunctionName::hideEvent: return this->Class_T::hideEvent(static_cast<QHideEvent *>(event));
        case bando_FunctionName::inputMethodEvent: return this->Class_T::inputMethodEvent(static_cast<QInputMethodEvent *>(event));
        case bando_FunctionName::keyPressEvent: return this->Class_T::keyPressEvent(static_cast<QKeyEvent *>(event));
        case bando_FunctionName::keyReleaseEvent: return this->Class_T::keyReleaseEvent(static_cast<QKeyEvent *>(event));
        case bando_FunctionName::leaveEvent: return this->Class_T::leaveEvent(event);
        case bando_FunctionName::mouseDoubleClickEvent: return this->Class_T::mouseDoubleClickEvent(static_cast<QMouseEvent *>(event));
        case bando_FunctionName::mouseMoveEvent: return this->Class_T::mouseMoveEvent(static_cast<QMouseEvent *>(event));
        case bando_FunctionName::mousePressEvent: return this->Class_T::mousePressEvent(static_cast<QMouseEvent *>(event));
        case bando_FunctionName::mouseReleaseEvent: return this->Class_T::mouseReleaseEvent(static_cast<QMouseEvent *>(event));
        case bando_FunctionName::moveEvent: return this->Class_T::moveEvent(static_cast<QMoveEvent *>(event));
        case bando_FunctionName::paintEvent: return this->Class_T::paintEvent(static_cast<QPaintEvent *>(event));
        case bando_FunctionName::resizeEvent: return this->Class_T::resizeEvent(static_cast<QResizeEvent *>(event));
        case bando_FunctionName::showEvent: return this->Class_T::showEvent(static_cast<QShowEvent *>(event));
        case bando_FunctionName::tabletEvent: return this->Class_T::tabletEvent(static_cast<QTabletEvent *>(event));
        case bando_FunctionName::wheelEvent: return this->Class_T::wheelEvent(static_cast<QWheelEvent *>(event));
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
Rice::Data_Type<BC_T> define_bando_qspinbox_under(Rice::Module module, char const *name)
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
        .define_method("_action_event", [](BC_T *self, QActionEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::actionEvent, event); })
        .define_method("_change_event", [](BC_T *self, QEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::changeEvent, event); })
        .define_method("_close_event", [](BC_T *self, QCloseEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::closeEvent, event); })
        .define_method("_context_menu_event", [](BC_T *self, QContextMenuEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::contextMenuEvent, event); })
        .define_method("_drag_enter_event", [](BC_T *self, QDragEnterEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::dragEnterEvent, event); })
        .define_method("_drag_leave_event", [](BC_T *self, QDragLeaveEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::dragLeaveEvent, event); })
        .define_method("_drag_move_event", [](BC_T *self, QDragMoveEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::dragMoveEvent, event); })
        .define_method("_drop_event", [](BC_T *self, QDropEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::dropEvent, event); })
        .define_method("_enter_event", [](BC_T *self, QEnterEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::enterEvent, event); })
        .define_method("_focus_in_event", [](BC_T *self, QFocusEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::focusInEvent, event); })
        .define_method("_focus_out_event", [](BC_T *self, QFocusEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::focusOutEvent, event); })
        .define_method("_hide_event", [](BC_T *self, QHideEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::hideEvent, event); })
        .define_method("_input_method_event", [](BC_T *self, QInputMethodEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::inputMethodEvent, event); })
        .define_method("_key_press_event", [](BC_T *self, QKeyEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::keyPressEvent, event); })
        .define_method("_key_release_event", [](BC_T *self, QKeyEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::keyReleaseEvent, event); })
        .define_method("_leave_event", [](BC_T *self, QEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::leaveEvent, event); })
        .define_method("_mouse_double_click_event", [](BC_T *self, QMouseEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::mouseDoubleClickEvent, event); })
        .define_method("_mouse_move_event", [](BC_T *self, QMouseEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::mouseMoveEvent, event); })
        .define_method("_mouse_press_event", [](BC_T *self, QMouseEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::mousePressEvent, event); })
        .define_method("_mouse_release_event", [](BC_T *self, QMouseEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::mouseReleaseEvent, event); })
        .define_method("_move_event", [](BC_T *self, QMoveEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::moveEvent, event); })
        .define_method("_paint_event", [](BC_T *self, QPaintEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::paintEvent, event); })
        .define_method("_resize_event", [](BC_T *self, QResizeEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::resizeEvent, event); })
        .define_method("_show_event", [](BC_T *self, QShowEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::showEvent, event); })
        .define_method("_tablet_event", [](BC_T *self, QTabletEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::tabletEvent, event); })
        .define_method("_wheel_event", [](BC_T *self, QWheelEvent *event) -> void { return self->Class_T_handleEvent(bando_FunctionName::wheelEvent, event); });

    bando_qlass
        .define_method("_minimum_size_hint", [](BC_T *self) -> QSize { return self->C_T::minimumSizeHint(); })
        .define_method("_size_hint", [](BC_T *self) -> QSize { return self->C_T::sizeHint(); })
        .define_method("minimum_size_hint", [](BC_T *self) -> QSize { return self->C_T::minimumSizeHint(); })
        .define_method("size_hint", [](BC_T *self) -> QSize { return self->C_T::sizeHint(); });

    return bando_qlass;
}

#endif
