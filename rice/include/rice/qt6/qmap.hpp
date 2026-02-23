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

#include <QMap>

RICE4RUBYQT6_USE_NAMESPACE

template<typename QMap_T>
class DefineQMapMethods
{
      using Key_T = typename QMap_T::key_type;
      using Mapped_T = typename QMap_T::mapped_type;
      using To_Ruby_T = typename detail::remove_cv_recursive_t<Mapped_T>;

public:
    DefineQMapMethods(Data_Type<QMap_T> klass) : klass_(klass)
    {
        this->define_constructors();
        this->define_capacity_methods();
        this->define_access_methods();
        this->define_comparable_methods();
        this->define_insert_methods();
        this->define_remove_methods();
        this->define_enumerable();
        this->define_to_hash();
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
        klass_.define_method("[]", [](QMap_T *self, Key_T &key) -> std::optional<Mapped_T> {
            auto iter = self->find(key);
            if (iter != self->end())
                return iter.value();
            return std::nullopt;
        });

        klass_.define_method("keys", [](QMap_T *self) -> QList<Key_T> {
            return self->keys();
        });

        klass_.define_method("values", [](QMap_T *self) -> QList<Mapped_T> {
            return self->values();
        });
    }

    void define_comparable_methods()
    {
        klass_.define_method("has_key?", [](QMap_T *self, Key_T &key) -> bool {
            return self->contains(key);
        });

        klass_.define_method("has_value?", [](QMap_T *self, Mapped_T &value) -> bool {
            for (auto i = self->cbegin(), end = self->cend(); i != end; ++i)
                if (i.value() == value)
                    return true;
            return false;
        });

        rb_define_alias(klass_, "key?", "has_key?");
        rb_define_alias(klass_, "value?", "has_value?");
    }

    void define_insert_methods()
    {
        klass_.define_method("insert", [](QMap_T *self, Key_T &key, Mapped_T &value) -> Mapped_T {
            self->insert(key, value);
            return value;
        });

        rb_define_alias(klass_, "[]=", "insert");
    }

    void define_remove_methods()
    {
        klass_.define_method("clear", [](QMap_T *self) -> QMap_T* {
            self->clear();
            return self;
        });

        klass_.define_method("delete", [](QMap_T *self, Key_T &key) -> std::optional<Mapped_T> {
            auto iter = self->find(key);
            if (iter != self->cend()) {
                Mapped_T result = iter.value();
                self->erase(iter);
                return result;
            }
            return std::nullopt;
        });
    }

    void define_enumerable()
    {
        klass_.template define_iterator<typename QMap_T::iterator (QMap_T::*)()>(&QMap_T::begin, &QMap_T::end);
    }

    void define_to_hash()
    {
        klass_.define_method("to_h", [](QMap_T *self) {
            VALUE result = rb_hash_new();
            for (auto iter = self->cbegin(), end = self->cend(); iter != end; ++iter) {
                VALUE key = detail::To_Ruby<Key_T&>().convert(iter.key());
                VALUE value = detail::To_Ruby<To_Ruby_T&>().convert(iter.value());
                rb_hash_aset(result, key, value);
            }
            return result;
        }, Return().setValue());
    }

private:
    Data_Type<QMap_T> klass_;
};

template <typename Key_T, typename Mapped_T>
void define_qmap_under(Module module)
{
    using QMap_T = QMap<Key_T, Mapped_T>;

    detail::TypeDetail<QMap_T> typeDetail;
    std::string klassName = typeDetail.rubyName();
    Identifier id(klassName);

    Data_Type<QMap_T> qmap = define_qlass_under<QMap_T>(module, id);
    DefineQMapMethods<QMap_T> qmap_(qmap);
}

#endif
