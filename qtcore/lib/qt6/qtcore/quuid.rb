# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/quuid.html
    class QUuid
      include ::Comparable

      # @!parse class StringFormat; end
      # @!parse class Variant     ; end
      # @!parse class Version     ; end
      rubyqt6_include_constants QUuid, QUuid::StringFormat
      rubyqt6_include_constants QUuid, QUuid::Variant
      rubyqt6_include_constants QUuid, QUuid::Version

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param string [String, QString]
      # @return [QUuid]
      def initialize(string)
        _initialize(T.to_qanystringview(string))
      end

      # @!visibility private
      def to_s
        to_string(QUuid::StringFormat::WithoutBraces).to_s
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QUuid)
        self.class._compare(self, other)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
