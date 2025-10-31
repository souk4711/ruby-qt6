// This file is part of [RubyQt6](https://github.com/souk4711/ruby-qt6).
//
// It is licensed under the LGPLv3, included below.
//
// As a special exception to the GNU Lesser General Public License version 3
// ("LGPL3"), the copyright holders of this Library give you permission to
// convey to a third party a Combined Work that links statically or dynamically
// to this Library without providing any Minimal Corresponding Source or
// Minimal Application Code as set out in 4d or providing the installation
// information set out in section 4e, provided that you comply with the other
// provisions of LGPL3 and provided that you meet, for the Application the
// terms and conditions of the license(s) which apply to the Application.
//
// Except as stated in this special exception, the provisions of LGPL3 will
// continue to comply in full to this Library. If you modify this Library, you
// may apply this exception to your version of this Library, but you are not
// obliged to do so. If you do not wish to do so, delete this exception
// statement from your version. This exception does not (and cannot) modify any
// license terms which apply to the Application, with which you must still
// comply.

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

    Data_Type<QFlags_T> qflags = define_class_under<QFlags_T>(module, name)
        .define_constructor(Constructor<QFlags_T>())
        .define_constructor(Constructor<QFlags_T, Enum_T>(), Arg("flags"))
        .template define_method("to_i", [](QFlags_T *self) -> int { return (int)(*self); })
        .template define_method("~", [](QFlags_T *self) -> int { return ~(int)(*self); })
        .template define_method<QFlags_T (QFlags_T::*)(Enum_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
        .template define_method<QFlags_T (QFlags_T::*)(QFlags_T) const noexcept>("&", &QFlags_T::operator&, Arg("mask"))
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
        .template define_singleton_function("from_int", [](int i) -> QFlags_T { return QFlags_T::fromInt(i); }, Arg("i"));
    return qflags;
}

#endif
