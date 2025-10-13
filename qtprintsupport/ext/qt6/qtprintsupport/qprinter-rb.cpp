#include "qprinter-rb.hpp"
#include <qprinter.h>

#include <QPaintEngine>
#include <QPrintEngine>
#include <QPrinterInfo>

using namespace Rice;

Rice::Class rb_cQPrinter;

void Init_qprinter(Rice::Module rb_mQt6QtPrintSupport)
{
    rb_cQPrinter =
        // RubyQt6::QtPrintSupport::QPrinter
        define_class_under<QPrinter, QPagedPaintDevice>(rb_mQt6QtPrintSupport, "QPrinter")
            // Constructor
            .define_constructor(Constructor<QPrinter, QPrinter::PrinterMode>(), Arg("mode"))
            .define_constructor(Constructor<QPrinter, const QPrinterInfo &, QPrinter::PrinterMode>(), Arg("printer"), Arg("mode"))
            // Public Functions
            .define_method("abort", &QPrinter::abort)
            .define_method("collate_copies", &QPrinter::collateCopies)
            .define_method("color_mode", &QPrinter::colorMode)
            .define_method("copy_count", &QPrinter::copyCount)
            .define_method("creator", &QPrinter::creator)
            .define_method("dev_type", &QPrinter::devType)
            .define_method("doc_name", &QPrinter::docName)
            .define_method("duplex", &QPrinter::duplex)
            .define_method("font_embedding_enabled", &QPrinter::fontEmbeddingEnabled)
            .define_method("from_page", &QPrinter::fromPage)
            .define_method("full_page", &QPrinter::fullPage)
            .define_method("valid?", &QPrinter::isValid)
            .define_method("new_page", &QPrinter::newPage)
            .define_method("output_file_name", &QPrinter::outputFileName)
            .define_method("output_format", &QPrinter::outputFormat)
            .define_method("page_order", &QPrinter::pageOrder)
            .define_method("page_rect", &QPrinter::pageRect, Arg("unit"))
            .define_method("paper_rect", &QPrinter::paperRect, Arg("unit"))
            .define_method("paper_source", &QPrinter::paperSource)
            .define_method("pdf_version", &QPrinter::pdfVersion)
            .define_method("print_engine", &QPrinter::printEngine)
            .define_method("print_program", &QPrinter::printProgram)
            .define_method("print_range", &QPrinter::printRange)
            .define_method("printer_name", &QPrinter::printerName)
            .define_method("printer_selection_option", &QPrinter::printerSelectionOption)
            .define_method("printer_state", &QPrinter::printerState)
            .define_method("resolution", &QPrinter::resolution)
            .define_method("set_collate_copies", &QPrinter::setCollateCopies, Arg("collate"))
            .define_method("set_color_mode", &QPrinter::setColorMode, Arg("mode"))
            .define_method("set_copy_count", &QPrinter::setCopyCount, Arg("count"))
            .define_method("set_creator", &QPrinter::setCreator, Arg("creator"))
            .define_method("set_doc_name", &QPrinter::setDocName, Arg("name"))
            .define_method("set_duplex", &QPrinter::setDuplex, Arg("duplex"))
            .define_method("set_font_embedding_enabled", &QPrinter::setFontEmbeddingEnabled, Arg("enable"))
            .define_method("set_from_to", &QPrinter::setFromTo, Arg("from_page"), Arg("to_page"))
            .define_method("set_full_page", &QPrinter::setFullPage, Arg("fp"))
            .define_method("set_output_file_name", &QPrinter::setOutputFileName, Arg("file_name"))
            .define_method("set_output_format", &QPrinter::setOutputFormat, Arg("format"))
            .define_method("set_page_order", &QPrinter::setPageOrder, Arg("page_order"))
            .define_method("set_paper_source", &QPrinter::setPaperSource, Arg("paper_source"))
            .define_method("set_pdf_version", &QPrinter::setPdfVersion, Arg("version"))
            .define_method("set_print_program", &QPrinter::setPrintProgram, Arg("print_prog"))
            .define_method("set_print_range", &QPrinter::setPrintRange, Arg("range"))
            .define_method("set_printer_name", &QPrinter::setPrinterName, Arg("name"))
            .define_method("set_printer_selection_option", &QPrinter::setPrinterSelectionOption, Arg("option"))
            .define_method("set_resolution", &QPrinter::setResolution, Arg("resolution"))
            .define_method("supported_resolutions", &QPrinter::supportedResolutions)
            .define_method("supports_multiple_copies", &QPrinter::supportsMultipleCopies)
            .define_method("to_page", &QPrinter::toPage);

    Enum<QPrinter::ColorMode> rb_cQPrinterColorMode =
        // RubyQt6::QtPrintSupport::QPrinter::ColorMode
        define_enum_under<QPrinter::ColorMode>("ColorMode", rb_cQPrinter)
            .define_value("GrayScale", QPrinter::ColorMode::GrayScale)
            .define_value("Color", QPrinter::ColorMode::Color);

    Enum<QPrinter::DuplexMode> rb_cQPrinterDuplexMode =
        // RubyQt6::QtPrintSupport::QPrinter::DuplexMode
        define_enum_under<QPrinter::DuplexMode>("DuplexMode", rb_cQPrinter)
            .define_value("DuplexNone", QPrinter::DuplexMode::DuplexNone)
            .define_value("DuplexAuto", QPrinter::DuplexMode::DuplexAuto)
            .define_value("DuplexLongSide", QPrinter::DuplexMode::DuplexLongSide)
            .define_value("DuplexShortSide", QPrinter::DuplexMode::DuplexShortSide);

    Enum<QPrinter::OutputFormat> rb_cQPrinterOutputFormat =
        // RubyQt6::QtPrintSupport::QPrinter::OutputFormat
        define_enum_under<QPrinter::OutputFormat>("OutputFormat", rb_cQPrinter)
            .define_value("NativeFormat", QPrinter::OutputFormat::NativeFormat)
            .define_value("PdfFormat", QPrinter::OutputFormat::PdfFormat);

    Enum<QPrinter::PageOrder> rb_cQPrinterPageOrder =
        // RubyQt6::QtPrintSupport::QPrinter::PageOrder
        define_enum_under<QPrinter::PageOrder>("PageOrder", rb_cQPrinter)
            .define_value("FirstPageFirst", QPrinter::PageOrder::FirstPageFirst)
            .define_value("LastPageFirst", QPrinter::PageOrder::LastPageFirst);

    Enum<QPrinter::PaperSource> rb_cQPrinterPaperSource =
        // RubyQt6::QtPrintSupport::QPrinter::PaperSource
        define_enum_under<QPrinter::PaperSource>("PaperSource", rb_cQPrinter)
            .define_value("OnlyOne", QPrinter::PaperSource::OnlyOne)
            .define_value("Lower", QPrinter::PaperSource::Lower)
            .define_value("Middle", QPrinter::PaperSource::Middle)
            .define_value("Manual", QPrinter::PaperSource::Manual)
            .define_value("Envelope", QPrinter::PaperSource::Envelope)
            .define_value("EnvelopeManual", QPrinter::PaperSource::EnvelopeManual)
            .define_value("Auto", QPrinter::PaperSource::Auto)
            .define_value("Tractor", QPrinter::PaperSource::Tractor)
            .define_value("SmallFormat", QPrinter::PaperSource::SmallFormat)
            .define_value("LargeFormat", QPrinter::PaperSource::LargeFormat)
            .define_value("LargeCapacity", QPrinter::PaperSource::LargeCapacity)
            .define_value("Cassette", QPrinter::PaperSource::Cassette)
            .define_value("FormSource", QPrinter::PaperSource::FormSource)
            .define_value("MaxPageSource", QPrinter::PaperSource::MaxPageSource)
            .define_value("CustomSource", QPrinter::PaperSource::CustomSource)
            .define_value("LastPaperSource", QPrinter::PaperSource::LastPaperSource)
            .define_value("Upper", QPrinter::PaperSource::Upper);

    Enum<QPrinter::PrintRange> rb_cQPrinterPrintRange =
        // RubyQt6::QtPrintSupport::QPrinter::PrintRange
        define_enum_under<QPrinter::PrintRange>("PrintRange", rb_cQPrinter)
            .define_value("AllPages", QPrinter::PrintRange::AllPages)
            .define_value("Selection", QPrinter::PrintRange::Selection)
            .define_value("PageRange", QPrinter::PrintRange::PageRange)
            .define_value("CurrentPage", QPrinter::PrintRange::CurrentPage);

    Enum<QPrinter::PrinterMode> rb_cQPrinterPrinterMode =
        // RubyQt6::QtPrintSupport::QPrinter::PrinterMode
        define_enum_under<QPrinter::PrinterMode>("PrinterMode", rb_cQPrinter)
            .define_value("ScreenResolution", QPrinter::PrinterMode::ScreenResolution)
            .define_value("PrinterResolution", QPrinter::PrinterMode::PrinterResolution)
            .define_value("HighResolution", QPrinter::PrinterMode::HighResolution);

    Enum<QPrinter::PrinterState> rb_cQPrinterPrinterState =
        // RubyQt6::QtPrintSupport::QPrinter::PrinterState
        define_enum_under<QPrinter::PrinterState>("PrinterState", rb_cQPrinter)
            .define_value("Idle", QPrinter::PrinterState::Idle)
            .define_value("Active", QPrinter::PrinterState::Active)
            .define_value("Aborted", QPrinter::PrinterState::Aborted)
            .define_value("Error", QPrinter::PrinterState::Error);

    Enum<QPrinter::Unit> rb_cQPrinterUnit =
        // RubyQt6::QtPrintSupport::QPrinter::Unit
        define_enum_under<QPrinter::Unit>("Unit", rb_cQPrinter)
            .define_value("Millimeter", QPrinter::Unit::Millimeter)
            .define_value("Point", QPrinter::Unit::Point)
            .define_value("Inch", QPrinter::Unit::Inch)
            .define_value("Pica", QPrinter::Unit::Pica)
            .define_value("Didot", QPrinter::Unit::Didot)
            .define_value("Cicero", QPrinter::Unit::Cicero)
            .define_value("DevicePixel", QPrinter::Unit::DevicePixel);
}
