#include "qprinter-rb.hpp"
#include <qprinter.h>
#include <rice/qt6/qenum.hpp>

#include <QPaintEngine>
#include <QPrintEngine>
#include <QPrinterInfo>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPrinter;

void Init_qprinter(Module rb_mQt6QtPrintSupport)
{
    rb_cQPrinter =
        // RubyQt6::QtPrintSupport::QPrinter
        define_class_under<QPrinter, QPagedPaintDevice>(rb_mQt6QtPrintSupport, "QPrinter")
            // Constructor
            .define_constructor(Constructor<QPrinter>())
            .define_constructor(Constructor<QPrinter, QPrinter::PrinterMode>(), Arg("mode"))
            .define_constructor(Constructor<QPrinter, const QPrinterInfo &>(), Arg("printer"))
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

    Data_Type<QPrinter::ColorMode> rb_cQPrinterColorMode =
        // RubyQt6::QtPrintSupport::QPrinter::ColorMode
        define_qenum_under<QPrinter::ColorMode>(rb_cQPrinter, "ColorMode");
        define_qenum_value_under(rb_cQPrinterColorMode, "GrayScale", QPrinter::ColorMode::GrayScale);
        define_qenum_value_under(rb_cQPrinterColorMode, "Color", QPrinter::ColorMode::Color);

    Data_Type<QPrinter::DuplexMode> rb_cQPrinterDuplexMode =
        // RubyQt6::QtPrintSupport::QPrinter::DuplexMode
        define_qenum_under<QPrinter::DuplexMode>(rb_cQPrinter, "DuplexMode");
        define_qenum_value_under(rb_cQPrinterDuplexMode, "DuplexNone", QPrinter::DuplexMode::DuplexNone);
        define_qenum_value_under(rb_cQPrinterDuplexMode, "DuplexAuto", QPrinter::DuplexMode::DuplexAuto);
        define_qenum_value_under(rb_cQPrinterDuplexMode, "DuplexLongSide", QPrinter::DuplexMode::DuplexLongSide);
        define_qenum_value_under(rb_cQPrinterDuplexMode, "DuplexShortSide", QPrinter::DuplexMode::DuplexShortSide);

    Data_Type<QPrinter::OutputFormat> rb_cQPrinterOutputFormat =
        // RubyQt6::QtPrintSupport::QPrinter::OutputFormat
        define_qenum_under<QPrinter::OutputFormat>(rb_cQPrinter, "OutputFormat");
        define_qenum_value_under(rb_cQPrinterOutputFormat, "NativeFormat", QPrinter::OutputFormat::NativeFormat);
        define_qenum_value_under(rb_cQPrinterOutputFormat, "PdfFormat", QPrinter::OutputFormat::PdfFormat);

    Data_Type<QPrinter::PageOrder> rb_cQPrinterPageOrder =
        // RubyQt6::QtPrintSupport::QPrinter::PageOrder
        define_qenum_under<QPrinter::PageOrder>(rb_cQPrinter, "PageOrder");
        define_qenum_value_under(rb_cQPrinterPageOrder, "FirstPageFirst", QPrinter::PageOrder::FirstPageFirst);
        define_qenum_value_under(rb_cQPrinterPageOrder, "LastPageFirst", QPrinter::PageOrder::LastPageFirst);

    Data_Type<QPrinter::PaperSource> rb_cQPrinterPaperSource =
        // RubyQt6::QtPrintSupport::QPrinter::PaperSource
        define_qenum_under<QPrinter::PaperSource>(rb_cQPrinter, "PaperSource");
        define_qenum_value_under(rb_cQPrinterPaperSource, "OnlyOne", QPrinter::PaperSource::OnlyOne);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Lower", QPrinter::PaperSource::Lower);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Middle", QPrinter::PaperSource::Middle);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Manual", QPrinter::PaperSource::Manual);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Envelope", QPrinter::PaperSource::Envelope);
        define_qenum_value_under(rb_cQPrinterPaperSource, "EnvelopeManual", QPrinter::PaperSource::EnvelopeManual);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Auto", QPrinter::PaperSource::Auto);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Tractor", QPrinter::PaperSource::Tractor);
        define_qenum_value_under(rb_cQPrinterPaperSource, "SmallFormat", QPrinter::PaperSource::SmallFormat);
        define_qenum_value_under(rb_cQPrinterPaperSource, "LargeFormat", QPrinter::PaperSource::LargeFormat);
        define_qenum_value_under(rb_cQPrinterPaperSource, "LargeCapacity", QPrinter::PaperSource::LargeCapacity);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Cassette", QPrinter::PaperSource::Cassette);
        define_qenum_value_under(rb_cQPrinterPaperSource, "FormSource", QPrinter::PaperSource::FormSource);
        define_qenum_value_under(rb_cQPrinterPaperSource, "MaxPageSource", QPrinter::PaperSource::MaxPageSource);
        define_qenum_value_under(rb_cQPrinterPaperSource, "CustomSource", QPrinter::PaperSource::CustomSource);
        define_qenum_value_under(rb_cQPrinterPaperSource, "LastPaperSource", QPrinter::PaperSource::LastPaperSource);
        define_qenum_value_under(rb_cQPrinterPaperSource, "Upper", QPrinter::PaperSource::Upper);

    Data_Type<QPrinter::PrintRange> rb_cQPrinterPrintRange =
        // RubyQt6::QtPrintSupport::QPrinter::PrintRange
        define_qenum_under<QPrinter::PrintRange>(rb_cQPrinter, "PrintRange");
        define_qenum_value_under(rb_cQPrinterPrintRange, "AllPages", QPrinter::PrintRange::AllPages);
        define_qenum_value_under(rb_cQPrinterPrintRange, "Selection", QPrinter::PrintRange::Selection);
        define_qenum_value_under(rb_cQPrinterPrintRange, "PageRange", QPrinter::PrintRange::PageRange);
        define_qenum_value_under(rb_cQPrinterPrintRange, "CurrentPage", QPrinter::PrintRange::CurrentPage);

    Data_Type<QPrinter::PrinterMode> rb_cQPrinterPrinterMode =
        // RubyQt6::QtPrintSupport::QPrinter::PrinterMode
        define_qenum_under<QPrinter::PrinterMode>(rb_cQPrinter, "PrinterMode");
        define_qenum_value_under(rb_cQPrinterPrinterMode, "ScreenResolution", QPrinter::PrinterMode::ScreenResolution);
        define_qenum_value_under(rb_cQPrinterPrinterMode, "PrinterResolution", QPrinter::PrinterMode::PrinterResolution);
        define_qenum_value_under(rb_cQPrinterPrinterMode, "HighResolution", QPrinter::PrinterMode::HighResolution);

    Data_Type<QPrinter::PrinterState> rb_cQPrinterPrinterState =
        // RubyQt6::QtPrintSupport::QPrinter::PrinterState
        define_qenum_under<QPrinter::PrinterState>(rb_cQPrinter, "PrinterState");
        define_qenum_value_under(rb_cQPrinterPrinterState, "Idle", QPrinter::PrinterState::Idle);
        define_qenum_value_under(rb_cQPrinterPrinterState, "Active", QPrinter::PrinterState::Active);
        define_qenum_value_under(rb_cQPrinterPrinterState, "Aborted", QPrinter::PrinterState::Aborted);
        define_qenum_value_under(rb_cQPrinterPrinterState, "Error", QPrinter::PrinterState::Error);

    Data_Type<QPrinter::Unit> rb_cQPrinterUnit =
        // RubyQt6::QtPrintSupport::QPrinter::Unit
        define_qenum_under<QPrinter::Unit>(rb_cQPrinter, "Unit");
        define_qenum_value_under(rb_cQPrinterUnit, "Millimeter", QPrinter::Unit::Millimeter);
        define_qenum_value_under(rb_cQPrinterUnit, "Point", QPrinter::Unit::Point);
        define_qenum_value_under(rb_cQPrinterUnit, "Inch", QPrinter::Unit::Inch);
        define_qenum_value_under(rb_cQPrinterUnit, "Pica", QPrinter::Unit::Pica);
        define_qenum_value_under(rb_cQPrinterUnit, "Didot", QPrinter::Unit::Didot);
        define_qenum_value_under(rb_cQPrinterUnit, "Cicero", QPrinter::Unit::Cicero);
        define_qenum_value_under(rb_cQPrinterUnit, "DevicePixel", QPrinter::Unit::DevicePixel);
}
