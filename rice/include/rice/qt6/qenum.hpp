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

#ifndef RICE_QENUM_HPP
#define RICE_QENUM_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QVariant>

using namespace Rice;

template<typename Enum_T>
VALUE qenum_to_i(VALUE self)
{
    auto rb_return = (int)detail::From_Ruby<Enum_T>().convert(self);
    return detail::To_Ruby<int>().convert(rb_return);
}

template<typename Enum_T>
VALUE qenum_from_int(VALUE self, VALUE i)
{
    auto rb_return = static_cast<Enum_T>(detail::From_Ruby<int>().convert(i));
    return detail::To_Ruby<Enum_T>().convert(rb_return);
}

template<typename Enum_T>
VALUE qenum_qvariant_register_metatype(VALUE self)
{
    auto rb_return = qRegisterMetaType<Enum_T>();
    return detail::To_Ruby<int>().convert(rb_return);
}

template<typename Enum_T>
Data_Type<Enum_T> define_qenum_under(Module module, char const* name)
{
    Data_Type<Enum_T> qenum = define_class_under<Enum_T>(module, name);
    detail::protect(rb_define_method, qenum, "to_i", (RUBY_METHOD_FUNC)qenum_to_i<Enum_T>, 0);
    detail::protect(rb_define_singleton_method, qenum, "from_int", (RUBY_METHOD_FUNC)qenum_from_int<Enum_T>, 1);
    detail::protect(rb_define_singleton_method, qenum, "_qvariant_register_metatype", (RUBY_METHOD_FUNC)qenum_qvariant_register_metatype<Enum_T>, 0);
    return qenum;
}

template<typename Enum_T>
void define_qenum_value_under(Data_Type<Enum_T> qenum, std::string name, Enum_T value)
{
    Data_Object<Enum_T> object(value, true, Data_Type<Enum_T>::klass());
    qenum.const_set(name, object);
}

#endif
