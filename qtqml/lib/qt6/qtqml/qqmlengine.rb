# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qqmlengine.html
    class QQmlEngine < RubyQt6::QtQml::QJSEngine
      # @param path [QString]
      # @return [nil]
      #
      # Adds path as a directory where the engine searches for installed
      # modules in a URL-based directory structure.
      #
      # The path may be a local filesystem directory, a Qt Resource path
      # (:/imports), a Qt Resource url (qrc:/imports) or a URL.
      #
      # The path will be converted into canonical form before it is added to
      # the import path list.
      #
      # The newly added path will be first in the importPathList().
      def add_import_path(path)
        _add_import_path(QtCore::QString.new(path))
      end
    end
  end
end
