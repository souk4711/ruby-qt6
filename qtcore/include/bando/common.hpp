#ifndef BANDO_COMMON_HPP
#define BANDO_COMMON_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QMetaMethod>
#include <QMetaObject>
#include <QObject>

template <typename BandoClass_T> void bando_initializeValue(BandoClass_T *self, Rice::Object value, QMetaObject *mo)
{
    self->value_ = value;
    self->mo_ = mo;
}

template <typename BandoClass_T, typename Class_T> const QMetaObject *bando_metaObject(const BandoClass_T *self)
{
    if (self->QObject::d_ptr->metaObject != nullptr)
        return self->QObject::d_ptr->dynamicMetaObject();
    if (self->mo_ != nullptr)
        return self->mo_;
    return &Class_T::staticMetaObject;
};

template <typename BandoClass_T> int bando_qt_metacall(BandoClass_T *self, QMetaObject::Call call, int id, void **args)
{
    if (call == QMetaObject::InvokeMetaMethod)
    {
        auto mo = self->metaObject();
        auto method = mo->method(id);
        if (!method.isValid())
        {
            qDebug() << "RubyQt6::Bando: qt_metacall: invalid method";
            return -1;
        }
        if (method.methodType() == QMetaMethod::Signal)
        {
            QMetaObject::activate(self, method.methodIndex(), args);
            return -1;
        }
        if (method.methodType() == QMetaMethod::Slot)
        {
            auto name = method.name().toStdString();
            Q_ASSERT(name.rfind("_rubyqt6_", 0) == 0);

            auto arguments = Rice::Array();
            for (int i = 0; i < method.parameterCount(); ++i)
            {
                QVariant argument(method.parameterMetaType(i), args[i + 1]);
                arguments.push(std::move(argument));
            }

            Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
            self->value_.vcall(name, arguments);
            return -1;
        }
    }

    return -1;
};

template <typename BandoClass_T, typename Class_T, typename Event_T> void bando_handleEvent(BandoClass_T *self, Event_T* event, const char* rb_name)
{
    if (!self->value_.respond_to(rb_name)) {
        self->ClassT_handleEvent(event);
        return;
    }

    auto arguments = Rice::Array();
    arguments.push(Rice::Object(Rice::detail::to_ruby(event)));

    Q_ASSERT(self->value_.rb_type() != RUBY_T_NONE);
    self->value_.vcall(rb_name, arguments);
}

#endif
