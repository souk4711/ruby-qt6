#include "qurl-rb.hpp"
#include <qurl.h>

using namespace Rice;

Rice::Class rb_cQUrl;

void Init_qurl(Rice::Module rb_mQt6QtCore)
{
    rb_cQUrl =
        // RubyQt6::QtCore::QUrl
        define_class_under<QUrl>(rb_mQt6QtCore, "QUrl")
            .define_singleton_function("from_local_file", &QUrl::fromLocalFile, Arg("localfile"));
}
