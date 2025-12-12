#include "qdesktopservices-rb.hpp"
#include <qdesktopservices.h>

#include <QUrl>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDesktopServices;

void Init_qdesktopservices(Module rb_mQt6QtGui)
{
    rb_cQDesktopServices =
        // RubyQt6::QtGui::QDesktopServices
        define_class_under<QDesktopServices>(rb_mQt6QtGui, "QDesktopServices")
            // Static Public Members
            .define_singleton_function("open_url", &QDesktopServices::openUrl, Arg("url"));
}
