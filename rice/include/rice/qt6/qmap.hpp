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

#ifndef RICE_QMAP_HPP
#define RICE_QMAP_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QMap>

using namespace Rice;

template<typename QMap_T>
class DefineQMapMethods
{
      using Key_T = typename QMap_T::key_type;
      using Mapped_T = typename QMap_T::mapped_type;

public:
    DefineQMapMethods(Data_Type<QMap_T> klass) : klass_(klass)
    {
        this->define_constructors();
        this->define_capacity_methods();
        this->define_access_methods();
        this->define_comparable_methods();
        this->define_insert_methods();
        this->define_remove_methods();
        this->define_replace_methods();
        this->define_enumerable();
        this->define_to_hash();
        this->define_to_s();
    }

private:
    void define_constructors()
    {
        klass_.define_constructor(Constructor<QMap_T>());
        klass_.define_constructor(Constructor<QMap_T, const QMap_T&>(), Arg("other"));
    }

    void define_capacity_methods()
    {
        klass_.define_method("empty?", &QMap_T::isEmpty);
        klass_.define_method("length", &QMap_T::size);
        klass_.define_method("size", &QMap_T::size);
    }

    void define_access_methods()
    {
    }

    void define_comparable_methods()
    {
    }

    void define_insert_methods()
    {
    }

    void define_remove_methods()
    {
    }

    void define_replace_methods()
    {
    }

    void define_enumerable()
    {
    }

    void define_to_hash()
    {
    }

    void define_to_s()
    {
    }

private:
    Data_Type<QMap_T> klass_;
};

template <typename Key_T, typename Mapped_T>
void define_qmap_under(Module module)
{
    using QMap_T = QMap<Key_T, Mapped_T>;

    detail::TypeMapper<QMap_T> typeMapper;
    std::string klassName = typeMapper.rubyName();
    Identifier id(klassName);

    Data_Type<QMap_T> qmap = define_class_under<QMap_T>(module, id);
    DefineQMapMethods<QMap_T> qmap_(qmap);
}

#endif
