#include "qurlquery-rb.hpp"
#include <qurlquery.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQUrlQuery;

void Init_qurlquery(Module rb_mQt6QtCore)
{
    rb_cQUrlQuery =
        // RubyQt6::QtCore::QUrlQuery
        define_class_under<QUrlQuery>(rb_mQt6QtCore, "QUrlQuery")
            // Constructor
            .define_constructor(Constructor<QUrlQuery>())
            // Public Functions
            .define_method("_add_query_item", &QUrlQuery::addQueryItem, Arg("key"), Arg("value"))
            .define_method("all_query_item_values", &QUrlQuery::allQueryItemValues, Arg("key"), Arg("encoding") = static_cast<QUrl::ComponentFormattingOptions>(QUrl::PrettyDecoded))
            .define_method("clear", &QUrlQuery::clear)
            .define_method("_has_query_item", &QUrlQuery::hasQueryItem, Arg("key"))
            .define_method("detached?", &QUrlQuery::isDetached)
            .define_method("empty?", &QUrlQuery::isEmpty)
            .define_method("query", &QUrlQuery::query, Arg("encoding") = static_cast<QUrl::ComponentFormattingOptions>(QUrl::PrettyDecoded))
            .define_method("query_item_value", &QUrlQuery::queryItemValue, Arg("key"), Arg("encoding") = static_cast<QUrl::ComponentFormattingOptions>(QUrl::PrettyDecoded))
            .define_method("query_items", &QUrlQuery::queryItems, Arg("encoding") = static_cast<QUrl::ComponentFormattingOptions>(QUrl::PrettyDecoded))
            .define_method("query_pair_delimiter", &QUrlQuery::queryPairDelimiter)
            .define_method("query_value_delimiter", &QUrlQuery::queryValueDelimiter)
            .define_method("_remove_all_query_items", &QUrlQuery::removeAllQueryItems, Arg("key"))
            .define_method("_remove_query_item", &QUrlQuery::removeQueryItem, Arg("key"))
            .define_method("_set_query", &QUrlQuery::setQuery, Arg("query"))
            .define_method("set_query_delimiters", &QUrlQuery::setQueryDelimiters, Arg("value_delimiter"), Arg("pair_delimiter"))
            .define_method("set_query_items", &QUrlQuery::setQueryItems, Arg("query"))
            .define_method("to_string", &QUrlQuery::toString, Arg("encoding") = static_cast<QUrl::ComponentFormattingOptions>(QUrl::PrettyDecoded));
}
