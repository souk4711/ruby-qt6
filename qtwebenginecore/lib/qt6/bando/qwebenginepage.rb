# frozen_string_literal: true

module RubyQt6
  module Bando
    class QWebEnginePage < RubyQt6::QtWebEngineCore::QWebEnginePage
      Bando.define_bando_qobject Bando::QWebEnginePage
    end
  end
end
