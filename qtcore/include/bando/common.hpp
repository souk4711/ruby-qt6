#ifndef BANDO_COMMON_HPP
#define BANDO_COMMON_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QMetaObject>
#include <QObject>

template <typename Class_T> void QObject_initializeValue(Class_T *self, Rice::Object value, QMetaObject *mo)
{
    self->value_ = value;
    self->mo_ = mo;
}

template <typename Class_T> const QMetaObject *QObject_metaObject(const Class_T *self)
{
    if (self->QObject::d_ptr->metaObject != nullptr)
        return self->QObject::d_ptr->dynamicMetaObject();
    if (self->mo_ != nullptr)
        return self->mo_;
    return &Class_T::staticMetaObject;
};

template <typename Class_T> int QObject_qt_metacall(Class_T *self, QMetaObject::Call call, int id, void **args)
{
    int result = self->Class_T::qt_metacall(call, id, args);
    if (result < 0)
        return result;

    std::cout << "invoke qt_metacall(.., " << id << ", ..)" << std::endl;
    return -1;
};

#endif
