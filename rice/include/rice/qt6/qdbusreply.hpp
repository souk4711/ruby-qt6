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

#ifndef RICE_QDBUSREPLY_HPP
#define RICE_QDBUSREPLY_HPP

#include <QDBusReply>

RICE4RUBYQT6_USE_NAMESPACE

template <typename Value_T>
void define_qdbusreply_under(Module module)
{
    using QDBusReply_T = QDBusReply<Value_T>;
    using QDBusPendingReply_T = QDBusPendingReply<Value_T>;

    detail::TypeMapper<QDBusReply_T> typeMapper;
    std::string klassName = typeMapper.rubyName();
    Identifier id(klassName);

    define_class_under<QDBusReply_T>(module, id)
        .define_constructor(Constructor<QDBusReply_T, const QDBusError &>(), Arg("dbus_error") = static_cast<const QDBusError &>(QDBusError()))
        .define_constructor(Constructor<QDBusReply_T, const QDBusMessage &>(), Arg("reply"))
        .define_constructor(Constructor<QDBusReply_T, const QDBusPendingCall &>(), Arg("pcall"))
        .define_constructor(Constructor<QDBusReply_T, const QDBusPendingReply_T &>(), Arg("reply"))
        .define_constructor(Constructor<QDBusReply_T, const QDBusReply_T &>(), Arg("other"))
        .template define_method<const QDBusError &(QDBusReply_T::*)() const>("error", &QDBusReply_T::error)
        .template define_method("valid?", &QDBusReply_T::isValid)
        .template define_method("value", &QDBusReply_T::value);
};

#endif
