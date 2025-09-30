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

#ifndef RICE_QLIST_HPP
#define RICE_QLIST_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QList>

using namespace Rice;

template<typename QList_T>
class DefineQListMethods
{
      using Value_T = typename QList_T::value_type;
      using Parameter_T = typename QList_T::parameter_type;

public:
    DefineQListMethods(Data_Type<QList_T> klass) : klass_(klass)
    {
        this->define_constructors();
        this->define_constructable_methods();
        this->define_capacity_methods();
        this->define_access_methods();
        this->define_comparable_methods();
        this->define_insert_methods();
        this->define_remove_methods();
        this->define_replace_methods();
        this->define_enumerable();
        this->define_to_array();
        this->define_to_s();
    }

private:
    qsizetype normalizeIndex(qsizetype size, qsizetype index, bool enforceBounds = false)
    {
        if (index < 0) {
            index = ((-index) % size);
            index = index > 0 ? size - index : index;
        }
        if (enforceBounds && (index < 0 || index >= size)) {
            throw std::out_of_range("Invalid index: " + std::to_string(index));
        }
        return index;
    }

    void define_constructors()
    {
        klass_.define_constructor(Constructor<QList_T>());
        klass_.define_constructor(Constructor<QList_T, qsizetype>(), Arg("size"));
        klass_.define_constructor(Constructor<QList_T, qsizetype, const Parameter_T>(), Arg("size"), Arg("value"));
        klass_.define_constructor(Constructor<QList_T, const QList_T&>(), Arg("other"));
    }

    void define_constructable_methods()
    {
        klass_.template define_method<void (QList_T::*)(qsizetype)>("resize", &QList_T::resize, Arg("size"));
        klass_.template define_method<void (QList_T::*)(qsizetype, Parameter_T)>("resize", &QList_T::resize, Arg("size"), Arg("value"));
    }

    void define_capacity_methods()
    {
        klass_.define_method("capacity", &QList_T::capacity);
        klass_.define_method("empty?", &QList_T::isEmpty);
        klass_.define_method("length", &QList_T::length);
        klass_.define_method("max_size", &QList_T::max_size);
        klass_.define_method("reserve", &QList_T::reserve);
        klass_.define_method("shrink_to_fit", &QList_T::shrink_to_fit);
        klass_.define_method("size", &QList_T::size);
    }

    void define_access_methods()
    {
        klass_.define_method("at", [this](QList_T *self, qsizetype index) -> std::optional<Value_T> {
            if (self->size() > 0) {
                index = normalizeIndex(self->size(), index);
                if (index >= 0 && index < self->size())
                    return self->at(index);
            }
            return std::nullopt;
        });

        klass_.define_method("first", [](QList_T *self) -> std::optional<Value_T> {
            if (self->size() > 0)
                return self->first();
            return std::nullopt;
        });

        klass_.define_method("last", [](QList_T *self) -> std::optional<Value_T> {
            if (self->size() > 0)
                return self->last();
            return std::nullopt;
        });

        rb_define_alias(klass_, "[]", "at");
    }

    void define_comparable_methods()
    {
        klass_.define_method("count", [](QList_T *self) -> qsizetype {
            return self->size();
        });
        klass_.define_method("count", [](QList_T *self, Parameter_T element) -> qsizetype {
            return self->count(element);
        });

        klass_.define_method("include?", [](QList_T *self, Parameter_T element) -> bool {
            return self->contains(element);
        });

        klass_.define_method("index", [](QList_T *self, Parameter_T element) -> std::optional<qsizetype> {
            qsizetype index = self->indexOf(element);
            if (index != -1)
                return index;
            return std::nullopt;
        });
    }

    void define_insert_methods()
    {
        klass_.define_method("insert", [this](QList_T *self, qsizetype index, Parameter_T element) -> QList_T* {
            if (self->size() > 0) {
                if (index != self->size()) index = normalizeIndex(self->size(), index, true);
            } else {
                if (index != 0) throw std::out_of_range("Invalid index: " + std::to_string(index));
            }
            self->insert(index, element);
            return self;
        });

        klass_.define_method("push", [](QList_T *self, Parameter_T element) -> QList_T* {
            self->push_back(element);
            return self;
        });

        klass_.define_method("pop", [](QList_T *self) -> std::optional<Value_T> {
            if (self->size() > 0)
                return self->takeLast();
            return std::nullopt;
        });

        rb_define_alias(klass_, "<<", "push");
    }

    void define_remove_methods()
    {
        klass_.define_method("clear", [](QList_T *self) -> QList_T* {
            self->clear();
            return self;
        });

        klass_.define_method("delete", [](QList_T *self, Parameter_T element) -> std::optional<Value_T> {
            qsizetype index = self->lastIndexOf(element);
            if (index != -1) {
                Value_T result = self->takeAt(index);
                self->removeAll(element);
                return result;
            }
            return std::nullopt;
        });

        klass_.define_method("delete_at", [this](QList_T *self, qsizetype index) -> std::optional<Value_T> {
            if (self->size() > 0) {
                index = normalizeIndex(self->size(), index);
                if (index >= 0 && index < self->size())
                    return self->takeAt(index);
            }
            return std::nullopt;
        });
    }

    void define_replace_methods()
    {
        klass_.define_method("[]=", [this](QList_T*self, qsizetype index, Parameter_T element) -> Parameter_T {
            if (self->size() > 0) {
                index = normalizeIndex(self->size(), index, true);
            } else {
                throw std::out_of_range("Invalid index: " + std::to_string(index));
            }
            self->replace(index, element);
            return element;
        });
    }

    void define_enumerable()
    {
    }

    void define_to_array()
    {
    }

    void define_to_s()
    {
    }

private:
    Data_Type<QList_T> klass_;
};

template <typename Value_T>
void define_qlist_under(Module module)
{
    using QList_T = QList<Value_T>;

    std::string name = detail::typeName(typeid(QList_T));
    std::string klassName = detail::rubyClassName(name);
    Identifier id(klassName);

    Data_Type<QList_T> qlist = define_class_under<QList_T>(module, id);
    DefineQListMethods<QList_T> qlist_(qlist);
}

#endif
