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

    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQQuickItem>(this, value, mo); }

    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQQuickItem>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQQuickItem>(this, call, id, args); };

  public:
    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
