#include "qcameradevice-rb.hpp"
#include <qcameradevice.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCameraDevice;

void Init_qcameradevice(Module rb_mQt6QtMultimedia)
{
    rb_cQCameraDevice =
        // RubyQt6::QtMultimedia::QCameraDevice
        define_class_under<QCameraDevice>(rb_mQt6QtMultimedia, "QCameraDevice")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QCameraDevice *lhs, QCameraDevice *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QCameraDevice>(); })
            .define_singleton_function("_qvariant_from_value", [](const QCameraDevice &value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QCameraDevice { return qvariant.value<QCameraDevice>(); })
            // Constructor
            .define_constructor(Constructor<QCameraDevice>())
            // Public Functions
            .define_method("correction_angle", &QCameraDevice::correctionAngle)
            .define_method("description", &QCameraDevice::description)
            .define_method("id", &QCameraDevice::id)
            .define_method("default?", &QCameraDevice::isDefault)
            .define_method("null?", &QCameraDevice::isNull)
            .define_method("photo_resolutions", &QCameraDevice::photoResolutions)
            .define_method("position", &QCameraDevice::position)
            .define_method("video_formats", &QCameraDevice::videoFormats);

    Data_Type<QCameraDevice::Position> rb_cQCameraDevicePosition =
        // RubyQt6::QtMultimedia::QCameraDevice::Position
        define_qenum_under<QCameraDevice::Position>(rb_cQCameraDevice, "Position");
        define_qenum_value_under(rb_cQCameraDevicePosition, "UnspecifiedPosition", QCameraDevice::Position::UnspecifiedPosition);
        define_qenum_value_under(rb_cQCameraDevicePosition, "BackFace", QCameraDevice::Position::BackFace);
        define_qenum_value_under(rb_cQCameraDevicePosition, "FrontFace", QCameraDevice::Position::FrontFace);
}
