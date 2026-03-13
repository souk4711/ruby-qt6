# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qabstractproxymodel.html
    class QAbstractProxyModel < RubyQt6::QtCore::QAbstractItemModel
      # @!parse
      q_object do
        signal "sourceModelChanged()"
      end
    end
  end
end
