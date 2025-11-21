# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtoolbar.html
    class QToolBar < RubyQt6::QtWidgets::QWidget
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QWidget)\n" \
        "    initialize(QString, QWidget)\n"

      # @!parse
      q_object do
        signal "actionTriggered(QAction*)"
        signal "allowedAreasChanged(Qt::ToolBarAreas)"
        signal "iconSizeChanged(QSize)"
        signal "movableChanged(bool)"
        signal "orientationChanged(Qt::Orientation)"
        signal "toolButtonStyleChanged(Qt::ToolButtonStyle)"
        signal "topLevelChanged(bool)"
        signal "visibilityChanged(bool)"
        slot "setIconSize(QSize)"
        slot "setToolButtonStyle(Qt::ToolButtonStyle)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QToolBar]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QWidget]
      #
      # @overload initialize(title, parent = nil)
      #   @param title [String, QString]
      #   @param parent [QWidget]
      def initialize(*args)
        parent = T.args_nth_delete_qwidget(args, -1)
        case args.size
        when 0 then _initialize(parent)
        when 1 then _initialize_p(T.to_qstr(args[-1]), parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end

      private

      def _initialize_p(title, parent)
        _initialize(parent)
        set_window_title(title)
      end
    end
  end
end
