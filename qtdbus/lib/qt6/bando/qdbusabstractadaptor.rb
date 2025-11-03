# frozen_string_literal: true

module RubyQt6
  module Bando
    class QDBusAbstractAdaptor < RubyQt6::QtDBus::QDBusAbstractAdaptor
      Bando.define_bando_qobject Bando::QDBusAbstractAdaptor
    end
  end
end
