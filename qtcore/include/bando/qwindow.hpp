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

    void initializeValue(Rice::Object value, QMetaObject *mo) { bando_initializeValue<BandoQWindow>(this, value, mo); }

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQWindow>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQWindow>(this, call, id, args); };

  public:
    template <typename T> friend const QMetaObject *bando_metaObject(const T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
