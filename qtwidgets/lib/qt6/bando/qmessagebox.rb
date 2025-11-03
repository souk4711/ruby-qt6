# frozen_string_literal: true

module RubyQt6
  module Bando
    class QMessageBox < RubyQt6::QtWidgets::QMessageBox
      Bando.define_bando_qwidget Bando::QMessageBox
    end
  end
end
