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
            .define_singleton_function("_device_pixel_ratio_f_scale", &QPaintDevice::devicePixelRatioFScale)
            .define_singleton_function("_encode_metric_f", &QPaintDevice::encodeMetricF, Arg("metric"), Arg("value"))
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
            .define_method("_paint_engine", &QPaintDevice::paintEngine)
            .define_method("_dev_type", &QPaintDevice::devType);

    Enum<QPaintDevice::PaintDeviceMetric> rb_cQPaintDevicePaintDeviceMetric =
        // RubyQt6::QtGui::QPaintDevice::PaintDeviceMetric
        define_enum_under<QPaintDevice::PaintDeviceMetric>("PaintDeviceMetric", rb_cQPaintDevice)
            .define_value("PdmWidth", QPaintDevice::PaintDeviceMetric::PdmWidth)
            .define_value("PdmHeight", QPaintDevice::PaintDeviceMetric::PdmHeight)
            .define_value("PdmWidthMM", QPaintDevice::PaintDeviceMetric::PdmWidthMM)
            .define_value("PdmHeightMM", QPaintDevice::PaintDeviceMetric::PdmHeightMM)
            .define_value("PdmNumColors", QPaintDevice::PaintDeviceMetric::PdmNumColors)
            .define_value("PdmDepth", QPaintDevice::PaintDeviceMetric::PdmDepth)
            .define_value("PdmDpiX", QPaintDevice::PaintDeviceMetric::PdmDpiX)
            .define_value("PdmDpiY", QPaintDevice::PaintDeviceMetric::PdmDpiY)
            .define_value("PdmPhysicalDpiX", QPaintDevice::PaintDeviceMetric::PdmPhysicalDpiX)
            .define_value("PdmPhysicalDpiY", QPaintDevice::PaintDeviceMetric::PdmPhysicalDpiY)
            .define_value("PdmDevicePixelRatio", QPaintDevice::PaintDeviceMetric::PdmDevicePixelRatio)
            .define_value("PdmDevicePixelRatioScaled", QPaintDevice::PaintDeviceMetric::PdmDevicePixelRatioScaled)
            .define_value("PdmDevicePixelRatioF_EncodedA", QPaintDevice::PaintDeviceMetric::PdmDevicePixelRatioF_EncodedA)
            .define_value("PdmDevicePixelRatioF_EncodedB", QPaintDevice::PaintDeviceMetric::PdmDevicePixelRatioF_EncodedB);
}
