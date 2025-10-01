# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qsizepolicy.html
    class QSizePolicy
      # @!parse class ControlType; end
      # @!parse class Policy     ; end
      # @!parse class PolicyFlag ; end
      rubyqt6_include_constants QSizePolicy, QSizePolicy::ControlType
      rubyqt6_include_constants QSizePolicy, QSizePolicy::Policy
      rubyqt6_include_constants QSizePolicy, QSizePolicy::PolicyFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QSizePolicy]
      #
      # @overload initialize(horizontal, vertical)
      #   @param horizontal [QSizePolicy::Policy]
      #   @param vertical [QSizePolicy::Policy]
      #
      # @overload initialize(horizontal, vertical, type)
      #   @param horizontal [QSizePolicy::Policy]
      #   @param vertical [QSizePolicy::Policy]
      #   @param type [QSizePolicy::ControlType]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
