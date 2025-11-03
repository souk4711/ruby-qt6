# frozen_string_literal: true

module RubyQt6
  module Bando
    class QDBusAbstractInterface < RubyQt6::QtDBus::QDBusAbstractInterface
      Bando.define_bando_qobject Bando::QDBusAbstractInterface
    end
  end
end
