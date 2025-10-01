# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qurl.html
    class QUrl
      # @!parse class AceProcessingOption      ; end
      # @!parse class ComponentFormattingOption; end
      # @!parse class ParsingMode              ; end
      # @!parse class UrlFormattingOption      ; end
      # @!parse class UserInputResolutionOption; end
      rubyqt6_include_constants QUrl, QUrl::AceProcessingOption
      rubyqt6_include_constants QUrl, QUrl::ComponentFormattingOption
      rubyqt6_include_constants QUrl, QUrl::ParsingMode
      rubyqt6_include_constants QUrl, QUrl::UrlFormattingOption
      rubyqt6_include_constants QUrl, QUrl::UserInputResolutionOption

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QUrl]
      #
      # @overload initialize(url)
      #   @param url [String, QString]
      #
      # @overload initialize(url, mode)
      #   @param url [String, QString]
      #   @param mode [QUrl::ParsingMode]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(::String)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string.to_s
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
