#include "qpaintdevice-rb.hpp"
#include <qpaintdevice.h>

#include <QPaintEngine>

using namespace Rice;

Rice::Class rb_cQPaintDevice;

void Init_qpaintdevice(Rice::Module rb_mQt6QtGui)
{
    rb_cQPaintDevice =
        // RubyQt6::QtGui::QPaintDevice
        define_class_under<QPaintDevice>(rb_mQt6QtGui, "QPaintDevice")
            .define_method("_color_count", &QPaintDevice::colorCount)
            .define_method("_depth", &QPaintDevice::depth)
            .define_method("_device_pixel_ratio", &QPaintDevice::devicePixelRatio)
            .define_method("_device_pixel_ratio_f", &QPaintDevice::devicePixelRatioF)
            .define_method("_height", &QPaintDevice::height)
            .define_method("_height_mm", &QPaintDevice::heightMM)
            .define_method("_width", &QPaintDevice::width)
            .define_method("_width_mm", &QPaintDevice::widthMM)
            .define_method("_logical_dpi_x", &QPaintDevice::logicalDpiX)
            .define_method("_logical_dpi_y", &QPaintDevice::logicalDpiY)
            .define_method("_physical_dpi_x", &QPaintDevice::physicalDpiX)
            .define_method("_physical_dpi_y", &QPaintDevice::physicalDpiY)
            .define_method("_painting_active?", &QPaintDevice::paintingActive)
            .define_method("_paint_engine", &QPaintDevice::paintEngine);
}
