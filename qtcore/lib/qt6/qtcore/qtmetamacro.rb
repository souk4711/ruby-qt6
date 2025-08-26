# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/signalsandslots.html
    module QtMetaMacro
      def SIGNAL(signature)
        "2#{signature}"
      end

      def SLOT(signature)
        "1#{signature}"
      end
    end
  end
end
