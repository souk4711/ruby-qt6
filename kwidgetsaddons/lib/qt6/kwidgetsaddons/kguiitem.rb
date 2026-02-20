# frozen_string_literal: true

module RubyQt6
  module KWidgetsAddons
    # @see https://api.kde.org/kguiitem.html
    class KGuiItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param icon_name [String, QString]
      # @param tool_tip [String, QString]
      # @param whats_this [String, QString]
      # @return [KGuiItem]
      def initialize(text = "", icon_name = "", tool_tip = "", whats_this = "")
        _initialize(T.to_qstr(text), T.to_qstr(icon_name), T.to_qstr(tool_tip), T.to_qstr(whats_this))
      end
    end
  end
end
