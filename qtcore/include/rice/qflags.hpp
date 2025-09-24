#ifndef RICE_QFLAGS_HPP
#define RICE_QFLAGS_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QFlags>

using namespace Rice;

template<typename Enum_T>
Data_Type<QFlags<Enum_T>> define_qflags_under(Module module, char const* name)
{
    using QFlags_T = QFlags<Enum_T>;
    Data_Type<QFlags_T> flags = define_class_under<QFlags_T>(module, name)
        .define_constructor(Constructor<QFlags_T>())
        .define_constructor(Constructor<QFlags_T, Enum_T>(), Arg("flags"))
        .template define_method("set_flag", &QFlags_T::setFlag, Arg("flag"), Arg("on") = static_cast<bool>(true))
        .template define_method("test_any_flag", &QFlags_T::testAnyFlag, Arg("flag"))
        .template define_method("test_any_flags", &QFlags_T::testAnyFlags, Arg("flags"))
        .template define_method("test_flag", &QFlags_T::testFlag, Arg("flag"))
        .template define_method("test_flags", &QFlags_T::testFlags, Arg("flags"))
        .template define_method("to_int", &QFlags_T::toInt)
        .template define_method("to_i", &QFlags_T::toInt)
        .template define_method("!", &QFlags_T::operator!)
        .template define_method<QFlags_T (QFlags_T::*)(int) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(int) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("&=", &QFlags_T::operator&=, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("^", &QFlags_T::operator^, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("^", &QFlags_T::operator^, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("^=", &QFlags_T::operator^=, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("^=", &QFlags_T::operator^=, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("|", &QFlags_T::operator|, Arg("other"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("|", &QFlags_T::operator|, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(Enum_T) noexcept>("|=", &QFlags_T::operator|=, Arg("other"))
        .template define_method<QFlags_T &(QFlags_T::*)(QFlags_T) noexcept>("|=", &QFlags_T::operator|=, Arg("other"))
        .template define_method("~", &QFlags_T::operator~)
        .template define_singleton_function("from_int", [](int i) -> QFlags_T { return QFlags_T::fromInt(i); }, Arg("i"));
    return flags;
}

#endif
