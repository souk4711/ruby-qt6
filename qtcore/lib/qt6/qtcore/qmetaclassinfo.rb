# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmetaclassinfo.html
    class QMetaClassInfo
      # @!visibility private
      def inspect
        T.inspect_struct(self, name: name.to_s, value: value.to_s)
      end
    end
  end
end
