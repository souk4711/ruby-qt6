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

#include <QFlags>

RICE4RUBYQT6_USE_NAMESPACE

template<typename QFlags_T>
VALUE qflags_to_i(VALUE self)
{
    auto rb_return = (int)detail::From_Ruby<QFlags_T>().convert(self);
    return detail::To_Ruby<int>().convert(rb_return);
}

template<typename QFlags_T>
VALUE qflags_from_int(VALUE self, VALUE i)
{
    auto rb_return = static_cast<QFlags_T>(detail::From_Ruby<int>().convert(i));
    return detail::To_Ruby<QFlags_T>().convert(rb_return);
}

template<typename Enum_T>
Data_Type<QFlags<Enum_T>> define_qflags_under(Module module, char const* name)
{
    using QFlags_T = QFlags<Enum_T>;

    Data_Type<QFlags_T> qflags = define_class_under<QFlags_T>(module, name);
    detail::protect(rb_define_method, qflags, "to_i", (RUBY_METHOD_FUNC)qflags_to_i<QFlags_T>, 0);
    detail::protect(rb_define_singleton_method, qflags, "from_int", (RUBY_METHOD_FUNC)qflags_from_int<QFlags_T>, 1);
    return qflags;
}

#endif
