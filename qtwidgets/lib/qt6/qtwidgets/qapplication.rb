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
      def self.new
        argv = _initialize_qApp_argv
        _new(argv)._initialize_qApp
      end

      # @!visibility private
      %w[all_widgets top_level_widgets].each do |meth|
        define_singleton_method(meth) do |*args|
          widgets = __send__("_" + meth, *args)
          widgets.map { |w| T.bando_qobject_cast(w) }
        end
      end

      # @!visibility private
      def set_style_sheet(sheet)
        _set_style_sheet(T.to_qstr(sheet))
      end
    end
  end
end
