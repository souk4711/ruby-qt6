// This file is part of [Ruby-Qt6](https://github.com/souk4711/ruby-qt6).
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

#ifndef RICE_QENUM_HPP
#define RICE_QENUM_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QVariant>

using namespace Rice;

template<typename Enum_T>
Enum<Enum_T> define_qenum_under(char const* name, Module module)
{
    Enum<Enum_T> qenum = define_enum_under<Enum_T>(name, module);

    qenum
        .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<Enum_T>(); })
        .define_singleton_function("_qvariant_from_value", [](const Enum_T &value) -> QVariant { return QVariant::fromValue(value); })
        .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> Enum_T { return qvariant.value<Enum_T>(); });

    return qenum;
}

#endif
