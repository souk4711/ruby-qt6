# frozen_string_literal: true

module RubyQt6
  module QtNetwork
    # @see https://doc.qt.io/qt-6/qnetworkproxy.html
    class QNetworkProxy
      # @!parse class Capabilities; end
      # @!parse class Capability  ; end
      # @!parse class ProxyType   ; end
      rubyqt6_declare_enum_under QNetworkProxy, QNetworkProxy::Capability
      rubyqt6_declare_enum_under QNetworkProxy, QNetworkProxy::ProxyType
      rubyqt6_declare_qflags QNetworkProxy::Capabilities, QNetworkProxy::Capability

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QNetworkProxy]
      def initialize
        _initialize
      end
    end
  end
end
