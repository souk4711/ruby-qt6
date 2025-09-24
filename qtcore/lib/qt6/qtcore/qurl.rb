# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qurl.html
    class QUrl
      # @!parse class AceProcessingOption; end
      # @!parse class ComponentFormattingOption; end
      # @!parse class ParsingMode; end
      # @!parse class UrlFormattingOption; end
      # @!parse class UserInputResolutionOption; end
      rubyqt6_include_constants QUrl, QUrl::AceProcessingOption
      rubyqt6_include_constants QUrl, QUrl::ComponentFormattingOption
      rubyqt6_include_constants QUrl, QUrl::ParsingMode
      rubyqt6_include_constants QUrl, QUrl::UrlFormattingOption
      rubyqt6_include_constants QUrl, QUrl::UserInputResolutionOption

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param url [String, QString]
      # @param mode [QUrl::ParsingMode]
      # @return [QUrl]
      def initialize(url, mode = QUrl::ParsingMode::TolerantMode)
        _initialize(T.to_qstr(url), mode)
      end
    end
  end
end
