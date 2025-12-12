#include "qtextstream-rb.hpp"
#include <qtextstream.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QIODevice>
#include <QLocale>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextStream;

void Init_qtextstream(Module rb_mQt6QtCore)
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
            .define_method("string", &QTextStream::string)
            .define_method<QTextStream &(QTextStream::*)(const char *)>("<<", &QTextStream::operator<<, Arg("s"))
            .define_method<QTextStream &(QTextStream::*)(const QString &)>("<<", &QTextStream::operator<<, Arg("s"));

    Data_Type<QTextStream::FieldAlignment> rb_cQTextStreamFieldAlignment =
        // RubyQt6::QtCore::QTextStream::FieldAlignment
        define_qenum_under<QTextStream::FieldAlignment>(rb_cQTextStream, "FieldAlignment");
        define_qenum_value_under(rb_cQTextStreamFieldAlignment, "AlignLeft", QTextStream::FieldAlignment::AlignLeft);
        define_qenum_value_under(rb_cQTextStreamFieldAlignment, "AlignRight", QTextStream::FieldAlignment::AlignRight);
        define_qenum_value_under(rb_cQTextStreamFieldAlignment, "AlignCenter", QTextStream::FieldAlignment::AlignCenter);
        define_qenum_value_under(rb_cQTextStreamFieldAlignment, "AlignAccountingStyle", QTextStream::FieldAlignment::AlignAccountingStyle);

    Data_Type<QTextStream::NumberFlag> rb_cQTextStreamNumberFlag =
        // RubyQt6::QtCore::QTextStream::NumberFlag
        define_qenum_under<QTextStream::NumberFlag>(rb_cQTextStream, "NumberFlag");
        define_qenum_value_under(rb_cQTextStreamNumberFlag, "ShowBase", QTextStream::NumberFlag::ShowBase);
        define_qenum_value_under(rb_cQTextStreamNumberFlag, "ForcePoint", QTextStream::NumberFlag::ForcePoint);
        define_qenum_value_under(rb_cQTextStreamNumberFlag, "ForceSign", QTextStream::NumberFlag::ForceSign);
        define_qenum_value_under(rb_cQTextStreamNumberFlag, "UppercaseBase", QTextStream::NumberFlag::UppercaseBase);
        define_qenum_value_under(rb_cQTextStreamNumberFlag, "UppercaseDigits", QTextStream::NumberFlag::UppercaseDigits);

    Data_Type<QTextStream::RealNumberNotation> rb_cQTextStreamRealNumberNotation =
        // RubyQt6::QtCore::QTextStream::RealNumberNotation
        define_qenum_under<QTextStream::RealNumberNotation>(rb_cQTextStream, "RealNumberNotation");
        define_qenum_value_under(rb_cQTextStreamRealNumberNotation, "SmartNotation", QTextStream::RealNumberNotation::SmartNotation);
        define_qenum_value_under(rb_cQTextStreamRealNumberNotation, "FixedNotation", QTextStream::RealNumberNotation::FixedNotation);
        define_qenum_value_under(rb_cQTextStreamRealNumberNotation, "ScientificNotation", QTextStream::RealNumberNotation::ScientificNotation);

    Data_Type<QTextStream::Status> rb_cQTextStreamStatus =
        // RubyQt6::QtCore::QTextStream::Status
        define_qenum_under<QTextStream::Status>(rb_cQTextStream, "Status");
        define_qenum_value_under(rb_cQTextStreamStatus, "Ok", QTextStream::Status::Ok);
        define_qenum_value_under(rb_cQTextStreamStatus, "ReadPastEnd", QTextStream::Status::ReadPastEnd);
        define_qenum_value_under(rb_cQTextStreamStatus, "ReadCorruptData", QTextStream::Status::ReadCorruptData);
        define_qenum_value_under(rb_cQTextStreamStatus, "WriteFailed", QTextStream::Status::WriteFailed);

    Data_Type<QFlags<QTextStream::NumberFlag>> rb_cQTextStreamNumberFlags =
        // RubyQt6::QtCore::QTextStream::NumberFlags
        define_qflags_under<QTextStream::NumberFlag>(rb_cQTextStream, "NumberFlags");
}
