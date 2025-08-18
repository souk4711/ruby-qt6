# frozen_string_literal: true

module Qt6
  module QtWidgets
    class QApplication
      def exec
        self.class.exec
      end
    end
  end
end
