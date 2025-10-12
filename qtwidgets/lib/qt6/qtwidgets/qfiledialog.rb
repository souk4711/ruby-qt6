# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qfiledialog.html
    class QFileDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class AcceptMode ; end
      # @!parse class DialogLabel; end
      # @!parse class FileMode   ; end
      # @!parse class Option     ; end
      # @!parse class ViewMode   ; end
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::AcceptMode
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::DialogLabel
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::FileMode
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::Option
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::ViewMode

      # @!parse class Options; end
      rubyqt6_declare_qflags QFileDialog::Options, QFileDialog::Option

      # @!parse
      q_object do
        signal "currentChanged(QString)"
        signal "currentUrlChanged(QUrl)"
        signal "directoryEntered(QString)"
        signal "directoryUrlEntered(QUrl)"
        signal "fileSelected(QString)"
        signal "filesSelected(QStringList)"
        signal "filterSelected(QString)"
        signal "urlSelected(QUrl)"
        signal "urlsSelected(QList<QUrl>)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QFileDialog]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
