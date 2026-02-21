#include "qpagedpaintdevice-rb.hpp"
#include <qpagedpaintdevice.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPagedPaintDevice;

void Init_qpagedpaintdevice(Module rb_mQt6QtGui)
{
    rb_cQPagedPaintDevice =
        // RubyQt6::QtGui::QPagedPaintDevice
        define_qlass_under<QPagedPaintDevice, QPaintDevice>(rb_mQt6QtGui, "QPagedPaintDevice")
            // Public Functions
            .define_method("new_page", &QPagedPaintDevice::newPage)
            .define_method("page_layout", &QPagedPaintDevice::pageLayout)
            .define_method("page_ranges", &QPagedPaintDevice::pageRanges)
            .define_method("set_page_layout", &QPagedPaintDevice::setPageLayout, Arg("page_layout"))
            .define_method("set_page_margins", &QPagedPaintDevice::setPageMargins, Arg("margins"), Arg("units") = static_cast<QPageLayout::Unit>(QPageLayout::Millimeter))
            .define_method("set_page_orientation", &QPagedPaintDevice::setPageOrientation, Arg("orientation"))
            .define_method("set_page_ranges", &QPagedPaintDevice::setPageRanges, Arg("ranges"))
            .define_method("set_page_size", &QPagedPaintDevice::setPageSize, Arg("page_size"));

    Data_Type<QPagedPaintDevice::PdfVersion> rb_cQPagedPaintDevicePdfVersion =
        // RubyQt6::QtGui::QPagedPaintDevice::PdfVersion
        define_qenum_under<QPagedPaintDevice::PdfVersion>(rb_cQPagedPaintDevice, "PdfVersion");
        define_qenum_value_under(rb_cQPagedPaintDevicePdfVersion, "PdfVersion_1_4", QPagedPaintDevice::PdfVersion::PdfVersion_1_4);
        define_qenum_value_under(rb_cQPagedPaintDevicePdfVersion, "PdfVersion_A1b", QPagedPaintDevice::PdfVersion::PdfVersion_A1b);
        define_qenum_value_under(rb_cQPagedPaintDevicePdfVersion, "PdfVersion_1_6", QPagedPaintDevice::PdfVersion::PdfVersion_1_6);
        define_qenum_value_under(rb_cQPagedPaintDevicePdfVersion, "PdfVersion_X4", QPagedPaintDevice::PdfVersion::PdfVersion_X4);
}
