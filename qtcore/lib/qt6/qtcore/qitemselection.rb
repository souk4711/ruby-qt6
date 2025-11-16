# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qitemselection.html
    class QItemSelection
      # @!parse
      QtCore::QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )
    end
  end
end
