# frozen_string_literal: true

module Qt6
  module QtCore
    class QString
      alias_method :to_s, :to_std_string
    end
  end
end
