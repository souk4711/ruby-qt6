# frozen_string_literal: true

module RubyQt6
  module KCoreAddons
    # @see https://api.kde.org/kaboutdata.html
    class KAboutData
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param component_name [String, QString]
      # @param display_name [String, QString]
      # @param version [String, QString]
      # @return [KAboutData]
      def initialize(component_name = "", display_name = "", version = "")
        _initialize(T.to_qstr(component_name), T.to_qstr(display_name), T.to_qstr(version))
      end
    end
  end
end
