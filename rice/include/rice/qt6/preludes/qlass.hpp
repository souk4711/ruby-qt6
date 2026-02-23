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

#ifndef RICE_QT6_PRELUDES_QLASS_HPP
#define RICE_QT6_PRELUDES_QLASS_HPP

#include <rice/cxx/asserts.hpp>

RICE4RUBYQT6_USE_NAMESPACE

template<typename T, typename Base_T = void>
inline Data_Type<T> define_qlass_under(Object parent, Identifier id)
{
    Class superKlass = get_superklass<Base_T>();
    Data_Type<T> klass = define_class_under<T, Base_T>(parent, id, superKlass);

    auto instance = RubyQt6_RTypedData_Registries::instance();
    auto klassid = klass.object_id();
    auto rtypeddata = klass.ruby_data_type();
    auto pair = instance->klass2rtypeddata_.insert({ klassid, rtypeddata });
    if (!pair.second && pair.first->second != rtypeddata) {
        std::string msg = "define_qlass_under: already registered qlass: " + klass.to_s().str();
        assertm(false, msg.c_str());
    }

    return klass;
}

template<typename T, typename Base_T = void>
inline Data_Type<T> declare_qlass_under(Object parent, Identifier id)
{
    Class klass = parent.const_get(id).value();

    auto instance = RubyQt6_RTypedData_Registries::instance();
    auto klassid = klass.object_id();
    auto iter = instance->klass2rtypeddata_.find(klassid);
    if (iter == instance->klass2rtypeddata_.end()) {
        std::string msg = "declare_qlass_under: unregistered qlass: " + klass.to_s().str();
        assertm(false, msg.c_str());
    }

    return declare_class_under<T, Base_T>(parent, id.c_str(), iter->second);
}

#endif
