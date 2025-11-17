# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qspaceritem.html
    class QSpacerItem < RubyQt6::QtWidgets::QLayoutItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param w [Integer]
      # @param h [Integer]
      # @param h_policy [QSizePolicy::Policy]
      # @param v_policy [QSizePolicy::Policy]
      # @return [QSpacerItem]
      def initialize(w, h, h_policy = nil, v_policy = nil)
        h_policy ||= QtWidgets::QSizePolicy::Policy::Minimum
        v_policy ||= QtWidgets::QSizePolicy::Policy::Minimum
        _initialize(w, h, h_policy, v_policy)
      end
    end
  end
end
