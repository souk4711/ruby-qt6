# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfilesystemmodel.html
    class QFileSystemModel < RubyQt6::QtCore::QAbstractItemModel
      # @!parse class Roles  ; end
      # @!parse class Option ; end
      # @!parse class Options; end
      rubyqt6_declare_enum_under QFileSystemModel, QFileSystemModel::Roles
      rubyqt6_declare_enum_under QFileSystemModel, QFileSystemModel::Option
      rubyqt6_declare_qflags QFileSystemModel::Options, QFileSystemModel::Option

      # @!parse
      q_object do
        signal "directoryLoaded(QString)"
        signal "fileRenamed(QString,QString,QString)"
        signal "rootPathChanged(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QFileSystemModel]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
