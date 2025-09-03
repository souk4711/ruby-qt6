# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/signalsandslots.html
    module QtMetaMacro
      # @param signature [String]
      # @return [String]
      def SIGNAL(signature)
        "2#{signature}"
      end

      # @param signature [String]
      # @return [String]
      def SLOT(signature)
        "1#{signature}"
      end
    end
  end
end
