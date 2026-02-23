#include "qmimetype-rb.hpp"
#include <qmimetype.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMimeType;

void Init_qmimetype(Module rb_mQt6QtCore)
{
    rb_cQMimeType =
        // RubyQt6::QtCore::QMimeType
        define_qlass_under<QMimeType>(rb_mQt6QtCore, "QMimeType")
            // Public Functions
            .define_method("aliases", &QMimeType::aliases)
            .define_method("all_ancestors", &QMimeType::allAncestors)
            .define_method("comment", &QMimeType::comment)
            .define_method("filter_string", &QMimeType::filterString)
            .define_method("generic_icon_name", &QMimeType::genericIconName)
            .define_method("glob_patterns", &QMimeType::globPatterns)
            .define_method("icon_name", &QMimeType::iconName)
            .define_method("inherits", &QMimeType::inherits, Arg("mime_type_name"))
            .define_method("default?", &QMimeType::isDefault)
            .define_method("valid?", &QMimeType::isValid)
            .define_method("name", &QMimeType::name)
            .define_method("parent_mime_types", &QMimeType::parentMimeTypes)
            .define_method("preferred_suffix", &QMimeType::preferredSuffix)
            .define_method("suffixes", &QMimeType::suffixes);
}
