#ifndef BANDO_QWINDOW_HPP
#define BANDO_QWINDOW_HPP

#include <bando/common.hpp>

template <typename Class_T, typename... Arg_Ts> class BandoQWindow : public Class_T
{
  public:
    BandoQWindow(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQWindow(const BandoQWindow &) = delete;
    BandoQWindow &operator=(const BandoQWindow &) = delete;
    BandoQWindow(BandoQWindow &&) = delete;
    BandoQWindow &operator=(BandoQWindow &&) = delete;
    ~BandoQWindow() override {};

    template <typename T> friend void QObject_initializeValue(T *self, Rice::Object value, QMetaObject *mo);
    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQWindow>(this, value, mo); }

    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);
    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQWindow>(this); };

    template <typename T> friend int QObject_qt_metacall(Class_T *self, QMetaObject::Call call, int id, void **args);
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQWindow>(this, call, id, args); };

  private:
    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
