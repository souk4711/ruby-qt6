#ifndef BANDO_QLAYOUT_HPP
#define BANDO_QLAYOUT_HPP

#include <bando/common.hpp>

template <typename Class_T, typename... Arg_Ts> class BandoQLayout : public Class_T
{
  public:
    BandoQLayout(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQLayout(const BandoQLayout &) = delete;
    BandoQLayout &operator=(const BandoQLayout &) = delete;
    BandoQLayout(BandoQLayout &&) = delete;
    BandoQLayout &operator=(BandoQLayout &&) = delete;
    ~BandoQLayout() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQLayout>(this, value, mo); };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQLayout, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQLayout>(this, call, id, args); };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
