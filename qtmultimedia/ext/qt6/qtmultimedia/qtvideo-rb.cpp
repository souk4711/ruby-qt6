#include "qtvideo-rb.hpp"
#include <qtvideo.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

void Init_qtvideo(Rice::Module rb_mQt6QtMultimedia)
{
    Module rb_mQtVideo =
        // RubyQt6::QtMultimedia::QtVideo
        define_module_under(rb_mQt6QtMultimedia, "QtVideo");

    Data_Type<QtVideo::Rotation> rb_cQtVideoRotation =
        // RubyQt6::QtMultimedia::QtVideo::Rotation
        define_qenum_under<QtVideo::Rotation>(rb_mQtVideo, "Rotation");
        define_qenum_value_under(rb_cQtVideoRotation, "None", QtVideo::Rotation::None);
        define_qenum_value_under(rb_cQtVideoRotation, "Clockwise90", QtVideo::Rotation::Clockwise90);
        define_qenum_value_under(rb_cQtVideoRotation, "Clockwise180", QtVideo::Rotation::Clockwise180);
        define_qenum_value_under(rb_cQtVideoRotation, "Clockwise270", QtVideo::Rotation::Clockwise270);
}
