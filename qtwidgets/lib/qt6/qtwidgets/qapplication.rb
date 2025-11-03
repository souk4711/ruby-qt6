# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qapplication.html
    class QApplication < RubyQt6::QtGui::QGuiApplication
      # @!parse
      q_object do
        signal "focusChanged(QWidget*,QWidget*)"
        slot "aboutQt()"
        slot "closeAllWindows()"
        slot "setAutoSipEnabled(bool)"
        slot "setStyleSheet(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      %w[all_widgets top_level_widgets].each do |meth|
        define_singleton_method(meth) do |*args|
          widgets = __send__("_" + meth, *args)
          widgets.map { |w| T.bando_qobject_cast(w) }
        end
      end

      # @param argv [Array<String>]
      # @return [QApplication]
      def initialize(argv)
        argv = ::Rice::Buffer≺char∗≻.new(argv.map(&:bytes))
        _initialize(argv.size, argv.data)
        _initialize_qApp
      end

      # @!visibility private
      def exec
        self.class.exec
      rescue
        self.class.close_all_windows
        raise
      end

      # @!visibility private
      def set_style_sheet(sheet)
        _set_style_sheet(T.to_qstr(sheet))
      end
    end
  end
end
