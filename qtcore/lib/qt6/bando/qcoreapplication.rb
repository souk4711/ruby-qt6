# frozen_string_literal: true

module RubyQt6
  module Bando
    class QCoreApplication < RubyQt6::QtCore::QCoreApplication
      alias_method :_initialize, :initialize
    end
  end
end
