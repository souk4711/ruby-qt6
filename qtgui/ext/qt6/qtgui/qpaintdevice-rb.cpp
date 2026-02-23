#include "qpaintdevice-rb.hpp"
#include <qpaintdevice.h>

#include <QPaintEngine>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPaintDevice;

void Init_qpaintdevice(Module rb_mQt6QtGui)
{
    rb_cQPaintDevice =
        // RubyQt6::QtGui::QPaintDevice
        define_qlass_under<QPaintDevice>(rb_mQt6QtGui, "QPaintDevice")
            // Public Functions
            .define_method("color_count", &QPaintDevice::colorCount)
            .define_method("depth", &QPaintDevice::depth)
            .define_method("dev_type", &QPaintDevice::devType)
            .define_method("device_pixel_ratio", &QPaintDevice::devicePixelRatio)
            .define_method("device_pixel_ratio_f", &QPaintDevice::devicePixelRatioF)
            .define_method("height", &QPaintDevice::height)
            .define_method("height_mm", &QPaintDevice::heightMM)
            .define_method("logical_dpi_x", &QPaintDevice::logicalDpiX)
            .define_method("logical_dpi_y", &QPaintDevice::logicalDpiY)
            .define_method("painting_active", &QPaintDevice::paintingActive)
            .define_method("physical_dpi_x", &QPaintDevice::physicalDpiX)
            .define_method("physical_dpi_y", &QPaintDevice::physicalDpiY)
            .define_method("width", &QPaintDevice::width)
            .define_method("width_mm", &QPaintDevice::widthMM)
            // Static Public Members
            .define_singleton_function("device_pixel_ratio_f_scale", &QPaintDevice::devicePixelRatioFScale)
            .define_singleton_function("encode_metric_f", &QPaintDevice::encodeMetricF, Arg("metric"), Arg("value"));
}
