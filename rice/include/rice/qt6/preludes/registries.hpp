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

#ifndef RICE_QT6_PRELUDES_REGISTRIES_HPP
#define RICE_QT6_PRELUDES_REGISTRIES_HPP

#ifdef _WIN32
#  ifdef RUBYQT6_BUILD_QTCORE_LIB
#    define RUBYQT6_QTCORE_EXPORT __declspec(dllexport)
#  else
#    define RUBYQT6_QTCORE_EXPORT __declspec(dllimport)
#  endif
#else
#  define RUBYQT6_QTCORE_EXPORT
#endif

struct RUBYQT6_QTCORE_EXPORT RubyQt6_RTypedData_Registries
{
    RUBYQT6_QTCORE_EXPORT static RubyQt6_RTypedData_Registries *instance();
    static RubyQt6_RTypedData_Registries* instance_;

    std::map<VALUE, rb_data_type_t*> klass2rtypeddata_;
};

#ifdef RUBYQT6_BUILD_QTCORE_LIB
inline RubyQt6_RTypedData_Registries *RubyQt6_RTypedData_Registries::instance()
{
    if (instance_ == nullptr) { instance_ = new RubyQt6_RTypedData_Registries; }
    return instance_;
}
inline RubyQt6_RTypedData_Registries *RubyQt6_RTypedData_Registries::instance_ = nullptr;
#endif

#endif
