# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qurl.html
    class QUrl
      # @!parse class AceProcessingOption       ; end
      # @!parse class AceProcessingOptions      ; end
      # @!parse class ComponentFormattingOption ; end
      # @!parse class ComponentFormattingOptions; end
      # @!parse class FormattingOptions         ; end
      # @!parse class ParsingMode               ; end
      # @!parse class UrlFormattingOption       ; end
      # @!parse class UserInputResolutionOption ; end
      # @!parse class UserInputResolutionOptions; end
      rubyqt6_declare_enum_under QUrl, QUrl::AceProcessingOption
      rubyqt6_declare_enum_under QUrl, QUrl::ComponentFormattingOption
      rubyqt6_declare_enum_under QUrl, QUrl::ParsingMode
      rubyqt6_declare_enum_under QUrl, QUrl::UrlFormattingOption
      rubyqt6_declare_enum_under QUrl, QUrl::UserInputResolutionOption
      rubyqt6_declare_qflags QUrl::AceProcessingOptions, QUrl::AceProcessingOption
      rubyqt6_declare_qflags QUrl::ComponentFormattingOptions, QUrl::ComponentFormattingOption
      rubyqt6_declare_qflags QUrl::FormattingOptions, QUrl::UrlFormattingOption
      rubyqt6_declare_qflags QUrl::UserInputResolutionOptions, QUrl::UserInputResolutionOption

      # @!parse
      QtCore::QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.from_local_file(local_file)
        _from_local_file(T.to_qstr(local_file))
      end

      # @!visibility private
      def self.from_user_input(user_input, working_directory = "", options = nil)
        options ||= QtCore::QUrl::DefaultResolution
        _from_user_input(T.to_qstr(user_input), T.to_qstr(working_directory), T.to_qflags(options))
      end

      # @return [QUrl]
      #
      # @overload initialize
      #
      # @overload initialize(url)
      #   @param url [String, QString]
      #
      # @overload initialize(url, mode)
      #   @param url [String, QString]
      #   @param mode [QUrl::ParsingMode]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string.to_s
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
