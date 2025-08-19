# frozen_string_literal: true

module Qt6
  module QtCore
    class QString
      def self.new(str = "")
        (QString === str) ? str : super
      end
    end
  end
end
