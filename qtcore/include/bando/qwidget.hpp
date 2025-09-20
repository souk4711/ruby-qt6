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

    void actionEvent(QActionEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QActionEvent>(this, event, "actionEvent"); };
    // void changeEvent(QEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QEvent>(this, event, "changeEvent"); };
    void closeEvent(QCloseEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QCloseEvent>(this, event, "closeEvent"); };
    void contextMenuEvent(QContextMenuEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QContextMenuEvent>(this, event, "contextMenuEvent"); };
    void dragEnterEvent(QDragEnterEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QDragEnterEvent>(this, event, "dragEnterEvent"); };
    void dragLeaveEvent(QDragLeaveEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QDragLeaveEvent>(this, event, "dragLeaveEvent"); };
    void dragMoveEvent(QDragMoveEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QDragMoveEvent>(this, event, "dragMoveEvent"); };
    void dropEvent(QDropEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QDropEvent>(this, event, "dropEvent"); };
    void enterEvent(QEnterEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QEnterEvent>(this, event, "enterEvent"); };
    // void focusInEvent(QFocusEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QFocusEvent>(this, event, "focusInEvent"); };
    // void focusOutEvent(QFocusEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QFocusEvent>(this, event, "focusOutEvent"); };
    void hideEvent(QHideEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QHideEvent>(this, event, "hideEvent"); };
    void inputMethodEvent(QInputMethodEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QInputMethodEvent>(this, event, "inputMethodEvent"); };
    // void keyPressEvent(QKeyEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QKeyEvent>(this, event, "keyPressEvent"); };
    // void keyReleaseEvent(QKeyEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QKeyEvent>(this, event, "keyReleaseEvent"); };
    // void leaveEvent(QEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QEvent>(this, event, "leaveEvent"); };
    // void mouseDoubleClickEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QMouseEvent>(this, event, "mouseDoubleClickEvent"); };
    // void mouseMoveEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QMouseEvent>(this, event, "mouseMoveEvent"); };
    // void mousePressEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QMouseEvent>(this, event, "mousePressEvent"); };
    // void mouseReleaseEvent(QMouseEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QMouseEvent>(this, event, "mouseReleaseEvent"); };
    void moveEvent(QMoveEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QMoveEvent>(this, event, "moveEvent"); };
    void paintEvent(QPaintEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QPaintEvent>(this, event, "paintEvent"); };
    void resizeEvent(QResizeEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QResizeEvent>(this, event, "resizeEvent"); };
    void showEvent(QShowEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QShowEvent>(this, event, "showEvent"); };
    void tabletEvent(QTabletEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QTabletEvent>(this, event, "tabletEvent"); };
    void wheelEvent(QWheelEvent *event) override { bando_handleEvent<BandoQWidget, Class_T, QWheelEvent>(this, event, "wheelEvent"); };

  public:
    void ClassT_handleEvent(QActionEvent *event) { this->Class_T::actionEvent(event); };
    // void ClassT_handleEvent(QEvent *event) { this->Class_T::changeEvent(event); };
    void ClassT_handleEvent(QCloseEvent *event) { this->Class_T::closeEvent(event); };
    void ClassT_handleEvent(QContextMenuEvent *event) { this->Class_T::contextMenuEvent(event); };
    void ClassT_handleEvent(QDragEnterEvent *event) { this->Class_T::dragEnterEvent(event); };
    void ClassT_handleEvent(QDragLeaveEvent *event) { this->Class_T::dragLeaveEvent(event); };
    void ClassT_handleEvent(QDragMoveEvent *event) { this->Class_T::dragMoveEvent(event); };
    void ClassT_handleEvent(QDropEvent *event) { this->Class_T::dropEvent(event); };
    void ClassT_handleEvent(QEnterEvent *event) { this->Class_T::enterEvent(event); };
    // void ClassT_handleEvent(QFocusEvent *event) { this->Class_T::focusInEvent(event); };
    // void ClassT_handleEvent(QFocusEvent *event) { this->Class_T::focusOutEvent(event); };
    void ClassT_handleEvent(QHideEvent *event) { this->Class_T::hideEvent(event); };
    void ClassT_handleEvent(QInputMethodEvent *event) { this->Class_T::inputMethodEvent(event); };
    // void ClassT_handleEvent(QKeyEvent *event) { this->Class_T::keyPressEvent(event); };
    // void ClassT_handleEvent(QKeyEvent *event) { this->Class_T::keyReleaseEvent(event); };
    // void ClassT_handleEvent(QEvent *event) { this->Class_T::leaveEvent(event); };
    // void ClassT_handleEvent(QMouseEvent *event) { this->Class_T::mouseDoubleClickEvent(event); };
    // void ClassT_handleEvent(QMouseEvent *event) { this->Class_T::mouseMoveEvent(event); };
    // void ClassT_handleEvent(QMouseEvent *event) { this->Class_T::mousePressEvent(event); };
    // void ClassT_handleEvent(QMouseEvent *event) { this->Class_T::mouseReleaseEvent(event); };
    void ClassT_handleEvent(QMoveEvent *event) { this->Class_T::moveEvent(event); };
    void ClassT_handleEvent(QPaintEvent *event) { this->Class_T::paintEvent(event); };
    void ClassT_handleEvent(QResizeEvent *event) { this->Class_T::resizeEvent(event); };
    void ClassT_handleEvent(QShowEvent *event) { this->Class_T::showEvent(event); };
    void ClassT_handleEvent(QTabletEvent *event) { this->Class_T::tabletEvent(event); };
    void ClassT_handleEvent(QWheelEvent *event) { this->Class_T::wheelEvent(event); };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);
    template <typename BC_T, typename C_T, typename E_T> friend void bando_handleEvent(BC_T *self, E_T* event, const char* rb_name);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
