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

#ifndef RICE_QT6CORE_HPP
#define RICE_QT6CORE_HPP

#ifdef _WIN32
#  ifdef RUBYQT6_BUILD_QTCORE_LIB
#    define RUBYQT6_QTCORE_EXPORT RUBYQT6_DECL_DLLEXPORT
#  else
#    define RUBYQT6_QTCORE_EXPORT RUBYQT6_DECL_DLLIMPORT
#  endif
#else
#  define RUBYQT6_QTCORE_EXPORT
#endif

#include <QtAssert>

using namespace Rice;

struct RUBYQT6_QTCORE_EXPORT RubyQt6_RTypedData_Collector
{
    RUBYQT6_QTCORE_EXPORT static RubyQt6_RTypedData_Collector *instance();
    static RubyQt6_RTypedData_Collector* instance_;

    std::map<VALUE, rb_data_type_t*> map_;
};

#ifdef RUBYQT6_BUILD_QTCORE_LIB
inline RubyQt6_RTypedData_Collector *RubyQt6_RTypedData_Collector::instance()
{
    if (instance_ == nullptr) { instance_ = new RubyQt6_RTypedData_Collector; }
    return instance_;
}
inline RubyQt6_RTypedData_Collector *RubyQt6_RTypedData_Collector::instance_ = nullptr;
#endif

template<typename T, typename Base_T = void>
inline Data_Type<T> define_qlass_under(Object parent, Identifier id)
{
    Class superKlass = get_superklass<Base_T>();
    Data_Type<T> klass = define_class_under<T, Base_T>(parent, id, superKlass);

    auto ret = RubyQt6_RTypedData_Collector::instance()->map_.insert({ klass.object_id(), klass.ruby_data_type() });
    if (!ret.second && (*ret.first).second != klass.ruby_data_type()) {
        std::string msg = "klass: " + klass.to_s().str();
        Q_ASSERT_X(false, "define_qlass_under", msg.c_str());
    }

    return klass;
}

template<typename T, typename Base_T = void>
inline Data_Type<T> define_qlass_under(Object parent, char const* name)
{
    Identifier id(name);
    return define_qlass_under<T, Base_T>(parent, id);
}

template<typename T, typename Base_T = void>
inline Data_Type<T> declare_qlass_under(Object parent, Identifier id)
{
    Class klass = parent.const_get(id).value();

    auto ret = RubyQt6_RTypedData_Collector::instance()->map_.find(klass.object_id());
    if (ret == RubyQt6_RTypedData_Collector::instance()->map_.end()) {
        std::string msg = "klass: " + klass.to_s().str();
        Q_ASSERT_X(false, "declare_qlass_under", msg.c_str());
    }

    return declare_class_under<T, Base_T>(parent, id.c_str(), (*ret).second);
}

template<typename T, typename Base_T = void>
inline Data_Type<T> declare_qlass_under(Object parent, char const* name)
{
    Identifier id(name);
    return declare_qlass_under<T, Base_T>(parent, id);
}

#endif
