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

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQQuickItem>(this, value, mo); };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQQuickItem, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQQuickItem>(this, call, id, args); };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
