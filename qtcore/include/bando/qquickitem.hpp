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

    template <typename T> friend void QObject_initializeValue(T *self, Rice::Object value, QMetaObject *mo);
    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQQuickItem>(this, value, mo); }

    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);
    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQQuickItem>(this); };

    template <typename T> friend int QObject_qt_metacall(Class_T *self, QMetaObject::Call call, int id, void **args);
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQQuickItem>(this, call, id, args); };

  private:
    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
