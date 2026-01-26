# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qeventloop.html
    class QEventLoop < RubyQt6::QtCore::QObject
      # @!parse class ProcessEventsFlag ; end
      # @!parse class ProcessEventsFlags; end
      rubyqt6_declare_enum_under QEventLoop, QEventLoop::ProcessEventsFlag
      rubyqt6_declare_qflags QEventLoop::ProcessEventsFlags, QEventLoop::ProcessEventsFlag

      # @!parse
      q_object do
      end
    end
  end
end
