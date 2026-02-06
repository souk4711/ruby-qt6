# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qregularexpression.html
    class QRegularExpression
      # @!parse class PatternOption            ; end
      # @!parse class MatchType                ; end
      # @!parse class MatchOption              ; end
      # @!parse class WildcardConversionOption ; end
      # @!parse class PatternOptions           ; end
      # @!parse class MatchOptions             ; end
      # @!parse class WildcardConversionOptions; end
      rubyqt6_declare_enum_under QRegularExpression, QRegularExpression::PatternOption
      rubyqt6_declare_enum_under QRegularExpression, QRegularExpression::MatchType
      rubyqt6_declare_enum_under QRegularExpression, QRegularExpression::MatchOption
      rubyqt6_declare_enum_under QRegularExpression, QRegularExpression::WildcardConversionOption
      rubyqt6_declare_qflags QRegularExpression::PatternOptions, QRegularExpression::PatternOption
      rubyqt6_declare_qflags QRegularExpression::MatchOptions, QRegularExpression::MatchOption
      rubyqt6_declare_qflags QRegularExpression::WildcardConversionOptions, QRegularExpression::WildcardConversionOption

      # @!visibility private
      def self.from_wildcard(pattern, cs = nil, options = nil)
        options ||= QRegularExpression::DefaultWildcardConversion
        pattern = wildcard_to_regular_expression(T.to_qstr(pattern), options)

        cs ||= Qt::CaseInsensitive
        options = (cs == Qt::CaseSensitive) ? QRegularExpression::NoPatternOption : QRegularExpression::CaseInsensitiveOption
        new(pattern, options)
      end

      # @!visibility private
      def self.wildcard_to_regular_expression(pattern, options = nil)
        options ||= QRegularExpression::DefaultWildcardConversion
        _wildcard_to_regular_expression(T.to_qstr(pattern), T.to_qflags(options))
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param pattern [String, QString]
      # @param options [QRegularExpression::PatternOptions]
      # @return [QRegularExpression]
      def initialize(pattern = "", options = nil)
        options ||= QRegularExpression::NoPatternOption
        _initialize(T.to_qstr(pattern), T.to_qflags(options))
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, pattern: pattern.to_s)
      end
    end
  end
end
