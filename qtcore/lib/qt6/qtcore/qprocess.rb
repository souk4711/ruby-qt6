# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qprocess.html
    class QProcess < RubyQt6::QtCore::QIODevice
      # @!parse class ExitStatus        ; end
      # @!parse class InputChannelMode  ; end
      # @!parse class ProcessChannel    ; end
      # @!parse class ProcessChannelMode; end
      # @!parse class ProcessError      ; end
      # @!parse class ProcessState      ; end
      rubyqt6_declare_enum_under QProcess, QProcess::ExitStatus
      rubyqt6_declare_enum_under QProcess, QProcess::InputChannelMode
      rubyqt6_declare_enum_under QProcess, QProcess::ProcessChannel
      rubyqt6_declare_enum_under QProcess, QProcess::ProcessChannelMode
      rubyqt6_declare_enum_under QProcess, QProcess::ProcessError
      rubyqt6_declare_enum_under QProcess, QProcess::ProcessState

      # @!parse
      q_object do
        signal "errorOccurred(QProcess::ProcessError)"
        signal "finished(int,QProcess::ExitStatus)"
        signal "finished(int)"
        signal "readyReadStandardError()"
        signal "readyReadStandardOutput()"
        signal "started()"
        signal "stateChanged(QProcess::ProcessState)"
        slot "kill()"
        slot "terminate()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.execute(program, arguments = nil)
        arguments ||= QStringList.new
        _execute(T.to_qstr(program), arguments)
      end

      # @param parent [QObject]
      # @return [QProcess]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def start(*args)
        T.args_nth_to_qstr(args, 0)
        _start(*args)
      end
    end
  end
end
