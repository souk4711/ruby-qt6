# frozen_string_literal: true

module Qt6
  module QtWidgets
    class QApplication
      def self.new(argv = [])
        ::Qt6::QtWidgets._new_qapplication(argv)
      end

      def exec
        self.class.exec
      end
    end
  end
end
