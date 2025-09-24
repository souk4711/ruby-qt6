#ifndef RICE_QLIST_HPP
#define RICE_QLIST_HPP

#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <QList>

using namespace Rice;

template<typename Element_T>
void define_qlist_constructors(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_constructable_methods(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_capacity_methods(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_access_methods(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_comparable_methods(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_modify_methods(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_enumerable(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_to_array(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
void define_qlist_to_s(Data_Type<QList<Element_T>> qlist)
{
    using QList_T = QList<Element_T>;
}

template<typename Element_T>
Data_Type<QList<Element_T>> define_qlist_under(Module module, char const* name)
{
    std::cout << "?????" << std::endl;
    using QList_T = QList<Element_T>;
    Data_Type<QList_T> qlist = define_class_under<QList_T>(module, name)
        .template define_method("size", &QList_T::size);
    define_qlist_constructors(qlist);
    define_qlist_constructable_methods(qlist);
    define_qlist_capacity_methods(qlist);
    define_qlist_access_methods(qlist);
    define_qlist_comparable_methods(qlist);
    define_qlist_modify_methods(qlist);
    define_qlist_enumerable(qlist);
    define_qlist_to_array(qlist);
    define_qlist_to_s(qlist);
    return qlist;
}

#endif
