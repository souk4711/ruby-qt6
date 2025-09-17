#ifndef BANDO_QQUICKITEM_HPP
#define BANDO_QQUICKITEM_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QMetaObject>
#include <QObject>

template <typename Class_T, typename... Arg_Ts> class BandoQQuickItem : public Class_T
{
  public:
    BandoQQuickItem(Arg_Ts... args) : Class_T(args...), value_(Qnil), mo_(nullptr) {};
    BandoQQuickItem(const BandoQQuickItem &) = delete;
    BandoQQuickItem &operator=(const BandoQQuickItem &) = delete;
    BandoQQuickItem(BandoQQuickItem &&) = delete;
    BandoQQuickItem &operator=(BandoQQuickItem &&) = delete;
    ~BandoQQuickItem() override {};

    void initializeValue(Rice::Object value, QMetaObject *mo)
    {
        value_ = value;
        mo_ = mo;
    }

    const QMetaObject *metaObject() const override
    {
        if (QObject::d_ptr->metaObject != nullptr)
            return QObject::d_ptr->dynamicMetaObject();
        if (mo_ != nullptr)
            return mo_;
        return &Class_T::staticMetaObject;
    };

    int qt_metacall(QMetaObject::Call call, int id, void **args) override
    {
        int result = Class_T::qt_metacall(call, id, args);
        if (result < 0)
            return result;

        std::cout << "invoke qt_metacall(.., " << id << ", ..)" << std::endl;
        return -1;
    };

  private:
    Rice::Object value_;
    QMetaObject *mo_;
};

#endif
