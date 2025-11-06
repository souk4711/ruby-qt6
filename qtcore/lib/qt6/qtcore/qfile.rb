# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qfile.html
    class QFile < RubyQt6::QtCore::QFileDevice
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param name [String, QString]
      # @param parent [QObject]
      # @return [QFile]
      def initialize(name, parent = nil)
        _initialize(T.to_qstr(name), parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
