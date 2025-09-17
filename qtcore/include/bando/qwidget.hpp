#ifndef BANDO_QWIDGET_HPP
#define BANDO_QWIDGET_HPP

#include <bando/common.hpp>

template <typename Class_T, typename... Arg_Ts> class BandoQWidget : public Class_T
{
  public:
    BandoQWidget(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQWidget(const BandoQWidget &) = delete;
    BandoQWidget &operator=(const BandoQWidget &) = delete;
    BandoQWidget(BandoQWidget &&) = delete;
    BandoQWidget &operator=(BandoQWidget &&) = delete;
    ~BandoQWidget() override {};

    template <typename T> friend void QObject_initializeValue(T *self, Rice::Object value, QMetaObject *mo);
    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQWidget>(this, value, mo); }

    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);
    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQWidget>(this); };

    template <typename T> friend int QObject_qt_metacall(Class_T *self, QMetaObject::Call call, int id, void **args);
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQWidget>(this, call, id, args); };

  private:
    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
