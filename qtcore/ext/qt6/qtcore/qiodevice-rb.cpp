#include "qiodevice-rb.hpp"
#include <qiodevice.h>

using namespace Rice;

Rice::Class rb_cQIODevice;

void Init_qiodevice(Rice::Module rb_mQt6QtCore)
{
    rb_cQIODevice =
        // RubyQt6::QtCore::QIODevice
        define_class_under<QIODevice, QObject>(rb_mQt6QtCore, "QIODevice")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QIODevice::staticMetaObject; })
            // Public Functions
            .define_method("at_end", &QIODevice::atEnd)
            .define_method("bytes_available", &QIODevice::bytesAvailable)
            .define_method("bytes_to_write", &QIODevice::bytesToWrite)
            .define_method("can_read_line", &QIODevice::canReadLine)
            .define_method("close", &QIODevice::close)
            .define_method("commit_transaction", &QIODevice::commitTransaction)
            .define_method("current_read_channel", &QIODevice::currentReadChannel)
            .define_method("current_write_channel", &QIODevice::currentWriteChannel)
            .define_method("error_string", &QIODevice::errorString)
            .define_method("get_char", &QIODevice::getChar, Arg("c"))
            .define_method("open?", &QIODevice::isOpen)
            .define_method("readable?", &QIODevice::isReadable)
            .define_method("sequential?", &QIODevice::isSequential)
            .define_method("text_mode_enabled?", &QIODevice::isTextModeEnabled)
            .define_method("transaction_started?", &QIODevice::isTransactionStarted)
            .define_method("writable?", &QIODevice::isWritable)
            .define_method("open", &QIODevice::open, Arg("mode"))
            .define_method("open_mode", &QIODevice::openMode)
            .define_method<QByteArray (QIODevice::*)(qint64)>("peek", &QIODevice::peek, Arg("maxlen"))
            .define_method<qint64 (QIODevice::*)(char *, qint64)>("peek", &QIODevice::peek, Arg("data"), Arg("maxlen"))
            .define_method("pos", &QIODevice::pos)
            .define_method("put_char", &QIODevice::putChar, Arg("c"))
            .define_method<QByteArray (QIODevice::*)(qint64)>("read", &QIODevice::read, Arg("maxlen"))
            .define_method<qint64 (QIODevice::*)(char *, qint64)>("read", &QIODevice::read, Arg("data"), Arg("maxlen"))
            .define_method("read_all", &QIODevice::readAll)
            .define_method("read_channel_count", &QIODevice::readChannelCount)
            .define_method<QByteArray (QIODevice::*)(qint64)>("read_line", &QIODevice::readLine, Arg("maxlen") = static_cast<qint64>(0))
            .define_method<qint64 (QIODevice::*)(char *, qint64)>("read_line", &QIODevice::readLine, Arg("data"), Arg("maxlen"))
            .define_method<QByteArrayView (QIODevice::*)(QSpan<char>)>("read_line_into", &QIODevice::readLineInto, Arg("buffer"))
            .define_method<QByteArrayView (QIODevice::*)(QSpan<std::byte>)>("read_line_into", &QIODevice::readLineInto, Arg("buffer"))
            .define_method<QByteArrayView (QIODevice::*)(QSpan<uchar>)>("read_line_into", &QIODevice::readLineInto, Arg("buffer"))
            .define_method<bool (QIODevice::*)(QByteArray *, qint64)>("read_line_into", &QIODevice::readLineInto, Arg("result"), Arg("maxlen") = static_cast<qint64>(0))
            .define_method("reset", &QIODevice::reset)
            .define_method("rollback_transaction", &QIODevice::rollbackTransaction)
            .define_method("seek", &QIODevice::seek, Arg("pos"))
            .define_method("set_current_read_channel", &QIODevice::setCurrentReadChannel, Arg("channel"))
            .define_method("set_current_write_channel", &QIODevice::setCurrentWriteChannel, Arg("channel"))
            .define_method("set_text_mode_enabled", &QIODevice::setTextModeEnabled, Arg("enabled"))
            .define_method("size", &QIODevice::size)
            .define_method("skip", &QIODevice::skip, Arg("max_size"))
            .define_method("start_transaction", &QIODevice::startTransaction)
            .define_method("unget_char", &QIODevice::ungetChar, Arg("c"))
            .define_method("wait_for_bytes_written", &QIODevice::waitForBytesWritten, Arg("msecs"))
            .define_method("wait_for_ready_read", &QIODevice::waitForReadyRead, Arg("msecs"))
            .define_method<qint64 (QIODevice::*)(const QByteArray &)>("write", &QIODevice::write, Arg("data"))
            .define_method<qint64 (QIODevice::*)(const char *)>("write", &QIODevice::write, Arg("data"))
            .define_method<qint64 (QIODevice::*)(const char *, qint64)>("write", &QIODevice::write, Arg("data"), Arg("len"))
            .define_method("write_channel_count", &QIODevice::writeChannelCount)
            // Signals
            .define_method("about_to_close", &QIODevice::aboutToClose)
            .define_method("bytes_written", &QIODevice::bytesWritten, Arg("bytes"))
            .define_method("channel_bytes_written", &QIODevice::channelBytesWritten, Arg("channel"), Arg("bytes"))
            .define_method("channel_ready_read", &QIODevice::channelReadyRead, Arg("channel"))
            .define_method("read_channel_finished", &QIODevice::readChannelFinished)
            .define_method("ready_read", &QIODevice::readyRead);
}
