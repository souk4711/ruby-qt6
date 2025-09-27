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

#ifndef BANDO_QWIDGET_HPP
#define BANDO_QWIDGET_HPP

#include <bando/common.hpp>
#include <QActionEvent>
#include <QEvent>
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
#include <QWheelEvent>

template <typename Class_T, typename... Arg_Ts> class BandoQWidget : public Class_T
{
  public:
    BandoQWidget(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQWidget(const BandoQWidget &) = delete;
    BandoQWidget &operator=(const BandoQWidget &) = delete;
    BandoQWidget(BandoQWidget &&) = delete;
    BandoQWidget &operator=(BandoQWidget &&) = delete;
    ~BandoQWidget() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQWidget>(this, value, mo); };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQWidget, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQWidget>(this, call, id, args); };

    void actionEvent(QActionEvent *event) override { bando_handleEvent<BandoQWidget, QActionEvent>(this, event, bando_FunctionName::actionEvent); };
    void changeEvent(QEvent *event) override { bando_handleEvent<BandoQWidget, QEvent>(this, event, bando_FunctionName::changeEvent); };
    void closeEvent(QCloseEvent *event) override { bando_handleEvent<BandoQWidget, QCloseEvent>(this, event, bando_FunctionName::closeEvent); };
    void contextMenuEvent(QContextMenuEvent *event) override { bando_handleEvent<BandoQWidget, QContextMenuEvent>(this, event, bando_FunctionName::contextMenuEvent); };
    void dragEnterEvent(QDragEnterEvent *event) override { bando_handleEvent<BandoQWidget, QDragEnterEvent>(this, event, bando_FunctionName::dragEnterEvent); };
    void dragLeaveEvent(QDragLeaveEvent *event) override { bando_handleEvent<BandoQWidget, QDragLeaveEvent>(this, event, bando_FunctionName::dragLeaveEvent); };
    void dragMoveEvent(QDragMoveEvent *event) override { bando_handleEvent<BandoQWidget, QDragMoveEvent>(this, event, bando_FunctionName::dragMoveEvent); };
    void dropEvent(QDropEvent *event) override { bando_handleEvent<BandoQWidget, QDropEvent>(this, event, bando_FunctionName::dropEvent); };
    void enterEvent(QEnterEvent *event) override { bando_handleEvent<BandoQWidget, QEnterEvent>(this, event, bando_FunctionName::enterEvent); };
    void focusInEvent(QFocusEvent *event) override { bando_handleEvent<BandoQWidget, QFocusEvent>(this, event, bando_FunctionName::focusInEvent); };
    void focusOutEvent(QFocusEvent *event) override { bando_handleEvent<BandoQWidget, QFocusEvent>(this, event, bando_FunctionName::focusOutEvent); };
    void hideEvent(QHideEvent *event) override { bando_handleEvent<BandoQWidget, QHideEvent>(this, event, bando_FunctionName::hideEvent); };
    void inputMethodEvent(QInputMethodEvent *event) override { bando_handleEvent<BandoQWidget, QInputMethodEvent>(this, event, bando_FunctionName::inputMethodEvent); };
    void keyPressEvent(QKeyEvent *event) override { bando_handleEvent<BandoQWidget, QKeyEvent>(this, event, bando_FunctionName::keyPressEvent); };
    void keyReleaseEvent(QKeyEvent *event) override { bando_handleEvent<BandoQWidget, QKeyEvent>(this, event, bando_FunctionName::keyReleaseEvent); };
    void leaveEvent(QEvent *event) override { bando_handleEvent<BandoQWidget, QEvent>(this, event, bando_FunctionName::leaveEvent); };
    void mouseDoubleClickEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, QMouseEvent>(this, event, bando_FunctionName::mouseDoubleClickEvent); };
    void mouseMoveEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, QMouseEvent>(this, event, bando_FunctionName::mouseMoveEvent); };
    void mousePressEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, QMouseEvent>(this, event, bando_FunctionName::mousePressEvent); };
    void mouseReleaseEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, QMouseEvent>(this, event, bando_FunctionName::mouseReleaseEvent); };
    void moveEvent(QMoveEvent *event) override { bando_handleEvent<BandoQWidget, QMoveEvent>(this, event, bando_FunctionName::moveEvent); };
    void paintEvent(QPaintEvent *event) override { bando_handleEvent<BandoQWidget, QPaintEvent>(this, event, bando_FunctionName::paintEvent); };
    void resizeEvent(QResizeEvent *event) override { bando_handleEvent<BandoQWidget, QResizeEvent>(this, event, bando_FunctionName::resizeEvent); };
    void showEvent(QShowEvent *event) override { bando_handleEvent<BandoQWidget, QShowEvent>(this, event, bando_FunctionName::showEvent); };
    void tabletEvent(QTabletEvent *event) override { bando_handleEvent<BandoQWidget, QTabletEvent>(this, event, bando_FunctionName::tabletEvent); };
    void wheelEvent(QWheelEvent *event) override { bando_handleEvent<BandoQWidget, QWheelEvent>(this, event, bando_FunctionName::wheelEvent); };

  public:
    void Class_T_handleEvent(bando_FunctionName name, QEvent *event) {
        switch (name)
        {
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
    template <typename BC_T, typename E_T> friend void bando_handleEvent(BC_T *self, E_T* event, const char* rb_name);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
