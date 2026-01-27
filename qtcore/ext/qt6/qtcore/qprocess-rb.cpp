#include "qprocess-rb.hpp"
#include <qprocess.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQProcess;

void Init_qprocess(Module rb_mQt6QtCore)
{
    rb_cQProcess =
        // RubyQt6::QtCore::QProcess
        define_class_under<QProcess, QIODevice>(rb_mQt6QtCore, "QProcess")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QProcess::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QProcess, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("arguments", &QProcess::arguments)
            .define_method("bytes_to_write", &QProcess::bytesToWrite)
            .define_method("child_process_modifier", &QProcess::childProcessModifier)
            .define_method("close", &QProcess::close)
            .define_method("close_read_channel", &QProcess::closeReadChannel, Arg("channel"))
            .define_method("close_write_channel", &QProcess::closeWriteChannel)
            .define_method("environment", &QProcess::environment)
            .define_method("error", &QProcess::error)
            .define_method("exit_code", &QProcess::exitCode)
            .define_method("exit_status", &QProcess::exitStatus)
            .define_method("fail_child_process_modifier", &QProcess::failChildProcessModifier, Arg("description"), Arg("error") = static_cast<int>(0))
            .define_method("input_channel_mode", &QProcess::inputChannelMode)
            .define_method("sequential?", &QProcess::isSequential)
            .define_method("open", &QProcess::open, Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::ReadWrite))
            .define_method("process_channel_mode", &QProcess::processChannelMode)
            .define_method("process_environment", &QProcess::processEnvironment)
            .define_method("process_id", &QProcess::processId)
            .define_method("program", &QProcess::program)
            .define_method("read_all_standard_error", &QProcess::readAllStandardError)
            .define_method("read_all_standard_output", &QProcess::readAllStandardOutput)
            .define_method("read_channel", &QProcess::readChannel)
            .define_method("set_arguments", &QProcess::setArguments, Arg("arguments"))
            .define_method("set_child_process_modifier", &QProcess::setChildProcessModifier, Arg("modifier"))
            .define_method("set_environment", &QProcess::setEnvironment, Arg("environment"))
            .define_method("set_input_channel_mode", &QProcess::setInputChannelMode, Arg("mode"))
            .define_method("set_process_channel_mode", &QProcess::setProcessChannelMode, Arg("mode"))
            .define_method("set_process_environment", &QProcess::setProcessEnvironment, Arg("environment"))
            .define_method("set_program", &QProcess::setProgram, Arg("program"))
            .define_method("set_read_channel", &QProcess::setReadChannel, Arg("channel"))
            .define_method("set_standard_error_file", &QProcess::setStandardErrorFile, Arg("file_name"), Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::Truncate))
            .define_method("set_standard_input_file", &QProcess::setStandardInputFile, Arg("file_name"))
            .define_method("set_standard_output_file", &QProcess::setStandardOutputFile, Arg("file_name"), Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::Truncate))
            .define_method("set_standard_output_process", &QProcess::setStandardOutputProcess, Arg("destination"))
            .define_method("set_working_directory", &QProcess::setWorkingDirectory, Arg("dir"))
            .define_method<void (QProcess::*)(QIODeviceBase::OpenMode)>("start", &QProcess::start, Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::ReadWrite))
            .define_method<void (QProcess::*)(const QString &, const QStringList &, QIODeviceBase::OpenMode)>("start", &QProcess::start, Arg("program"), Arg("arguments") = static_cast<const QStringList &>(QStringList {}), Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::ReadWrite))
            .define_method("start_command", &QProcess::startCommand, Arg("command"), Arg("mode") = static_cast<QIODeviceBase::OpenMode>(QIODeviceBase::ReadWrite))
            .define_method<bool (QProcess::*)(qint64 *)>("start_detached", &QProcess::startDetached, Arg("pid") = static_cast<qint64 *>(nullptr))
            .define_method("state", &QProcess::state)
            .define_method("wait_for_bytes_written", &QProcess::waitForBytesWritten, Arg("msecs") = static_cast<int>(30000))
            .define_method("wait_for_finished", &QProcess::waitForFinished, Arg("msecs") = static_cast<int>(30000))
            .define_method("wait_for_ready_read", &QProcess::waitForReadyRead, Arg("msecs") = static_cast<int>(30000))
            .define_method("wait_for_started", &QProcess::waitForStarted, Arg("msecs") = static_cast<int>(30000))
            .define_method("working_directory", &QProcess::workingDirectory)
            // Public Slots
            .define_method("kill", &QProcess::kill)
            .define_method("terminate", &QProcess::terminate)
            // Signals
            // .define_method("error_occurred", &QProcess::errorOccurred, Arg("error"))
            // .define_method("finished", &QProcess::finished, Arg("exit_code"), Arg("exit_status") = static_cast<QProcess::ExitStatus>(QProcess::NormalExit))
            // .define_method("ready_read_standard_error", &QProcess::readyReadStandardError)
            // .define_method("ready_read_standard_output", &QProcess::readyReadStandardOutput)
            // .define_method("started", &QProcess::started)
            // .define_method("state_changed", &QProcess::stateChanged, Arg("state"))
            // Static Public Members
            .define_singleton_function("_execute", &QProcess::execute, Arg("program"), Arg("arguments"))
            .define_singleton_function("null_device", &QProcess::nullDevice)
            .define_singleton_function("split_command", &QProcess::splitCommand, Arg("command"))
            .define_singleton_function<bool (*)(const QString &, const QStringList &, const QString &, qint64 *)>("start_detached", &QProcess::startDetached, Arg("program"), Arg("arguments") = static_cast<const QStringList &>(QStringList {}), Arg("working_directory") = static_cast<const QString &>(QString()), Arg("pid") = static_cast<qint64 *>(nullptr))
            .define_singleton_function("system_environment", &QProcess::systemEnvironment);

    Data_Type<QProcess::ExitStatus> rb_cQProcessExitStatus =
        // RubyQt6::QtCore::QProcess::ExitStatus
        define_qenum_under<QProcess::ExitStatus>(rb_cQProcess, "ExitStatus");
        define_qenum_value_under(rb_cQProcessExitStatus, "NormalExit", QProcess::ExitStatus::NormalExit);
        define_qenum_value_under(rb_cQProcessExitStatus, "CrashExit", QProcess::ExitStatus::CrashExit);

    Data_Type<QProcess::InputChannelMode> rb_cQProcessInputChannelMode =
        // RubyQt6::QtCore::QProcess::InputChannelMode
        define_qenum_under<QProcess::InputChannelMode>(rb_cQProcess, "InputChannelMode");
        define_qenum_value_under(rb_cQProcessInputChannelMode, "ManagedInputChannel", QProcess::InputChannelMode::ManagedInputChannel);
        define_qenum_value_under(rb_cQProcessInputChannelMode, "ForwardedInputChannel", QProcess::InputChannelMode::ForwardedInputChannel);

    Data_Type<QProcess::ProcessChannel> rb_cQProcessProcessChannel =
        // RubyQt6::QtCore::QProcess::ProcessChannel
        define_qenum_under<QProcess::ProcessChannel>(rb_cQProcess, "ProcessChannel");
        define_qenum_value_under(rb_cQProcessProcessChannel, "StandardOutput", QProcess::ProcessChannel::StandardOutput);
        define_qenum_value_under(rb_cQProcessProcessChannel, "StandardError", QProcess::ProcessChannel::StandardError);

    Data_Type<QProcess::ProcessChannelMode> rb_cQProcessProcessChannelMode =
        // RubyQt6::QtCore::QProcess::ProcessChannelMode
        define_qenum_under<QProcess::ProcessChannelMode>(rb_cQProcess, "ProcessChannelMode");
        define_qenum_value_under(rb_cQProcessProcessChannelMode, "SeparateChannels", QProcess::ProcessChannelMode::SeparateChannels);
        define_qenum_value_under(rb_cQProcessProcessChannelMode, "MergedChannels", QProcess::ProcessChannelMode::MergedChannels);
        define_qenum_value_under(rb_cQProcessProcessChannelMode, "ForwardedChannels", QProcess::ProcessChannelMode::ForwardedChannels);
        define_qenum_value_under(rb_cQProcessProcessChannelMode, "ForwardedOutputChannel", QProcess::ProcessChannelMode::ForwardedOutputChannel);
        define_qenum_value_under(rb_cQProcessProcessChannelMode, "ForwardedErrorChannel", QProcess::ProcessChannelMode::ForwardedErrorChannel);

    Data_Type<QProcess::ProcessError> rb_cQProcessProcessError =
        // RubyQt6::QtCore::QProcess::ProcessError
        define_qenum_under<QProcess::ProcessError>(rb_cQProcess, "ProcessError");
        define_qenum_value_under(rb_cQProcessProcessError, "FailedToStart", QProcess::ProcessError::FailedToStart);
        define_qenum_value_under(rb_cQProcessProcessError, "Crashed", QProcess::ProcessError::Crashed);
        define_qenum_value_under(rb_cQProcessProcessError, "Timedout", QProcess::ProcessError::Timedout);
        define_qenum_value_under(rb_cQProcessProcessError, "ReadError", QProcess::ProcessError::ReadError);
        define_qenum_value_under(rb_cQProcessProcessError, "WriteError", QProcess::ProcessError::WriteError);
        define_qenum_value_under(rb_cQProcessProcessError, "UnknownError", QProcess::ProcessError::UnknownError);

    Data_Type<QProcess::ProcessState> rb_cQProcessProcessState =
        // RubyQt6::QtCore::QProcess::ProcessState
        define_qenum_under<QProcess::ProcessState>(rb_cQProcess, "ProcessState");
        define_qenum_value_under(rb_cQProcessProcessState, "NotRunning", QProcess::ProcessState::NotRunning);
        define_qenum_value_under(rb_cQProcessProcessState, "Starting", QProcess::ProcessState::Starting);
        define_qenum_value_under(rb_cQProcessProcessState, "Running", QProcess::ProcessState::Running);
}
