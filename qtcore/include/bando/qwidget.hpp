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

    void initializeValue(Rice::Object value, QMetaObject *mo) { QObject_initializeValue<BandoQWidget>(this, value, mo); }

    const QMetaObject *metaObject() const override { return QObject_metaObject<BandoQWidget>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return QObject_qt_metacall<BandoQWidget>(this, call, id, args); };

  public:
    template <typename T> friend const QMetaObject *QObject_metaObject(const T *self);

    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
