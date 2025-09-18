#ifndef BANDO_QOBJECT_HPP
#define BANDO_QOBJECT_HPP

#include <bando/common.hpp>

template <typename Class_T, typename... Arg_Ts> class BandoQObject : public Class_T
{
  public:
    BandoQObject(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQObject(const BandoQObject &) = delete;
    BandoQObject &operator=(const BandoQObject &) = delete;
    BandoQObject(BandoQObject &&) = delete;
    BandoQObject &operator=(BandoQObject &&) = delete;
    ~BandoQObject() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQObject>(this, value, mo); }

    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQObject>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQObject>(this, call, id, args); };

  public:
    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
