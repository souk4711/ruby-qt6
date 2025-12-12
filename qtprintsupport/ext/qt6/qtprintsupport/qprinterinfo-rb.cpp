#include "qprinterinfo-rb.hpp"
#include <qprinterinfo.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPrinterInfo;

void Init_qprinterinfo(Module rb_mQt6QtPrintSupport)
{
    rb_cQPrinterInfo =
        // RubyQt6::QtPrintSupport::QPrinterInfo
        define_class_under<QPrinterInfo>(rb_mQt6QtPrintSupport, "QPrinterInfo")
            // Constructor
            .define_constructor(Constructor<QPrinterInfo>())
            .define_constructor(Constructor<QPrinterInfo, const QPrinter &>(), Arg("printer"))
            // Public Functions
            .define_method("default_color_mode", &QPrinterInfo::defaultColorMode)
            .define_method("default_duplex_mode", &QPrinterInfo::defaultDuplexMode)
            .define_method("default_page_size", &QPrinterInfo::defaultPageSize)
            .define_method("description", &QPrinterInfo::description)
            .define_method("default?", &QPrinterInfo::isDefault)
            .define_method("null?", &QPrinterInfo::isNull)
            .define_method("remote?", &QPrinterInfo::isRemote)
            .define_method("location", &QPrinterInfo::location)
            .define_method("make_and_model", &QPrinterInfo::makeAndModel)
            .define_method("maximum_physical_page_size", &QPrinterInfo::maximumPhysicalPageSize)
            .define_method("minimum_physical_page_size", &QPrinterInfo::minimumPhysicalPageSize)
            .define_method("printer_name", &QPrinterInfo::printerName)
            .define_method("state", &QPrinterInfo::state)
            .define_method("supported_color_modes", &QPrinterInfo::supportedColorModes)
            .define_method("supported_duplex_modes", &QPrinterInfo::supportedDuplexModes)
            .define_method("supported_page_sizes", &QPrinterInfo::supportedPageSizes)
            .define_method("supported_resolutions", &QPrinterInfo::supportedResolutions)
            .define_method("supports_custom_page_sizes", &QPrinterInfo::supportsCustomPageSizes)
            // Static Public Members
            .define_singleton_function("available_printer_names", &QPrinterInfo::availablePrinterNames)
            .define_singleton_function("available_printers", &QPrinterInfo::availablePrinters)
            .define_singleton_function("default_printer", &QPrinterInfo::defaultPrinter)
            .define_singleton_function("default_printer_name", &QPrinterInfo::defaultPrinterName)
            .define_singleton_function("printer_info", &QPrinterInfo::printerInfo, Arg("printer_name"));
}
