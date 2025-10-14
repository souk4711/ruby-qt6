# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/quuid.html
    class QUuid
      include Comparable

      # @!parse class StringFormat; end
      # @!parse class Variant     ; end
      # @!parse class Version     ; end
      rubyqt6_declare_enum_under QUuid, QUuid::StringFormat
      rubyqt6_declare_enum_under QUuid, QUuid::Variant
      rubyqt6_declare_enum_under QUuid, QUuid::Version

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QUuid]
      #
      # @overload initialize
      #
      # @overload initialize(text)
      #   @param text [String, QString, QAnyStringView]
      def initialize(*args)
        T.args_nth_to_qanystringview(args, 0, String, QtCore::QString)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string(QUuid::StringFormat::WithoutBraces).to_s
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QUuid)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
