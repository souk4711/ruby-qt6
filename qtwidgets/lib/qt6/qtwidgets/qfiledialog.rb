# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qfiledialog.html
    class QFileDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class AcceptMode ; end
      # @!parse class DialogLabel; end
      # @!parse class FileMode   ; end
      # @!parse class Option     ; end
      # @!parse class Options    ; end
      # @!parse class ViewMode   ; end
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::AcceptMode
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::DialogLabel
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::FileMode
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::Option
      rubyqt6_declare_enum_under QFileDialog, QFileDialog::ViewMode
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

      # @!visibility private
      def self.get_existing_directory(parent, caption = "", dir = "", options = nil)
        options ||= QtWidgets::QFileDialog::Option::ShowDirsOnly
        _get_existing_directory(parent, T.to_qstr(caption), T.to_qstr(dir), T.to_qflags(options))
      end

      # @!visibility private
      def self.get_open_file_name(parent, caption = "", dir = "", filter = "", selected_filter = "", options = nil)
        options ||= QtWidgets::QFileDialog::Options.new
        _get_open_file_name(parent, T.to_qstr(caption), T.to_qstr(dir), T.to_qstr(filter), T.to_qstr(selected_filter), T.to_qflags(options))
      end

      # @!visibility private
      def self.get_open_file_names(parent, caption = "", dir = "", filter = "", selected_filter = "", options = nil)
        options ||= QtWidgets::QFileDialog::Options.new
        _get_open_file_names(parent, T.to_qstr(caption), T.to_qstr(dir), T.to_qstr(filter), T.to_qstr(selected_filter), T.to_qflags(options))
      end

      # @!visibility private
      def self.get_save_file_name(parent, caption = "", dir = "", filter = "", selected_filter = "", options = nil)
        options ||= QtWidgets::QFileDialog::Options.new
        _get_save_file_name(parent, T.to_qstr(caption), T.to_qstr(dir), T.to_qstr(filter), T.to_qstr(selected_filter), T.to_qflags(options))
      end

      # @param parent [QWidget]
      # @return [QFileDialog]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
