#include "qtextstream-rb.hpp"
#include <qtextstream.h>

#include <QIODevice>
#include <QLocale>

using namespace Rice;

Rice::Class rb_cQTextStream;

void Init_qtextstream(Rice::Module rb_mQt6QtCore)
{
    rb_cQTextStream =
        // RubyQt6::QtCore::QTextStream
        define_class_under<QTextStream, QIODeviceBase>(rb_mQt6QtCore, "QTextStream")
            // Constructor
            .define_constructor(Constructor<QTextStream>())
            .define_constructor(Constructor<QTextStream, QIODevice *>(), Arg("device"))
            // Public Functions
            .define_method("at_end", &QTextStream::atEnd)
            .define_method("auto_detect_unicode", &QTextStream::autoDetectUnicode)
            .define_method("device", &QTextStream::device)
            .define_method("encoding", &QTextStream::encoding)
            .define_method("field_alignment", &QTextStream::fieldAlignment)
            .define_method("field_width", &QTextStream::fieldWidth)
            .define_method("flush", &QTextStream::flush)
            .define_method("generate_byte_order_mark", &QTextStream::generateByteOrderMark)
            .define_method("integer_base", &QTextStream::integerBase)
            .define_method("locale", &QTextStream::locale)
            .define_method("number_flags", &QTextStream::numberFlags)
            .define_method("pad_char", &QTextStream::padChar)
            .define_method("pos", &QTextStream::pos)
            .define_method("read", &QTextStream::read, Arg("maxlen"))
            .define_method("read_all", &QTextStream::readAll)
            .define_method("read_line", &QTextStream::readLine, Arg("maxlen") = static_cast<qint64>(0))
            .define_method("read_line_into", &QTextStream::readLineInto, Arg("line"), Arg("maxlen") = static_cast<qint64>(0))
            .define_method("real_number_notation", &QTextStream::realNumberNotation)
            .define_method("real_number_precision", &QTextStream::realNumberPrecision)
            .define_method("reset", &QTextStream::reset)
            .define_method("reset_status", &QTextStream::resetStatus)
            .define_method("seek", &QTextStream::seek, Arg("pos"))
            .define_method("set_auto_detect_unicode", &QTextStream::setAutoDetectUnicode, Arg("enabled"))
            .define_method("set_device", &QTextStream::setDevice, Arg("device"))
            .define_method("set_encoding", &QTextStream::setEncoding, Arg("encoding"))
            .define_method("set_field_alignment", &QTextStream::setFieldAlignment, Arg("alignment"))
            .define_method("set_field_width", &QTextStream::setFieldWidth, Arg("width"))
            .define_method("set_generate_byte_order_mark", &QTextStream::setGenerateByteOrderMark, Arg("generate"))
            .define_method("set_integer_base", &QTextStream::setIntegerBase, Arg("base"))
            .define_method("set_locale", &QTextStream::setLocale, Arg("locale"))
            .define_method("set_number_flags", &QTextStream::setNumberFlags, Arg("flags"))
            .define_method("set_pad_char", &QTextStream::setPadChar, Arg("ch"))
            .define_method("set_real_number_notation", &QTextStream::setRealNumberNotation, Arg("notation"))
            .define_method("set_real_number_precision", &QTextStream::setRealNumberPrecision, Arg("precision"))
            .define_method("set_status", &QTextStream::setStatus, Arg("status"))
            .define_method("set_string", &QTextStream::setString, Arg("string"), Arg("open_mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::OpenModeFlag::ReadWrite))
            .define_method("skip_white_space", &QTextStream::skipWhiteSpace)
            .define_method("status", &QTextStream::status)
            .define_method("string", &QTextStream::string);

    Enum<QTextStream::FieldAlignment> rb_cQTextStreamFieldAlignment =
        // RubyQt6::QtCore::QTextStream::FieldAlignment
        define_enum_under<QTextStream::FieldAlignment>("FieldAlignment", rb_cQTextStream)
            .define_value("AlignLeft", QTextStream::FieldAlignment::AlignLeft)
            .define_value("AlignRight", QTextStream::FieldAlignment::AlignRight)
            .define_value("AlignCenter", QTextStream::FieldAlignment::AlignCenter)
            .define_value("AlignAccountingStyle", QTextStream::FieldAlignment::AlignAccountingStyle);

    Enum<QTextStream::NumberFlag> rb_cQTextStreamNumberFlag =
        // RubyQt6::QtCore::QTextStream::NumberFlag
        define_enum_under<QTextStream::NumberFlag>("NumberFlag", rb_cQTextStream)
            .define_value("ShowBase", QTextStream::NumberFlag::ShowBase)
            .define_value("ForcePoint", QTextStream::NumberFlag::ForcePoint)
            .define_value("ForceSign", QTextStream::NumberFlag::ForceSign)
            .define_value("UppercaseBase", QTextStream::NumberFlag::UppercaseBase)
            .define_value("UppercaseDigits", QTextStream::NumberFlag::UppercaseDigits);

    Enum<QTextStream::RealNumberNotation> rb_cQTextStreamRealNumberNotation =
        // RubyQt6::QtCore::QTextStream::RealNumberNotation
        define_enum_under<QTextStream::RealNumberNotation>("RealNumberNotation", rb_cQTextStream)
            .define_value("SmartNotation", QTextStream::RealNumberNotation::SmartNotation)
            .define_value("FixedNotation", QTextStream::RealNumberNotation::FixedNotation)
            .define_value("ScientificNotation", QTextStream::RealNumberNotation::ScientificNotation);

    Enum<QTextStream::Status> rb_cQTextStreamStatus =
        // RubyQt6::QtCore::QTextStream::Status
        define_enum_under<QTextStream::Status>("Status", rb_cQTextStream)
            .define_value("Ok", QTextStream::Status::Ok)
            .define_value("ReadPastEnd", QTextStream::Status::ReadPastEnd)
            .define_value("ReadCorruptData", QTextStream::Status::ReadCorruptData)
            .define_value("WriteFailed", QTextStream::Status::WriteFailed);
}
