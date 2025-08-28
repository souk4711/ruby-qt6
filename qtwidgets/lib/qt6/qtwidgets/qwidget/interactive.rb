# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    class QWidget < RubyQt6::QtCore::QObject
      # @return [QString]
      #
      # This property holds the widget's tooltip.
      #
      # Note that by default tooltips are only shown for widgets that are
      # children of the active window. You can change this behavior by
      # setting the attribute Qt::WA_AlwaysShowToolTips on the window,
      # not on the widget with the tooltip.
      #
      # If you want to control a tooltip's behavior, you can intercept the
      # event() function and catch the QEvent::ToolTip event (e.g., if you
      # want to customize the area for which the tooltip should be shown).
      #
      # By default, this property contains an empty string.
      def tool_tip
        _tool_tip
      end

      # @return [Integer]
      #
      # This property holds the widget's tooltip duration.
      #
      # Specifies how long time the tooltip will be displayed, in milliseconds.
      # If the value is -1 (default) the duration is calculated depending on
      # the length of the tooltip.
      def tool_tip_duration
        _tool_tip_duration
      end

      # @return [QString]
      #
      # This property holds the widget's status tip.
      #
      # By default, this property contains an empty string.
      def status_tip
        _status_tip
      end

      # @return [QString]
      #
      # This property holds the widget's What's This help text.
      #
      # By default, this property contains an empty string.
      def whats_this
        _whats_this
      end

      # @param tip [QString]
      # @return [nil]
      #
      # Sets the widget's tooltip property.
      def set_tool_tip(tip)
        _set_tool_tip(QtCore::QString.new(tip))
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Sets the widget's toolTipDuration property.
      def set_tool_tip_duration(msec)
        _set_tool_tip_duration(msec)
      end

      # @param tip [QString]
      # @return [nil]
      #
      # Sets the widget's statusTip property.
      def set_status_tip(tip)
        _set_status_tip(QtCore::QString.new(tip))
      end

      # @param help [QString]
      # @return [nil]
      #
      # Sets the widget's whatsThis property.
      def set_whats_this(help)
        _set_whats_this(QtCore::QString.new(help))
      end
    end
  end
end
