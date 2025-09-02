# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QObject
      private

      def _take_ownership_from_rice(object)
        self.class._take_ownership_from_rice(object)
      end
    end
  end
end
