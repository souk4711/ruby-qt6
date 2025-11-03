# frozen_string_literal: true

module RubyQt6
  module Bando
    class QMainWindow < RubyQt6::QtWidgets::QMainWindow
      Bando.define_bando_qwidget Bando::QMainWindow
    end
  end
end
