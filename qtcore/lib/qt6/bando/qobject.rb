# frozen_string_literal: true

module RubyQt6
  module Bando
    class QObject < RubyQt6::QtCore::QObject
      alias_method :_initialize, :initialize
    end
  end
end
